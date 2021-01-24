#include "stm32f10x_rcc.h"
#include "stm32f10x_gpio.h"


void BeepInit(void)
{
	
	GPIO_InitTypeDef GPIO_struct;
	RCC_APB2PeriphResetCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	
	GPIO_struct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_struct.GPIO_Pin=GPIO_Pin_8;
	GPIO_struct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_struct);
	
	GPIO_ResetBits(GPIOB,GPIO_Pin_8);
}

