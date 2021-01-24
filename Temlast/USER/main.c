#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"

/*int main(void)
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
	


}*/

int main(void)
{
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�ж����ȼ����飬�ж�����ǰҪ���壬2Ϊ2����ռ���ȼ���2����Ӧ���ȼ�
	LED_Init();
	Delay_Init();   //��ʱ��ʼ��
	//USART_init(115200);//��׼���õ�ֵ
	USART_init(115200);
	while(1);
	
}


