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
/*  EEPROMУ׼�������򷽷���                                                                    */
/************************************************************************/
//M_ADJ_WriteCal дУ׼
class M_ADJ_WriteCal:public BaseMethod
{
public:
	M_ADJ_WriteCal();
	virtual ~M_ADJ_WriteCal();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[4];
	TParamSetStruct m_OutputPara1,m_OutputPara2,m_OutputPara3;

};
//M_ADJ_ReadCal ��У׼
class M_ADJ_ReadCal:public BaseMethod
{
public:
	M_ADJ_ReadCal();
	virtual ~M_ADJ_ReadCal();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;	
	TParamSetStruct m_OutputPara1,m_OutputPara2,m_OutputPara3;
};
//M_ADJ_GetClientSNRelate ��ȡ��Ʒ�Ŀͻ�SN��У׼�����Ƿ��й�ϵ(0:��  1:��)
class M_ADJ_GetClientSNRelate:public BaseMethod
{
public:
	M_ADJ_GetClientSNRelate();
	virtual ~M_ADJ_GetClientSNRelate();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;	
	TParamSetStruct m_OutputPara1;
};