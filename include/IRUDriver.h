/************************************************************************
* Copyright (c) 2009,оͨ�Ƽ����޹�˾
* All rights reserved.
* �ļ����ƣ�IRUDriver.h
* �ļ���ʶ��reserved
* ժҪ��This class is exported from the IRUDriver.dll
*
************************************************************************/

// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the IRUDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// IRUDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef IRUDRIVER_EXPORTS
#define IRUDRIVER_API __declspec(dllimport)
#else
#define IRUDRIVER_API __declspec(dllexport)
#endif

/************************************************************************
* �汾��2.0.0.0
* ���ߣ�dolby.jiang
* ������ڣ�2009��12��21��
* ���ģ��½�
*
************************************************************************/

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

	//�򿪲���ʼ���豸
	IRUDRIVER_API short int	_stdcall	IRU_OpenDev(char *protocol, short int *Handle);

	//�ر��豸
	IRUDRIVER_API short int	_stdcall	IRU_CloseDev(short int Handle);

	//����
	IRUDRIVER_API short int	_stdcall	IRU_Reboot(short int Handle);

	//IRU�帴λ
	IRUDRIVER_API short int	_stdcall	IRU_Reset(short int Handle);
		
	//��ȡ������Ϣ
	IRUDRIVER_API short int	_stdcall	IRU_GetIDN(short int Handle, char *IDN);

	//����ָ��
	IRUDRIVER_API	short int _stdcall	IRU_SendCmd(short int Handle, char *Command);
	
	//��ȡ����ָ��ֵ
	IRUDRIVER_API	short int _stdcall	IRU_GetCmd(short int Handle, char *Command, char *RetStr);

	//�����ļ�
	IRUDRIVER_API short int _stdcall    IRU_LoadFile(short int Handle, char *FileName);
	
	
#pragma pack()
	
#ifdef __cplusplus
}
#endif