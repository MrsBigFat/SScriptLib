
#include "stdafx.h"
#include "NTSMethod.h"
#include <assert.h>
#include "stdio.h"


extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

/************************************************************************/
/*  公司模块驱动方法类                                                  */
/************************************************************************/

//M_NTS_OpenDev 
M_NTS_OpenDev::M_NTS_OpenDev()
:BaseMethod()
{
	sprintf(m_MethodScript,"打开设备(ConnectStr格式(厂商[自定义]::型号[设备型号]::接口[TCPIP|GPIB|COM]::地址参数::固定值))");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	Init();
}

M_NTS_OpenDev::~M_NTS_OpenDev()
{
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara1);
	
}

int M_NTS_OpenDev::Init(void)
{
	sprintf(m_InputPara1->paramName, "DevType");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "ConnectStr");
	m_InputPara2->paramType = NTSDevice;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"NTS::LT800::TCPIP::192.168.0.1::SOCKET,1::50000");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	
	sprintf(m_OutputPara1->paramName, "DeviceHandle");
	m_OutputPara1->paramType = NTSInt16;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"-1");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}

int M_NTS_OpenDev::Run(void)
{		
	int retVal;
	TDevcieType devType;
	int devHandle;
	devHandle = -1;
	devType = (TDevcieType)(atoi(m_InputPara1->paramVal));
    retVal = OpenDevice(devType, m_InputPara2->paramVal, &devHandle);
	if (retVal == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%d", devHandle);
	}
	return retVal;
}

//M_NTS_CloseDev 
M_NTS_CloseDev::M_NTS_CloseDev()
:BaseMethod()
{
	sprintf(m_MethodScript,"关闭设备");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_NTS_CloseDev::~M_NTS_CloseDev()
{
//	free(m_InputPara1);
//	free(m_InputPara2);
	
}

int M_NTS_CloseDev::Init(void)
{	
	sprintf(m_InputPara1->paramName, "DeviceType");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "ConnectStr");
	m_InputPara2->paramType = NTSDevice;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_NTS_CloseDev::Run(void)
{		
	TDevcieType devType;
	devType = TDevcieType(atoi(m_InputPara1->paramVal));
    return CloseDevice(devType, m_InputPara2->paramVal);
}


//class M_NTS_SetModuleFuncNo
/*
M_NTS_SetModuleFuncNo::M_NTS_SetModuleFuncNo()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置模块功能号(无效)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}

M_NTS_SetModuleFuncNo::~M_NTS_SetModuleFuncNo()
{
	free(m_InputDeviceName);
	free(m_InputPara);
}

int M_NTS_SetModuleFuncNo::Init()
{
	m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit , " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	m_InputPara->paramName, "FunctionNo";
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	m_InputPara->paramUnit , " ";
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}

int M_NTS_SetModuleFuncNo::Run()
{
	unsigned char functionNo;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	functionNo = (unsigned char)m_InputPara->paramVal;
	return NTS_SetModuleFuncNo(vHandle, functionNo);
}*/


//class M_NTS_SetModuleNo
/*
M_NTS_SetModuleNo::M_NTS_SetModuleNo()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置模块编号(无效)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}

M_NTS_SetModuleNo::~M_NTS_SetModuleNo()
{
	free(m_InputDeviceName);
	free(m_InputPara);
}

int M_NTS_SetModuleNo::Init()
{
	m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit , " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	m_InputPara->paramName, "moduleNo";
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	m_InputPara->paramUnit , " ";
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_NTS_SetModuleNo::Run()
{
	unsigned char moduleNO;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	moduleNO  = (unsigned char)m_InputPara->paramVal;
	return NTS_SetModuleNo(vHandle,moduleNO);
}*/

//class M_NTS_SetUpAtten
/*
M_NTS_SetUpAtten::M_NTS_SetUpAtten()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的上行衰减值(//T3420,2263:无效 //T3364DT:有效(0~31)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_NTS_SetUpAtten::~M_NTS_SetUpAtten()
{
	free(m_InputDeviceName);
	free(m_InputPara1);
	free(m_InputPara2);
}

int M_NTS_SetUpAtten::Init()
{
	m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit , " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	m_InputPara1->paramName, "chindex";
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	m_InputPara1->paramUnit , " ";
	m_InputParamVector.push_back(m_InputPara1);

	m_InputPara2->paramName, "UpAtten";
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	m_InputPara2->paramUnit , "dB";
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_NTS_SetUpAtten::Run()
{
	short ch;
	short upatten;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);
	upatten = atoi(m_InputPara2->paramVal);
	return NTS_SetUpAtten(vHandle,ch,&upatten);
}*/

//class M_NTS_GetUpAtten
/*
M_NTS_GetUpAtten::M_NTS_GetUpAtten()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的上行衰减值(//T3420,2263:无效 //T3364DT:有效)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetUpAtten::~M_NTS_GetUpAtten()
{
	free(m_InputDeviceName);
	free(m_InputPara);
	free(m_OutputPara);
}

int M_NTS_GetUpAtten::Init()
{
	m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit , " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	m_InputPara->paramName, "chindex";
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	m_InputPara->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara);

	m_OutputPara->paramName, "UpAtten";
	m_OutputPara->paramType = NTSInt8;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	m_OutputPara->paramUnit , "dB";
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetUpAtten::Run()
{
	short ch,upatten;
	int retVal;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara->paramVal);
	retVal =NTS_GetUpAtten(vHandle,ch,&upatten);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",upatten);
	}
	return retVal;
}*/

//class M_NTS_SetDownAtten
/*
M_NTS_SetDownAtten::M_NTS_SetDownAtten()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的下行衰减值(//T3420,2263:无效 //T3364DT:有效(0~31)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_NTS_SetDownAtten::~M_NTS_SetDownAtten()
{
	free(m_InputDeviceName);
	free(m_InputPara1);
	free(m_InputPara2);
}

int M_NTS_SetDownAtten::Init()
{
	m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit , " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	m_InputPara1->paramName, "chindex";
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	m_InputPara1->paramUnit , " ";
	m_InputParamVector.push_back(m_InputPara1);

	m_InputPara2->paramName, "DownAtten";
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	m_InputPara2->paramUnit , "dB";
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_NTS_SetDownAtten::Run()
{
	short ch,downatten;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);
	downatten = atoi(m_InputPara2->paramVal);
	return NTS_SetDownAtten(vHandle,ch,&downatten);
}*/

//class M_NTS_GetDownAtten
/*
M_NTS_GetDownAtten::M_NTS_GetDownAtten()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的下行衰减值(//T3420,2263:无效 //T3364DT:有效)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetDownAtten::~M_NTS_GetDownAtten()
{
	free(m_InputDeviceName);
	free(m_InputPara);
	free(m_OutputPara);
}

int M_NTS_GetDownAtten::Init()
{
	m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit , " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	m_InputPara->paramName, "chindex";
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	m_InputPara->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara);

	m_OutputPara->paramName, "DownAtten";
	m_OutputPara->paramType = NTSInt8;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	m_OutputPara->paramUnit , "dB";
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetDownAtten::Run()
{
	short ch,downatten;
	int retVal;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara->paramVal);
	retVal =NTS_GetDownAtten(vHandle, ch,&downatten);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",downatten);
	}
	return retVal;
}*/

//class M_NTS_GetUpOpd
/*
M_NTS_GetUpOpd::M_NTS_GetUpOpd()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的上行OPD(//T3420,2263,T3364DT:无效)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetUpOpd::~M_NTS_GetUpOpd()
{
	free(m_InputDeviceName);
	free(m_InputPara);
	free(m_OutputPara);
}

int M_NTS_GetUpOpd::Init()
{
	m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit , " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	m_InputPara->paramName, "chindex";
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	m_InputPara->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara);

	m_OutputPara->paramName, "upOPD";
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	m_OutputPara->paramUnit , "dBm";
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetUpOpd::Run()
{
	short ch;
	float opd;
	int retVal;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara->paramVal);
	retVal = NTS_GetUpOpd(vHandle,ch,&opd);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%e",opd);
	}
	return retVal;
}*/

//class M_NTS_GetDownOpd
/*
M_NTS_GetDownOpd::M_NTS_GetDownOpd()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的下行OPD(//T3420,2263:无效 //T3364DT:有效)");
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_NTS_GetDownOpd::~M_NTS_GetDownOpd()
{
	free(m_InputDeviceName);
	free(m_InputPara);
	free(m_OutputPara);
}

int M_NTS_GetDownOpd::Init()
{
	m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit , " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	m_InputPara->paramName, "chindex";
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	m_InputPara->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara);

	m_OutputPara->paramName, "downOPD";
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	m_OutputPara->paramUnit , "dBm";
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetDownOpd::Run()
{
	short ch;
	float opd;
	int retVal;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	ch = atoi(m_InputPara->paramVal);
	retVal= NTS_GetDownOpd(vHandle, ch,&opd);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%e",opd);
	}
	return retVal;
}*/

//class M_NTS_GetDownIpd
/*
M_NTS_GetDownIpd::M_NTS_GetDownIpd()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的下行IPD(无效)");
	m_InputPara = CreateParamStruct();
	m_OutputPara =CreateParamStruct();
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_NTS_GetDownIpd::~M_NTS_GetDownIpd()
{
	free(m_InputDeviceName);
	free(m_InputPara);
	free(m_OutputPara);
}

int M_NTS_GetDownIpd::Init()
{
	m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit , " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	m_InputPara->paramName, "chindex";
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	m_InputPara->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara);

	m_OutputPara->paramName, "downIPD";
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	m_OutputPara->paramUnit , "dBm";
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_NTS_GetDownIpd::Run()
{
	short ch;
	float ipd;
	int retVal;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara->paramVal);
	retVal = NTS_GetDownIpd(vHandle,ch,&ipd);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%.3f",ipd);
	}
	return retVal;
}*/

//class M_NTS_GetModuleVersion
M_NTS_GetModuleVersion::M_NTS_GetModuleVersion()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取模块MCU的软件版本");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetModuleVersion::~M_NTS_GetModuleVersion()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara);
}

