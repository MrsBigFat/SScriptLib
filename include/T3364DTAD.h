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

	//加载方法
	ADDRIVER_API void	*  __stdcall	DEB_LoadMethod(	HMODULE Dllhandle,char *methedname);
	//获取动态库的方法名
	ADDRIVER_API short int __stdcall	DEB_GetFunNames(char **names,long *count);
	//获取所有温补数据
	ADDRIVER_API short int __stdcall	DEB_GetTCompensateData(
		short int devHandle,
		int *ChannelNo,		//通道个数
		int *Length,
		int *RefTemeprature,
		int *DriverValue,	//0-127 bit:1通道推动级DA；128-255 bit:2通道推动级DA
		int *FinalValue		//0-127 bit:1通道末级DA；128-255 bit:2通道末级DA
		);  
	//写电流调试数据到数据库
	ADDRIVER_API short int __stdcall	DEB_WriteDebugData(
		short int devhandle,	//设备句柄
		short int mmthandle,	//电流表句柄
		char *PCBID,			//模块PCB条码
		char *Tester,			//操作员
		char *TestTime,			//时间
		int flowID,				//工艺流程号
		int stationID,			//站点号
		int *Ch_Num,
		int *Length,
		float *RefTemperature,
		int *DriverDAValue,
		int *FinalDAValue
		);
	//获得流水号
	ADDRIVER_API short int __stdcall  ADJ_GetFlowID(
		char *PCBID,
		char *ClientID,
		char *CurrentMaxFlow,
		char *ResultFlowID); 
	
	//把校准数据写到数据库和excel表格中
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
	//从EEPROM中获取校准数据
	ADDRIVER_API short int __stdcall  ADJ_GetCalData(
		short int devHandle,
		int *Length,
		int *CalAddr,
		int *CalData
		);
	//校验校准数据的正确性 0:失败   1:成功
	ADDRIVER_API short int __stdcall  ADJ_CheckCalData(
		short int devHandle,
		int *Flag
		);
	//ACPR 自动调试
	ADDRIVER_API short int __stdcall  DEB_SetAutoACPR(
		short int NTSHandle ,	//模块句柄
		short int MMTHandle ,	//电流表串口号
		short int SGHandle ,	//信号源句柄	
		short int PSAHandle ,	//频谱仪句柄
		float RefPower,			//模块额定功率
		float SGMaxPower,		//信号源的上限幅度值
		int Intervaltime		//读取频谱仪的间隔时间(ms)
		);
#pragma pack()
	
#ifdef __cplusplus
}
#endif

#endif