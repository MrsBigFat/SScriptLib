#pragma warning( disable : 4786)

/************************************************************************
* Copyright (c) 2009,оͨ�Ƽ����޹�˾
* All rights reserved.
* �ļ����ƣ�NTSProducts.h
* �ļ���ʶ��reserved
* ժҪ��This class is exported from the NTSProducts.dll
*
************************************************************************/

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NTSProducts_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NTSPRODUCTS_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifndef __NTSPRODUCTS_H__
#define __NTSPRODUCTS_H__

//Version 1.0
#define __NTSPRODUCTS_H_VERSION 0x0001

#ifdef NTSPRODUCTS_EXPORTS
#define NTSPRODUCTS_API __declspec(dllimport)
#else
#define NTSPRODUCTS_API __declspec(dllexport)
#endif

/************************************************************************
* �汾��2.0.1.0
* ���ߣ�dolby.jiang
* ������ڣ�2009��9��8��
* ���ģ�����NTS_GetIDN����̬��ȡ��Ʒ��֧�ֵķ���
*
************************************************************************/

/************************************************************************
* �汾��2.0.1.1
* ���ߣ�dolby.jiang
* ������ڣ�2009��9��8��
* ���ģ�����NTS_SendCmd\NTS_GetCmd����
*
************************************************************************/


/************************************************************************
* �汾��2.0.1.3
* ���ߣ�dolby.jiang
* ������ڣ�2009��11��23��
* ���ģ�1)�޸Ĵ򿪺���
		2���޸ĺ�������λ��
*
************************************************************************/

/************************************************************************
* �汾��2.0.1.3
* ���ߣ�dolby.jiang
* ������ڣ�2009��11��24��
* ���ģ�1) ����NTS_SetCardStarAndStopFlash  NTS_GetCardStarAndStopFlash
*
************************************************************************/

/************************************************************************
* �汾��2.0.1.4
* ���ߣ�dolby.jiang
* ������ڣ�2009��12��29��
* ���ģ�1) ���� NTS_SetPID NTS_SetGainWorkPara  NTS_GainDebug
*
************************************************************************/

/************************************************************************
* �汾��2.0.1.6
* ���ߣ�dolby.jiang
* ������ڣ�2010��1��25��
* ���ģ�1) ���� NTS_SetCRC
*
************************************************************************/


/************************************************************************
* �汾��3.0.0.0
* ���ߣ�dolby.jiang
* ������ڣ�2010��5��13��
* ���ģ�1) �޸ľ�����㷽��
*
************************************************************************/


/************************************************************************
* �汾��3.0.0.1
* ���ߣ�dolby.jiang
* ������ڣ�2010��7��20��
* ���ģ�1) ���� NTS_GetPowerState ����
		2) ���� NTS_SetStartAndStopRAM ����
*
************************************************************************/


/************************************************************************
* �汾��3.0.0.3
* ���ߣ�dolby.jiang
* ������ڣ�2010��12��29��
* ���ģ�1) ���� NTS_GetVoltage ����
		2) ���� NTS_SetActiveObject ����
*
************************************************************************/


/************************************************************************
* �汾��3.0.0.4
* ���ߣ�dolby.jiang
* ������ڣ�2011��4��13��
* ���ģ�1) ���� NTS_SetFourGAOutputVol ����
		2) ���� NTS_GetFourGAOutputVol ����
*
************************************************************************/

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif
	
	//�򿪲���ʼ���豸
	NTSPRODUCTS_API short int	_stdcall	NTS_OpenDev(char *ConnectStr, short int *devHandle);

	//�ر��豸
	NTSPRODUCTS_API short int	_stdcall	NTS_CloseDev(short int Handle);
	
	//����ģ�鹦�ܺ�
//	NTSPRODUCTS_API short int _stdcall    NTS_SetModuleFuncNo(short int Handle, unsigned char ModFuncNo);

	//����ģ����
//	NTSPRODUCTS_API short int _stdcall    NTS_SetModuleNo(short int Handle, unsigned char ModNo);

	//����ͨ��������˥��ֵ
//	NTSPRODUCTS_API short int _stdcall    NTS_SetUpAtten(short int Handle, short ch, short *upData);

	//��ȡͨ��������˥��ֵ
