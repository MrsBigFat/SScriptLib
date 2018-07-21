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


/************************************************************************/
/*  万用表驱动程序方法类                                                 */
/************************************************************************/

//Class M_MMT_GetCurrent 获取万用表的电流值
class M_MMT_GetCurrent:public BaseMethod
{
public:
	M_MMT_GetCurrent();
	virtual ~M_MMT_GetCurrent();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};

//class M_MMT_GetZn 获取电阻(Ω)
class M_MMT_GetZn:public BaseMethod
{
public:
	M_MMT_GetZn();
	virtual ~M_MMT_GetZn();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};