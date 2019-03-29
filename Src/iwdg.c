#include "iwdg.h"
#include "__def.h"

IWDG_HandleTypeDef IWDG_Handler;

//��ʼ���������Ź�
//prer:��Ƶ��:IWDG_PRESCALER_4~IWDG_PRESCALER_256
//rlr:�Զ���װ��ֵ,0~0XFFF.
//ʱ�����(���):Tout=((4*2^prer)*rlr)/32 (ms).
void
IWDG_Init (uint8_t prer, uint16_t rlr)
{
    IWDG_Handler.Instance = IWDG;
    IWDG_Handler.Init.Prescaler = prer;
    IWDG_Handler.Init.Reload = rlr;
    HAL_IWDG_Init (&IWDG_Handler);
}

void
IWDG_Feed (void)
{
    HAL_IWDG_Refresh (&IWDG_Handler); 
}