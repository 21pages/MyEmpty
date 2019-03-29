#include "key.h"
#include "main.h"
#include "stm32f4xx_hal.h"

extern void uart_log (const char *fmt, ...);

#define KEY_DELAY_TIMES 10

volatile uint8_t key_scan_flag = 0;

uint8_t
get_key_press (void)
{
    uint8_t key0_state = 0;
    uint8_t key1_state = 0;
    uint8_t key2_state = 0;
    uint8_t keyUp_state = 0;
    key0_state = !HAL_GPIO_ReadPin (KEY0_GPIO_Port, KEY0_Pin);
    key1_state = !HAL_GPIO_ReadPin (KEY1_GPIO_Port, KEY1_Pin);
    key2_state = !HAL_GPIO_ReadPin (KEY2_GPIO_Port, KEY2_Pin);
    keyUp_state = HAL_GPIO_ReadPin (KEY_WKUP_GPIO_Port, KEY_WKUP_Pin);
    return key0_state + (key1_state << 1) + (key2_state << 2) +
           (keyUp_state << 3);
}

uint8_t
key_scan (void)
{
    static uint8_t key_result = KEY_NO_ONE;
    static uint8_t scan_times = 0;
    key_scan_flag = 0;
    key_result = get_key_press ();
    if (key_result != KEY_NO_ONE) {
        if (get_key_press () == key_result) {
            if (scan_times < KEY_DELAY_TIMES) {
                ++scan_times;
            } else {
                return key_result;
            }
        } else {
            scan_times = 0;
        }
    } else {
        scan_times = 0;
    }
    return KEY_NO_ONE;
}

void
on_key_press ()
{
    uint8_t key_val = 0;
    key_scan_flag = 1;
    if (key_scan_flag) {
        key_val = key_scan ();
        if (KEY_0_PRESS (key_val) == 1) {
            HAL_GPIO_WritePin (LED0_GPIO_Port, LED0_Pin, GPIO_PIN_RESET);
        } else {
            HAL_GPIO_WritePin (LED0_GPIO_Port, LED0_Pin, GPIO_PIN_SET);
        }

        if (KEY_1_PRESS (key_val) == 1) {
            HAL_GPIO_WritePin (LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
        } else {
            HAL_GPIO_WritePin (LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
        }

        if (KEY_2_PRESS (key_val) == 1) {
            HAL_GPIO_WritePin (BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_SET);
        } else {
            HAL_GPIO_WritePin (BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET);
        }
        if (KEY_UP_PRESS (key_val) == 1) {
            uart_log ("%d\r\n", HAL_GetTick ());
        }
    }
}