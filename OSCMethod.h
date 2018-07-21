#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"

//复位
class M_OSC_Reset:public BaseMethod
{
public:
	M_OSC_Reset();
	virtual ~M_OSC_Reset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
		
};
//OSC_SetDTLEVParam:
class M_OSC_SetDTLEVParam:public BaseMethod
{
public:
	M_OSC_SetDTLEVParam();
	virtual ~M_OSC_SetDTLEVParam();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara0,m_InputPara1,m_InputPara2,m_InputPara3,m_InputPara4,m_InputPara5,m_InputPara6;
	TParamSetStruct m_InputDeviceName;
		
};


//OSC_SetGrid:
class M_OSC_SetGrid:public BaseMethod
{
public:
	M_OSC_SetGrid();
	virtual ~M_OSC_SetGrid();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_InputDeviceName;
		
};


//OSC_SetTrigType:
class M_OSC_SetTrigType:public BaseMethod
{
public:
	M_OSC_SetTrigType();
	virtual ~M_OSC_SetTrigType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_InputDeviceName;
		
};

//OSC_SetTrigCoupling:
class M_OSC_SetTrigCoupling:public BaseMethod
{
public:
	M_OSC_SetTrigCoupling();
	virtual ~M_OSC_SetTrigCoupling();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1, m_InputPara2;
	TParamSetStruct m_InputDeviceName;
		
};

//OSC_SetTrigSlope:
class M_OSC_SetTrigSlope:public BaseMethod
{
public:
	M_OSC_SetTrigSlope();
	virtual ~M_OSC_SetTrigSlope();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1, m_InputPara2;
	TParamSetStruct m_InputDeviceName;
		
};

//OSC_SetTrigLevel:
class M_OSC_SetTrigLevel:public BaseMethod
{
public:
	M_OSC_SetTrigLevel();
	virtual ~M_OSC_SetTrigLevel();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1, m_InputPara2;
	TParamSetStruct m_InputDeviceName;
		
};

//OSC_SetScaleVDIV:
class M_OSC_SetScaleVDIV:public BaseMethod
{
public:
	M_OSC_SetScaleVDIV();
	virtual ~M_OSC_SetScaleVDIV();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1, m_InputPara2;
	TParamSetStruct m_InputDeviceName;
		
};

//OSC_SetScaleTDIV:
class M_OSC_SetScaleTDIV:public BaseMethod
{
public:
	M_OSC_SetScaleTDIV();
	virtual ~M_OSC_SetScaleTDIV();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_InputDeviceName;
		
};

//OSC_GetMeaValue:
class M_OSC_GetMeaValue:public BaseMethod
{
public:
	M_OSC_GetMeaValue();
	virtual ~M_OSC_GetMeaValue();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1;
	TParamSetStruct m_InputDeviceName;
		
};

//M_OSC_SetTrigMode:
class M_OSC_SetTrigMode:public BaseMethod
{
public:
	M_OSC_SetTrigMode();
	virtual ~M_OSC_SetTrigMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_InputDeviceName;
		
};

//class M_OSC_SendCmd 发送指令
class M_OSC_SendCmd:public BaseMethod
{
public:
	M_OSC_SendCmd();
	virtual ~M_OSC_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_OSC_GetCmd 发送指令并获取指令的返回数据
class M_OSC_GetCmd:public BaseMethod
{
public:
	M_OSC_GetCmd();
	virtual ~M_OSC_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
};

//设置DeltaDelay模式参数:
class M_OSC_SetDeltaDelay:public BaseMethod
{
public:
	M_OSC_SetDeltaDelay();
	virtual ~M_OSC_SetDeltaDelay();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara0,m_InputPara1,m_InputPara2;	

};

//设置Trace显示:
class M_OSC_SetTraceDis:public BaseMethod
{
public:
	M_OSC_SetTraceDis();
	virtual ~M_OSC_SetTraceDis();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;	

};