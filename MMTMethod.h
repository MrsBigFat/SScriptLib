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
* �汾��2.0.0.45
* ���ߣ�dolby.jiang
* ������ڣ�2009��10��10��
* ���ģ�
*
************************************************************************/


/************************************************************************/
/*  ���ñ��������򷽷���                                                 */
/************************************************************************/

//Class M_MMT_GetCurrent ��ȡ���ñ�ĵ���ֵ
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

//class M_MMT_GetZn ��ȡ����(��)
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