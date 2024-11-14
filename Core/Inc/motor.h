#ifndef MOTOR_H
#define MOTOR_H

#include "stdio.h"

#define INTEGRAL_LIMIT 20000

struct PIDController {
    int16_t targetVal;
    int16_t currentError;
    int16_t preError;
    int16_t derivative;
    int32_t integral;
    int16_t output;
    float Kp, Ki, Kd;
};

extern struct PIDController leftMotorPID;
extern struct PIDController rightMotorPID;
void ComputePID(struct PIDController *pid, int16_t measuredVal);
void MotorControl(void);
















#endif