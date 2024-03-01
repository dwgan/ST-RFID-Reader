/**
  ******************************************************************************
  * @file    stm32g0xx_nucleo_bus.c
  * @author  AMS IPC IO-Link Application Team
  * @brief   X_NUCLEO_IOD02A1_application
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

/* Includes ------------------------------------------------------------------*/
#include "stm32g0xx_nucleo_bus.h"

/** @addtogroup IOD02A1_Application IOD02A1_Application
  * @{
  */

/** @defgroup STM32G0xx_NUCLEO_BUS STM32G0xx Nucleo BUS
  * @{
  */

/* Global variables ----------------------------------------------------------*/
/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/** @defgroup STM32G0xx_NUCLEO_BUS_Private_Variables STM32G0xx Nucleo BUS Private Variables
  * @{
  */

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1U)
static uint32_t IsUSART1MspCbValid = 0;
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */
static uint32_t USART1InitCounter = 0;
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
static uint32_t IsSPI1MspCbValid = 0;
#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */
static uint32_t SPI1InitCounter = 0;

/**
  * @}
  */

/** @defgroup STM32G0xx_NUCLEO_BUS_Private_Function_Prototypes STM32G0xx Nucleo BUS Private Function Prototypes
  * @{
  */

/* Private function prototypes -----------------------------------------------*/

//static void USART1_MspInit(UART_HandleTypeDef* huart);
//static void USART1_MspDeInit(UART_HandleTypeDef* huart);
static void SPI1_MspInit(SPI_HandleTypeDef* hSPI);
static void SPI1_MspDeInit(SPI_HandleTypeDef* hSPI);
#if (USE_CUBEMX_BSP_V2 == 1)
static uint32_t SPI_GetPrescaler( uint32_t clk_src_hz, uint32_t baudrate_mbps );
#endif

#if (USE_CUBEMX_BSP_V2 == 1)
static uint32_t I2C_GetTiming(uint32_t clock_src_hz, uint32_t i2cfreq_hz);
static void Compute_PRESC_SCLDEL_SDADEL(uint32_t clock_src_freq, uint32_t I2C_Speed);
static uint32_t Compute_SCLL_SCLH (uint32_t clock_src_freq, uint32_t I2C_speed);
#endif
/**
  * @}
  */


/* Functions Definition ------------------------------------------------------*/

/** @defgroup STM32G0xx_NUCLEO_BUS_Functions_Definition STM32G0xx Nucleo BUS Functions Definition
  * @{
  */

/*******************************************************************************
                            BUS OPERATIONS OVER USART
*******************************************************************************/

/**
  * @brief  Initializes USART HAL.
  * @retval BSP status
  */
//int32_t BSP_USART1_Init(void)
//{
//  int32_t ret = BSP_ERROR_NONE;
//
//  huart1.Instance  = USART1;
//  USART1InitCounter++;
//
//  if (USART1InitCounter == 0U)
//  {
//    if (HAL_UART_GetState(&huart1) == HAL_UART_STATE_RESET)
//    {
//
//#if (USE_HAL_UART_REGISTER_CALLBACKS == 0U)
//      /* Init the UART Msp */
//      USART1_MspInit(&huart1);
//
//      /* Init the UART */
//      MX_USART1_UART_Init();
//#else
//      if (IsUSART1MspCbValid == 0U)
//      {
//        if(BSP_USART1_RegisterDefaultMspCallbacks() != BSP_ERROR_NONE)
//        {
//          ret = BSP_ERROR_MSP_FAILURE;
//        }
//      }
//
//      if (ret == BSP_ERROR_NONE)
//      {
//        /* Init the UART */
//        MX_USART1_UART_Init();
//      }
//#endif
//    }
//  }
//  return ret;
//}

/**
  * @brief  DeInitializes UART HAL.
  * @retval BSP status
  */
