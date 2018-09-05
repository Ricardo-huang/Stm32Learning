/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include  "pwm.h"

/**********************************************************************************************************
*                                               LED_Init()
* 描述 : 初始化LED所用的IO口
**********************************************************************************************************/

void LED_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;

  LED_ENABLE  //使能GPIOF时钟
  GPIO_Config  //将IO口复用为定时器输出
	   
  GPIO_InitStructure.GPIO_Pin = PIN_LED;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;      //复用输出模式
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;     //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //50MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;       //上拉
  GPIO_Init(GPIO_LED, &GPIO_InitStructure);             //初始化
		
}

/**********************************************************************************************************
*                                               TIM_Init()
* 描述 : 初始化定时器配置
**********************************************************************************************************/

void TIM1_Init(void)
{
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;

	TIM1_ENABLE  ///使能定时器时钟
	
    TIM_TimeBaseInitStructure.TIM_Period = arr1;     //自动重装载值
	TIM_TimeBaseInitStructure.TIM_Prescaler= psc1;   //定时器分频
	TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up; //向上计数模式
	TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1; 
	TIM_TimeBaseInit(tim1,&TIM_TimeBaseInitStructure);//初始化定时器
		
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //选择定时器模式:TIM脉冲宽度调制模式1
 	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性:TIM输出比较极性高 即在达到比较值之前高电平
	TIM_OC1Init(tim1, &TIM_OCInitStructure);  //根据指定的参数初始化外设TIM OC1

	TIM_OC1PreloadConfig(tim1, TIM_OCPreload_Enable);  //使能TIM在CCR1上的预装载寄存器
    TIM_ARRPreloadConfig(tim1,ENABLE);//ARPE使能 
	
	TIM_Cmd(tim1,ENABLE); //使能定时器
}