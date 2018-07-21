
//////////////////////////////////////////////////////////////////////
/* 
*Copyright (c) 2009,芯通科技有限公司 
*All rights reserved.
*文件名称：LPTDriver.h
*文件标识：reserved
*摘要：Specify the Interface for InterfaceDriver.dll 
*/
//////////////////////////////////////////////////////////////////////


// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NTSDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NTSCOMDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifndef __LPTDriver_H__
#define __LPTDriver_H__

//Version 1.0
#define __NTSDRIVER_H_VERSION 0x0001

/************************************************************************/
/* 
*版本：3.0.0.0
*作者：Dolby.Jiang
*完成日期：2010年11月18日
*更改：新建
*/
/************************************************************************/

#ifdef NTSLPTDriver_EXPORTS
#define NTSLPTDRIVER_API __declspec(dllimport)
#else
#define NTSLPTDRIVER_API __declspec(dllexport)
#endif

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

	// 向I/O口写数据
	NTSLPTDRIVER_API short int _stdcall NTS_SetIOPortVal(WORD wPortAddr, DWORD dwPortVal, BYTE bSize); 
	
	// 从I/O读取数据
	NTSLPTDRIVER_API short int _stdcall NTS_GetIOPortVal(WORD wPortAddr, PDWORD pdwPortVal, BYTE bSize); 
	
	// 向I/O引脚缓冲区写入要发送的二进制数据
	NTSLPTDRIVER_API short int _stdcall NTS_SetIOBits( WORD wPortAddr, int Pin, char *Bits);

	// 向I/O引脚缓冲区写入要发送的二进制数据
	NTSLPTDRIVER_API short int _stdcall NTS_StartIO( WORD wPortAddr);
	
	// 设置时钟信号
	NTSLPTDRIVER_API short int _stdcall NTS_SetIOCLKBits( int Pin, char *Bits);

	// 设置T/R组件并口数据(Pin2:Data Pin3:CLK Pin4:Lock)
	NTSLPTDRIVER_API short int _stdcall NTS_SetIOTRBits( WORD wPortAddr, char *Bits);

	// 设置IO触发方式 0:Positive(上升沿) 1:Negative(下降沿)
	NTSLPTDRIVER_API short int _stdcall NTS_SetIOTrigPolarity( int Pin, BYTE Polarity);
	

#pragma pack()
	
#ifdef __cplusplus
}
#endif

#endif	

