#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"


int main(void)
{
	u8 t = 0;//调试用，对于变量的声明不能放在可执行语句后面，必须在主函数开头声明变量。
	LED_Init();
	Delay_Init();

	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(500);
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(500);
		t++;
	}
	
}