//int32_t BSP_USART1_DeInit(void)
//{
//  int32_t ret = BSP_ERROR_BUS_FAILURE;
//
//  if (USART1InitCounter > 0U)
//  {
//    USART1InitCounter--;
//
//    if (USART1InitCounter == 0U)
//    {
//#if (USE_HAL_UART_REGISTER_CALLBACKS == 0U)
//      USART1_MspDeInit(&huart1);
//#endif
//      /* DeInit the UART*/
//      if (HAL_UART_DeInit(&huart1) == HAL_OK)
//      {
//        ret = BSP_ERROR_NONE;
//      }
//    }
//  }
//  return ret;
//}

/**
  * @brief  Write Data through UART BUS.
  * @param  pData: Pointer to data buffer to send
  * @param  Length: Length of data in byte
  * @retval BSP status
  */
int32_t BSP_USART1_Send(uint8_t *pData, uint16_t Length)
{
  int32_t ret = BSP_ERROR_UNKNOWN_FAILURE;

//  if (HAL_UART_Transmit(&huart1, pData, Length, BUS_USART1_POLL_TIMEOUT) == HAL_OK)
//  {
//      ret = BSP_ERROR_NONE;
//  }
  return ret;
}

/**
  * @brief  Receive Data from UART BUS
  * @param  pData: Pointer to data buffer to receive
  * @param  Length: Length of data in byte
  * @retval BSP status
  */
int32_t  BSP_USART1_Recv(uint8_t *pData, uint16_t Length)
{
  int32_t ret = BSP_ERROR_UNKNOWN_FAILURE;

//  if (HAL_UART_Receive(&huart1, pData, Length, BUS_USART1_POLL_TIMEOUT) == HAL_OK)
//  {
//      ret = BSP_ERROR_NONE;
//  }
  return ret;
}

/*******************************************************************************
                            BUS OPERATIONS OVER SPI
*******************************************************************************/

/**
  * @brief  Initializes SPI HAL.
  * @retval BSP status
  */
int32_t BSP_SPI1_Init(void)
{
  int32_t ret = BSP_ERROR_NONE;

  hspi1.Instance = SPI1;
  SPI1InitCounter++;

  if (SPI1InitCounter == 0U)
  {
    if (HAL_SPI_GetState(&hspi1) == HAL_SPI_STATE_RESET)
    {
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 0U)
      /* Init the SPI Msp */
      SPI1_MspInit(&hspi1);
#else
      if (IsSPI1MspCbValid == 0U)
      {
        if(BSP_SPI1_RegisterDefaultMspCallbacks() != BSP_ERROR_NONE)
  		  {
          ret = BSP_ERROR_MSP_FAILURE;
        }
      }

      if (ret == BSP_ERROR_NONE)
      {
        /* Init the SPI */
        MX_SPI1_Init();
      }
#endif
    }
  }

  return ret;
}

/**
  * @brief  DeInitializes SPI HAL.
  * @retval None
  * @retval BSP status
  */
int32_t BSP_SPI1_DeInit(void)
{
  int32_t ret = BSP_ERROR_BUS_FAILURE;
  if (SPI1InitCounter > 0U)
  {
    SPI1InitCounter--;

    if (SPI1InitCounter == 0U)
    {
#if (USE_HAL_SPI_REGISTER_CALLBACKS == 0U)
      SPI1_MspDeInit(&hspi1);
#endif
      /* DeInit the SPI*/
      if (HAL_SPI_DeInit(&hspi1) == HAL_OK)
      {
        ret = BSP_ERROR_NONE;
      }
    }
  }
  return ret;
}

/**
  * @brief  Write Data through SPI BUS.
  * @param  pData: Pointer to data buffer to send
  * @param  Length: Length of data in byte
  * @retval BSP status
  */
int32_t BSP_SPI1_Send(uint8_t *pData, uint16_t Length)
{
  int32_t ret = BSP_ERROR_NONE;

  if (HAL_SPI_Transmit(&hspi1, pData, Length, BUS_SPI1_POLL_TIMEOUT) != HAL_OK)
  {
    ret = BSP_ERROR_UNKNOWN_FAILURE;
  }
  return ret;
}

