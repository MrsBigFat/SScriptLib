
//////////////////////////////////////////////////////////////////////
/* 
*Copyright (c) 2009,оͨ�Ƽ����޹�˾ 
*All rights reserved.
*�ļ����ƣ�LPTDriver.h
*�ļ���ʶ��reserved
*ժҪ��Specify the Interface for InterfaceDriver.dll 
*/
//////////////////////////////////////////////////////////////////////


// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the NTSDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// NTSCOMDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifndef __LPTDriver_H__
#define __LPTDriver_H__

//Version 1.0
#define __NTSDRIVER_H_VERSION 0x0001

/************************************************************************/
/* 
*�汾��3.0.0.0
*���ߣ�Dolby.Jiang
*������ڣ�2010��11��18��
*���ģ��½�
*/
/************************************************************************/

#ifdef NTSLPTDriver_EXPORTS
#define NTSLPTDRIVER_API __declspec(dllimport)
#else
#define NTSLPTDRIVER_API __declspec(dllexport)
#endif

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

	// ��I/O��д����
	NTSLPTDRIVER_API short int _stdcall NTS_SetIOPortVal(WORD wPortAddr, DWORD dwPortVal, BYTE bSize); 
	
	// ��I/O��ȡ����
	NTSLPTDRIVER_API short int _stdcall NTS_GetIOPortVal(WORD wPortAddr, PDWORD pdwPortVal, BYTE bSize); 
	
	// ��I/O���Ż�����д��Ҫ���͵Ķ���������
	NTSLPTDRIVER_API short int _stdcall NTS_SetIOBits( WORD wPortAddr, int Pin, char *Bits);

	// ��I/O���Ż�����д��Ҫ���͵Ķ���������
	NTSLPTDRIVER_API short int _stdcall NTS_StartIO( WORD wPortAddr);
	
	// ����ʱ���ź�
	NTSLPTDRIVER_API short int _stdcall NTS_SetIOCLKBits( int Pin, char *Bits);

	// ����T/R�����������(Pin2:Data Pin3:CLK Pin4:Lock)
	NTSLPTDRIVER_API short int _stdcall NTS_SetIOTRBits( WORD wPortAddr, char *Bits);

	// ����IO������ʽ 0:Positive(������) 1:Negative(�½���)
	NTSLPTDRIVER_API short int _stdcall NTS_SetIOTrigPolarity( int Pin, BYTE Polarity);
	

#pragma pack()
	
#ifdef __cplusplus
}
#endif

#endif	

