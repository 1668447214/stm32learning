#include "stm32f10x.h"
#include "led.h"
#include "delay.h"

int main(void)
{
	LED_Init();   //LED��ʼ��
	Delay_Init();   //��ʱ��ʼ��
	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_12);

		Delay_ms(500);//��ʱ500΢��
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		//delay(100);		
		Delay_ms(500);//��ʱ500΢��
	}
	


}


