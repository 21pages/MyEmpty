/**
  ******************************************************************************
  * @file    explorer_stm32_f407.c
  * @author  MCD Application Team
  * @brief   This file provides a set of firmware functions to manage LEDs, 
  *          push-buttons and COM ports available on EXPLORER_STM32_F407 evaluation 
  *          board(MB786) RevB from STMicroelectronics.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2017 STMicroelectronics</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "explorer_stm32_f407.h"

/** @defgroup BSP BSP
  * @{
  */ 

/** @defgroup EXPLORER_STM32_F407 EXPLORER_STM32 F407
  * @{
  */   
    
/** @defgroup SEXPLORER_STM32_F407_LOW_LEVEL  EXPLORER_STM32_F407 LOW LEVEL
  * @{
  */ 
/** @defgroup STM324xG_EVAL_LOW_LEVEL_Private_TypesDefinitions STM324xG EVAL LOW LEVEL Private TypesDefinitions
  * @{
  */ 
  
/**
  * @}
  */
/**
  * @brief STM32407  BSP Driver version number V3.0.2
  */
#define __STM32407_BSP_VERSION_MAIN   (0x03) /*!< [31:24] main version */
#define __STM32407_BSP_VERSION_SUB1   (0x00) /*!< [23:16] sub1 version */
#define __STM32407_BSP_VERSION_SUB2   (0x02) /*!< [15:8]  sub2 version */
#define __STM32407_BSP_VERSION_RC     (0x00) /*!< [7:0]  release candidate */ 
#define __STM32407_BSP_VERSION         ((__STM32407_BSP_VERSION_MAIN << 24)\
                                             |(__STM32407_BSP_VERSION_SUB1 << 16)\
                                             |(__STM32407_BSP_VERSION_SUB2 << 8 )\
                                             |(__STM32407_BSP_VERSION_RC))  
/**
  * @}
  */ 

/** @defgroup STM324xG_EVAL_LOW_LEVEL_Private_Variables STM324xG EVAL LOW LEVEL Private Variables
  * @{
  */ 
GPIO_TypeDef* LED_PORT[LEDn] = {LED0_GPIO_PORT, 
                                LED1_GPIO_PORT};

const uint16_t LED_PIN[LEDn] = {LED0_PIN, 
                                LED1_PIN};

GPIO_TypeDef* BUTTON_PORT[BUTTONn] = {WKUP_BUTTON_GPIO_PORT, 
		                              BUTTON0_GPIO_PORT,
		                              BUTTON1_GPIO_PORT,
		                              BUTTON2_GPIO_PORT}; 

const uint16_t BUTTON_PIN[BUTTONn] = {WKUP_BUTTON_PIN, 
	                                  BUTTON0_PIN,
	                                  BUTTON1_PIN,
	                                  BUTTON2_PIN}; 

const IRQn_Type BUTTON_IRQn[BUTTONn] = {WKUP_BUTTON_EXTI_IRQn, 
                                       BUTTON0_EXTI_IRQn,
                                       BUTTON1_EXTI_IRQn,
                                       BUTTON2_EXTI_IRQn};

USART_TypeDef* COM_USART[COMn] = {BSP_COM1}; 

GPIO_TypeDef* COM_TX_PORT[COMn] = {BSP_COM1_TX_GPIO_PORT};
 
GPIO_TypeDef* COM_RX_PORT[COMn] = {BSP_COM1_RX_GPIO_PORT};

const uint16_t COM_TX_PIN[COMn] = {BSP_COM1_TX_PIN};

const uint16_t COM_RX_PIN[COMn] = {BSP_COM1_RX_PIN};
 
const uint16_t COM_TX_AF[COMn] = {BSP_COM1_TX_AF};
 
const uint16_t COM_RX_AF[COMn] = {BSP_COM1_RX_AF};

/**
  * @}
  */  
/**
  * @brief  This method returns the STM32407 BSP Driver revision
  * @retval version: 0xXYZR (8bits for each decimal, R for RC)
  */  
uint32_t BSP_GetVersion(void)
{
	return __STM32407_BSP_VERSION;
}

/**
  * @brief  Configures LED GPIO.
  * @param  Led: LED to be configured. 
  *          This parameter can be one of the following values:
  *            @arg  LED0
  *            @arg  LED1
  */
void BSP_LED_Init(Led_TypeDef Led)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/*Enable the GPIO_LED clock*/
	LEDx_GPIO_CLK_ENABLE(Led);
	
	
	/*Configure the GPIO_LEN pin*/
	GPIO_InitStruct.Pin = LED_PIN[Led];
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_LOW;

	HAL_GPIO_Init(LED_PORT[Led], &GPIO_InitStruct);
	
}

