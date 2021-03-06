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
* 版本：2.1.0.9
* 作者：dolby.jiang
* 完成日期：2010年3月29日
* 更改：增加 PSA_LoadFile 
*
************************************************************************/

/************************************************************************
* 版本：3.0.0.3
* 作者：dolby.jiang
* 完成日期：2010年5月6日
* 更改：增加 M_PSA_SetSweepPoint 设置扫描点数
*
************************************************************************/

/************************************************************************/
/*  频谱分析仪驱动程序方法类                                            */
/************************************************************************/
//M_PSA_SetPreset 频谱仪复位
class M_PSA_SetPreset:public BaseMethod
{
public:
	M_PSA_SetPreset();
	virtual ~M_PSA_SetPreset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
		
};

//M_PSA_SetCenterFrq 设置频谱仪中心频率
class M_PSA_SetCenterFrq:public BaseMethod
{
public:
	M_PSA_SetCenterFrq();
	virtual ~M_PSA_SetCenterFrq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
	
};
//M_PSA_SetCenterFrqandSpan 设置频谱仪中心频率和span
class M_PSA_SetCenterFrqandSpan:public BaseMethod
{
public:
	M_PSA_SetCenterFrqandSpan();
	virtual ~M_PSA_SetCenterFrqandSpan();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_InputDeviceName;
	
};

//M_PSA_SetRefLevel 设置频谱仪参考电平
class M_PSA_SetRefLevel:public BaseMethod
{
public:
	M_PSA_SetRefLevel();
	virtual ~M_PSA_SetRefLevel();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
	
};

//M_PSA_SetRFAttenuation 设置频谱仪内部衰减值
class M_PSA_SetRFAttenuation:public BaseMethod
{
public:
	M_PSA_SetRFAttenuation();
	virtual ~M_PSA_SetRFAttenuation();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
	
};

