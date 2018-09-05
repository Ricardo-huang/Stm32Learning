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

#define		USART			     USART1

#define		GPIO_TX_Enable	    {RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);}
#define		GPIO_RX_Enable	    {RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);}
#define		Usart_Enable	    {RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);}

#define		GPIO_TX		        GPIOA
#define		PIN_TX	            GPIO_Pin_9
#define		PINSor_TX		    GPIO_PinSource9

#define		GPIO_RX		        GPIOA
#define		PIN_RX	            GPIO_Pin_10
#define		PINSor_RX           GPIO_PinSource10

#define		GPIO_AF_USART	    GPIO_AF_USART1
#define     USART_IRQn          USART1_IRQn
#define     USART_IRQHandler    USART1_IRQHandler
#define     USART_BOUND         115200


/*
*********************************************************************************************************
*                                           FUNCTION PROTOTYPES
*********************************************************************************************************
*/

void USART_Configuration(void);
void USART_Send_Char(u8 Char);

/*
*********************************************************************************************************
*                                              EXTERNS
*********************************************************************************************************
*/

extern u8 ReceiveData;