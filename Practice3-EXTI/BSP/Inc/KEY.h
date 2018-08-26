/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#pragma once
#include "includes.h"

/*
*********************************************************************************************************
*                                           	 DEFINES
*********************************************************************************************************
*/

#define		LED_Enable	       {RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);}
#define		KEY_Enable	       {RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);}
#define		SYSCFG_Enable	   {RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);}

#define		GPIO_KEY		    GPIOE
#define		PIN_KEY	            GPIO_Pin_2

#define		GPIO_LED		    GPIOF
#define		PIN_LED	            GPIO_Pin_9

#define     EXTILine_Config    {SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOE,EXTI_PinSource2);}

#define     EXTILine            EXTI_Line2
#define     EXTI_IRQn           EXTI2_IRQn
#define     EXTI_IRQHandler     EXTI2_IRQHandler

/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void KEY_Init(void);

/*
*********************************************************************************************************
*                                              EXTERNS
*********************************************************************************************************
*/

