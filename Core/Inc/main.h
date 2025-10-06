/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#define Led1_Pin GPIO_PIN_3
#define Led1_GPIO_Port GPIOE
#define Led2_Pin GPIO_PIN_4
#define Led2_GPIO_Port GPIOE
#define LED_BTN_R_Pin GPIO_PIN_12
#define LED_BTN_R_GPIO_Port GPIOE
#define LED_BTN_G_Pin GPIO_PIN_13
#define LED_BTN_G_GPIO_Port GPIOE
#define BUZZER_Pin GPIO_PIN_14
#define BUZZER_GPIO_Port GPIOE
#define Col3_Pin GPIO_PIN_8
#define Col3_GPIO_Port GPIOD
#define Col2_Pin GPIO_PIN_9
#define Col2_GPIO_Port GPIOD
#define Col1_Pin GPIO_PIN_10
#define Col1_GPIO_Port GPIOD
#define Row3_Pin GPIO_PIN_11
#define Row3_GPIO_Port GPIOD
#define Row2_Pin GPIO_PIN_12
#define Row2_GPIO_Port GPIOD
#define Row1_Pin GPIO_PIN_13
#define Row1_GPIO_Port GPIOD
#define LED_ERROR_Pin GPIO_PIN_4
#define LED_ERROR_GPIO_Port GPIOG
#define LED_WARN_Pin GPIO_PIN_5
#define LED_WARN_GPIO_Port GPIOG
#define LED_TRACK_Pin GPIO_PIN_6
#define LED_TRACK_GPIO_Port GPIOG
#define LED_READY_Pin GPIO_PIN_7
#define LED_READY_GPIO_Port GPIOG
#define DE_Pin GPIO_PIN_0
#define DE_GPIO_Port GPIOD
#define RE_Pin GPIO_PIN_1
#define RE_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
