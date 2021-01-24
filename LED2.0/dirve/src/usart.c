#include "stm32f10x.h"
#include "stdio.h"

void USART_init(uint32_t bound)
{
	GPIO_InitTypeDef GPIO_InitStruct;//定义GPIO结构体变量
	USART_InitTypeDef USART_InitStruct;   //定义串口结构体变量
	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);//初始化系统时钟,开启对应总线的时钟
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOA,&GPIO_InitStruct);   //GPIO初始化函数
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOA,&GPIO_InitStruct);   //GPIO初始化函数
	
	USART_InitStruct.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;//发送接收模式，严格区分大小写
	USART_InitStruct.USART_BaudRate = bound;//波特率，传个形参，随时变
	USART_InitStruct.USART_Parity = USART_Parity_No;//无奇偶检验
	USART_InitStruct.USART_StopBits = USART_StopBits_1;//停止位1位
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;//字节长8位
	USART_Init(USART1,&USART_InitStruct);//
	
	USART_Cmd(USART1,ENABLE);//使能USART1
	
}

int fputc(int ch,FILE *f)   //printf重定向函数
{
	USART_SendData(USART1,(uint8_t)ch);   //发送一字节数据
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);   //等待发送完成
	return ch;
}
