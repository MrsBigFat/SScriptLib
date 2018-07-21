#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"


/************************************************************************
* 版本：2.0.0.45
* 作者：dolby.jiang
* 完成日期：2009年10月10日
* 更改：
*
************************************************************************/


/************************************************************************
* 版本：2.1.0.0
* 作者：dolby.jiang
* 完成日期：2009年10月13日
* 更改：增加NTS_SendCmd\NTS_GetCmd 方法类
*
************************************************************************/


/************************************************************************
* 版本：2.1.0.7
* 作者：dolby.jiang
* 完成日期：2009年12月30日
* 更改：1) 增加 M_NTS_SetStarAndStopFlash
		2) 增加 M_NTS_GetStarAndStopFlash
		3) 增加 M_NTS_SetStarAndStopEEPROM
		4) 增加 M_NTS_GetStarAndStopEEPROM		
*
************************************************************************/

/************************************************************************
* 版本：2.1.0.7
* 作者：dolby.jiang
* 完成日期：2010年1月25日
* 更改：1) 增加 M_NTS_SetCRC		
*
************************************************************************/


/************************************************************************
* 版本：2.1.0.8
* 作者：dolby.jiang
* 完成日期：2010年2月26日
* 更改：1) 增加 M_NTS_SetPID 设置电流调试参数		
		2) 增加 M_NTS_SetGainWorkPara 设置功放的静态工作参数
		3) 增加 M_NTS_GainDebug 在电流表下调试单级功放的静态工作电流
*
************************************************************************/

/************************************************************************
* 版本：3.0.0.8
* 作者：dolby.jiang
* 完成日期：2010年7月12日
* 更改：1) 增加 M_NTS_GetPowerState 获取电源开关状态			
*
************************************************************************/

/************************************************************************
* 版本：3.0.2.5
* 作者：dolby.jiang
* 完成日期：2010年12月29日
* 更改：1) 增加 M_NTS_GetVoltage 获取通道的电压(单位:bit)
		2) 增加 M_NTS_SetActiveObject 设置当前需要的监控的对象
*
************************************************************************/

/************************************************************************
* 版本：3.0.2.8
* 作者：dolby.jiang
* 完成日期：2011年4月13日
* 更改：1) 增加 M_NTS_SetFourGAOutputVol 设置第四级功放的输出电压
		2) 增加 M_NTS_GetFourGAOutputVol 获取第四级功放的输出电压
*
************************************************************************/

/************************************************************************/
/*  公司模块驱动程序方法类                                               */
/************************************************************************/

//M_NTS_OpenDev 打开设备
class M_NTS_OpenDev: public BaseMethod
{
public:
	M_NTS_OpenDev();
	virtual ~M_NTS_OpenDev();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1, m_InputPara2;	
	TParamSetStruct m_OutputPara1;
};

//M_NTS_CloseDev 关闭设备
class M_NTS_CloseDev: public BaseMethod
{
public:
	M_NTS_CloseDev();
	virtual ~M_NTS_CloseDev();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1, m_InputPara2;	
};

//Class M_NTS_SetModuleFuncNo 设置模块功能号
/*
class M_NTS_SetModuleFuncNo:public BaseMethod
{
public:
   M_NTS_SetModuleFuncNo();
   virtual ~M_NTS_SetModuleFuncNo();
   virtual int Init(void);
   virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};*/

//class M_NTS_SetModuleNo 设置模块编号
/*
class M_NTS_SetModuleNo:public BaseMethod
{
public:
	M_NTS_SetModuleNo();
	virtual ~M_NTS_SetModuleNo();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};*/

//class M_NTS_SetUpAtten 设置通道的上行衰减值
/*
class M_NTS_SetUpAtten:public BaseMethod
{
public:
	M_NTS_SetUpAtten();
	virtual ~M_NTS_SetUpAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};*/

//class M_NTS_GetUpAtten 获取通道的上行衰减值
/*
class M_NTS_GetUpAtten:public BaseMethod
{
public:
	M_NTS_GetUpAtten();
	virtual ~M_NTS_GetUpAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
	
};*/

//class M_NTS_SetDownAtten 设置通道的下行衰减值
/*
class M_NTS_SetDownAtten:public BaseMethod
{
public:
	M_NTS_SetDownAtten();
	virtual ~M_NTS_SetDownAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};*/

