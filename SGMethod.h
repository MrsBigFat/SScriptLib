#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"

//#include ".\include\SGDriver.h"
//#pragma comment(lib,".\\lib\\SGDriver.lib")


//typedef std::vector<TParamSetStruct> TParamSetStructVector;

/************************************************************************
* �汾��2.0.0.45
* ���ߣ�dolby.jiang
* ������ڣ�2009��10��10��
* ���ģ�
*
************************************************************************/

/************************************************************************/
/*  �ź�Դ�������򷽷���                                                                    */
/************************************************************************/

//class M_SG_Reset �ź�Դ�豸��λ
class M_SG_Reset: public BaseMethod
{
public:
	M_SG_Reset();
	virtual ~M_SG_Reset();
	virtual int Run(void);
	virtual int Init(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//M_SG_SetWaveFile�����ź�Դ�����ļ�
class M_SG_SetWaveFile: public BaseMethod
{
public:
	M_SG_SetWaveFile();
	virtual ~M_SG_SetWaveFile();
	virtual int Run(void);
	virtual int Init(void);	
protected:
	TParamSetStruct m_InputPara, m_InputDeviceName;
};
//M_SG_SetArbWaveState ���ò����ļ�״̬
class M_SG_SetArbWaveState:public BaseMethod
{
public:
	M_SG_SetArbWaveState();
	virtual ~M_SG_SetArbWaveState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara, m_InputDeviceName;
};

//M_SG_SetRFFreq���òο�Ƶ��ֵ
class M_SG_SetRFFreq:public BaseMethod
{
public:
	M_SG_SetRFFreq();
	virtual ~M_SG_SetRFFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetRFAmplitu�����ź�Դ����ֵ
class M_SG_SetRFAmplitu:public BaseMethod
{
public:
	M_SG_SetRFAmplitu();
	virtual ~M_SG_SetRFAmplitu();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_GetRFAmplitu��ȡ�ź�Դ����ֵ
class M_SG_GetRFAmplitu:public BaseMethod
{
public:
	M_SG_GetRFAmplitu();
	virtual ~M_SG_GetRFAmplitu();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_OutputPara;
};
//M_SG_SetRFAmplituOffset�����ź�Դ����ƫ��ֵ
class M_SG_SetRFAmplituOffset:public BaseMethod
{
public:
	M_SG_SetRFAmplituOffset();
	virtual ~M_SG_SetRFAmplituOffset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetIQModulationState�����ź�Դ���״̬
class M_SG_SetIQModulationState:public BaseMethod
{
public:
	M_SG_SetIQModulationState();
	virtual ~M_SG_SetIQModulationState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetRFPowerOnState�����ź�Դ���״̬
class M_SG_SetRFPowerOnState:public BaseMethod
{
public:
	M_SG_SetRFPowerOnState();
	virtual ~M_SG_SetRFPowerOnState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetSweepPoint�����ź�Դɨ�����
class M_SG_SetSweepPoint:public BaseMethod
{
public:
	M_SG_SetSweepPoint();
	virtual ~M_SG_SetSweepPoint();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
		
};
//M_SG_SetSweepTriMode�����ź�Դɨ�败����ʽ
class M_SG_SetSweepTriMode:public BaseMethod
{
public:
	M_SG_SetSweepTriMode();
	virtual ~M_SG_SetSweepTriMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetStartandStopFreq�����ź�Դɨ����ʼƵ�ʺͽ�ֹƵ��
class M_SG_SetStartandStopFreq:public BaseMethod
{
public:
	M_SG_SetStartandStopFreq();
	virtual ~M_SG_SetStartandStopFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara1,m_InputPara2;
};
//M_SG_SetSweepMode����ɨ��ģʽ
class M_SG_SetSweepMode:public BaseMethod
{
public:
	M_SG_SetSweepMode();
	virtual ~M_SG_SetSweepMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetARBMarkMode �����ź�ԴMarkģʽ
class M_SG_SetARBMarkMode:public BaseMethod
{
public:
	M_SG_SetARBMarkMode();
	virtual ~M_SG_SetARBMarkMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara1,m_InputPara2;
};
//M_SG_SetFreqOffset �����ź�ԴƵ��ƫ����
class M_SG_SetFreqOffset:public BaseMethod
{
public:
	M_SG_SetFreqOffset();
	virtual ~M_SG_SetFreqOffset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetMarkDelay �����ź�ԴMark�ӳ�ʱ��
class M_SG_SetARBMarkDelay:public BaseMethod
{
public:
	M_SG_SetARBMarkDelay();
	virtual ~M_SG_SetARBMarkDelay();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara1,m_InputPara2;
};
//M_SG_SetTrigInContinuousType �����ź�Դ������������ 0:FREE 1:TRIGger 2:RESet
class M_SG_SetTrigInContinuousType:public BaseMethod
{
public:
	M_SG_SetTrigInContinuousType();
	virtual ~M_SG_SetTrigInContinuousType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetTrigInSourceType �����ź�Դ����Դ���� 0:KEY 1:EXT 2:BUS
class M_SG_SetTrigInSourceType:public BaseMethod
{
public:
	M_SG_SetTrigInSourceType();
	virtual ~M_SG_SetTrigInSourceType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
// M_SG_SetTrigInPolarity �����ź�Դ�������� 0:POSitive 1:NEGative
class M_SG_SetTrigInPolarity:public BaseMethod
{
public:
	M_SG_SetTrigInPolarity();
	virtual ~M_SG_SetTrigInPolarity();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
// M_SG_SetTrigInDelay �����ź�Դ�����ӳ�ʱ��(��λ:ms)
class M_SG_SetTrigInDelay:public BaseMethod
{
public:
	M_SG_SetTrigInDelay();
	virtual ~M_SG_SetTrigInDelay();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
// M_SG_SetMarkerALCHold �����ź�ԴMarker ALC Holdֵ 0:NONE 1:M1 2:M2 3:M3 4:M4
class M_SG_SetMarkerALCHold:public BaseMethod
{
public:
	M_SG_SetMarkerALCHold();
	virtual ~M_SG_SetMarkerALCHold();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};
//M_SG_SetAmpALCMode �����ź�Դ��ƽ ALC״̬ 0:Off 1:On 
class M_SG_SetAmpALCMode:public BaseMethod
{
public:
	M_SG_SetAmpALCMode();
	virtual ~M_SG_SetAmpALCMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};

//M_SG_SetClockFreq ����ʱ��Ƶ��(��λ:MHz)
class M_SG_SetClockFreq:public BaseMethod
{
public:
	M_SG_SetClockFreq();
	virtual ~M_SG_SetClockFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};

//M_SG_SetRFPowerSearchMode ���ù��ʼ�ⷽʽ(0:Normal 1:Minimum)
class M_SG_SetRFPowerSearchMode:public BaseMethod
{
public:
	M_SG_SetRFPowerSearchMode();
	virtual ~M_SG_SetRFPowerSearchMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName,m_InputPara;
};

//class M_SG_SendCmd ����ָ��
class M_SG_SendCmd:public BaseMethod
{
public:
	M_SG_SendCmd();
	virtual ~M_SG_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_SG_GetCmd ����ָ���ȡָ��ķ�������
class M_SG_GetCmd:public BaseMethod
{
public:
	M_SG_GetCmd();
	virtual ~M_SG_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
};


//class M_SG_GetIDN ��ȡ�豸�ͺ���Ϣ
class M_SG_GetIDN:public BaseMethod
{
public:
	M_SG_GetIDN();
	virtual ~M_SG_GetIDN();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};
//class M_SG_SetCwCarrier ��ȡ�豸�ͺ���Ϣ
class M_SG_SetCwCarrier :public BaseMethod
{
public:
	M_SG_SetCwCarrier();
	virtual ~M_SG_SetCwCarrier();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName, m_InputPara1, m_InputPara2;
};
