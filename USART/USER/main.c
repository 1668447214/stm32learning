#include "led.h"
#include "delay.h"
//#include "key.h"
#include "sys.h"
#include "usart.h"
 
 
/************************************************
 ALIENTEK战舰STM32开发板实验4
 串口实验 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/


 int main(void)
 {		
 	u16 t;  
	u16 len;	
	u16 times=0;
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	uart_init(115200);	 //串口初始化为115200
 	LED_Init();			     //LED端口初始化
	//KEY_Init();          //初始化与按键连接的硬件接口
 	while(1)
	{
		if(USART_RX_STA&0x8000)
		{					   
			len=USART_RX_STA&0x3fff;//得到此次接收到的数据长度
			printf("\r\n您发送的消息为:\r\n\r\n");
			for(t=0;t<len;t++)
			{
				USART_SendData(USART1, USART_RX_BUF[t]);//向串口1发送数据
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);//等待发送结束
			}
			printf("\r\n\r\n");//插入换行
			USART_RX_STA=0;
		}else
		{
			times++;
			if(times%5000==0)
			{
				printf("\r\n战舰STM32开发板 串口实验\r\n");
				printf("正点原子@ALIENTEK\r\n\r\n");
			}
			if(times%200==0)printf("请输入数据,以回车键结束\n");  
			if(times%30==0)LED0=!LED0;//闪烁LED,提示系统正在运行.
			delay_ms(10);   
		}
	}	 
 }


/*#include "stm32f10x.h"

#include "led.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"

int main(void)
{
	
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断优先级分组，中断配置前要定义，2为2个抢占优先级，2个响应优先级
	//LED_Init();
	//Delay_Init();   //延时初始化
	//USART_init(115200);//标准常用的值
	//while(1)
	

	LED_Init();
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
		//printf("printf test\r\n");
		
	}

}*/


