/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#pragma once
#include "includes.h"

/*
*********************************************************************************************************
*                                               DEFINES
*********************************************************************************************************
*/
	 
#define PORT_LED0						GPIOE

#define PIN_LED0						GPIO_Pin_5
#define LED_PORT_ENABLE()				{RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);}


/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void LED_Init (void);
 
 

/*
*********************************************************************************************************
*                                             MODULE END
*********************************************************************************************************
*/





















