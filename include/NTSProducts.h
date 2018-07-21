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
#ifndef __NTSPRODUCTS_H__
#define __NTSPRODUCTS_H__

//Version 1.0
#define __NTSPRODUCTS_H_VERSION 0x0001

#ifdef NTSPRODUCTS_EXPORTS
#define NTSPRODUCTS_API __declspec(dllimport)
#else
#define NTSPRODUCTS_API __declspec(dllexport)
#endif

/************************************************************************
* 版本：2.0.1.0
* 作者：dolby.jiang
* 完成日期：2009年9月8日
* 更改：增加NTS_GetIDN并动态获取产品所支持的方法
*
************************************************************************/

/************************************************************************
* 版本：2.0.1.1
* 作者：dolby.jiang
* 完成日期：2009年9月8日
* 更改：增加NTS_SendCmd\NTS_GetCmd方法
*
************************************************************************/


/************************************************************************
* 版本：2.0.1.3
* 作者：dolby.jiang
* 完成日期：2009年11月23日
* 更改：1)修改打开函数
		2）修改函数加载位置
*
************************************************************************/

/************************************************************************
* 版本：2.0.1.3
* 作者：dolby.jiang
* 完成日期：2009年11月24日
* 更改：1) 增加NTS_SetCardStarAndStopFlash  NTS_GetCardStarAndStopFlash
*
************************************************************************/

/************************************************************************
* 版本：2.0.1.4
* 作者：dolby.jiang
* 完成日期：2009年12月29日
* 更改：1) 增加 NTS_SetPID NTS_SetGainWorkPara  NTS_GainDebug
*
************************************************************************/

/************************************************************************
* 版本：2.0.1.6
* 作者：dolby.jiang
* 完成日期：2010年1月25日
* 更改：1) 增加 NTS_SetCRC
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.0
* 作者：dolby.jiang
* 完成日期：2010年5月13日
* 更改：1) 修改句柄计算方法
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.1
* 作者：dolby.jiang
* 完成日期：2010年7月20日
* 更改：1) 增加 NTS_GetPowerState 方法
		2) 增加 NTS_SetStartAndStopRAM 方法
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.3
* 作者：dolby.jiang
* 完成日期：2010年12月29日
* 更改：1) 增加 NTS_GetVoltage 方法
		2) 增加 NTS_SetActiveObject 方法
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.4
* 作者：dolby.jiang
* 完成日期：2011年4月13日
* 更改：1) 增加 NTS_SetFourGAOutputVol 方法
		2) 增加 NTS_GetFourGAOutputVol 方法
*
************************************************************************/

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif
	
	//打开并初始化设备
	NTSPRODUCTS_API short int	_stdcall	NTS_OpenDev(char *ConnectStr, short int *devHandle);

	//关闭设备
	NTSPRODUCTS_API short int	_stdcall	NTS_CloseDev(short int Handle);
	
	//设置模块功能号
//	NTSPRODUCTS_API short int _stdcall    NTS_SetModuleFuncNo(short int Handle, unsigned char ModFuncNo);

	//设置模块编号
//	NTSPRODUCTS_API short int _stdcall    NTS_SetModuleNo(short int Handle, unsigned char ModNo);

	//设置通道的上行衰减值
//	NTSPRODUCTS_API short int _stdcall    NTS_SetUpAtten(short int Handle, short ch, short *upData);

	//获取通道的上行衰减值
//	NTSPRODUCTS_API short int _stdcall    NTS_GetUpAtten(short int Handle, short ch, short *upData);

	//设置通道的下行衰减值
//	NTSPRODUCTS_API short int _stdcall    NTS_SetDownAtten(short int Handle, short ch, short *downData);

	//获取通道的下行衰减值
//	NTSPRODUCTS_API short int _stdcall    NTS_GetDownAtten(short int Handle, short ch, short *downData);

	//获取通道的上行OPD
//	NTSPRODUCTS_API short int _stdcall    NTS_GetUpOpd(short int Handle, short ch, float *opdValue);

	//获取通道的下行OPD
//	NTSPRODUCTS_API short int _stdcall    NTS_GetDownOpd(short int Handle, short ch, float *opdValue);
	
	//获取通道的下行IPD
