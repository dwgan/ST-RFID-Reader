/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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

#include "stm32g0xx_ll_rcc.h"
#include "stm32g0xx_ll_bus.h"
#include "stm32g0xx_ll_system.h"
#include "stm32g0xx_ll_exti.h"
#include "stm32g0xx_ll_cortex.h"
#include "stm32g0xx_ll_utils.h"
#include "stm32g0xx_ll_pwr.h"
#include "stm32g0xx_ll_dma.h"
#include "stm32g0xx_ll_spi.h"
#include "stm32g0xx_ll_usart.h"
#include "stm32g0xx_ll_gpio.h"

#if defined(USE_FULL_ASSERT)
#include "stm32_assert.h"
#endif /* USE_FULL_ASSERT */

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
void UserButton_Callback(void);
void USART_TXEmpty_Callback(void);
void USART_CharTransmitComplete_Callback(void);
void Error_Callback(void);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ST25R3916_IRQ_Pin LL_GPIO_PIN_0
#define ST25R3916_IRQ_GPIO_Port GPIOA
#define ST25R3916_IRQ_EXTI_IRQn EXTI0_1_IRQn
#define TMS_Pin LL_GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin LL_GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define SPI1_CS_Pin LL_GPIO_PIN_6
#define SPI1_CS_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

#define ST25R3916
#define STACK_TIM3_PRESCALER 3
#define SYSCLOCK_FREQUENCY 32000000
#define STACK_TIM3_FREQ 10000
#define STACK_TIM3_PERIOD ((SYSCLOCK_FREQUENCY/(STACK_TIM3_FREQ * (STACK_TIM3_PRESCALER + 1))) - 1)
#define ST25R_SPI_INT_Pin ST25R3916_IRQ_Pin
#define ST25R_SPI_INT_GPIO_Port ST25R3916_IRQ_GPIO_Port
#define ST25R_SPI_INT_EXTI_IRQn ST25R3916_IRQ_EXTI_IRQn
#define ST25R_SPI_SS_Pin SPI1_CS_Pin
#define ST25R_SPI_SS_GPIO_Port SPI1_CS_GPIO_Port

#define USE_UART_PORT_AS_GPIO 0
#define NFC_Detected() LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_2)
#define NFC_Undetected() LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_2)

#define USE_LOGGER 1
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
