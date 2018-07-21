//////////////////////VSA 89600 Method///////////////////////////////////
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
* 版本：3.0.2.14
* 作者：dolby.jiang
* 完成日期：2011年9月13日
* 更改：新建
*
************************************************************************/


// 加载VSA配置文件(Visible 0:不可见 1:可见)
class M_PSA_VSAOpen:public BaseMethod
{
public:
	M_PSA_VSAOpen();
	virtual ~M_PSA_VSAOpen();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;
};

// 关闭进程,退出VSA
class M_PSA_VSAClose:public BaseMethod
{
public:
	M_PSA_VSAClose();
	virtual ~M_PSA_VSAClose();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
};

// 启动VSA测量,并保存测试结果到文件
class M_PSA_VSARunAndSaveData:public BaseMethod
{
public:
	M_PSA_VSARunAndSaveData();
	virtual ~M_PSA_VSARunAndSaveData();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;
};

// 设置中心频率(MHz)
class M_PSA_VSASetCenterFreq:public BaseMethod
{
public:
	M_PSA_VSASetCenterFreq();
	virtual ~M_PSA_VSASetCenterFreq();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

// 设置起止频率(MHz)
class M_PSA_VSASetStartandStopFreq:public BaseMethod
{
public:
	M_PSA_VSASetStartandStopFreq();
	virtual ~M_PSA_VSASetStartandStopFreq();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;
};

// 设置SPAN(MHz)
class M_PSA_VSASetSpan:public BaseMethod
{
public:
	M_PSA_VSASetSpan();
	virtual ~M_PSA_VSASetSpan();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

// 设置RBW(MHz)
class M_PSA_VSASetRBW:public BaseMethod
{
public:
	M_PSA_VSASetRBW();
	virtual ~M_PSA_VSASetRBW();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

// 设置扫描时间(mS)
class M_PSA_VSASetSweepTime:public BaseMethod
{
public:
	M_PSA_VSASetSweepTime();
	virtual ~M_PSA_VSASetSweepTime();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

// 设置参考电平(dB)
class M_PSA_VSASetRefLevel:public BaseMethod
{
public:
	M_PSA_VSASetRefLevel();
	virtual ~M_PSA_VSASetRefLevel();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;
};	

// 设置当前激活通道
class M_PSA_VSASetActiveChannel:public BaseMethod
{
public:
	M_PSA_VSASetActiveChannel();
	virtual ~M_PSA_VSASetActiveChannel();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

// 设置触发源(0:Freerun 1:External 2:External TTL  3:Channel 4:IF Mag)
class M_PSA_VSASetTrigSource:public BaseMethod
{
public:
	M_PSA_VSASetTrigSource();
	virtual ~M_PSA_VSASetTrigSource();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

// 设置触发延迟时间(单位:ms)
class M_PSA_VSASetTrigDelayTime:public BaseMethod
{
public:
	M_PSA_VSASetTrigDelayTime();
	virtual ~M_PSA_VSASetTrigDelayTime();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};
	