//	NTSPRODUCTS_API short int _stdcall    NTS_GetUpAtten(short int Handle, short ch, short *upData);

	//����ͨ��������˥��ֵ
//	NTSPRODUCTS_API short int _stdcall    NTS_SetDownAtten(short int Handle, short ch, short *downData);

	//��ȡͨ��������˥��ֵ
//	NTSPRODUCTS_API short int _stdcall    NTS_GetDownAtten(short int Handle, short ch, short *downData);

	//��ȡͨ��������OPD
//	NTSPRODUCTS_API short int _stdcall    NTS_GetUpOpd(short int Handle, short ch, float *opdValue);

	//��ȡͨ��������OPD
//	NTSPRODUCTS_API short int _stdcall    NTS_GetDownOpd(short int Handle, short ch, float *opdValue);
	
	//��ȡͨ��������IPD
//	NTSPRODUCTS_API short int _stdcall    NTS_GetDownIpd(short int Handle, short ch, float *ipdValue);

	//��ȡģ������汾
	NTSPRODUCTS_API short int _stdcall    NTS_GetModuleVersion(short int Handle, char *version);

	//��ȡ���Կ�����汾
	NTSPRODUCTS_API short int _stdcall    NTS_GetCardVersion(short int Handle, char *version);

	//����ͨ�����¶Ȳ�������
	NTSPRODUCTS_API short int _stdcall    NTS_SetTmpCompensationData(short int Handle, short ch);

	//��ȡͨ�����¶Ȳ����¶ȴ��������¶�ֵ
	NTSPRODUCTS_API short int _stdcall    NTS_GetTmpCompensationSense(short int Handle, short ch, float *temperature);

	//���õ�һ�����ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_SetPushOutputVol(short int Handle, short ch, float temperature, unsigned short DAvalue);

	//��ȡ��һ�����ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_GetPushOutPutVol(short int Handle, short ch, float temperature, unsigned short *DAvalue);

	//���õڶ������ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_SetSecGAOutputVol(short int Handle, short ch, float temperature, unsigned short DAvalue);
	
	//��ȡ�ڶ������ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_GetSecGAOutputVol(short int Handle, short ch,float temperature,unsigned short *DAvalue);
	
	//���õ��������ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_SetThirdGAOutputVol(short int Handle, short ch,float temperature,unsigned short DAvalue);
	
	//��ȡ���������ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_GetThirdGAOutputVol(short int Handle, short ch, float temperature,unsigned short *DAvalue);
	
	//���õ��ļ����ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_SetFourGAOutputVol(short int Handle, short ch, float temperature, unsigned short DAvalue);
	
	//��ȡ���ļ����ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_GetFourGAOutputVol(short int Handle, short ch, float temperature, unsigned short *DAvalue);

	//���õ��弶���ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_SetFiveGAOutputVol(short int Handle, short ch,float temperature,unsigned short DAvalue);
	
	//��ȡ���弶���ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_GetFiveGAOutputVol(short int Handle, short ch,float temperature,unsigned short *DAvalue);
	
	//���õ��������ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_SetSixGAOutputVol(short int Handle, short ch,float temperature,unsigned short DAvalue);
	
	//��ȡ���������ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_GetSixGAOutputVol(short int Handle, short ch,float temperature,unsigned short *DAvalue);
	
	//���õ��߼����ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_SetSevenGAOutputVol(short int Handle, short ch,float temperature,unsigned short DAvalue);
	
	//��ȡ���߼����ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_GetSevenGAOutputVol(short int Handle, short ch,float temperature,unsigned short *DAvalue);
	
	//���õڰ˼����ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_SetEightGAOutputVol(short int Handle, short ch,float temperature,unsigned short DAvalue);
	
	//��ȡ�ڰ˼����ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_GetEightGAOutputVol(short int Handle, short ch,float temperature,unsigned short *DAvalue);
	
	//���õھż����ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_SetNineGAOutputVol(short int Handle, short ch,float temperature,unsigned short DAvalue);
	
	//��ȡ�ھż����ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_GetNineGAOutputVol(short int Handle, short ch,float temperature,unsigned short *DAvalue);
	
	//�������һ�����ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_SetLastOutputVol(short int Handle, short ch, float temperature, unsigned short DAvalue);

	//��ȡ���һ�����ŵ������ѹ
	NTSPRODUCTS_API short int _stdcall    NTS_GetLastOutputVol(short int Handle, short ch, float temperature, unsigned short *DAvalue);

	//����ģ�鹤��ģʽ�ͼ��ģʽ(0:OPD 1:RPD)
	NTSPRODUCTS_API short int _stdcall    NTS_SetWorkMode(short int Handle, unsigned short workmode, unsigned short detectormode);

	//��ȡģ�鹤��ģʽ�ͼ��ģʽ
	NTSPRODUCTS_API short int _stdcall    NTS_GetWorkMode(short int Handle, unsigned short *workmode, unsigned short *detectormode);

	//����1λPCB���뵽ģ��
	NTSPRODUCTS_API short int _stdcall    NTS_SetOneBytePCB(short int Handle, unsigned short index, short pcb);

	//��ȡ1λPCB����
	NTSPRODUCTS_API short int _stdcall    NTS_GetOneBytePCB(short int Handle, unsigned short index, short* pcb);

	//��������PCB���뵽FLASH
	NTSPRODUCTS_API short int _stdcall    NTS_SetPCB(short int Handle,BYTE *pcb);

	//��ȡ����PCB����
	NTSPRODUCTS_API short int _stdcall    NTS_GetPCB(short int Handle,BYTE *PCB, long *length);

	//��ģ��EEPROM��ĳ����ַд����
	NTSPRODUCTS_API short int _stdcall    NTS_SetEEPROM(short int Handle, unsigned int address, float data);

	//��ȡEEPROM��ĳ����ַ������
	NTSPRODUCTS_API short int _stdcall    NTS_GetEEPROM(short int Handle, unsigned int address, float *data);

	//���þ��󿪹ص�ģʽ
	NTSPRODUCTS_API short int _stdcall    NTS_SetSwtichMode(short int Handle, unsigned short k1, unsigned short k2, unsigned short k3, unsigned short k4);

	//����ģ�鹩����Դ״̬
	NTSPRODUCTS_API short int _stdcall    NTS_SetPowerState(short int Handle, unsigned short powerstate);

	//��ȡģ�鹩����Դ״̬
	NTSPRODUCTS_API short int _stdcall    NTS_GetPowerState(short int Handle, short *PowerState);
	

	//��ȡͨ�����¶�
	NTSPRODUCTS_API short int _stdcall    NTS_GetTemperature(short int Handle,short ch,float *temperature);

	//��ȡģ���פ����
	NTSPRODUCTS_API short int _stdcall    NTS_GetDownVSWR(short int Handle,short ch,float *vswrValue);

	//����ģ��ı���Ƶ��
	NTSPRODUCTS_API short int _stdcall    NTS_SetLOFreq(short int Handle,short ch,float freq);

	//��ȡģ��CPLD�汾��
	NTSPRODUCTS_API short int _stdcall    NTS_GetModuleCPLDVersion(short int Handle,char *version);

	//��ȡ���Կ�CPLD�汾��
	NTSPRODUCTS_API short int _stdcall    NTS_GetCardCPLDVersion(short int Handle,char *version);

	//����ģ��ͨ���Ĺ���ģʽ
	NTSPRODUCTS_API short int _stdcall    NTS_SetWorkModeEx(short int Handle, short ch, unsigned short workmode);

	//��ȡģ��ͨ���Ĺ���ģʽ
	NTSPRODUCTS_API short int _stdcall    NTS_GetWorkModeEx(short int Handle, short ch,	unsigned short *workmode);

	//����ģ��ͨ���ļ��ģʽ
	NTSPRODUCTS_API short int _stdcall    NTS_SetDetectorMode(short int Handle, short ch, unsigned short detectormode);

	//��ȡģ��ͨ���ļ��ģʽ
	NTSPRODUCTS_API short int _stdcall    NTS_GetDetectorMode(short int Handle, short ch, unsigned short *detectormode);

	//���þ��󿪹�״̬
	NTSPRODUCTS_API short int _stdcall    NTS_SetSwtichState(short int Handle,long count,short *state );

	//��ȡ���Կ���Ʒ��
	NTSPRODUCTS_API short int _stdcall    NTS_GetCardProductNo(short int Handle,short *productno);

	//��ȡģ��Ĳ�Ʒ��
	NTSPRODUCTS_API short int _stdcall    NTS_GetModuleProductNo(short int Handle,short *productno);

	//���õ������·ģʽ
	NTSPRODUCTS_API short int _stdcall    NTS_SetLanLinkMode(short int Handle,short ch,short mode);

	//����ָ��ͨ���Ĺ��ʼ��ʹ��״̬
	NTSPRODUCTS_API short int _stdcall    NTS_SetDectorState(short int Handle,short ch,short state);

	//������ֹ��ַ��RRPROM����
	NTSPRODUCTS_API short int _stdcall    NTS_SetStarAndStopEEPROM(short int Handle, unsigned int startaddress, long count, float *data);

	//��ȡ��ֹ��ַ��RRPROM����
	NTSPRODUCTS_API short int _stdcall    NTS_GetStarAndStopEEPROM(short int Handle, unsigned int startaddress, long count, float *data);

	//����ͨ��PK���¶�ϵ��
