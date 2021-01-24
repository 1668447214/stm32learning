#ifndef _DELAY_H
#define _DELAY_H
#include "stdint.h"


//void delay(uint16_t timers);
void Delay_Init(void);
void Delay_us(uint32_t nus);
void Delay_ms(uint32_t nms);



#endif



