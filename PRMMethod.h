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
* �汾��2.0.0.45
* ���ߣ�dolby.jiang
* ������ڣ�2009��10��10��
* ���ģ���һ����
*
************************************************************************/

/************************************************************************
* �汾��2.1.0.4
* ���ߣ�dolby.jiang
* ������ڣ�2009��11��12��
* ���ģ�����PRM_GetIDN PRM_SendCmd PRM_GetCmd
*
************************************************************************/

/************************************************************************/
/*  ���ʼ��������򷽷���                                                */
/************************************************************************/

//M_PRM_Reset ��λ 
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

//M_PRM_Calculate У׼
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

//M_PRM_SetMeasPos ���ò�����ʽ(0:Load 1:SOURce)
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

//M_PRM_SetOffset ���ò���(0~100 dB)
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

//M_PRM_GetPower ��ȡ���Բ���ֵ
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

//M_PRM_SetMeasMode ���ò���ģʽ(0:ƽ������ 1:��ֵ���� 2:���幦�� )
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

//M_PRM_SetMeasMode ���ò�����λ(0:W 1:DB 2:%)
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

//class M_PRM_GetIDN ��ȡ�豸�ͺ���Ϣ
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

//class M_PRM_SendCmd ����ָ��
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

//class M_PRM_GetCmd ����ָ���ȡָ��ķ�������
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



