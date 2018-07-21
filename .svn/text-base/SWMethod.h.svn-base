#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"



/************************************************************************/
/* 矩阵开关驱动程序方法类                                               */
/************************************************************************/

//class M_SW_SetSwtichState 设置矩阵开关状态
class M_SW_SetSwtichState:public BaseMethod
{
public:
	M_SW_SetSwtichState();
	virtual ~M_SW_SetSwtichState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

// class M_SW_SetCtrlPort 设置矩阵端口号(1~255)
class M_SW_SetCtrlPort:public BaseMethod
{
public:
	M_SW_SetCtrlPort();
	virtual ~M_SW_SetCtrlPort();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

