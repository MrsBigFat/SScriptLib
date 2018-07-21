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
* �汾��2.0.0.45
* ���ߣ�dolby.jiang
* ������ڣ�2009��10��10��
* ���ģ�
*
************************************************************************/



/************************************************************************/
/*  DA�����������򷽷���                                                                    */
/************************************************************************/
//M_DEB_WriteDebug DA���Բ����ص��Ժ������
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

//M_DEB_ReadDebug ��ȡ��������
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