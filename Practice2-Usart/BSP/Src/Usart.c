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
	
	// ����IO��ʱ��
	GPIO_TX_Enable
	GPIO_RX_Enable
	
	// ��������ʱ��
	Usart_Enable
	
    // ���ù�������
	GPIO_PinAFConfig(GPIO_TX,PINSor_TX,GPIO_AF_USART);
	GPIO_PinAFConfig(GPIO_RX,PINSor_RX,GPIO_AF_USART);
	
	// TX 
	GPIO_InitStructure.GPIO_Pin = PIN_TX;                 
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;            //���ù���
	GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;        //�ٶ�50MHZ
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;          //���츴�����
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;            //����
	GPIO_Init(GPIO_TX,&GPIO_InitStructure);                 //��ʼ��IO��
	
	// RX
	GPIO_InitStructure.GPIO_Pin = PIN_RX;
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_Speed = GPIO_Fast_Speed;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIO_RX,&GPIO_InitStructure);
	
	// USART�ж����ȼ�
	NVIC_InitStructure.NVIC_IRQChannel = USART_IRQn;           
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2; // ��ռ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;        // ��Ӧ���ȼ�
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;           // IRQͨ��ʹ��
	NVIC_Init(&NVIC_InitStructure);                           //  ����ָ��������ʼ��NVIC�Ĵ��� 
	
	// USART��ʼ��
	USART_DeInit(USART1);
	USART_InitStructure.USART_BaudRate = USART_BOUND;                               // ������
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;                     // �ֳ�Ϊ8Ϊ���ݸ�ʽ
	USART_InitStructure.USART_StopBits = USART_StopBits_1;                          // һ��ֹͣλ
	USART_InitStructure.USART_Parity = USART_Parity_No;                             // ����żУ��λ
	USART_InitStructure.USART_Mode = USART_Mode_Rx|USART_Mode_Tx;                   // �շ�ģʽ
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_Init(USART,&USART_InitStructure);                                         // ��ʼ������
	
	USART_Cmd(USART,ENABLE);                        // ʹ�ܴ���
	USART_ITConfig(USART,USART_IT_RXNE,ENABLE);     // ���������ж�
  
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
	// �ȴ��������һ���ֽ�
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
	   ReceiveData= USART_ReceiveData(USART);   //��������
	   USART_SendData(USART,ReceiveData);       //���ͽ��յ�������
	}
	
	USART_ClearITPendingBit(USART, USART_IT_RXNE);
}