/**
  * @brief  Receive Data from SPI BUS
  * @param  pData: Pointer to data buffer to receive
  * @param  Length: Length of data in byte
  * @retval BSP status
  */
int32_t  BSP_SPI1_Recv(uint8_t *pData, uint16_t Length)
{
  int32_t ret = BSP_ERROR_NONE;

  if (HAL_SPI_Receive(&hspi1, pData, Length, BUS_SPI1_POLL_TIMEOUT) != HAL_OK)
  {
    ret = BSP_ERROR_UNKNOWN_FAILURE;
  }
  return ret;
}

///**
//  * @brief  Send and Receive data to/from SPI BUS (Full duplex)
//  * @param  pTxData: Pointer to Tx data buffer to send
//  * @param  pRxData: Pointer to Rx data buffer to receive
//  * @param  Length: Length of data in byte
//  * @retval BSP status
//  */
//int32_t BSP_SPI1_SendRecv(uint8_t *pTxData, uint8_t *pRxData, uint16_t Length)
//{
//  int32_t ret = BSP_ERROR_NONE;
//
//  if (HAL_SPI_TransmitReceive(&hspi1, pTxData, pRxData, Length, BUS_SPI1_POLL_TIMEOUT) != HAL_OK)
//  {
//    ret = BSP_ERROR_UNKNOWN_FAILURE;
//  }
//  return ret;
//}

#if (USE_HAL_UART_REGISTER_CALLBACKS == 1U)
/**
  * @brief Register Default BSP USART1 Bus Msp Callbacks
  * @retval BSP status
  */
int32_t BSP_USART1_RegisterDefaultMspCallbacks (void)
{

  __HAL_UART_RESET_HANDLE_STATE(&huart1);

  /* Register MspInit Callback */
  if (HAL_UART_RegisterCallback(&huart1, HAL_UART_MSPINIT_CB_ID, USART1_MspInit)  != HAL_OK)
  {
    return BSP_ERROR_PERIPH_FAILURE;
  }

  /* Register MspDeInit Callback */
  if (HAL_UART_RegisterCallback(&huart1, HAL_UART_MSPDEINIT_CB_ID, USART1_MspDeInit) != HAL_OK)
  {
    return BSP_ERROR_PERIPH_FAILURE;
  }
  IsUSART1MspCbValid = 1;

  return BSP_ERROR_NONE;
}

/**
  * @brief BSP USART1 Bus Msp Callback registering
  * @param Callbacks     pointer to USART1 MspInit/MspDeInit callback functions
  * @retval BSP status
  */
int32_t BSP_USART1_RegisterMspCallbacks (BSP_UART_Cb_t *Callbacks)
{
  /* Prevent unused argument(s) compilation warning */
  __HAL_UART_RESET_HANDLE_STATE(&huart1);

   /* Register MspInit Callback */
  if (HAL_UART_RegisterCallback(&huart1, HAL_UART_MSPINIT_CB_ID, Callbacks->pMspInitCb)  != HAL_OK)
  {
    return BSP_ERROR_PERIPH_FAILURE;
  }

  /* Register MspDeInit Callback */
  if (HAL_UART_RegisterCallback(&huart1, HAL_UART_MSPDEINIT_CB_ID, Callbacks->pMspDeInitCb) != HAL_OK)
  {
    return BSP_ERROR_PERIPH_FAILURE;
  }

  IsUSART1MspCbValid = 1;

  return BSP_ERROR_NONE;
}
#endif /* USE_HAL_UART_REGISTER_CALLBACKS */

#if (USE_HAL_SPI_REGISTER_CALLBACKS == 1U)
/**
  * @brief Register Default BSP SPI1 Bus Msp Callbacks
  * @retval BSP status
  */
