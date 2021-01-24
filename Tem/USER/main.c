#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

int main(void)
{
	LED_Init();   //LED初始化
	Delay_Init();   //延时初始化
	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_12);

		Delay_ms(500);//延时500微秒
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		//delay(100);		
		Delay_ms(500);//延时500微秒
	}
	


}


