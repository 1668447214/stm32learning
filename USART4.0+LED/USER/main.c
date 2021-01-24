#include "stm32f10x.h"

#include "led.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"


int main(void)
{
	LED_Init();   //LED��ʼ��
	Delay_Init();   //��ʱ��ʼ��
	USART_init(115200);   //���ڳ�ʼ������ڲ���Ϊ������115200
	
	while(1)
	{
		uint8_t RX_Data;   //����һ��8λ����
		GPIO_ResetBits(GPIOC,GPIO_Pin_13);
		Delay_ms(100);
		GPIO_SetBits(GPIOC,GPIO_Pin_13);
		Delay_ms(100);
		/*while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==RESET);   //�ȴ�һ�ֽ����ݽ������
		RX_Data = USART_ReceiveData(USART1);   //�����յ���һ�ֽ����ݸ�������RX_Data
		USART_SendData(USART1,RX_Data);   //�����յ���һ�ֽ����ݷ��͵���������*/
		printf("printf test\r\n");
	}
}