//class M_NTS_GetDownAtten 获取通道的下行衰减值
/*
class M_NTS_GetDownAtten:public BaseMethod
{
public:
	M_NTS_GetDownAtten();
	virtual ~M_NTS_GetDownAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};*/

//class M_NTS_GetUpOpd 获取通道的上行OPD
/*
class M_NTS_GetUpOpd:public BaseMethod
{
public:
	M_NTS_GetUpOpd();
	virtual ~M_NTS_GetUpOpd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};*/

//class M_NTS_GetDownOpd 获取通道的下行OPD
/*
class M_NTS_GetDownOpd:public BaseMethod
{
public:
	M_NTS_GetDownOpd();
	virtual ~M_NTS_GetDownOpd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
	
};*/

//class M_NTS_GetDownIpd 获取通道的下行IPD
/*
class M_NTS_GetDownIpd:public BaseMethod
{
public:
	M_NTS_GetDownIpd();
	virtual ~M_NTS_GetDownIpd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};*/

//class M_NTS_GetModuleVersion 获取模块MCU的软件版本
class M_NTS_GetModuleVersion:public BaseMethod
{
public:
	M_NTS_GetModuleVersion();
	virtual ~M_NTS_GetModuleVersion();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_GetCardVersion 获取测试卡MCU的软件版本
class M_NTS_GetCardVersion:public BaseMethod
{
public:
	M_NTS_GetCardVersion();
	virtual ~M_NTS_GetCardVersion();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetTmpCompensationData 设置通道的温度补偿数据
class M_NTS_SetTmpCompensationData:public BaseMethod
{
public:
	M_NTS_SetTmpCompensationData();
	virtual ~M_NTS_SetTmpCompensationData();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_GetTmpCompensationSense 获取通道的温度补偿温度传感器数据
class M_NTS_GetTmpCompensationSense:public BaseMethod
{
public:
	M_NTS_GetTmpCompensationSense();
	virtual ~M_NTS_GetTmpCompensationSense();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetPushOutputVol 设置通道的推动级调整输出电压(DA值)
class M_NTS_SetPushOutputVol:public BaseMethod
{
public:
	M_NTS_SetPushOutputVol();
	virtual ~M_NTS_SetPushOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};
//class M_NTS_GetPushOutPutVol 获取通道的推动级调整输出电压(DA值)
class M_NTS_GetPushOutPutVol:public BaseMethod
{
public:
	M_NTS_GetPushOutPutVol();
	virtual ~M_NTS_GetPushOutPutVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetLastOutputVol 设置通道的末级调整输出电压(DA值)
class M_NTS_SetLastOutputVol:public BaseMethod
{
public:
	M_NTS_SetLastOutputVol();
	virtual ~M_NTS_SetLastOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};
//class M_NTS_GetLastOutputVol 获取通道的末级调整输出电压(DA值)
class M_NTS_GetLastOutputVol:public BaseMethod
{
public:
	M_NTS_GetLastOutputVol();
	virtual ~M_NTS_GetLastOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetWorkMode 设置模块工作模式和检测模式(0:OPD 1:RPD)
class M_NTS_SetWorkMode:public BaseMethod
{
public:
	M_NTS_SetWorkMode();
	virtual ~M_NTS_SetWorkMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_GetWorkMode 获取模块的工作模式
class M_NTS_GetWorkMode:public BaseMethod
{
public:
	M_NTS_GetWorkMode();
	virtual ~M_NTS_GetWorkMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1,m_OutputPara2;
};
//class M_NTS_SetOneBytePCB 设置1位PCB条码
class M_NTS_SetOneBytePCB:public BaseMethod
{
public:
	M_NTS_SetOneBytePCB();
	virtual ~M_NTS_SetOneBytePCB();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_GetOneBytePCB 获取1位PCB条码
class M_NTS_GetOneBytePCB:public BaseMethod
{
public:
	M_NTS_GetOneBytePCB();
	virtual ~M_NTS_GetOneBytePCB();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetPCB 设置PCB条码到FLASH中
class M_NTS_SetPCB:public BaseMethod
{
public:
	M_NTS_SetPCB();
	virtual ~M_NTS_SetPCB();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};
//class M_NTS_GetPCB 获取PCB条码
class M_NTS_GetPCB:public BaseMethod
{
public:
	M_NTS_GetPCB();
	virtual ~M_NTS_GetPCB();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetEEPROM 设置EEPROM数据
class M_NTS_SetEEPROM:public BaseMethod
{
public:
	M_NTS_SetEEPROM();
	virtual ~M_NTS_SetEEPROM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_GetEEPROM 获取EEPROM数据
class M_NTS_GetEEPROM:public BaseMethod
{
public:
	M_NTS_GetEEPROM();
	virtual ~M_NTS_GetEEPROM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetSwtichMode 设置矩阵开关的模式
class M_NTS_SetSwtichMode:public BaseMethod
{
public:
	M_NTS_SetSwtichMode();
	virtual ~M_NTS_SetSwtichMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3,m_InputPara4;
};
//class M_NTS_SetPowerState 设置模块的供给电源状态
class M_NTS_SetPowerState:public BaseMethod
{
public:
	M_NTS_SetPowerState();
	virtual ~M_NTS_SetPowerState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//class M_NTS_GetPowerState 获取模块的供给电源状态
class M_NTS_GetPowerState:public BaseMethod
{
public:
	M_NTS_GetPowerState();
	virtual ~M_NTS_GetPowerState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};

//class M_NTS_GetTemperature 获取通道的温度
class M_NTS_GetTemperature:public BaseMethod
{
public:
	M_NTS_GetTemperature();
	virtual ~M_NTS_GetTemperature();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};

/*

//class M_NTS_GetAgedData 获取模块老化数据(温度，电流，PCB条码)
class M_NTS_GetAgedData:public BaseMethod
{
public:
	M_NTS_GetAgedData();
	virtual ~M_NTS_GetAgedData();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara[50];
};*/

/*
//class M_NTS_SetAgedWorkMode 设置模块老化时的工作模式
class M_NTS_SetAgedWorkMode:public BaseMethod
{
public:
	M_NTS_SetAgedWorkMode();
	virtual ~M_NTS_SetAgedWorkMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3,m_InputPara4;
	
};
*/

//class M_NTS_GetDownVSWR 获取模块的驻波比
class M_NTS_GetDownVSWR:public BaseMethod
{
public:
	M_NTS_GetDownVSWR();
	virtual ~M_NTS_GetDownVSWR();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetLOFreq 设置模块的本振频率
class M_NTS_SetLOFreq:public BaseMethod
{
public:
	M_NTS_SetLOFreq();
	virtual ~M_NTS_SetLOFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	
};
//class M_NTS_GetModuleCPLDVersion 获取模块CPLD的软件版本
class M_NTS_GetModuleCPLDVersion:public BaseMethod
{
public:
	M_NTS_GetModuleCPLDVersion();
	virtual ~M_NTS_GetModuleCPLDVersion();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_GetCardCPLDVersion 获取测试卡CPLD的软件版本
class M_NTS_GetCardCPLDVersion:public BaseMethod
{
public:
	M_NTS_GetCardCPLDVersion();
	virtual ~M_NTS_GetCardCPLDVersion();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetWorkModeEx 设置模块指定通道的工作模式
class M_NTS_SetWorkModeEx:public BaseMethod
{
public:
	M_NTS_SetWorkModeEx();
	virtual ~M_NTS_SetWorkModeEx();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_GetWorkModeEx 获取模块指定通道的工作模
class M_NTS_GetWorkModeEx:public BaseMethod
{
public:
	M_NTS_GetWorkModeEx();
	virtual ~M_NTS_GetWorkModeEx();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1,m_OutputPara2;
};
//class M_NTS_SetDetectorMode 设置模块指定通道的检测模式
class M_NTS_SetDetectorMode:public BaseMethod
{
public:
	M_NTS_SetDetectorMode();
	virtual ~M_NTS_SetDetectorMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_GetDetectorMode 获取模块指定通道的检测模式
class M_NTS_GetDetectorMode:public BaseMethod
{
public:
	M_NTS_GetDetectorMode();
	virtual ~M_NTS_GetDetectorMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1;
};

//M_NTS_GetCardProductNo 获取测试卡产品号
class M_NTS_GetCardProductNo:public BaseMethod
{
public:
	M_NTS_GetCardProductNo();
	virtual ~M_NTS_GetCardProductNo();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};
//M_NTS_GetModuleProductNo 获取模块的产品号
class M_NTS_GetModuleProductNo:public BaseMethod
{
public:
	M_NTS_GetModuleProductNo();
	virtual ~M_NTS_GetModuleProductNo();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};
//class M_NTS_SetLanLinkMode 设置模块指定通道的低噪放链路模式
class M_NTS_SetLanLinkMode:public BaseMethod
{
public:
	M_NTS_SetLanLinkMode();
	virtual ~M_NTS_SetLanLinkMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_SetDectorState 设置指定通道的功率检测使能状态(0:off 1:on)
class M_NTS_SetDectorState:public BaseMethod
{
public:
	M_NTS_SetDectorState();
	virtual ~M_NTS_SetDectorState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};

//class M_NTS_SetSecGAOutputVol 设置第二级功放的输出电压
class M_NTS_SetSecGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetSecGAOutputVol();
	virtual ~M_NTS_SetSecGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};
//class M_NTS_GetSecGAOutputVol 获取第二级功放的输出电压
class M_NTS_GetSecGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetSecGAOutputVol();
	virtual ~M_NTS_GetSecGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};

//class M_NTS_SetThirdGAOutputVol 设置第三级功放的输出电压
class M_NTS_SetThirdGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetThirdGAOutputVol();
	virtual ~M_NTS_SetThirdGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//class M_NTS_GetThirdGAOutputVol 获取第三级功放的输出电压
class M_NTS_GetThirdGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetThirdGAOutputVol();
	virtual ~M_NTS_GetThirdGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};

//class M_NTS_SetFourGAOutputVol 设置第四级功放的输出电压
class M_NTS_SetFourGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetFourGAOutputVol();
	virtual ~M_NTS_SetFourGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//class M_NTS_GetFourGAOutputVol 获取第四级功放的输出电压
class M_NTS_GetFourGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetFourGAOutputVol();
	virtual ~M_NTS_GetFourGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};


//设置第五级功放的输出电压
class M_NTS_SetFiveGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetFiveGAOutputVol();
	virtual ~M_NTS_SetFiveGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//获取第五级功放的输出电压
class M_NTS_GetFiveGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetFiveGAOutputVol();
	virtual ~M_NTS_GetFiveGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};


//设置第六级功放的输出电压
class M_NTS_SetSixGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetSixGAOutputVol();
	virtual ~M_NTS_SetSixGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//获取第六级功放的输出电压
class M_NTS_GetSixGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetSixGAOutputVol();
	virtual ~M_NTS_GetSixGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};

//设置第七级功放的输出电压
class M_NTS_SetSevenGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetSevenGAOutputVol();
	virtual ~M_NTS_SetSevenGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//获取第七级功放的输出电压
class M_NTS_GetSevenGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetSevenGAOutputVol();
	virtual ~M_NTS_GetSevenGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};

//设置第八级功放的输出电压
class M_NTS_SetEightGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetEightGAOutputVol();
	virtual ~M_NTS_SetEightGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//获取第八级功放的输出电压
class M_NTS_GetEightGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetEightGAOutputVol();
	virtual ~M_NTS_GetEightGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};

//设置第九级功放的输出电压
class M_NTS_SetNineGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetNineGAOutputVol();
	virtual ~M_NTS_SetNineGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//获取第九级功放的输出电压
class M_NTS_GetNineGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetNineGAOutputVol();
	virtual ~M_NTS_GetNineGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};


//获取通道的电流值(单位:bit)
class M_NTS_GetCurrent:public BaseMethod
{
public:
	M_NTS_GetCurrent();
	virtual ~M_NTS_GetCurrent();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara;
};
//设置通道的上下限电流值(单位:bit)
class M_NTS_SetCurrentLimited:public BaseMethod
{
public:
	M_NTS_SetCurrentLimited();
	virtual ~M_NTS_SetCurrentLimited();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2, m_InputPara3;
};
//获取通道的上下限电流值(单位:bit)
class M_NTS_GetCurrentLimited:public BaseMethod
{
public:
	M_NTS_GetCurrentLimited();
	virtual ~M_NTS_GetCurrentLimited();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1, m_OutputPara2;
};
//获取告警信息
class M_NTS_GetIsWarning:public BaseMethod
{
public:
	M_NTS_GetIsWarning();
	virtual ~M_NTS_GetIsWarning();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara;
};
//清除告警信息
class M_NTS_ClearWarning:public BaseMethod
{
public:
	M_NTS_ClearWarning();
	virtual ~M_NTS_ClearWarning();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

//获取产品生产信息
class M_NTS_GetIDN:public BaseMethod
{
public:
	M_NTS_GetIDN();
	virtual ~M_NTS_GetIDN();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
	TParamSetStruct m_OutputPara2;
};

//class M_NTS_SendCmd 发送指令
class M_NTS_SendCmd:public BaseMethod
{
public:
	M_NTS_SendCmd();
	virtual ~M_NTS_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_NTS_GetCmd 发送指令并获取指令的返回数据
class M_NTS_GetCmd:public BaseMethod
{
public:
	M_NTS_GetCmd();
	virtual ~M_NTS_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
};

// M_NTS_SetStartAndStopRAM 设置模块RAM起止地址的数据
class M_NTS_SetStartAndStopRAM:public BaseMethod
{
public:
	M_NTS_SetStartAndStopRAM();
	virtual ~M_NTS_SetStartAndStopRAM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[4];		
};


// M_NTS_SetStarAndStopFlash 设置模块FLASH起止地址的数据
class M_NTS_SetStarAndStopFlash:public BaseMethod
{
public:
	M_NTS_SetStarAndStopFlash();
	virtual ~M_NTS_SetStarAndStopFlash();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[4];		
};


//M_NTS_GetStarAndStopFlash 获取模块FLAST起止地址的数据
class M_NTS_GetStarAndStopFlash:public BaseMethod
{
public:
	M_NTS_GetStarAndStopFlash();
	virtual ~M_NTS_GetStarAndStopFlash();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[3];
	TParamSetStruct m_OutputPara1;
};

// M_NTS_SetStarAndStopEEPROM 设置起止地址的RRPROM数据
class M_NTS_SetStarAndStopEEPROM:public BaseMethod
{
public:
	M_NTS_SetStarAndStopEEPROM();
	virtual ~M_NTS_SetStarAndStopEEPROM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[3];		
};

//M_NTS_GetStarAndStopEEPROM 获取起止地址的RRPROM数据
class M_NTS_GetStarAndStopEEPROM:public BaseMethod
{
public:
	M_NTS_GetStarAndStopEEPROM();
	virtual ~M_NTS_GetStarAndStopEEPROM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[2];
	TParamSetStruct m_OutputPara1;
};

// class M_NTS_SetCRC 写EEPROM离线参数的校验码
class M_NTS_SetCRC:public BaseMethod
{
public:
	M_NTS_SetCRC();
	virtual ~M_NTS_SetCRC();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
};

// M_NTS_SetPID 设置电流调试参数
class M_NTS_SetPID:public BaseMethod
{
public:
	M_NTS_SetPID();
	virtual ~M_NTS_SetPID();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[4];
};

// M_NTS_SetGainWorkPara 设置功放的静态工作参数
class M_NTS_SetGainWorkPara:public BaseMethod
{
public:
	M_NTS_SetGainWorkPara();
	virtual ~M_NTS_SetGainWorkPara();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[6];
};

// M_NTS_GainDebug 在电流表下调试单级功放的静态工作电流
class M_NTS_GainDebug:public BaseMethod
{
public:
	M_NTS_GainDebug();
	virtual ~M_NTS_GainDebug();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[5];
	TParamSetStruct m_OutputPara[2];
};

// M_NTS_GetVoltage 获取通道的电压(单位:bit)
class M_NTS_GetVoltage:public BaseMethod
{
public:
	M_NTS_GetVoltage();
	virtual ~M_NTS_GetVoltage();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1;
};

// M_NTS_SetActiveObject 设置当前需要监控的对象(Type 1:电流 2:电压 Index 1:推动级/28V 2:末级/5V 3:Peak 4:peak2)
class M_NTS_SetActiveObject:public BaseMethod
{
public:
	M_NTS_SetActiveObject();
	virtual ~M_NTS_SetActiveObject();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;
};
