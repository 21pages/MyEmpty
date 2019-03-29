#ifndef KEY_H
#define KEY_H

#include <stdint.h>

#define KEY_NO_ONE 0
#define KEY_0_PRESS(x) BIT0 (x)
#define KEY_1_PRESS(x) BIT1 (x)
#define KEY_2_PRESS(x) BIT2 (x)
#define KEY_UP_PRESS(x) BIT3 (x)

uint8_t get_key_press (void);
uint8_t key_scan (void);
void on_key_press ();

#endif // KEY_H