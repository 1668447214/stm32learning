#include "stm32f10x.h"

void TIM_Init(uint16_t per, uint16_t psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;   //定义定时器结构体变量
	NVIC_InitTypeDef NVIC_InitStruct;   //定义中断优先级结构体变量
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);   //使能TIM3的时钟
	
	TIM_TimeBaseInitStruct.TIM_Period=per;   //设置自动重装载的周期值
	TIM_TimeBaseInitStruct.TIM_Prescaler=psc;   //设置预分频值
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;   //向上计数模式
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;   //设置时钟分割
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);   //定时器初始化函数
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);   //TIM3中断使能1(定时器号，定时器中断源，状态)
	
	NVIC_InitStruct.NVIC_IRQChannel=TIM3_IRQn;   //TIM3中断通道
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=0;   //抢占优先级0
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;   //子优先级1
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;   //使能TIM3中断通道
	NVIC_Init(&NVIC_InitStruct);   //中断优先级初始化函数
	
	TIM_Cmd(TIM3,ENABLE);   //TIM3使能
}



