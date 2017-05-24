#include "usart_send.h"
#include "stm32f10x.h"
//----------------------------------------------------------------------------//
//函数功能：USART发送一个字节
//入口参数：USARTx是USART模块号；Byte是要发送的字节
//出口参数：无
//最后修改：2016.4.18
//备注：
//----------------------------------------------------------------------------//
void Usart_send_byte(USART_TypeDef * USARTx, u8 Byte)
{
	while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
	USARTx->DR = Byte;	
}

//----------------------------------------------------------------------------//
//函数功能：USART发送一个字节数组
//入口参数：USARTx是USART模块号；
//出口参数：无
//最后修改：2016.4.20
//备注：
//----------------------------------------------------------------------------//
void Usart_send_array(USART_TypeDef * USARTx, u8 * Array, u8 Length)
{
	while(Length-- != 0)
	{
		while((USARTx->SR & USART_SR_TC) != USART_SR_TC);	//等待上一次发送完毕
		USARTx->DR = *Array++;
	}
}

//----------------------------------------------------------------------------//
//函数功能：USART发送一个字符串
//入口参数：USARTx是USART模块号；String是要发送的字符串
//出口参数：无
//最后修改：2016.4.20
//备注：
//----------------------------------------------------------------------------//
void Usart_send_string(USART_TypeDef * USARTx, u8 * String)
{
	while(*String != '\0')
	{
		while((USARTx->SR & USART_SR_TC) != USART_SR_TC);	//等待上一次发送完毕
		USARTx->DR = *String++;
	}
}
/**
 * 最多发送一个4位数
 * @Author   zilin-Wang
 * @DateTime 2017-03-01
 * @version  1.0
 * @param    USARTx     串口号
 * @param    data       四位数
 */
void Usart_send_u16(USART_TypeDef * USARTx, u16 data)
{
	if (data >= 1000)
	{
		while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
		USARTx->DR = (u8)(data / 1000) + 48;	
		while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
		USARTx->DR = (u8)((data % 1000) / 100) + 48;			
		while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
		USARTx->DR = (u8)((data % 100) / 10) + 48;		
		while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
		USARTx->DR = (u8)(data % 10) + 48;	
	}
	if (data >= 100)
	{
		while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
		USARTx->DR = (u8)((data % 1000) / 100) + 48;			
		while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
		USARTx->DR = (u8)((data % 100) / 10) + 48;		
		while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
		USARTx->DR = (u8)(data % 10) + 48;		
	}
	else if (data >= 10)
	{
		while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
		USARTx->DR = (u8)(data / 10) + 48;	
		while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
		USARTx->DR = (u8)(data % 10) + 48;
	}
	else
	{
		while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
		USARTx->DR = (u8)(data % 10) + 48;
	}
}
/**
 * 发送空格
 * @Author   zilin-Wang
 * @DateTime 2017-03-01
 * @version  1.0
 */
void Usart_send_space(USART_TypeDef * USARTx)
{
	while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
	USARTx->DR = 0x20;//空格			
}
/**
 * 发送回车
 * @Author   zilin-Wang
 * @DateTime 2017-03-01
 * @version  1.0
 */
void usart_send_enter(USART_TypeDef * USARTx)
{
	while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
	USARTx->DR = 0x0d;	
	while((USARTx->SR & USART_SR_TC) != USART_SR_TC);		//等待上一次发送完毕
	USARTx->DR = 0x0a;		
}
