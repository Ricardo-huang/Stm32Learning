#pragma once
#include "includes.h"

#define PORT_LED10						GPIOE    
#define Pin_10						GPIO_Pin_5

#define KEY1  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_10)
#define KEY2  GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_11)


#define KEY1_PRES 1
#define KEY2_PRES 2

void KEY_Init(void);
u8 KEY_Scan(u8);
