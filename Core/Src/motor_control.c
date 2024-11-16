#include "main.h"
#include "motor_control.h"
#include "motor.h"
#include "SEEKFREE_MT9V03X.h"

// PID初始化
void pidInit(void) {
    // 左电机初始化
    leftMotorPID.targetVal = 0;
    leftMotorPID.currentError = 0;
    leftMotorPID.preError = 0;
    leftMotorPID.derivative = 0;
    leftMotorPID.integral = 0;
    leftMotorPID.output = 0;
    leftMotorPID.Kp = 4.0;
    leftMotorPID.Ki = 0.02;
    leftMotorPID.Kd = 0.0;
    // 右电机初始化
    rightMotorPID.targetVal = 0;
    rightMotorPID.currentError = 0;
    rightMotorPID.preError = 0;
    rightMotorPID.derivative = 0;
    rightMotorPID.integral = 0;
    rightMotorPID.output = 0;
    rightMotorPID.Kp = 4.0;
    rightMotorPID.Ki = 0.02;
    rightMotorPID.Kd = 0.0;

}


// 设置电机速度
void motorPidSetSpeed(float Motor1setSpeed, float Motor2setSpeed) {
    leftMotorPID.targetVal = Motor1setSpeed;
    rightMotorPID.targetVal = Motor2setSpeed;

    //这里的参数要根据弯道调整
    //motorPidSetSpeed(2, 1);       // 向右转弯
    //motorPidSetSpeed(1, 2);       // 向左转弯
    //motorPidSetSpeed(1, 1);       // 前进
    //motorPidSetSpeed(-1, -1);     // 后退
    //motorPidSetSpeed(0, 0);       // 停止
    //motorPidSetSpeed(1, -1);      // 右原地旋转
    //motorPidSetSpeed(-1, 1);      // 左原地旋转


}


// 向前加速函数
void motorSpeedup(void) {

    static float MotorSetSpeedUp = 5;  // 静态变量，函数结束，变量不会销毁
    if(MotorSetSpeedUp <= MAX_SPEED_UP)  // 如果没有超过最大值就增加5
    {
        MotorSetSpeedUp += 5;
    }
    motorPidSetSpeed(MotorSetSpeedUp, MotorSetSpeedUp);  // 设置到电机


}


// 向前减速函数，结束阶段
void motorSpeeddown(void) {

    static float MotorSetSpeeddown = 3;  // 静态变量，函数结束，变量不会销毁
    if(MotorSetSpeeddown >= 0.5)  // 判断是否速度太小
    {
        MotorSetSpeeddown -= 0.5;
    }
    motorPidSetSpeed(MotorSetSpeeddown, MotorSetSpeeddown);  // 设置到电机


}


// 获取中线位置
int getLinePosition(uint8_t* output_image) {
    int x_center = MT9V03X_W / 2;
    int linePos = -1;  // 用-1标记未找到中线

    // 从图像底部向上扫描，寻找中线的横坐标
    for (int y = MT9V03X_H - 1; y >= MIDDLE_H; y--) {  // 可以限制从底部中间位置到上方的区域进行扫描
        // 扫描一行中的每个像素，寻找白色像素
        for (int x = 0; x < MT9V03X_W; x++) {
            if (output_image[x + y * MT9V03X_W] == 255) {  // 如果找到黑色像素
                linePos = x;  // 找到后记录横坐标
                break;
            }
        }
				if (linePos != -1)
				{
					break;  // 找到中线就退出
				}
    }
		return linePos;
    
}


// 追踪中线
void motorFollow(uint8_t* output_image) {
    // 获取当前中线的位置
    int linePos = getLinePosition(output_image);

    // 如果未找到中线，停止运动
    if (linePos == -1) {
        motorPidSetSpeed(0, 0);
        return;
    }

    // 计算与中心的偏差
    int x_center = MT9V03X_W / 2;
    int deviation = linePos - x_center;  // 负值表示偏左，正值表示偏右

    // 使用简单的比例控制来修正偏差
    float correction = deviation * 0.1;  // 控制系数（可以根据实际情况调整）

    // 设定电机的速度
    float leftSpeed  = MAX_SPEED_UP - correction;
    float rightSpeed = MAX_SPEED_UP + correction;

    // 限制电机的速度范围
    if (leftSpeed  > MAX_SPEED_UP)  leftSpeed  = MAX_SPEED_UP;
    if (rightSpeed > MAX_SPEED_UP)  rightSpeed = MAX_SPEED_UP;
    if (leftSpeed  < -MAX_SPEED_UP) leftSpeed  = -MAX_SPEED_UP;
    if (rightSpeed < -MAX_SPEED_UP) rightSpeed = -MAX_SPEED_UP;

    // 设置电机速度
    motorPidSetSpeed(leftSpeed, rightSpeed);
}







