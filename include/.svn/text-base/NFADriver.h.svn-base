/************************************************************************
* Copyright (c) 2009,芯通科技有限公司
* All rights reserved.
* 文件名称：NFADriver.h
* 文件标识：reserved
* 摘要：NFADriver.dll的外部接口文件
*
************************************************************************/

// The following ifdef block is the standard way of creating macros whiCh make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NFADRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NFADRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef NFADRIVER_EXPORTS
#define NFADRIVER_API __declspec(dllexport)
#else
#define NFADRIVER_API __declspec(dllimport)
#endif

/************************************************************************
* 版本：2.0.1.0
* 作者：dolby.jiang
* 完成日期：2009年9月24日
* 更改：文件建立
*
************************************************************************/


/************************************************************************
* 版本：2.0.1.1
* 作者：dolby.jiang
* 完成日期：2009年11月23日
* 更改：修改打开函数
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.0
* 作者：dolby.jiang
* 完成日期：2010年5月12日
* 更改：
	1 增加 GetTraceMax接口
	2 增加 GetTraceMin接口
	3 增加 GetTraceFreqValue接口
*
************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
	
	//打开并初始化设备
	NFADRIVER_API short int	_stdcall	NFA_OpenDev(char *ConnectStr, short int *Handle);

	//关闭设备
	NFADRIVER_API short int	_stdcall	NFA_CloseDev(short int Handle);

	//重启设备
	NFADRIVER_API short int	_stdcall	NFA_Reset(short int Handle);

	//设置频率模式 0:SWEep 1:LIST 2:FIXed
	NFADRIVER_API short int _stdcall    NFA_SetFreqMode(short int Handle, unsigned short FreqMode);

	//设置起始频率值和截止频率
	NFADRIVER_API short int	_stdcall	NFA_SetStartAndStopFreq(short int Handle, float StartFreq, float StopFreq);	

	//设置显示模式 0:GRAPh 1:TABLe 2:METer
	NFADRIVER_API short int _stdcall    NFA_SetDispFormat(short int Handle, unsigned short Format);

	//获得指定频率点的噪声系数
	NFADRIVER_API short int _stdcall    NFA_GetFreqNfigure(short int Handle, float FixedFreq, float *Value);

	//设置扫描模式 0:Single 1:Continous
	NFADRIVER_API short int _stdcall    NFA_SetSweepMode(short int Handle, unsigned short Mode);

	//加载文件
	NFADRIVER_API short int _stdcall	NFA_LoadFile(short int Handle , char *FileName);

	//获取最大噪声系数值
	NFADRIVER_API short int _stdcall	NFA_GetListMax(short int Handle, float StartFreq, float Step, unsigned long FreqCount, float *Max);
	
	//获取设备型号信息
	NFADRIVER_API	short int _stdcall	NFA_GetIDN(short int Handle, char *IDN);
	
	//发送指令
	NFADRIVER_API	short int _stdcall	NFA_SendCmd(short int Handle, char *Command);
	
	//获取返回指令值
	NFADRIVER_API	short int _stdcall	NFA_GetCmd(short int Handle, char *Command, char *RetStr);

	// 获取曲线数据的最大值(TraceIndex 1:NFIGure 2:GAIN 3:PHOT 4:PCOLd 5:TEFFective)
	NFADRIVER_API	short int _stdcall	NFA_GetTraceMax(short int Handle, int TraceIndex, double *Max);
	
	// 获取曲线数据的最小值(TraceIndex 1:NFIGure 2:GAIN 3:PHOT 4:PCOLd 5:TEFFective)
	NFADRIVER_API	short int _stdcall	NFA_GetTraceMin(short int Handle, int TraceIndex, double *Min);
	
	// 获取曲线指定频率点的值(TraceIndex 1:NFIGure 2:GAIN 3:PHOT 4:PCOLd 5:TEFFective Freq:单位:MHz)
	NFADRIVER_API	short int _stdcall	NFA_GetTraceFreqValue(short int Handle, int TraceIndex, double Freq, double *Value);
	
		
#ifdef __cplusplus
}
#endif