int M_NTS_GetModuleVersion::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	m_OutputPara->paramName, "version";
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	m_OutputPara->paramUnit , " ";
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetModuleVersion::Run()
{
	char version[20];
	int retVal;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	retVal = NTS_GetModuleVersion(vHandle, version);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,version);
	}
	return retVal;
}
//class M_NTS_GetCardVersion
M_NTS_GetCardVersion::M_NTS_GetCardVersion()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取测试卡MCU的软件版本");
	m_OutputPara = CreateParamStruct();
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_NTS_GetCardVersion::~M_NTS_GetCardVersion()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara);
}

int M_NTS_GetCardVersion::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara->paramName, "version");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetCardVersion::Run()
{
	char version[20];
	int retVal;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	retVal= NTS_GetCardVersion(vHandle, version);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,version);	
	}
	return retVal;
}
//class M_NTS_SetTmpCompensationData
M_NTS_SetTmpCompensationData::M_NTS_SetTmpCompensationData()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的温度补偿数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_NTS_SetTmpCompensationData::~M_NTS_SetTmpCompensationData()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_NTS_SetTmpCompensationData::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	return NTS_SUCCESS;
}
int M_NTS_SetTmpCompensationData::Run()
{
	short ch;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	ch = atoi(m_InputPara1->paramVal);
	return NTS_SetTmpCompensationData(vHandle,ch);
}
//class M_NTS_GetTmpCompensationSense
M_NTS_GetTmpCompensationSense::M_NTS_GetTmpCompensationSense()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的温度补偿温度传感器的温度值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetTmpCompensationSense::~M_NTS_GetTmpCompensationSense()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
//	free(m_OutputPara);
}

int M_NTS_GetTmpCompensationSense::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "chindex");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);

	sprintf(m_OutputPara->paramName, "temperature");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetTmpCompensationSense::Run()
{
	short ch;
	float temperature;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara->paramVal);
	retVal = NTS_GetTmpCompensationSense(vHandle,ch,&temperature);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%e",temperature);
	}
	return retVal;
}
//class M_NTS_SetPushOutputVol
M_NTS_SetPushOutputVol::M_NTS_SetPushOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的推动级调整输出电压(DA值0~4095)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}

M_NTS_SetPushOutputVol::~M_NTS_SetPushOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}

int M_NTS_SetPushOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "DAvalue");
	m_InputPara3->paramType = NTSUInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_NTS_SetPushOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	DAvalue = atoi(m_InputPara3->paramVal);
	return NTS_SetPushOutputVol(vHandle, ch,temperature,DAvalue);
}
//class M_NTS_GetPushOutPutVol
M_NTS_GetPushOutPutVol::M_NTS_GetPushOutPutVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的推动级调整输出电压(DA值)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetPushOutPutVol::~M_NTS_GetPushOutPutVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}

int M_NTS_GetPushOutPutVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_OutputPara->paramName, "DAvalue");
	m_OutputPara->paramType = NTSUInt16;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetPushOutPutVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	retVal = NTS_GetPushOutPutVol(vHandle, ch,temperature,&DAvalue);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",DAvalue);
	}
	return retVal;
}
//class M_NTS_SetLastOutputVol
M_NTS_SetLastOutputVol::M_NTS_SetLastOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的末级调整输出电压(DA值0~4095)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();

}

M_NTS_SetLastOutputVol::~M_NTS_SetLastOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}

int M_NTS_SetLastOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "DAvalue");
	m_InputPara3->paramType = NTSUInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_NTS_SetLastOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	DAvalue = atoi(m_InputPara3->paramVal);
	return NTS_SetLastOutputVol(vHandle,ch,temperature,DAvalue);
}
//class M_NTS_GetLastOutputVol
M_NTS_GetLastOutputVol::M_NTS_GetLastOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的末级调整输出电压(DA值)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetLastOutputVol::~M_NTS_GetLastOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}

int M_NTS_GetLastOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara->paramName, "DAvalue");
	m_OutputPara->paramType = NTSUInt16;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetLastOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	retVal = NTS_GetLastOutputVol(vHandle,ch,temperature,&DAvalue);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",DAvalue);
	}
	return retVal;
}	
//class M_NTS_SetWorkMode
M_NTS_SetWorkMode::M_NTS_SetWorkMode()
:BaseMethod()
{
	sprintf(m_MethodScript,
		"设置模块工作模式(//2263: 0:CH1常发 1:CH2常发 2:TWO接收 3:TWO动态 4:TWO空闲)和检测模式(0:OPD 1:RPD)  //T3364DT 0:常发 1:保留 2:接收 3:动态 4:空闲   //T3420: 0:常发 1:保留 2:接收 3:动态 4:空闲)和检测模式(0:OPD 1:RPD)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_NTS_SetWorkMode::~M_NTS_SetWorkMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_NTS_SetWorkMode::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "workmode");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "detectormode");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_NTS_SetWorkMode::Run()
{
	unsigned short workmode,detectormode;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	workmode = atoi(m_InputPara1->paramVal);
	detectormode = atoi(m_InputPara2->paramVal);
	return NTS_SetWorkMode(vHandle,workmode,detectormode);
}
//class M_NTS_SetWorkModeEx
M_NTS_SetWorkModeEx::M_NTS_SetWorkModeEx()
:BaseMethod()
{
	sprintf(m_MethodScript,"设置模块指定通道的工作模式(1:发射(功放开) 2:接收(功放关) 3:TDD 4:空闲)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_NTS_SetWorkModeEx::~M_NTS_SetWorkModeEx()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);

}

int M_NTS_SetWorkModeEx::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "workmode");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"4");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	

	return NTS_SUCCESS;
}
int M_NTS_SetWorkModeEx::Run()
{
	short ch;
	unsigned short workmode;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);
	workmode = atoi(m_InputPara2->paramVal);

	return NTS_SetWorkModeEx(vHandle,ch,workmode);
}
//class M_NTS_GetWorkMode
M_NTS_GetWorkMode::M_NTS_GetWorkMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取模块的工作模式");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	Init();
}

M_NTS_GetWorkMode::~M_NTS_GetWorkMode()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);
//	free(m_OutputPara2);
}

int M_NTS_GetWorkMode::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "workmode");
	m_OutputPara1->paramType = NTSUInt8;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);

	sprintf(m_OutputPara2->paramName, "detectormode");
	m_OutputPara2->paramType = NTSUInt8;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara2);
	return NTS_SUCCESS;
}
int M_NTS_GetWorkMode::Run()
{
	unsigned short workmode,detectormode;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	retVal = NTS_GetWorkMode(vHandle, &workmode,&detectormode);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal,"%1d",workmode);
		sprintf(m_OutputPara2->paramVal,"%1d",detectormode);
	}
	return retVal;
}
//class M_NTS_GetWorkModeEx
M_NTS_GetWorkModeEx::M_NTS_GetWorkModeEx()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取模块指定通道的工作模");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	Init();
}

M_NTS_GetWorkModeEx::~M_NTS_GetWorkModeEx()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_OutputPara1);

}

int M_NTS_GetWorkModeEx::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_OutputPara1->paramName, "workmode");
	m_OutputPara1->paramType = NTSUInt8;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_NTS_GetWorkModeEx::Run()
{
	short ch;
	unsigned short workmode;
	int retVal;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);
	retVal = NTS_GetWorkModeEx(vHandle,ch,&workmode);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal,"%1d",workmode);

	}
	return retVal;
}

//class M_NTS_SetOneBytePCB
M_NTS_SetOneBytePCB::M_NTS_SetOneBytePCB()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置模块的1位PCB条码");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_NTS_SetOneBytePCB::~M_NTS_SetOneBytePCB()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_NTS_SetOneBytePCB::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "PCBindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "PCB");
	m_InputPara2->paramType = NTSString;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_NTS_SetOneBytePCB::Run()
{
	unsigned short pcbindex;
	short pcb;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	pcbindex = atoi(m_InputPara1->paramVal);
	if(!strlen(m_InputPara2->paramVal))
	{
		return NTS_INVALID_PARA;
	}
	pcb =m_InputPara2->paramVal[0];
	return NTS_SetOneBytePCB(vHandle,pcbindex,pcb);
}
//class M_NTS_GetOneBytePCB
M_NTS_GetOneBytePCB::M_NTS_GetOneBytePCB()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取模块的1位PCB条码");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	m_OutputPara =CreateParamStruct();
	Init();
}

M_NTS_GetOneBytePCB::~M_NTS_GetOneBytePCB()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
//	free(m_OutputPara);
}

int M_NTS_GetOneBytePCB::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "PCBindex");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);

	sprintf(m_OutputPara->paramName, "PCB");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetOneBytePCB::Run()
{
	unsigned short index;
	short pcb;
	char tmppcb;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	index = atoi(m_InputPara->paramVal);
	retVal = NTS_GetOneBytePCB(vHandle, index,&pcb);
	if(retVal ==NTS_SUCCESS)
	{
		tmppcb = pcb;
		sprintf(m_OutputPara->paramVal," ");
		m_OutputPara->paramVal[0] = pcb;
	}
	return retVal;
}
//class M_NTS_SetPCB
M_NTS_SetPCB::M_NTS_SetPCB()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置模块的PCB条码到FLASH中");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}

