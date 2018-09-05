/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include "exti.h"
int count = 0;
int v;

/*******************************************************************************
*函数名：   KEY_Init(void)
*描述：     配置按键与外部中断
*******************************************************************************/

void EXTI0_Init(void)
{

	  GPIO_InitTypeDef GPIO_InitStructure;
	  EXTI_InitTypeDef EXTI_InitStructure;
	  NVIC_InitTypeDef NVIC_InitStructure;
	  
      EXTI_Enable
	  SYSCFG_Enable
	  
	  //配置按键的IO口
	  GPIO_InitStructure.GPIO_Pin=PIN_EXTI;
	  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;
	  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	  GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	  GPIO_Init(GPIO_EXTI,&GPIO_InitStructure);
	    

	  
	  //配置EXTI外部中断
	  EXTILine_Config   //将IO口连接上中断线
	  EXTI_InitStructure.EXTI_Line=EXTILine;                
	  EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;      // 中断事件
	  EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;  // 下降沿触发
	  EXTI_InitStructure.EXTI_LineCmd=ENABLE;                // 中断线使能
	  EXTI_Init(&EXTI_InitStructure);                        // 配置
	  
	  //配置中断
	  NVIC_InitStructure.NVIC_IRQChannel=EXTI_IRQn;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	  NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	  NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
*函数名：   EXTI0_IRQHandler
*描述：     中断处理
*******************************************************************************/

void EXTI_IRQHandler(void)
{
    if(EXTI_GetITStatus(EXTILine)!=RESET)
    {
//	  GPIO_ToggleBits(GPIO_LED,PIN_LED);
      count ++;
      v = count/512; 
      EXTI_ClearITPendingBit(EXTILine);
    }
    
 }


