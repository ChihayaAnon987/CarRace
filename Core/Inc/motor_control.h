#ifndef MOTOR_CONTROL_H
#define MOTOR_CONTROL_H

<<<<<<< HEAD
=======
#include "main.h"
#include "stdio.h"
>>>>>>> 7b44d06cf2ef5db21a88168a7f73a52f017112e2
#include "SEEKFREE_MT9V03X.h"


#define MAX_SPEED_UP 100  // 最大前进速度
#define MAX_SPEED_DOWN 0  // 最大后退速度

#define MIDDLE_H MT9V03X_H / 2  // 中间位置



void pidInit(void);  // PID初始化
void motorPidSetSpeed(float Motor1setSpeed, float Motor2setSpeed);  // 设置电机速度
void motorSpeedup(void);  // 向前加速
void motorSpeeddown(void);  // 向前减速

int getLinePosition(uint8_t* output_image);  // 获取中线位置
void motorFollow(uint8_t* output_image);  // 寻线（假设视觉处理出一个要跟踪的中线）









#endif