M_NTS_SetPCB::~M_NTS_SetPCB()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_NTS_SetPCB::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "PCB");
	m_InputPara->paramType = NTSString;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_NTS_SetPCB::Run()
{
	BYTE pcb[20] = {0};
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	for(int i=0;i<strlen(m_InputPara->paramVal);i++)
	{
		pcb[i] =(unsigned char )m_InputPara->paramVal[i];
	}

	return NTS_SetPCB(vHandle,pcb);
}
//class M_NTS_GetPCB
M_NTS_GetPCB::M_NTS_GetPCB()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取模块的PCB条码");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetPCB::~M_NTS_GetPCB()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara);
	
}

int M_NTS_GetPCB::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara->paramName, "pcb");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal," ");
	sprintf(m_OutputPara->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara);

	return NTS_SUCCESS;
}
int M_NTS_GetPCB::Run()
{
	BYTE pcb[20] = {0};
	long length;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	retVal = NTS_GetPCB(vHandle, pcb,&length);
	if(retVal == NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,(char*)pcb);
	}
	return retVal;
}
//class M_NTS_SetEEPROM
M_NTS_SetEEPROM::M_NTS_SetEEPROM()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置EEPROM数据(0~255)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_NTS_SetEEPROM::~M_NTS_SetEEPROM()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_NTS_SetEEPROM::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "address");
	m_InputPara1->paramType = NTSUInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "data");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_NTS_SetEEPROM::Run()
{
	unsigned int address;
	float data;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	address = atoi(m_InputPara1->paramVal);
	data = atof(m_InputPara2->paramVal);
	return NTS_SetEEPROM(vHandle,address,data);
}
//class M_NTS_GetEEPROM
M_NTS_GetEEPROM::M_NTS_GetEEPROM()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取EEPROM数据");
	m_InputPara  = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_NTS_GetEEPROM::~M_NTS_GetEEPROM()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
//	free(m_OutputPara);
}

int M_NTS_GetEEPROM::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "address");
	m_InputPara->paramType = NTSUInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);
	
	sprintf(m_OutputPara->paramName, "EEPROMdata");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetEEPROM::Run()
{
	unsigned int address;
	float data;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	address = atoi(m_InputPara->paramVal);
	retVal = NTS_GetEEPROM(vHandle,address, &data);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%e",data);
	}
	return retVal;
}
//class M_NTS_SetSwtichMode
M_NTS_SetSwtichMode::M_NTS_SetSwtichMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置矩阵开关的模式( 0:Off 1:On)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	m_InputPara4 = CreateParamStruct();
	Init();
}

M_NTS_SetSwtichMode::~M_NTS_SetSwtichMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
//	free(m_InputPara4);
}

int M_NTS_SetSwtichMode::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName,"k1");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName,"k2");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName,"k3");
	m_InputPara3->paramType = NTSUInt8;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"0");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);

	sprintf(m_InputPara4->paramName,"k4");
	m_InputPara4->paramType = NTSUInt8;
	m_InputPara4->paramCount = 1;
	sprintf(m_InputPara4->paramVal,"0");
	sprintf(m_InputPara4->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara4);

	return NTS_SUCCESS;
}
int M_NTS_SetSwtichMode::Run()
{
	unsigned short k1,k2,k3,k4;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	k1 = atoi(m_InputPara1->paramVal);
	k2 = atoi(m_InputPara2->paramVal);
	k3 = atoi(m_InputPara3->paramVal);
	k4 = atoi(m_InputPara4->paramVal);
	return NTS_SetSwtichMode(vHandle, k1,k2,k3,k4);
}

//class M_NTS_SetPowerState
M_NTS_SetPowerState::M_NTS_SetPowerState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置模块供给电源状态(0:off 1:on)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}

M_NTS_SetPowerState::~M_NTS_SetPowerState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_NTS_SetPowerState::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "powerstate");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);

	return NTS_SUCCESS;
}
int M_NTS_SetPowerState::Run()
{
	unsigned short state;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	state = atoi(m_InputPara->paramVal);
	return NTS_SetPowerState(vHandle, state);
}

//class M_NTS_GetPowerState
M_NTS_GetPowerState::M_NTS_GetPowerState()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取模块供给电源状态(0:off 1:on)");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetPowerState::~M_NTS_GetPowerState()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara);
}

int M_NTS_GetPowerState::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal, "");
	sprintf(m_InputDeviceName->paramUnit, "");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara->paramName, "PowerState");
	m_OutputPara->paramType = NTSUInt8;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal, "0");
	sprintf(m_OutputPara->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_NTS_GetPowerState::Run()
{
	int res;
	short state = 0;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;	
	res = NTS_GetPowerState(vHandle, &state);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal, "%d", state);
	}
	return res;
}

//class M_NTS_GetTemperature
M_NTS_GetTemperature::M_NTS_GetTemperature()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的温度值");
	m_InputDeviceName = CreateParamStruct();
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetTemperature::~M_NTS_GetTemperature()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
//	free(m_OutputPara);
}

int M_NTS_GetTemperature::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "chindex");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);

	sprintf(m_OutputPara->paramName, "temperature");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "℃");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetTemperature::Run()
{
	short ch;
	float temperature;
	int retval;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara->paramVal);
	retval = NTS_GetTemperature(vHandle, ch,&temperature);
	if(retval==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%e",temperature);
	}
	return retval;
}
/*

//class M_NTS_GetAgedData
M_NTS_GetAgedData::M_NTS_GetAgedData()
:BaseMethod()
{
	sprintf(m_MethodScript,"获取老化数据(//2263 温度，电流、PCB条码)");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	for(int i =0;i<50;i++)
	{
		m_OutputPara[i] = CreateParamStruct();
		m_OutputPara[i]->paramName, new char[30];
		m_OutputPara[i]->paramUnit , new char[30];
		sprintf(m_OutputPara[i]->paramName,"");
		sprintf(m_OutputPara[i]->paramUnit,"");
		m_OutputPara[i]->paramCount = 1;
	}
	Init();
}
M_NTS_GetAgedData::~M_NTS_GetAgedData()
{
	free(m_InputPara1);
	free(m_InputPara2);
	
	for(int i =0;i<50;i++)
	{
		free(m_OutputPara[i]);
	}
}
int M_NTS_GetAgedData::Init(void)
{

	m_InputPara1->paramName, "channelNO";
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	m_InputPara1->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara1);

	m_InputPara2->paramName, "BoardNo";
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	m_InputPara2->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_NTS_GetAgedData::Run(void)
{
	short int channelNO,boardNO;
	int retVal;
	short int datacount,modulecount;
	float data[300];
	char *(pcb[20]);
	char temppcb[50][20] = {0};
	

	if(vHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	channelNO = atoi(m_InputPara1->paramVal);
	boardNO = atoi(m_InputPara2->paramVal);
	retVal = NTS_GetAgedData(vHandle,channelNO,boardNO,
						&datacount,&modulecount,data,&pcb[0]);
	if(retVal==NTS_SUCCESS&&modulecount>0)
	{
		sprintf(m_OutputPara[0]->paramName,"ModuleCount");
		sprintf(m_OutputPara[0]->paramVal,"%d",modulecount);
		sprintf(m_OutputPara[0]->paramUnit,"");
		m_OutputPara[0]->paramType = NTSInt8;
		for(int i= 0;i<modulecount;i++)
		{
			//模块温度值
			sprintf(m_OutputPara[i+1]->paramName,"Tempreture");
			sprintf(m_OutputPara[i+1]->paramVal,"%d",data[i-1]);
			sprintf(m_OutputPara[i+1]->paramUnit,"℃");
			m_OutputPara[i+1]->paramType = NTSReal32;
			//模块电流
			sprintf(m_OutputPara[i+1+modulecount]->paramName,"Current");
			sprintf(m_OutputPara[i+1+modulecount]->paramVal,"%d",data[i+modulecount-1]);
			sprintf(m_OutputPara[i+1+modulecount]->paramUnit,"A");
			m_OutputPara[i+1+modulecount]->paramType = NTSReal32;
			//模块PCB条码
			sprintf(m_OutputPara[i+1+2*modulecount]->paramName,"PCB");
			sprintf(temppcb[i],pcb[i]);
			sprintf(m_OutputPara[i+1+2*modulecount]->paramVal,temppcb[i]);
			m_OutputPara[i+1+2*modulecount]->paramType = NTSString;
		}
		for(i=0;i<=3*modulecount;i++)
		{
			m_OutputParamVector.push_back(m_OutputPara[i]);
		}

	}
	return retVal;
}
*/

/*
//class M_NTS_SetAgedWorkMode
M_NTS_SetAgedWorkMode::M_NTS_SetAgedWorkMode()
:BaseMethod()
{
	sprintf(m_MethodScript,"设置老化时的工作模式(0:空闲 1:工作)");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();

	Init();
}
M_NTS_SetAgedWorkMode::~M_NTS_SetAgedWorkMode()
{
	free(m_InputPara1);
	free(m_InputPara2);
	free(m_InputPara3);

}
int M_NTS_SetAgedWorkMode::Init(void)
{
	m_InputPara1->paramName, "BoardNo";
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	m_InputPara1->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara1);
	
	m_InputPara2->paramName, "moduleNo";
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	m_InputPara2->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara2);

	m_InputPara3->paramName, "mode";
	m_InputPara3->paramType = NTSInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"0");
	m_InputPara3->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_NTS_SetAgedWorkMode::Run(void)
{
	short int moduleNO,boardNO,mode;
	
	if(vHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	boardNO = atoi(m_InputPara1->paramVal);
	moduleNO = atoi(m_InputPara2->paramVal);
	mode = atoi(m_InputPara3->paramVal);
	return NTS_SetAgedWorkMode(vHandle,boardNO,moduleNO,mode);
	
}
*/

