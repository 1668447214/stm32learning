#include "stm32f10x.h"

void TIM_Init(uint16_t per, uint16_t psc)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStruct;   //���嶨ʱ���ṹ�����
	NVIC_InitTypeDef NVIC_InitStruct;   //�����ж����ȼ��ṹ�����
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);   //ʹ��TIM3��ʱ��
	
	TIM_TimeBaseInitStruct.TIM_Period=per;   //�����Զ���װ�ص�����ֵ
	TIM_TimeBaseInitStruct.TIM_Prescaler=psc;   //����Ԥ��Ƶֵ
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;   //���ϼ���ģʽ
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;   //����ʱ�ӷָ�
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);   //��ʱ����ʼ������
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);   //TIM3�ж�ʹ��1(��ʱ���ţ���ʱ���ж�Դ��״̬)
	
	NVIC_InitStruct.NVIC_IRQChannel=TIM3_IRQn;   //TIM3�ж�ͨ��
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=0;   //��ռ���ȼ�0
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;   //�����ȼ�1
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;   //ʹ��TIM3�ж�ͨ��
	NVIC_Init(&NVIC_InitStruct);   //�ж����ȼ���ʼ������
	
	TIM_Cmd(TIM3,ENABLE);   //TIM3ʹ��
}