//	NTSPRODUCTS_API short int _stdcall    NTS_GetDownIpd(short int Handle, short ch, float *ipdValue);

	//获取模块软件版本
	NTSPRODUCTS_API short int _stdcall    NTS_GetModuleVersion(short int Handle, char *version);

	//获取测试卡软件版本
	NTSPRODUCTS_API short int _stdcall    NTS_GetCardVersion(short int Handle, char *version);

	//设置通道的温度补偿数据
	NTSPRODUCTS_API short int _stdcall    NTS_SetTmpCompensationData(short int Handle, short ch);

	//获取通道的温度补偿温度传感器的温度值
	NTSPRODUCTS_API short int _stdcall    NTS_GetTmpCompensationSense(short int Handle, short ch, float *temperature);

	//设置第一级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_SetPushOutputVol(short int Handle, short ch, float temperature, unsigned short DAvalue);

	//获取第一级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_GetPushOutPutVol(short int Handle, short ch, float temperature, unsigned short *DAvalue);

	//设置第二级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_SetSecGAOutputVol(short int Handle, short ch, float temperature, unsigned short DAvalue);
	
	//获取第二级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_GetSecGAOutputVol(short int Handle, short ch,float temperature,unsigned short *DAvalue);
	
	//设置第三级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_SetThirdGAOutputVol(short int Handle, short ch,float temperature,unsigned short DAvalue);
	
	//获取第三级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_GetThirdGAOutputVol(short int Handle, short ch, float temperature,unsigned short *DAvalue);
	
	//设置第四级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_SetFourGAOutputVol(short int Handle, short ch, float temperature, unsigned short DAvalue);
	
	//获取第四级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_GetFourGAOutputVol(short int Handle, short ch, float temperature, unsigned short *DAvalue);

	//设置第五级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_SetFiveGAOutputVol(short int Handle, short ch,float temperature,unsigned short DAvalue);
	
	//获取第五级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_GetFiveGAOutputVol(short int Handle, short ch,float temperature,unsigned short *DAvalue);
	
	//设置第六级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_SetSixGAOutputVol(short int Handle, short ch,float temperature,unsigned short DAvalue);
	
	//获取第六级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_GetSixGAOutputVol(short int Handle, short ch,float temperature,unsigned short *DAvalue);
	
	//设置第七级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_SetSevenGAOutputVol(short int Handle, short ch,float temperature,unsigned short DAvalue);
	
	//获取第七级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_GetSevenGAOutputVol(short int Handle, short ch,float temperature,unsigned short *DAvalue);
	
	//设置第八级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_SetEightGAOutputVol(short int Handle, short ch,float temperature,unsigned short DAvalue);
	
	//获取第八级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_GetEightGAOutputVol(short int Handle, short ch,float temperature,unsigned short *DAvalue);
	
	//设置第九级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_SetNineGAOutputVol(short int Handle, short ch,float temperature,unsigned short DAvalue);
	
	//获取第九级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_GetNineGAOutputVol(short int Handle, short ch,float temperature,unsigned short *DAvalue);
	
	//设置最后一级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_SetLastOutputVol(short int Handle, short ch, float temperature, unsigned short DAvalue);

	//获取最后一级功放的输出电压
	NTSPRODUCTS_API short int _stdcall    NTS_GetLastOutputVol(short int Handle, short ch, float temperature, unsigned short *DAvalue);

	//设置模块工作模式和检测模式(0:OPD 1:RPD)
	NTSPRODUCTS_API short int _stdcall    NTS_SetWorkMode(short int Handle, unsigned short workmode, unsigned short detectormode);

	//获取模块工作模式和检测模式
	NTSPRODUCTS_API short int _stdcall    NTS_GetWorkMode(short int Handle, unsigned short *workmode, unsigned short *detectormode);

	//设置1位PCB条码到模块
	NTSPRODUCTS_API short int _stdcall    NTS_SetOneBytePCB(short int Handle, unsigned short index, short pcb);

	//获取1位PCB条码
	NTSPRODUCTS_API short int _stdcall    NTS_GetOneBytePCB(short int Handle, unsigned short index, short* pcb);

	//设置所有PCB条码到FLASH
	NTSPRODUCTS_API short int _stdcall    NTS_SetPCB(short int Handle,BYTE *pcb);

	//获取所有PCB条码
	NTSPRODUCTS_API short int _stdcall    NTS_GetPCB(short int Handle,BYTE *PCB, long *length);

	//向模块EEPROM中某个地址写数据
	NTSPRODUCTS_API short int _stdcall    NTS_SetEEPROM(short int Handle, unsigned int address, float data);

	//获取EEPROM中某个地址的数据
	NTSPRODUCTS_API short int _stdcall    NTS_GetEEPROM(short int Handle, unsigned int address, float *data);

	//设置矩阵开关的模式
	NTSPRODUCTS_API short int _stdcall    NTS_SetSwtichMode(short int Handle, unsigned short k1, unsigned short k2, unsigned short k3, unsigned short k4);

	//设置模块供给电源状态
	NTSPRODUCTS_API short int _stdcall    NTS_SetPowerState(short int Handle, unsigned short powerstate);

	//获取模块供给电源状态
	NTSPRODUCTS_API short int _stdcall    NTS_GetPowerState(short int Handle, short *PowerState);
	

	//获取通道的温度
	NTSPRODUCTS_API short int _stdcall    NTS_GetTemperature(short int Handle,short ch,float *temperature);

	//获取模块的驻波比
	NTSPRODUCTS_API short int _stdcall    NTS_GetDownVSWR(short int Handle,short ch,float *vswrValue);

	//设置模块的本振频率
	NTSPRODUCTS_API short int _stdcall    NTS_SetLOFreq(short int Handle,short ch,float freq);

	//获取模块CPLD版本号
	NTSPRODUCTS_API short int _stdcall    NTS_GetModuleCPLDVersion(short int Handle,char *version);

	//获取测试卡CPLD版本号
	NTSPRODUCTS_API short int _stdcall    NTS_GetCardCPLDVersion(short int Handle,char *version);

	//设置模块通道的工作模式
	NTSPRODUCTS_API short int _stdcall    NTS_SetWorkModeEx(short int Handle, short ch, unsigned short workmode);

	//获取模块通道的工作模式
	NTSPRODUCTS_API short int _stdcall    NTS_GetWorkModeEx(short int Handle, short ch,	unsigned short *workmode);

	//设置模块通道的检测模式
	NTSPRODUCTS_API short int _stdcall    NTS_SetDetectorMode(short int Handle, short ch, unsigned short detectormode);

	//获取模块通道的检测模式
	NTSPRODUCTS_API short int _stdcall    NTS_GetDetectorMode(short int Handle, short ch, unsigned short *detectormode);

	//设置矩阵开关状态
	NTSPRODUCTS_API short int _stdcall    NTS_SetSwtichState(short int Handle,long count,short *state );

	//获取测试卡产品号
	NTSPRODUCTS_API short int _stdcall    NTS_GetCardProductNo(short int Handle,short *productno);

	//获取模块的产品号
	NTSPRODUCTS_API short int _stdcall    NTS_GetModuleProductNo(short int Handle,short *productno);

	//设置低噪放链路模式
	NTSPRODUCTS_API short int _stdcall    NTS_SetLanLinkMode(short int Handle,short ch,short mode);

	//设置指定通道的功率检测使能状态
	NTSPRODUCTS_API short int _stdcall    NTS_SetDectorState(short int Handle,short ch,short state);

	//设置起止地址的RRPROM数据
	NTSPRODUCTS_API short int _stdcall    NTS_SetStarAndStopEEPROM(short int Handle, unsigned int startaddress, long count, float *data);

	//获取起止地址的RRPROM数据
	NTSPRODUCTS_API short int _stdcall    NTS_GetStarAndStopEEPROM(short int Handle, unsigned int startaddress, long count, float *data);

	//设置通道PK级温度系数