//class M_NTS_GetDownVSWR 
M_NTS_GetDownVSWR::M_NTS_GetDownVSWR()
:BaseMethod()
{
	sprintf(m_MethodScript,"获取模块的驻波比(//T3420,2263:无效 //T3364DT:有效)");
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_NTS_GetDownVSWR::~M_NTS_GetDownVSWR()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
//	free(m_OutputPara);
		
}
int M_NTS_GetDownVSWR::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "channel");
	m_InputPara->paramType = NTSInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	sprintf(m_OutputPara->paramName, "VSWR");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_NTS_GetDownVSWR::Run(void)
{
	short ch;
	float vswr;
	int retVal;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara->paramVal);
	retVal= NTS_GetDownVSWR(vHandle,ch,&vswr);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	sprintf(m_OutputPara->paramVal,"%e",vswr);
	return retVal;
}

//class M_NTS_SetLOFreq 
M_NTS_SetLOFreq::M_NTS_SetLOFreq()
:BaseMethod()
{
	sprintf(m_MethodScript,"设置模块的本振频率(//T3420,2263:无效 //T3364DT:有效(1914~1929)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
		
	Init();
}
M_NTS_SetLOFreq::~M_NTS_SetLOFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);

}
int M_NTS_SetLOFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "channel");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "freqency");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1921.4");
	sprintf(m_InputPara2->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_NTS_SetLOFreq::Run(void)
{
	short int ch;
	float freq;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);
	freq = atof(m_InputPara2->paramVal);
	return NTS_SetLOFreq(vHandle,ch,freq);	
}
//class M_NTS_GetModuleCPLDVersion
M_NTS_GetModuleCPLDVersion::M_NTS_GetModuleCPLDVersion()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取模块CPLD软件版本");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara = CreateParamStruct();

	Init();
}

M_NTS_GetModuleCPLDVersion::~M_NTS_GetModuleCPLDVersion()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara);
}

int M_NTS_GetModuleCPLDVersion::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara->paramName, "version");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetModuleCPLDVersion::Run()
{
	char version[20];
	int retVal;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	retVal = NTS_GetModuleCPLDVersion(vHandle, version);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,version);
	}
	return retVal;
}
//class M_NTS_GetCardCPLDVersion
M_NTS_GetCardCPLDVersion::M_NTS_GetCardCPLDVersion()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取测试卡CPLD软件版本");
	m_OutputPara = CreateParamStruct();
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_NTS_GetCardCPLDVersion::~M_NTS_GetCardCPLDVersion()
{
//	free(m_OutputPara);
//	free(m_InputDeviceName);
}

int M_NTS_GetCardCPLDVersion::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara->paramName, "version");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetCardCPLDVersion::Run()
{
	char version[20];
	int retVal;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	retVal= NTS_GetCardCPLDVersion(vHandle, version);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,version);	
	}
	return retVal;
}

//class M_NTS_SetDetectorMode
M_NTS_SetDetectorMode::M_NTS_SetDetectorMode()
:BaseMethod()
{
	sprintf(m_MethodScript,"设置模块指定通道的检测方式(//0:OPD 1:RPD 2:DPD)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_NTS_SetDetectorMode::~M_NTS_SetDetectorMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
	
}

int M_NTS_SetDetectorMode::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "Dectormode");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"4");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);	
	
	return NTS_SUCCESS;
}
int M_NTS_SetDetectorMode::Run()
{
	short ch;
	unsigned short mode;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);
	mode = atoi(m_InputPara2->paramVal);
	
	return NTS_SetDetectorMode(vHandle,ch,mode);
}

//class M_NTS_GetDetectorMode
M_NTS_GetDetectorMode::M_NTS_GetDetectorMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取模块指定通道的检测方式");
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_NTS_GetDetectorMode::~M_NTS_GetDetectorMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_OutputPara1);
	
}

int M_NTS_GetDetectorMode::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_OutputPara1->paramName, "Dectormode");
	m_OutputPara1->paramType = NTSUInt8;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_NTS_GetDetectorMode::Run()
{
	short ch;
	unsigned short mode;
	int retVal;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);
	retVal = NTS_GetDetectorMode(vHandle,ch,&mode);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal,"%1d",mode);
		
	}
	return retVal;
}

//M_NTS_GetCardProductNo
M_NTS_GetCardProductNo::M_NTS_GetCardProductNo()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取测试卡产品号");	
	m_OutputPara1 = CreateParamStruct();
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_NTS_GetCardProductNo::~M_NTS_GetCardProductNo()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);	
}

int M_NTS_GetCardProductNo::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "CardProductNo");
	m_OutputPara1->paramType = NTSInt8;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_NTS_GetCardProductNo::Run()
{
	short code;
	int retVal;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	retVal = NTS_GetCardProductNo(vHandle,&code);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal,"%d",code);		
	}
	return retVal;
}
//M_NTS_GetModuleProductNo
M_NTS_GetModuleProductNo::M_NTS_GetModuleProductNo()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取模块产品号");	
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	Init();
}

M_NTS_GetModuleProductNo::~M_NTS_GetModuleProductNo()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);	
}

int M_NTS_GetModuleProductNo::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "ModuleProductNo");
	m_OutputPara1->paramType = NTSInt8;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_NTS_GetModuleProductNo::Run()
{
	short code;
	int retVal;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	retVal = NTS_GetModuleProductNo(vHandle,&code);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal,"%d",code);		
	}
	return retVal;
}
//M_NTS_SetLanLinkMode
M_NTS_SetLanLinkMode::M_NTS_SetLanLinkMode()
:BaseMethod()
{
	sprintf(m_MethodScript,"设置模块指定通道的低噪放链路模式(//T7380ZX CH:无效 mode: 1:LNA,2:LNA-BYPASS)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_NTS_SetLanLinkMode::~M_NTS_SetLanLinkMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
	
}

int M_NTS_SetLanLinkMode::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "Mode");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);	
	
	return NTS_SUCCESS;
}
int M_NTS_SetLanLinkMode::Run()
{
	short ch;
	unsigned short mode;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);
	mode = atoi(m_InputPara2->paramVal);
	
	return NTS_SetLanLinkMode(vHandle,ch,mode);
}
//M_NTS_SetDectorState
M_NTS_SetDectorState::M_NTS_SetDectorState()
:BaseMethod()
{
	sprintf(m_MethodScript,"设置指定通道的功率检测使能状态(0:OFF 1:ON)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_NTS_SetDectorState::~M_NTS_SetDectorState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
	
}

int M_NTS_SetDectorState::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "State");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);	
	
	return NTS_SUCCESS;
}
int M_NTS_SetDectorState::Run()
{
	short ch;
	short state;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);
	state = atoi(m_InputPara2->paramVal);
	
	return NTS_SetDectorState(vHandle,ch,state);
}
// class M_NTS_SetSecGAOutputVol
M_NTS_SetSecGAOutputVol::M_NTS_SetSecGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的第二级功放调整输出电压(DA值0~4095)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}

M_NTS_SetSecGAOutputVol::~M_NTS_SetSecGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}

int M_NTS_SetSecGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "DAvalue");
	m_InputPara3->paramType = NTSUInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_NTS_SetSecGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	if(!strlen(m_InputPara3->paramVal))
	{
		return NTS_INVALID_PARA;
	}
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	DAvalue = atoi(m_InputPara3->paramVal);
	return NTS_SetSecGAOutputVol(vHandle, ch,temperature,DAvalue);
}
//class  M_NTS_GetSecGAOutputVol
M_NTS_GetSecGAOutputVol::M_NTS_GetSecGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道第二级功放调整输出电压(DA值)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetSecGAOutputVol::~M_NTS_GetSecGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}

int M_NTS_GetSecGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_OutputPara->paramName, "DAvalue");
	m_OutputPara->paramType = NTSUInt16;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetSecGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	retVal = NTS_GetSecGAOutputVol(vHandle, ch,temperature,&DAvalue);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",DAvalue);
	}
	return retVal;
}

//class M_NTS_SetThirdGAOutputVol
M_NTS_SetThirdGAOutputVol::M_NTS_SetThirdGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的第三级功放调整输出电压(DA值0~4095)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}

M_NTS_SetThirdGAOutputVol::~M_NTS_SetThirdGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}

int M_NTS_SetThirdGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "DAvalue");
	m_InputPara3->paramType = NTSUInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_NTS_SetThirdGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	if(!strlen(m_InputPara3->paramVal))
	{
		return NTS_INVALID_PARA;
	}
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	DAvalue = atoi(m_InputPara3->paramVal);
	return NTS_SetThirdGAOutputVol(vHandle, ch,temperature,DAvalue);
}
//class M_NTS_GetThirdGAOutputVol
M_NTS_GetThirdGAOutputVol::M_NTS_GetThirdGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的第三级功放调整输出电压(DA值)");
	m_InputDeviceName = CreateParamStruct();
	
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetThirdGAOutputVol::~M_NTS_GetThirdGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}

int M_NTS_GetThirdGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_OutputPara->paramName, "DAvalue");
	m_OutputPara->paramType = NTSUInt16;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetThirdGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	retVal = NTS_GetThirdGAOutputVol(vHandle, ch,temperature,&DAvalue);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",DAvalue);
	}
	return retVal;
}

