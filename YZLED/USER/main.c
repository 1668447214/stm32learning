#include "stm32f10x.h"
#include "LED.h"
#include "delay.h"


int main(void)
{
	u8 t = 0;//�����ã����ڱ������������ܷ��ڿ�ִ�������棬��������������ͷ����������
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

