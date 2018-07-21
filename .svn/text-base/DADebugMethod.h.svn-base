#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"


//#include ".\include\NTSAD.h"
//#pragma comment(lib,".\\lib\\NTSAD.lib")


/************************************************************************
* 版本：2.0.0.45
* 作者：dolby.jiang
* 完成日期：2009年10月10日
* 更改：
*
************************************************************************/



/************************************************************************/
/*  DA调试驱动程序方法类                                                                    */
/************************************************************************/
//M_DEB_WriteDebug DA调试并返回调试后的数据
class M_DEB_WriteDebug:public BaseMethod
{
public:
	M_DEB_WriteDebug();
	virtual ~M_DEB_WriteDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
	TParamSetStruct m_OutputPara1, m_OutputPara2, m_OutputPara3,m_OutputPara4;
	
};

//M_DEB_ReadDebug 读取调试数据
class M_DEB_ReadDebug:public BaseMethod
{
public:
	M_DEB_ReadDebug();
	virtual ~M_DEB_ReadDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1, m_OutputPara2, m_OutputPara3;
};