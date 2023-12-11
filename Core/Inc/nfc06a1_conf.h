/**
  ******************************************************************************
  * @file    nfc06a1_conf.h
  * @author  MMY Application Team
  * @brief   This file contains definitions for the NFC6 components bus interfaces
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef NFC06A1_CONF_H_
#define NFC06A1_CONF_H_

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_hal.h"

/** @addtogroup BSP
  * @{
  */

/** @addtogroup NFC06A1
  * @{
  */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/** @defgroup NFC06A1_Exported_Constants
  * @{
  */

#define NFC06A1_LED1_PIN_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE();
#define NFC06A1_LED2_PIN_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE();
#define NFC06A1_LED3_PIN_CLK_ENABLE()     __HAL_RCC_GPIOB_CLK_ENABLE();
#define NFC06A1_LED4_PIN_CLK_ENABLE()     __HAL_RCC_GPIOC_CLK_ENABLE();
#define NFC06A1_LED5_PIN_CLK_ENABLE()     __HAL_RCC_GPIOC_CLK_ENABLE();
#define NFC06A1_LED6_PIN_CLK_ENABLE()     __HAL_RCC_GPIOA_CLK_ENABLE();
#define NFC06A1_LED1_PIN_CLK_DISABLE()    __HAL_RCC_GPIOA_CLK_DISABLE();
#define NFC06A1_LED2_PIN_CLK_DISABLE()    __HAL_RCC_GPIOA_CLK_DISABLE();
#define NFC06A1_LED3_PIN_CLK_DISABLE()    __HAL_RCC_GPIOB_CLK_DISABLE();
#define NFC06A1_LED4_PIN_CLK_DISABLE()    __HAL_RCC_GPIOC_CLK_DISABLE();
#define NFC06A1_LED5_PIN_CLK_DISABLE()    __HAL_RCC_GPIOC_CLK_DISABLE();
#define NFC06A1_LED6_PIN_CLK_DISABLE()    __HAL_RCC_GPIOA_CLK_DISABLE();
#define NFC06A1_LED1_PIN                  GPIO_PIN_1
#define NFC06A1_LED1_PIN_PORT             GPIOA
#define NFC06A1_LED2_PIN                  GPIO_PIN_4
#define NFC06A1_LED2_PIN_PORT             GPIOA
#define NFC06A1_LED3_PIN                  GPIO_PIN_0
#define NFC06A1_LED3_PIN_PORT             GPIOB
#define NFC06A1_LED4_PIN                  GPIO_PIN_1
#define NFC06A1_LED4_PIN_PORT             GPIOC
#define NFC06A1_LED5_PIN                  GPIO_PIN_0
#define NFC06A1_LED5_PIN_PORT             GPIOC
#define NFC06A1_LED6_PIN                  GPIO_PIN_8
#define NFC06A1_LED6_PIN_PORT             GPIOA
/**
  * @}
  */

/* Exported macro ------------------------------------------------------------*/
/** @defgroup NFC06A1_Exported_Macro
  * @{
  */

#define NFC06A1_ALLLED_GPIO_CLK_ENABLE()  do{__HAL_RCC_GPIOA_CLK_ENABLE(); \
                                             __HAL_RCC_GPIOB_CLK_ENABLE(); \
                                             __HAL_RCC_GPIOC_CLK_ENABLE(); \
                                            }while(0)
                                              
#define NFC06A1_ALLLED_GPIO_CLK_DISABLE() do{__HAL_RCC_GPIOA_CLK_DISABLE(); \
                                             __HAL_RCC_GPIOB_CLK_DISABLE(); \
                                             __HAL_RCC_GPIOC_CLK_DISABLE(); \
                                            }while(0)
/**
  * @}
  */

/* Exported variables --------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

/**
  * @}
  */

/**
  * @}
  */
                                              
#ifdef __cplusplus
}
#endif
                                            
#endif /* NFC06A1_CONF_H_ */

