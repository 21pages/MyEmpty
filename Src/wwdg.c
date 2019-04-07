#include "wwdg.h"

#ifdef HAL_WWDG_MODULE_ENABLED
#include "explorer_stm32_f407.h"

#define  WWDG_COUNTER_MASK  0X7F
static WWDG_HandleTypeDef hwwdg;


/**
  *@brief init the WWDG
  *@param tr:counter,0x7F~0x40
  *	      wr:window value,0x7F~0x40,tr>wr
  *       fprer: WWDG_PRESCALER_1,WWDG_PRESCALER_2,WWDG_PRESCALER_4,WWDG_PRESCALER_8
  */
void WWDG_Init(uint8_t tr, uint8_t wr, uint32_t fprer)
{
    hwwdg.Instance = WWDG;
    hwwdg.Init.Prescaler = fprer;
    hwwdg.Init.Window    = wr;
    hwwdg.Init.Counter   = tr & WWDG_COUNTER_MASK;
    hwwdg.Init.EWIMode   = WWDG_EWI_ENABLE;

    if(HAL_WWDG_Init(&hwwdg) != HAL_OK)
    {
		Error_Handler();
    }
	
}

void HAL_WWDG_MspInit(WWDG_HandleTypeDef *hwwdg)
{
    /* Prevent unused argument(s) compilation warning */
    UNUSED(hwwdg);

    /*Enable the WWDG Clock*/
    __HAL_RCC_WWDG_CLK_ENABLE();

	HAL_NVIC_SetPriority(WWDG_IRQn,1,0);
    HAL_NVIC_EnableIRQ(WWDG_IRQn);
}


void HAL_WWDG_EarlyWakeupCallback(WWDG_HandleTypeDef* hwwdg)
{
	/* Prevent unused argument(s) compilation warning */
	UNUSED(hwwdg);

	WWDG_Refresh();
	BSP_BEEP_On();	
}


HAL_StatusTypeDef WWDG_Refresh()
{
  return HAL_WWDG_Refresh(&hwwdg);
}


#endif

