#include "stm32f10x.h"
#include "stdio.h"
#include "usart.h"
#include "delay.h"
#include "sys.h"

////////////////////////////////////////////////////////////////////////////////// 	 
//如果使用ucos,则包括下面的头文件即可.
#if SYSTEM_SUPPORT_OS
//#include "includes.h"					//ucos 使用	  
#endif
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32开发板
//串口1初始化		   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//修改日期:2012/8/18
//版本：V1.5
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2009-2019
//All rights reserved
//********************************************************************************
//V1.3修改说明 
//支持适应不同频率下的串口波特率设置.
//加入了对printf的支持
//增加了串口接收命令功能.
//修正了printf第一个字符丢失的bug
//V1.4修改说明
//1,修改串口初始化IO的bug
//2,修改了USART_RX_STA,使得串口最大接收字节数为2的14次方
//3,增加了USART_REC_LEN,用于定义串口最大允许接收的字节数(不大于2的14次方)
//4,修改了EN_USART1_RX的使能方式
//V1.5修改说明
//1,增加了对UCOSII的支持
////////////////////////////////////////////////////////////////////////////////// 	  
 

//////////////////////////////////////////////////////////////////
//加入以下代码,支持printf函数,而不需要选择use MicroLIB	  
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
_sys_exit(int x) 
{ 
	x = x; 
} 
//重定义fputc函数 
int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);//循环发送,直到发送完毕   
    USART1->DR = (u8) ch;      
	return ch;
}
#endif 

/*使用microLib的方法*/
 /* 
int fputc(int ch, FILE *f)
{
	USART_SendData(USART1, (uint8_t) ch);

	while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET) {}	
   
    return ch;
}
int GetKey (void)  { 

    while (!(USART1->SR & USART_FLAG_RXNE));

    return ((int)(USART1->DR & 0x1FF));
}
*/
 
#if EN_USART1_RX   //如果使能了接收
//串口1中断服务程序
//注意,读取USARTx->SR能避免莫名其妙的错误   	
u8 USART_RX_BUF[USART_REC_LEN];     //接收缓冲,最大USART_REC_LEN个字节.
//接收状态
//bit15，	接收完成标志
//bit14，	接收到0x0d
//bit13~0，	接收到的有效字节数目
u16 USART_RX_STA=0;       //接收状态标记	  
  

void USART_init(uint32_t bound)
{
	GPIO_InitTypeDef GPIO_InitStruct;//定义GPIO结构体变量
	USART_InitTypeDef USART_InitStruct;   //定义串口结构体变量
	NVIC_InitTypeDef NVIC_Initstrue;//定义中断结构体变量
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);//初始化系统时钟,开启对应总线的时钟
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_Init(GPIOA,&GPIO_InitStruct);   //GPIO初始化函数
	
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
	GPIO_Init(GPIOA,&GPIO_InitStruct);   //GPIO初始化函数
	
	USART_InitStruct.USART_Mode = USART_Mode_Tx|USART_Mode_Rx;//发送接收模式，严格区分大小写
	USART_InitStruct.USART_BaudRate = bound;//波特率，传个形参，可变
	USART_InitStruct.USART_Parity = USART_Parity_No;//无奇偶检验
	USART_InitStruct.USART_StopBits = USART_StopBits_1;//停止位1位
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;//无硬件数据流控制
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;//字节长8位
	USART_Init(USART1,&USART_InitStruct);//
	
	USART_Cmd(USART1,ENABLE);//使能USART1
	
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);//打开接收中断
	
	NVIC_Initstrue.NVIC_IRQChannel=USART1_IRQn;//stm32f10x中有定义
	NVIC_Initstrue.NVIC_IRQChannelPreemptionPriority=1;
	NVIC_Initstrue.NVIC_IRQChannelSubPriority=1;
	NVIC_Initstrue.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_Initstrue);
}

void USART1_IRQHandler(void)//中断符函数
{
	if(USART_GetITStatus(USART1,USART_IT_RXNE))
	{
		u8 res;
		res = USART_ReceiveData(USART1);
		
		USART_SendData(USART1,res);
		
	}
}

/*int fputc(int ch,FILE *f)   //printf重定向函数
{
	USART_SendData(USART1,(uint8_t)ch);   //发送一字节数据
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE) == RESET);   //等待发送完成
	return ch;
}*/

void USART1_IRQHandler(void)                	//串口1中断服务程序
	{
	u8 Res;
#if SYSTEM_SUPPORT_OS 		//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
	OSIntEnter();    
#endif
	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)  //接收中断(接收到的数据必须是0x0d 0x0a结尾)
		{
		Res =USART_ReceiveData(USART1);	//读取接收到的数据
		
		if((USART_RX_STA&0x8000)==0)//接收未完成
			{
			if(USART_RX_STA&0x4000)//接收到了0x0d
				{
				if(Res!=0x0a)USART_RX_STA=0;//接收错误,重新开始
				else USART_RX_STA|=0x8000;	//接收完成了 
				}
			else //还没收到0X0D
				{	
				if(Res==0x0d)USART_RX_STA|=0x4000;
				else
					{
					USART_RX_BUF[USART_RX_STA&0X3FFF]=Res ;
					USART_RX_STA++;
					if(USART_RX_STA>(USART_REC_LEN-1))USART_RX_STA=0;//接收数据错误,重新开始接收	  
					}		 
				}
			}   		 
     } 
#if SYSTEM_SUPPORT_OS 	//如果SYSTEM_SUPPORT_OS为真，则需要支持OS.
	OSIntExit();  											 
#endif
} 
#endif	











