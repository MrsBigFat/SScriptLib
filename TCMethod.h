#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"


//class M_TC_GetCardMCUVersion ��ȡ���Կ�MCU������汾
class M_TC_GetCardMCUVersion:public BaseMethod
{
public:
	M_TC_GetCardMCUVersion();
	virtual ~M_TC_GetCardMCUVersion();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};


// class M_TC_GetCardCPLDVersion ��ȡ���Կ�CPLD�汾��
class M_TC_GetCardCPLDVersion:public BaseMethod
{
public:
	M_TC_GetCardCPLDVersion();
	virtual ~M_TC_GetCardCPLDVersion();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};

// class M_TC_SetCardProductNo ���ò��Կ���Ʒ�� 	
class M_TC_SetCardProductNo:public BaseMethod
{
public:
	M_TC_SetCardProductNo();
	virtual ~M_TC_SetCardProductNo();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

// class M_TC_GetCardProductNo ��ȡ���Կ���Ʒ��
class M_TC_GetCardProductNo:public BaseMethod
{
public:
	M_TC_GetCardProductNo();
	virtual ~M_TC_GetCardProductNo();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};

//class M_TC_GetIDN ��ȡ��Ʒ������Ϣ
//class M_TC_GetIDN(short int Handle, char *IDNHigh, char *IDNLow);

// class M_TC_SendCmd ����ָ��
//class M_TC_SendCmd(short int Handle, char *Command);

// class M_TC_GetCmd ��ȡ����ָ��ֵ
//class M_TC_GetCmd(short int Handle, char *Command, char *RetStr);


// M_TC_SetCardStartAndStopFlash ���ò��Կ�FLASH��ֹ��ַ������
class M_TC_SetCardStartAndStopFlash:public BaseMethod
{
public:
	M_TC_SetCardStartAndStopFlash();
	virtual ~M_TC_SetCardStartAndStopFlash();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[4];		
};


//M_TC_GetCardStartAndStopFlash ��ȡ���Կ�FLAST��ֹ��ַ������
class M_TC_GetCardStartAndStopFlash:public BaseMethod
{
public:
	M_TC_GetCardStartAndStopFlash();
	virtual ~M_TC_GetCardStartAndStopFlash();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[3];
	TParamSetStruct m_OutputPara1;
};