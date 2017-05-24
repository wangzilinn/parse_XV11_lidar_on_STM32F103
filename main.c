/* 包含头文件 ----------------------------------------------------------------*/
#include "includes.h"
/************************************************************  
* Function: Usart1_init  
* Description:   
* Input parameter: void  
* Return parameter: void  
* Calls:  
* Called by:  
* Author: zilin Wang     Build_Date:2017-5-24 15:46:45
* Other:  
*************************************************************/  
void Usart1_init(void)  
{  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_USART1 | RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_initStructure;
	GPIO_initStructure.GPIO_Pin = GPIO_Pin_9;//tx
	GPIO_initStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_initStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_initStructure);
	GPIO_initStructure.GPIO_Pin = GPIO_Pin_10;//rx
	GPIO_initStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_initStructure);
	
	NVIC_InitTypeDef NVIC_InitStructure;   
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//usart1
	NVIC_InitStructure.NVIC_IRQChannel                   = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	USART_InitTypeDef USART_initStructure;
	USART_initStructure.USART_BaudRate = 115200;
	USART_initStructure.USART_WordLength = USART_WordLength_8b;
	USART_initStructure.USART_StopBits = USART_StopBits_1;
	USART_initStructure.USART_Parity = USART_Parity_No;
	USART_initStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_initStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART1, &USART_initStructure);
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	USART_ITConfig(USART1, USART_IT_TXE, DISABLE);
	USART_Cmd(USART1, ENABLE);
	USART_ClearFlag(USART1, USART_IT_RXNE);	
}  

/************************************************************  
* Function: Usart2_init  
* Description:   
* Input parameter: void  
* Return parameter: void  
* Calls:  
* Called by:  
* Author: zilin Wang     Build_Date:2017-5-24 15:47:57
* Other:  
*************************************************************/  

void Usart2_init(void)  
{  
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);

	GPIO_InitTypeDef GPIO_initStructure;
	GPIO_initStructure.GPIO_Pin = GPIO_Pin_2;//tx
	GPIO_initStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_initStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA, &GPIO_initStructure);
	GPIO_initStructure.GPIO_Pin = GPIO_Pin_3;//rx
	GPIO_initStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA, &GPIO_initStructure);

	NVIC_InitTypeDef NVIC_InitStructure;   
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//usart2
	NVIC_InitStructure.NVIC_IRQChannel                   = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	USART_InitTypeDef USART_initStructure;
	USART_initStructure.USART_BaudRate = 115200;
	USART_initStructure.USART_WordLength = USART_WordLength_8b;
	USART_initStructure.USART_StopBits = USART_StopBits_1;
	USART_initStructure.USART_Parity = USART_Parity_No;
	USART_initStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_initStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART2, &USART_initStructure);
	USART_ITConfig(USART2, USART_IT_RXNE, ENABLE);//?????ж?
	USART_ITConfig(USART2, USART_IT_TXE, DISABLE);//????????
	USART_Cmd(USART2, ENABLE);
	USART_ClearFlag(USART2, USART_IT_RXNE);	
}  

/************************************************************  
* Function: NVIC_init  
* Description:   
* Input parameter: void  
* Return parameter: void  
* Calls:  
* Called by:  
* Author: zilin Wang     Build_Date:2017-5-24 15:48:32
* Other:  
*************************************************************/  

void NVIC_init(void)  
{  
	NVIC_InitTypeDef NVIC_InitStructure;   
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	//usart1
	NVIC_InitStructure.NVIC_IRQChannel                   = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	//usart2
	NVIC_InitStructure.NVIC_IRQChannel                   = USART2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority        = 1;
	NVIC_InitStructure.NVIC_IRQChannelCmd                = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}  
/************************************************************  
 * Function: Main  
 * Description: The main function
 * Calls:  
 * Author: zilin Wang      Build_Date：2017/3/25 星期六    
 * Others:  
************************************************************/  
void main(void)  
{  
	SystemInit();
	NVIC_init();
	Usart1_init();
	Usart2_init();
    while(1)
    {  
		start_parse_XV11();
		//Output the distance data
		for (u8 i = 0; i < 4; i++)
		{
			Usart_send_string(USART2,"angle ");
			Usart_send_u16(USART2,(u16)raderData[i].angle);
			Usart_send_space(USART2);
			Usart_send_string(USART2,"distence ");
			Usart_send_u16(USART2,raderData[i].distance);
			usart_send_enter(USART2);
			Usart_send_u16(USART2,raderDataTable[9]);
			usart_send_enter(USART2);
		}
//		//Output the distance data array (Only 36 distance values)
//		for (u8 i = 0; i < 36; i++)
//		{
//			Usart_send_string(USART2,"angle ");
//			Usart_send_u16(USART2,i * 10);
//			Usart_send_space(USART2);
//			Usart_send_string(USART2,"distence ");
//			Usart_send_u16(USART2,raderDataTable[i]);
//			usart_send_enter(USART2);		
//		}
    }
}