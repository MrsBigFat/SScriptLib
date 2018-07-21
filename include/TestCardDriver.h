#pragma warning( disable : 4786)

/************************************************************************
* Copyright (c) 2009,芯通科技有限公司
* All rights reserved.
* 文件名称：NTSProducts.h
* 文件标识：reserved
* 摘要：This class is exported from the NTSProducts.dll
*
************************************************************************/

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NTSProducts_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NTSPRODUCTS_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifndef __TESTCARDDRIVER_H__
#define __TESTCARDDRIVER_H__

//Version 1.0
#define __TESTCARDDRIVER_H_VERSION 0x0001

#ifdef TESTCARDDRIVER_EXPORTS
#define NTSPRODUCTS_API __declspec(dllimport)
#else
#define NTSPRODUCTS_API __declspec(dllexport)
#endif

/************************************************************************
* 版本：2.0.1.0
* 作者：dolby.jiang
* 完成日期：2009年9月8日
* 更改：新建
*
************************************************************************/

/************************************************************************
* 版本：2.0.1.1
* 作者：dolby.jiang
* 完成日期：2010年1月16日
* 更改：将TC_GetCardVersion函数接口修改为TC_GetCardMCUVersion
*
************************************************************************/


#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif
	
	//打开并初始化设备
	NTSPRODUCTS_API short int	_stdcall	TC_OpenDev(char *ConnectStr, short int *devHandle);

	//关闭设备
	NTSPRODUCTS_API short int	_stdcall	TC_CloseDev(short int Handle);

	//获取测试卡MCU软件版本
	NTSPRODUCTS_API short int	_stdcall    TC_GetCardMCUVersion(short int Handle, char *version);

	//获取测试卡CPLD版本号
	NTSPRODUCTS_API short int	_stdcall    TC_GetCardCPLDVersion(short int Handle,char *version);

	//设置测试卡产品号 	
	NTSPRODUCTS_API short int	_stdcall    TC_SetCardProductNo(short int Handle, short ProductNo);
	
	//获取测试卡产品号
	NTSPRODUCTS_API short int	_stdcall    TC_GetCardProductNo(short int Handle, short *ProductNo);
	
	//获取产品生产信息
	NTSPRODUCTS_API short int	_stdcall    TC_GetIDN(short int Handle, char *IDNHigh, char *IDNLow);

	//发送指令
	NTSPRODUCTS_API short int	_stdcall    TC_SendCmd(short int Handle, char *Command);
	
	//获取返回指令值
	NTSPRODUCTS_API short int	_stdcall    TC_GetCmd(short int Handle, char *Command, char *RetStr);

	//设置测试卡FLASH起止地址的数据
	NTSPRODUCTS_API short int	_stdcall    TC_SetCardStartAndStopFlash(short int Handle,short FlashIndex,int StartAddress,long Count,int *Data);
	
	//获取测试卡FLAST起止地址的数据
	NTSPRODUCTS_API short int	_stdcall    TC_GetCardStartAndStopFlash(short int Handle,short FlashIndex,int StartAddress,long Count,int *Data);
	
#pragma pack()
	
#ifdef __cplusplus
}
#endif

#endif	

