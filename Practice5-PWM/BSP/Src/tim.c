/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include  "tim.h"

/**********************************************************************************************************
*                                               LED_Init()
* ���� : ��ʼ��LED���õ�IO��
**********************************************************************************************************/

void LED_Init(void)
{    	 
    GPIO_InitTypeDef  GPIO_InitStructure;

    LED_ENABLE  //ʹ��GPIOFʱ��
    GPIO_Config  //��IO�ڸ���Ϊ��ʱ�����
       
    GPIO_InitStructure.GPIO_Pin = PIN_LED;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;      //�������ģʽ
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     //�������
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //50MHz
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;       //����
    GPIO_Init(GPIO_LED, &GPIO_InitStructure);             //��ʼ��
		
}

/**********************************************************************************************************
*                                               TIM_Init()
* ���� : ��ʼ����ʱ������
**********************************************************************************************************/

void TIM_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;

	TIM_ENABLE  ///ʹ�ܶ�ʱ��ʱ��
	
    TIM_TimeBaseInitStructure.TIM_Period = arr;     //�Զ���װ��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler= psc;   //��ʱ����Ƶ
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(tim,&TIM_TimeBaseInitStructure);//��ʼ����ʱ��
		
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //ѡ��ʱ��ģʽ:TIM�����ȵ���ģʽ1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�Ƚ����ʹ��
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_Low; //�������:TIM����Ƚϼ��Ե�
	TIM_OC1Init(tim, &TIM_OCInitStructure);  //����ָ���Ĳ�����ʼ������TIM OC1

	TIM_OC1PreloadConfig(tim, TIM_OCPreload_Enable);  //ʹ��TIM��CCR1�ϵ�Ԥװ�ؼĴ���
    TIM_ARRPreloadConfig(tim,ENABLE);//ARPEʹ�� 
	
	TIM_Cmd(tim,ENABLE); //ʹ�ܶ�ʱ��
}








