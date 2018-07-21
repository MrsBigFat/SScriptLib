/************************************************************************
* Copyright (c) 2009,芯通科技有限公司
* All rights reserved.
* 文件名称： NTSScriptLib.h
* 文件标识：reserved
* 摘要：Specify the Interface for NTSScriptLib.dll 
*
************************************************************************/
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NTSSCRIPTLIB_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NTSSCRIPTLIB_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifndef __NTSSCRIPTLIB_H__
#define __NTSSCRIPTLIB_H__


//Version 2.0
#define __NTSSCRIPTLIB_H_VERSION 0x0002

/************************************************************************
* 版本：2.1.0.0
* 作者：dolby.jiang
* 完成日期：2009年10月12日
* 更改：文件整理
*
************************************************************************/


/************************************************************************
* 版本：2.1.0.4
* 作者：dolby.jiang
* 完成日期：2009年11月6日
* 更改：修改DA值数据类型
*
************************************************************************/

/************************************************************************
* 版本：2.1.0.4
* 作者：dolby.jiang
* 完成日期：2009年11月12日
* 更改：增加PRM_GetIDN PRM_SendCmd PRM_GetCmd
*
************************************************************************/


/************************************************************************
* 版本：2.1.0.5
* 作者：dolby.jiang
* 完成日期：2009年11月24日
* 更改：删除设备句柄判断语句
*
************************************************************************/

/************************************************************************
* 版本：3.0.2.1
* 作者：dolby.jiang
* 完成日期：2010年11月16日
* 更改：增加扩展设备接口
*
************************************************************************/


#ifdef NTSSCRIPTLIB_EXPORTS
#define NTSSCRIPTLIB_API __declspec(dllexport)
#else
#define NTSSCRIPTLIB_API __declspec(dllimport)
#endif

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif
	
	//初始化方法库
	NTSSCRIPTLIB_API short int __stdcall     InitMethodLib();

	//打开设备
	NTSSCRIPTLIB_API short int __stdcall     OpenDevice(int devType, char *ConnectStr, int *devHandle);

	//关闭设备
	NTSSCRIPTLIB_API short int __stdcall     CloseDevice(int devType, char *ConnectStr);

	//获取设备名称
	NTSSCRIPTLIB_API short int __stdcall     GetDevice(char **name,unsigned long *count);

	//获取驱动库类名
	NTSSCRIPTLIB_API short int __stdcall     GetDriverTypeName(char **name,unsigned long *count);
	
	//获取方法库中所有的驱动库方法
	NTSSCRIPTLIB_API short int __stdcall     GetAllMethod(char *(methodName[50]), unsigned long *count);

	//获取某类设备的驱动库方法
	NTSSCRIPTLIB_API short int __stdcall     GetMethodEx(int MethodType, char *(methodName[50]), unsigned long *count);

	//验证某个方法名是否合法
	NTSSCRIPTLIB_API short int __stdcall     MethodIsInLib(char *methodName, unsigned short *IsInLib);
	
	//创建一个方法
	NTSSCRIPTLIB_API short int __stdcall     CreateMethod(char *methodName, int *methodHandle);

	//删除一个方法
	NTSSCRIPTLIB_API short int __stdcall     DeleteMethod(int methodHandle);

	//获取方法功能描述语
	NTSSCRIPTLIB_API short int	__stdcall	GetMethodScript(int methodHandle, char *Script);

	//设置方法功能描述语
	NTSSCRIPTLIB_API short int	__stdcall	SetMethodScript(int methodHandle, char *Script);

	//获取方法的输入个数
	NTSSCRIPTLIB_API short int	__stdcall	GetInputParamNum(int methodHandle, unsigned short *inputParamNum);

	//获取某个输入参数的详细信息(参数名|参数类型|参数个数|参数值|单位)
	NTSSCRIPTLIB_API short int  __stdcall    GetInputParaInfo(int methodHandle, unsigned short inputParamIndex, 
		char *paramName, int *paramType, unsigned short *paramNum, char *paramVal, char *paramUnit);
	
	// 设置某个参数的参数值(扩展内存长度)
	NTSSCRIPTLIB_API short int  __stdcall    SetInputParamVal(int methodHandle, unsigned short inputParamIndex, char *paramVal);
	
	//设置某个参数的参数值
	NTSSCRIPTLIB_API short int  __stdcall    SetInputParamValEx(int methodHandle, unsigned short inputParamIndex, char *paramVal, long Len);
	
	//获取方法的输出参数个数
	NTSSCRIPTLIB_API short int	__stdcall	GetOutputParamNum(int methodHandle, unsigned short *outputParamNum);
	
	//获取某个输出参数的参数详细信息(参数名|参数类型|参数个数|参数值|单位)
	NTSSCRIPTLIB_API short int  __stdcall    GetOutputParaInfo(int methodHandle, unsigned short outParamIndex, 
		char *paramName, int *paramType, unsigned short *paramNum, char *paramVal, char *paramUnit);
	
	//运行方法
	NTSSCRIPTLIB_API short int	__stdcall	DoMethodRun(int methodHandle);

	//获取产品的调试/校准方法
	NTSSCRIPTLIB_API short int	__stdcall	GetADMethodName(char *ProductName, char **MethodName ,int *Count);

	//获取参数类型
	NTSSCRIPTLIB_API short int	__stdcall	GetParaName(char **TypeName ,int *Count);

	//获取设备的连接字符串
	NTSSCRIPTLIB_API short int	__stdcall	GetConnectStr(int DeviceType, int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

	//获取产品的驱动库
	NTSSCRIPTLIB_API short int	__stdcall	GetDeviceMethod(int DeviceType, char *ConnectStr, char **Name, int *Count);
		
	//获取设备的前缀名(DeviceType 0:All)
	NTSSCRIPTLIB_API short int	__stdcall	GetDevicePreName(int DeviceType, char **Name, int *Count);

	// 设置通信属性参数(CommIsStr) 
	NTSSCRIPTLIB_API short int	__stdcall	SetAttributeDev(char *ConnectStr, char *attrName, int attrState);  
	
	
#pragma pack()
	
#ifdef __cplusplus
}
#endif

#endif	
