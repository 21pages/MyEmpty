#ifndef _IWDG_H_
#define _IWDG_H_

#ifdef __cplusplus
 extern "C" {
#endif
   
#include "stm32f4xx_hal.h"
#include "stdint.h"
#include "stm32f4xx_hal_iwdg.h"

  

void IWDG_Init(uint8_t prer,uint16_t rlr);//��ʼ��IWDG����ʹ��IWDG
void IWDG_Feed(void);//ι��

#ifdef __cplusplus
}
#endif

#endif //_IWDG_H_