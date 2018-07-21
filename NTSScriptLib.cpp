// NTSDriver.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#pragma warning( disable : 4786)
#include <string>
#include "NTSScriptLib.h"
#include "Method.h"
#include "MethodFactory.h"
#include <map>
#include "DllAnalyse.h"
#include "ComFunction.h"



// 全局变量定义
extern BaseMethod *gMethodDev[MAXMETHOD + 1];	// 方法句柄
extern TDeviceManagerMap gDeviceManagerMap;	// 设备句柄管理器
//void * g_pMemAddr;						// 输入参数为指针时，参数值的存取地址 
extern BOOL gCommIsStr;						// 通用读写函数数据发送方式 True:字符串	false:数据流

//获取PSA设备的连接字符串
int GetConnectStrOfPSA(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

//获取SG设备的连接字符串
int GetConnectStrOfSG(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

//获取ENA设备的连接字符串
int GetConnectStrOfENA(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

//获取NFA设备的连接字符串
int GetConnectStrOfNFA(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

// 获取PRM设备的连接字符串
int GetConnectStrOfPRM(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

// 获取IRU设备的连接字符串
int GetConnectStrOfIRU(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

//获取DPD设备的连接字符串
int GetConnectStrOfDPD(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

//获取DWG设备的连接字符串
int GetConnectStrOfDWG(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

//获取OSC设备的连接字符串
int GetConnectStrOfOSC(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);
/******************************************************************************
* 函数名称:  
* 作者:	 dolob.jiang
* 日期  2009.12.12
* 参数: 
* 功能:  初始化方法库
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     InitMethodLib()
{	
	MethodFactory *pMethodFactory = NULL;
	pMethodFactory = MethodFactory::GetInstance();	
	//清空句柄管理
	gDeviceManagerMap.clear();
	return NTS_SUCCESS;
}


/******************************************************************************
* 函数名称:  OpenDevice
* 作者:	 dolob.jiang
* 日期  2009.12.12
* 参数: int devType, char *ConnectStr, short int *devHandle
* 功能:  打开设备
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     OpenDevice(int devType, char *ConnectStr, int *devHandle)
{
	int retVal;
	ViSession rmHandle, vDevHandle;
	DeviceInfoStruct vDeviceInfoStruct;
	TDeviceManagerMap::iterator it; 

	std::string protoclString(ConnectStr);
	std::string tmpString, vManalfacotoryName;
	std::vector<std::string> subProtocls;
	std::string::size_type pos = 0, oldPos = 0;
	int SectionCount, i;
	char tmpStr[100], vParentConnStr[200], vSubConnStr[200];
	char ErrMsg[1024] = {0};

	
	if (ConnectStr == 0)
	{
		return NTS_INVALID_PARA;
	}
	*devHandle = -1;
	// 
	pos = protoclString.find("," , oldPos);
	if (pos != std::string::npos)
	{
		tmpString = protoclString.substr(oldPos, pos - oldPos);
		sprintf(vParentConnStr, "%s", tmpString.c_str());
		oldPos = pos + 1;
		tmpString = protoclString.substr(oldPos, std::string::npos - oldPos);
		sprintf(vSubConnStr, "%s", tmpString.c_str());
	}
	else 
	{	
		tmpString = protoclString.substr(oldPos, pos - oldPos);	
		sprintf(vParentConnStr, "%s", tmpString.c_str());
	}
	
	// 主连接字符串
	protoclString = vParentConnStr;
	oldPos = 0;
	do
	{
		pos = protoclString.find("::", oldPos);
		if (pos != std::string::npos)
		{
			tmpString = protoclString.substr(oldPos, pos - oldPos);
			subProtocls.push_back(tmpString);
			oldPos = pos + 2;
		}
		else 
		{
			subProtocls.push_back(protoclString.substr(oldPos, pos));
			break;
		}
	}while(true);
	
	SectionCount = subProtocls.size();
	if(SectionCount != 1 && SectionCount != 5 && SectionCount != 6 && SectionCount != 7)
	{
		sprintf(ErrMsg, "输入的连接字符串错误(厂商::型号::接口::地址参数::固定值)");
		NTS_Error(ErrMsg);
		return NTS_INVALID_PROTOCL;
	}


	switch(devType) 
	{
	case NCARD:				// 通用接口卡
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		
		retVal = NC_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = LAN;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;	
		}
		break;

	case NTS:				//芯通产品		
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}				
		sprintf(tmpStr, subProtocls[SectionCount - 1].c_str());		
		if(strcmp(tmpStr, "CAL") == 0 )	       //校准
		{
			retVal = AD_OpenDev(ConnectStr, (short int *)devHandle);			
		}
		else if(strcmp(tmpStr, "DEB") == 0 )	//调试
		{
			retVal = AD_OpenDev(ConnectStr, (short int *)devHandle);	
		}
		else if(strcmp(tmpStr, "TESTCARD") == 0 )	//通用测试卡
		{
			retVal = TC_OpenDev(ConnectStr, (short int *)devHandle);	
		}
		else								   //测试
		{
			retVal = NTS_OpenDev(ConnectStr, (short int *)devHandle);		
		}
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = COM;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}
		break;
	case SG:				//信号源
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
	
		retVal = SG_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;	
		}
		break;
	case PSA:				//频谱仪
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		retVal = PSA_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;	
		}
		break;
	case ENA:				//网络仪
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		retVal = ENA_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;	
		}
		break;
	case NFA:				//噪声仪
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}	
		
		retVal = NFA_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}
		break;
	case MMT:				//万用表
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}	
		retVal = MMT_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = COM;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}	
		break;
	case SWI:				//矩阵开关
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}	
		retVal = SW_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = COM;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}	
		break;
	case DPD:				//DPD
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}	
		retVal = DPD_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = LAN;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}	
		break;
	case PRM:				//功率计
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}	
		retVal = PRM_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}	
		break;
	case IRU:				//IRU
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		retVal = IRU_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = LAN;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}	
		break;

	case DWG:				//DWG
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		retVal = DWG_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;	
		}
		break;

	case OSC:				//OSC
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		retVal = OSC_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;	
		}
		break;

	default:			// 自定义设备
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "设备%s%s", ConnectStr, "已经被打开");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		// 判断通讯接口类型
		if (SectionCount == 1)
		{
			// 只有com支持短连接
			tmpString = subProtocls[0];	
		}
		else
		{
			vManalfacotoryName = subProtocls[0];			
			tmpString = subProtocls[2];			
		}
		
		if (vManalfacotoryName.find("NTS") != std::string::npos) 
		{
			// 加载NTS驱动库
			return OpenDevice(101, ConnectStr, devHandle);
		}
		pos = tmpString.find("GPIB");
		if(pos != std::string::npos)					// GPIB
		{
			// 根据格式要求组织连接字符串
			for(i = 2; i < SectionCount; i++) 
			{
				if(i == 2)
				{
					sprintf(tmpStr, "%s", subProtocls[i].c_str());
				}
				else
				{
					sprintf(tmpStr, "%s::%s", tmpStr, subProtocls[i].c_str() );
					
				}
			}	
			retVal = viGetDefaultRM(&rmHandle);
			if(retVal < VI_SUCCESS)
			{
				return NTS_INVALID_DEVICE;
			}
			retVal = viOpen(rmHandle, tmpStr, VI_NULL, VI_NULL, &vDevHandle);
			if(retVal == VI_SUCCESS)
			{	
				// 打开成功
				*devHandle = vDevHandle;
				sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
				vDeviceInfoStruct.DevHandle = vDevHandle;
				vDeviceInfoStruct.DeviceType = devType;
				vDeviceInfoStruct.InterFaceType = GPIB;
				gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;				
				retVal = NTS_SUCCESS;					
			}
			else
			{
				retVal = NTS_INVALID_DEVICE;
			}
			break;
		}
		pos = tmpString.find("TCPIP");
		if(pos != std::string::npos)					// TCPIP
		{
			tmpString = subProtocls[4];
			pos = tmpString.find("SOCKET");
			if (pos != std::string::npos)				// 
			{
				// 根据格式要求组织连接字符串				
				retVal = NTS_OpenLan(ConnectStr, (short int *)devHandle);
				if (retVal != NTS_SUCCESS)
				{
					sprintf(ErrMsg, "打开%s设备失败", ConnectStr);
					NTS_Error(ErrMsg);
					return NTS_INVALID_DEVICE;
				}				
				sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
				vDeviceInfoStruct.DevHandle = *devHandle;
				vDeviceInfoStruct.DeviceType = devType;
				vDeviceInfoStruct.InterFaceType = LAN;
				gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
				break;	
			}
			else 
			{
				// 根据格式要求组织连接字符串
				sprintf(tmpStr, "%s::%s::%s", subProtocls[2].c_str(), subProtocls[3].c_str(), subProtocls[4].c_str());
				retVal = viGetDefaultRM(&rmHandle);
				if(retVal < VI_SUCCESS)
				{
					return NTS_INVALID_DEVICE;
				}
				retVal = viOpen(rmHandle, tmpStr, VI_NULL, VI_NULL, &vDevHandle);
				if(retVal == VI_SUCCESS)
				{	
					// 打开成功
					*devHandle = vDevHandle;
					sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
					vDeviceInfoStruct.DevHandle = *devHandle;
					vDeviceInfoStruct.DeviceType = devType;
					vDeviceInfoStruct.InterFaceType = LAN;
					gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
					retVal = NTS_SUCCESS;					
				}
				else
				{
					retVal = NTS_INVALID_DEVICE;
				}
			}	
			break;
		}

		pos = tmpString.find("COM");
		if(pos != std::string::npos)					// COM
		{
			// 根据格式要求组织连接字符串		
			retVal = NTS_OpenCom(ConnectStr, (short int *)devHandle);
			if (retVal != NTS_SUCCESS)
			{
				sprintf(ErrMsg, "打开%s设备失败", ConnectStr);
				NTS_Error(ErrMsg);
				return NTS_INVALID_DEVICE;
			}			
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = COM;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
			break;			
		}
		pos = tmpString.find("USB");
		if(pos != std::string::npos)					// USB
		{
			// 根据格式要求组织连接字符串
			sprintf(tmpStr, "%s::%s::%s::%s::%s", subProtocls[2].c_str(), subProtocls[3].c_str(), subProtocls[4].c_str(),
				subProtocls[5].c_str(), subProtocls[6].c_str());
			retVal = viGetDefaultRM(&rmHandle);
			if(retVal < VI_SUCCESS)
			{
				return NTS_INVALID_DEVICE;
			}
			retVal = viOpen(rmHandle, tmpStr, VI_NULL, VI_NULL, &vDevHandle);
			if(retVal == VI_SUCCESS)
			{	
				// 打开成功
				*devHandle = vDevHandle;
				sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
				vDeviceInfoStruct.DevHandle = vDevHandle;
				vDeviceInfoStruct.DeviceType = devType;
				vDeviceInfoStruct.InterFaceType = GPIB;
				gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;				
				retVal = NTS_SUCCESS;					
			}
			else
			{
				retVal = NTS_INVALID_DEVICE;
			}
			break;
		}
		else
		{
			sprintf(ErrMsg, "暂时还不支持该接口!");
			NTS_Error(ErrMsg);
			return NTS_INVALID_PARA;
		}
		break;
	}
	if (retVal != NTS_SUCCESS)
	{
		sprintf(ErrMsg, "打开%s设备失败", ConnectStr);
		NTS_Error(ErrMsg);
	}
	return retVal;
}

/******************************************************************************
* 函数名称:  CloseDevice
* 作者:	 dolob.jiang
* 日期  2009.12.12
* 参数: TDevcieType devType, char *ConnectStr
* 功能:  关闭设备
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     CloseDevice(int devType, char *ConnectStr)
{
	int retVal;
	TDeviceManagerMap::iterator it; 
	unsigned long DevHandle = -1;
	TInterfaceType vIType;

	std::string protoclString(ConnectStr);
	std::string tmpString, vManalfacotoryName;
	std::vector<std::string> subProtocls;
	std::string::size_type pos = 0, oldPos = 0;
	int SectionCount;
	char tmpStr[200] = {0};
	char ErrMsg[1024] = {0};
	char vParentConnectStr[500] = {0};
//	char vChildConnectStr[500] = {0};
	
	if (ConnectStr == 0)
	{
		return NTS_INVALID_PARA;
	}
	// 获取主连接字符串
	NTS_SeparateStr(ConnectStr, "," , &subProtocls);
	if (subProtocls.size() < 1)
	{
		return NTS_INVALID_PROTOCL;
	}
	else
	{
		sprintf(vParentConnectStr, "%s", subProtocls[0].c_str());
		protoclString = vParentConnectStr;
	}
	
	subProtocls.clear();
	do
	{
		pos = protoclString.find("::", oldPos);
		if (pos != std::string::npos)
		{
			tmpString = protoclString.substr(oldPos, pos - oldPos);
			subProtocls.push_back(tmpString);
			oldPos = pos + 2;
		}
		else 
		{
			subProtocls.push_back(protoclString.substr(oldPos, pos));
			break;
		}
	}while(true);
	SectionCount = subProtocls.size();
	if (SectionCount != 1 && SectionCount != 5 && SectionCount != 6 && SectionCount != 7)
	{
		return NTS_INVALID_PROTOCL;
	}
	switch(devType) 
	{
	case NCARD:
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = NC_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;

	case NTS:					//芯通产品
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		sprintf(tmpStr, subProtocls[SectionCount - 1].c_str());		
		if(strcmp(tmpStr, "CAL") == 0 )	       //校准
		{
			retVal = AD_CloseDev(DevHandle);
		}
		else if(strcmp(tmpStr, "DEB") == 0 )	//调试
		{
			retVal = AD_CloseDev(DevHandle);
		}
		else if(strcmp(tmpStr, "TESTCARD") == 0 )	//通用测试卡
		{
			retVal = TC_CloseDev(DevHandle);
		}
		else								   //测试
		{
			retVal = NTS_CloseDev(DevHandle);
		}
		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;
	case SG:					//信号源
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = SG_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;
	case PSA:					//频谱仪
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = PSA_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}		
		break;
	case ENA:					//网络仪
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = ENA_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}		
		break;
	case NFA:					//噪声仪
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = NFA_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}		
		break;
	case MMT:					//万用表
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = MMT_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;
	case SWI:					//矩阵开关
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = SW_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;
	case DPD:					//矩阵开关
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = DPD_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;	
	case PRM:
		it = gDeviceManagerMap.find(ConnectStr);
		if(it == gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = PRM_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;
	case IRU:				//IRU
		it = gDeviceManagerMap.find(ConnectStr);
		if(it == gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = IRU_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;

	case DWG:				//DWG
		it = gDeviceManagerMap.find(ConnectStr);
		if(it == gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = DWG_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;

	case OSC:				//OSC
		it = gDeviceManagerMap.find(ConnectStr);
		if(it == gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = OSC_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;


	default:				// 自定义设备
		// 判断通讯接口类型
		if (SectionCount == 1)
		{
			// 只有com支持短连接
			tmpString = subProtocls[0];	
		}
		else
		{
			vManalfacotoryName = subProtocls[0];			
			tmpString = subProtocls[3];			
		}
		if (vManalfacotoryName.find("NTS") != std::string::npos) 
		{
			// 加载NTS驱动库
			return CloseDevice(101, ConnectStr);
		}

		it = gDeviceManagerMap.find(ConnectStr);
		if(it == gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "设备没有被打开或者已经关闭了");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		vIType = (TInterfaceType)it->second.InterFaceType;
		switch(vIType)
		{
		case GPIB:
			retVal = viClose(DevHandle);
			if(retVal < VI_SUCCESS)
			{		
				return NTS_INVALID_OPERATE;
			}
			break;

		case LAN:
			tmpString = subProtocls[4];
			pos = tmpString.find("SOCKET");
			if (pos != std::string::npos)				// 
			{
				// 根据格式要求组织连接字符串
				retVal = NTS_CloseLan(DevHandle);
				if(retVal != NTS_SUCCESS)
				{		
					return NTS_INVALID_OPERATE;
				}
				break;	
			}
			else 
			{
				retVal = viClose(DevHandle);
				if(retVal < VI_SUCCESS)
				{		
					return NTS_INVALID_OPERATE;
				}
			}
				
			break;

		case COM:
			retVal = NTS_CloseCom(DevHandle);
			if(retVal != NTS_SUCCESS)
			{		
				return NTS_INVALID_OPERATE;
			}
			break;

		case USB:
			retVal = viClose(DevHandle);
			if(retVal < VI_SUCCESS)
			{		
				return NTS_INVALID_OPERATE;
			}
			break;

		default:
			return NTS_INVALID_OPERATE;
			break;
		}
		
		gDeviceManagerMap.erase(it); 
		retVal = NTS_SUCCESS;
		break;
	}

	if (retVal != NTS_SUCCESS)
	{
		sprintf(ErrMsg, "关闭%s设备失败", ConnectStr);
		NTS_Error(ErrMsg);
	}
	return retVal;
}

/******************************************************************************
* 函数名称:  GetDriverTypeName
* 作者:	 dolob.jiang
* 日期  2009.12.12
* 参数: char **name, unsigned long *count
* 功能:  获取驱动方法类名
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     GetDriverTypeName(char **name, unsigned long *count)
{
	char DevName[50][50] = {0};
	int tmpcount = 0 ;
	
	sprintf(DevName[0],"芯通产品方法");
	sprintf(DevName[1],"信号源方法");
	sprintf(DevName[2],"频谱仪方法");
	sprintf(DevName[3],"网络仪方法");
	sprintf(DevName[4],"噪声仪方法");
	sprintf(DevName[5],"综合方法");
	sprintf(DevName[6],"数字万用表方法");
	sprintf(DevName[7],"矩阵开关方法");
	sprintf(DevName[8],"DPD板方法");
	sprintf(DevName[9],"功率计方法");
	sprintf(DevName[10],"IRU方法");
	sprintf(DevName[11],"测试卡方法");
	sprintf(DevName[12],"NCARD方法");
	sprintf(DevName[13],"AUT方法");
	sprintf(DevName[14],"波形发生器方法");
	sprintf(DevName[15],"示波器方法");
	tmpcount = 16;
	for(int i = 0;i<tmpcount;i++)
	{
		*(name+i)  = *(DevName+i);
	}
	*count = tmpcount;
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetDevice
* 作者:	 dolob.jiang
* 日期  2009.12.12
* 参数: char **name, unsigned long *count
* 功能:  获取设备名称
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     GetDevice(char **name, unsigned long *count)
{
	char DevName[50][100] = {0};
	int tmpcount = 0 ;
/*
	sprintf(DevName[0],"NTSDevice");
	sprintf(DevName[1],"SGDevice(信号源)");
	sprintf(DevName[2],"PSADevice(频谱仪)");	
	sprintf(DevName[3],"ENADevice(矢网)");
	sprintf(DevName[4],"NFADevice(噪声仪)");
	sprintf(DevName[5],"MMTDevice(万用表)");
	sprintf(DevName[6],"SWIDevice(NTS矩阵开关)");
	sprintf(DevName[7],"DPDDevice(DPD工装)");
	sprintf(DevName[8],"PRMDevice(功率计)");
	sprintf(DevName[9],"IRUDevice(BBU工装)");
	sprintf(DevName[10],"NCardDevice(NTS通用卡)");
 	sprintf(DevName[11],"ExDevice(扩展设备)");
*/

	sprintf(DevName[0],"NTSDevice");
	sprintf(DevName[1],"SGDevice");
	sprintf(DevName[2],"PSADevice");	
	sprintf(DevName[3],"ENADevice");
	sprintf(DevName[4],"NFADevice");
	sprintf(DevName[5],"MMTDevice");
	sprintf(DevName[6],"SWIDevice");
	sprintf(DevName[7],"DPDDevice");
	sprintf(DevName[8],"PRMDevice");
	sprintf(DevName[9],"IRUDevice");
	sprintf(DevName[10],"NCardDevice");
	sprintf(DevName[13],"ExDevice");
	sprintf(DevName[11],"DWGDevice");
	sprintf(DevName[12],"OSCDevice");

	tmpcount = 14;
	for(int i = 0;i<tmpcount;i++)
	{
		*(name+i)  = *(DevName+i);
	}
	*count = tmpcount;
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetAllMethod
* 作者:	 dolob.jiang
* 日期  2009.12.12
* 参数: char *(methodName[50]), unsigned long *count
* 功能:  获取方法库中所有的驱动库方法
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     GetAllMethod(char *(methodName[50]), unsigned long *count)
{
	TMethodMap::iterator it;
	MethodNameStruct m_MethodSet;
	std::string Key;
	char FunName[3000][100] = {0};
	int i = 0;
	char ErrMsg[1024];
	MethodFactory *pMethodFactory = NULL;
	pMethodFactory = MethodFactory::GetInstance();	
	if ( pMethodFactory == NULL)
	{
		sprintf(ErrMsg, "%s", "方法库实例未初始化!");
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}
	it = pMethodFactory->m_MethodMap.begin();
	while(it != pMethodFactory->m_MethodMap.end())
	{
		m_MethodSet = it->second;
		if(m_MethodSet.Visable == 1)
		{
			Key = it->first;
			sprintf(FunName[i], "%s", Key.c_str());
			*(methodName + i) = *(FunName+i);		
			i++;
		}
		it++;
	}
	*count = i;

	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetMethodEx
* 作者:	 dolob.jiang
* 日期  2009.12.12
* 参数: int MethodType, char *(methodName[50]), unsigned long *count
* 功能:  获取某类设备的驱动库方法
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     GetMethodEx(int MethodType, char *(methodName[50]), unsigned long *count)
{
	TMethodMap::iterator it;
	std::string tmpStr;
	MethodNameStruct m_MethodSet;
	char FunName[1000][100] = {0};
	char ErrMsg[1024];
	std::string::size_type pos =0;
	char flagHead[10];
	int i = 0;
	int tmpcount;
	

	switch(MethodType)
	{
	case NTSMethod:
		sprintf(flagHead, "NTS_");
		break;
		
	case SGMethod:
		sprintf(flagHead, "SG_");
		break;

	case NFAMethod:
		sprintf(flagHead, "NFA_");
		break;

	case PSAMethod:
		sprintf(flagHead, "PSA_");
		break;

	case ENAMethod:
		sprintf(flagHead, "ENA_");
		break;

	case SPEMethod:
		sprintf(flagHead, "SPE_");
		break;

	case MMTMethod:
		sprintf(flagHead, "MMT_");
		break;

	case DEBMethod:			//调试
		sprintf(flagHead, "DEB_");
		break;

	case ADJMethod:			//校准
		sprintf(flagHead, "ADJ_");
		break;

	case SWIMethod:
		sprintf(flagHead, "SW_");
		break;

	case DPDMethod:
		sprintf(flagHead, "DPD_");
		break;

	case PRMMethod:			//功率计
		sprintf(flagHead, "PRM_");
		break;

	case IRUMethod:			//IRU
		sprintf(flagHead, "IRU_");
		break;

	case TCMethod:			//测试卡
		sprintf(flagHead, "TC_");
		break;

	case NCMethod:			// NCARD 通用接口卡
		sprintf(flagHead, "NC_");
		break;
		
	case AU3Method:			// AutoIT 接口
		sprintf(flagHead, "AU3_");
		break;

	case DWGMethod:			// DWG接口
		sprintf(flagHead, "DWG_");
		break;

	case OSCMethod:			// OSC接口
		sprintf(flagHead, "OSC_");
		break;
	}
	MethodFactory *pMethodFactory = NULL;
	pMethodFactory = MethodFactory::GetInstance();	
	if ( pMethodFactory == NULL)
	{
		sprintf(ErrMsg, "%s", "方法库实例未初始化!");
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}
	it = pMethodFactory->m_MethodMap.begin();
	i=0;
	while(it != pMethodFactory->m_MethodMap.end())
	{
		tmpStr = it->first;
		m_MethodSet = it->second;
		pos = tmpStr.find(flagHead);
		if(pos==0 && m_MethodSet.Visable == 1)
		{	
			sprintf(FunName[i], "%s", tmpStr.c_str());
			*(methodName + i) = *(FunName+i);
			i++;
		}	
		it++;
	}
	tmpcount = pMethodFactory->m_MethodMap.size();
	
	*count = i;
	
	//添加代码
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  MethodIsInLib
* 作者:	 dolob.jiang
* 日期  2009.12.12
* 参数: char *methodName, unsigned short *IsInLib
* 功能:  验证某个方法名是否合法
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     MethodIsInLib(char *methodName, unsigned short *IsInLib)
{
	TMethodMap::iterator it;
	int i = 0;
	char ErrMsg[1024];
	MethodFactory *pMethodFactory = NULL;
	pMethodFactory = MethodFactory::GetInstance();	
	if ( pMethodFactory == NULL)
	{
		sprintf(ErrMsg, "%s", "方法库实例未初始化!");
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}

	it = pMethodFactory->m_MethodMap.begin();
	for (int j = 0; j < pMethodFactory->m_MethodMap.size(); j++)
	{
		if (strcmp(it->first.c_str(), methodName) == 0)
		{
			break;
		}
		it++;
	}
	if (it == pMethodFactory->m_MethodMap.end())
	{
		*IsInLib = 0;
	}
	else
	{
		*IsInLib = 1;
	}

	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  CreateMethod
* 作者:	 dolob.jiang
* 日期  2009.10.12
* 参数: char *methodName, int *methodHandle
* 功能:  创建一个方法
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     CreateMethod(char *methodName, int *methodHandle)
{
	TMethodMap::iterator it;
	MethodNameStruct m_MethodSet;
	char ErrMsg[1024] = {0};

	MethodFactory *pMethodFactory = NULL;
	pMethodFactory = MethodFactory::GetInstance();	
	if ( pMethodFactory == NULL)
	{
		sprintf(ErrMsg, "%s", "方法库实例未初始化!");
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}
	
	it = pMethodFactory->m_MethodMap.find(methodName);
	
	if (it == pMethodFactory->m_MethodMap.end())
	{
		sprintf(ErrMsg, "%s为非法方法,在方法库中没有注册", methodName);
		NTS_Error(ErrMsg);
		return NTS_INVALID_PARA;
	}
	for (int i = 0; i <= MAXMETHOD; i++)
	{
		if (!gMethodDev[i])
		{
			m_MethodSet = it->second;
			gMethodDev[i] = pMethodFactory->CreateMethod(m_MethodSet.MethodID, methodName);
			if (!gMethodDev[i])
			{
				sprintf(ErrMsg, "创建%s方法失败", methodName);
				NTS_Error(ErrMsg);
				return NTS_INVALID_DEVICE;
			}
			*methodHandle = i;
			return NTS_SUCCESS;
		}
	}	
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  DeleteMethod
* 作者:	 dolob.jiang
* 日期  2009.10.12
* 参数: int methodHandle
* 功能:  删除一个方法
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     DeleteMethod(int methodHandle)
{
	
	if(methodHandle<0)
	{
		return NTS_INVALID_DEVICE;
	}
	if (methodHandle > MAXMETHOD)
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	delete gMethodDev[methodHandle];
	gMethodDev[methodHandle] =0;
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetMethodScript
* 作者:	 dolob.jiang
* 日期  2009.10.12
* 参数: int methodHandle, char *Script
* 功能:  获取方法功能描述语
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetMethodScript(int methodHandle, char *Script)
{
	if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	return gMethodDev[methodHandle]->GetMethodScript(Script);
}

/******************************************************************************
* 函数名称:  SetMethodScript
* 作者:	 dolob.jiang
* 日期  2009.10.12
* 参数: int methodHandle, char *Script
* 功能:  设置方法功能描述语
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	SetMethodScript(int methodHandle, char *Script)
{
	if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	return gMethodDev[methodHandle]->SetMethodScript(Script);
}

/******************************************************************************
* 函数名称:  GetInputParamNum
* 作者:	 dolob.jiang
* 日期  2009.10.12
* 参数: int methodHandle, unsigned short *inputParamNum
* 功能:  获取方法的输入个数
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetInputParamNum(int methodHandle, unsigned short *inputParamNum)
{
	TParamSetVector m_paramSetVector;
	if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	int retVal = gMethodDev[methodHandle]->GetInputParam(&m_paramSetVector);
	if (retVal != NTS_SUCCESS)
	{
		return retVal;
	}
	*inputParamNum = m_paramSetVector.size();
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetInputParaInfo
* 作者:	 dolob.jiang
* 日期  2009.12.12
* 参数: int methodHandle, unsigned short inputParamIndex, char *paramName, int *paramType, 
		unsigned short *paramNum, char *paramVal, char *paramUnit
* 功能: 获取某个输入参数的详细信息(参数名|参数类型|参数个数|参数值|单位) 
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int  __stdcall    GetInputParaInfo(int methodHandle, unsigned short inputParamIndex, 
														 char *paramName, int *paramType, 
														 unsigned short *paramNum, char *paramVal, char *paramUnit)
{
	char ErrMsg[1024];
	TParamSetVector m_paramSetVector;

	try
	{
		if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
		{
			return NTS_INVALID_DEVICE;
		}
		if (!gMethodDev[methodHandle]) 
		{
			return NTS_INVALID_DEVICE;
		}
		int retVal = gMethodDev[methodHandle]->GetInputParam(&m_paramSetVector);
		if (retVal != NTS_SUCCESS)

		{
			return retVal;
		}
		if (inputParamIndex >= m_paramSetVector.size())
		{
			return NTS_INVALID_PARA;
		}
		sprintf(paramName, m_paramSetVector[inputParamIndex]->paramName);
		sprintf(paramVal, m_paramSetVector[inputParamIndex]->paramVal);
		sprintf(paramUnit, m_paramSetVector[inputParamIndex]->paramUnit);
		*paramType = m_paramSetVector[inputParamIndex]->paramType;
		*paramNum = m_paramSetVector[inputParamIndex]->paramCount;
		return NTS_SUCCESS;
	}
	catch (std::exception &e)
	{
		sprintf(ErrMsg, "异常错误:%s", e.what());
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}

}

/******************************************************************************
* 函数名称:  SetInputParamVal
* 作者:	 dolob.jiang
* 日期  2009.10.12
* 参数: int methodHandle, unsigned short inputParamIndex, char *paramVal
* 功能:  设置某个参数的参数值
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int  __stdcall    SetInputParamVal(int methodHandle, unsigned short inputParamIndex, char *paramVal)
{
	TParamSetVector vParamSetVector;
	ParamSetStruct *pParamSetStruct;
	int vLength, vInputParaCount;
	
	vLength = strlen(paramVal);
	//清空容器中的记录
	vParamSetVector.clear();
	
	if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	//将参数信息拷贝到一个容器中
	int retVal = gMethodDev[methodHandle]->GetInputParam(&vParamSetVector);
	if (retVal != NTS_SUCCESS)
	{
		return retVal;
	}
	//输入参数个数
	vInputParaCount = vParamSetVector.size();
	if (inputParamIndex >= vInputParaCount)
	{
		return NTS_INVALID_PARA;
	}
	if( vLength > PARALENGTH)				//大数据处理
	{	
		pParamSetStruct = NULL;
		pParamSetStruct = vParamSetVector[inputParamIndex];		
		//为大数据动态分配内存空间			
		vParamSetVector[inputParamIndex]->LparamVal = (char *)malloc((vLength + 10) * sizeof(char));		
		sprintf(pParamSetStruct->LparamVal, "%s", paramVal);	
	}
	else
	{
		pParamSetStruct = NULL;			
		pParamSetStruct = vParamSetVector[inputParamIndex];
		sprintf(vParamSetVector[inputParamIndex]->paramVal, paramVal);
	}	
	gMethodDev[methodHandle]->SetInputParam(vParamSetVector);
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  SetInputParamVal
* 作者:	 dolob.jiang
* 日期  2009.10.12
* 参数: unsigned short inputParamIndex, char *paramVal, long Len
* 功能:  设置某个参数的参数值(扩展内存长度) 
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int  __stdcall    SetInputParamValEx(int methodHandle, unsigned short inputParamIndex, char *paramVal, long Len)
{
	
	TParamSetVector vParamSetVector;
	ParamSetStruct *pParamSetStruct;
	int vLength, vInputParaCount;
	
	vLength = Len;
	if (vLength <= 0) 
	{
		return NTS_INVALID_PARA;
	}
	//清空容器中的记录
	vParamSetVector.clear();
	
	if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	//将参数信息拷贝到一个容器中
	int retVal = gMethodDev[methodHandle]->GetInputParam(&vParamSetVector);
	if (retVal != NTS_SUCCESS)
	{
		return retVal;
	}
	//输入参数个数
	vInputParaCount = vParamSetVector.size();
	if (inputParamIndex >= vInputParaCount)
	{
		return NTS_INVALID_PARA;
	}
	if( vLength > PARALENGTH)				//大数据处理
	{	
		pParamSetStruct = NULL;
		pParamSetStruct = vParamSetVector[inputParamIndex];		
		//为大数据动态分配内存空间			
		vParamSetVector[inputParamIndex]->LparamVal = (char *)malloc((vLength + 10) * sizeof(char));	
		memset(vParamSetVector[inputParamIndex]->LparamVal, 0, vLength + 10);
		memcpy(vParamSetVector[inputParamIndex]->LparamVal, paramVal, vLength);	
	}
	else
	{
		pParamSetStruct = NULL;			
		pParamSetStruct = vParamSetVector[inputParamIndex];
		memset(vParamSetVector[inputParamIndex]->paramVal, 0, sizeof(vParamSetVector[inputParamIndex]->paramVal) );
		memcpy(vParamSetVector[inputParamIndex]->paramVal, paramVal, vLength);
		vParamSetVector[inputParamIndex]->paramCount = vLength;
	}	
	gMethodDev[methodHandle]->SetInputParam(vParamSetVector);
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetOutputParamNum
* 作者:	 dolob.jiang
* 日期  2009.12.12
* 参数: int methodHandle, unsigned short *outputParamNum
* 功能:  获取方法的输出参数个数
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetOutputParamNum(int methodHandle, unsigned short *outputParamNum)
{
	TParamSetVector m_paramSetVector;

	if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	int retVal = gMethodDev[methodHandle]->GetOutputParam(&m_paramSetVector);
	if (retVal != NTS_SUCCESS)
	{
		return retVal;
	}
	*outputParamNum = m_paramSetVector.size();
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetOutputParaInfo
* 作者:	 dolob.jiang
* 日期  2009.12.12
* 参数: int methodHandle, unsigned short outputParamIndex,char *paramName, int *paramType, 
		unsigned short *paramNum, char *paramVal, char *paramUnit
* 功能:  获取某个输出参数的参数详细信息(参数名|参数类型|参数个数|参数值|单位)
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int  __stdcall    GetOutputParaInfo(int methodHandle, unsigned short outputParamIndex, 
																char *paramName, int *paramType, 
																unsigned short *paramNum, char *paramVal, char *paramUnit)
{
	TParamSetVector m_paramSetVector;
	int ParaCount, index;
	char ErrMsg[1024];
	
	try
	{
	
		if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
		{
			return NTS_INVALID_DEVICE;
		}
		if (!gMethodDev[methodHandle]) 
		{
			return NTS_INVALID_DEVICE;
		}
		int retVal = gMethodDev[methodHandle]->GetOutputParam(&m_paramSetVector);
		if (retVal != NTS_SUCCESS)
		{
			return retVal;
		}
		//输出参数个数
		ParaCount = m_paramSetVector.size();
		if (outputParamIndex >= ParaCount )
		{
			return NTS_INVALID_PARA;
		}
		index = outputParamIndex;
		if(m_paramSetVector[index]->LparamVal != NULL)
		{
			
			sprintf(paramName, m_paramSetVector[index]->paramName);
			sprintf(paramVal, m_paramSetVector[index]->LparamVal);
			sprintf(paramUnit, m_paramSetVector[index]->paramUnit);
			*paramType = m_paramSetVector[index]->paramType;
			*paramNum = m_paramSetVector[index]->paramCount;
		}
		else
		{		
			sprintf(paramName, m_paramSetVector[index]->paramName);
			sprintf(paramVal, m_paramSetVector[index]->paramVal);
			sprintf(paramUnit, m_paramSetVector[index]->paramUnit);
			*paramType = m_paramSetVector[index]->paramType;
			*paramNum = m_paramSetVector[index]->paramCount;
		}
	}
	catch (std::exception &e)
	{
		sprintf(ErrMsg, "异常错误:%s", e.what());
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}

	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  DoMethodRun
* 作者:	 dolob.jiang
* 日期  2009.12.12
* 参数: int methodHandle
* 功能:  运行方法
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	DoMethodRun(int methodHandle)
{
	char ErrMsg[1024];
	
	try
	{		
		if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
		{
			return NTS_INVALID_DEVICE;
		}
		if (!gMethodDev[methodHandle]) 
		{
			return NTS_INVALID_DEVICE;
		}
		return gMethodDev[methodHandle]->Run();
	}
	catch (std::exception &e)
	{
		sprintf(ErrMsg, "异常错误:%s", e.what());
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}
}

/******************************************************************************
* 函数名称:  GetADMethodName
* 作者:	 dolob.jiang
* 日期  2009.12.12
* 参数: char *ProductName, char **MethodName, int *Count
* 功能:  获取产品的调试/校准方法
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetADMethodName(char *ProductName, char **MethodName, int *Count)
{

	char Name[50][50] = {0};
	int tmpcount = 0 ;
	sprintf(Name[0],"DEB_WriteDebug");
	sprintf(Name[1],"ADJ_WriteCal");

	tmpcount = 2;
	for(int i = 0;i<tmpcount;i++)
	{
		*(MethodName+i)  = *(Name+i);
	}
	*Count = tmpcount;
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetParaName
* 作者:	 dolob.jiang
* 日期  2009.10.12
* 参数: char **TypeName ,int *Count
* 功能:  获取参数类型
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetParaName(char **TypeName ,int *Count)
{
	char Name[50][50] = {0};
	int tmpcount = 0 ;
	
	sprintf(Name[0],"NTSInt16");
	sprintf(Name[1],"NTSInt8");
	sprintf(Name[2],"NTSInt32");
	sprintf(Name[3],"NTSUInt16");
	sprintf(Name[4],"NTSUInt8");
	sprintf(Name[5],"NTSUInt32");
	sprintf(Name[6],"NTSInt16Array");
	sprintf(Name[7],"NTSInt8Array");
	sprintf(Name[8],"NTSInt32Array");
	sprintf(Name[9],"NTSUInt16Array");
	sprintf(Name[10],"NTSUInt8Array");
	sprintf(Name[11],"NTSUInt32Array");
	sprintf(Name[12],"NTSString");
	sprintf(Name[13],"NTSReal32");
	sprintf(Name[14],"NTSReal64");
	sprintf(Name[15],"NTSReal32Array");
	sprintf(Name[16],"NTSReal64Array");
	sprintf(Name[17],"NTSSWLinkString");
	sprintf(Name[18],"NTSPChar");
	
	tmpcount = 19;
	for(int i = 0;i<tmpcount;i++)
	{
		*(TypeName+i)  = *(Name+i);
	}
	*Count = tmpcount;
	return NTS_SUCCESS;	
}

/******************************************************************************
* 函数名称:  GetConnectStr
* 作者:	 dolob.jiang
* 日期  2009.10.12
* 参数: int DeviceType, int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* 功能:  获取设备的连接字符串
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetConnectStr(int DeviceType, int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vProductName[50];
	int retVal;
	short int DevHandle;

	char IP[50] = {0};
	char Instrument_Descriptor[500], vInfoStr[200], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i, j, index;	
	int DPDCount;
	std::vector<std::string> vVectorString;
	
	DPDCount = 0;
	Return_Count = 0;
	sprintf(vProductName, ProductName);
	//设备类型
	switch(DeviceType) 
	{
	case NTS:
		break;

	case  SG:
		retVal = GetConnectStrOfSG(Interface, inParaStr, ProductName, vConnectStr);
		break;

	case PSA:
		retVal = GetConnectStrOfPSA(Interface, inParaStr, ProductName, vConnectStr);
		break;

	case ENA:
		retVal = GetConnectStrOfENA(Interface, inParaStr, ProductName, vConnectStr);
		break;

	case NFA:
		retVal = GetConnectStrOfNFA(Interface, inParaStr, ProductName, vConnectStr);
		break;

	case MMT:
		return NTS_INVALID_PARA;		
		break;

	case SWI:
		if (Interface != 3)
		{
			return NTS_INVALID_PARA;
		}
		if (strlen(inParaStr) == 0 )
		{
			return NTS_INVALID_PARA;	
		}
		sprintf(vConnectStr, "%s%s%s","NTS::SW::SW::COM",inParaStr,"::CARD");
		retVal = SW_OpenDev(vConnectStr, &DevHandle);
		if (retVal != NTS_SUCCESS)
		{
			return NTS_INVALID_PARA;	
		}	
		SW_CloseDev(DevHandle);
		break;

	case DPD:
		retVal = GetConnectStrOfDPD(Interface, inParaStr, ProductName, vConnectStr);		
		break;

	case  PRM:
		retVal = GetConnectStrOfPRM(Interface, inParaStr, ProductName, vConnectStr);	
		break;

	case IRU:
		retVal = GetConnectStrOfIRU(Interface, inParaStr, ProductName, vConnectStr);
		break;

	case DWG:
		retVal = GetConnectStrOfDWG(Interface, inParaStr, ProductName, vConnectStr);
		break;

	case OSC:
		retVal = GetConnectStrOfOSC(Interface, inParaStr, ProductName, vConnectStr);
		break;

	default:		
		if(Interface == GPIB)				//GPIB
		{
			retVal = viGetDefaultRM(&Rsmanager);
			if(retVal < VI_SUCCESS)
			{			
				return NTS_INVALID_DEVICE;
			}
			retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
			if(retVal >= 0 &&Return_Count > 0)
			{				
				for(i = 0 ; i< Return_Count; i++)
				{	
					//打开设备
					viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
					//产商信息
					viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
					sprintf(manfName,"%s", NTS_Trim(vInfoStr));
					
					//设备型号
					sprintf(vInfoStr , ""); 
					viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
					sprintf(DevTypeName,"%s", NTS_Trim(vInfoStr));
										
					//关闭设备
					viClose(vi);
					
					//安捷伦仪器
					if (strcmp(manfName,"Agilent Technologies")== 0)
					{
						sprintf(manfName, "%s", "AGILENT");						
					}
					// R&S仪器
					else if (strcmp(manfName,"Rohde&Schwarz")== 0)
					{
						sprintf(manfName, "%s", "RS");
					}								
					if(i == 0)
					{
						sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
					}
					else
					{						
						sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
					}			
					viFindNext (Find_Handle,Instrument_Descriptor);
				}
			}
			viClose(Rsmanager);
		}
		else if(Interface == LAN)			//Lan
		{
			sprintf(IP, inParaStr);
			//输入IP地址错误
			if(strlen(IP) <= 9)
			{
				return NTS_INVALID_PARA;
			}
			sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
			retVal = viGetDefaultRM(&Rsmanager);
			if(retVal < VI_SUCCESS)
			{			
				return NTS_INVALID_DEVICE;
			}		
			//打开设备
			retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
			if(retVal < VI_SUCCESS)
			{			
				return NTS_INVALID_DEVICE;
			}
			//产商信息
			viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
			sprintf(manfName,vInfoStr);
			
			//设备型号
			sprintf(vInfoStr , ""); 
			viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
			for(index = 0,j=0; j<strlen(vInfoStr); j++)
			{
				if(vInfoStr[j]!=' ')
				{
					DevTypeName[index] = vInfoStr[j]; 
					index++;
				}
			}
			DevTypeName[index] = '\0';		
			//关闭设备
			viClose(vi);			
			sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
			
//			return NTS_INVALID_PARA;
		}
		else if(Interface == COM)			//Com
		{				
			retVal = NTS_OpenCom(inParaStr, &DevHandle);
			if(retVal != NTS_SUCCESS)
			{
				return NTS_INVALID_DEVICE;
			}	
			retVal = NTS_SetCom(DevHandle, 9600, 8, 0, 1);
			if(retVal != NTS_SUCCESS)
			{
				NTS_CloseCom(DevHandle);
				return NTS_INVALID_DEVICE;
			}
									
			sprintf(vInfoStr, "%s\n", "*IDN?");			
			retVal = NTS_WriteCom(DevHandle, vInfoStr, strlen(vInfoStr));
			if(retVal != NTS_SUCCESS)
			{
				NTS_CloseCom(DevHandle);
				return NTS_INVALID_DEVICE;
			}
			Sleep(1000);
			retVal = NTS_ReadCom(DevHandle,Instrument_Descriptor, sizeof(Instrument_Descriptor), &Return_Count);
			if(retVal != NTS_SUCCESS)
			{
				NTS_CloseCom(DevHandle);
				return NTS_INVALID_DEVICE;
			}			
			retVal = NTS_CloseCom(DevHandle);
			// 分离字符串
			NTS_SeparateStr(Instrument_Descriptor, ",", &vVectorString);
			if ( vVectorString.size() >= 2)
			{
				sprintf(manfName, "%s", vVectorString[0].c_str());
				NTS_Trim(manfName);
				sprintf(DevTypeName, "%s", vVectorString[1].c_str());
				NTS_Trim(DevTypeName);
				sprintf(vConnectStr, "%s::%s::COM::%s::INSTR", manfName, DevTypeName, inParaStr);
			}						
		}
		if(Interface == USB)				//USB
		{
			retVal = viGetDefaultRM(&Rsmanager);
			if(retVal < VI_SUCCESS)
			{			
				return NTS_INVALID_DEVICE;
			}
			retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
			if(retVal >= 0 &&Return_Count > 0)
			{				
				for(i = 0 ; i< Return_Count; i++)
				{	
					//打开设备
					viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
					//产商信息
					viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
					sprintf(manfName,"%s", NTS_Trim(vInfoStr));
					
					//设备型号
					sprintf(vInfoStr , ""); 
					viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
					sprintf(DevTypeName,"%s", NTS_Trim(vInfoStr));
					
					//关闭设备
					viClose(vi);
					
					//安捷伦仪器
					if (strcmp(manfName,"Agilent Technologies")== 0)
					{
						sprintf(manfName, "%s", "AGILENT");						
					}
					// R&S仪器
					else if (strcmp(manfName,"Rohde&Schwarz")== 0)
					{
						sprintf(manfName, "%s", "RS");
					}								
					if(i == 0)
					{
						sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
					}
					else
					{						
						sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
					}			
					viFindNext (Find_Handle,Instrument_Descriptor);
				}
			}
			viClose(Rsmanager);
		}

		break;
	} 
	
	
	if (strlen(vConnectStr) == 0)
	{
		return NTS_INVALID_PARA;	
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetDeviceMethod
* 作者:	 dolob.jiang
* 日期  2009.12.22
* 参数: int DeviceType, char *ConnectStr, char **Name, int *Count
* 功能:  获取设备的驱动方法名
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetDeviceMethod(int DeviceType, char *ConnectStr, char **Name, int *Count)
{
	std::string protoclString(ConnectStr);
	std::vector<std::string> subProtocls;
	std::string::size_type pos = 0, oldPos = 0;
	char vMethodName[1024][50] = {0};

	char vDriverName[100] = {0};
	char ProductName[50] = {0};

	//获取驱动库中的函数名
	char fileName[1024];
	char *Fns[3000] = {0};
	char SubFn[100] = {0};
	int i, FnCount, FnParaCount;
	HMODULE DllHandle;
	
	do
	{
		pos = protoclString.find("::", oldPos);
		if (pos != std::string::npos)
		{
			subProtocls.push_back(protoclString.substr(oldPos, pos - oldPos));
			oldPos = pos + 2;
		}
		else 
		{
			subProtocls.push_back(protoclString.substr(oldPos, pos));
			break;
		}
	}while(true);
	if (subProtocls.size() == 0)
	{
		return NTS_INVALID_PROTOCL;
	}
	
	switch(DeviceType)
	{
	case NTS:
		if(subProtocls.size() < 4)			//V1
		{
			sprintf(ProductName,"%s",subProtocls[0].c_str());
		}
		else								//V2
		{
			sprintf(ProductName,"%s",subProtocls[1].c_str());
		}		
		//产商::型号::协议名::接口::固定值
		protoclString = ProductName;
		pos = 0;
		oldPos = 0;
		do
		{
			pos = protoclString.find("ComDevice", oldPos);
			if (pos != std::string::npos)
			{
				sprintf(ProductName,(protoclString.substr(oldPos, pos - oldPos)).c_str());
				oldPos = pos + strlen("ComDevice");
			}
			else 
			{				
				break;
			}
		}while(true);
		//驱动库名称
		sprintf(vDriverName, "%s%s", ProductName, "Driver.dll");		
		break;
		
	case  SG:
		//产品名称
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//驱动库名称
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case PSA:
		//产品名称
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//驱动库名称
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;

	case ENA:
		//产品名称
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//驱动库名称
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case NFA:
		//产品名称
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//驱动库名称
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case MMT:
		//产品名称
		sprintf(ProductName,"%s","MMT");
		//驱动库名称
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case SWI:
		//产品名称
		sprintf(ProductName,"%s","SW");
		//驱动库名称
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case DPD:
		//产商::型号::协议名::接口::固定值 (如:"NTS::ZXDPD::TCPIP::100.191.3.2::T3440ZXDPDCARD")
		//产品名称
		sprintf(ProductName,"%s",subProtocls[4].c_str());
		ProductName[strlen(ProductName) - 4] = '\0';		
		//
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case  PRM:
		//产品名称
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//驱动库名称
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case IRU:
		//产品名称
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//驱动库名称
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;

	case DWG:
		//产品名称
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//驱动库名称
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;

	case OSC:
		//产品名称
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//驱动库名称
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
	}
	DllHandle = NULL;
	DllHandle = LoadLibrary(vDriverName) ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return NTS_LOADDLL_ERROR;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}
	
	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		if(strcmp(SubFn, "NTS_SetWorkModeA") == 0)
		{
			sprintf(vMethodName[i], "%s", "NTS_SetWorkModeEx");	
		}
		else if(strcmp(SubFn, "NTS_GetWorkModeA") == 0)
		{
			sprintf(vMethodName[i], "%s", "NTS_GetWorkModeEx");	
		} 
		else if (strcmp(SubFn, "SG_SetArbWave") == 0)
		{
            sprintf(vMethodName[i], "%s", "SG_SetWaveFile");	
		} 
		else if (strcmp(SubFn, "PSA_SetMarkPosition") == 0)
		{
			sprintf(vMethodName[i], "%s", "PSA_SetMarkFreq");
		}
		else
		{		
			sprintf(vMethodName[i], "%s", SubFn);		
		}
		*(Name + i) = vMethodName[i];
	}
	// 设备驱动库中没有的方法，但在方法库也存在的方法，需要手动增加
	switch(DeviceType) 
	{
	case NTS:			
		break;
		
	case  SG:
		break;
		
	case PSA:
		break;

	case OSC:
		break;

	case DWG:
		break;
		
	case ENA:		
		break;
		
	case NFA:		
		break;
		
	case MMT:		
		break;
		
	case SWI:		
		break;
		
	case DPD:
		sprintf(vMethodName[FnCount], "%s", "DPD_SetErrPwrDebug");
		*(Name + FnCount) = vMethodName[FnCount];		
		FnCount++;
		
		sprintf(vMethodName[FnCount], "%s", "DPD_SetErrPwrDebugDT");
		*(Name + FnCount) = vMethodName[FnCount];
		FnCount++;

		sprintf(vMethodName[FnCount], "%s", "DPD_ACPRPowerDebug");
		*(Name + FnCount) = vMethodName[FnCount];
		FnCount++;

		sprintf(vMethodName[FnCount], "%s", "DPD_ACPRPowerDebugDT");
		*(Name + FnCount) = vMethodName[FnCount];
		FnCount++;

		sprintf(vMethodName[FnCount], "%s", "DPD_PRMPowerDebug");
		*(Name + FnCount) = vMethodName[FnCount];
		FnCount++;
		break;
		
	case  PRM:	
		break;
		
	case IRU:		
		break;
	}
	*Count = FnCount;
	
	return NTS_SUCCESS;
}


/******************************************************************************
* 函数名称:  GetDevicePreName
* 作者:	 dolob.jiang
* 日期  2009.12.22
* 参数: int DeviceType, char **Name, int *Count
* 功能:  获取设备的前缀名(DeviceType 0:All)
* 返回值:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetDevicePreName(int DeviceType, char **Name, int *Count)
{
	char vPreName[100][50] = {0};	
	int i = 0;
	int tmpcount;	
	
	switch(DeviceType)
	{
	case 0:					// All
		sprintf(vPreName[0], "NTS_");			//产品		
		sprintf(vPreName[1], "SG_");			//信号源				
		sprintf(vPreName[2], "PSA_");			//频谱仪			
		sprintf(vPreName[3], "ENA_");			//网络仪				
		sprintf(vPreName[4], "NFA_");			//噪声仪				
		sprintf(vPreName[5], "SPE_");			//噪声仪					
		sprintf(vPreName[6], "MMT_");			//完用表				
		sprintf(vPreName[7], "SW_");			//矩阵开关			
		sprintf(vPreName[8], "DPD_");			//DPD板			
		sprintf(vPreName[9], "PRM_");			//功率计			
		sprintf(vPreName[10], "IRU_");			//IRU
		sprintf(vPreName[11], "NC_");			// NCARD
		sprintf(vPreName[12], "DWG_");			// DWG
		sprintf(vPreName[13], "OSC_");			// OSC
		tmpcount = 14;
		break;

	case NTS:				
		sprintf(vPreName[0], "NTS_");			//产品
		tmpcount = 1;
		break;

	case SG:				
		sprintf(vPreName[0], "SG_");			//信号源
		tmpcount = 1;
		break;

	case NFA:			
		sprintf(vPreName[0], "NFA_");			//噪声仪
		tmpcount = 1;
		break;

	case PSA:				
		sprintf(vPreName[0], "PSA_");			//频谱仪
		tmpcount = 1;
		break;

	case ENA:				
		sprintf(vPreName[0], "ENA_");			//网络仪
		tmpcount = 1;
		break;	

	case MMT:				
		sprintf(vPreName[0], "MMT_");			//完用表
		tmpcount = 1;
		break;	

	case SWI:				
		sprintf(vPreName[0], "SW_");			//矩阵开关
		tmpcount = 1;
		break;

	case DPD:				
		sprintf(vPreName[0], "DPD_");			//DPD板
		tmpcount = 1;
		break;

	case PRM:				
		sprintf(vPreName[0], "PRM_");			//功率计
		tmpcount = 1;
		break;

	case IRU:				
		sprintf(vPreName[0], "IRU_");			//IRU
		tmpcount = 1;
		break;

	case NCARD:				
		sprintf(vPreName[0], "NC_");			// NCard 通用接口卡
		tmpcount = 1;
		break;

	case DWG:				
		sprintf(vPreName[0], "DWG_");			// DWG 通用接口卡
		tmpcount = 1;
		break;

	case OSC:				
		sprintf(vPreName[0], "OSC_");			// OSC 通用接口卡
		tmpcount = 1;
		break;
	}
	for(i = 0; i<tmpcount; i++)
	{	
		*(Name + i) = vPreName[i];
	}
	*Count = tmpcount;
	return NTS_SUCCESS;
}
#pragma hdrstop
/******************************************************************************
* 函数名称:  GetConnectStrOfOSC
* 作者:	 dolob.jiang
* 日期  2009.12.21
* 参数: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* 功能:  获取OSC设备的连接字符串
* 返回值:  无
******************************************************************************/
int GetConnectStrOfOSC(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100] = {0};
	char IP[50] = {0};
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i;
	
	int OSCCount;
	
	Return_Count = 0;
	OSCCount = 0;
	
	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//打开设备
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//产商信息
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", NTS_Trim(vInfoStr));
				
				//设备型号
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
				
				//关闭设备
				viClose(vi);
				
				if(OSCCount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				OSCCount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		sprintf(IP, inParaStr);
		//输入IP地址错误
		if(strlen(IP) <= 9)
		{
			return NTS_INVALID_PARA;
		}
		sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//打开设备
		retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//产商信息
		viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
		sprintf(manfName,"%s", NTS_Trim(vInfoStr));
		
		//设备型号
		sprintf(vInfoStr , ""); 
		viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
		sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
		
		if(OSCCount == 0)
		{
			sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
		}
		else
		{						
			sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
		}
		OSCCount++;	
		//关闭设备
		viClose(vi);
		viClose(Rsmanager);
		
	}
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}
	else if(Interface == USB)			//USB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//打开设备
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//产商信息
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName, "%s", NTS_Trim(vInfoStr));
				
				//设备型号
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
				
				//关闭设备
				viClose(vi);
				
				if(OSCCount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				OSCCount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
		
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetConnectStrOfDWG
* 作者:	 dolob.jiang
* 日期  2009.12.21
* 参数: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* 功能:  获取DWG设备的连接字符串
* 返回值:  无
******************************************************************************/
int GetConnectStrOfDWG(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100] = {0};
	char IP[50] = {0};
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i;
	
	int DWGCount;
	
	Return_Count = 0;
	DWGCount = 0;
	
	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//打开设备
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//产商信息
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", NTS_Trim(vInfoStr));
				
				//设备型号
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
				
				//关闭设备
				viClose(vi);
				
				if(DWGCount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				DWGCount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		sprintf(IP, inParaStr);
		//输入IP地址错误
		if(strlen(IP) <= 9)
		{
			return NTS_INVALID_PARA;
		}
		sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//打开设备
		retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//产商信息
		viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
		sprintf(manfName,"%s", NTS_Trim(vInfoStr));
		
		//设备型号
		sprintf(vInfoStr , ""); 
		viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
		sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
		
		if(DWGCount == 0)
		{
			sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
		}
		else
		{						
			sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
		}
		DWGCount++;	
		//关闭设备
		viClose(vi);
		viClose(Rsmanager);
		
	}
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}
	else if(Interface == USB)			//USB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//打开设备
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//产商信息
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName, "%s", NTS_Trim(vInfoStr));
				
				//设备型号
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
				
				//关闭设备
				viClose(vi);
				
				if(DWGCount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				DWGCount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
		
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetConnectStrOfPSA
* 作者:	 dolob.jiang
* 日期  2009.12.21
* 参数: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* 功能:  获取PSA设备的连接字符串
* 返回值:  无
******************************************************************************/
int GetConnectStrOfPSA(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100] = {0};
	char IP[50] = {0};
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i;
	
	int PSACount;
	
	Return_Count = 0;
	PSACount = 0;
	
	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//打开设备
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//产商信息
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", NTS_Trim(vInfoStr));
				
				//设备型号
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
				
				//关闭设备
				viClose(vi);
				
				if(PSACount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				PSACount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		sprintf(IP, inParaStr);
		//输入IP地址错误
		if(strlen(IP) <= 9)
		{
			return NTS_INVALID_PARA;
		}
		sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//打开设备
		retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//产商信息
		viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
		sprintf(manfName,"%s", NTS_Trim(vInfoStr));
		
		//设备型号
		sprintf(vInfoStr , ""); 
		viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
		sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
		
		if(PSACount == 0)
		{
			sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
		}
		else
		{						
			sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
		}
		PSACount++;	
		//关闭设备
		viClose(vi);
		viClose(Rsmanager);
		
	}
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}
	else if(Interface == USB)			//USB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//打开设备
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//产商信息
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName, "%s", NTS_Trim(vInfoStr));
				
				//设备型号
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
				
				//关闭设备
				viClose(vi);
				
				if(PSACount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				PSACount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
		
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetConnectStrOfSG
* 作者:	 dolob.jiang
* 日期  2009.12.21
* 参数: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* 功能:  获取SG设备的连接字符串
* 返回值:  无
******************************************************************************/
int GetConnectStrOfSG(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100] = {0};
	char IP[50];
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i,j,index;
	
	int SGCount;
	
	Return_Count = 0;
	SGCount = 0;
	
	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//打开设备
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//产商信息
			 	viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s",vInfoStr);

				//设备型号
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				memset(DevTypeName, 0, sizeof(DevTypeName));
				for(index = 0,j=0; j<strlen(vInfoStr); j++)
				{
					if(vInfoStr[j]!=' ')
					{
						DevTypeName[index] = vInfoStr[j]; 
						index++;
					}
				}
				DevTypeName[index] = '\0';
 				//关闭设备
				viClose(vi);
			
				if(SGCount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				SGCount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		sprintf(IP, inParaStr);
		//输入IP地址错误
		if(strlen(IP) <= 9)
		{
			return NTS_INVALID_PARA;
		}
		sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//打开设备
		retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//产商信息
		viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
		sprintf(manfName,vInfoStr);
		
		//设备型号
		sprintf(vInfoStr , ""); 
		viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
		for(index = 0,j=0; j<strlen(vInfoStr); j++)
		{
			if(vInfoStr[j]!=' ')
			{
				DevTypeName[index] = vInfoStr[j]; 
				index++;
			}
		}
		DevTypeName[index] = '\0';
		if(SGCount == 0)
		{
			sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
		}
		else
		{						
			sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
		}
		SGCount++;	
		//关闭设备
		viClose(vi);
		viClose(Rsmanager);
		
	}
	else if(Interface == USB)				//USB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//打开设备
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//产商信息
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", NTS_Trim(vInfoStr));
				
				//设备型号
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName,"%s", NTS_Trim(vInfoStr));
				
				//关闭设备
				viClose(vi);
				
				//安捷伦仪器
				if (strcmp(manfName,"Agilent Technologies")== 0)
				{
					sprintf(manfName, "%s", "AGILENT");						
				}
				// R&S仪器
				else if (strcmp(manfName,"Rohde&Schwarz")== 0)
				{
					sprintf(manfName, "%s", "RS");
				}								
				if(i == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
					SGCount++;
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
					SGCount++;
				}			
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}	
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetConnectStrOfENA
* 作者:	 dolob.jiang
* 日期  2009.12.21
* 参数: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* 功能:  获取ENA设备的连接字符串
* 返回值:  无
******************************************************************************/
int GetConnectStrOfENA(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100] = {0};
	char IP[50] = {0};
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i,j,index;
	
	int ENACount;
	
	Return_Count = 0;
	ENACount = 0;
	
	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//打开设备
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//产商信息
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", vInfoStr);
				
				//设备型号
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				memset(DevTypeName, 0, sizeof(DevTypeName));
				for(index = 0,j=0; j<strlen(vInfoStr); j++)
				{
					if(vInfoStr[j]!=' ')
					{
						DevTypeName[index] = vInfoStr[j]; 
						index++;
					}
				}
				DevTypeName[index] = '\0';
				//关闭设备
				viClose(vi);
				
				if(strcmp(DevTypeName,"8753ES")== 0) 
				{
					//网络仪
					if(ENACount == 0)
					{
						sprintf(vConnectStr, "%s::HP%s::%s", manfName, DevTypeName, Instrument_Descriptor);
					}
					else
					{						
						sprintf(vConnectStr, "%s,%s::HP%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
					}
					ENACount++;
				}
				else
				{
					//网络仪
					if(ENACount == 0)
					{
						sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
					}
					else
					{						
						sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
					}
					ENACount++;
				}
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		sprintf(IP, inParaStr);
		//输入IP地址错误
		if(strlen(IP) <= 9)
		{
			return NTS_INVALID_PARA;
		}
		sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//打开设备
		retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//产商信息
		viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
		sprintf(manfName,vInfoStr);
		
		//设备型号
		sprintf(vInfoStr , ""); 
		viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
		for(index = 0,j=0; j<strlen(vInfoStr); j++)
		{
			if(vInfoStr[j]!=' ')
			{
				DevTypeName[index] = vInfoStr[j]; 
				index++;
			}
		}
		DevTypeName[index] = '\0';
		if(strcmp(DevTypeName,"8753ES")== 0) 
		{
			//网络仪
			if(ENACount == 0)
			{
				sprintf(vConnectStr, "%s::HP%s::%s", manfName, DevTypeName, Instrument_Descriptor);
			}
			else
			{						
				sprintf(vConnectStr, "%s,%s::HP%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
			}
			ENACount++;
		}
		else
		{
			//网络仪
			if(ENACount == 0)
			{
				sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
			}
			else
			{						
				sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
			}
			ENACount++;
		}
		//关闭设备
		viClose(vi);
		viClose(Rsmanager);		
	}
	else if(Interface == USB)				//USB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//打开设备
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//产商信息
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", NTS_Trim(vInfoStr));
				
				//设备型号
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName,"%s", NTS_Trim(vInfoStr));
				
				//关闭设备
				viClose(vi);
				
				//安捷伦仪器
				if (strcmp(manfName,"Agilent Technologies")== 0)
				{
					sprintf(manfName, "%s", "AGILENT");						
				}
				// R&S仪器
				else if (strcmp(manfName,"Rohde&Schwarz")== 0)
				{
					sprintf(manfName, "%s", "RS");
				}								
				if(i == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}	
				ENACount++;
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}	
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetConnectStrOfNFA
* 作者:	 dolob.jiang
* 日期  2009.12.21
* 参数: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* 功能:  获取NFA设备的连接字符串
* 返回值:  无
******************************************************************************/
int GetConnectStrOfNFA(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100], IP[50];
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i,j,index;
	
	int NFACount;
	
	Return_Count = 0;
	NFACount = 0;

	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//打开设备
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//产商信息
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,vInfoStr);
				
				//设备型号
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				for(index = 0,j=0; j<strlen(vInfoStr); j++)
				{
					if(vInfoStr[j]!=' ')
					{
						DevTypeName[index] = vInfoStr[j]; 
						index++;
					}
				}
				DevTypeName[index] = '\0';
				//关闭设备
				viClose(vi);

				if(NFACount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				NFACount++;			

				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		sprintf(IP, inParaStr);
		//输入IP地址错误
		if(strlen(IP) <= 9)
		{
			return NTS_INVALID_PARA;
		}
		sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//打开设备
		retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//产商信息
		viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
		sprintf(manfName,vInfoStr);
		
		//设备型号
		sprintf(vInfoStr , ""); 
		viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
		for(index = 0,j=0; j<strlen(vInfoStr); j++)
		{
			if(vInfoStr[j]!=' ')
			{
				DevTypeName[index] = vInfoStr[j]; 
				index++;
			}
		}
		DevTypeName[index] = '\0';

		if(NFACount == 0)
		{
			sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
		}
		else
		{						
			sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
		}
		NFACount++;		

		//关闭设备
		viClose(vi);
		viClose(Rsmanager);
		
	}
	else if(Interface == USB)				//USB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//打开设备
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//产商信息
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", NTS_Trim(vInfoStr));
				
				//设备型号
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName,"%s", NTS_Trim(vInfoStr));
				
				//关闭设备
				viClose(vi);
				
				//安捷伦仪器
				if (strcmp(manfName,"Agilent Technologies")== 0)
				{
					sprintf(manfName, "%s", "AGILENT");						
				}
				// R&S仪器
				else if (strcmp(manfName,"Rohde&Schwarz")== 0)
				{
					sprintf(manfName, "%s", "RS");
				}								
				if(i == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}	
				NFACount++;
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}	
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}

	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetConnectStrOfPRM
* 作者:	 dolob.jiang
* 日期  2009.12.21
* 参数: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* 功能:  获取PRM设备的连接字符串
* 返回值:  无
******************************************************************************/
int GetConnectStrOfPRM(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100];
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i,j,index;
	
	int PRMCount;
	
	Return_Count = 0;
	PRMCount = 0;	
	
	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//打开设备
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//产商信息
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s",vInfoStr);
				
				//设备型号
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);   
				for(index = 0,j=0; j<strlen(vInfoStr); j++)
				{
					if(vInfoStr[j]!=' ')
					{
						DevTypeName[index] = vInfoStr[j]; 
						index++;
					}
				}
				DevTypeName[index] = '\0';
				//关闭设备
				viClose(vi);
				
				if(PRMCount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				PRMCount++;				
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		return NTS_INVALID_PARA;
	}
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  GetConnectStrOfIRU
* 作者:	 dolob.jiang
* 日期  2009.12.21
* 参数: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* 功能:  获取IRU设备的连接字符串
* 返回值:  无
******************************************************************************/
int GetConnectStrOfIRU(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	int retVal;
	int IP_Addr[4];
	unsigned long Return_Count;
	short int DevHandle;
	int i, j;
	int IRUCount;
	
	Return_Count = 0;
	IRUCount = 0;
	
	if(Interface == GPIB)					//GPIB 接口
	{
		return NTS_INVALID_PROTOCL;
	}
	else if (Interface == LAN)			//LAN 接口
	{
		if (strlen(inParaStr) == 0 )
		{
			return NTS_INVALID_PARA;	
		}
		//分离IP地址	
		IP_Addr[0] = atoi(&inParaStr[0]);					
		j = 1;
		for(i = 1;i < strlen(inParaStr);i++)
		{
			if (inParaStr[i] == '.') 
			{
				IP_Addr[j] = atoi(&inParaStr[i+1]);
				j++;
			}
		}		
		if (j!=4)
		{
			//输入IP地址不正确
			return NTS_INVALID_PARA;	
		}
		//判断IRU的类型 
		if (IP_Addr[0] == 192 && IP_Addr[1] == 168)
		{
			//测试R809产品用的IRU
			sprintf(vConnectStr, "%s%s%s","NTS::IRU01::TCPIP::",inParaStr,"::INSTR");
		}
	}
	else if (Interface == COM)			//COM 接口
	{
		return NTS_INVALID_PROTOCL;
	}
	else
	{
		return NTS_INVALID_PARA;	
	}
	
	retVal = IRU_OpenDev(vConnectStr, &DevHandle);
	if (retVal != NTS_SUCCESS)
	{
		return NTS_INVALID_PARA;	
	}
	IRU_CloseDev(DevHandle);

	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;

}

/******************************************************************************
* 函数名称:  GetConnectStrOfDPD
* 作者:	 dolob.jiang
* 日期  2009.12.21
* 参数: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* 功能:  获取DPD设备的连接字符串
* 返回值:  无
******************************************************************************/
int GetConnectStrOfDPD(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	int retVal;
	unsigned long Return_Count;
	short int DevHandle;
	int i, j;
	int DPDCount;
	
	Return_Count = 0;
	DPDCount = 0;
	
	if (Interface != 2)
	{
		return NTS_INVALID_PARA;
	}
	if (strlen(inParaStr) == 0 )
	{
		return NTS_INVALID_PARA;	
	}
	//分离IP地址
	int IP_Addr[4];
	IP_Addr[0] = atoi(&inParaStr[0]);					
	j = 1;
	
	for(i = 1;i < strlen(inParaStr);i++)
	{
		if (inParaStr[i] == '.') 
		{
			IP_Addr[j] = atoi(&inParaStr[i+1]);
			j++;
		}
	}		
	if (j!=4)
	{
		//输入IP地址不正确
		return NTS_INVALID_PARA;	
	}
	//判断DPD的类型 
	////////////////////////////ZX DPD//////////////////////////////////	
	if (IP_Addr[0] == 100 && IP_Addr[1] == 191 && IP_Addr[2] == 2)
	{
		//测试T7380ZX模块用的DPD板
		sprintf(vConnectStr, "%s%s%s","NTS::ZXDPD::TCPIP::",inParaStr,"::T7380ZXDPDCARD");
	}
	else if (IP_Addr[0] == 100 && IP_Addr[1] == 191 && IP_Addr[2] == 9)
	{
		//测试T9390ZX模块用的DPD板
		sprintf(vConnectStr, "%s%s%s","NTS::ZXDPD::TCPIP::",inParaStr,"::T9390ZXDPDCARD");
	}
	else if (IP_Addr[0] == 100 && IP_Addr[1] == 191 && IP_Addr[2] == 3)
	{
		//测试T3440ZX模块用的DPD板
		sprintf(vConnectStr, "%s%s%s","NTS::ZXDPD::TCPIP::",inParaStr,"::T3440ZXDPDCARD");
	}
	else if (IP_Addr[0] == 100 && IP_Addr[1] == 191 && IP_Addr[2] == 1)
	{
		//测试T1440ZX模块用的DPD板
		sprintf(vConnectStr, "%s%s%s","NTS::ZXDPD::TCPIP::",inParaStr,"::T1440ZXDPDCARD");
	}
	else if (IP_Addr[0] == 199 && IP_Addr[1] == 33 && IP_Addr[2] == 33)
	{
		//测试D500ZX模块用的DPD板
		sprintf(vConnectStr, "%s%s%s","NTS::ZXDPD::TCPIP::",inParaStr,"::D500ZXDPDCARD");
	}
	else if (IP_Addr[0] == 199 && IP_Addr[1] == 33 && IP_Addr[2] == 34)
	{
		//测试W3501ZX模块用的DPD板
		sprintf(vConnectStr, "%s%s%s","NTS::ZXDPD::TCPIP::",inParaStr,"::W3501ZXDPDCARD");
	}
	////////////////////////////DT DPD//////////////////////////////////	
	else if (IP_Addr[0] == 172 && IP_Addr[1] == 27 && (IP_Addr[2] == 4 || IP_Addr[2] ==45) )
	{
		//测试T4370DT模块用的DPD板
		sprintf(vConnectStr, "%s%s%s","NTS::DTDPD::TCPIP::",inParaStr,"::T4370DTDPDCARD");
	}
	else if (IP_Addr[0] == 172 && IP_Addr[1] == 27 && (IP_Addr[2] == 1) )
	{
		//测试T1440DT模块用的DPD板
		sprintf(vConnectStr, "%s%s%s","NTS::DTDPD::TCPIP::",inParaStr,"::T1440DTDPDCARD");
	}
	else if (IP_Addr[0] == 172 && IP_Addr[1] == 27 && (IP_Addr[2] == 2) )
	{
		//测试T2380DT模块用的DPD板
		sprintf(vConnectStr, "%s%s%s","NTS::DTDPD::TCPIP::",inParaStr,"::T2380DTDPDCARD");
	}
	else if (IP_Addr[0] == 172 && IP_Addr[1] == 27 && (IP_Addr[2] == 5) )
	{
		//测试T5394DT模块用的DPD板
		sprintf(vConnectStr, "%s%s%s","NTS::DTDPD::TCPIP::",inParaStr,"::T5394DTDPDCARD");
	}
	////////////////////////////NTS DPD//////////////////////////////////	
	else if (IP_Addr[0] == 192 && IP_Addr[1] == 168 && (IP_Addr[2] == 52) )
	{
		//测试T8390模块用的DPD板
		sprintf(vConnectStr, "%s%s%s","NTS::DTDPD::TCPIP::",inParaStr,"::T8390DPDCARD");
	}
	else
	{
		return NTS_INVALID_PARA;	
	}
	retVal = DPD_OpenDev(vConnectStr, &DevHandle);
	if (retVal != NTS_SUCCESS)
	{
		return NTS_INVALID_PARA;	
	}
	DPD_CloseDev(DevHandle);

	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;

}

/******************************************************************************
* 函数名称:  SetAttributeDev
* 作者:	 dolob.jiang
* 日期  2011.11.02
* 参数: char *ConnectStr, char *attrName,  int attrState
* 功能:  设置通信属性参数(CommIsStr)
* 返回值:  short int
******************************************************************************/
//  
NTSSCRIPTLIB_API short int	__stdcall	SetAttributeDev(char *ConnectStr, char *attrName,  int attrState)
{
	if (attrState == 0)
	{
		gCommIsStr = false;
	}
	else
	{
		gCommIsStr = true;
	}
	return NTS_SUCCESS;
}


 

// Every DLL has an entry point LibMain || DllEntryPoint
// and an exit point WEP.
BOOL APIENTRY DllMain (HANDLE hModule, DWORD fdwReason, LPVOID lpReserved)
{	
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		{
//			g_Instance = (HINSTANCE)hModule;
//		    g_Instance++;
		    break;
		}
		
	case DLL_THREAD_ATTACH:
		break;
		
	case DLL_THREAD_DETACH:
		break;
		
	case DLL_PROCESS_DETACH:
/*
		if (instance>0)
		{
			for (int i = 0; i < MAXMETHOD + 1; i++)
				if (gMethodDev[i])
				{
					delete gMethodDev[i];
					gMethodDev[i]=0;
				}
				instance--;
		}
*/

		break;
	}
	
	return 1;
}
