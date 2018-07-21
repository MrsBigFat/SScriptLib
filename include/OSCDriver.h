/************************************************************************
* Copyright (c) 2009,оͨ�Ƽ����޹�˾
* All rights reserved.
* �ļ����ƣ�OSCDriver.h
* �ļ���ʶ��reserved
* ժҪ��OSCDriver.dll���ⲿ�ӿ��ļ�
*
************************************************************************/

// The following ifdef block is the standard way of creating macros whiCh make exporting 
// from a DLL simpler. All files within this DLL are compiled with the OSCDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// OSCDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef OSCDRIVER_EXPORTS
#define OSCDRIVER_API __declspec(dllimport)
#else
#define OSCDRIVER_API __declspec(dllexport)
#endif

#pragma warning(disable:4786)
/************************************************************************
* �汾��2.0.1.0
* ���ߣ�dolby.jiang
* ������ڣ�2009��8��26��
* ���ģ��ļ�����
*
************************************************************************/

/************************************************************************
* �汾��2.0.1.1
* ���ߣ�dolby.jiang
* ������ڣ�2009��9��23��
* ���ģ������ֶ�����ACPR�ķ����ӿ�
*
************************************************************************/


/************************************************************************
* �汾��2.0.1.2
* ���ߣ�dolby.jiang
* ������ڣ�2009��9��25��
* ���ģ��޸�SetMeasNoiseBW�ӿ�
*
************************************************************************/


/************************************************************************
* �汾��2.0.1.3
* ���ߣ�dolby.jiang
* ������ڣ�2009��9��30��
* ���ģ��޸ĺ�������λ��
*
************************************************************************/


/************************************************************************
* �汾��2.0.1.4
* ���ߣ�dolby.jiang
* ������ڣ�2009��11��23��
* ���ģ��޸Ĵ򿪺���
*
************************************************************************/

/************************************************************************
* �汾��3.0.0.0
* ���ߣ�dolby.jiang
* ������ڣ�2010��5��6��
* ���ģ�����OSC_SetSweepPoint
*
************************************************************************/


/************************************************************************
* �汾��3.0.0.1
* ���ߣ�dolby.jiang
* ������ڣ�2011��5��10��
* ���ģ�
1 ���� OSC_SaveTraceByName
2 ���� OSC_SetTraceMathTypeByName
3 ���� OSC_DeleteTraceByName
4 ���� OSC_DeleteAllTrace
5 ���� OSC_SetMarkerSearchFreqByName
6 ���� OSC_GetMarkerValueByName
7 ���� OSC_GetFluctuateByName
8 ���� OSC_GetMarkerFreqByName
*
************************************************************************/

/************************************************************************
* �汾��3.0.0.7
* ���ߣ�dolby.jiang
* ������ڣ�2011��8��5��
* ���ģ�
1 ���� OSC_GetTraceDataXByName
2 ���� OSC_GetTraceDataYByName
*
************************************************************************/


/************************************************************************
* �汾��3.0.0.8
* ���ߣ�dolby.jiang
* ������ڣ�2011��9��9��
* ���ģ�
1 ���� Vsa 89600 Method
*
************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
	
	//�򿪲���ʼ���豸
	OSCDRIVER_API short int	_stdcall	OSC_OpenDev(char *ConnectStr, short int *Handle);

	//�ر��豸
	OSCDRIVER_API short int	_stdcall	OSC_CloseDev(short int Handle);

	//������λ	
	OSCDRIVER_API short int	_stdcall	OSC_Reset(short int Handle);

	//����Dtime@levelģʽ����
	OSCDRIVER_API short int	_stdcall	OSC_SetDTLEVParam(short int Handle,short int Pos,short int Channel1,short int Slope1,double AbsLev1,short int Channel2,short int Slope2,double AbsLev2);
	
	//����Grid	
	OSCDRIVER_API short int	_stdcall	OSC_SetGrid(short int Handle,short int gridType);

	//����Trig����
	OSCDRIVER_API short int	_stdcall	OSC_SetTrigType(short int Handle, short int trigType, short int source);

	//����TrigCoupling
	OSCDRIVER_API short int	_stdcall	OSC_SetTrigCoupling(short int Handle,short int source, short int coupling);

	//����TrigSlope
	OSCDRIVER_API short int	_stdcall	OSC_SetTrigSlope(short int Handle,short int source, short int Slope);

	//����TrigLevel
	OSCDRIVER_API short int	_stdcall	OSC_SetTrigLevel(short int Handle,short int source, double level);

	//����Vertical Scale
	OSCDRIVER_API short int	_stdcall	OSC_SetScaleVDIV(short int Handle,short int channel, double vdiv);

	//����Timebase Scale
	OSCDRIVER_API short int	_stdcall	OSC_SetScaleTDIV(short int Handle, double tdiv);

	//��ȡDTLֵ
	OSCDRIVER_API short int	_stdcall	OSC_GetMeaValue(short int Handle, short int point, char *dtlvalue);

	//����Trig Mode
	OSCDRIVER_API short int	_stdcall	OSC_SetTrigMode(short int Handle, short int mode);
	
	//Getcmd
	OSCDRIVER_API short int _stdcall	OSC_GetCmd(short int Handle, char *Command, char *RetStr);

	//Sendcmd
	OSCDRIVER_API short int _stdcall	OSC_SendCmd(short int Handle, char *Command);

	//����DeltaDelayģʽ����
	OSCDRIVER_API short int _stdcall	OSC_SetDeltaDelay(short int Handle, short int Pos, short int source1, short int source2);

	//����Trace��ʾ
	OSCDRIVER_API short int _stdcall	OSC_SetTraceDis(short int Handle, short int channel, short int Switch);

#ifdef __cplusplus
}
#endif























