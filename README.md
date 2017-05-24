# parse_XV11_lidar_on_STM32F103
XV11雷达数据通过串口1接收，可解析并串口2发送出接收到实时距离数据，可把角度数据分成36份放到一个数组中

------------

### 硬件环境

- STM32F103C8T6
- STLink 2.0

------------


### 软件环境
- IAR7.10
- 硬件库版本3.5

------------


### 通讯方式
XV11雷达通过串口连接到STM32串口1上，STM32串口二连接到电脑可获得雷达信息
波特率均为115200

------------


### 包含文件
1. include.h包含全部头文件，其中
	1. stm32f10x.h
	 system_stm32f10x.h
	 stm32f10x_conf.h
	 为硬件库头文件
	1. stm32f10x_it.h
	为封装好的串口接收雷达中断函数
	1. usart_send.h
	为封装的串口发送函数头文件，用于查看雷达输出信息
	1. XV11_parse.h
	为雷达数据解析头文件
1. main.c
main.h
	1. 初始化了串口1以及串口2
	2. 循环调用了雷达解析函数，
	1. 通过串口2打印雷达解析数据
1. stm32f10x_it.c
stm32f10x_it.h
为雷达串口接收中断
1. usart_send.c
usart_send.h
为封装好的串口发送函数
1. XV11_parse.c
XV11_parse.h
为封装好的雷达数据解析函数

------------


### 调用方法
有两个变量存储了雷达距离数据，在main.c中已经有很好的实例
1. 获取实时雷达数据：
由于雷达每发送一个数据包包含四个角度数据，所以raderData[]有4个，依次调用数组内容即可获得每次雷达获得的数据
`for (u8 i = 0; i < 4; i++)
		{
			Usart_send_string(USART2,"angle ");
			Usart_send_u16(USART2,(u16)raderData[i].angle);
			Usart_send_space(USART2);
			Usart_send_string(USART2,"distence ");
			Usart_send_u16(USART2,raderData[i].distance);
			usart_send_enter(USART2);
			Usart_send_u16(USART2,raderDataTable[9]);
			usart_send_enter(USART2);
		}`

1. 获取精简后的雷达数据
精简后的雷达数据放在了一个长度为36的u16数组中，想要哪个角度直接调用即可
`for (u8 i = 0; i < 36; i++)
		{
			Usart_send_string(USART2,"angle ");
			Usart_send_u16(USART2,i * 10);
			Usart_send_space(USART2);
			Usart_send_string(USART2,"distence ");
			Usart_send_u16(USART2,raderDataTable[i]);
			usart_send_enter(USART2);
		}
`
------------

2017-05-24 20:01:26 星期三