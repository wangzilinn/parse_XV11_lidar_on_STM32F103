#ifndef __USART_SEND_H
#define __USART_SEND_H
#include "stm32f10x.h"
/**
 * 发送一个字节
 * @Author   zilin-Wang
 * @DateTime 2017-02-28
 * @version  1.0
 * @param    USARTx     串口号
 * @param    Byte       发送内容
 */
extern void Usart_send_byte(USART_TypeDef * USARTx, u8 Byte);
/**
 * USART发送一个字节数组
 * @Author   zilin-Wang
 * @DateTime 2017-02-28
 * @version  1.0
 * @param    USARTx     串口号
 * @param    Array      数组名
 * @param    Length     数组长度
 */
extern void Usart_send_array(USART_TypeDef * USARTx, u8 * Array, u8 Length);
/**
 * 发送一个字符串
 * @Author   zilin-Wang
 * @DateTime 2017-02-28
 * @version  1.0	
 * @param    USARTx     串口号
 * @param    String     指针
 */
extern void Usart_send_string(USART_TypeDef * USARTx, u8 * String);
/**
 * 最多发送一个4位正数
 * @Author   zilin-Wang
 * @DateTime 2017-03-01
 * @version  1.0
 * @param    USARTx     串口号
 * @param    data       四位数
 */
extern void Usart_send_u16(USART_TypeDef * USARTx, u16 data);
/**
 * 发送空格
 * @Author   zilin-Wang
 * @DateTime 2017-03-01
 * @version  1.0
 */
extern void Usart_send_space(USART_TypeDef * USARTx);
/**
 * 发送回车
 * @Author   zilin-Wang
 * @DateTime 2017-03-01
 * @version  1.0
 */
extern void usart_send_enter(USART_TypeDef * USARTx);
#endif