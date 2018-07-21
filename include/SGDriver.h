/************************************************************************
* Copyright (c) 2009,оͨ�Ƽ����޹�˾
* All rights reserved.
* �ļ����ƣ�SGDriver.h
* �ļ���ʶ��reserved
* ժҪ��SGDriver.dll���ⲿ�ӿ��ļ�
*
************************************************************************/

// The following ifdef block is the standard way of creating macros whiCh make exporting 
// from a DLL simpler. All files within this DLL are compiled with the SGDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// SGDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef SGDRIVER_EXPORTS
#define SGDRIVER_API __declspec(dllexport)
#else
#define SGDRIVER_API __declspec(dllimport)
#endif

#pragma warning(disable:4786)
/************************************************************************
* �汾��2.0.1.0
* ���ߣ�dolby.jiang
* ������ڣ�2009��9��24��
* ���ģ��ļ�����
*
************************************************************************/

/************************************************************************
* �汾��2.0.1.1
* ���ߣ�dolby.jiang
* ������ڣ�2009��11��23��
* ���ģ��޸Ĵ򿪺���
*
************************************************************************/


/************************************************************************
* �汾��3.0.0.0
* ���ߣ�dolby.jiang
* ������ڣ�2010��5��13��
* ���ģ��޸ľ�����㷽��
*
************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
	
	//�򿪲���ʼ���豸
	SGDRIVER_API short int	_stdcall	SG_OpenDev(char *ConnectStr, short int *Handle);

	//�ر��豸
	SGDRIVER_API short int	_stdcall	SG_CloseDev(short int Handle);

	//������λ
	SGDRIVER_API short int	_stdcall	SG_Reset(short int Handle);

	//�����źŲ����ļ�
	SGDRIVER_API short int	_stdcall	SG_SetWaveFile(short int Handle, char *WaveName);

	//���ò����ļ���״̬
	SGDRIVER_API short int	_stdcall	SG_SetArbWaveState(short int Handle, unsigned short State);

	//��������Ƶ��
	SGDRIVER_API short int	_stdcall	SG_SetRFFreq(short int Handle, double Freq);

	//���÷���ֵ
	SGDRIVER_API short int	_stdcall	SG_SetRFAmplitu(short int Handle, double Level);

	//��ȡ����ֵ
	SGDRIVER_API short int	_stdcall	SG_GetRFAmplitu(short int Handle, double *Level);

	//���÷���ƫ��ֵ
	SGDRIVER_API short int	_stdcall	SG_SetRFAmplituOffset(short int Handle, double Level);

	//�����źŽ��״̬(0:off 1:on)
	SGDRIVER_API short int	_stdcall	SG_SetIQModulationState(short int Handle, unsigned short State);
	
	//�����ź�Դ�ź����״̬(0:off 1:on)
	SGDRIVER_API short int	_stdcall	SG_SetRFPowerOnState(short int Handle, unsigned short State);

	//����ɨ�����
	SGDRIVER_API short int	_stdcall	SG_SetSweepPoint(short int Handle, unsigned long Point);

	//����ɨ�败��ģʽ 
	SGDRIVER_API short int	_stdcall	SG_SetSweepTriMode(short int Handle, unsigned short TrigMode);

	//�����ź�Դɨ��ʼֹƵ��
	SGDRIVER_API short int	_stdcall	SG_SetStartandStopFreq(short int Handle, double StartFreq, double StopFreq);

	//�����ź�Դɨ��ģʽ
	SGDRIVER_API short int	_stdcall	SG_SetSweepMode(short int Handle,  unsigned short Mode);

	//�����ź�ԴMarkģʽ 0:Unchanged 1:Restart 2:pulse 3:pattern 4:on/off Ratio
	SGDRIVER_API short int	_stdcall	SG_SetARBMarkMode(short int Handle, short Channel, unsigned short Mode);

	//�����ź�ԴMarkģʽ 0:Unchanged 1:Restart 2:pulse 3:pattern 4:on/off Ratio
	SGDRIVER_API short int	_stdcall	SG_SetCwCarrier(short int Handle, double frequency, int mode);
	
	//�����ź�ԴƵ��ƫ��������λ:MHz��
	SGDRIVER_API short int	_stdcall	SG_SetFreqOffset(short int Handle, double FreqOffset);
	
	//�����ź�ԴMark�ӳ�ʱ��
	SGDRIVER_API short int	_stdcall	SG_SetARBMarkDelay(short int Handle, short Channel, double DelayTime);

	//�����ź�Դ������������ 0:FREE 1:TRIGger 2:RESet
	SGDRIVER_API short int	_stdcall	SG_SetTrigInContinuousType(short int Handle, unsigned short Type);

	//�����ź�Դ����Դ���� 0:KEY 1:EXT 2:BUS
	SGDRIVER_API short int	_stdcall	SG_SetTrigInSourceType(short int Handle, unsigned short Type);

	//�����ź�Դ�������� 0:POSitive 1:NEGative
	SGDRIVER_API short int	_stdcall	SG_SetTrigInPolarity(short int Handle, unsigned short Polarity);

	//�����ź�Դ�����ӳ�ʱ��(��λ:ms)
	SGDRIVER_API short int	_stdcall	SG_SetTrigInDelay(short int Handle, double DelayTime);

	//�����ź�ԴMarker ALC Holdֵ 0:NONE 1:M1 2:M2 3:M3 4:M4
	SGDRIVER_API short int	_stdcall	SG_SetMarkerALCHold(short int Handle, unsigned short Marker);

	//�����ź�Դ��ƽ ALC״̬ 0:Off 1:On 
	SGDRIVER_API short int	_stdcall	SG_SetAmpALCMode(short int Handle, unsigned short Mode);

	//����ʱ��Ƶ��(��λ:MHz)
	SGDRIVER_API short int	_stdcall	SG_SetClockFreq(short int Handle, double Freq);

	//���ù��ʼ�ⷽʽ(0:Normal 1:Minimum)
	SGDRIVER_API short int	_stdcall	SG_SetRFPowerSearchMode(short int Handle, short Mode);

	//��ȡ�豸�ͺ���Ϣ
	SGDRIVER_API	short int _stdcall	SG_GetIDN(short int Handle, char *IDN);
	
	//����ָ��
	SGDRIVER_API	short int _stdcall	SG_SendCmd(short int Handle, char *Command);
	
	//��ȡ����ָ��ֵ
	SGDRIVER_API	short int _stdcall	SG_GetCmd(short int Handle, char *Command, char *RetStr);
		
#ifdef __cplusplus
}
#endif