//M_PSA_SetRFAttenAuto 设置频谱仪自动内部衰减值
class M_PSA_SetRFAttenAuto:public BaseMethod
{
public:
	M_PSA_SetRFAttenAuto();
	virtual ~M_PSA_SetRFAttenAuto();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	
};
//M_PSA_SetRefLevelOff 设置频谱仪内部衰减偏移量
class M_PSA_SetRefLevelOff:public BaseMethod
{
public:
	M_PSA_SetRefLevelOff();
	virtual ~M_PSA_SetRefLevelOff();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
	
};
//M_PSA_SetExtAtten 设置频谱仪外部衰减偏移量
class M_PSA_SetExtAtten:public BaseMethod
{
public:
	M_PSA_SetExtAtten();
	virtual ~M_PSA_SetExtAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetIntPreampOff 设置频谱仪预放状态
class M_PSA_SetIntPreampOff:public BaseMethod
{
public:
	M_PSA_SetIntPreampOff();
	virtual ~M_PSA_SetIntPreampOff();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetLevelRange 设置频谱仪Y轴显示电平范围
class M_PSA_SetLevelRange:public BaseMethod
{
public:
	M_PSA_SetLevelRange();
	virtual ~M_PSA_SetLevelRange();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetAverCount 设置频谱仪平均次数
class M_PSA_SetAverCount:public BaseMethod
{
public:
	M_PSA_SetAverCount();
	virtual ~M_PSA_SetAverCount();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetAverType 设置频谱仪平均类型
class M_PSA_SetAverType:public BaseMethod
{
public:
	M_PSA_SetAverType();
	virtual ~M_PSA_SetAverType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetAverState 设置频谱仪平均状态
class M_PSA_SetAverState:public BaseMethod
{
public:
	M_PSA_SetAverState();
	virtual ~M_PSA_SetAverState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetRBW 设置频谱仪RBW值
class M_PSA_SetRBW:public BaseMethod
{
public:
	M_PSA_SetRBW();
	virtual ~M_PSA_SetRBW();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetVBW 设置频谱仪VBW值
class M_PSA_SetVBW:public BaseMethod
{
public:
	M_PSA_SetVBW();
	virtual ~M_PSA_SetVBW();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetDetectorMode 设置频谱仪检波模式
class M_PSA_SetDetectorMode:public BaseMethod
{
public:
	M_PSA_SetDetectorMode();
	virtual ~M_PSA_SetDetectorMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetSweepTime 设置频谱仪扫描时间
class M_PSA_SetSweepTime:public BaseMethod
{
public:
	M_PSA_SetSweepTime();
	virtual ~M_PSA_SetSweepTime();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetAUTOSweepTime 设置频谱仪自动扫描状态
class M_PSA_SetAUTOSweepTime:public BaseMethod
{
public:
	M_PSA_SetAUTOSweepTime();
	virtual ~M_PSA_SetAUTOSweepTime();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetSweepTimeMode 设置频谱仪扫描模式
class M_PSA_SetSweepTimeMode:public BaseMethod
{
public:
	M_PSA_SetSweepTimeMode();
	virtual ~M_PSA_SetSweepTimeMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetTraceMaxHold 设置频谱仪为MAX HOLD模式
class M_PSA_SetTraceMaxHold:public BaseMethod
{
public:
	M_PSA_SetTraceMaxHold();
	virtual ~M_PSA_SetTraceMaxHold();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetTraceMinHold 设置频谱仪为MIN HOLD模式
class M_PSA_SetTraceMinHold:public BaseMethod
{
public:
	M_PSA_SetTraceMinHold();
	virtual ~M_PSA_SetTraceMinHold();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_SetTraceClearWrite 设置频谱仪为Cleat write模式
class M_PSA_SetTraceClearWrite:public BaseMethod
{
public:
	M_PSA_SetTraceClearWrite();
	virtual ~M_PSA_SetTraceClearWrite();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_Gettracedata 读会整条曲线数据
class M_PSA_GetTraceData:public BaseMethod
{
public:
	M_PSA_GetTraceData();
	virtual ~M_PSA_GetTraceData();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};

//M_PSA_SetTrigSource 设置频谱仪触发源
class M_PSA_SetTrigSource:public BaseMethod
{
public:
	M_PSA_SetTrigSource();
	virtual ~M_PSA_SetTrigSource();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMarkMax 设置频谱仪最大MARKER点
class M_PSA_SetMarkMax:public BaseMethod
{
public:
	M_PSA_SetMarkMax();
	virtual ~M_PSA_SetMarkMax();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMarkMin 设置频谱仪最小MARKER点
class M_PSA_SetMarkMin:public BaseMethod
{
public:
	M_PSA_SetMarkMin();
	virtual ~M_PSA_SetMarkMin();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMaxNext 设置频谱仪下一最大MARKER点
class M_PSA_SetMaxNext:public BaseMethod
{
public:
	M_PSA_SetMaxNext();
	virtual ~M_PSA_SetMaxNext();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMarkState 设置频谱仪MARKER点的状态
class M_PSA_SetMarkState:public BaseMethod
{
public:
	M_PSA_SetMarkState();
	virtual ~M_PSA_SetMarkState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMarkPosition 设置频谱仪MARKER点的频率
class M_PSA_SetMarkPosition:public BaseMethod
{
public:
	M_PSA_SetMarkPosition();
	virtual ~M_PSA_SetMarkPosition();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_InputPara2;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMarkerMode 设置频谱仪MARKER点的模式
class M_PSA_SetMarkerMode:public BaseMethod
{
public:
	M_PSA_SetMarkerMode();
	virtual ~M_PSA_SetMarkerMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_InputPara2;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_GetMarkValue 获取频谱仪MARKER点的值
class M_PSA_GetMarkValue:public BaseMethod 
{
public:
	M_PSA_GetMarkValue();
	virtual ~M_PSA_GetMarkValue();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
	TParamSetStruct m_InputDeviceName;
};
/*
//M_PSA_SetTDPWRMODE 设置频谱仪为TD功率模式
class M_PSA_SetTDPWRMODE:public BaseMethod
{
public:
	M_PSA_SetTDPWRMODE();
	virtual ~M_PSA_SetTDPWRMODE();
	virtual int Init(void);
	virtual int Run(void);
};
*/
//M_PSA_SetTDPOWSLOT 设置频谱仪TD功率模式下的测试时隙
class M_PSA_SetTDPOWSLOT:public BaseMethod
{
public:
	M_PSA_SetTDPOWSLOT();
	virtual ~M_PSA_SetTDPOWSLOT();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
/*
//M_PSA_SetTDMODMODE 设置频谱仪为TD解调模式
class M_PSA_SetTDMODMODE:public BaseMethod
{
public:
	M_PSA_SetTDMODMODE();
	virtual ~M_PSA_SetTDMODMODE();
	virtual int Init(void);
	virtual int Run(void);
};
*/
//M_PSA_GetEVMandPCDE 获取频谱仪TD解调模式下的时隙功率值
class M_PSA_GetEVMandPCDE:public BaseMethod
{
public:
	M_PSA_GetEVMandPCDE();
	virtual ~M_PSA_GetEVMandPCDE();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara1;
	TParamSetStruct m_OutputPara2;
	TParamSetStruct m_InputDeviceName;
};

//M_PSA_SetSPECMODE 设置频谱仪为频谱模式
class M_PSA_SetSPECMODE:public BaseMethod 
{
public:
	M_PSA_SetSPECMODE();
	virtual ~M_PSA_SetSPECMODE();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetStarandStopFreq 设置频谱仪起止频率
class M_PSA_SetStarandStopFreq:public BaseMethod
{
public:
	M_PSA_SetStarandStopFreq();
	virtual ~M_PSA_SetStarandStopFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMULACPRMeas 设置频谱仪为多载波测试模式
class M_PSA_SetMULACPRMeas:public BaseMethod
{
public:
	M_PSA_SetMULACPRMeas();
	virtual ~M_PSA_SetMULACPRMeas();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;

};
//M_PSA_SetMCCOUNT 设置频谱仪载波数
class M_PSA_SetMCCOUNT:public BaseMethod
{
public:
	M_PSA_SetMCCOUNT();
	virtual ~M_PSA_SetMCCOUNT();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_GetMULACPR 获取频谱仪在多载波模式下的所有测量值
class M_PSA_GetMULACPR:public BaseMethod
{
public:
	M_PSA_GetMULACPR();
	virtual ~M_PSA_GetMULACPR();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara[5];
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMCPAVER 设置频谱仪在多载波模式下的平均次数
class M_PSA_SetMCPAVER:public BaseMethod
{
public:
	M_PSA_SetMCPAVER();
	virtual ~M_PSA_SetMCPAVER();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetSEMMeas 设置频谱仪为频谱发射模板测试模式
class M_PSA_SetSEMMeas:public BaseMethod
{
public:
	M_PSA_SetSEMMeas();
	virtual ~M_PSA_SetSEMMeas();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetInitSEM 初始化频频仪频谱发射模板测试
class M_PSA_SetInitSEM:public BaseMethod
{
public:
	M_PSA_SetInitSEM();
	virtual ~M_PSA_SetInitSEM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetSEMAverageEnable 设置频谱仪频谱发射模板模式下平均状态
class M_PSA_SetSEMAverageEnable:public BaseMethod
{
public:
	M_PSA_SetSEMAverageEnable();
	virtual ~M_PSA_SetSEMAverageEnable();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetSEMLimits 设置频谱仪频谱发射模板类型
class M_PSA_SetSEMLimits:public BaseMethod
{
public:
	M_PSA_SetSEMLimits();
	virtual ~M_PSA_SetSEMLimits();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_GetSEM 获得频谱仪频谱发射模板测量模式下的测量值
class M_PSA_GetSEM:public BaseMethod
{
public:
	M_PSA_GetSEM();
	virtual ~M_PSA_GetSEM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetEVMMeas 设置频谱仪为EVM和PCDE测量模式
class M_PSA_SetEVMMeas:public BaseMethod
{
public:
	M_PSA_SetEVMMeas();
	virtual ~M_PSA_SetEVMMeas();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;

};
//M_PSA_SetEVMSlot 设置频谱仪EVM和PCDE模式下的时隙值
class M_PSA_SetEVMSlot:public BaseMethod
{
public:
	M_PSA_SetEVMSlot();
	virtual ~M_PSA_SetEVMSlot();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetInitEVM 初始化频谱仪EVM和PCDE测量模式
class M_PSA_SetInitEVM:public BaseMethod
{
public:
	M_PSA_SetInitEVM();
	virtual ~M_PSA_SetInitEVM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;

};
/*
//M_PSA_GetEVM 获取频谱仪EVM和PCDE模式下的EVM值
class M_PSA_GetEVM:public BaseMethod
{
public:
	M_PSA_GetEVM();
	virtual ~M_PSA_GetEVM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara;
};
//M_PSA_GetPCDE 获取频谱仪EVM和PCDE模式下的PCDE值
class M_PSA_GetPCDE:public BaseMethod
{
public:
	M_PSA_GetPCDE();
	virtual ~M_PSA_GetPCDE();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara;
};
*/

//M_PSA_SetSyncType 设置频谱仪EVM和PCDE模式下的同步类型
class M_PSA_SetSyncType:public BaseMethod
{
public:
	M_PSA_SetSyncType();
	virtual ~M_PSA_SetSyncType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetTOI 设置频谱仪为三阶交调测试模式
class M_PSA_SetTOI:public BaseMethod
{
public:
	M_PSA_SetTOI();
	virtual ~M_PSA_SetTOI();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_GetTOI 获得频谱仪三阶交调模式下的测量值
class M_PSA_GetTOI:public BaseMethod
{
public:
	M_PSA_GetTOI();
	virtual ~M_PSA_GetTOI();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara[4];
	TParamSetStruct m_InputDeviceName;
};
/*
//M_PSA_SetTOIAVGState 设置频谱仪三阶交调模式下的平均状态
class M_PSA_SetTOIAVGState:public BaseMethod
{
public:
	M_PSA_SetTOIAVGState();
	virtual ~M_PSA_SetTOIAVGState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
};
*/

//M_PSA_SetPVTMeas 设置频谱仪为时间开关模板测试模式
class M_PSA_SetPVTMeas:public BaseMethod
{
public:
	M_PSA_SetPVTMeas();
	virtual ~M_PSA_SetPVTMeas();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetInitPVT 触发一次时间开关模板测试
class M_PSA_SetInitPVT:public BaseMethod
{
public:
	M_PSA_SetInitPVT();
	virtual ~M_PSA_SetInitPVT();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	
};
//M_PSA_GetPVT 获取频谱仪时间开关模板模式的功率值
class M_PSA_GetPVT:public BaseMethod
{
public:
	M_PSA_GetPVT();
	virtual ~M_PSA_GetPVT();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetPVTAverageEnable 设置频谱仪时间开关模板模式下平均的状态
class M_PSA_SetPVTAverageEnable:public BaseMethod
{
public:
	M_PSA_SetPVTAverageEnable();
	virtual ~M_PSA_SetPVTAverageEnable();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetPVTMEASTimes 设置频谱仪时间开关模板模式下的测量次数
class M_PSA_SetPVTMEASTimes:public BaseMethod
{
public:
	M_PSA_SetPVTMEASTimes();
	virtual ~M_PSA_SetPVTMEASTimes();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetACPMeas 设置频谱仪为单载波测量模式、
class M_PSA_SetACPMeas:public BaseMethod
{
public:
	M_PSA_SetACPMeas();
	virtual ~M_PSA_SetACPMeas();
	virtual int Init(void);
	virtual int Run(void);
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_GetACP 获取频谱仪单载波模式下个的测量功率值
class M_PSA_GetACP:public BaseMethod
{
public:
	M_PSA_GetACP();
	virtual ~M_PSA_GetACP();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara[5];
	
};
/*
//M_PSA_SetWindow 设置频谱仪的显示窗口
class M_PSA_SetWindow:public BaseMethod
{
public:
	M_PSA_SetWindow();
	virtual ~M_PSA_SetWindow();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
};
*/

//M_PSA_SetTrigDelayTime 设置频谱仪触发延迟时间
class M_PSA_SetTrigDelayTime:public BaseMethod
{
public:
	M_PSA_SetTrigDelayTime();
	virtual ~M_PSA_SetTrigDelayTime();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_M_PSA_SetTraceAverage 设置踪迹为平均估值方式
class M_PSA_SetTraceAverage:public BaseMethod
{
public:
	M_PSA_SetTraceAverage();
	virtual ~M_PSA_SetTraceAverage();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetEVMAver	设置EVM和PCDE模式下的平均状态和平均次数
class M_PSA_SetEVMAver:public BaseMethod
{
public:
	M_PSA_SetEVMAver();
	virtual ~M_PSA_SetEVMAver();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetFilterType	设置频谱耦合方式
class M_PSA_SetFilterType:public BaseMethod
{
public:
	M_PSA_SetFilterType();
	virtual ~M_PSA_SetFilterType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetScrambleCode 设置EVM和PCDE模式下的扰码
class M_PSA_SetScrambleCode:public BaseMethod
{
public:
	M_PSA_SetScrambleCode();
	virtual ~M_PSA_SetScrambleCode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

//M_PSA_GetFluctuate 获取指定带宽范围内的波动
class M_PSA_GetFluctuate:public BaseMethod
{
public:
	M_PSA_GetFluctuate();
	virtual ~M_PSA_GetFluctuate();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
	TParamSetStruct m_InputDeviceName;
};

//M_PSA_SetMarkTime 设置频谱仪在时域下MARKER点的位置
class M_PSA_SetMarkTime:public BaseMethod
{
public:
	M_PSA_SetMarkTime();
	virtual ~M_PSA_SetMarkTime();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_InputPara2;	
	TParamSetStruct m_InputDeviceName;
};
//class M_PSA_SetSweepEgatePolarity 设置外部门信号极性
class M_PSA_SetSweepEgatePolarity:public BaseMethod
{
public:
	M_PSA_SetSweepEgatePolarity();
	virtual ~M_PSA_SetSweepEgatePolarity();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_InputDeviceName;
};
//class M_PSA_SetSweepEgateLength 设置门扫描有效时间 (单位:ms)
class M_PSA_SetSweepEgateLength:public BaseMethod
{
public:
	M_PSA_SetSweepEgateLength();
	virtual ~M_PSA_SetSweepEgateLength();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_InputDeviceName;
};

//class M_PSA_SetTrigLevel 设置外部触发电平(-5V ~ 5V)
class M_PSA_SetTrigLevel:public BaseMethod
{
public:
	M_PSA_SetTrigLevel();
	virtual ~M_PSA_SetTrigLevel();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;		
};
//M_PSA_SetStartAndStopSlot 设置ACP模式下起止时隙
class M_PSA_SetStartAndStopSlot:public BaseMethod
{
public:
	M_PSA_SetStartAndStopSlot();
	virtual ~M_PSA_SetStartAndStopSlot();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;		
};
//设置频谱仪的测试模式(0:SA 1:TDSCDMA_ACP 2:TDSCDMA_MCP 3:TDSCDMA_SEM 4:TDSCDMA_EVM 5:SA_Harmonic 6:SA_CCDF 7:SA_ACP|MCP 8:SA_Channel Power 9:SA_Burst Power)
class M_PSA_SetMeasMode:public BaseMethod
{
public:
	M_PSA_SetMeasMode();
	virtual ~M_PSA_SetMeasMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;		
};
//获取SA_CCDF模式下的测量值
class M_PSA_GetPST:public BaseMethod
{
public:
	M_PSA_GetPST();
	virtual ~M_PSA_GetPST();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara[10];		
};

//获取SA_Harmonic模式下的测量值(dBm)(HarmonicNum:(0~10)  0:所有谐波值)
class M_PSA_GetHarmonic:public BaseMethod
{
public:
	M_PSA_GetHarmonic();
	virtual ~M_PSA_GetHarmonic();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara[10];		
};

/*
//设置Offset\Limit类型(0:SA 1:WCDMA 2:C2K 3:WIMAX OFDMA 4:TD-SCDMA 5:1xEVDO)
class M_PSA_SetOffsetLimitType:public BaseMethod
{
public:
	M_PSA_SetOffsetLimitType();
	virtual ~M_PSA_SetOffsetLimitType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};
*/

//设置载波间隔
class M_PSA_SetCarrierSpaceList:public BaseMethod
{
public:
	M_PSA_SetCarrierSpaceList();
	virtual ~M_PSA_SetCarrierSpaceList();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

//设置Offset Freqence列表(MHz)
class M_PSA_SetOffsetFreqList:public BaseMethod
{
public:
	M_PSA_SetOffsetFreqList();
	virtual ~M_PSA_SetOffsetFreqList();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

//设置Offset Freqence列表状态(0:Off 1:On)
class M_PSA_SetOffsetFreqState:public BaseMethod
{
public:
	M_PSA_SetOffsetFreqState();
	virtual ~M_PSA_SetOffsetFreqState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

//设置Offset Integ BW列表(KHz)
class M_PSA_SetOffsetIBWList:public BaseMethod
{
public:
	M_PSA_SetOffsetIBWList();
	virtual ~M_PSA_SetOffsetIBWList();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;

};

//设置Gate View状态(0:Off 1:On)
class M_PSA_SetGateViewState:public BaseMethod
{
public:
	M_PSA_SetGateViewState();
	virtual ~M_PSA_SetGateViewState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//设置扫描Gate Delay(ms)
class M_PSA_SetSweepEgatDelay:public BaseMethod
{
public:
	M_PSA_SetSweepEgatDelay();
	virtual ~M_PSA_SetSweepEgatDelay();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//设置噪声修正状态(0: Off 1:On)
class M_PSA_SetNoiseCorrState:public BaseMethod
{
public:
	M_PSA_SetNoiseCorrState();
	virtual ~M_PSA_SetNoiseCorrState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_PSA_SetMeasNoiseBW 设置Measurement Noise Bandwidth(MHz)
class M_PSA_SetMeasNoiseBW:public BaseMethod
{
public:
	M_PSA_SetMeasNoiseBW();
	virtual ~M_PSA_SetMeasNoiseBW();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_PSA_SetRefCarrier 设置参考载波
class M_PSA_SetRefCarrier:public BaseMethod
{
public:
	M_PSA_SetRefCarrier();
	virtual ~M_PSA_SetRefCarrier();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_PSA_SetRefCarrierFreq 设置参考载波频率(MHz)
class M_PSA_SetRefCarrierFreq:public BaseMethod
{
public:
	M_PSA_SetRefCarrierFreq();
	virtual ~M_PSA_SetRefCarrierFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_PSA_SendCmd 发送指令
class M_PSA_SendCmd:public BaseMethod
{
public:
	M_PSA_SendCmd();
	virtual ~M_PSA_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_PSA_GetCmd 发送指令并获取指令的返回数据
class M_PSA_GetCmd:public BaseMethod
{
public:
	M_PSA_GetCmd();
	virtual ~M_PSA_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
};


//class M_PSA_GetIDN 获取设备型号信息
class M_PSA_GetIDN:public BaseMethod
{
public:
	M_PSA_GetIDN();
	virtual ~M_PSA_GetIDN();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

//M_PSA_LoadFile 加载状态文件
class M_PSA_LoadFile:public BaseMethod
{
public:
	M_PSA_LoadFile();
	virtual ~M_PSA_LoadFile();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_PSA_SaveFile 保存文件
class M_PSA_SaveFile:public BaseMethod
{
public:
	M_PSA_SaveFile();
	virtual ~M_PSA_SaveFile();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;
};

//M_PSA_GetSEMPower 获取SEM模式下的功率值
class M_PSA_GetSEMPower:public BaseMethod
{
public:
	M_PSA_GetSEMPower();
	virtual ~M_PSA_GetSEMPower();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

//M_PSA_GetEVMPower 获取EVM模式下的功率值
class M_PSA_GetEVMPower:public BaseMethod
{
public:
	M_PSA_GetEVMPower();
	virtual ~M_PSA_GetEVMPower();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

//M_PSA_SetSweepPoint 设置扫描点数
class M_PSA_SetSweepPoint:public BaseMethod
{
public:
	M_PSA_SetSweepPoint();
	virtual ~M_PSA_SetSweepPoint();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};


// 以命名方式将测试曲线数据保存到PC内存中
class M_PSA_SaveTraceByName:public BaseMethod
{
public:
	M_PSA_SaveTraceByName();
	virtual ~M_PSA_SaveTraceByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;		
};

// 以命名方式处理PC内存数据(0:Off 1:Trace1/Trace2 2:Trace1*Trace2 3:Trace1-Trace2 4:Trace1+Trace2)
class M_PSA_SetTraceMathTypeByName:public BaseMethod
{
public:
	M_PSA_SetTraceMathTypeByName();
	virtual ~M_PSA_SetTraceMathTypeByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3, m_InputPara4;		
};

// 删除一条PC内存曲线
class M_PSA_DeleteTraceByName:public BaseMethod
{
public:
	M_PSA_DeleteTraceByName();
	virtual ~M_PSA_DeleteTraceByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	
};

// 删除所有PC内存曲线
class M_PSA_DeleteAllTrace:public BaseMethod
{
public:
	M_PSA_DeleteAllTrace();
	virtual ~M_PSA_DeleteAllTrace();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;	
};

// 在PC内存数据中设置MARKER 的查找范围(MHz) 
class M_PSA_SetMarkerSearchFreqByName:public BaseMethod
{
public:
	M_PSA_SetMarkerSearchFreqByName();
	virtual ~M_PSA_SetMarkerSearchFreqByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;		
};

// 从PC内存数据中获取最大值和最小值
class M_PSA_GetMarkerValueByName:public BaseMethod
{
public:
	M_PSA_GetMarkerValueByName();
	virtual ~M_PSA_GetMarkerValueByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1, m_OutputPara2;	
};

// 从PC内存数据中获取指定带宽范围内的平坦度(MHz) 
class M_PSA_GetFluctuateByName:public BaseMethod
{
public:
	M_PSA_GetFluctuateByName();
	virtual ~M_PSA_GetFluctuateByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;	
	TParamSetStruct m_OutputPara1;
	
};

// 从PC内存数据获取指定频率点Marker值
class M_PSA_GetMarkerFreqByName:public BaseMethod
{
public:
	M_PSA_GetMarkerFreqByName();
	virtual ~M_PSA_GetMarkerFreqByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;	
	TParamSetStruct m_OutputPara1;	
};

// class M_PSA_GetTraceDataXByName 从PC内存数据获取X轴数据
class M_PSA_GetTraceDataXByName:public BaseMethod
{
public:
	M_PSA_GetTraceDataXByName();
	virtual ~M_PSA_GetTraceDataXByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;	
};

// class M_PSA_GetTraceDataYByName 从PC内存数据获取Y轴数据
class M_PSA_GetTraceDataYByName:public BaseMethod
{
public:
	M_PSA_GetTraceDataYByName();
	virtual ~M_PSA_GetTraceDataYByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;	
};

//获取扫描时间值
class M_PSA_GetSweepTime:public BaseMethod
{
public:
	M_PSA_GetSweepTime();
	virtual ~M_PSA_GetSweepTime();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

//获取触发延迟时间
class M_PSA_GetTrigDelayTime:public BaseMethod
{
public:
	M_PSA_GetTrigDelayTime();
	virtual ~M_PSA_GetTrigDelayTime();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};

// 设置触发极性(0:Positive 1:Negative)
class M_PSA_SetTrigPolarity:public BaseMethod
{
public:
	M_PSA_SetTrigPolarity();
	virtual ~M_PSA_SetTrigPolarity();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

// 读取设备的测试数据
class M_PSA_ReadDev:public BaseMethod
{
public:
	M_PSA_ReadDev();
	virtual ~M_PSA_ReadDev();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1;	
};

// 触发一次测量
class M_PSA_SetTrigOnce:public BaseMethod
{
public:
	M_PSA_SetTrigOnce();
	virtual ~M_PSA_SetTrigOnce();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
};

// 重新测量一次
class M_PSA_Restart:public BaseMethod
{
public:
	M_PSA_Restart();
	virtual ~M_PSA_Restart();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
};

//设置Offset Abs
class M_PSA_SetOffsetAbsList:public BaseMethod
{
public:
	M_PSA_SetOffsetAbsList();
	virtual ~M_PSA_SetOffsetAbsList();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};
 

//设置Egat State
class M_PSA_SetEgatState:public BaseMethod
{
public:
	M_PSA_SetEgatState();
	virtual ~M_PSA_SetEgatState();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

 
// 获取OBW值
class M_PSA_GetOBW:public BaseMethod
{
public:
	M_PSA_GetOBW();
	virtual ~M_PSA_GetOBW();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara;
	TParamSetStruct m_InputDeviceName;
};
  

// 设置Span
class M_PSA_SetSpan:public BaseMethod
{
public:
	M_PSA_SetSpan();
	virtual ~M_PSA_SetSpan();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
  
// 设置自动电平
class M_PSA_RefLevelAuto:public BaseMethod
{
public:
	M_PSA_RefLevelAuto();
	virtual ~M_PSA_RefLevelAuto();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

// 设置ACLR模式
class M_PSA_SetACLRMEAS:public BaseMethod
{
public:
	M_PSA_SetACLRMEAS();
	virtual ~M_PSA_SetACLRMEAS();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

// 设置ACLR模式TX带宽
class M_PSA_SetACPTXBW:public BaseMethod
{
public:
	M_PSA_SetACPTXBW();
	virtual ~M_PSA_SetACPTXBW();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara,m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};

// 设置ACLR模式TXCount
class M_PSA_SetACPTXCount:public BaseMethod
{
public:
	M_PSA_SetACPTXCount();
	virtual ~M_PSA_SetACPTXCount();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

// 设置TrigSource
class M_PSA_SetTriggerSource:public BaseMethod
{
public:
	M_PSA_SetTriggerSource();
	virtual ~M_PSA_SetTriggerSource();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

// 设置TrigLevel
class M_PSA_SetTriggerLevel:public BaseMethod
{
public:
	M_PSA_SetTriggerLevel();
	virtual ~M_PSA_SetTriggerLevel();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara, m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};

// 设置GateTrigSwitch
class M_PSA_SetGateTrigSwitch:public BaseMethod
{
public:
	M_PSA_SetGateTrigSwitch();
	virtual ~M_PSA_SetGateTrigSwitch();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

//设置GateDelay
class M_PSA_SetGateDelay:public BaseMethod
{
public:
	M_PSA_SetGateDelay();
	virtual ~M_PSA_SetGateDelay();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

//设置GateLength
class M_PSA_SetGateLength:public BaseMethod
{
public:
	M_PSA_SetGateLength();
	virtual ~M_PSA_SetGateLength();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

//获取ACLR值
class M_PSA_GetACLR:public BaseMethod
{
public:
	M_PSA_GetACLR();
	virtual ~M_PSA_GetACLR();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

//设置频谱仪为VSA模式
class M_PSA_SetVSAMODE:public BaseMethod 
{
public:
	M_PSA_SetVSAMODE();
	virtual ~M_PSA_SetVSAMODE();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//设置频谱仪为PULSE模式
class M_PSA_SetPULSEMODE:public BaseMethod 
{
public:
	M_PSA_SetPULSEMODE();
	virtual ~M_PSA_SetPULSEMODE();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//设置OBWPowerBandWidth
class M_PSA_SetOBWPOWERBW:public BaseMethod
{
public:
	M_PSA_SetOBWPOWERBW();
	virtual ~M_PSA_SetOBWPOWERBW();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

//获得VSA模式下的EVM值
class M_PSA_GetEVMValue:public BaseMethod
{
public:
	M_PSA_GetEVMValue();
	virtual ~M_PSA_GetEVMValue();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara1,m_OutputPara2,m_OutputPara3,m_OutputPara4,m_OutputPara5,m_OutputPara6;
	TParamSetStruct m_InputDeviceName;
};


//获得PULSE模式下的值
class M_PSA_GetPULSEValue:public BaseMethod
{
public:
	M_PSA_GetPULSEValue();
	virtual ~M_PSA_GetPULSEValue();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara1,m_OutputPara2;
	TParamSetStruct m_InputDeviceName;
};

//设置SignCountFunction
class M_PSA_SetSignCountFunc:public BaseMethod 
{
public:
	M_PSA_SetSignCountFunc();
	virtual ~M_PSA_SetSignCountFunc();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//获取Mark点频率
class M_PSA_GetMarkFreq:public BaseMethod 
{
public:
	M_PSA_GetMarkFreq();
	virtual ~M_PSA_GetMarkFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1;
	TParamSetStruct m_InputDeviceName;
};

//设置TriggerOffSet
class M_PSA_SetTriggerOffSet:public BaseMethod 
{
public:
	M_PSA_SetTriggerOffSet();
	virtual ~M_PSA_SetTriggerOffSet();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

//设置Timing参数显示
class M_PSA_SetTimingPara:public BaseMethod 
{
public:
	M_PSA_SetTimingPara();
	virtual ~M_PSA_SetTimingPara();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara, m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};


//设置Transmit Filter
class M_PSA_SetTransFilter:public BaseMethod 
{
public:
	M_PSA_SetTransFilter();
	virtual ~M_PSA_SetTransFilter();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara, m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};

//设置ModulationSetting
class M_PSA_SetModulation:public BaseMethod 
{
public:
	M_PSA_SetModulation();
	virtual ~M_PSA_SetModulation();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara, m_InputPara2, m_InputPara3, m_InputPara4;
	TParamSetStruct m_InputDeviceName;
};

//设置CaptureLengthAuto
class M_PSA_SetCaptureLengthAuto:public BaseMethod 
{
public:
	M_PSA_SetCaptureLengthAuto();
	virtual ~M_PSA_SetCaptureLengthAuto();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};



//获取PulseNumber值
class M_PSA_GetPULSENumber:public BaseMethod 
{
public:
	M_PSA_GetPULSENumber();
	virtual ~M_PSA_GetPULSENumber();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara1;
	TParamSetStruct m_InputDeviceName;
};