int32_t BSP_SPI1_RegisterDefaultMspCallbacks (void)
{

  __HAL_SPI_RESET_HANDLE_STATE(&hspi1);

  /* Register MspInit Callback */
  if (HAL_SPI_RegisterCallback(&hspi1, HAL_SPI_MSPINIT_CB_ID, SPI1_MspInit)  != HAL_OK)
  {
    return BSP_ERROR_PERIPH_FAILURE;
  }

  /* Register MspDeInit Callback */
  if (HAL_SPI_RegisterCallback(&hspi1, HAL_SPI_MSPDEINIT_CB_ID, SPI1_MspDeInit) != HAL_OK)
  {
    return BSP_ERROR_PERIPH_FAILURE;
  }
  IsSPI1MspCbValid = 1;

  return BSP_ERROR_NONE;
}

/**
  * @brief BSP SPI1 Bus Msp Callback registering
  * @param Callbacks pointer to SPI1 MspInit/MspDeInit callback functions
  * @retval BSP status
  */
int32_t BSP_SPI1_RegisterMspCallbacks (BSP_SPI_Cb_t *Callbacks)
{
  /* Prevent unused argument(s) compilation warning */
  __HAL_SPI_RESET_HANDLE_STATE(&hspi1);

   /* Register MspInit Callback */
  if (HAL_SPI_RegisterCallback(&hspi1, HAL_SPI_MSPINIT_CB_ID, Callbacks->pMspInitCb)  != HAL_OK)
  {
    return BSP_ERROR_PERIPH_FAILURE;
  }

  /* Register MspDeInit Callback */
  if (HAL_SPI_RegisterCallback(&hspi1, HAL_SPI_MSPDEINIT_CB_ID, Callbacks->pMspDeInitCb) != HAL_OK)
  {
    return BSP_ERROR_PERIPH_FAILURE;
  }

  IsSPI1MspCbValid = 1;

  return BSP_ERROR_NONE;
}

#endif /* USE_HAL_SPI_REGISTER_CALLBACKS */

/**
  * @brief  Return system tick in ms
  * @retval Current HAL time base time stamp
  */
uint32_t BSP_GetTick(void)
{
  return HAL_GetTick();
}

