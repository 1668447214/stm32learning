#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
#include "key.h"
#include "sys.h"
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
	u8 key;
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�ж����ȼ����飬�ж�����ǰҪ���壬2Ϊ2����ռ���ȼ���2����Ӧ���ȼ�
	LED_Init();
	Delay_Init();   //��ʱ��ʼ��
	Key_Init();
	USART_init(115200);//��׼���õ�ֵ
	//GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	LED0 = 0;
	while(1)
	{
		key = KEY_Scan(0); //�õ���ֵKEY_Scan
		if(key)
		{
			//GPIO_SetBits(GPIOC,GPIO_Pin_13);
			LED0 = !LED0;
			//printf("welcome to you");
		}else Delay_ms(500);//��ʱ500΢��
	
	}
	/*NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�ж����ȼ����飬�ж�����ǰҪ���壬2Ϊ2����ռ���ȼ���2����Ӧ���ȼ�
	LED_Init();
	Delay_Init();   //��ʱ��ʼ��
	USART_init(115200);//��׼���õ�ֵ
	while(1);*/
	
}


