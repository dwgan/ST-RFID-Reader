/**
  ******************************************************************************
  * @file    stm32g0xx_nucleo_errno.h
  * @author  AMS IPC IO-Link Application Team
  * @brief   Header for error code
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2020-2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32G0XX_NUCLEO_ERRNO_H
#define STM32G0XX_NUCLEO_ERRNO_H

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup IOD02A1_Application IOD02A1_Application
 * @{
 */

/* Includes ------------------------------------------------------------------*/
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/

/** @defgroup IOD02A1_Application_Exported_Constants IOD02A1_Application Exported Constants
 * @{
 */

/* Common Error codes */
/** No BSP Error code */
#define BSP_ERROR_NONE                    0
/** BSP No Init Error code */
#define BSP_ERROR_NO_INIT                -1
/** BSP Wrong Parameter Error code */
#define BSP_ERROR_WRONG_PARAM            -2
/** BSP Busy Error code */
#define BSP_ERROR_BUSY                   -3
/** BSP Peripheral Failure Error code */
#define BSP_ERROR_PERIPH_FAILURE         -4
/** BSP Component Failure Error code */
#define BSP_ERROR_COMPONENT_FAILURE      -5
/** BSP Unknown Failure Error code */
#define BSP_ERROR_UNKNOWN_FAILURE        -6
/** BSP Unknown Component Error code */
#define BSP_ERROR_UNKNOWN_COMPONENT      -7
/** BSP Bus Failure Error code */
#define BSP_ERROR_BUS_FAILURE            -8
/** BSP Clock Failure Error code */
#define BSP_ERROR_CLOCK_FAILURE          -9
/** BSP Msp Failure Error code */
#define BSP_ERROR_MSP_FAILURE            -10
/** BSP Msp Feature Not Supported Error code */
#define BSP_ERROR_FEATURE_NOT_SUPPORTED  -11

/* BSP BUS error codes */

#define BSP_ERROR_BUS_TRANSACTION_FAILURE    -100
#define BSP_ERROR_BUS_ARBITRATION_LOSS       -101
#define BSP_ERROR_BUS_ACKNOWLEDGE_FAILURE    -102
#define BSP_ERROR_BUS_PROTOCOL_FAILURE       -103

#define BSP_ERROR_BUS_MODE_FAULT             -104
#define BSP_ERROR_BUS_FRAME_ERROR            -105
#define BSP_ERROR_BUS_CRC_ERROR              -106
#define BSP_ERROR_BUS_DMA_FAILURE            -107

/**
  * @}
  */

/* External variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* STM32G0XX_NUCLEO_ERRNO_H */
