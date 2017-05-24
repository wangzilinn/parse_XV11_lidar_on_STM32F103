# parse_XV11_lidar_on_STM32F103
XV11雷达数据通过串口1接收，可解析并串口2发送出接收到实时距离数据，可把角度数据分成36份放到一个数组中

### 硬件环境

- STM32F103C8T6
- STLink 2.0

###软件环境
- IAR7.10

### 通讯方式
Xv11雷达通过串口连接到STM32串口1上，STM32串口二连接到电脑可获得雷达信息

### 使用方式
1.  包含所有.h .c 文件
1.  在main函数中循环调用解析函数
1.  读出解析数组数组即可