//class M_NTS_SetFourGAOutputVol
M_NTS_SetFourGAOutputVol::M_NTS_SetFourGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的第四级功放调整输出电压(DA值0~4095)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}

M_NTS_SetFourGAOutputVol::~M_NTS_SetFourGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}

int M_NTS_SetFourGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "DAvalue");
	m_InputPara3->paramType = NTSUInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_NTS_SetFourGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	if(!strlen(m_InputPara3->paramVal))
	{
		return NTS_INVALID_PARA;
	}
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	DAvalue = atoi(m_InputPara3->paramVal);
	return NTS_SetFourGAOutputVol(vHandle, ch,temperature,DAvalue);
}
//class M_NTS_GetFourGAOutputVol
M_NTS_GetFourGAOutputVol::M_NTS_GetFourGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的第四级功放调整输出电压(DA值)");
	m_InputDeviceName = CreateParamStruct();
	
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetFourGAOutputVol::~M_NTS_GetFourGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}

int M_NTS_GetFourGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_OutputPara->paramName, "DAvalue");
	m_OutputPara->paramType = NTSUInt16;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetFourGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	retVal = NTS_GetFourGAOutputVol(vHandle, ch,temperature,&DAvalue);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",DAvalue);
	}
	return retVal;
}

//class M_NTS_SetFiveGAOutputVol
M_NTS_SetFiveGAOutputVol::M_NTS_SetFiveGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的第五级功放调整输出电压(DA值0~4095)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}

M_NTS_SetFiveGAOutputVol::~M_NTS_SetFiveGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}

int M_NTS_SetFiveGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "DAvalue");
	m_InputPara3->paramType = NTSUInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_NTS_SetFiveGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	if(!strlen(m_InputPara3->paramVal))
	{
		return NTS_INVALID_PARA;
	}
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	DAvalue = atoi(m_InputPara3->paramVal);
	return NTS_SetFiveGAOutputVol(vHandle, ch,temperature,DAvalue);
}

//class M_NTS_GetFiveGAOutputVol
M_NTS_GetFiveGAOutputVol::M_NTS_GetFiveGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的第五级功放调整输出电压(DA值)");
	m_InputDeviceName = CreateParamStruct();
	
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetFiveGAOutputVol::~M_NTS_GetFiveGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}

int M_NTS_GetFiveGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_OutputPara->paramName, "DAvalue");
	m_OutputPara->paramType = NTSUInt16;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetFiveGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	retVal = NTS_GetFiveGAOutputVol(vHandle, ch,temperature,&DAvalue);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",DAvalue);
	}
	return retVal;
}


//class M_NTS_SetSixGAOutputVol
M_NTS_SetSixGAOutputVol::M_NTS_SetSixGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的第六级功放调整输出电压(DA值0~4095)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}

M_NTS_SetSixGAOutputVol::~M_NTS_SetSixGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}

int M_NTS_SetSixGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "DAvalue");
	m_InputPara3->paramType = NTSUInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_NTS_SetSixGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	if(!strlen(m_InputPara3->paramVal))
	{
		return NTS_INVALID_PARA;
	}
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	DAvalue = atoi(m_InputPara3->paramVal);
	return NTS_SetSixGAOutputVol(vHandle, ch,temperature,DAvalue);
}

//class M_NTS_GetSixGAOutputVol
M_NTS_GetSixGAOutputVol::M_NTS_GetSixGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的第六级功放调整输出电压(DA值)");
	m_InputDeviceName = CreateParamStruct();
	
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetSixGAOutputVol::~M_NTS_GetSixGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}

int M_NTS_GetSixGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_OutputPara->paramName, "DAvalue");
	m_OutputPara->paramType = NTSUInt16;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetSixGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	retVal = NTS_GetSixGAOutputVol(vHandle, ch,temperature,&DAvalue);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",DAvalue);
	}
	return retVal;
}

//class M_NTS_SetSevenGAOutputVol
M_NTS_SetSevenGAOutputVol::M_NTS_SetSevenGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的第七级功放调整输出电压(DA值0~4095)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}

M_NTS_SetSevenGAOutputVol::~M_NTS_SetSevenGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}

int M_NTS_SetSevenGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "DAvalue");
	m_InputPara3->paramType = NTSUInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_NTS_SetSevenGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	if(!strlen(m_InputPara3->paramVal))
	{
		return NTS_INVALID_PARA;
	}
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	DAvalue = atoi(m_InputPara3->paramVal);
	return NTS_SetSevenGAOutputVol(vHandle, ch,temperature,DAvalue);
}

//class M_NTS_GetSixGAOutputVol
M_NTS_GetSevenGAOutputVol::M_NTS_GetSevenGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的第七级功放调整输出电压(DA值)");
	m_InputDeviceName = CreateParamStruct();
	
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetSevenGAOutputVol::~M_NTS_GetSevenGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}

int M_NTS_GetSevenGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_OutputPara->paramName, "DAvalue");
	m_OutputPara->paramType = NTSUInt16;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetSevenGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	retVal = NTS_GetSevenGAOutputVol(vHandle, ch,temperature,&DAvalue);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",DAvalue);
	}
	return retVal;
}


//class M_NTS_SetEightGAOutputVol
M_NTS_SetEightGAOutputVol::M_NTS_SetEightGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的第八级功放调整输出电压(DA值0~4095)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}

M_NTS_SetEightGAOutputVol::~M_NTS_SetEightGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}

int M_NTS_SetEightGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "DAvalue");
	m_InputPara3->paramType = NTSUInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_NTS_SetEightGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	if(!strlen(m_InputPara3->paramVal))
	{
		return NTS_INVALID_PARA;
	}
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	DAvalue = atoi(m_InputPara3->paramVal);
	return NTS_SetEightGAOutputVol(vHandle, ch,temperature,DAvalue);
}

//class M_NTS_GetEightGAOutputVol
M_NTS_GetEightGAOutputVol::M_NTS_GetEightGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的第八级功放调整输出电压(DA值)");
	m_InputDeviceName = CreateParamStruct();
	
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetEightGAOutputVol::~M_NTS_GetEightGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}

int M_NTS_GetEightGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_OutputPara->paramName, "DAvalue");
	m_OutputPara->paramType = NTSUInt16;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetEightGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	retVal = NTS_GetEightGAOutputVol(vHandle, ch,temperature,&DAvalue);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",DAvalue);
	}
	return retVal;
}

//class M_NTS_SetNineGAOutputVol
M_NTS_SetNineGAOutputVol::M_NTS_SetNineGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的第九级功放调整输出电压(DA值0~4095)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}

M_NTS_SetNineGAOutputVol::~M_NTS_SetNineGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}

int M_NTS_SetNineGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "DAvalue");
	m_InputPara3->paramType = NTSUInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_NTS_SetNineGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	if(!strlen(m_InputPara3->paramVal))
	{
		return NTS_INVALID_PARA;
	}
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	DAvalue = atoi(m_InputPara3->paramVal);
	return NTS_SetNineGAOutputVol(vHandle, ch,temperature,DAvalue);
}


//class M_NTS_GetNineGAOutputVol
M_NTS_GetNineGAOutputVol::M_NTS_GetNineGAOutputVol()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的第九级功放调整输出电压(DA值)");
	m_InputDeviceName = CreateParamStruct();
	
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetNineGAOutputVol::~M_NTS_GetNineGAOutputVol()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}

int M_NTS_GetNineGAOutputVol::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "tempreatrue");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_OutputPara->paramName, "DAvalue");
	m_OutputPara->paramType = NTSUInt16;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetNineGAOutputVol::Run()
{
	short ch;
	float temperature;
	unsigned short DAvalue;
	int retVal;

	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	ch = atoi(m_InputPara1->paramVal);
	temperature = atof(m_InputPara2->paramVal);
	retVal = NTS_GetNineGAOutputVol(vHandle, ch,temperature,&DAvalue);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",DAvalue);
	}
	return retVal;
}


//class M_NTS_GetCurrent
M_NTS_GetCurrent::M_NTS_GetCurrent()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的电流值(单位:bit)");
	m_InputDeviceName = CreateParamStruct();
	
	m_InputPara1 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetCurrent::~M_NTS_GetCurrent()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_OutputPara);
}

int M_NTS_GetCurrent::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);	
	
	sprintf(m_OutputPara->paramName, "Current");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"bit");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetCurrent::Run()
{
	short ch;
	float Current;
	int retVal;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);	
	retVal = NTS_GetCurrent(vHandle, ch,&Current);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%e",Current);
	}
	return retVal;
}

//class M_NTS_SetCurrentLimited
M_NTS_SetCurrentLimited::M_NTS_SetCurrentLimited()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道的上下限电流值(单位:bit)");
	m_InputDeviceName = CreateParamStruct();
	
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}

M_NTS_SetCurrentLimited::~M_NTS_SetCurrentLimited()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}

int M_NTS_SetCurrentLimited::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "DownLimited");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "bit");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "UpLimited");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"5000");
	sprintf(m_InputPara3->paramUnit , "bit");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_NTS_SetCurrentLimited::Run()
{
	short ch;
	float DownLimited, UpLimited;	
	int retVal;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	ch = atoi(m_InputPara1->paramVal);
	DownLimited = atof(m_InputPara2->paramVal);
	UpLimited = atof(m_InputPara3->paramVal);

	retVal = NTS_SetCurrentLimited(vHandle, ch,DownLimited, UpLimited);
	return retVal;
}

//class M_NTS_GetCurrentLimited
M_NTS_GetCurrentLimited::M_NTS_GetCurrentLimited()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的上下限电流值(单位:bit)");
	m_InputDeviceName = CreateParamStruct();
	
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	Init();
}

