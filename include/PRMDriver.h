/************************************************************************
* Copyright (c) 2009,芯通科技有限公司
* All rights reserved.
* 文件名称：PRMDriver.h
* 文件标识：reserved
* 摘要：PRMDriver.dll的外部接口文件
*
************************************************************************/

// The following ifdef block is the standard way of creating macros whiCh make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PRMDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PRMDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef PRMDRIVER_EXPORTS
#define PRMDRIVER_API __declspec(dllexport)
#else
#define PRMDRIVER_API __declspec(dllimport)
#endif

/************************************************************************
* 版本：2.0.1.0
* 作者：dolby.jiang
* 完成日期：2009年9月25日
* 更改：文件建立
*
************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
	
	//打开并初始化设备
	PRMDRIVER_API short int	_stdcall	PRM_OpenDev(char *ConnectStr, short int *Handle);

	//关闭设备
	PRMDRIVER_API short int	_stdcall	PRM_CloseDev(short int Handle);

	//复位 
	PRMDRIVER_API short int	_stdcall	PRM_Reset(short int Handle);

	//校准
	PRMDRIVER_API short int	_stdcall	PRM_Calculate(short int Handle, float Freq);

	//设置测量位置(0:Load 1:SOURce)
	PRMDRIVER_API short int	_stdcall	PRM_SetMeasPos(short int Handle, short Port, short Mode);

	//设置插损(0~100 dB)
	PRMDRIVER_API short int	_stdcall	PRM_SetOffset(short int Handle, short Port, float Offset);

	//获取测试测量值
	PRMDRIVER_API short int	_stdcall	PRM_GetPower(short int Handle, float *Pwr, float *SWR);

	//设置测量模式(0:平均功率 1:峰值功率 2:脉冲功率 )
	PRMDRIVER_API short int	_stdcall	PRM_SetMeasMode(short int Handle, short Mode);

	//设置测量单位(0:W 1:DB 2:%)
	PRMDRIVER_API short int	_stdcall	PRM_SetMeasUnit(short int Handle, short Unit);

	//获取设备型号信息
	PRMDRIVER_API	short int _stdcall	PRM_GetIDN(short int Handle, char *IDN);
	
	//发送指令
	PRMDRIVER_API	short int _stdcall	PRM_SendCmd(short int Handle, char *Command);
	
	//获取返回指令值
	PRMDRIVER_API	short int _stdcall	PRM_GetCmd(short int Handle, char *Command, char *RetStr);
		
#ifdef __cplusplus
}
#endif


