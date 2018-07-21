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
* �汾��3.0.2.22
* ���ߣ�dolby.jiang
* ������ڣ�2011��12��27��
* ���ģ��½�
*
************************************************************************/


/************************************************************************/
/*  ͨ�ýӿڿ��������򷽷���                                            */
/************************************************************************/
// M_NC_OpenDev �򿪲���ʼ��NCard
class M_NC_OpenDev:public BaseMethod
{
public:
	M_NC_OpenDev();
	virtual ~M_NC_OpenDev();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
};
//�ر�NCard�豸
class M_NC_CloseDev : public BaseMethod
{
public:
	M_NC_CloseDev();
	virtual ~M_NC_CloseDev();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
};
//ϵͳ������ѯ
class M_NC_QuerySysParam : public BaseMethod
{
public:
	M_NC_QuerySysParam();
	virtual ~M_NC_QuerySysParam();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputSysparam;
};
//ϵͳ״̬��ѯ
class M_NC_QuerySysState : public BaseMethod
{
public:
	M_NC_QuerySysState();
	virtual ~M_NC_QuerySysState();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputSysState;
};
//����ͨѶ����
class M_NC_CreateCommObject : public BaseMethod
{
public:
	M_NC_CreateCommObject();
	virtual ~M_NC_CreateCommObject();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputConnStr;    //char* (object connection string)
	TParamSetStruct m_OutputObjID;  //long (object ID)
};
//����ͨѶ����
class M_NC_DeleteCommObject : public BaseMethod
{
public:
	M_NC_DeleteCommObject();
	virtual ~M_NC_DeleteCommObject();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
};
//ͨѶ���������
class M_NC_Read : public BaseMethod
{
public:
	M_NC_Read();
	virtual ~M_NC_Read();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
	TParamSetStruct m_InputExpLen;
	TParamSetStruct m_InputDataFormat;
	TParamSetStruct m_OutputRead;
	TParamSetStruct m_OutputRealLen;
};
//ͨ�Ŷ���д����
class M_NC_Write : public BaseMethod
{
public:
	M_NC_Write();
	virtual ~M_NC_Write();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
	TParamSetStruct m_InputExpLen;
	TParamSetStruct m_InputDataFormat;
	TParamSetStruct m_InputWrite;
	TParamSetStruct m_OutputRealLen;
};
//����ͨѶ���󻺳���
class M_NC_SetBufSize : public BaseMethod
{
public:
	M_NC_SetBufSize();
	virtual ~M_NC_SetBufSize();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
	TParamSetStruct m_InputType;
	TParamSetStruct m_InputSize;
};
//���ͨѶ���󻺳���
class M_NC_ClearBuf : public BaseMethod
{
public:
	M_NC_ClearBuf();
	virtual ~M_NC_ClearBuf();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
	TParamSetStruct m_InputType;
};
//ͨѶ����д�������ַ�����
class M_NC_Sprintf : public BaseMethod
{
public:
	M_NC_Sprintf();
	virtual ~M_NC_Sprintf();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
	TParamSetStruct m_InputCommand;
};
//ͨѶ������������ַ�����
class M_NC_Query : public BaseMethod
{
public:
	M_NC_Query();
	virtual ~M_NC_Query();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
	TParamSetStruct m_InputCommand;
	TParamSetStruct m_OutputRetStr;
};
//������Ϣ��ѯ
class M_NC_QueryContextInfo : public BaseMethod
{
public:
	M_NC_QueryContextInfo();
	virtual ~M_NC_QueryContextInfo();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputSysparam;
};
//�汾��Ϣ��ѯ
class M_NC_QueryVersionInfo : public BaseMethod
{
public:
	M_NC_QueryVersionInfo();
	virtual ~M_NC_QueryVersionInfo();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputSysparam;
};
//����IP��ַ
class M_NC_SetIPAddress : public BaseMethod
{
public:
	M_NC_SetIPAddress();
	virtual ~M_NC_SetIPAddress();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputNetType;
	TParamSetStruct m_InputIPAdress;
};
//����
class M_NC_Reset : public BaseMethod
{
public:
	M_NC_Reset();
	virtual ~M_NC_Reset();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
};