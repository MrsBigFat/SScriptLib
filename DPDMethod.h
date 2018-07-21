#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"
//
//#include ".\include\DPDDriver.h"
//#pragma comment(lib,".\\lib\\DPDDriver.lib")
//
//#include ".\include\PSADriver.h"
//#pragma comment(lib,".\\lib\\PSADriver.lib")
//
//#include ".\include\PRMDriver.h"
//#pragma comment(lib,".\\lib\\PRMDriver.lib")


/************************************************************************
* 版本：2.0.0.45
* 作者：dolby.jiang
* 完成日期：2009年10月10日
* 更改：
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.7
* 作者：dolby.jiang
* 完成日期：2010年6月22日
* 更改：修改 M_DPD_SetCarriedMode的功能描述语
*
************************************************************************/
/************************************************************************
* 版本：3.0.2.7
* 作者：dolby.jiang
* 完成日期：2011年4月3日
* 更改：
1 增加 M_DPD_SetSmallTxAtten 设置输出TX链路细调功率值
2 增加 M_DPD_GetSmallTxAtten 读取输出TX链路细调功率值
*
************************************************************************/

/************************************************************************/
/*  DPD板驱动程序方法类                                                 */
/************************************************************************/

//M_DPD_SetDPDState 设置DPD开关状态(0:关 1:开)
class M_DPD_SetDPDState:public BaseMethod
{
public:
	M_DPD_SetDPDState();
	virtual ~M_DPD_SetDPDState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_DPD_SetTxAtten 设置发射通道衰减值(0x3f表示不衰，0表示全衰，步进0.5dB)
class M_DPD_SetTxAtten:public BaseMethod
{
public:
	M_DPD_SetTxAtten();
	virtual ~M_DPD_SetTxAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_DPD_SetSmallTxAtten 设置输出TX链路细调功率值(步进0.1dB)
class M_DPD_SetSmallTxAtten:public BaseMethod
{
public:
	M_DPD_SetSmallTxAtten();
	virtual ~M_DPD_SetSmallTxAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_DPD_SetRDAtten 设置反馈通道衰减值(0x3f表示不衰，0表示全衰，步进0.5dB)
class M_DPD_SetRDAtten:public BaseMethod
{
public:
	M_DPD_SetRDAtten();
	virtual ~M_DPD_SetRDAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_DPD_GetErrPower 获取偏差功率
class M_DPD_GetErrPower:public BaseMethod
{
public:
	M_DPD_GetErrPower();
	virtual ~M_DPD_GetErrPower();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};

//M_DPD_SetSixPwrFpg 设置6载波功率因子
class M_DPD_SetSixPwrFpg:public BaseMethod
{
public:
	M_DPD_SetSixPwrFpg();
	virtual ~M_DPD_SetSixPwrFpg();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//M_DPD_SetNinePwrFpg 设置9载功率波因子
class M_DPD_SetNinePwrFpg:public BaseMethod
{
public:
	M_DPD_SetNinePwrFpg();
	virtual ~M_DPD_SetNinePwrFpg();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//M_DPD_SetTwelvePwrFpg 设置12载功率波因子
class M_DPD_SetTwelvePwrFpg:public BaseMethod
{
public:
	M_DPD_SetTwelvePwrFpg();
	virtual ~M_DPD_SetTwelvePwrFpg();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//M_DPD_SetErrPwrDebug DPD偏差功率调试
class M_DPD_SetErrPwrDebug:public BaseMethod
{
public:
	M_DPD_SetErrPwrDebug();
	virtual ~M_DPD_SetErrPwrDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DPDDeviceName, m_PSADeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//class M_DPD_ACPRPowerDebug ZX模块产品ACPR功率调试
class M_DPD_ACPRPowerDebug:public BaseMethod
{
public:
	M_DPD_ACPRPowerDebug();
	virtual ~M_DPD_ACPRPowerDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DPDDeviceName, m_PSADeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};

//class M_DPD_SetWorkFreq 设置DPD工作频率(1: 2017.5M 2: 1880M 3:875/930/1810  4:880/946.8/1830  5:885/955/1855
//6:1830 7:1850 8:1875 9:1910M)
class M_DPD_SetWorkFreq:public BaseMethod
{
public:
	M_DPD_SetWorkFreq();
	virtual ~M_DPD_SetWorkFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//class M_DPD_ACPRPowerDebugDT DT模块产品ACPR功率调试
class M_DPD_ACPRPowerDebugDT:public BaseMethod
{
public:
	M_DPD_ACPRPowerDebugDT();
	virtual ~M_DPD_ACPRPowerDebugDT();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DPDDeviceName, m_PSADeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//M_DPD_SetErrPwrDebug DT DPD偏差功率调试
class M_DPD_SetErrPwrDebugDT:public BaseMethod
{
public:
	M_DPD_SetErrPwrDebugDT();
	virtual ~M_DPD_SetErrPwrDebugDT();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DPDDeviceName, m_PSADeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};
//class M_DPD_SetSGMode 设置DPD信号模式(0:GMSK  1:8PSK 2:GMSK+8PSK)
class M_DPD_SetSGMode:public BaseMethod
{
public:
	M_DPD_SetSGMode();
	virtual ~M_DPD_SetSGMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};
//class M_DPD_SetCarriedMode 设置DPD载波模式	
/* Mode : 0:3M等间隔	1:3M不等间隔	2:5M等间隔	3:5M不等间隔  
		  4:10M等间隔	5:0M不等间隔	6:5M等间隔  7:15M不等间隔
*/	 
class M_DPD_SetCarriedMode:public BaseMethod
{
public:
	M_DPD_SetCarriedMode();
	virtual ~M_DPD_SetCarriedMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};
//class M_DPD_SetCarriedCount 设置载波个数(0:3载波	1:4载波	2:6载波)	 
class M_DPD_SetCarriedCount:public BaseMethod
{
public:
	M_DPD_SetCarriedCount();
	virtual ~M_DPD_SetCarriedCount();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};
//M_DPD_Reset 复位
class M_DPD_Reset:public BaseMethod
{
public:
	M_DPD_Reset();
	virtual ~M_DPD_Reset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//class M_DPD_PRMPowerDebug 在功率下调试输出
class M_DPD_PRMPowerDebug:public BaseMethod
{
public:
	M_DPD_PRMPowerDebug();
	virtual ~M_DPD_PRMPowerDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DPDDevName,m_PRMDevName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//M_DPD_GetIDN 获取生产信息
class M_DPD_GetIDN:public BaseMethod
{
public:
	M_DPD_GetIDN();
	virtual ~M_DPD_GetIDN();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};


//class M_DPD_SendCmd 发送指令
class M_DPD_SendCmd:public BaseMethod
{
public:
	M_DPD_SendCmd();
	virtual ~M_DPD_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};
//class M_DPD_GetCmd 发送指令并获取指令的返回数据
class M_DPD_GetCmd:public BaseMethod
{
public:
	M_DPD_GetCmd();
	virtual ~M_DPD_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
};

//class M_DPD_SetRFOutPower 设置DPD输出功率
class M_DPD_SetRFOutPower:public BaseMethod
{
public:
	M_DPD_SetRFOutPower();
	virtual ~M_DPD_SetRFOutPower();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_DPD_GetRFOutPower 获取DPD输出功率
class M_DPD_GetRFOutPower:public BaseMethod
{
public:
	M_DPD_GetRFOutPower();
	virtual ~M_DPD_GetRFOutPower();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};

//class M_DPD_SetCFR 设置CFR门限值
class M_DPD_SetCFR:public BaseMethod
{
public:
	M_DPD_SetCFR();
	virtual ~M_DPD_SetCFR();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_DPD_GetCFR 获取CFR门限值
class M_DPD_GetCFR:public BaseMethod
{
public:
	M_DPD_GetCFR();
	virtual ~M_DPD_GetCFR();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};

//class M_DPD_GetRDAtten 获取反馈通道衰减值
class M_DPD_GetRDAtten:public BaseMethod
{
public:
	M_DPD_GetRDAtten();
	virtual ~M_DPD_GetRDAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};

//class M_DPD_GetTxAtten 获取发射通道衰减值
class M_DPD_GetTxAtten:public BaseMethod
{
public:
	M_DPD_GetTxAtten();
	virtual ~M_DPD_GetTxAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};

//class M_DPD_GetSmallTxAtten 获取输出TX链路细调功率值
class M_DPD_GetSmallTxAtten:public BaseMethod
{
public:
	M_DPD_GetSmallTxAtten();
	virtual ~M_DPD_GetSmallTxAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};

// 读取设备返回数据
class M_DPD_ReadDev:public BaseMethod
{
public:
	M_DPD_ReadDev();
	virtual ~M_DPD_ReadDev();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};
	