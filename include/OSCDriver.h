/************************************************************************
* Copyright (c) 2009,芯通科技有限公司
* All rights reserved.
* 文件名称：OSCDriver.h
* 文件标识：reserved
* 摘要：OSCDriver.dll的外部接口文件
*
************************************************************************/

// The following ifdef block is the standard way of creating macros whiCh make exporting 
// from a DLL simpler. All files within this DLL are compiled with the OSCDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// OSCDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef OSCDRIVER_EXPORTS
#define OSCDRIVER_API __declspec(dllimport)
#else
#define OSCDRIVER_API __declspec(dllexport)
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
* 更改：增加OSC_SetSweepPoint
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.1
* 作者：dolby.jiang
* 完成日期：2011年5月10日
* 更改：
1 增加 OSC_SaveTraceByName
2 增加 OSC_SetTraceMathTypeByName
3 增加 OSC_DeleteTraceByName
4 增加 OSC_DeleteAllTrace
5 增加 OSC_SetMarkerSearchFreqByName
6 增加 OSC_GetMarkerValueByName
7 增加 OSC_GetFluctuateByName
8 增加 OSC_GetMarkerFreqByName
*
************************************************************************/

/************************************************************************
* 版本：3.0.0.7
* 作者：dolby.jiang
* 完成日期：2011年8月5日
* 更改：
1 增加 OSC_GetTraceDataXByName
2 增加 OSC_GetTraceDataYByName
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
	OSCDRIVER_API short int	_stdcall	OSC_OpenDev(char *ConnectStr, short int *Handle);

	//关闭设备
	OSCDRIVER_API short int	_stdcall	OSC_CloseDev(short int Handle);

	//仪器复位	
	OSCDRIVER_API short int	_stdcall	OSC_Reset(short int Handle);

	//设置Dtime@level模式参数
	OSCDRIVER_API short int	_stdcall	OSC_SetDTLEVParam(short int Handle,short int Pos,short int Channel1,short int Slope1,double AbsLev1,short int Channel2,short int Slope2,double AbsLev2);
	
	//设置Grid	
	OSCDRIVER_API short int	_stdcall	OSC_SetGrid(short int Handle,short int gridType);

	//设置Trig类型
	OSCDRIVER_API short int	_stdcall	OSC_SetTrigType(short int Handle, short int trigType, short int source);

	//设置TrigCoupling
	OSCDRIVER_API short int	_stdcall	OSC_SetTrigCoupling(short int Handle,short int source, short int coupling);

	//设置TrigSlope
	OSCDRIVER_API short int	_stdcall	OSC_SetTrigSlope(short int Handle,short int source, short int Slope);

	//设置TrigLevel
	OSCDRIVER_API short int	_stdcall	OSC_SetTrigLevel(short int Handle,short int source, double level);

	//设置Vertical Scale
	OSCDRIVER_API short int	_stdcall	OSC_SetScaleVDIV(short int Handle,short int channel, double vdiv);

	//设置Timebase Scale
	OSCDRIVER_API short int	_stdcall	OSC_SetScaleTDIV(short int Handle, double tdiv);

	//获取DTL值
	OSCDRIVER_API short int	_stdcall	OSC_GetMeaValue(short int Handle, short int point, char *dtlvalue);

	//设置Trig Mode
	OSCDRIVER_API short int	_stdcall	OSC_SetTrigMode(short int Handle, short int mode);
	
	//Getcmd
	OSCDRIVER_API short int _stdcall	OSC_GetCmd(short int Handle, char *Command, char *RetStr);

	//Sendcmd
	OSCDRIVER_API short int _stdcall	OSC_SendCmd(short int Handle, char *Command);

	//设置DeltaDelay模式参数
	OSCDRIVER_API short int _stdcall	OSC_SetDeltaDelay(short int Handle, short int Pos, short int source1, short int source2);

	//设置Trace显示
	OSCDRIVER_API short int _stdcall	OSC_SetTraceDis(short int Handle, short int channel, short int Switch);

#ifdef __cplusplus
}
#endif























