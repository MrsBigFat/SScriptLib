#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"
//
//#include ".\include\DPDDriver.h"
//#pragma comment(lib,".\\lib\\DPDDriver.lib")
//
//#include ".\include\PSADriver.h"
//#pragma comment(lib,".\\lib\\PSADriver.lib")
//
//#include ".\include\PRMDriver.h"
//#pragma comment(lib,".\\lib\\PRMDriver.lib")


/************************************************************************
* �汾��2.0.0.45
* ���ߣ�dolby.jiang
* ������ڣ�2009��10��10��
* ���ģ�
*
************************************************************************/


/************************************************************************
* �汾��3.0.0.7
* ���ߣ�dolby.jiang
* ������ڣ�2010��6��22��
* ���ģ��޸� M_DPD_SetCarriedMode�Ĺ���������
*
************************************************************************/
/************************************************************************
* �汾��3.0.2.7
* ���ߣ�dolby.jiang
* ������ڣ�2011��4��3��
* ���ģ�
1 ���� M_DPD_SetSmallTxAtten �������TX��·ϸ������ֵ
2 ���� M_DPD_GetSmallTxAtten ��ȡ���TX��·ϸ������ֵ
*
************************************************************************/

/************************************************************************/
/*  DPD���������򷽷���                                                 */
/************************************************************************/

