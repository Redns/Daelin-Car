/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
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
#include "stm32f1xx_hal.h"

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
#define EN1_Pin GPIO_PIN_0
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_1
#define EN2_GPIO_Port GPIOA
#define EN3_Pin GPIO_PIN_2
#define EN3_GPIO_Port GPIOA
#define EN4_Pin GPIO_PIN_3
#define EN4_GPIO_Port GPIOA
#define R_Pin GPIO_PIN_6
#define R_GPIO_Port GPIOA
#define Gripper_Pin GPIO_PIN_7
#define Gripper_GPIO_Port GPIOA
#define IN1_Pin GPIO_PIN_0
#define IN1_GPIO_Port GPIOB
#define IN2_Pin GPIO_PIN_1
#define IN2_GPIO_Port GPIOB
#define IN3_Pin GPIO_PIN_10
#define IN3_GPIO_Port GPIOB
#define IN4_Pin GPIO_PIN_11
#define IN4_GPIO_Port GPIOB
#define IN5_Pin GPIO_PIN_12
#define IN5_GPIO_Port GPIOB
#define IN6_Pin GPIO_PIN_13
#define IN6_GPIO_Port GPIOB
#define IN7_Pin GPIO_PIN_14
#define IN7_GPIO_Port GPIOB
#define IN8_Pin GPIO_PIN_15
#define IN8_GPIO_Port GPIOB
#define LED_Pin GPIO_PIN_8
#define LED_GPIO_Port GPIOA
#define L_Pin GPIO_PIN_7
#define L_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
