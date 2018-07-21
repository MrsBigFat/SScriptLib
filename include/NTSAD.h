
/* -------------------------------------------------------------------------
//	文件名		：	NTSAD.h
//	创建者		：	dolby jiang
//	创建时间	：	08-3-12 10:53:04
//	功能描述	：	Specify the Interface for NTSAD.dll 
//
// -----------------------------------------------------------------------*/

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NTSAD_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NTSAD_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifndef __NTSAD_H__
#define __NTSAD_H__

//Version 1.0
#define __NTSAD_H_VERSION 0x0001

/************************************************************************
* 版本：2.0.1.0
* 作者：dolby.jiang
* 完成日期：2009年12月29日
* 更改：1)修改打开函数
		2）修改函数加载位置
*
************************************************************************/


/************************************************************************
* 版本：2.0.1.1
* 作者：dolby.jiang
* 完成日期：2010年3月29日
* 更改：1) 设备管理结构体中增加动态库编号信息变量
		2）修改API接口中获取设备句柄的方法
*
************************************************************************/

#ifdef NTSAD_EXPORTS
#define NTSAD_API __declspec(dllexport)
#else
#define NTSAD_API __declspec(dllimport)
#endif

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif
	
	//打开并初始化设备
	NTSAD_API short int	_stdcall	AD_OpenDev(char *ConnectStr, short int *devHandle);

	//关闭设备
	NTSAD_API short int	_stdcall	AD_CloseDev(short int Handle);

	//写校准
	NTSAD_API short int	_stdcall	AD_WriteCal(short int Handle,char *ParamTypeName, int FlowSN, 
		char *SMTSN, char *ClientSN, int *Count, float *Data, int *Address);

	//读取校准数据
	NTSAD_API short int	_stdcall	AD_ReadCal(short int Handle,int *Count, float *Data, int *Address);

	//获取产品的客户SN与校准数据是否有关系
	NTSAD_API short int	_stdcall	AD_GetClientSNRelate(short int Handle,int *State);
	
	//在电流表下调试功放的静态工作点
	NTSAD_API short int	_stdcall	AD_WriteDebug(short int Handle,int ComNo,char *ParamTypeName,
		int CHIndex,int *GainCount, float *RFTemperature,int *DACount ,float *DAValue);

	//读取调试数据
	NTSAD_API short int	_stdcall	AD_ReadDebug(short int Handle,int CHIndex, int *GainCount, int *DACount ,float *DAValue);

	
#pragma pack()
	
#ifdef __cplusplus
}
#endif

#endif	

