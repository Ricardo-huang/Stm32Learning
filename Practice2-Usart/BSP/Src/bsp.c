/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#define   BSP_MODULE
#include  "bsp.h"


/*
*********************************************************************************************************
*                                           	 DEFINES
*********************************************************************************************************
*/

#define  NVIC_PrioGroup                NVIC_PriorityGroup_2

      

/*
*********************************************************************************************************
*                                           	CONSTANTS
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                      			VARIABLES
*********************************************************************************************************
*/



                                                

/*
*********************************************************************************************************
*                         	             LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************
*/



/*
*********************************************************************************************************
*                                               BSP_Init()
*
* Description : Initialize the Board Support Package (BSP).
*
* Argument(s) : none.
*
* Return(s)   : none.
*
* Caller(s)   : Application.
*
*********************************************************************************************************
*/

void  BSP_Init (void)
{
    NVIC_PriorityGroupConfig(NVIC_PrioGroup);                  /* Initialize the priority group                        */ 
    
    SystemInit();                                              /* Initialize the clocks                                */ 
}


void delay_ms(int t)
{
	int  tmp1;
	int i;
	for(i = 0;i < 8400;i++)
	{
		tmp1 = t;
		while(tmp1--);
	}
}

