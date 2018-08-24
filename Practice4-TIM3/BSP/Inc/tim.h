/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#pragma once
#include "includes.h"

/*
*********************************************************************************************************
*                                              DEFINE
*********************************************************************************************************
*/
#define LED_ENABLE      {RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);}
#define GPIO_LED         GPIOF
#define PIN_LED          GPIO_Pin_9

#define TIM_ENABLE      {RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);}
#define arr              10000-1   
#define psc              8400-1

#define tim              TIM3
#define tim_IRQn         TIM3_IRQn
#define tim_IRQHandler   TIM3_IRQHandler
/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void LED_Init(void);
void TIM_Init(void);