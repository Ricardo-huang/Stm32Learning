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
#define LED_ENABLE          {RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);}
#define GPIO_LED            GPIOE
#define PIN_LED             GPIO_Pin_5
#define GPIO_Config         {GPIO_PinAFConfig(GPIOE,GPIO_PinSource5,GPIO_AF_TIM9);}

#define TIM1_ENABLE          {RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM9,ENABLE);}
#define arr1                 500-1   
#define psc1                 168-1

#define tim1                 TIM9
#define tim1_IRQn            TIM1_BRK_TIM9_IRQn
#define tim1_IRQHandler      TIM1_BRK_TIM9_IRQHandler
/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void LED_Init(void);
void TIM1_Init(void);