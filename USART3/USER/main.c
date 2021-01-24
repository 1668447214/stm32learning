#include "stm32f10x.h"

#include "led.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"

int main(void)
{
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�ж����ȼ����飬�ж�����ǰҪ���壬2Ϊ2����ռ���ȼ���2����Ӧ���ȼ�
	LED_Init();
	Delay_Init();   //��ʱ��ʼ��
	USART_init(115200);//��׼���õ�ֵ
	
	while(1)
	{
		u8 data;
		GPIO_ResetBits(GPIOB,GPIO_Pin_13);
		Delay_ms(100);
		GPIO_SetBits(GPIOB,GPIO_Pin_13);
		Delay_ms(100);
		while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==RESET);
		data = USART_ReceiveData(USART1);
		USART_SendData(USART1,data);
		printf("yes or no");
	}
	
}

	/*LED_Init();
	Delay_Init();   //��ʱ��ʼ��
	USART_init(115200);//��׼���õ�ֵ
	while(1)
	{
		uint8_t RX_Data;   //����һ��8λ����
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(500);
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(500);
		
		while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==RESET);   //�ȴ�һ�ֽ����ݽ������
		RX_Data = USART_ReceiveData(USART1);   //�����յ���һ�ֽ����ݸ�������RX_Data
		USART_SendData(USART1,RX_Data);   //�����յ���һ�ֽ����ݷ��͵���������
		printf("printf test\r\n");
		
	}

}
void My_USART1_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStrue;
	USART_InitTypeDef USART_InitStrue;
	
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_USART1,ENABLE);
	
	GPIO_InitStrue.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStrue.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStrue.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOA,&GPIO_InitStrue);
	
	GPIO_InitStrue.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStrue.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_InitStrue.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIO_InitStrue);
	

	USART_InitStrue.USART_BaudRate=115200;
	USART_InitStrue.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStrue.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
	USART_InitStrue.USART_Parity=USART_Parity_No;//��żУ����Ϊ���������׼ȷ��
	USART_InitStrue.USART_StopBits=USART_StopBits_1;//
	USART_InitStrue.USART_WordLength=USART_WordLength_8b;//����żУ�����9���޾��ǰ�
	USART_Init(USART1,&USART_InitStrue);
	
	USART_Cmd(USART1,ENABLE);
}


int main()
{
	LED_Init();
	Delay_Init();   //��ʱ��ʼ��
	//My_USART1_Init();//��׼���õ�ֵ
	USART_init(115200);
	
	while(1)
	{
		uint8_t RX_Data;   //����һ��8λ����
		GPIO_ResetBits(GPIOC,GPIO_Pin_12);
		Delay_ms(100);
		GPIO_SetBits(GPIOC,GPIO_Pin_12);
		Delay_ms(100);
		
		while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==RESET);   //�ȴ�һ�ֽ����ݽ������
		RX_Data = USART_ReceiveData(USART1);   //�����յ���һ�ֽ����ݸ�������RX_Data
		USART_SendData(USART1,RX_Data);   //�����յ���һ�ֽ����ݷ��͵���������
		//printf("printf test\r\n");
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

}*/


