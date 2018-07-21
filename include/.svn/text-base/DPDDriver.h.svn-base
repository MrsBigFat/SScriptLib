/************************************************************************
* Copyright (c) 2009,芯通科技有限公司
* All rights reserved.
* 文件名称：T1440DTDPDDriver.h
* 文件标识：reserved
* 摘要：This class is exported from the DPDDriver.dll
*
************************************************************************/

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DPDDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DPDDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef DPDDRIVER_EXPORTS
#define DPDDRIVER_API __declspec(dllexport)
#else
#define DPDDRIVER_API __declspec(dllimport)
#endif

/************************************************************************
* 版本：2.0.1.2
* 作者：dolby.jiang
* 完成日期：2009年9月4日
* 更改：增加GetIDN方法
*
************************************************************************/

/************************************************************************
* 版本：2.0.1.3
* 作者：dolby.jiang
* 完成日期：2009年9月23日
* 更改：增加DPD_SetTwelvePwrFpg方法
*
************************************************************************/

/************************************************************************
* 版本：2.0.1.4
* 作者：dolby.jiang
* 完成日期：2009年11月23日
* 更改：1）修改打开函数 
2）增加	DPD_SendCmd DPD_GetCmd方法
*
************************************************************************/


/************************************************************************
* 版本：2.0.0.5
* 作者：dolby.jiang
* 完成日期：2010年3月23日
* 更改：
1 增加 SetCFR
2 增加 GetCFR
*
************************************************************************/
#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

	//打开并初始化设备
	DPDDRIVER_API short int	_stdcall	DPD_OpenDev(char *protocol, short int *Handle);

	//关闭设备
	DPDDRIVER_API short int	_stdcall	DPD_CloseDev(short int Handle);

	//重启
	DPDDRIVER_API short int	_stdcall	DPD_Reboot(short int Handle);

	//DPD板复位
	DPDDRIVER_API short int	_stdcall	DPD_Reset(short int Handle);

	//设置DPD开关状态(0:关 1:开)
	DPDDRIVER_API short int	_stdcall	DPD_SetDPDState(short int Handle,short int State);

	//设置发射通道衰减值
	DPDDRIVER_API short int	_stdcall	DPD_SetTxAtten(short int Handle, int Atten);

	//设置反馈通道衰减值
	DPDDRIVER_API short int	_stdcall	DPD_SetRDAtten(short int Handle, int Atten);

	//获取偏差功率
	DPDDRIVER_API short int	_stdcall	DPD_GetErrPower(short int Handle,float *Power);

	//设置6载波功率因子
	DPDDRIVER_API short int	_stdcall	DPD_SetSixPwrFpg(short int Handle);

	//设置9载功率波因子
	DPDDRIVER_API short int	_stdcall	DPD_SetNinePwrFpg(short int Handle);

	//设置12载功率波因子
	DPDDRIVER_API short int	_stdcall	DPD_SetTwelvePwrFpg(short int Handle);
	
	//DPD偏差功率调试
	DPDDRIVER_API short int	_stdcall	DPD_SetErrPwrDebug(short int Handle, float ErrPower, float *RealErrPwr);

	//获取发射通道衰减值
	DPDDRIVER_API short int	_stdcall	DPD_GetTxAtten(short int Handle,int *Atten);

	//获取反馈通道衰减值
	DPDDRIVER_API short int	_stdcall	DPD_GetRDAtten(short int Handle,int *Atten);

	//设置DPD输出功率
	DPDDRIVER_API short int	_stdcall	DPD_SetRFOutPower(short int Handle,int Power);

	//获取DPD输出功率
	DPDDRIVER_API short int	_stdcall	DPD_GetRFOutPower(short int Handle,int *Power);

	//设置DPD工作频率(1: B频段 2: A频段 3:875/930/1810  4:880/946.8/1830  5:885/955/1855
	//6:1830 7:1850 8:1875  9:1910 10:1890 )
	DPDDRIVER_API short int	_stdcall	DPD_SetWorkFreq(short int Handle,int FreqMode);

	//设置DPD的IP地址
	DPDDRIVER_API short int	_stdcall	DPD_SetIP(short int Handle,int IP_Add_1,int IP_Add_2);

	//设置输出TX链路细调功率值
	DPDDRIVER_API short int	_stdcall	DPD_SetSmallTxAtten(short int Handle,double Atten);

	//获取输出TX链路细调功率值
	DPDDRIVER_API short int	_stdcall	DPD_GetSmallTxAtten(short int Handle,double *Atten);

	//设置DPD信号模式(0:GMSK  1:8PSK 2:GMSK+8PSK)
	DPDDRIVER_API short int	_stdcall	DPD_SetSGMode(short int Handle,int Mode);

	//设置DPD载波模式	
	/* Mode : 0:3M等间隔	1:3M不等间隔	2:5M等间隔	3:5M不等间隔  
	4:10M等间隔	5:10M不等间隔	6:15M等间隔 7:15M不等间隔 
	*/ 
	DPDDRIVER_API short int	_stdcall	DPD_SetCarriedMode(short int Handle,int Mode);

	//设置载波个数(0:3载波	1:4载波	2:6载波)
	DPDDRIVER_API short int	_stdcall	DPD_SetCarriedCount(short int Handle,int Count);
		
	//获取生产信息
	DPDDRIVER_API short int	_stdcall	DPD_GetIDN(short int Handle, char *IDN);

	//发送指令
	DPDDRIVER_API	short int _stdcall	DPD_SendCmd(short int Handle, char *Command);
	
	//获取返回指令值
	DPDDRIVER_API	short int _stdcall	DPD_GetCmd(short int Handle, char *Command, char *RetStr);
	
	// 设置CFR门限值
	DPDDRIVER_API short int	_stdcall	DPD_SetCFR(short int Handle, unsigned int CfrValue);
	
	// 获取CFR门限值
	DPDDRIVER_API short int	_stdcall	DPD_GetCFR(short int Handle, unsigned int *CfrValue);
	
	// 读取设备返回数据
	DPDDRIVER_API short int _stdcall	DPD_ReadDev(short int Handle, char *RetSrt, int ReadCount, int *RealCount);
	
	
#pragma pack()
	
#ifdef __cplusplus
}
#endif