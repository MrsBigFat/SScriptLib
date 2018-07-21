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
* 版本：2.0.1.6
* 作者：dolby.jiang
* 完成日期：2009年12月21日
* 更改：新建
*
************************************************************************/

//M_IRU_Reboot 重启
class M_IRU_Reboot:public BaseMethod
{
public:
	M_IRU_Reboot();
	virtual ~M_IRU_Reboot();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//M_IRU_Reset IRU板复位
class M_IRU_Reset:public BaseMethod
{
public:
	M_IRU_Reset();
	virtual ~M_IRU_Reset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//M_IRU_GetIDN 获取生产信息
class M_IRU_GetIDN:public BaseMethod
{
public:
	M_IRU_GetIDN();
	virtual ~M_IRU_GetIDN();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};

//M_IRU_SendCmd 发送指令
class M_IRU_SendCmd:public BaseMethod
{
public:
	M_IRU_SendCmd();
	virtual ~M_IRU_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_IRU_GetCmd 发送指令并获取指令的返回数据
class M_IRU_GetCmd:public BaseMethod
{
public:
	M_IRU_GetCmd();
	virtual ~M_IRU_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};

//M_IRU_LoadFile 加载文件
class M_IRU_LoadFile:public BaseMethod
{
public:
	M_IRU_LoadFile();
	virtual ~M_IRU_LoadFile();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};