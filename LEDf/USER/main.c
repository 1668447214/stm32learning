#include "stm32f10x.h"
//#include "stm32f10x_it.h"

#include "led.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
#include "tim.h"
#include "usart.h"


int main(void)
{
	//uint8_t flag= 0;
	//uint16_t pwm_value=0;
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);   //����NVIC�жϷ���Ϊ2
	LED_Init();   //LED��ʼ��
	Delay_Init();   //��ʱ��ʼ��
	//USART_init(115200);
//	KEY_Init();   //������ʼ��
	//TIM_Init(9999,7199);   //��ʽ��9999 + 1��* ��7199+1��/72MHz = 1s
	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		//delay(100);
		Delay_ms(500);//��ʱ500΢��
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		//delay(100);
		Delay_ms(500);//��ʱ500΢��
	}
	
}

