
/* -------------------------------------------------------------------------
//	文件名		：	InterfaceDriver.h
//	创建者		：	dolby jiang
//	创建时间	：	08-3-12 10:53:04
//	功能描述	：	Specify the Interface for InterfaceDriver.dll 
//
// -----------------------------------------------------------------------*/

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NTSDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NTSDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifndef __SWDRIVER_H__
#define __SWDRIVER_H__

//Version 1.0
#define __NTSDRIVER_H_VERSION 0x0001

#ifdef SWDRIVER_EXPORTS
#define NTSDRIVER_API __declspec(dllexport)
#else
#define NTSDRIVER_API __declspec(dllimport)
#endif

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif
	//获取函数入口名称
	NTSDRIVER_API short int	_stdcall	SW_GetFunName(char **name,short *count);
	//打开并初始化设备
	NTSDRIVER_API short int	_stdcall	SW_OpenDev(char *protocol, short int *devhandle);
	//关闭设备
	NTSDRIVER_API short int	_stdcall	SW_CloseDev(short int handle);

	//设置矩阵开关状态
	NTSDRIVER_API short int _stdcall    SW_SetSwtichState(short int handle,long count,short *state );

#pragma pack()
	
#ifdef __cplusplus
}
#endif

#endif	

