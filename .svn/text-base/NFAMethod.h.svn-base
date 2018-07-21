#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"

//#include ".\include\NFADriver.h"
//#pragma comment(lib,".\\lib\\NFADriver.lib")



/************************************************************************
* 版本：2.0.0.45
* 作者：dolby.jiang
* 完成日期：2009年10月10日
* 更改：修改M_NFA_GetIDN::Init(void)方法中的设备变量类型
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.4
* 作者：dolby.jiang
* 完成日期：2010年5月12日
* 更改：
1 增加 M_NFA_GetTraceMax接口
2 增加 M_NFA_GetTraceMin接口
3 增加 M_NFA_GetTraceFreqValue接口
*
************************************************************************/

/************************************************************************/
/*  噪声分析仪驱动方法类                                                */
/************************************************************************/
//class M_NFA_Reset 噪声仪复位
class M_NFA_Reset:public BaseMethod
{
public:
	M_NFA_Reset();
	virtual ~M_NFA_Reset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//class M_NFA_SetFreqMode 设置噪声仪频率模式
class M_NFA_SetFreqMode:public BaseMethod
{
public:
	M_NFA_SetFreqMode();
	virtual ~M_NFA_SetFreqMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};
// class M_NFA_SetStartAndStopFreq 设置噪声仪起止频率
class M_NFA_SetStartAndStopFreq:public BaseMethod
{
public:
	M_NFA_SetStartAndStopFreq();
	virtual ~M_NFA_SetStartAndStopFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NFA_SetDispFormat 设置噪声仪数据显示方式
class M_NFA_SetDispFormat:public BaseMethod
{
public:
	M_NFA_SetDispFormat();
	virtual ~M_NFA_SetDispFormat();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};
//class M_NFA_GetFreqNfigure 获取指定频率点的噪声系数值
class M_NFA_GetFreqNfigure:public BaseMethod
{
public:
	M_NFA_GetFreqNfigure();
	virtual ~M_NFA_GetFreqNfigure();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
	
};
//class M_NFA_SetSweepMode 设置噪声仪扫描模式
class M_NFA_SetSweepMode:public BaseMethod
{
public:
	M_NFA_SetSweepMode();
	virtual ~M_NFA_SetSweepMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	
};
//class M_NFA_LoadFile 加载噪声仪校准状态文件
class M_NFA_LoadFile:public BaseMethod
{
public:
	M_NFA_LoadFile();
	virtual ~M_NFA_LoadFile();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};
//class M_NFA_GetListMax 获取最大噪声系数
class M_NFA_GetListMax:public BaseMethod
{
public:
	M_NFA_GetListMax();
	virtual ~M_NFA_GetListMax();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
	TParamSetStruct m_OutputPara;
};


//class M_NFA_SendCmd 发送指令
class M_NFA_SendCmd:public BaseMethod
{
public:
	M_NFA_SendCmd();
	virtual ~M_NFA_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_NFA_GetCmd 发送指令并获取指令的返回数据
class M_NFA_GetCmd:public BaseMethod
{
public:
	M_NFA_GetCmd();
	virtual ~M_NFA_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
};


//class M_NFA_GetIDN 获取设备型号信息
class M_NFA_GetIDN:public BaseMethod
{
public:
	M_NFA_GetIDN();
	virtual ~M_NFA_GetIDN();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

// class M_NFA_GetTraceMax 获取曲线数据的最大值(TraceIndex 1:NFIGure 2:GAIN 3:PHOT 4:PCOLd 5:TEFFective)
class M_NFA_GetTraceMax:public BaseMethod
{
public:
	M_NFA_GetTraceMax();
	virtual ~M_NFA_GetTraceMax();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1;
};

// class M_NFA_GetTraceMin 获取曲线数据的最小值(TraceIndex 1:NFIGure 2:GAIN 3:PHOT 4:PCOLd 5:TEFFective)
class M_NFA_GetTraceMin:public BaseMethod
{
public:
	M_NFA_GetTraceMin();
	virtual ~M_NFA_GetTraceMin();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1;
};

// class M_NFA_GetTraceFreqValue 获取曲线指定频率点的值(TraceIndex 1:NFIGure 2:GAIN 3:PHOT 4:PCOLd 5:TEFFective Freq:单位:MHz)
class M_NFA_GetTraceFreqValue:public BaseMethod
{
public:
	M_NFA_GetTraceFreqValue();
	virtual ~M_NFA_GetTraceFreqValue();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;
	TParamSetStruct m_OutputPara1;
};

