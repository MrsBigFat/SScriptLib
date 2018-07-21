/* -------------------------------------------------------------------------
//	文件名		：	MMTDriver.h
//	创建者		：	dolby jiang
//	创建时间	：	08-6-15 17:11:04
//	功能描述	：	Specify the Interface MMTDriver.dll 
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
	//打开并初始化设备
	MMTDRIVER_API short int	_stdcall	MMT_OpenDev(char *protocol, short int *devhandle);
	//关闭设备
	MMTDRIVER_API short int	_stdcall	MMT_CloseDev(short int handle);

	//获取电流表的电流值
	MMTDRIVER_API short int _stdcall	MMT_GetCurrent(short int handle,short int portno,float *current);
	
	//清空缓冲区
	MMTDRIVER_API short int _stdcall	MMT_ClearBuffer(short int handle);
	//获取电阻(Ω)
	MMTDRIVER_API short int _stdcall	MMT_GetZn(short int handle, short int portno, float *Zn);

#pragma pack()
	
#ifdef __cplusplus
}
#endif
