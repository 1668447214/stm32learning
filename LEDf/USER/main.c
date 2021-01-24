#include "stm32f10x.h"
//#include "stm32f10x_it.h"

#include "led.h"
#include "delay.h"
#include "usart.h"
#include "stdio.h"
#include "tim.h"
#include "usart.h"


int main(void)
{
	//uint8_t flag= 0;
	//uint16_t pwm_value=0;
	//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);   //设置NVIC中断分组为2
	LED_Init();   //LED初始化
	Delay_Init();   //延时初始化
	//USART_init(115200);
//	KEY_Init();   //按键初始化
	//TIM_Init(9999,7199);   //公式（9999 + 1）* （7199+1）/72MHz = 1s
	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
		//delay(100);
		Delay_ms(500);//延时500微秒
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
		//delay(100);
		Delay_ms(500);//延时500微秒
	}
	
}

