/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
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
#include "stm32g0xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#ifdef ST25R3916
#include "nfc06a1.h"
#endif /* ST25R3916 */
#ifdef ST25R3916B
#include "nfc08a1.h"
#endif /* ST25R3916B */
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
int32_t BSP_SPI1_SendRecv(const uint8_t * const pTxData, uint8_t * const pRxData, uint16_t Length);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOF
#define ST25R3916_IRQ_Pin GPIO_PIN_0
#define ST25R3916_IRQ_GPIO_Port GPIOA
#define ST25R3916_IRQ_EXTI_IRQn EXTI0_1_IRQn
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SPI1_CS_Pin GPIO_PIN_6
#define SPI1_CS_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define ST25R3916
#define STACK_TIM3_PRESCALER 3
#define SYSCLOCK_FREQUENCY 32000000
#define STACK_TIM3_FREQ 10000
#define STACK_TIM3_PERIOD ((SYSCLOCK_FREQUENCY/(STACK_TIM3_FREQ * (STACK_TIM3_PRESCALER + 1))) - 1)
//#define LED6_Pin GPIO_PIN_8
//#define LED6_GPIO_Port GPIOA
//#define LED7_Pin GPIO_PIN_10
//#define LED7_GPIO_Port GPIOB
//#define LED4_Pin GPIO_PIN_15
//#define LED4_GPIO_Port GPIOA
//#define LED5_Pin GPIO_PIN_0
//#define LED5_GPIO_Port GPIOD
#define ST25R_SPI_INT_Pin ST25R3916_IRQ_Pin
#define ST25R_SPI_INT_GPIO_Port ST25R3916_IRQ_GPIO_Port
#define ST25R_SPI_INT_EXTI_IRQn ST25R3916_IRQ_EXTI_IRQn
#define ST25R_SPI_SS_Pin SPI1_CS_Pin
#define ST25R_SPI_SS_GPIO_Port SPI1_CS_GPIO_Port

#define USE_UART_PORT_AS_GPIO 1
#define NFC_Detected() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1)
#define NFC_Undetected() HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0)

#define USE_LOGGER 0
//#define DEMO_NO_DELAY_IN_DEMOCYCLE
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