//	NTSPRODUCTS_API short int _stdcall    NTS_SetPKTCeof(short int Handle,short ch,float Vo ,float To, float *Coefficient);

	//��ȡͨ��PK���¶�ϵ��
//	NTSPRODUCTS_API short int _stdcall    NTS_GetPKTCeof(short int Handle,short ch,float *Vo ,float *To, float *Coefficient);

	//����ͨ��С��-40���ƶ�����դѹб��
//	NTSPRODUCTS_API short int _stdcall    NTS_SetPushLTCeof(short int Handle,short ch,int Coefficient);

	//��ȡͨ��С��-40���ƶ�����դѹб��
//	NTSPRODUCTS_API short int _stdcall    NTS_GetPushLTCeof(short int Handle,short ch,int  *Coefficient);

	//����ͨ��С��-40��ĩ����դѹб��
//	NTSPRODUCTS_API short int _stdcall    NTS_SetLastLTCeof(short int Handle,short ch,int  Coefficient);

	//��ȡͨ��С��-40��ĩ����դѹб��
//	NTSPRODUCTS_API short int _stdcall    NTS_GetLastLTCeof(short int Handle,short ch,int  *Coefficient);

	//����ͨ������87���ƶ�����դѹб��
//	NTSPRODUCTS_API short int _stdcall    NTS_SetPushHTCeof(short int Handle,short ch,int  Coefficient);

	//��ȡͨ������87���ƶ�����դѹб��
