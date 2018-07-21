/************************************************************************
* Copyright (c) 2009,оͨ�Ƽ����޹�˾
* All rights reserved.
* �ļ����ƣ�T1440DTDPDDriver.h
* �ļ���ʶ��reserved
* ժҪ��This class is exported from the DPDDriver.dll
*
************************************************************************/

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the DPDDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// DPDDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef DPDDRIVER_EXPORTS
#define DPDDRIVER_API __declspec(dllexport)
#else
#define DPDDRIVER_API __declspec(dllimport)
#endif

/************************************************************************
* �汾��2.0.1.2
* ���ߣ�dolby.jiang
* ������ڣ�2009��9��4��
* ���ģ�����GetIDN����
*
************************************************************************/

/************************************************************************
* �汾��2.0.1.3
* ���ߣ�dolby.jiang
* ������ڣ�2009��9��23��
* ���ģ�����DPD_SetTwelvePwrFpg����
*
************************************************************************/

/************************************************************************
* �汾��2.0.1.4
* ���ߣ�dolby.jiang
* ������ڣ�2009��11��23��
* ���ģ�1���޸Ĵ򿪺��� 
2������	DPD_SendCmd DPD_GetCmd����
*
************************************************************************/


/************************************************************************
* �汾��2.0.0.5
* ���ߣ�dolby.jiang
* ������ڣ�2010��3��23��
* ���ģ�
1 ���� SetCFR
2 ���� GetCFR
*
************************************************************************/
#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

	//�򿪲���ʼ���豸
	DPDDRIVER_API short int	_stdcall	DPD_OpenDev(char *protocol, short int *Handle);

	//�ر��豸
	DPDDRIVER_API short int	_stdcall	DPD_CloseDev(short int Handle);

	//����
	DPDDRIVER_API short int	_stdcall	DPD_Reboot(short int Handle);

	//DPD�帴λ
	DPDDRIVER_API short int	_stdcall	DPD_Reset(short int Handle);

	//����DPD����״̬(0:�� 1:��)
	DPDDRIVER_API short int	_stdcall	DPD_SetDPDState(short int Handle,short int State);

	//���÷���ͨ��˥��ֵ
	DPDDRIVER_API short int	_stdcall	DPD_SetTxAtten(short int Handle, int Atten);

	//���÷���ͨ��˥��ֵ
	DPDDRIVER_API short int	_stdcall	DPD_SetRDAtten(short int Handle, int Atten);

	//��ȡƫ���
	DPDDRIVER_API short int	_stdcall	DPD_GetErrPower(short int Handle,float *Power);

	//����6�ز���������
	DPDDRIVER_API short int	_stdcall	DPD_SetSixPwrFpg(short int Handle);

	//����9�ع��ʲ�����
	DPDDRIVER_API short int	_stdcall	DPD_SetNinePwrFpg(short int Handle);

	//����12�ع��ʲ�����
	DPDDRIVER_API short int	_stdcall	DPD_SetTwelvePwrFpg(short int Handle);
	
	//DPDƫ��ʵ���
	DPDDRIVER_API short int	_stdcall	DPD_SetErrPwrDebug(short int Handle, float ErrPower, float *RealErrPwr);

	//��ȡ����ͨ��˥��ֵ
	DPDDRIVER_API short int	_stdcall	DPD_GetTxAtten(short int Handle,int *Atten);

	//��ȡ����ͨ��˥��ֵ
	DPDDRIVER_API short int	_stdcall	DPD_GetRDAtten(short int Handle,int *Atten);

	//����DPD�������
	DPDDRIVER_API short int	_stdcall	DPD_SetRFOutPower(short int Handle,int Power);

	//��ȡDPD�������
	DPDDRIVER_API short int	_stdcall	DPD_GetRFOutPower(short int Handle,int *Power);

	//����DPD����Ƶ��(1: BƵ�� 2: AƵ�� 3:875/930/1810  4:880/946.8/1830  5:885/955/1855
	//6:1830 7:1850 8:1875  9:1910 10:1890 )
	DPDDRIVER_API short int	_stdcall	DPD_SetWorkFreq(short int Handle,int FreqMode);

	//����DPD��IP��ַ
	DPDDRIVER_API short int	_stdcall	DPD_SetIP(short int Handle,int IP_Add_1,int IP_Add_2);

	//�������TX��·ϸ������ֵ
	DPDDRIVER_API short int	_stdcall	DPD_SetSmallTxAtten(short int Handle,double Atten);

	//��ȡ���TX��·ϸ������ֵ
	DPDDRIVER_API short int	_stdcall	DPD_GetSmallTxAtten(short int Handle,double *Atten);

	//����DPD�ź�ģʽ(0:GMSK  1:8PSK 2:GMSK+8PSK)
	DPDDRIVER_API short int	_stdcall	DPD_SetSGMode(short int Handle,int Mode);

	//����DPD�ز�ģʽ	
	/* Mode : 0:3M�ȼ��	1:3M���ȼ��	2:5M�ȼ��	3:5M���ȼ��  
	4:10M�ȼ��	5:10M���ȼ��	6:15M�ȼ�� 7:15M���ȼ�� 
	*/ 
	DPDDRIVER_API short int	_stdcall	DPD_SetCarriedMode(short int Handle,int Mode);

	//�����ز�����(0:3�ز�	1:4�ز�	2:6�ز�)
	DPDDRIVER_API short int	_stdcall	DPD_SetCarriedCount(short int Handle,int Count);
		
	//��ȡ������Ϣ
	DPDDRIVER_API short int	_stdcall	DPD_GetIDN(short int Handle, char *IDN);

	//����ָ��
	DPDDRIVER_API	short int _stdcall	DPD_SendCmd(short int Handle, char *Command);
	
	//��ȡ����ָ��ֵ
	DPDDRIVER_API	short int _stdcall	DPD_GetCmd(short int Handle, char *Command, char *RetStr);
	
	// ����CFR����ֵ
	DPDDRIVER_API short int	_stdcall	DPD_SetCFR(short int Handle, unsigned int CfrValue);
	
	// ��ȡCFR����ֵ
	DPDDRIVER_API short int	_stdcall	DPD_GetCFR(short int Handle, unsigned int *CfrValue);
	
	// ��ȡ�豸��������
	DPDDRIVER_API short int _stdcall	DPD_ReadDev(short int Handle, char *RetSrt, int ReadCount, int *RealCount);
	
	
#pragma pack()
	
#ifdef __cplusplus
}
#endif