/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define Encoder1_Pin GPIO_PIN_1
#define Encoder1_GPIO_Port GPIOA
#define USART_SDA_TX_Pin GPIO_PIN_2
#define USART_SDA_TX_GPIO_Port GPIOA
#define USART_SCL_RX_Pin GPIO_PIN_3
#define USART_SCL_RX_GPIO_Port GPIOA
#define Encoder2_Pin GPIO_PIN_6
#define Encoder2_GPIO_Port GPIOA
#define Encoder2A7_Pin GPIO_PIN_7
#define Encoder2A7_GPIO_Port GPIOA
#define D0_Pin GPIO_PIN_0
#define D0_GPIO_Port GPIOB
#define D1_Pin GPIO_PIN_1
#define D1_GPIO_Port GPIOB
#define D2_Pin GPIO_PIN_2
#define D2_GPIO_Port GPIOB
#define IO1_Pin GPIO_PIN_12
#define IO1_GPIO_Port GPIOB
#define IO2_Pin GPIO_PIN_13
#define IO2_GPIO_Port GPIOB
#define VSY_Pin GPIO_PIN_11
#define VSY_GPIO_Port GPIOA
#define VSY_EXTI_IRQn EXTI15_10_IRQn
#define PCLK_Pin GPIO_PIN_12
#define PCLK_GPIO_Port GPIOA
#define Encoder1A15_Pin GPIO_PIN_15
#define Encoder1A15_GPIO_Port GPIOA
#define D3_Pin GPIO_PIN_3
#define D3_GPIO_Port GPIOB
#define D4_Pin GPIO_PIN_4
#define D4_GPIO_Port GPIOB
#define D5_Pin GPIO_PIN_5
#define D5_GPIO_Port GPIOB
#define D6_Pin GPIO_PIN_6
#define D6_GPIO_Port GPIOB
#define D7_Pin GPIO_PIN_7
#define D7_GPIO_Port GPIOB
#define PWM1_Pin GPIO_PIN_8
#define PWM1_GPIO_Port GPIOB
#define PWM2_Pin GPIO_PIN_9
#define PWM2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */