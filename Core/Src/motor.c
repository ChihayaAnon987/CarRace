#include "motor.h"

struct PIDController leftMotorPID;
struct PIDController rightMotorPID;

void ComputePID(struct PIDController *pid, int16_t measuredVal) {
    pid->preError = pid->currentError;
    pid->currentError = pid->targetVal- measuredVal;
    pid->derivative = pid->currentError- pid->preError;
    pid->integral += pid->currentError;

    if (pid->integral > INTEGRAL_LIMIT) {
        pid->integral = INTEGRAL_LIMIT;
    } 
    else if (pid->integral <-INTEGRAL_LIMIT) {
        pid->integral =-INTEGRAL_LIMIT;
    }

    pid->output = pid->Kp * pid->currentError + pid->Ki * pid->integral + pid->Kd *
    pid->derivative;
}

void MotorControl(void) {
    
    int16_t pwmLeft = leftMotorPID.output;
    int16_t pwmRight = rightMotorPID.output;

    if (pwmLeft > 3600) {
        pwmLeft = 3600;
    } 
    else if (pwmLeft <-3600) {
        pwmLeft =-3600;
    }

    if (pwmLeft >= 0) {
        TIM2->CCR1 = pwmLeft, HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
    } 
    else {
        TIM2->CCR1 =-pwmLeft, HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
    }

    if (pwmRight > 3600) {
        pwmRight = 3600;
    } 
    else if (pwmRight <-3600) {
        pwmRight =-3600;
    }

    if (pwmRight >= 0) {
        TIM2->CCR2 = pwmRight, HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
    } 
    else {
        TIM2->CCR2 =-pwmRight, HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
    }
}