M_NTS_GetCurrentLimited::~M_NTS_GetCurrentLimited()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_OutputPara1);
//	free(m_OutputPara2);
}

int M_NTS_GetCurrentLimited::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_OutputPara1->paramName, "DownLimited");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "bit");
	m_OutputParamVector.push_back(m_OutputPara1);

	sprintf(m_OutputPara2->paramName, "UpLimited");
	m_OutputPara2->paramType = NTSReal32;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , "bit");
	m_OutputParamVector.push_back(m_OutputPara2);
	return NTS_SUCCESS;
}
int M_NTS_GetCurrentLimited::Run()
{
	short ch;
	float DownLimited, UpLimited;
	int retVal;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	ch = atoi(m_InputPara1->paramVal);
	retVal = NTS_GetCurrentLimited(vHandle, ch, &DownLimited, &UpLimited);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal,"%e",DownLimited);
		sprintf(m_OutputPara2->paramVal,"%e",UpLimited);
	}
	return retVal;
}

//class M_NTS_GetIsWarning
M_NTS_GetIsWarning::M_NTS_GetIsWarning()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取告警信息");
	m_InputDeviceName = CreateParamStruct();
	
	m_InputPara1 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_NTS_GetIsWarning::~M_NTS_GetIsWarning()
{
///	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_OutputPara);
}

int M_NTS_GetIsWarning::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_OutputPara->paramName, "State");
	m_OutputPara->paramType = NTSInt16;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"0");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NTS_GetIsWarning::Run()
{
	short ch;
	int  State;
	int retVal;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	ch = atoi(m_InputPara1->paramVal);	
	retVal = NTS_GetIsWarning(vHandle, ch,&State);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",State);
	}
	return retVal;
}

//class M_NTS_ClearWarning
M_NTS_ClearWarning::M_NTS_ClearWarning()
:BaseMethod()
{
	sprintf(m_MethodScript, "清除告警信息");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();

	Init();
}

M_NTS_ClearWarning::~M_NTS_ClearWarning()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
}

int M_NTS_ClearWarning::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	return NTS_SUCCESS;
}
int M_NTS_ClearWarning::Run()
{
	int retVal;
	int ch;
	
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	ch = atoi(m_InputPara1->paramVal);
	retVal = NTS_ClearWarning(vHandle, ch);	
	return retVal;
}

//class M_NTS_GetIDN
M_NTS_GetIDN::M_NTS_GetIDN()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取产品生产信息");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	Init();
}

M_NTS_GetIDN::~M_NTS_GetIDN()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);
//	free(m_OutputPara2);
}

int M_NTS_GetIDN::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "IDNHigh");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);

	sprintf(m_OutputPara2->paramName, "IDNLow");
	m_OutputPara2->paramType = NTSString;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara2);
	
	return NTS_SUCCESS;
}
int M_NTS_GetIDN::Run()
{
	int retVal;
	char IDNHigh[500] = {0};
	char IDNLow[500] = {0};
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	retVal = NTS_GetIDN(vHandle, IDNHigh,IDNLow);	
	if (retVal == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%s", IDNHigh);
		sprintf(m_OutputPara2->paramVal, "%s", IDNLow);
	}
	return retVal;
}

//class M_NTS_SendCmd 
M_NTS_SendCmd::M_NTS_SendCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_NTS_SendCmd::~M_NTS_SendCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_NTS_SendCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Command");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_NTS_SendCmd::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char CmdStr[20000] = {0};
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	sprintf(CmdStr, "%s", m_InputPara1->paramVal);
	return NTS_SendCmd(vHandle, CmdStr);
}

//class M_NTS_GetCmd 
M_NTS_GetCmd::M_NTS_GetCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令并获取指令的返回数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_NTS_GetCmd::~M_NTS_GetCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara1);
}

int M_NTS_GetCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Command");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_OutputPara1->paramName, "RetStr");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_NTS_GetCmd::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char CmdStr[5000] = {0};
	char RetStr[LPARALENGTH] = {0};
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	//获取输入参数值 
	sprintf(CmdStr, "%s", m_InputPara1->paramVal);
	res = NTS_GetCmd(vHandle, CmdStr, RetStr);
	if (res != NTS_SUCCESS)
	{
		return res;		
	}
	if (strlen(RetStr) > PARALENGTH)
	{		
		m_OutputPara1->LparamVal = (char *)malloc((strlen(RetStr) + 10)*sizeof(char));
		sprintf(m_OutputPara1->LparamVal, "%s", RetStr);
	}
	else
	{
		sprintf(m_OutputPara1->paramVal, "%s", RetStr);
	}
	return res;
}


// M_NTS_SetStartAndStopRAM 
M_NTS_SetStartAndStopRAM::M_NTS_SetStartAndStopRAM()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置模块RAM起止地址的数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();
	m_InputPara[3] = CreateParamStruct();
	
	Init();
}

M_NTS_SetStartAndStopRAM::~M_NTS_SetStartAndStopRAM()
{
//	free(m_InputDeviceName);
//	free(m_InputPara[0]);	
//	free(m_InputPara[1]);	
//	free(m_InputPara[2]);	
//	free(m_InputPara[3]);
}

int M_NTS_SetStartAndStopRAM::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "%s", "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "%s", "FlashIndex");
	m_InputPara[0]->paramType = NTSInt16;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"");
	sprintf(m_InputPara[0]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[0]);	
		
	sprintf(m_InputPara[1]->paramName, "%s", "StartAddress");
	m_InputPara[1]->paramType = NTSInt16;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"");
	sprintf(m_InputPara[1]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[1]);

	sprintf(m_InputPara[2]->paramName, "%s", "Count");
	m_InputPara[2]->paramType = NTSInt16;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"");
	sprintf(m_InputPara[2]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[2]);

	sprintf(m_InputPara[3]->paramName, "%s", "FlashData");
	m_InputPara[3]->paramType = NTSString;
	m_InputPara[3]->paramCount = 1;
	sprintf(m_InputPara[3]->paramVal,"");
	sprintf(m_InputPara[3]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[3]);
	return NTS_SUCCESS;
}
int M_NTS_SetStartAndStopRAM::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	short FlashIndex;
	int StartAddress;
	long Count;
	int i, j, strLength;
	char *TmpStr = NULL;
	int FlashData[1024] = {0};
	int res;


	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	FlashIndex = atoi(m_InputPara[0]->paramVal);
	StartAddress = atoi(m_InputPara[1]->paramVal);
	Count = atoi(m_InputPara[2]->paramVal);
	if (m_InputPara[3]->LparamVal != NULL)
	{
		strLength = strlen(m_InputPara[3]->LparamVal);
		TmpStr = (char *) malloc((strLength + 10)*sizeof(char));
		sprintf(TmpStr , "%s", m_InputPara[3]->LparamVal);		
	}
	else
	{
		strLength = strlen(m_InputPara[3]->paramVal);
		TmpStr = (char *) malloc((strLength + 10)*sizeof(char));
		sprintf(TmpStr , "%s", m_InputPara[3]->paramVal);
	}
	//分离DA值
	FlashData[0] = atoi(&TmpStr[0]);
	for(i = 1, j = 1; i<strLength; i++)
	{
		if (TmpStr[i] == ',')
		{
			FlashData[j] = atoi(&TmpStr[i+1]);
			j++;
		}
	}
	//释放内存
	free(TmpStr);
	res = NTS_SetStartAndStopRAM(vHandle, FlashIndex, StartAddress, Count, FlashData);
	return res;
}

// M_NTS_SetStarAndStopFlash 
M_NTS_SetStarAndStopFlash::M_NTS_SetStarAndStopFlash()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置模块FLASH起止地址的数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();
	m_InputPara[3] = CreateParamStruct();
	
	Init();
}

M_NTS_SetStarAndStopFlash::~M_NTS_SetStarAndStopFlash()
{
//	free(m_InputDeviceName);
//	free(m_InputPara[0]);	
//	free(m_InputPara[1]);	
//	free(m_InputPara[2]);	
//	free(m_InputPara[3]);
}

int M_NTS_SetStarAndStopFlash::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "%s", "FlashIndex");
	m_InputPara[0]->paramType = NTSInt16;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"");
	sprintf(m_InputPara[0]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[0]);	
		
	sprintf(m_InputPara[1]->paramName, "%s", "StartAddress");
	m_InputPara[1]->paramType = NTSInt16;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"");
	sprintf(m_InputPara[1]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[1]);

	sprintf(m_InputPara[2]->paramName, "%s", "Count");
	m_InputPara[2]->paramType = NTSInt16;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"");
	sprintf(m_InputPara[2]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[2]);

	sprintf(m_InputPara[3]->paramName, "%s", "FlashData");
	m_InputPara[3]->paramType = NTSString;
	m_InputPara[3]->paramCount = 1;
	sprintf(m_InputPara[3]->paramVal,"");
	sprintf(m_InputPara[3]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[3]);
	return NTS_SUCCESS;
}
int M_NTS_SetStarAndStopFlash::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	short FlashIndex;
	int StartAddress;
	long Count;
	int i, j, strLength;
	char *TmpStr = NULL;
	int FlashData[1024] = {0};
	int res;


	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	FlashIndex = atoi(m_InputPara[0]->paramVal);
	StartAddress = atoi(m_InputPara[1]->paramVal);
	Count = atoi(m_InputPara[2]->paramVal);
	if (m_InputPara[3]->LparamVal != NULL)
	{
		strLength = strlen(m_InputPara[3]->LparamVal);
		TmpStr = (char *) malloc((strLength + 10)*sizeof(char));
		sprintf(TmpStr , "%s", m_InputPara[3]->LparamVal);		
	}
	else
	{
		strLength = strlen(m_InputPara[3]->paramVal);
		TmpStr = (char *) malloc((strLength + 10)*sizeof(char));
		sprintf(TmpStr , "%s", m_InputPara[3]->paramVal);
	}
	//分离DA值
	FlashData[0] = atoi(&TmpStr[0]);
	for(i = 1, j = 1; i<strLength; i++)
	{
		if (TmpStr[i] == ',')
		{
			FlashData[j] = atoi(&TmpStr[i+1]);
			j++;
		}
	}
	//释放内存
	free(TmpStr);
	res = NTS_SetStarAndStopFlash(vHandle, FlashIndex, StartAddress, Count, FlashData);
	return res;
}

