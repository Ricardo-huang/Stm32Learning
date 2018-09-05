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
#define LED_ENABLE         {RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);}
#define GPIO_LED            GPIOB
#define PIN_LED             GPIO_Pin_8
#define GPIO_Config        {GPIO_PinAFConfig(GPIOB,GPIO_PinSource8,GPIO_AF_TIM10);}

#define TIM_ENABLE         {RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM10,ENABLE);}
#define arr                 500-1   
#define psc                 168-1

#define tim                 TIM10
//#define tim_IRQn            TIM4_IRQn
//#define tim_IRQHandler      TIM4_IRQHandler
/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void LED_Init(void);
void TIM_Init(void);