static void SPI1_MspInit(SPI_HandleTypeDef* spiHandle)
{
  UNUSED(spiHandle);

  GPIO_InitTypeDef GPIO_InitStruct;

    /* Enable Peripheral clock */
    __HAL_RCC_SPI1_CLK_ENABLE();

    __HAL_RCC_GPIOA_CLK_ENABLE();
    /**SPI1 GPIO Configuration
    PA5     ------> SPI1_SCK
    PA6     ------> SPI1_MISO
    PA7     ------> SPI1_MOSI
    */
    GPIO_InitStruct.Pin = BUS_SPI1_SCK_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_PULLUP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = BUS_SPI1_SCK_GPIO_AF;
    HAL_GPIO_Init(BUS_SPI1_SCK_GPIO_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = BUS_SPI1_MISO_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = BUS_SPI1_MISO_GPIO_AF;
    HAL_GPIO_Init(BUS_SPI1_MISO_GPIO_PORT, &GPIO_InitStruct);

    GPIO_InitStruct.Pin = BUS_SPI1_MOSI_GPIO_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = BUS_SPI1_MOSI_GPIO_AF;
    HAL_GPIO_Init(BUS_SPI1_MOSI_GPIO_PORT, &GPIO_InitStruct);

}

static void SPI1_MspDeInit(SPI_HandleTypeDef* spiHandle)
{
    UNUSED(spiHandle);

    /* Peripheral clock disable */
    __HAL_RCC_SPI1_CLK_DISABLE();

    /**SPI1 GPIO Configuration
    PA5     ------> SPI1_SCK
    PA6     ------> SPI1_MISO
    PA7     ------> SPI1_MOSI
    */
    HAL_GPIO_DeInit(BUS_SPI1_SCK_GPIO_PORT, BUS_SPI1_SCK_GPIO_PIN);

    HAL_GPIO_DeInit(BUS_SPI1_MISO_GPIO_PORT, BUS_SPI1_MISO_GPIO_PIN);

    HAL_GPIO_DeInit(BUS_SPI1_MOSI_GPIO_PORT, BUS_SPI1_MOSI_GPIO_PIN);
}

/* USART1 init function */

//static void USART1_MspInit(UART_HandleTypeDef* uartHandle)
//{
//  UNUSED(uartHandle);
//
//  GPIO_InitTypeDef GPIO_InitStruct;
//
//  /* Enable Peripheral clock */
//    __HAL_RCC_USART1_CLK_ENABLE();
//
//    __HAL_RCC_GPIOA_CLK_ENABLE();
//    /**USART1 GPIO Configuration
//    PA9     ------> USART1_TX
//    PA10     ------> USART1_RX
//    */
//    GPIO_InitStruct.Pin = BUS_USART1_TX_GPIO_PIN;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_PULLUP;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//    GPIO_InitStruct.Alternate = BUS_USART1_TX_GPIO_AF;
//    HAL_GPIO_Init(BUS_USART1_TX_GPIO_PORT, &GPIO_InitStruct);
//
//    GPIO_InitStruct.Pin = BUS_USART1_RX_GPIO_PIN;
//    GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
//    GPIO_InitStruct.Pull = GPIO_NOPULL;
//    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
//    GPIO_InitStruct.Alternate = BUS_USART1_RX_GPIO_AF;
//    HAL_GPIO_Init(BUS_USART1_RX_GPIO_PORT, &GPIO_InitStruct);
//
//    /* Peripheral interrupt init */
//    HAL_NVIC_SetPriority(USART1_IRQn, 3, 0);
//    HAL_NVIC_EnableIRQ(USART1_IRQn);
//}

//static void USART1_MspDeInit(UART_HandleTypeDef* uartHandle)
//{
//    UNUSED(uartHandle);
//
//    /* Peripheral clock disable */
//    __HAL_RCC_USART1_CLK_DISABLE();
//
//    /**USART1 GPIO Configuration
//    PA9     ------> USART1_TX
//    PA10     ------> USART1_RX
//    */
//    HAL_GPIO_DeInit(BUS_USART1_TX_GPIO_PORT, BUS_USART1_TX_GPIO_PIN);
//
//    HAL_GPIO_DeInit(BUS_USART1_RX_GPIO_PORT, BUS_USART1_RX_GPIO_PIN);
//
//    /* Peripheral interrupt Deinit*/
//    HAL_NVIC_DisableIRQ(USART1_IRQn);
//}

#if (USE_CUBEMX_BSP_V2 == 1)
/**
  * @brief  Convert the SPI baudrate into prescaler.
  * @param  clock_src_hz : SPI source clock in HZ.
  * @param  baudrate_mbps : SPI baud rate in mbps.
  * @retval Prescaler dividor
  */
static uint32_t SPI_GetPrescaler( uint32_t clock_src_hz, uint32_t baudrate_mbps )
{
  uint32_t divisor = 0;
  uint32_t spi_clk = clock_src_hz;
  uint32_t presc = 0;

  static const uint32_t baudrate[]=
  {
    SPI_BAUDRATEPRESCALER_2,
    SPI_BAUDRATEPRESCALER_4,
    SPI_BAUDRATEPRESCALER_8,
    SPI_BAUDRATEPRESCALER_16,
    SPI_BAUDRATEPRESCALER_32,
    SPI_BAUDRATEPRESCALER_64,
    SPI_BAUDRATEPRESCALER_128,
    SPI_BAUDRATEPRESCALER_256,
  };

  while (spi_clk > baudrate_mbps)
  {
    presc = baudrate[divisor];
    if (++divisor > 7)
      break;

    spi_clk = (spi_clk >> 1);
  }

  return presc;
}
#endif

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */
