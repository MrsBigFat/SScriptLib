#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"

//#include ".\include\SGDriver.h"
//#pragma comment(lib,".\\lib\\SGDriver.lib")


//typedef std::vector<TParamSetStruct> TParamSetStructVector;

/************************************************************************
* 版本：2.0.0.45
* 作者：dolby.jiang
* 完成日期：2009年10月10日
* 更改：
*
************************************************************************/

/************************************************************************/
/*  信号源驱动程序方法类                                                                    */
/************************************************************************/

//class M_SG_Reset 信号源设备复位
class M_SG_Reset: public BaseMethod
{
public:
	M_SG_Reset();
	virtual ~M_SG_Reset();
	virtual int Run(void);
	virtual int Init(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//M_SG_SetWaveFile设置信号源波形文件
class M_SG_SetWaveFile: public BaseMethod
{
public:
	M_SG_SetWaveFile();
	virtual ~M_SG_SetWaveFile();
	virtual int Run(void);
	virtual int Init(void);	
protected:
	TParamSetStruct m_InputPara, m_InputDeviceName;
};
//M_SG_SetArbWaveState 设置波形文件状态
class M_SG_SetArbWaveState:public BaseMethod
{
public:
	M_SG_SetArbWaveState();
	virtual ~M_SG_SetArbWaveState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara, m_InputDeviceName;
};

//M_SG_SetRFFreq设置参考频率值
class M_SG_SetRFFreq:public BaseMethod
{
public:
	M_SG_SetRFFreq();
	virtual ~M_SG_SetRFFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetRFAmplitu设置信号源幅度值
class M_SG_SetRFAmplitu:public BaseMethod
{
public:
	M_SG_SetRFAmplitu();
	virtual ~M_SG_SetRFAmplitu();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_GetRFAmplitu读取信号源幅度值
class M_SG_GetRFAmplitu:public BaseMethod
{
public:
	M_SG_GetRFAmplitu();
	virtual ~M_SG_GetRFAmplitu();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_OutputPara;
};
//M_SG_SetRFAmplituOffset设置信号源幅度偏移值
class M_SG_SetRFAmplituOffset:public BaseMethod
{
public:
	M_SG_SetRFAmplituOffset();
	virtual ~M_SG_SetRFAmplituOffset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetIQModulationState设置信号源解调状态
class M_SG_SetIQModulationState:public BaseMethod
{
public:
	M_SG_SetIQModulationState();
	virtual ~M_SG_SetIQModulationState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetRFPowerOnState设置信号源输出状态
class M_SG_SetRFPowerOnState:public BaseMethod
{
public:
	M_SG_SetRFPowerOnState();
	virtual ~M_SG_SetRFPowerOnState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetSweepPoint设置信号源扫描点数
class M_SG_SetSweepPoint:public BaseMethod
{
public:
	M_SG_SetSweepPoint();
	virtual ~M_SG_SetSweepPoint();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
		
};
//M_SG_SetSweepTriMode设置信号源扫描触发方式
class M_SG_SetSweepTriMode:public BaseMethod
{
public:
	M_SG_SetSweepTriMode();
	virtual ~M_SG_SetSweepTriMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetStartandStopFreq设置信号源扫描起始频率和截止频率
class M_SG_SetStartandStopFreq:public BaseMethod
{
public:
	M_SG_SetStartandStopFreq();
	virtual ~M_SG_SetStartandStopFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara1,m_InputPara2;
};
//M_SG_SetSweepMode设置扫描模式
class M_SG_SetSweepMode:public BaseMethod
{
public:
	M_SG_SetSweepMode();
	virtual ~M_SG_SetSweepMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetARBMarkMode 设置信号源Mark模式
class M_SG_SetARBMarkMode:public BaseMethod
{
public:
	M_SG_SetARBMarkMode();
	virtual ~M_SG_SetARBMarkMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara1,m_InputPara2;
};
//M_SG_SetFreqOffset 设置信号源频率偏移量
class M_SG_SetFreqOffset:public BaseMethod
{
public:
	M_SG_SetFreqOffset();
	virtual ~M_SG_SetFreqOffset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetMarkDelay 设置信号源Mark延迟时间
class M_SG_SetARBMarkDelay:public BaseMethod
{
public:
	M_SG_SetARBMarkDelay();
	virtual ~M_SG_SetARBMarkDelay();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara1,m_InputPara2;
};
//M_SG_SetTrigInContinuousType 设置信号源连续触发类型 0:FREE 1:TRIGger 2:RESet
class M_SG_SetTrigInContinuousType:public BaseMethod
{
public:
	M_SG_SetTrigInContinuousType();
	virtual ~M_SG_SetTrigInContinuousType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetTrigInSourceType 设置信号源触发源类型 0:KEY 1:EXT 2:BUS
class M_SG_SetTrigInSourceType:public BaseMethod
{
public:
	M_SG_SetTrigInSourceType();
	virtual ~M_SG_SetTrigInSourceType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
// M_SG_SetTrigInPolarity 设置信号源触发极性 0:POSitive 1:NEGative
class M_SG_SetTrigInPolarity:public BaseMethod
{
public:
	M_SG_SetTrigInPolarity();
	virtual ~M_SG_SetTrigInPolarity();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
// M_SG_SetTrigInDelay 设置信号源触发延迟时间(单位:ms)
class M_SG_SetTrigInDelay:public BaseMethod
{
public:
	M_SG_SetTrigInDelay();
	virtual ~M_SG_SetTrigInDelay();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
// M_SG_SetMarkerALCHold 设置信号源Marker ALC Hold值 0:NONE 1:M1 2:M2 3:M3 4:M4
class M_SG_SetMarkerALCHold:public BaseMethod
{
public:
	M_SG_SetMarkerALCHold();
	virtual ~M_SG_SetMarkerALCHold();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetAmpALCMode 设置信号源电平 ALC状态 0:Off 1:On 
class M_SG_SetAmpALCMode:public BaseMethod
{
public:
	M_SG_SetAmpALCMode();
	virtual ~M_SG_SetAmpALCMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};

//M_SG_SetClockFreq 设置时钟频率(单位:MHz)
class M_SG_SetClockFreq:public BaseMethod
{
public:
	M_SG_SetClockFreq();
	virtual ~M_SG_SetClockFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};

//M_SG_SetRFPowerSearchMode 设置功率检测方式(0:Normal 1:Minimum)
class M_SG_SetRFPowerSearchMode:public BaseMethod
{
public:
	M_SG_SetRFPowerSearchMode();
	virtual ~M_SG_SetRFPowerSearchMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};

//class M_SG_SendCmd 发送指令
class M_SG_SendCmd:public BaseMethod
{
public:
	M_SG_SendCmd();
	virtual ~M_SG_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_SG_GetCmd 发送指令并获取指令的返回数据
class M_SG_GetCmd:public BaseMethod
{
public:
	M_SG_GetCmd();
	virtual ~M_SG_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
};


//class M_SG_GetIDN 获取设备型号信息
class M_SG_GetIDN:public BaseMethod
{
public:
	M_SG_GetIDN();
	virtual ~M_SG_GetIDN();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};
//class M_SG_SetCwCarrier 获取设备型号信息
class M_SG_SetCwCarrier :public BaseMethod
{
public:
	M_SG_SetCwCarrier();
	virtual ~M_SG_SetCwCarrier();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName, m_InputPara1, m_InputPara2;
};
