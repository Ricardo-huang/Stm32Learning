/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include "KEY.h"

/*******************************************************************************
*��������   KEY_Init(void)
*������     ���ð������ⲿ�ж�
*******************************************************************************/

void KEY_Init(void)
{

	  GPIO_InitTypeDef GPIO_InitStructure;
	  EXTI_InitTypeDef EXTI_InitStructure;
	  NVIC_InitTypeDef NVIC_InitStructure;
	  
	  LED_Enable
      KEY_Enable
	  SYSCFG_Enable
	  
	  //���ð�����IO��
	  GPIO_InitStructure.GPIO_Pin=PIN_KEY;
	  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;
	  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	  GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	  GPIO_Init(GPIO_KEY,&GPIO_InitStructure);
	    
	  //����LED��IO��
	  GPIO_InitStructure.GPIO_Pin=PIN_LED;
	  GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	  GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	  GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	  GPIO_Init(GPIO_LED,&GPIO_InitStructure);
	  
	  //����EXTI�ⲿ�ж�
	  EXTILine_Config   //��IO���������ж���
	  EXTI_InitStructure.EXTI_Line=EXTILine;                
	  EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;      // �ж��¼�
	  EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;  // �½��ش���
	  EXTI_InitStructure.EXTI_LineCmd=ENABLE;                // �ж���ʹ��
	  EXTI_Init(&EXTI_InitStructure);                        // ����
	  
	  //�����ж�
	  NVIC_InitStructure.NVIC_IRQChannel=EXTI_IRQn;
	  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0;
	  NVIC_InitStructure.NVIC_IRQChannelSubPriority=0;
	  NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	  NVIC_Init(&NVIC_InitStructure);
}

/*******************************************************************************
*��������   EXTI0_IRQHandler
*������     �жϴ���
*******************************************************************************/

void EXTI_IRQHandler(void)
{
    delay_ms(10);
    if(EXTI_GetITStatus(EXTILine)!=RESET)
    {
	  GPIO_ToggleBits(GPIO_LED,PIN_LED);
      EXTI_ClearITPendingBit(EXTILine);
    }
    
 }


