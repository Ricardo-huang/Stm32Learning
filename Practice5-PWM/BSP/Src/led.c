/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#define  LED_MODULE
#include "led.h"


/*
*********************************************************************************************************
*                                            	DEFINES
*********************************************************************************************************
*/




/*
*********************************************************************************************************
*                                           	LED_Init()
*
* Description : Initialize  all the LEDs on the board.
*
* Argument(s) : none
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
* Note(s)     : The LED pins are active-low on the board.
*********************************************************************************************************
*/
void LED_Init (void)
{
    GPIO_InitTypeDef GPIO_InitStructure;               // define a sturct
	
	LED_PORT_ENABLE();                                 // enable the clock of IO port
	
	GPIO_InitStructure.GPIO_Pin = PIN_LED0;            // the corresponding IO pin
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;      // output mode       //OUT or IN
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     // push¨Cpull output  // PP or OD
    GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;   // IO port output speed  50MHZ
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;       // pull-up           // UP or DOWN or NOPULL
	
	GPIO_Init(PORT_LED0,&GPIO_InitStructure);          //  initial IO port                    
}
