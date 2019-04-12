/**
  ******************************************************************************
  * @file    explorer_stm32_f407.h
  * @author  sunb
  * @brief   This file contains definitions for explorer_stm32_f407.h's LEDs, 
  *          push-buttons and beep hardware resources.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT(c) 2019 STMicroelectronics</center></h2>
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __EXPLORER_STM32_F407_H
#define __EXPLORER_STM32_F407_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"
   
/** @addtogroup BSP
  * @{
  */ 

/** @addtogroup EXPLORER_STM32_F407
  * @{
  */ 
      
/** @addtogroup EXPLORER_STM32_F407_LOW_LEVEL
  * @{
  */ 

/** @defgroup EXPLORER_STM32_F407_LOW_LEVEL_Exported_Types EXPLORER_STM32_F407 EVAL LOW LEVEL Exported Types
  * @{
  */
typedef enum 
{
  LED0 = 0,
  LED1 = 1,
}Led_TypeDef;

typedef enum 
{  
  BUTTON_WKUP = 0,
  BUTTON0     = 1,
  BUTTON1     = 2,
  BUTTON2     = 3,
}Button_TypeDef;

typedef enum 
{  
  BUTTON_MODE_GPIO = 0,
  BUTTON_MODE_EXTI = 1
}ButtonMode_TypeDef;

typedef enum 
{
  COM1 = 0,
}COM_TypeDef;

/**
  * @}
  */ 

/** @defgroup EXPLORER_STM32_F407_LOW_LEVEL_Exported_Constants EXPLORER_STM32_F407 LOW LEVEL Exported Constants
  * @{
  */ 

/** 
  * @brief  Define for STM324xG_EVAL board  
  */ 
#if !defined (EXPLORER_STM32_F407)
 #define USE_EXPLORER_STM32_F407
#endif

/** @addtogroup EXPLORER_STM32_F407_LOW_LEVEL_LED STM324xG EVAL LOW LEVEL LED
  * @{
  */
#define LEDn                             2

#define LED0_PIN                         GPIO_PIN_9
#define LED0_GPIO_PORT                   GPIOF
#define LED0_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOF_CLK_ENABLE()
#define LED0_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOF_CLK_DISABLE()
  
#define LED1_PIN                         GPIO_PIN_10
#define LED1_GPIO_PORT                   GPIOF
#define LED1_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOF_CLK_ENABLE()
#define LED1_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOF_CLK_DISABLE()

#define LEDx_GPIO_CLK_ENABLE(__INDEX__)  do{if((__INDEX__) == 0) LED0_GPIO_CLK_ENABLE(); else \
                                            if((__INDEX__) == 1) LED1_GPIO_CLK_ENABLE(); \
                                            }while(0)
#define LEDx_GPIO_CLK_DISABLE(__INDEX__) do{if((__INDEX__) == 0) LED0_GPIO_CLK_DISABLE(); else \
                                            if((__INDEX__) == 1) LED1_GPIO_CLK_DISABLE(); \
                                            }while(0)
/**
  * @}
  */ 
  
/** @addtogroup EXPLORER_STM32_F407_LOW_LEVEL_KEY EXPLORER_STM32_F407 LOW LEVEL KEY
  * @{
  */ 
#define BUTTONn                              4

/**
  * @brief Key push-button
  */
#define WKUP_BUTTON_PIN                   	GPIO_PIN_0
#define WKUP_BUTTON_GPIO_PORT              GPIOA
#define WKUP_BUTTON_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define WKUP_BUTTON_GPIO_CLK_DISABLE()     __HAL_RCC_GPIOA_CLK_DISABLE()
#define WKUP_BUTTON_EXTI_IRQn              EXTI0_IRQn

#define BUTTON0_PIN                       GPIO_PIN_4
#define BUTTON0_GPIO_PORT                 GPIOE
#define BUTTON0_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOE_CLK_ENABLE()
#define BUTTON0_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOE_CLK_DISABLE()
#define BUTTON0_EXTI_IRQn                 EXTI4_IRQn

#define BUTTON1_PIN                       GPIO_PIN_3
#define BUTTON1_GPIO_PORT                 GPIOE
#define BUTTON1_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOE_CLK_ENABLE()
#define BUTTON1_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOE_CLK_DISABLE()
#define BUTTON1_EXTI_IRQn                 EXTI3_IRQn

#define BUTTON2_PIN                       GPIO_PIN_2
#define BUTTON2_GPIO_PORT                 GPIOE
#define BUTTON2_GPIO_CLK_ENABLE()         __HAL_RCC_GPIOE_CLK_ENABLE()
#define BUTTON2_GPIO_CLK_DISABLE()        __HAL_RCC_GPIOE_CLK_DISABLE()
#define BUTTON2_EXTI_IRQn                 EXTI2_IRQn
					      
#define BUTTONx_GPIO_CLK_ENABLE(__INDEX__)     do{if((__INDEX__) == 0) WKUP_BUTTON_GPIO_CLK_ENABLE(); else \
											   if((__INDEX__) == 1) BUTTON0_GPIO_CLK_ENABLE(); else \
											   if((__INDEX__) == 2) BUTTON1_GPIO_CLK_ENABLE(); else \
											   if((__INDEX__) == 3) BUTTON2_GPIO_CLK_ENABLE(); \
											   }while(0)
