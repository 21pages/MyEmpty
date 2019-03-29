
#include "wwdg.h"

uint8_t WWDG_CNT=0X7F;
void WWDG_Init(uint8_t tr, uint8_t wr, uint32_t fprer)
{
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_WWDG, ENABLE);

	//使能窗口看门狗时钟
	WWDG_CNT			= tr & WWDG_CNT;			//初始化 WWDG_CNT.
	WWDG_SetPrescaler(fprer);						//设置分频值
	WWDG_SetWindowValue(wr);						//设置窗口值
	WWDG_SetCounter(WWDG_CNT);						//设置计数值
	WWDG_Enable(WWDG_CNT);							//开启看门狗
	NVIC_InitStructure.NVIC_IRQChannel = WWDG_IRQn; //窗口看门狗中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x02; //抢占优先级为 2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x03; //响应优先级为 3
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //使能窗口看门狗
	NVIC_Init(&NVIC_InitStructure);
	WWDG_ClearFlag();								//清除提前唤醒中断标志位
	WWDG_EnableIT();								//开启提前唤醒中断
}

