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


/************************************************************************
* �汾��2.1.0.0
* ���ߣ�dolby.jiang
* ������ڣ�2009��10��13��
* ���ģ�����NTS_SendCmd\NTS_GetCmd ������
*
************************************************************************/


/************************************************************************
* �汾��2.1.0.7
* ���ߣ�dolby.jiang
* ������ڣ�2009��12��30��
* ���ģ�1) ���� M_NTS_SetStarAndStopFlash
		2) ���� M_NTS_GetStarAndStopFlash
		3) ���� M_NTS_SetStarAndStopEEPROM
		4) ���� M_NTS_GetStarAndStopEEPROM		
*
************************************************************************/

/************************************************************************
* �汾��2.1.0.7
* ���ߣ�dolby.jiang
* ������ڣ�2010��1��25��
* ���ģ�1) ���� M_NTS_SetCRC		
*
************************************************************************/


/************************************************************************
* �汾��2.1.0.8
* ���ߣ�dolby.jiang
* ������ڣ�2010��2��26��
* ���ģ�1) ���� M_NTS_SetPID ���õ������Բ���		
		2) ���� M_NTS_SetGainWorkPara ���ù��ŵľ�̬��������
		3) ���� M_NTS_GainDebug �ڵ������µ��Ե������ŵľ�̬��������
*
************************************************************************/

/************************************************************************
* �汾��3.0.0.8
* ���ߣ�dolby.jiang
* ������ڣ�2010��7��12��
* ���ģ�1) ���� M_NTS_GetPowerState ��ȡ��Դ����״̬			
*
************************************************************************/

/************************************************************************
* �汾��3.0.2.5
* ���ߣ�dolby.jiang
* ������ڣ�2010��12��29��
* ���ģ�1) ���� M_NTS_GetVoltage ��ȡͨ���ĵ�ѹ(��λ:bit)
		2) ���� M_NTS_SetActiveObject ���õ�ǰ��Ҫ�ļ�صĶ���
*
************************************************************************/

/************************************************************************
* �汾��3.0.2.8
* ���ߣ�dolby.jiang
* ������ڣ�2011��4��13��
* ���ģ�1) ���� M_NTS_SetFourGAOutputVol ���õ��ļ����ŵ������ѹ
		2) ���� M_NTS_GetFourGAOutputVol ��ȡ���ļ����ŵ������ѹ
*
************************************************************************/

/************************************************************************/
/*  ��˾ģ���������򷽷���                                               */
/************************************************************************/

//M_NTS_OpenDev ���豸
class M_NTS_OpenDev: public BaseMethod
{
public:
	M_NTS_OpenDev();
	virtual ~M_NTS_OpenDev();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1, m_InputPara2;	
	TParamSetStruct m_OutputPara1;
};

//M_NTS_CloseDev �ر��豸
class M_NTS_CloseDev: public BaseMethod
{
public:
	M_NTS_CloseDev();
	virtual ~M_NTS_CloseDev();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1, m_InputPara2;	
};

//Class M_NTS_SetModuleFuncNo ����ģ�鹦�ܺ�
/*
class M_NTS_SetModuleFuncNo:public BaseMethod
{
public:
   M_NTS_SetModuleFuncNo();
   virtual ~M_NTS_SetModuleFuncNo();
   virtual int Init(void);
   virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};*/

//class M_NTS_SetModuleNo ����ģ����
/*
class M_NTS_SetModuleNo:public BaseMethod
{
public:
	M_NTS_SetModuleNo();
	virtual ~M_NTS_SetModuleNo();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};*/

//class M_NTS_SetUpAtten ����ͨ��������˥��ֵ
/*
class M_NTS_SetUpAtten:public BaseMethod
{
public:
	M_NTS_SetUpAtten();
	virtual ~M_NTS_SetUpAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};*/

//class M_NTS_GetUpAtten ��ȡͨ��������˥��ֵ
/*
class M_NTS_GetUpAtten:public BaseMethod
{
public:
	M_NTS_GetUpAtten();
	virtual ~M_NTS_GetUpAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
	
};*/

//class M_NTS_SetDownAtten ����ͨ��������˥��ֵ
/*
class M_NTS_SetDownAtten:public BaseMethod
{
public:
	M_NTS_SetDownAtten();
	virtual ~M_NTS_SetDownAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};*/

//class M_NTS_GetDownAtten ��ȡͨ��������˥��ֵ
/*
class M_NTS_GetDownAtten:public BaseMethod
{
public:
	M_NTS_GetDownAtten();
	virtual ~M_NTS_GetDownAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};*/

