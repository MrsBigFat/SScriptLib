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

	// 打开并初始化NCard
	NTSDRIVER_API short int	_stdcall   NC_OpenDev(char *szConnection, short int *Handle);

	//关闭设备
	NTSDRIVER_API short int	_stdcall   NC_CloseDev(short int Handle);

	//系统参数查询
	NTSDRIVER_API short int _stdcall   NC_QuerySysParam(short int Handle,char* sysParam);

	//系统状态查询
	NTSDRIVER_API short int _stdcall   NC_QuerySysState(short int Handle, char* sysState);

	//通讯对象创建 szConnection:连接字符串
	NTSDRIVER_API short int _stdcall   NC_CreateCommObject(short int Handle, char* szConnection,long* objID);

	//销毁通讯对象
	NTSDRIVER_API short int _stdcall   NC_DeleteCommObject(short int Handle, long objID);

	//通讯对象读操作
	//dataForamat: 读取数据格式，0：字符串格式，10：十进制格式；16：十六进制格式
	NTSDRIVER_API short int _stdcall   NC_Read(short int Handle, long objID,long dataFormat , long expLen, 
												char* readBuf, unsigned long *realLen);

	// 通讯对象写操作 expLen:期望长度
	////dataForamat: 写入数据格式，0：字符串格式，10：十进制格式；16：十六进制格式
	NTSDRIVER_API short int _stdcall   NC_Write(short int Handle, long objID, long dataFormat,long expLen, 
												const char* writeBuf, unsigned long *realLen);

	// 通讯对象缓冲区设置 type(0:all 1:Read 2:Write)
	NTSDRIVER_API short int _stdcall   NC_SetBufSize(short int Handle, long objID, long type, long bufSize);

	//通讯对象缓冲区清除 type(0:all 1:Read 2:Write))
	NTSDRIVER_API short int _stdcall   NC_ClearBuf(short int Handle, long objID,long type);

	// 通讯对象写操作(字符串)
	NTSDRIVER_API short int _stdcall   NC_Sprintf(short int Handle, long objID, const char* czCommand);

	// 通讯对象读操作(字符串)
	NTSDRIVER_API short int _stdcall   NC_Query(short int Handle, long objID, const char* czCommand, char *RetStr);

	//环境信息查询
	NTSDRIVER_API short int _stdcall   NC_QueryContextInfo(short int Handle,char* contextInfo);
	
	//版本信息查询
	NTSDRIVER_API short int _stdcall   NC_QueryVersionInfo(short int Handle, char* verInfo);

	//设置IP地址 (netType: 0-LAN口;1-DUT口)
	NTSDRIVER_API short int _stdcall   NC_SetIPAddress(short int Handle, long netType, const char* IPAddress);

	//重新启动
	NTSDRIVER_API short int _stdcall   NC_Reset(short int Handle);

#pragma pack()
	
#ifdef __cplusplus
}
#endif

#endif // !defined(AFX_NCARDDRIVER_H__508B4B39_E4E4_40D7_81D9_544AD453B9D7__INCLUDED_)
