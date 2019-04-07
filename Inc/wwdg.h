#ifndef __WWDG_H__
#define __WWDG_H__

#include <stdint.h>
#include "stm32f4xx_hal.h"
#include "main.h"

/**
  * tr:计数值;  wr:窗口值; fprer:分频系数
  * Fwwdg=PCLK1/(4096*2^fprer)
  */
void WWDG_Init(uint8_t tr,uint8_t wr,uint32_t fprer);
HAL_StatusTypeDef WWDG_Refresh();

#endif //__WWDG_H__