#define BUTTONx_GPIO_CLK_DISABLE(__INDEX__)    do{if((__INDEX__) == 0) WKUP_BUTTON_GPIO_CLK_DISABLE(); else \
											   if((__INDEX__) == 1) BUTTON0_GPIO_CLK_DISABLE(); else \
											   if((__INDEX__) == 2) BUTTON1_GPIO_CLK_DISABLE(); else \
											   if((__INDEX__) == 3) BUTTON2_GPIO_CLK_DISABLE(); \
											   }while(0)	
/**
  * @}
  */ 
					     
/** @addtogroup EXPLORER_STM32_F407_LOW_LEVEL_BEEP EXPLORER_STM32_F407 LOW LEVEL BEEP
  * @{
  */ 
#define BEEPn                              1

#define BEEP_PIN                         GPIO_PIN_8
#define BEEP_GPIO_PORT                   GPIOF
#define BEEP_GPIO_CLK_ENABLE()           __HAL_RCC_GPIOF_CLK_ENABLE()
#define BEEP_GPIO_CLK_DISABLE()          __HAL_RCC_GPIOF_CLK_DISABLE()  					   					  

/**
  * @}
  */ 
/** @addtogroup STM324xG_EVAL_LOW_LEVEL_COM STM324xG EVAL LOW LEVEL COM
  * @{
  */
#define COMn                                 1

/**
 * @brief Definition for COM port1, connected to USART1
 */ 
#define BSP_COM1                            USART1
#define BSP_COM1_CLK_ENABLE()               __HAL_RCC_USART1_CLK_ENABLE()
#define BSP_COM1_CLK_DISABLE()              __HAL_RCC_USART1_CLK_DISABLE()

#define BSP_COM1_TX_PIN                     GPIO_PIN_9
#define BSP_COM1_TX_GPIO_PORT               GPIOA
#define BSP_COM1_TX_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define BSP_COM1_TX_GPIO_CLK_DISABLE()      __HAL_RCC_GPIOA_CLK_DISABLE()
#define BSP_COM1_TX_AF                      GPIO_AF7_USART1

#define BSP_COM1_RX_PIN                     GPIO_PIN_10
#define BSP_COM1_RX_GPIO_PORT               GPIOA
#define BSP_COM1_RX_GPIO_CLK_ENABLE()       __HAL_RCC_GPIOA_CLK_ENABLE()
#define BSP_COM1_RX_GPIO_CLK_DISABLE()      __HAL_RCC_GPIOA_CLK_DISABLE()
#define BSP_COM1_RX_AF                      GPIO_AF7_USART1

#define BSP_COM1_IRQn                       USART1_IRQn

#define BSP_COMx_CLK_ENABLE(__INDEX__)              do{if((__INDEX__) == 0) BSP_COM1_CLK_ENABLE(); \
                                                       }while(0)
#define BSP_COMx_CLK_DISABLE(__INDEX__)             do{if((__INDEX__) == 0) BSP_COM1_CLK_DISABLE(); \
                                                       }while(0)

#define BSP_COMx_TX_GPIO_CLK_ENABLE(__INDEX__)      do{if((__INDEX__) == 0) BSP_COM1_TX_GPIO_CLK_ENABLE(); \
                                                       }while(0)
#define BSP_COMx_TX_GPIO_CLK_DISABLE(__INDEX__)     do{if((__INDEX__) == 0) BSP_COM1_TX_GPIO_CLK_DISABLE(); \
                                                       }while(0)

#define BSP_COMx_RX_GPIO_CLK_ENABLE(__INDEX__)      do{if((__INDEX__) == 0) BSP_COM1_RX_GPIO_CLK_ENABLE(); \
                                                       }while(0)
#define BSP_COMx_RX_GPIO_CLK_DISABLE(__INDEX__)     do{if((__INDEX__) == 0) BSP_COM1_RX_GPIO_CLK_DISABLE(); \
                                                       }while(0)  
/**
  * @}
  */                                                        
/**
  * @}
  */ 

/** @defgroup STM324xG_EVAL_LOW_LEVEL_Exported_Functions STM324xG EVAL LOW LEVEL Exported Functions
  * @{
  */
uint32_t         BSP_GetVersion(void);  
void             BSP_LED_Init(Led_TypeDef Led);
void             BSP_LED_On(Led_TypeDef Led);
void             BSP_LED_Off(Led_TypeDef Led);
void             BSP_LED_Toggle(Led_TypeDef Led);
void             BSP_BUTTON_Init(Button_TypeDef Button, ButtonMode_TypeDef Button_Mode);
uint32_t         BSP_BUTTON_GetState(Button_TypeDef Button);
void             BSP_BEEP_Init();
void             BSP_BEEP_On();
void             BSP_BEEP_Off();
void             BSP_BEEP_Toggle();
HAL_StatusTypeDef BSP_COM_Init(COM_TypeDef COM, UART_HandleTypeDef *huart);

/**
  * @}
  */

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

#endif //__EXPLORER_STM32_F407_H