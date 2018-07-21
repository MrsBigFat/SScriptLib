
// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the LANDRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// D6180ZXLANDRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef LANDRIVER_EXPORTS
#define LANDRIVER_API __declspec(dllimport)
#else
#define LANDRIVER_API __declspec(dllexport)
#endif


/************************************************************************
* �汾��0.0.0.0
* ���ߣ�dolby.jiang
* ������ڣ�2011��6��3��
* ���ģ��½�
*
************************************************************************/

// This class is exported from the Lanriver.dll
#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

	//�򿪲���ʼ���豸
	LANDRIVER_API short int	_stdcall	NTS_OpenLan(char *protocol, short int *Handle);

	//�ر��豸
	LANDRIVER_API short int	_stdcall	NTS_CloseLan(short int Handle);
	
	// ��LAN�ڶ�ȡ����
	LANDRIVER_API short int	_stdcall	NTS_ReadLan(short int Handle, char*ReadBuf, unsigned long Count, unsigned long *RealCount);
	
	// ��LAN��д����
	LANDRIVER_API short int	_stdcall	NTS_WriteLan(short int Handle, char*WriteBuf, unsigned long Count);	
	
	// ��ѯLan��
	LANDRIVER_API short int	_stdcall	NTS_QueryLan(short int Handle, char *WriteBuf, unsigned long Count, char *ReadBuf, unsigned long *RealCount);
	
	// ���û���������(Mask 0:ALL 1:Tx_Buffer 2:Rx_Buffer)
	LANDRIVER_API short int	_stdcall	NTS_SetLanBufSize(short int Handle, unsigned short Mask, unsigned int Size);
	
	// ���������(Mask 0:ALL 1:Tx_Buffer 2:Rx_Buffer)
	LANDRIVER_API short int	_stdcall	NTS_FlushLanBuf(short int Handle, unsigned short Mask);

	// ����ϵͳ��ʱʱ����(��λ:��)
	LANDRIVER_API short int	_stdcall	NTS_SetLanTimeOut(short int Handle, int TimeOut);
	

	
#pragma pack()
	
#ifdef __cplusplus
}
#endif
