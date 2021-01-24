//#include "LED.h"
#include "stm32f10x.h"
#include "stm32f10x_rcc.h"


void LED_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	//RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOB,ENABLE);error
	
	
	
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStruct);
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
	
	
}

