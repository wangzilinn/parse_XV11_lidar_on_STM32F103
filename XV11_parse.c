/***********************************************************  
 *  
 * Copyright (C), 2017, Chuying Lab .   
 *  
 * FileName：XV11_parse  
 * Author: zilin Wang       Version : 1.0         Date: 2017-5-24 16:07:07
 * Description: XV11解析文件
 * Function List:     
 * Others:      
***********************************************************/  
/* 包含头文件 ----------------------------------------------------------------*/
#include "XV11_parse.h" 

/* 变量定义 ------------------------------------------------------------------*/
u8 raderReceiveQueue[22] = {0};//接收用
vu8 raderReceiveBuffer[22] = {0};//传递用
u8 raderOriginalDataTable[22] = {0};//解析用
u16 raderDataTable[36] = {0};//最终结果
u8 raderReceiveCnt = 0;
FlagStatus raderDataCorrectFlag = RESET;
FlagStatus raderBusyFlag = RESET;
raderDataTypeDef raderData[4];

/* 函数定义 ------------------------------------------------------------------*/
  
/************************************************************  
 * Function: start_parse_XV11  
 * Description: Began to parse lidar data,it is recommended that the function be placed in a loop
 * Input parameter: void  
 * Return parameter: void  
 * Calls:  
 * Called by:  
* Author: zilin Wang     Build_Date:2017-5-24 17:24:38
 * Other:  
*************************************************************/  
   
void start_parse_XV11(void)  
{  
   if (raderDataCorrectFlag == SET)
   {
	   for (u8 i = 0; i < 22; i++)
	   {
		   raderOriginalDataTable[i] = raderReceiveBuffer[i];
	   }
	   raderDataCorrectFlag = RESET;
	   for (u8 i = 0; i < 4; i++)
	   {
		   int beg = 4 * i;				
		   raderData[i].disvalid = ((0xff & raderOriginalDataTable[5 + beg]) >> 7) == 0 ? true : false;//Verify data
		   if (raderData[i].disvalid == true)
		   {	
			   raderData[i].distance = ((0x3f & raderOriginalDataTable[5 + beg]) << 8) | raderOriginalDataTable[4 + beg];
			   raderData[i].sigintens = (raderOriginalDataTable[7 + beg] << 8) + raderOriginalDataTable[6 + beg];
			   raderData[i].angle = (raderOriginalDataTable[1]-0xa0)*4 + i;
			   if (raderData[i].angle >= 355)//顺时针旋转5度 Turn clockwise 5 degrees
				   raderDataTable[(raderData[i].angle - 355)/ 10] = raderData[i].distance;
			   else
				   raderDataTable[(raderData[i].angle + 5)/ 10] = raderData[i].distance;
		   }
	   }
   }
   else
	   return;
}  