//	NTSPRODUCTS_API short int _stdcall    NTS_GetPushHTCeof(short int Handle,short ch,int  *Coefficient);

	//����ͨ������87��ĩ����դѹб��
//	NTSPRODUCTS_API short int _stdcall    NTS_SetLastHTCeof(short int Handle,short ch,int  Coefficient);

	//��ȡͨ������87��ĩ����դѹб��
//	NTSPRODUCTS_API short int _stdcall    NTS_GetLastHTCeof(short int Handle,short ch,int  *Coefficient);

	//����ͨ��PK���ο���ѹƫ����
//	NTSPRODUCTS_API short int _stdcall    NTS_SetPKVolOffset(short int Handle,short ch,short VolIndex,float StartVol, float StopVol,int VolOffset);
	
	//����ͨ���ƶ����ο���ѹƫ����
//	NTSPRODUCTS_API short int _stdcall    NTS_SetPushVolOffset(short int Handle,short ch,short VolIndex,float StartVol, float StopVol,int VolOffset);
	
	//����ͨ��ĩ���ο���ѹƫ����
//	NTSPRODUCTS_API short int _stdcall    NTS_SetLastVolOffset(short int Handle,short ch,short VolIndex,float StartVol, float StopVol,int VolOffset);
	
	//��ȡͨ��PK���ο���ѹƫ����
//	NTSPRODUCTS_API short int _stdcall    NTS_GetPKVolOffset(short int Handle,short ch,short VolIndex,float *StartVol, float *StopVol,int *VolOffset);
	
	//��ȡͨ���ƶ����ο���ѹƫ����
//	NTSPRODUCTS_API short int _stdcall    NTS_GetPushVolOffset(short int Handle,short ch,short VolIndex,float *StartVol, float *StopVol,int *VolOffset);

	//��ȡͨ��ĩ���ο���ѹƫ����
//	NTSPRODUCTS_API short int _stdcall    NTS_GetLastVolOffset(short int Handle,short ch,short VolIndex,float *StartVol, float *StopVol,int *VolOffset);

	//����RAM��ֹ��ַ������
	NTSPRODUCTS_API short int _stdcall    NTS_SetStartAndStopRAM(short int Handle, short FlashIndex, int startaddress, long count, int *data);
	
	//����FLASH��ֹ��ַ������
	NTSPRODUCTS_API short int _stdcall    NTS_SetStarAndStopFlash(short int Handle,short FlashIndex,int startaddress,long count,int *data);

	//��ȡFLAST��ֹ��ַ������
	NTSPRODUCTS_API short int _stdcall    NTS_GetStarAndStopFlash(short int Handle,short FlashIndex,int startaddress,long count,int *data);
	
	//��ȡͨ���ĵ���ֵ(��λ:bit)
	NTSPRODUCTS_API short int _stdcall    NTS_GetCurrent(short int Handle, short ch, float *Current);

	// ��ȡͨ���ĵ�ѹ(��λ:bit)
	NTSPRODUCTS_API short int _stdcall    NTS_GetVoltage(short int Handle, short ch, float *Voltage);
	
	// ���õ�ǰ��Ҫ�ļ�ض���(Type 1:���� 2:��ѹ 3:�¶� Index 1:PA1����|PA1�¶�|28V 2:PA2����|PA2�¶�|5V 3:PA3����|PA3�¶� 4:PA4����|PA4�¶�)
	NTSPRODUCTS_API short int _stdcall    NTS_SetActiveObject(short int Handle, short ch, int Type, int Index);
	
	//����ͨ���������޵���ֵ(��λ:bit)
	NTSPRODUCTS_API short int _stdcall    NTS_SetCurrentLimited(short int Handle, short ch,float DownCurrent, float UpCurrent);

	//��ȡͨ���������޵���ֵ(��λ:bit)
	NTSPRODUCTS_API short int _stdcall    NTS_GetCurrentLimited(short int Handle, short ch,float *DownCurrent, float *UpCurrent);

	//��ȡ�澯��Ϣ
	NTSPRODUCTS_API short int _stdcall    NTS_GetIsWarning(short int Handle, short ch,int *state);

	//����澯��Ϣ
	NTSPRODUCTS_API short int _stdcall    NTS_ClearWarning(short int Handle,short ch);

	//��ȡ��Ʒ������Ϣ
	NTSPRODUCTS_API short int _stdcall    NTS_GetIDN(short int Handle, char *IDNHigh, char *IDNLow);

	//����ָ��
	NTSPRODUCTS_API short int _stdcall    NTS_SendCmd(short int Handle, char *Command);
	
	//��ȡ����ָ��ֵ
	NTSPRODUCTS_API short int _stdcall    NTS_GetCmd(short int Handle, char *Command, char *RetStr);
	
	//���õ������Բ���	
	NTSPRODUCTS_API short int _stdcall    NTS_SetPID(short int Handle, int GainIndex, double P, double I,  double D);
	
	//���ù��ŵľ�̬��������	
	NTSPRODUCTS_API short int _stdcall    NTS_SetGainWorkPara(short int Handle, int GainIndex, double WorkCurrent, 
		double ErrCurrent, int InitDA, int MinDA, int MaxDA);
	
	//�ڵ������µ��Ե������ŵľ�̬��������
	NTSPRODUCTS_API short int _stdcall    NTS_GainDebug(short int Handle,  short int MMTPort, short Ch, int GainIndex, 
		int FlashIndex, int BaseAddress, float *RefTemperature, int *RefDA);	
	
	// дУ����
	NTSPRODUCTS_API short int _stdcall    NTS_SetCRC(short int Handle);
	
	//�������
//	NTSPRODUCTS_API short int _stdcall    NTS_DataCalculate(double *K, int n, double RefTemperature, double RefDA);

	
#pragma pack()
	
#ifdef __cplusplus
}
#endif

#endif	