//M_NTS_GetStarAndStopFlash 
M_NTS_GetStarAndStopFlash::M_NTS_GetStarAndStopFlash()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取模块FLAST起止地址的数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_NTS_GetStarAndStopFlash::~M_NTS_GetStarAndStopFlash()
{
//	free(m_InputDeviceName);
//	free(m_InputPara[0]);	
//	free(m_InputPara[1]);	
//	free(m_InputPara[2]);	
//	free(m_OutputPara1);
}

int M_NTS_GetStarAndStopFlash::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "%s", "FlashIndex");
	m_InputPara[0]->paramType = NTSInt16;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"");
	sprintf(m_InputPara[0]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[0]);	
		
	sprintf(m_InputPara[1]->paramName, "%s", "StartAddress");
	m_InputPara[1]->paramType = NTSInt16;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"");
	sprintf(m_InputPara[1]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[1]);

	sprintf(m_InputPara[2]->paramName, "%s", "Count");
	m_InputPara[2]->paramType = NTSInt16;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"");
	sprintf(m_InputPara[2]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[2]);

	sprintf(m_OutputPara1->paramName, "%s", "FlashData");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit ,"%s", "");
	m_OutputParamVector.push_back(m_OutputPara1);
	return NTS_SUCCESS;
}
int M_NTS_GetStarAndStopFlash::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	short FlashIndex;
	int StartAddress;
	long Count;
	int i;
	char *TmpStr = NULL;
	int FlashData[1024] = {0};
	int res;


	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	FlashIndex = atoi(m_InputPara[0]->paramVal);
	StartAddress = atoi(m_InputPara[1]->paramVal);
	Count = atoi(m_InputPara[2]->paramVal);
	if (Count > 1024) 
	{
		Count = 1024;
	}
	res = NTS_GetStarAndStopFlash(vHandle, FlashIndex, StartAddress, Count, FlashData);
	if (res != NTS_SUCCESS)
	{
		return res;			
	}
	TmpStr = (char *) malloc((Count*7 + 10)*sizeof(char));	
	for(i = 0 ; i< Count; i++)
	{
		if (i == 0)
		{
			sprintf(TmpStr, "%d", FlashData[i]);
		}
		else
		{
			sprintf(TmpStr, "%s ,%d", TmpStr, FlashData[i]);
		}
	}
	if (strlen(TmpStr) > PARALENGTH)
	{		
		m_OutputPara1->LparamVal = (char *)malloc((strlen(TmpStr) + 10)*sizeof(char));
		sprintf(m_OutputPara1->LparamVal, "%s", TmpStr);
	}
	else
	{
		sprintf(m_OutputPara1->paramVal, "%s", TmpStr);
	}	
	//释放内存
	free(TmpStr);
	
	return res;
}

// M_NTS_SetStarAndStopEEPROM 
M_NTS_SetStarAndStopEEPROM::M_NTS_SetStarAndStopEEPROM()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置起止地址的RRPROM数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();		
	Init();
}

M_NTS_SetStarAndStopEEPROM::~M_NTS_SetStarAndStopEEPROM()
{
//	free(m_InputDeviceName);
//	free(m_InputPara[0]);	
//	free(m_InputPara[1]);	
//	free(m_InputPara[2]);	
}

int M_NTS_SetStarAndStopEEPROM::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "%s", "StartAddress");
	m_InputPara[0]->paramType = NTSInt16;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"");
	sprintf(m_InputPara[0]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[0]);	
		
	sprintf(m_InputPara[1]->paramName, "%s", "Count");
	m_InputPara[1]->paramType = NTSInt16;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"");
	sprintf(m_InputPara[1]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[1]);

	sprintf(m_InputPara[2]->paramName, "%s", "EEPROMData");
	m_InputPara[2]->paramType = NTSString;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"");
	sprintf(m_InputPara[2]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[2]);

	return NTS_SUCCESS;
}
int M_NTS_SetStarAndStopEEPROM::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int StartAddress;
	long Count;
	int i, j, strLength;
	char *TmpStr = NULL;
	float Data[1024] = {0};
	int res;


	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;


	StartAddress = atoi(m_InputPara[0]->paramVal);
	Count = atoi(m_InputPara[1]->paramVal);
	if (m_InputPara[2]->LparamVal != NULL)
	{
		strLength = strlen(m_InputPara[2]->LparamVal);
		TmpStr = (char *) malloc((strLength + 10)*sizeof(char));
		sprintf(TmpStr , "%s", m_InputPara[2]->LparamVal);		
	}
	else
	{
		strLength = strlen(m_InputPara[2]->paramVal);
		TmpStr = (char *) malloc((strLength + 10)*sizeof(char));
		sprintf(TmpStr , "%s", m_InputPara[2]->paramVal);
	}
	//分离DA值
	Data[0] = atof(&TmpStr[0]);
	for(i = 1, j = 1; i<strLength; i++)
	{
		if (TmpStr[i] == ',')
		{
			Data[j] = atof(&TmpStr[i+1]);
			j++;
		}
	}
	//释放内存
	free(TmpStr);
	res = NTS_SetStarAndStopEEPROM(vHandle, StartAddress, Count, Data);
	return res;
}

//M_NTS_GetStarAndStopEEPROM 
M_NTS_GetStarAndStopEEPROM::M_NTS_GetStarAndStopEEPROM()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取起止地址的RRPROM数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();	
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_NTS_GetStarAndStopEEPROM::~M_NTS_GetStarAndStopEEPROM()
{
//	free(m_InputDeviceName);
//	free(m_InputPara[0]);	
//	free(m_InputPara[1]);		
//	free(m_OutputPara1);
}

int M_NTS_GetStarAndStopEEPROM::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "%s", "StartAddress");
	m_InputPara[0]->paramType = NTSInt16;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"");
	sprintf(m_InputPara[0]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[0]);	
		
	sprintf(m_InputPara[1]->paramName, "%s", "Count");
	m_InputPara[1]->paramType = NTSInt16;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"");
	sprintf(m_InputPara[1]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[1]);
	
	sprintf(m_OutputPara1->paramName, "%s", "Data");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit ,"%s", "");
	m_OutputParamVector.push_back(m_OutputPara1);
	return NTS_SUCCESS;
}
int M_NTS_GetStarAndStopEEPROM::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int StartAddress;
	long Count;
	int i;
	char *TmpStr = NULL;
	float Data[1024] = {0};
	int res;


	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	StartAddress = atoi(m_InputPara[0]->paramVal);
	Count = atoi(m_InputPara[1]->paramVal);
	res = NTS_GetStarAndStopEEPROM(vHandle, StartAddress, Count, Data);
	if (res != NTS_SUCCESS)
	{
		return res;			
	}
	TmpStr = (char *) malloc((Count*9 + 10)*sizeof(char));	
	for(i = 0 ; i< Count; i++)
	{
		if (i == 0)
		{
			sprintf(TmpStr, "%0.1f", Data[i]);
		}
		else
		{
			sprintf(TmpStr, "%s ,%0.1f", TmpStr, Data[i]);
		}
	}
	if (strlen(TmpStr) > PARALENGTH)
	{		
		m_OutputPara1->LparamVal = (char *)malloc((strlen(TmpStr) + 10)*sizeof(char));
		sprintf(m_OutputPara1->LparamVal, "%s", TmpStr);
	}
	else
	{
		sprintf(m_OutputPara1->paramVal, "%s", TmpStr);
	}	
	//释放内存
	free(TmpStr);
	
	return res;
}


// class M_NTS_SetCRC 
M_NTS_SetCRC::M_NTS_SetCRC()
:BaseMethod()
{
	sprintf(m_MethodScript, "写EEPROM离线参数的校验码");
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_NTS_SetCRC::~M_NTS_SetCRC()
{
//	free(m_InputDeviceName);
}

int M_NTS_SetCRC::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);	
	
	return NTS_SUCCESS;
}
int M_NTS_SetCRC::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	
	sprintf(vDeviveName, m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	res = NTS_SetCRC(vHandle);
	return res;
}

// M_NTS_SetPID 
M_NTS_SetPID::M_NTS_SetPID()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置电流调试参数");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();
	m_InputPara[3] = CreateParamStruct();
	Init();
}

M_NTS_SetPID::~M_NTS_SetPID()
{
//	free(m_InputDeviceName);
//	free(m_InputPara[0]);
//	free(m_InputPara[1]);
//	free(m_InputPara[2]);
//	free(m_InputPara[3]);
}

