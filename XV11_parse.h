#ifndef __XV11_PARSE_H
#define __XV11_PARSE_H
/* 包含头文件 ----------------------------------------------------------------*/
#include "stm32f10x.h"
#define bool u8
#define true 1
#define false 0
/* 变量声明 ------------------------------------------------------------------*/
extern u8 raderReceiveQueue[22];
extern vu8 raderReceiveBuffer[22];
extern u8 raderReceiveCnt;
extern FlagStatus raderDataCorrectFlag;
extern u8 raderOriginalDataTable[22];//解析用
extern u16 raderDataTable[36];//最终结果
extern FlagStatus raderBusyFlag;
typedef struct
{
	bool disvalid;
	u16 distance;
	int sigintens;
	int angle;
}raderDataTypeDef;
extern raderDataTypeDef raderData[4];  
/* 函数声明 ------------------------------------------------------------------*/
extern void start_parse_XV11();
#endif