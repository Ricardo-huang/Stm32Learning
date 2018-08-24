/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#define   _MAIN_
#include  "includes.h"


/*
*********************************************************************************************************
*                                            	DEFINES
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                          	   VARIABLES
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                                main()
*
* Description : This is the standard entry point for C code.  It is assumed that your code will cal
*               main() once you have performed all necessary initialization.
*
* Arguments   : none
*
* Returns     : none
*********************************************************************************************************
*/


int main(void)
{ 
  
        LED_Init();    //initial the IO port 
        
        
        while(1)
        {
            GPIO_ToggleBits(PORT_LED0, PIN_LED0);
            delay_ms(100);
            GPIO_ToggleBits(PORT_LED1, PIN_LED1);
            delay_ms(100);
        }
		
	
}

