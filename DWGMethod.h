#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"

//M_DWG_Reset ��λ
class M_DWG_Reset:public BaseMethod
{
public:
	M_DWG_Reset();
	virtual ~M_DWG_Reset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
		
};

//class M_DWG_SendCmd ����ָ��
class M_DWG_SendCmd:public BaseMethod
{
public:
	M_DWG_SendCmd();
	virtual ~M_DWG_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_DWG_GetCmd ����ָ���ȡָ��ķ�������
class M_DWG_GetCmd:public BaseMethod
{
public:
	M_DWG_GetCmd();
	virtual ~M_DWG_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
};


//class M_DWG_GetIDN ��ȡ�豸�ͺ���Ϣ
class M_DWG_GetIDN:public BaseMethod
{
public:
	M_DWG_GetIDN();
	virtual ~M_DWG_GetIDN();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

//M_DWG_LoadFile ����״̬�ļ�
class M_DWG_LoadFile:public BaseMethod
{
public:
	M_DWG_LoadFile();
	virtual ~M_DWG_LoadFile();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//����ͨ������
class M_DWG_SetCHSwitch:public BaseMethod
{
public:
	M_DWG_SetCHSwitch();
	virtual ~M_DWG_SetCHSwitch();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	//TParamSetStruct m_IutputPara1;
	TParamSetStruct m_InputPara2;

};

//�����ܿ���
class M_DWG_SetAllSwitch:public BaseMethod
{
public:
	M_DWG_SetAllSwitch();
	virtual ~M_DWG_SetAllSwitch();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;

};

//���õ�ƽ
class M_DWG_SetAmpLevel:public BaseMethod
{
public:
	M_DWG_SetAmpLevel();
	virtual ~M_DWG_SetAmpLevel();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;

};