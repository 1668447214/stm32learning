#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
#include "beep.h"


int main()
{
	Delay_Init();
	LED_Init();
	BeepInit();
	
	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_8);
		Delay_ms(500);
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
		Delay_ms(500);
	}
	
	
}