//M_DPD_SetDPDState ����DPD����״̬(0:�� 1:��)
class M_DPD_SetDPDState:public BaseMethod
{
public:
	M_DPD_SetDPDState();
	virtual ~M_DPD_SetDPDState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_DPD_SetTxAtten ���÷���ͨ��˥��ֵ(0x3f��ʾ��˥��0��ʾȫ˥������0.5dB)
class M_DPD_SetTxAtten:public BaseMethod
{
public:
	M_DPD_SetTxAtten();
	virtual ~M_DPD_SetTxAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_DPD_SetSmallTxAtten �������TX��·ϸ������ֵ(����0.1dB)
class M_DPD_SetSmallTxAtten:public BaseMethod
{
public:
	M_DPD_SetSmallTxAtten();
	virtual ~M_DPD_SetSmallTxAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_DPD_SetRDAtten ���÷���ͨ��˥��ֵ(0x3f��ʾ��˥��0��ʾȫ˥������0.5dB)
class M_DPD_SetRDAtten:public BaseMethod
{
public:
	M_DPD_SetRDAtten();
	virtual ~M_DPD_SetRDAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_DPD_GetErrPower ��ȡƫ���
class M_DPD_GetErrPower:public BaseMethod
{
public:
	M_DPD_GetErrPower();
	virtual ~M_DPD_GetErrPower();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};

//M_DPD_SetSixPwrFpg ����6�ز���������
class M_DPD_SetSixPwrFpg:public BaseMethod
{
public:
	M_DPD_SetSixPwrFpg();
	virtual ~M_DPD_SetSixPwrFpg();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//M_DPD_SetNinePwrFpg ����9�ع��ʲ�����
class M_DPD_SetNinePwrFpg:public BaseMethod
{
public:
	M_DPD_SetNinePwrFpg();
	virtual ~M_DPD_SetNinePwrFpg();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//M_DPD_SetTwelvePwrFpg ����12�ع��ʲ�����
class M_DPD_SetTwelvePwrFpg:public BaseMethod
{
public:
	M_DPD_SetTwelvePwrFpg();
	virtual ~M_DPD_SetTwelvePwrFpg();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//M_DPD_SetErrPwrDebug DPDƫ��ʵ���
class M_DPD_SetErrPwrDebug:public BaseMethod
{
public:
	M_DPD_SetErrPwrDebug();
	virtual ~M_DPD_SetErrPwrDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DPDDeviceName, m_PSADeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//class M_DPD_ACPRPowerDebug ZXģ���ƷACPR���ʵ���
class M_DPD_ACPRPowerDebug:public BaseMethod
{
public:
	M_DPD_ACPRPowerDebug();
	virtual ~M_DPD_ACPRPowerDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DPDDeviceName, m_PSADeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};

//class M_DPD_SetWorkFreq ����DPD����Ƶ��(1: 2017.5M 2: 1880M 3:875/930/1810  4:880/946.8/1830  5:885/955/1855
//6:1830 7:1850 8:1875 9:1910M)
class M_DPD_SetWorkFreq:public BaseMethod
{
public:
	M_DPD_SetWorkFreq();
	virtual ~M_DPD_SetWorkFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//class M_DPD_ACPRPowerDebugDT DTģ���ƷACPR���ʵ���
class M_DPD_ACPRPowerDebugDT:public BaseMethod
{
public:
	M_DPD_ACPRPowerDebugDT();
	virtual ~M_DPD_ACPRPowerDebugDT();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DPDDeviceName, m_PSADeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//M_DPD_SetErrPwrDebug DT DPDƫ��ʵ���
class M_DPD_SetErrPwrDebugDT:public BaseMethod
{
public:
	M_DPD_SetErrPwrDebugDT();
	virtual ~M_DPD_SetErrPwrDebugDT();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DPDDeviceName, m_PSADeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};
//class M_DPD_SetSGMode ����DPD�ź�ģʽ(0:GMSK  1:8PSK 2:GMSK+8PSK)
class M_DPD_SetSGMode:public BaseMethod
{
public:
	M_DPD_SetSGMode();
	virtual ~M_DPD_SetSGMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};
//class M_DPD_SetCarriedMode ����DPD�ز�ģʽ	
/* Mode : 0:3M�ȼ��	1:3M���ȼ��	2:5M�ȼ��	3:5M���ȼ��  
		  4:10M�ȼ��	5:0M���ȼ��	6:5M�ȼ��  7:15M���ȼ��
*/	 
class M_DPD_SetCarriedMode:public BaseMethod
{
public:
	M_DPD_SetCarriedMode();
	virtual ~M_DPD_SetCarriedMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};
//class M_DPD_SetCarriedCount �����ز�����(0:3�ز�	1:4�ز�	2:6�ز�)	 
class M_DPD_SetCarriedCount:public BaseMethod
{
public:
	M_DPD_SetCarriedCount();
	virtual ~M_DPD_SetCarriedCount();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};
//M_DPD_Reset ��λ
class M_DPD_Reset:public BaseMethod
{
public:
	M_DPD_Reset();
	virtual ~M_DPD_Reset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//class M_DPD_PRMPowerDebug �ڹ����µ������
class M_DPD_PRMPowerDebug:public BaseMethod
{
public:
	M_DPD_PRMPowerDebug();
	virtual ~M_DPD_PRMPowerDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DPDDevName,m_PRMDevName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//M_DPD_GetIDN ��ȡ������Ϣ
class M_DPD_GetIDN:public BaseMethod
{
public:
	M_DPD_GetIDN();
	virtual ~M_DPD_GetIDN();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};


//class M_DPD_SendCmd ����ָ��
class M_DPD_SendCmd:public BaseMethod
{
public:
	M_DPD_SendCmd();
	virtual ~M_DPD_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};
//class M_DPD_GetCmd ����ָ���ȡָ��ķ�������
class M_DPD_GetCmd:public BaseMethod
{
public:
	M_DPD_GetCmd();
	virtual ~M_DPD_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
};

//class M_DPD_SetRFOutPower ����DPD�������
class M_DPD_SetRFOutPower:public BaseMethod
{
public:
	M_DPD_SetRFOutPower();
	virtual ~M_DPD_SetRFOutPower();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_DPD_GetRFOutPower ��ȡDPD�������
class M_DPD_GetRFOutPower:public BaseMethod
{
public:
	M_DPD_GetRFOutPower();
	virtual ~M_DPD_GetRFOutPower();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};

//class M_DPD_SetCFR ����CFR����ֵ
class M_DPD_SetCFR:public BaseMethod
{
public:
	M_DPD_SetCFR();
	virtual ~M_DPD_SetCFR();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_DPD_GetCFR ��ȡCFR����ֵ
class M_DPD_GetCFR:public BaseMethod
{
public:
	M_DPD_GetCFR();
	virtual ~M_DPD_GetCFR();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};

//class M_DPD_GetRDAtten ��ȡ����ͨ��˥��ֵ
class M_DPD_GetRDAtten:public BaseMethod
{
public:
	M_DPD_GetRDAtten();
	virtual ~M_DPD_GetRDAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};

//class M_DPD_GetTxAtten ��ȡ����ͨ��˥��ֵ
class M_DPD_GetTxAtten:public BaseMethod
{
public:
	M_DPD_GetTxAtten();
	virtual ~M_DPD_GetTxAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};

//class M_DPD_GetSmallTxAtten ��ȡ���TX��·ϸ������ֵ
class M_DPD_GetSmallTxAtten:public BaseMethod
{
public:
	M_DPD_GetSmallTxAtten();
	virtual ~M_DPD_GetSmallTxAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};

// ��ȡ�豸��������
class M_DPD_ReadDev:public BaseMethod
{
public:
	M_DPD_ReadDev();
	virtual ~M_DPD_ReadDev();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};
	