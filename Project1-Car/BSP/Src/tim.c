/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include  "tim.h"
extern int count;

/**********************************************************************************************************
*                                               TIM_Init()
* 描述 : 初始化定时器配置
**********************************************************************************************************/

void TIM2_Init(void)
{
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;

    TIM_ENABLE  //使能定时器时钟

    TIM_TimeBaseInitStructure.TIM_Period = arr;     //自动重装载值
    TIM_TimeBaseInitStructure.TIM_Prescaler= psc;   //定时器分频
    TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
    TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
    TIM_TimeBaseInit(tim,&TIM_TimeBaseInitStructure);//初始化定时器

    TIM_ITConfig(tim,TIM_IT_Update,ENABLE); //允许定时器更新中断


    NVIC_InitStructure.NVIC_IRQChannel=tim_IRQn; //定时器中断
    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x00; //抢占优先级
    NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x00; //响应优先级
    NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
    NVIC_Init(&NVIC_InitStructure);

    TIM_Cmd(tim,ENABLE); //使能定时器9
}


//定时器中断服务函数
void tim_IRQHandler(void)
{
	if(TIM_GetITStatus(tim,TIM_IT_Update)==SET) //检测中断标志位
	{
		count = 0;
	}
	TIM_ClearITPendingBit(tim,TIM_IT_Update);  //清除中断标志位
}