int M_NTS_SetPID::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "GainIndex");
	m_InputPara[0]->paramType = NTSInt16;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"1");
	sprintf(m_InputPara[0]->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara[0]);	
	
	sprintf(m_InputPara[1]->paramName, "P of PID");
	m_InputPara[1]->paramType = NTSReal64;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"5");
	sprintf(m_InputPara[1]->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara[1]);	

	sprintf(m_InputPara[2]->paramName, "I of PID");
	m_InputPara[2]->paramType = NTSReal64;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"100");
	sprintf(m_InputPara[2]->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara[2]);	

	sprintf(m_InputPara[3]->paramName, "D of PID");
	m_InputPara[3]->paramType = NTSReal64;
	m_InputPara[3]->paramCount = 1;
	sprintf(m_InputPara[3]->paramVal,"20");
	sprintf(m_InputPara[3]->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara[3]);	

	return NTS_SUCCESS;
}
int M_NTS_SetPID::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	int GainIndex;
	double P, I, D;
	
	sprintf(vDeviveName, m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	GainIndex = atoi(m_InputPara[0]->paramVal);
	P = atof(m_InputPara[1]->paramVal);
	I = atof(m_InputPara[2]->paramVal);
	D = atof(m_InputPara[3]->paramVal);
	res = NTS_SetPID(vHandle, GainIndex, P, I, D);
	return res;
}
// M_NTS_SetGainWorkPara 
M_NTS_SetGainWorkPara::M_NTS_SetGainWorkPara()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置功放的静态工作参数");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();
	m_InputPara[3] = CreateParamStruct();
	m_InputPara[4] = CreateParamStruct();
	m_InputPara[5] = CreateParamStruct();
	Init();
}

M_NTS_SetGainWorkPara::~M_NTS_SetGainWorkPara()
{
//	free(m_InputDeviceName);
//	free(m_InputPara[0]);
//	free(m_InputPara[1]);
//	free(m_InputPara[2]);
//	free(m_InputPara[3]);
//	free(m_InputPara[4]);
//	free(m_InputPara[5]);
}

int M_NTS_SetGainWorkPara::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "GainIndex");
	m_InputPara[0]->paramType = NTSInt16;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"1");
	sprintf(m_InputPara[0]->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara[0]);	
	
	// 静态工作电流
	sprintf(m_InputPara[1]->paramName, "WorkCurrent");
	m_InputPara[1]->paramType = NTSReal64;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"");
	sprintf(m_InputPara[1]->paramUnit, "A");
	m_InputParamVector.push_back(m_InputPara[1]);	
	
	// 调试误差电流
	sprintf(m_InputPara[2]->paramName, "ErrCurrent");
	m_InputPara[2]->paramType = NTSReal64;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"5");
	sprintf(m_InputPara[2]->paramUnit, "mA");
	m_InputParamVector.push_back(m_InputPara[2]);	
	
	// 
	sprintf(m_InputPara[3]->paramName, "InitDA");
	m_InputPara[3]->paramType = NTSInt16;
	m_InputPara[3]->paramCount = 1;
	sprintf(m_InputPara[3]->paramVal,"2000");
	sprintf(m_InputPara[3]->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara[3]);	

	sprintf(m_InputPara[4]->paramName, "MinDA");
	m_InputPara[4]->paramType = NTSInt16;
	m_InputPara[4]->paramCount = 1;
	sprintf(m_InputPara[4]->paramVal,"1000");
	sprintf(m_InputPara[4]->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara[4]);	

	sprintf(m_InputPara[5]->paramName, "MaxDA");
	m_InputPara[5]->paramType = NTSInt16;
	m_InputPara[5]->paramCount = 1;
	sprintf(m_InputPara[5]->paramVal,"3000");
	sprintf(m_InputPara[5]->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara[5]);	
	
	return NTS_SUCCESS;
}
int M_NTS_SetGainWorkPara::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	int GainIndex;
	int InitDA, MinDA, MaxDA;
	double WorkCurrent, ErrCurrent;	
	
	sprintf(vDeviveName, m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	GainIndex = atoi(m_InputPara[0]->paramVal);
	WorkCurrent = atof(m_InputPara[1]->paramVal);
	ErrCurrent = atof(m_InputPara[2]->paramVal);
	InitDA = atoi(m_InputPara[3]->paramVal);
	MinDA = atoi(m_InputPara[4]->paramVal);
	MaxDA = atoi(m_InputPara[5]->paramVal);
	res = NTS_SetGainWorkPara(vHandle, GainIndex, WorkCurrent, ErrCurrent, InitDA, MinDA, MaxDA);
	return res;
}
// M_NTS_GainDebug
M_NTS_GainDebug::M_NTS_GainDebug()
:BaseMethod()
{
	sprintf(m_MethodScript, "在电流表下调试单级功放的静态工作电流");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();
	m_InputPara[3] = CreateParamStruct();
	m_InputPara[4] = CreateParamStruct();

	m_OutputPara[0] = CreateParamStruct();
	m_OutputPara[1] = CreateParamStruct();
	Init();
}

M_NTS_GainDebug::~M_NTS_GainDebug()
{
/*	free(m_InputDeviceName);
	free(m_InputPara[0]);
	free(m_InputPara[1]);
	free(m_InputPara[2]);
	free(m_InputPara[3]);
	free(m_InputPara[4]);

	free(m_OutputPara[0]);
	free(m_OutputPara[1]);*/
}

int M_NTS_GainDebug::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "MMTPort");
	m_InputPara[0]->paramType = NTSInt16;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"1");
	sprintf(m_InputPara[0]->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara[0]);	
	
	sprintf(m_InputPara[1]->paramName, "Ch");
	m_InputPara[1]->paramType = NTSInt16;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"1");
	sprintf(m_InputPara[1]->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara[1]);

	sprintf(m_InputPara[2]->paramName, "GainIndex");
	m_InputPara[2]->paramType = NTSInt16;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"1");
	sprintf(m_InputPara[2]->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara[2]);	
	
	sprintf(m_InputPara[3]->paramName, "FlashIndex");
	m_InputPara[3]->paramType = NTSInt16;
	m_InputPara[3]->paramCount = 1;
	sprintf(m_InputPara[3]->paramVal,"1");
	sprintf(m_InputPara[3]->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara[3]);		
	
	sprintf(m_InputPara[4]->paramName, "StartAddress");
	m_InputPara[4]->paramType = NTSInt16;
	m_InputPara[4]->paramCount = 1;
	sprintf(m_InputPara[4]->paramVal,"0");
	sprintf(m_InputPara[4]->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara[4]);	
	
	sprintf(m_OutputPara[0]->paramName, "RefTemperature");
	m_OutputPara[0]->paramType = NTSReal32;
	m_OutputPara[0]->paramCount = 1;
	sprintf(m_OutputPara[0]->paramVal,"");
	sprintf(m_OutputPara[0]->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara[0]);	

	sprintf(m_OutputPara[1]->paramName, "RefDA");
	m_OutputPara[1]->paramType = NTSInt16;
	m_OutputPara[1]->paramCount = 1;
	sprintf(m_OutputPara[1]->paramVal,"");
	sprintf(m_OutputPara[1]->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara[1]);	
	
	return NTS_SUCCESS;
}
int M_NTS_GainDebug::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	short int MMTPort;
	short Ch;
	int GainIndex, FlashIndex, BaseAddress;
	float RefTemperature;
	int RefDA;
	
	sprintf(vDeviveName, m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	MMTPort = atoi(m_InputPara[0]->paramVal);
	Ch = atoi(m_InputPara[1]->paramVal);
	GainIndex = atoi(m_InputPara[2]->paramVal);
	FlashIndex = atoi(m_InputPara[3]->paramVal);
	BaseAddress = atoi(m_InputPara[4]->paramVal);	
	res = NTS_GainDebug(vHandle, MMTPort, Ch, GainIndex, FlashIndex, BaseAddress, &RefTemperature, &RefDA);
	if ( res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara[0]->paramVal, "%e", RefTemperature);
		sprintf(m_OutputPara[1]->paramVal, "%d", RefDA);
	}
	return res;
}

// M_NTS_GetVoltage 
M_NTS_GetVoltage::M_NTS_GetVoltage()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取通道的电压(单位:bit)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();

	m_OutputPara1 = CreateParamStruct();

	Init();
}

M_NTS_GetVoltage::~M_NTS_GetVoltage()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
	
//	free(m_OutputPara1);
}

int M_NTS_GetVoltage::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_OutputPara1->paramName, "Voltage");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara1);

	return NTS_SUCCESS;
}
int M_NTS_GetVoltage::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	short Ch;
	float Voltage;

	
	sprintf(vDeviveName, m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	Ch = atoi(m_InputPara1->paramVal);
	res = NTS_GetVoltage(vHandle, Ch, &Voltage);
	if ( res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", Voltage);	
	}
	return res;
}

// M_NTS_SetActiveObject 
M_NTS_SetActiveObject::M_NTS_SetActiveObject()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置当前需要监控的对象(Type 1:电流 2:电压 3:温度 Index 1:推动级/28V 2:末级/5V 3:Peak 4:peak2)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}

M_NTS_SetActiveObject::~M_NTS_SetActiveObject()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);

}

int M_NTS_SetActiveObject::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);	
	
	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "Type");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "Index");
	m_InputPara3->paramType = NTSInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"1");
	sprintf(m_InputPara3->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara3);

	return NTS_SUCCESS;
}
int M_NTS_SetActiveObject::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	int Type, ObjectIndex;
	short Ch;
	
	
	sprintf(vDeviveName, m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	Ch = atoi(m_InputPara1->paramVal);
	Type = atoi(m_InputPara2->paramVal);
	ObjectIndex = atoi(m_InputPara3->paramVal);

	res = NTS_SetActiveObject(vHandle, Ch, Type, ObjectIndex);
	return res;
}