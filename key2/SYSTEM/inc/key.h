#ifndef _KEY_H
#define _KEY_H
#include "stm32f10x.h"

#define KEY0_PRES 0 //KEY0 ����
#define KEY0 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)//���ذ���״̬1Ϊ�Ͽ���0Ϊ����


void Key_Init(void);
u8 KEY_Scan(u8 mode);

#endif





