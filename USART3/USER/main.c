#include "stm32f10x.h"

#include "led.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"

int main(void)
{
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断优先级分组，中断配置前要定义，2为2个抢占优先级，2个响应优先级
	LED_Init();
	Delay_Init();   //延时初始化
	USART_init(115200);//标准常用的值
	
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
	Delay_Init();   //延时初始化
	USART_init(115200);//标准常用的值
	while(1)
	{
		uint8_t RX_Data;   //定义一个8位变量
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(500);
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		Delay_ms(500);
		
		while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==RESET);   //等待一字节数据接收完成
		RX_Data = USART_ReceiveData(USART1);   //将接收到的一字节数据赋给变量RX_Data
		USART_SendData(USART1,RX_Data);   //将接收到的一字节数据发送到串口助手
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
	USART_InitStrue.USART_Parity=USART_Parity_No;//奇偶校验是为了提高数据准确率
	USART_InitStrue.USART_StopBits=USART_StopBits_1;//
	USART_InitStrue.USART_WordLength=USART_WordLength_8b;//有奇偶校验就是9，无就是八
	USART_Init(USART1,&USART_InitStrue);
	
	USART_Cmd(USART1,ENABLE);
}


int main()
{
	LED_Init();
	Delay_Init();   //延时初始化
	//My_USART1_Init();//标准常用的值
	USART_init(115200);
	
	while(1)
	{
		uint8_t RX_Data;   //定义一个8位变量
		GPIO_ResetBits(GPIOC,GPIO_Pin_12);
		Delay_ms(100);
		GPIO_SetBits(GPIOC,GPIO_Pin_12);
		Delay_ms(100);
		
		while(USART_GetFlagStatus(USART1,USART_FLAG_RXNE)==RESET);   //等待一字节数据接收完成
		RX_Data = USART_ReceiveData(USART1);   //将接收到的一字节数据赋给变量RX_Data
		USART_SendData(USART1,RX_Data);   //将接收到的一字节数据发送到串口助手
		//printf("printf test\r\n");
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

}*/


