#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"

//#include ".\include\PRMDriver.h"
//#pragma comment(lib,".\\lib\\PRMDriver.lib")


/************************************************************************
* 版本：2.0.0.45
* 作者：dolby.jiang
* 完成日期：2009年10月10日
* 更改：第一整理
*
************************************************************************/

/************************************************************************
* 版本：2.1.0.4
* 作者：dolby.jiang
* 完成日期：2009年11月12日
* 更改：增加PRM_GetIDN PRM_SendCmd PRM_GetCmd
*
************************************************************************/

/************************************************************************/
/*  功率计驱动程序方法类                                                */
/************************************************************************/

//M_PRM_Reset 复位 
class M_PRM_Reset:public BaseMethod
{
public:
	M_PRM_Reset();
	virtual ~M_PRM_Reset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;	
};

//M_PRM_Calculate 校准
class M_PRM_Calculate:public BaseMethod
{
public:
	M_PRM_Calculate();
	virtual ~M_PRM_Calculate();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_PRM_SetMeasPos 设置测量方式(0:Load 1:SOURce)
class M_PRM_SetMeasPos:public BaseMethod
{
public:
	M_PRM_SetMeasPos();
	virtual ~M_PRM_SetMeasPos();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;
};

//M_PRM_SetOffset 设置插损(0~100 dB)
class M_PRM_SetOffset:public BaseMethod
{
public:
	M_PRM_SetOffset();
	virtual ~M_PRM_SetOffset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;
};

//M_PRM_GetPower 获取测试测量值
class M_PRM_GetPower:public BaseMethod
{
public:
	M_PRM_GetPower();
	virtual ~M_PRM_GetPower();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1, m_OutputPara2;
};

//M_PRM_SetMeasMode 设置测量模式(0:平均功率 1:峰值功率 2:脉冲功率 )
class M_PRM_SetMeasMode:public BaseMethod
{
public:
	M_PRM_SetMeasMode();
	virtual ~M_PRM_SetMeasMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_PRM_SetMeasMode 设置测量单位(0:W 1:DB 2:%)
class M_PRM_SetMeasUnit: public BaseMethod
{
public:
	M_PRM_SetMeasUnit();
	virtual ~M_PRM_SetMeasUnit();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//class M_PRM_GetIDN 获取设备型号信息
class M_PRM_GetIDN:public BaseMethod
{
public:
	M_PRM_GetIDN();
	virtual ~M_PRM_GetIDN();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

//class M_PRM_SendCmd 发送指令
class M_PRM_SendCmd:public BaseMethod
{
public:
	M_PRM_SendCmd();
	virtual ~M_PRM_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_PRM_GetCmd 发送指令并获取指令的返回数据
class M_PRM_GetCmd:public BaseMethod
{
public:
	M_PRM_GetCmd();
	virtual ~M_PRM_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
};



