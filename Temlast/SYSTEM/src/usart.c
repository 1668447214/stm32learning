#include "stm32f10x.h"
#include "stdio.h"
#include "usart.h"
#include "delay.h"

void USART_init(uint32_t bound)
{
	GPIO_InitTypeDef GPIO_InitStruct;//����GPIO�ṹ�����
	USART_InitTypeDef USART_InitStruct;   //���崮�ڽṹ�����
	NVIC_InitTypeDef NVIC_Initstrue;//�����жϽṹ�����
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);//��ʼ��ϵͳʱ��,������Ӧ���ߵ�ʱ��
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOA,&GPIO_InitStruct);   //GPIO��ʼ������
	
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIO_InitStruct);   //GPIO��ʼ������
	
	USART_InitStruct.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;//���ͽ���ģʽ���ϸ����ִ�Сд
	USART_InitStruct.USART_BaudRate = bound;//�����ʣ������βΣ��ɱ�
	USART_InitStruct.USART_Parity = USART_Parity_No;//����ż����
	USART_InitStruct.USART_StopBits = USART_StopBits_1;//ֹͣλ1λ
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//��Ӳ������������
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;//�ֽڳ�8λ
	USART_Init(USART1,&USART_InitStruct);//
	
	USART_Cmd(USART1,ENABLE);//ʹ��USART1
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//�򿪽����ж�
	
	NVIC_Initstrue.NVIC_IRQChannel=USART1_IRQn;//stm32f10x���ж���
	NVIC_Initstrue.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_Initstrue.NVIC_IRQChannelSubPriority=1;
	NVIC_Initstrue.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_Initstrue);
}

void USART1_IRQHandler(void)//�жϷ�����
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		u8 res;
		res = USART_ReceiveData(USART1);
		
		USART_SendData(USART1,res);
		
	}
}

/*int fputc(int ch,FILE *f)   //printf�ض�����
{
	USART_SendData(USART1,(uint8_t)ch);   //����һ�ֽ�����
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);   //�ȴ��������
	return ch;
}*/













