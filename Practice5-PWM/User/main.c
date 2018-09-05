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

u8 dir=1;
u16 led0pwmval=0;

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
        BSP_Init();
		LED_Init();
		TIM_Init();
		
        while(1)
        {
			TIM_SetCompare1(tim,led0pwmval);
        }
		
	
}


