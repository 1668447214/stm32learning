#include "stm32f10x.h"
#include "led.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
#include "key.h"
#include "sys.h"
/*int main(void)
{
	LED_Init();   //LED初始化
	Delay_Init();   //延时初始化
	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_12);

		Delay_ms(500);//延时500微秒
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		//delay(100);		
		Delay_ms(500);//延时500微秒
	}
	


}*/

int main(void)
{
	u8 key;
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断优先级分组，中断配置前要定义，2为2个抢占优先级，2个响应优先级
	LED_Init();
	Delay_Init();   //延时初始化
	Key_Init();
	USART_init(115200);//标准常用的值
	//GPIO_ResetBits(GPIOC,GPIO_Pin_13);
	LED0 = 0;
	while(1)
	{
		key = KEY_Scan(0); //得到键值KEY_Scan
		if(key)
		{
			//GPIO_SetBits(GPIOC,GPIO_Pin_13);
			LED0 = !LED0;
			//printf("welcome to you");
		}else Delay_ms(500);//延时500微秒
	
	}
	/*NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//中断优先级分组，中断配置前要定义，2为2个抢占优先级，2个响应优先级
	LED_Init();
	Delay_Init();   //延时初始化
	USART_init(115200);//标准常用的值
	while(1);*/
	
}


