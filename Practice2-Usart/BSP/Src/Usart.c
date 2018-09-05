/*
*********************************************************************************************************
*                                             INCLUDE FILES
*********************************************************************************************************
*/

#include  "Usart.h"

/*
*********************************************************************************************************
*                                           	 VARIBLES
*********************************************************************************************************
*/
u8 ReceiveData;

/*
*********************************************************************************************************
*                                               USART_Configuration()
*
* Description : Initialize the Usart.
*
* Argument(s) : none.
*
* Return(s)   : none.
*
*********************************************************************************************************
*/

void USART_Configuration(void)
{ 
	USART_InitTypeDef USART_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	
	// 开启IO口时钟
	GPIO_TX_Enable
	GPIO_RX_Enable
	
	// 开启串口时钟
	Usart_Enable
	
    // 复用功能配置
	GPIO_PinAFConfig(GPIO_TX,PINSor_TX,GPIO_AF_USART);
	GPIO_PinAFConfig(GPIO_RX,PINSor_RX,GPIO_AF_USART);
	
	// TX 
	GPIO_InitStructure.GPIO_Pin = PIN_TX;                 
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;            //复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;        //速度50MHZ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;            //上拉
	GPIO_Init(GPIO_TX,&GPIO_InitStructure);                 //初始化IO口
	
	// RX
	GPIO_InitStructure.GPIO_Pin = PIN_RX;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIO_RX,&GPIO_InitStructure);
	
	// USART中断优先级
	NVIC_InitStructure.NVIC_IRQChannel = USART_IRQn;           
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; // 抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        // 响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           // IRQ通道使能
	NVIC_Init(&NVIC_InitStructure);                           //  根据指定参数初始化NVIC寄存器 
	
	// USART初始化
	USART_DeInit(USART1);
	USART_InitStructure.USART_BaudRate = USART_BOUND;                               // 波特率
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;                     // 字长为8为数据格式
	USART_InitStructure.USART_StopBits = USART_StopBits_1;                          // 一个停止位
	USART_InitStructure.USART_Parity = USART_Parity_No;                             // 无奇偶校验位
	USART_InitStructure.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;                   // 收发模式
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART,&USART_InitStructure);                                         // 初始化串口
	
	USART_Cmd(USART,ENABLE);                        // 使能串口
	USART_ITConfig(USART,USART_IT_RXNE,ENABLE);     // 开启接收中断
  
}

/*
*********************************************************************************************************
*                                           USART_Send_Char(u8 Char)
*
* Brief    : send a char through Usart
*
* Param(s) : char 
*			
* Return(s): none.
*
*********************************************************************************************************
*/

void USART_Send_Char(u8 Char)
{
	USART_SendData(USART,Char);
	// 等待发送完成一个字节
	while(USART_GetFlagStatus(USART,USART_FLAG_TXE) != SET);
}


/*
*********************************************************************************************************
*                                          USART_IRQHandler(void)
*
* Brief    : This function handles USART interrupt (receive & transmit). 
*
* Param(s) : none
*			
* Return(s): none.
*
*********************************************************************************************************
*/

void USART_IRQHandler(void)
{
	/* USART in Receiver mode */
	if(USART_GetITStatus(USART, USART_IT_RXNE) != RESET) 
	{
	   ReceiveData= USART_ReceiveData(USART);   //接收数据
	   USART_SendData(USART,ReceiveData);       //发送接收到的数据
	}
	
	USART_ClearITPendingBit(USART, USART_IT_RXNE);
}