//	NTSPRODUCTS_API short int _stdcall    NTS_SetPKTCeof(short int Handle,short ch,float Vo ,float To, float *Coefficient);

	//获取通道PK级温度系数
//	NTSPRODUCTS_API short int _stdcall    NTS_GetPKTCeof(short int Handle,short ch,float *Vo ,float *To, float *Coefficient);

	//设置通道小于-40度推动级的栅压斜率
//	NTSPRODUCTS_API short int _stdcall    NTS_SetPushLTCeof(short int Handle,short ch,int Coefficient);

	//获取通道小于-40度推动级的栅压斜率
//	NTSPRODUCTS_API short int _stdcall    NTS_GetPushLTCeof(short int Handle,short ch,int  *Coefficient);

	//设置通道小于-40度末级的栅压斜率
//	NTSPRODUCTS_API short int _stdcall    NTS_SetLastLTCeof(short int Handle,short ch,int  Coefficient);

	//获取通道小于-40度末级的栅压斜率
//	NTSPRODUCTS_API short int _stdcall    NTS_GetLastLTCeof(short int Handle,short ch,int  *Coefficient);

	//设置通道大于87度推动级的栅压斜率
//	NTSPRODUCTS_API short int _stdcall    NTS_SetPushHTCeof(short int Handle,short ch,int  Coefficient);

	//获取通道大于87度推动级的栅压斜率
//	NTSPRODUCTS_API short int _stdcall    NTS_GetPushHTCeof(short int Handle,short ch,int  *Coefficient);

	//设置通道大于87度末级的栅压斜率
//	NTSPRODUCTS_API short int _stdcall    NTS_SetLastHTCeof(short int Handle,short ch,int  Coefficient);

	//获取通道大于87度末级的栅压斜率
//	NTSPRODUCTS_API short int _stdcall    NTS_GetLastHTCeof(short int Handle,short ch,int  *Coefficient);

	//设置通道PK级参考电压偏移量
//	NTSPRODUCTS_API short int _stdcall    NTS_SetPKVolOffset(short int Handle,short ch,short VolIndex,float StartVol, float StopVol,int VolOffset);
	
	//设置通道推动级参考电压偏移量
