/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include  "tim.h"

/**********************************************************************************************************
*                                               LED_Init()
* 描述 : 初始化LED所用的IO口
**********************************************************************************************************/

void LED_Init(void)
{    	 
    GPIO_InitTypeDef  GPIO_InitStructure;

    LED_ENABLE  //使能GPIOF时钟

    //GPIOE5初始化设置
    GPIO_InitStructure.GPIO_Pin = PIN_LED;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;      //普通输出模式
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     //推挽输出
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //50MHz
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;       //上拉
    GPIO_Init(GPIO_LED, &GPIO_InitStructure);             //初始化
		
}

/**********************************************************************************************************
*                                               TIM_Init()
* 描述 : 初始化定时器配置
**********************************************************************************************************/

void TIM_Init(void)
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
		GPIO_ToggleBits(GPIO_LED,PIN_LED);//LED翻转
	}
	TIM_ClearITPendingBit(tim,TIM_IT_Update);  //清除中断标志位
}





