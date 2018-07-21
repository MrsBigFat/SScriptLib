/************************************************************************
* Copyright (c) 2009,芯通科技有限公司
* All rights reserved.
* 文件名称：IRUDriver.h
* 文件标识：reserved
* 摘要：This class is exported from the IRUDriver.dll
*
************************************************************************/

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the IRUDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// IRUDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef IRUDRIVER_EXPORTS
#define IRUDRIVER_API __declspec(dllimport)
#else
#define IRUDRIVER_API __declspec(dllexport)
#endif

/************************************************************************
* 版本：2.0.0.0
* 作者：dolby.jiang
* 完成日期：2009年12月21日
* 更改：新建
*
************************************************************************/

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

	//打开并初始化设备
	IRUDRIVER_API short int	_stdcall	IRU_OpenDev(char *protocol, short int *Handle);

	//关闭设备
	IRUDRIVER_API short int	_stdcall	IRU_CloseDev(short int Handle);

	//重启
	IRUDRIVER_API short int	_stdcall	IRU_Reboot(short int Handle);

	//IRU板复位
	IRUDRIVER_API short int	_stdcall	IRU_Reset(short int Handle);
		
	//获取生产信息
	IRUDRIVER_API short int	_stdcall	IRU_GetIDN(short int Handle, char *IDN);

	//发送指令
	IRUDRIVER_API	short int _stdcall	IRU_SendCmd(short int Handle, char *Command);
	
	//获取返回指令值
	IRUDRIVER_API	short int _stdcall	IRU_GetCmd(short int Handle, char *Command, char *RetStr);

	//加载文件
	IRUDRIVER_API short int _stdcall    IRU_LoadFile(short int Handle, char *FileName);
	
	
#pragma pack()
	
#ifdef __cplusplus
}
#endif