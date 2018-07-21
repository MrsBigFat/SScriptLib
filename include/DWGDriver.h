/************************************************************************
* Copyright (c) 2009,оͨ�Ƽ����޹�˾
* All rights reserved.
* �ļ����ƣ�DWGDriver.h
* �ļ���ʶ��reserved
* ժҪ��DWGDriver.dll���ⲿ�ӿ��ļ�
*
************************************************************************/

// The following ifdef block is the standard way of creating macros whiCh make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DWGDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DWGDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef DWGDRIVER_EXPORTS
#define DWGDRIVER_API __declspec(dllimport)
#else
#define DWGDRIVER_API __declspec(dllexport)
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
* ���ģ�����DWG_SetSweepPoint
*
************************************************************************/


/************************************************************************
* �汾��3.0.0.1
* ���ߣ�dolby.jiang
* ������ڣ�2011��5��10��
* ���ģ�
1 ���� DWG_SaveTraceByName
2 ���� DWG_SetTraceMathTypeByName
3 ���� DWG_DeleteTraceByName
4 ���� DWG_DeleteAllTrace
5 ���� DWG_SetMarkerSearchFreqByName
6 ���� DWG_GetMarkerValueByName
7 ���� DWG_GetFluctuateByName
8 ���� DWG_GetMarkerFreqByName
*
************************************************************************/

/************************************************************************
* �汾��3.0.0.7
* ���ߣ�dolby.jiang
* ������ڣ�2011��8��5��
* ���ģ�
1 ���� DWG_GetTraceDataXByName
2 ���� DWG_GetTraceDataYByName
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
	DWGDRIVER_API short int	_stdcall	DWG_OpenDev(char *ConnectStr, short int *Handle);

	//�ر��豸
	DWGDRIVER_API short int	_stdcall	DWG_CloseDev(short int Handle);

	//������λ	
	DWGDRIVER_API short int	_stdcall	DWG_Reset(short int Handle);

	//��ȡIDN������Ϣ
	DWGDRIVER_API short int	_stdcall	DWG_GetIDN(short int Handle, char *IDN);

	//��ȡ�ļ�
	DWGDRIVER_API short int	_stdcall	DWG_LoadFile(short int Handle, char *FileName);

	//��������
	DWGDRIVER_API short int	_stdcall	DWG_SendCmd(short int Handle, char *Command);

	//��ȡ�����ֵ
	DWGDRIVER_API short int	_stdcall	DWG_GetCmd(short int Handle, char *Command, char *RetStr);

	//����ͨ������
	DWGDRIVER_API short int	_stdcall	DWG_SetCHSwitch(short int Handle, short int channel, short int select);

	//�����ܿ���
	DWGDRIVER_API short int	_stdcall	DWG_SetAllSwitch(short int Handle, short int select);

	//���õ�ƽ
	DWGDRIVER_API short int	_stdcall	DWG_SetAmpLevel(short int Handle, double level);
	
#ifdef __cplusplus
}
#endif























