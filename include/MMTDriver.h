/* -------------------------------------------------------------------------
//	�ļ���		��	MMTDriver.h
//	������		��	dolby jiang
//	����ʱ��	��	08-6-15 17:11:04
//	��������	��	Specify the Interface MMTDriver.dll 
//
// -----------------------------------------------------------------------*/

#ifdef MMTDRIVER_EXPORTS
#define MMTDRIVER_API __declspec(dllexport)
#else
#define MMTDRIVER_API __declspec(dllimport)
#endif

#pragma pack(1)

#ifdef __cplusplus
extern "C" {
#endif
	//�򿪲���ʼ���豸
	MMTDRIVER_API short int	_stdcall	MMT_OpenDev(char *protocol, short int *devhandle);
	//�ر��豸
	MMTDRIVER_API short int	_stdcall	MMT_CloseDev(short int handle);

	//��ȡ������ĵ���ֵ
	MMTDRIVER_API short int _stdcall	MMT_GetCurrent(short int handle,short int portno,float *current);
	
	//��ջ�����
	MMTDRIVER_API short int _stdcall	MMT_ClearBuffer(short int handle);
	//��ȡ����(��)
	MMTDRIVER_API short int _stdcall	MMT_GetZn(short int handle, short int portno, float *Zn);

#pragma pack()
	
#ifdef __cplusplus
}
#endif
