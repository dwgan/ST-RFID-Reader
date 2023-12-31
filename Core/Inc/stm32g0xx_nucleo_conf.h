/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : stm32g0xx_nucleo_conf.h
  * @brief          : Configuration file
  ******************************************************************************
  ******************************************************************************
*/
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32G0XX_NUCLEO_CONF_H
#define STM32G0XX_NUCLEO_CONF_H

#ifdef __cplusplus
extern "C" {
#endif
/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/** @addtogroup STM32G0xx STM32G0xx
  * @{
  */

/** @defgroup STM32G0xx_NUCLEO_CONFIG STM32G0xx Nucleo Config
  * @{
  */

/** @defgroup STM32G0xx_NUCLEO_CONFIG_Exported_Constants STM32G0xx Nucleo Config Exported Constants
  * @{
  */
/* COM Feature define */
#define USE_BSP_COM_FEATURE                 0U

/* COM define */
#define USE_COM_LOG                         1U

/* IRQ priorities */
#define BSP_BUTTON_USER_IT_PRIORITY         15U

/* SPI1 Baud rate in bps  */
#define BUS_SPI1_BAUDRATE                   16000000U /* baud rate of SPIn = 16 Mbps */

/* UART1 Baud rate in bps  */
#define BUS_UART1_BAUDRATE                  9600U /* baud rate of UARTn = 9600 baud */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif  /* STM32G0XX_NUCLEO_CONF_H */
