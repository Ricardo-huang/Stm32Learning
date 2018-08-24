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

    //GPIOE5��ʼ������
    GPIO_InitStructure.GPIO_Pin = PIN_LED;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;      //��ͨ���ģʽ
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
    NVIC_InitTypeDef NVIC_InitStructure;

    TIM_ENABLE  //ʹ�ܶ�ʱ��ʱ��

    TIM_TimeBaseInitStructure.TIM_Period = arr;     //�Զ���װ��ֵ
    TIM_TimeBaseInitStructure.TIM_Prescaler= psc;   //��ʱ����Ƶ
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //���ϼ���ģʽ
    TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
    TIM_TimeBaseInit(tim,&TIM_TimeBaseInitStructure);//��ʼ����ʱ��

    TIM_ITConfig(tim,TIM_IT_Update,ENABLE); //����ʱ�������ж�


    NVIC_InitStructure.NVIC_IRQChannel=tim_IRQn; //��ʱ���ж�
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x00; //��ռ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x00; //��Ӧ���ȼ�
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    TIM_Cmd(tim,ENABLE); //ʹ�ܶ�ʱ��9
}


//��ʱ���жϷ�����
void tim_IRQHandler(void)
{
	if(TIM_GetITStatus(tim,TIM_IT_Update)==SET) //����жϱ�־λ
	{
		GPIO_ToggleBits(GPIO_LED,PIN_LED);//LED��ת
	}
	TIM_ClearITPendingBit(tim,TIM_IT_Update);  //����жϱ�־λ
}





