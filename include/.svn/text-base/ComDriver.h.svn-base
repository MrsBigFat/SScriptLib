
//////////////////////////////////////////////////////////////////////
/* 
*Copyright (c) 2009,芯通科技有限公司 
*All rights reserved.
*文件名称：ComDriver.h
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
#ifndef __COMDRIVER_H__
#define __COMDRIVER_H__

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

#ifdef NTSCOMDRIVER_EXPORTS
#define NTSCOMDRIVER_API __declspec(dllimport)
#else
#define NTSCOMDRIVER_API __declspec(dllexport)
#endif

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

	//打开并初始化设备
	NTSCOMDRIVER_API short int	_stdcall	NTS_OpenCom(char *ConnectStr, short int *Handle);
	
	// 关闭串口,释放内存资源
	NTSCOMDRIVER_API short int	_stdcall	NTS_CloseCom(short int Handle);

	// 设置Com通讯参数
	NTSCOMDRIVER_API short int	_stdcall	NTS_SetCom(short int Handle, int BaudRate, int Databit, int parity, int stopbit);
	
	// 从串口读取数据
	NTSCOMDRIVER_API short int	_stdcall	NTS_ReadCom(short int Handle, char*ReadBuf, unsigned long Count, unsigned long *RealCount);
	
	// 向串口写数据
	NTSCOMDRIVER_API short int	_stdcall	NTS_WriteCom(short int Handle, char*WriteBuf, unsigned long Count);	
	
	// 查询Com口
	NTSCOMDRIVER_API short int	_stdcall	NTS_QueryCom(short int Handle, char *WriteBuf, unsigned long Count, char *ReadBuf, unsigned long *RealCount);
	
	// 设置缓冲区长度(Mask 0:ALL 1:Tx_Buffer 2:Rx_Buffer)
	NTSCOMDRIVER_API short int	_stdcall	NTS_SetComBufSize(short int Handle, unsigned short Mask, unsigned int Size);
	
	// 获取缓冲区长度(1:Tx_Buffer 2:Rx_Buffer)
	NTSCOMDRIVER_API short int	_stdcall	NTS_GetComBufSize(short int Handle, unsigned short Mask, unsigned int *Size);
	
	// 清除缓冲区(Mask 0:ALL 1:Tx_Buffer 2:Rx_Buffer)
	NTSCOMDRIVER_API short int	_stdcall	NTS_FlushComBuf(short int Handle, unsigned short Mask);
	
	// 设置系统超时时间量(单位:秒)
	NTSCOMDRIVER_API short int	_stdcall	NTS_SetComTimeOut(int TimeOut);	
	
	// 设置RTS(数据终端就绪)标志  硬件流控制 0:Low 1:Hight
	NTSCOMDRIVER_API short int	_stdcall	NTS_SetDTR(short int Handle, int State);		
	
	// 设置RTS(设置请求数据发送)标志  硬件流控制 0:Low 1:Hight
	NTSCOMDRIVER_API short int	_stdcall	NTS_SetRTS(short int Handle, int State);		
	
	// 设置XOFF(设置流数据停止发送)标志 软件流控制 
	NTSCOMDRIVER_API short int	_stdcall	NTS_SetXOFF(short int Handle);		
	
	// 设置XON(设置流数据继续发送)标志 软件流控制
	NTSCOMDRIVER_API short int	_stdcall	NTS_SetXON(short int Handle);	

#pragma pack()
	
#ifdef __cplusplus
}
#endif

#endif	