/**
  * @brief  Turns selected LED On.
  * @param  Led: LED to be set on 
  *          This parameter can be one of the following values:
  *            @arg  LED0
  *            @arg  LED1
  */
void BSP_LED_On(Led_TypeDef Led)
{
	HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET);
}

/**
  * @brief  Turns selected LED Off.
  * @param  Led: LED to be set off 
  *          This parameter can be one of the following values:
  *            @arg  LED0
  *            @arg  LED1
  */
void BSP_LED_Off(Led_TypeDef Led)
{
	HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_SET);
}

/**
  * @brief  Toggle selected LED.
  * @param  Led: LED to be toggled 
  *          This parameter can be one of the following values:
  *            @arg  LED0
  *            @arg  LED1
  */
void BSP_LED_Toggle(Led_TypeDef Led)
{
	HAL_GPIO_TogglePin(LED_PORT[Led], LED_PIN[Led]);
}
/**
  *@brief Init the button
  *@param Button:the button to be inited
  *        This parameter can be one of the following values:
  *				@arg  BUTTON_WKUP
  *				@arg  BUTTON0
  *				@arg  BUTTON1
  *				@arg  BUTTON2  
  *       Button_Mode:Button mode
  *				@arg  BUTTON_MODE_GPIO  
  *				@arg  BUTTON_MODE_EXTI    
  */
void BSP_BUTTON_Init(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	/*enable the GPIO clock*/
	BUTTONx_GPIO_CLK_ENABLE(Button);

	GPIO_InitStruct.Pin = BUTTON_PIN[Button];
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	
	if (BUTTON_MODE_GPIO == Button_Mode) {
		
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	} else {
	
		if (BUTTON_WKUP == Button) {
			
			GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
		} else {
			
			GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
		}
		HAL_NVIC_SetPriority(BUTTON_IRQn[Button], 15, 0);
		HAL_NVIC_EnableIRQ(BUTTON_IRQn[Button]);
	}
	HAL_GPIO_Init(BUTTON_PORT[Button], &GPIO_InitStruct);
}

/**
  *@brief Returns the selected button state.
  *@param Button:the button to be checked
  *        This parameter can be one of the following values:
  *				@arg  BUTTON_WKUP
  *				@arg  BUTTON0
  *				@arg  BUTTON1
  *				@arg  BUTTON2  
  *@retval The Button GPIO pin value
  */
uint32_t BSP_BUTTON_GetState(Button_TypeDef Button)
{
	return HAL_GPIO_ReadPin(BUTTON_PORT[Button], BUTTON_PIN[Button]);
}

/**
  * @brief  Configures BEEP GPIO.
  */
void BSP_BEEP_Init()
{
	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin = BEEP_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(BEEP_GPIO_Port, &GPIO_InitStruct);
	
}

/**
  *@brief Turn the beep on
  */
void BSP_BEEP_On()
{
	HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_PIN, GPIO_PIN_SET);
}

/**
  *@brief Turn the beep off
  */
void BSP_BEEP_Off()
{
	HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_PIN, GPIO_PIN_RESET);
}

/**
  *@brief Toggle the beep
  */
void BSP_BEEP_Toggle()
{
	HAL_GPIO_TogglePin(BEEP_GPIO_Port, BEEP_PIN);
}

/**
  * @brief  Configures COM port.
  * @param  COM: COM port to be configured.
  *          This parameter can be one of the following values:
  *            @arg  COM1 
  * @param  huart: Pointer to a UART_HandleTypeDef structure that contains the
  *                configuration information for the specified USART peripheral.
  */
HAL_StatusTypeDef BSP_COM_Init(COM_TypeDef COM, UART_HandleTypeDef *huart)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	/*Enable GPIO Clock*/
	BSP_COM1_TX_GPIO_CLK_ENABLE();
	BSP_COM1_RX_GPIO_CLK_ENABLE();

	/*Enable USART Clock*/
	BSP_COM1_CLK_ENABLE();

	/*Configure USART Tx as alternate function*/
	GPIO_InitStruct.Pin = COM_TX_PIN[COM];
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Alternate = COM_TX_AF[COM];
	HAL_GPIO_Init(COM_TX_PORT[COM], &GPIO_InitStruct);

	/*Configure USART Rx as alternate function*/
	GPIO_InitStruct.Pin = COM_RX_PIN[COM];
	GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
	GPIO_InitStruct.Alternate = COM_RX_AF[COM];
	HAL_GPIO_Init(COM_RX_PORT[COM], &GPIO_InitStruct);

	/* USART configuration */
	huart->Instance = COM_USART[COM];
	return HAL_UART_Init(huart);
}