//class M_NTS_GetUpOpd ��ȡͨ��������OPD
/*
class M_NTS_GetUpOpd:public BaseMethod
{
public:
	M_NTS_GetUpOpd();
	virtual ~M_NTS_GetUpOpd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};*/

//class M_NTS_GetDownOpd ��ȡͨ��������OPD
/*
class M_NTS_GetDownOpd:public BaseMethod
{
public:
	M_NTS_GetDownOpd();
	virtual ~M_NTS_GetDownOpd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
	
};*/

//class M_NTS_GetDownIpd ��ȡͨ��������IPD
/*
class M_NTS_GetDownIpd:public BaseMethod
{
public:
	M_NTS_GetDownIpd();
	virtual ~M_NTS_GetDownIpd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};*/

//class M_NTS_GetModuleVersion ��ȡģ��MCU������汾
class M_NTS_GetModuleVersion:public BaseMethod
{
public:
	M_NTS_GetModuleVersion();
	virtual ~M_NTS_GetModuleVersion();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_GetCardVersion ��ȡ���Կ�MCU������汾
class M_NTS_GetCardVersion:public BaseMethod
{
public:
	M_NTS_GetCardVersion();
	virtual ~M_NTS_GetCardVersion();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetTmpCompensationData ����ͨ�����¶Ȳ�������
class M_NTS_SetTmpCompensationData:public BaseMethod
{
public:
	M_NTS_SetTmpCompensationData();
	virtual ~M_NTS_SetTmpCompensationData();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_GetTmpCompensationSense ��ȡͨ�����¶Ȳ����¶ȴ���������
class M_NTS_GetTmpCompensationSense:public BaseMethod
{
public:
	M_NTS_GetTmpCompensationSense();
	virtual ~M_NTS_GetTmpCompensationSense();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetPushOutputVol ����ͨ�����ƶ������������ѹ(DAֵ)
class M_NTS_SetPushOutputVol:public BaseMethod
{
public:
	M_NTS_SetPushOutputVol();
	virtual ~M_NTS_SetPushOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};
//class M_NTS_GetPushOutPutVol ��ȡͨ�����ƶ������������ѹ(DAֵ)
class M_NTS_GetPushOutPutVol:public BaseMethod
{
public:
	M_NTS_GetPushOutPutVol();
	virtual ~M_NTS_GetPushOutPutVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetLastOutputVol ����ͨ����ĩ�����������ѹ(DAֵ)
class M_NTS_SetLastOutputVol:public BaseMethod
{
public:
	M_NTS_SetLastOutputVol();
	virtual ~M_NTS_SetLastOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};
//class M_NTS_GetLastOutputVol ��ȡͨ����ĩ�����������ѹ(DAֵ)
class M_NTS_GetLastOutputVol:public BaseMethod
{
public:
	M_NTS_GetLastOutputVol();
	virtual ~M_NTS_GetLastOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetWorkMode ����ģ�鹤��ģʽ�ͼ��ģʽ(0:OPD 1:RPD)
class M_NTS_SetWorkMode:public BaseMethod
{
public:
	M_NTS_SetWorkMode();
	virtual ~M_NTS_SetWorkMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_GetWorkMode ��ȡģ��Ĺ���ģʽ
class M_NTS_GetWorkMode:public BaseMethod
{
public:
	M_NTS_GetWorkMode();
	virtual ~M_NTS_GetWorkMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1,m_OutputPara2;
};
//class M_NTS_SetOneBytePCB ����1λPCB����
class M_NTS_SetOneBytePCB:public BaseMethod
{
public:
	M_NTS_SetOneBytePCB();
	virtual ~M_NTS_SetOneBytePCB();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_GetOneBytePCB ��ȡ1λPCB����
class M_NTS_GetOneBytePCB:public BaseMethod
{
public:
	M_NTS_GetOneBytePCB();
	virtual ~M_NTS_GetOneBytePCB();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetPCB ����PCB���뵽FLASH��
class M_NTS_SetPCB:public BaseMethod
{
public:
	M_NTS_SetPCB();
	virtual ~M_NTS_SetPCB();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};
//class M_NTS_GetPCB ��ȡPCB����
class M_NTS_GetPCB:public BaseMethod
{
public:
	M_NTS_GetPCB();
	virtual ~M_NTS_GetPCB();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetEEPROM ����EEPROM����
class M_NTS_SetEEPROM:public BaseMethod
{
public:
	M_NTS_SetEEPROM();
	virtual ~M_NTS_SetEEPROM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_GetEEPROM ��ȡEEPROM����
class M_NTS_GetEEPROM:public BaseMethod
{
public:
	M_NTS_GetEEPROM();
	virtual ~M_NTS_GetEEPROM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetSwtichMode ���þ��󿪹ص�ģʽ
class M_NTS_SetSwtichMode:public BaseMethod
{
public:
	M_NTS_SetSwtichMode();
	virtual ~M_NTS_SetSwtichMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3,m_InputPara4;
};
//class M_NTS_SetPowerState ����ģ��Ĺ�����Դ״̬
class M_NTS_SetPowerState:public BaseMethod
{
public:
	M_NTS_SetPowerState();
	virtual ~M_NTS_SetPowerState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//class M_NTS_GetPowerState ��ȡģ��Ĺ�����Դ״̬
class M_NTS_GetPowerState:public BaseMethod
{
public:
	M_NTS_GetPowerState();
	virtual ~M_NTS_GetPowerState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};

//class M_NTS_GetTemperature ��ȡͨ�����¶�
class M_NTS_GetTemperature:public BaseMethod
{
public:
	M_NTS_GetTemperature();
	virtual ~M_NTS_GetTemperature();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};

/*

//class M_NTS_GetAgedData ��ȡģ���ϻ�����(�¶ȣ�������PCB����)
class M_NTS_GetAgedData:public BaseMethod
{
public:
	M_NTS_GetAgedData();
	virtual ~M_NTS_GetAgedData();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara[50];
};*/

/*
//class M_NTS_SetAgedWorkMode ����ģ���ϻ�ʱ�Ĺ���ģʽ
class M_NTS_SetAgedWorkMode:public BaseMethod
{
public:
	M_NTS_SetAgedWorkMode();
	virtual ~M_NTS_SetAgedWorkMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3,m_InputPara4;
	
};
*/

//class M_NTS_GetDownVSWR ��ȡģ���פ����
class M_NTS_GetDownVSWR:public BaseMethod
{
public:
	M_NTS_GetDownVSWR();
	virtual ~M_NTS_GetDownVSWR();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetLOFreq ����ģ��ı���Ƶ��
class M_NTS_SetLOFreq:public BaseMethod
{
public:
	M_NTS_SetLOFreq();
	virtual ~M_NTS_SetLOFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	
};
//class M_NTS_GetModuleCPLDVersion ��ȡģ��CPLD������汾
class M_NTS_GetModuleCPLDVersion:public BaseMethod
{
public:
	M_NTS_GetModuleCPLDVersion();
	virtual ~M_NTS_GetModuleCPLDVersion();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_GetCardCPLDVersion ��ȡ���Կ�CPLD������汾
class M_NTS_GetCardCPLDVersion:public BaseMethod
{
public:
	M_NTS_GetCardCPLDVersion();
	virtual ~M_NTS_GetCardCPLDVersion();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};
//class M_NTS_SetWorkModeEx ����ģ��ָ��ͨ���Ĺ���ģʽ
class M_NTS_SetWorkModeEx:public BaseMethod
{
public:
	M_NTS_SetWorkModeEx();
	virtual ~M_NTS_SetWorkModeEx();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_GetWorkModeEx ��ȡģ��ָ��ͨ���Ĺ���ģ
class M_NTS_GetWorkModeEx:public BaseMethod
{
public:
	M_NTS_GetWorkModeEx();
	virtual ~M_NTS_GetWorkModeEx();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1,m_OutputPara2;
};
//class M_NTS_SetDetectorMode ����ģ��ָ��ͨ���ļ��ģʽ
class M_NTS_SetDetectorMode:public BaseMethod
{
public:
	M_NTS_SetDetectorMode();
	virtual ~M_NTS_SetDetectorMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_GetDetectorMode ��ȡģ��ָ��ͨ���ļ��ģʽ
class M_NTS_GetDetectorMode:public BaseMethod
{
public:
	M_NTS_GetDetectorMode();
	virtual ~M_NTS_GetDetectorMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1;
};

//M_NTS_GetCardProductNo ��ȡ���Կ���Ʒ��
class M_NTS_GetCardProductNo:public BaseMethod
{
public:
	M_NTS_GetCardProductNo();
	virtual ~M_NTS_GetCardProductNo();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};
//M_NTS_GetModuleProductNo ��ȡģ��Ĳ�Ʒ��
class M_NTS_GetModuleProductNo:public BaseMethod
{
public:
	M_NTS_GetModuleProductNo();
	virtual ~M_NTS_GetModuleProductNo();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};
//class M_NTS_SetLanLinkMode ����ģ��ָ��ͨ���ĵ������·ģʽ
class M_NTS_SetLanLinkMode:public BaseMethod
{
public:
	M_NTS_SetLanLinkMode();
	virtual ~M_NTS_SetLanLinkMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_NTS_SetDectorState ����ָ��ͨ���Ĺ��ʼ��ʹ��״̬(0:off 1:on)
class M_NTS_SetDectorState:public BaseMethod
{
public:
	M_NTS_SetDectorState();
	virtual ~M_NTS_SetDectorState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};

//class M_NTS_SetSecGAOutputVol ���õڶ������ŵ������ѹ
class M_NTS_SetSecGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetSecGAOutputVol();
	virtual ~M_NTS_SetSecGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};
//class M_NTS_GetSecGAOutputVol ��ȡ�ڶ������ŵ������ѹ
class M_NTS_GetSecGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetSecGAOutputVol();
	virtual ~M_NTS_GetSecGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};

//class M_NTS_SetThirdGAOutputVol ���õ��������ŵ������ѹ
class M_NTS_SetThirdGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetThirdGAOutputVol();
	virtual ~M_NTS_SetThirdGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//class M_NTS_GetThirdGAOutputVol ��ȡ���������ŵ������ѹ
class M_NTS_GetThirdGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetThirdGAOutputVol();
	virtual ~M_NTS_GetThirdGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};

//class M_NTS_SetFourGAOutputVol ���õ��ļ����ŵ������ѹ
class M_NTS_SetFourGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetFourGAOutputVol();
	virtual ~M_NTS_SetFourGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//class M_NTS_GetFourGAOutputVol ��ȡ���ļ����ŵ������ѹ
class M_NTS_GetFourGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetFourGAOutputVol();
	virtual ~M_NTS_GetFourGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};


//���õ��弶���ŵ������ѹ
class M_NTS_SetFiveGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetFiveGAOutputVol();
	virtual ~M_NTS_SetFiveGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//��ȡ���弶���ŵ������ѹ
class M_NTS_GetFiveGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetFiveGAOutputVol();
	virtual ~M_NTS_GetFiveGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};


//���õ��������ŵ������ѹ
class M_NTS_SetSixGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetSixGAOutputVol();
	virtual ~M_NTS_SetSixGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//��ȡ���������ŵ������ѹ
class M_NTS_GetSixGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetSixGAOutputVol();
	virtual ~M_NTS_GetSixGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};

//���õ��߼����ŵ������ѹ
class M_NTS_SetSevenGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetSevenGAOutputVol();
	virtual ~M_NTS_SetSevenGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//��ȡ���߼����ŵ������ѹ
class M_NTS_GetSevenGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetSevenGAOutputVol();
	virtual ~M_NTS_GetSevenGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};

//���õڰ˼����ŵ������ѹ
class M_NTS_SetEightGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetEightGAOutputVol();
	virtual ~M_NTS_SetEightGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//��ȡ�ڰ˼����ŵ������ѹ
class M_NTS_GetEightGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetEightGAOutputVol();
	virtual ~M_NTS_GetEightGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};

//���õھż����ŵ������ѹ
class M_NTS_SetNineGAOutputVol:public BaseMethod
{
public:
	M_NTS_SetNineGAOutputVol();
	virtual ~M_NTS_SetNineGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//��ȡ�ھż����ŵ������ѹ
class M_NTS_GetNineGAOutputVol:public BaseMethod
{
public:
	M_NTS_GetNineGAOutputVol();
	virtual ~M_NTS_GetNineGAOutputVol();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};


//��ȡͨ���ĵ���ֵ(��λ:bit)
class M_NTS_GetCurrent:public BaseMethod
{
public:
	M_NTS_GetCurrent();
	virtual ~M_NTS_GetCurrent();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara;
};
//����ͨ���������޵���ֵ(��λ:bit)
class M_NTS_SetCurrentLimited:public BaseMethod
{
public:
	M_NTS_SetCurrentLimited();
	virtual ~M_NTS_SetCurrentLimited();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2, m_InputPara3;
};
//��ȡͨ���������޵���ֵ(��λ:bit)
class M_NTS_GetCurrentLimited:public BaseMethod
{
public:
	M_NTS_GetCurrentLimited();
	virtual ~M_NTS_GetCurrentLimited();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1, m_OutputPara2;
};
//��ȡ�澯��Ϣ
class M_NTS_GetIsWarning:public BaseMethod
{
public:
	M_NTS_GetIsWarning();
	virtual ~M_NTS_GetIsWarning();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara;
};
//����澯��Ϣ
class M_NTS_ClearWarning:public BaseMethod
{
public:
	M_NTS_ClearWarning();
	virtual ~M_NTS_ClearWarning();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

//��ȡ��Ʒ������Ϣ
class M_NTS_GetIDN:public BaseMethod
{
public:
	M_NTS_GetIDN();
	virtual ~M_NTS_GetIDN();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
	TParamSetStruct m_OutputPara2;
};

//class M_NTS_SendCmd ����ָ��
class M_NTS_SendCmd:public BaseMethod
{
public:
	M_NTS_SendCmd();
	virtual ~M_NTS_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_NTS_GetCmd ����ָ���ȡָ��ķ�������
class M_NTS_GetCmd:public BaseMethod
{
public:
	M_NTS_GetCmd();
	virtual ~M_NTS_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
};

// M_NTS_SetStartAndStopRAM ����ģ��RAM��ֹ��ַ������
class M_NTS_SetStartAndStopRAM:public BaseMethod
{
public:
	M_NTS_SetStartAndStopRAM();
	virtual ~M_NTS_SetStartAndStopRAM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[4];		
};


// M_NTS_SetStarAndStopFlash ����ģ��FLASH��ֹ��ַ������
class M_NTS_SetStarAndStopFlash:public BaseMethod
{
public:
	M_NTS_SetStarAndStopFlash();
	virtual ~M_NTS_SetStarAndStopFlash();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[4];		
};


//M_NTS_GetStarAndStopFlash ��ȡģ��FLAST��ֹ��ַ������
class M_NTS_GetStarAndStopFlash:public BaseMethod
{
public:
	M_NTS_GetStarAndStopFlash();
	virtual ~M_NTS_GetStarAndStopFlash();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[3];
	TParamSetStruct m_OutputPara1;
};

// M_NTS_SetStarAndStopEEPROM ������ֹ��ַ��RRPROM����
class M_NTS_SetStarAndStopEEPROM:public BaseMethod
{
public:
	M_NTS_SetStarAndStopEEPROM();
	virtual ~M_NTS_SetStarAndStopEEPROM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[3];		
};

//M_NTS_GetStarAndStopEEPROM ��ȡ��ֹ��ַ��RRPROM����
class M_NTS_GetStarAndStopEEPROM:public BaseMethod
{
public:
	M_NTS_GetStarAndStopEEPROM();
	virtual ~M_NTS_GetStarAndStopEEPROM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[2];
	TParamSetStruct m_OutputPara1;
};

// class M_NTS_SetCRC дEEPROM���߲�����У����
class M_NTS_SetCRC:public BaseMethod
{
public:
	M_NTS_SetCRC();
	virtual ~M_NTS_SetCRC();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
};

// M_NTS_SetPID ���õ������Բ���
class M_NTS_SetPID:public BaseMethod
{
public:
	M_NTS_SetPID();
	virtual ~M_NTS_SetPID();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[4];
};

// M_NTS_SetGainWorkPara ���ù��ŵľ�̬��������
class M_NTS_SetGainWorkPara:public BaseMethod
{
public:
	M_NTS_SetGainWorkPara();
	virtual ~M_NTS_SetGainWorkPara();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[6];
};

// M_NTS_GainDebug �ڵ������µ��Ե������ŵľ�̬��������
class M_NTS_GainDebug:public BaseMethod
{
public:
	M_NTS_GainDebug();
	virtual ~M_NTS_GainDebug();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[5];
	TParamSetStruct m_OutputPara[2];
};

// M_NTS_GetVoltage ��ȡͨ���ĵ�ѹ(��λ:bit)
class M_NTS_GetVoltage:public BaseMethod
{
public:
	M_NTS_GetVoltage();
	virtual ~M_NTS_GetVoltage();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1;
};

// M_NTS_SetActiveObject ���õ�ǰ��Ҫ��صĶ���(Type 1:���� 2:��ѹ Index 1:�ƶ���/28V 2:ĩ��/5V 3:Peak 4:peak2)
class M_NTS_SetActiveObject:public BaseMethod
{
public:
	M_NTS_SetActiveObject();
	virtual ~M_NTS_SetActiveObject();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;
};
