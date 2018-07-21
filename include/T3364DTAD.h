#ifndef __T2263ZXAD_H__
#define __T2263ZXAD_H__

#ifndef ADDRIVER_EXPORTS
#define ADDRIVER_API __declspec(dllexport)
#else
#define ADDRIVER_API __declspec(dllimport)
#endif

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif

	//���ط���
	ADDRIVER_API void	*  __stdcall	DEB_LoadMethod(	HMODULE Dllhandle,char *methedname);
	//��ȡ��̬��ķ�����
	ADDRIVER_API short int __stdcall	DEB_GetFunNames(char **names,long *count);
	//��ȡ�����²�����
	ADDRIVER_API short int __stdcall	DEB_GetTCompensateData(
		short int devHandle,
		int *ChannelNo,		//ͨ������
		int *Length,
		int *RefTemeprature,
		int *DriverValue,	//0-127 bit:1ͨ���ƶ���DA��128-255 bit:2ͨ���ƶ���DA
		int *FinalValue		//0-127 bit:1ͨ��ĩ��DA��128-255 bit:2ͨ��ĩ��DA
		);  
	//д�����������ݵ����ݿ�
	ADDRIVER_API short int __stdcall	DEB_WriteDebugData(
		short int devhandle,	//�豸���
		short int mmthandle,	//��������
		char *PCBID,			//ģ��PCB����
		char *Tester,			//����Ա
		char *TestTime,			//ʱ��
		int flowID,				//�������̺�
		int stationID,			//վ���
		int *Ch_Num,
		int *Length,
		float *RefTemperature,
		int *DriverDAValue,
		int *FinalDAValue
		);
	//�����ˮ��
	ADDRIVER_API short int __stdcall  ADJ_GetFlowID(
		char *PCBID,
		char *ClientID,
		char *CurrentMaxFlow,
		char *ResultFlowID); 
	
	//��У׼����д�����ݿ��excel�����
	ADDRIVER_API short int __stdcall  ADJ_WriteCalData(
		short int devHandle,
		char *PCBID,
		char *Tester,
		char *TestTime,
		int flowID,
		int stationID,
		int *Length,
		int *CalData,
		int *CalAddr
		);
	//��EEPROM�л�ȡУ׼����
	ADDRIVER_API short int __stdcall  ADJ_GetCalData(
		short int devHandle,
		int *Length,
		int *CalAddr,
		int *CalData
		);
	//У��У׼���ݵ���ȷ�� 0:ʧ��   1:�ɹ�
	ADDRIVER_API short int __stdcall  ADJ_CheckCalData(
		short int devHandle,
		int *Flag
		);
	//ACPR �Զ�����
	ADDRIVER_API short int __stdcall  DEB_SetAutoACPR(
		short int NTSHandle ,	//ģ����
		short int MMTHandle ,	//�������ں�
		short int SGHandle ,	//�ź�Դ���	
		short int PSAHandle ,	//Ƶ���Ǿ��
		float RefPower,			//ģ������
		float SGMaxPower,		//�ź�Դ�����޷���ֵ
		int Intervaltime		//��ȡƵ���ǵļ��ʱ��(ms)
		);
#pragma pack()
	
#ifdef __cplusplus
}
#endif

#endif