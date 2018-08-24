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
#define LED_ENABLE         {RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);}
#define GPIO_LED            GPIOF
#define PIN_LED             GPIO_Pin_10
#define GPIO_Config   {GPIO_PinAFConfig(GPIOF,GPIO_PinSource10,GPIO_AF_TIM9);}

#define TIM_ENABLE         {RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9,ENABLE);}
#define arr                 500-1   
#define psc                 168-1

#define tim                 TIM9
#define tim_IRQn            TIM1_BRK_TIM9_IRQn
#define tim_IRQHandler      TIM1_BRK_TIM9_IRQHandler
/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void LED_Init(void);
void TIM_Init(void);