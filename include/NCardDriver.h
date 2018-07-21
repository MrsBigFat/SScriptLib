// NCardDriver.h: interface for the NCardDriver class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NCARDDRIVER_H__508B4B39_E4E4_40D7_81D9_544AD453B9D7__INCLUDED_)
#define AFX_NCARDDRIVER_H__508B4B39_E4E4_40D7_81D9_544AD453B9D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//Version 1.0
#define __NTSDRIVER_H_VERSION 0x0001

#ifdef NCARDDRIVER_EXPORTS
#define NTSDRIVER_API __declspec(dllexport)
#else
#define NTSDRIVER_API __declspec(dllimport)
#endif

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

	// �򿪲���ʼ��NCard
	NTSDRIVER_API short int	_stdcall   NC_OpenDev(char *szConnection, short int *Handle);

	//�ر��豸
	NTSDRIVER_API short int	_stdcall   NC_CloseDev(short int Handle);

	//ϵͳ������ѯ
	NTSDRIVER_API short int _stdcall   NC_QuerySysParam(short int Handle,char* sysParam);

	//ϵͳ״̬��ѯ
	NTSDRIVER_API short int _stdcall   NC_QuerySysState(short int Handle, char* sysState);

	//ͨѶ���󴴽� szConnection:�����ַ���
	NTSDRIVER_API short int _stdcall   NC_CreateCommObject(short int Handle, char* szConnection,long* objID);

	//����ͨѶ����
	NTSDRIVER_API short int _stdcall   NC_DeleteCommObject(short int Handle, long objID);

	//ͨѶ���������
	//dataForamat: ��ȡ���ݸ�ʽ��0���ַ�����ʽ��10��ʮ���Ƹ�ʽ��16��ʮ�����Ƹ�ʽ
	NTSDRIVER_API short int _stdcall   NC_Read(short int Handle, long objID,long dataFormat , long expLen, 
												char* readBuf, unsigned long *realLen);

	// ͨѶ����д���� expLen:��������
	////dataForamat: д�����ݸ�ʽ��0���ַ�����ʽ��10��ʮ���Ƹ�ʽ��16��ʮ�����Ƹ�ʽ
	NTSDRIVER_API short int _stdcall   NC_Write(short int Handle, long objID, long dataFormat,long expLen, 
												const char* writeBuf, unsigned long *realLen);

	// ͨѶ���󻺳������� type(0:all 1:Read 2:Write)
	NTSDRIVER_API short int _stdcall   NC_SetBufSize(short int Handle, long objID, long type, long bufSize);

	//ͨѶ���󻺳������ type(0:all 1:Read 2:Write))
	NTSDRIVER_API short int _stdcall   NC_ClearBuf(short int Handle, long objID,long type);

	// ͨѶ����д����(�ַ���)
	NTSDRIVER_API short int _stdcall   NC_Sprintf(short int Handle, long objID, const char* czCommand);

	// ͨѶ���������(�ַ���)
	NTSDRIVER_API short int _stdcall   NC_Query(short int Handle, long objID, const char* czCommand, char *RetStr);

	//������Ϣ��ѯ
	NTSDRIVER_API short int _stdcall   NC_QueryContextInfo(short int Handle,char* contextInfo);
	
	//�汾��Ϣ��ѯ
	NTSDRIVER_API short int _stdcall   NC_QueryVersionInfo(short int Handle, char* verInfo);

	//����IP��ַ (netType: 0-LAN��;1-DUT��)
	NTSDRIVER_API short int _stdcall   NC_SetIPAddress(short int Handle, long netType, const char* IPAddress);

	//��������
	NTSDRIVER_API short int _stdcall   NC_Reset(short int Handle);

#pragma pack()
	
#ifdef __cplusplus
}
#endif

#endif // !defined(AFX_NCARDDRIVER_H__508B4B39_E4E4_40D7_81D9_544AD453B9D7__INCLUDED_)