//	NTSPRODUCTS_API short int _stdcall    NTS_SetPushVolOffset(short int Handle,short ch,short VolIndex,float StartVol, float StopVol,int VolOffset);
	
	//设置通道末级参考电压偏移量
//	NTSPRODUCTS_API short int _stdcall    NTS_SetLastVolOffset(short int Handle,short ch,short VolIndex,float StartVol, float StopVol,int VolOffset);
	
	//获取通道PK级参考电压偏移量
//	NTSPRODUCTS_API short int _stdcall    NTS_GetPKVolOffset(short int Handle,short ch,short VolIndex,float *StartVol, float *StopVol,int *VolOffset);
	
	//获取通道推动级参考电压偏移量
//	NTSPRODUCTS_API short int _stdcall    NTS_GetPushVolOffset(short int Handle,short ch,short VolIndex,float *StartVol, float *StopVol,int *VolOffset);

	//获取通道末级参考电压偏移量
//	NTSPRODUCTS_API short int _stdcall    NTS_GetLastVolOffset(short int Handle,short ch,short VolIndex,float *StartVol, float *StopVol,int *VolOffset);

	//设置RAM起止地址的数据
	NTSPRODUCTS_API short int _stdcall    NTS_SetStartAndStopRAM(short int Handle, short FlashIndex, int startaddress, long count, int *data);
	
	//设置FLASH起止地址的数据
	NTSPRODUCTS_API short int _stdcall    NTS_SetStarAndStopFlash(short int Handle,short FlashIndex,int startaddress,long count,int *data);

	//获取FLAST起止地址的数据
	NTSPRODUCTS_API short int _stdcall    NTS_GetStarAndStopFlash(short int Handle,short FlashIndex,int startaddress,long count,int *data);
	
	//获取通道的电流值(单位:bit)
	NTSPRODUCTS_API short int _stdcall    NTS_GetCurrent(short int Handle, short ch, float *Current);

	// 获取通道的电压(单位:bit)
	NTSPRODUCTS_API short int _stdcall    NTS_GetVoltage(short int Handle, short ch, float *Voltage);
	
	// 设置当前需要的监控对象(Type 1:电流 2:电压 3:温度 Index 1:PA1电流|PA1温度|28V 2:PA2电流|PA2温度|5V 3:PA3电流|PA3温度 4:PA4电流|PA4温度)
	NTSPRODUCTS_API short int _stdcall    NTS_SetActiveObject(short int Handle, short ch, int Type, int Index);
	
	//设置通道的上下限电流值(单位:bit)
	NTSPRODUCTS_API short int _stdcall    NTS_SetCurrentLimited(short int Handle, short ch,float DownCurrent, float UpCurrent);

	//获取通道的上下限电流值(单位:bit)
	NTSPRODUCTS_API short int _stdcall    NTS_GetCurrentLimited(short int Handle, short ch,float *DownCurrent, float *UpCurrent);

	//获取告警信息
	NTSPRODUCTS_API short int _stdcall    NTS_GetIsWarning(short int Handle, short ch,int *state);

	//清除告警信息
	NTSPRODUCTS_API short int _stdcall    NTS_ClearWarning(short int Handle,short ch);

	//获取产品生产信息
	NTSPRODUCTS_API short int _stdcall    NTS_GetIDN(short int Handle, char *IDNHigh, char *IDNLow);

	//发送指令
	NTSPRODUCTS_API short int _stdcall    NTS_SendCmd(short int Handle, char *Command);
	
	//获取返回指令值
	NTSPRODUCTS_API short int _stdcall    NTS_GetCmd(short int Handle, char *Command, char *RetStr);
	
	//设置电流调试参数	
	NTSPRODUCTS_API short int _stdcall    NTS_SetPID(short int Handle, int GainIndex, double P, double I,  double D);
	
	//设置功放的静态工作参数	
	NTSPRODUCTS_API short int _stdcall    NTS_SetGainWorkPara(short int Handle, int GainIndex, double WorkCurrent, 
		double ErrCurrent, int InitDA, int MinDA, int MaxDA);
	
	//在电流表下调试单级功放的静态工作电流
	NTSPRODUCTS_API short int _stdcall    NTS_GainDebug(short int Handle,  short int MMTPort, short Ch, int GainIndex, 
		int FlashIndex, int BaseAddress, float *RefTemperature, int *RefDA);	
	
	// 写校验码
	NTSPRODUCTS_API short int _stdcall    NTS_SetCRC(short int Handle);
	
	//数据拟合
//	NTSPRODUCTS_API short int _stdcall    NTS_DataCalculate(double *K, int n, double RefTemperature, double RefDA);

	
#pragma pack()
	
#ifdef __cplusplus
}
#endif

#endif	

