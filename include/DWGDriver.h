/************************************************************************
* Copyright (c) 2009,芯通科技有限公司
* All rights reserved.
* 文件名称：DWGDriver.h
* 文件标识：reserved
* 摘要：DWGDriver.dll的外部接口文件
*
************************************************************************/

// The following ifdef block is the standard way of creating macros whiCh make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DWGDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DWGDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef DWGDRIVER_EXPORTS
#define DWGDRIVER_API __declspec(dllimport)
#else
#define DWGDRIVER_API __declspec(dllexport)
#endif

#pragma warning(disable:4786)
/************************************************************************
* 版本：2.0.1.0
* 作者：dolby.jiang
* 完成日期：2009年8月26日
* 更改：文件建立
*
************************************************************************/

/************************************************************************
* 版本：2.0.1.1
* 作者：dolby.jiang
* 完成日期：2009年9月23日
* 更改：增加手动配置ACPR的方法接口
*
************************************************************************/


/************************************************************************
* 版本：2.0.1.2
* 作者：dolby.jiang
* 完成日期：2009年9月25日
* 更改：修改SetMeasNoiseBW接口
*
************************************************************************/


/************************************************************************
* 版本：2.0.1.3
* 作者：dolby.jiang
* 完成日期：2009年9月30日
* 更改：修改函数加载位置
*
************************************************************************/


/************************************************************************
* 版本：2.0.1.4
* 作者：dolby.jiang
* 完成日期：2009年11月23日
* 更改：修改打开函数
*
************************************************************************/

/************************************************************************
* 版本：3.0.0.0
* 作者：dolby.jiang
* 完成日期：2010年5月6日
* 更改：增加DWG_SetSweepPoint
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.1
* 作者：dolby.jiang
* 完成日期：2011年5月10日
* 更改：
1 增加 DWG_SaveTraceByName
2 增加 DWG_SetTraceMathTypeByName
3 增加 DWG_DeleteTraceByName
4 增加 DWG_DeleteAllTrace
5 增加 DWG_SetMarkerSearchFreqByName
6 增加 DWG_GetMarkerValueByName
7 增加 DWG_GetFluctuateByName
8 增加 DWG_GetMarkerFreqByName
*
************************************************************************/

/************************************************************************
* 版本：3.0.0.7
* 作者：dolby.jiang
* 完成日期：2011年8月5日
* 更改：
1 增加 DWG_GetTraceDataXByName
2 增加 DWG_GetTraceDataYByName
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.8
* 作者：dolby.jiang
* 完成日期：2011年9月9日
* 更改：
1 增加 Vsa 89600 Method
*
************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
	
	//打开并初始化设备
	DWGDRIVER_API short int	_stdcall	DWG_OpenDev(char *ConnectStr, short int *Handle);

	//关闭设备
	DWGDRIVER_API short int	_stdcall	DWG_CloseDev(short int Handle);

	//仪器复位	
	DWGDRIVER_API short int	_stdcall	DWG_Reset(short int Handle);

	//获取IDN返回信息
	DWGDRIVER_API short int	_stdcall	DWG_GetIDN(short int Handle, char *IDN);

	//读取文件
	DWGDRIVER_API short int	_stdcall	DWG_LoadFile(short int Handle, char *FileName);

	//发送命令
	DWGDRIVER_API short int	_stdcall	DWG_SendCmd(short int Handle, char *Command);

	//获取命令返回值
	DWGDRIVER_API short int	_stdcall	DWG_GetCmd(short int Handle, char *Command, char *RetStr);

	//设置通道开关
	DWGDRIVER_API short int	_stdcall	DWG_SetCHSwitch(short int Handle, short int channel, short int select);

	//设置总开关
	DWGDRIVER_API short int	_stdcall	DWG_SetAllSwitch(short int Handle, short int select);

	//设置电平
	DWGDRIVER_API short int	_stdcall	DWG_SetAmpLevel(short int Handle, double level);
	
#ifdef __cplusplus
}
#endif























