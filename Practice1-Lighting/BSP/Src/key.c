#include "key.h"
//#include "delay.h"

//按键初始化函数
void KFY_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;
  
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD,ENABLE);//使能GPIOA|GPIOE时钟
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10| GPIO_Pin_11;//KEY1,KEY2对应引脚
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;//普通输入模式
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;//100MHz
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;//上拉
  GPIO_Init(GPIOD,&GPIO_InitStructure);//初始化GPIOD10，11
}

u8 KEY_Scan(u8 mode)
{
  static u8 key_up = 1;
  if (mode) key_up = 1;
  if (key_up&&(KEY2 == 0||KEY1 == 0))
  {
    delay_ms(10);
    key_up = 0;
    if (KEY1 == 0) return 1;
    else if (KEY2 == 0) return 2;
  }else if (KEY1 == 1&&KEY2 == 2){
    
  }
  return 0;
}