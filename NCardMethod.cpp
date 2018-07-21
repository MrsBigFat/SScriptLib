
#include "stdafx.h"
#include "NCardMethod.h"
#include <assert.h>
#include "stdio.h"
#include <map>
#include <string>
using std::string;

extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

#define INIT_DEV_NAME  sprintf(m_InputDeviceName->paramName, "ConnectStr");\
					   m_InputDeviceName->paramType = NCARDDevice;\
					   m_InputDeviceName->paramCount = 1;\
				   	   sprintf(m_InputDeviceName->paramVal,"");\
					   sprintf(m_InputDeviceName->paramUnit, " ");\
					   m_InputParamVector.push_back(m_InputDeviceName)

// M_NC_OpenDev 
M_NC_OpenDev::M_NC_OpenDev()
:BaseMethod()
{
	sprintf(m_MethodScript, "打开并初始化NCard");
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_NC_OpenDev::~M_NC_OpenDev()
{
//	free(m_InputDeviceName);
}

int M_NC_OpenDev::Init(void)
{
	INIT_DEV_NAME;
	return NTS_SUCCESS;
}

int M_NC_OpenDev::Run(void)
{
	int vHandle = 0;
	return OpenDevice(NCARD, const_cast<char*>(string(m_InputDeviceName->paramVal).c_str()) , &vHandle);	
}
//M_NC_CloseDev
M_NC_CloseDev::M_NC_CloseDev()
{
	sprintf(m_MethodScript,"关闭NCard设备");
	m_InputDeviceName = CreateParamStruct();
	init();
}
M_NC_CloseDev::~M_NC_CloseDev()
{
//	free(m_InputDeviceName);
}
int M_NC_CloseDev::init()
{
	INIT_DEV_NAME;
	return NTS_SUCCESS;
}
int M_NC_CloseDev::Run()
{
	return CloseDevice(NCARD, const_cast<char*>(string(m_InputDeviceName->paramVal).c_str()));
}

//M_NC_QuerySysParam
M_NC_QuerySysParam::M_NC_QuerySysParam()
{
	sprintf(m_MethodScript,"系统参数查询");
	m_InputDeviceName = CreateParamStruct();
	m_OutputSysparam = CreateParamStruct();
	init();
}
M_NC_QuerySysParam::~M_NC_QuerySysParam()
{
//	free(m_InputDeviceName);
//	free(m_OutputSysparam);
}
int M_NC_QuerySysParam::init()
{
	INIT_DEV_NAME;

	sprintf(m_OutputSysparam->paramName, "SysParam");
	m_OutputSysparam->paramType = NTSString;
	m_OutputSysparam->paramCount = 1;
	sprintf(m_OutputSysparam->paramVal,"");
	sprintf(m_OutputSysparam->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputSysparam);
	return NTS_SUCCESS;
}
int M_NC_QuerySysParam::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	char RetStr[40000] = {0};
	int res = NC_QuerySysParam(it->second.DevHandle,RetStr);
	if (res != NTS_SUCCESS)
	{
		return res;
	}
	if (strlen(RetStr) > PARALENGTH)
	{		
		m_OutputSysparam->LparamVal = (char *)malloc((strlen(RetStr) + 10)*sizeof(char));
		sprintf(m_OutputSysparam->LparamVal, "%s", RetStr);
	}
	else
	{
		sprintf(m_OutputSysparam->paramVal, "%s", RetStr);
	}
	return res;
}

//M_NC_QuerySysState
M_NC_QuerySysState::M_NC_QuerySysState()
{
	sprintf(m_MethodScript,"系统状态查询");
	m_InputDeviceName = CreateParamStruct();
	m_OutputSysState = CreateParamStruct();
	init();
}
M_NC_QuerySysState::~M_NC_QuerySysState()
{
//	free(m_InputDeviceName);
//	free(m_OutputSysState);
}
int M_NC_QuerySysState::init()
{
	INIT_DEV_NAME;

	sprintf(m_OutputSysState->paramName, "SysState");
	m_OutputSysState->paramType = NTSString;
	m_OutputSysState->paramCount = 1;
	sprintf(m_OutputSysState->paramVal,"");
	sprintf(m_OutputSysState->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputSysState);
	return NTS_SUCCESS;
}
int M_NC_QuerySysState::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	char RetStr[40000] = {0};
	int res = NC_QuerySysState(it->second.DevHandle,RetStr);
	if (res != NTS_SUCCESS)
	{
		return res;
	}
	if (strlen(RetStr) > PARALENGTH)
	{		
		m_OutputSysState->LparamVal = (char *)malloc((strlen(RetStr) + 10)*sizeof(char));
		sprintf(m_OutputSysState->LparamVal, "%s", RetStr);
	}
	else
	{
		sprintf(m_OutputSysState->paramVal, "%s", RetStr);
	}
	return res;
}

//M_NC_CreateCommObject
M_NC_CreateCommObject::M_NC_CreateCommObject()
{
	sprintf(m_MethodScript,"创建通讯对象");
	m_InputDeviceName = CreateParamStruct();
	m_InputConnStr = CreateParamStruct();
	m_OutputObjID = CreateParamStruct();
	init();
}
M_NC_CreateCommObject::~M_NC_CreateCommObject()
{
//	free(m_InputDeviceName);
//	free(m_InputConnStr);
//	free(m_OutputObjID);
}
int M_NC_CreateCommObject::init()
{
	INIT_DEV_NAME;
	sprintf(m_InputConnStr->paramName, "CommConnectStr");
	m_InputConnStr->paramType = NTSString;
	m_InputConnStr->paramCount = 1;
	sprintf(m_InputConnStr->paramUnit , "");
	sprintf(m_InputConnStr->paramVal,"");
	m_InputParamVector.push_back(m_InputConnStr);

	sprintf(m_OutputObjID->paramName, "ObjID");
	m_OutputObjID->paramType = NTSInt32;
	m_OutputObjID->paramCount = 1;
	sprintf(m_OutputObjID->paramUnit , "");
	sprintf(m_OutputObjID->paramVal,"");
	m_OutputParamVector.push_back(m_OutputObjID);
	return NTS_SUCCESS;
}
int M_NC_CreateCommObject::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if (it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	long objID = -1;
	int res = NC_CreateCommObject(it->second.DevHandle,m_InputConnStr->paramVal,&objID);
	if (res != NTS_SUCCESS)
	{
		return res;
	}
	sprintf(m_OutputObjID->paramVal,"%d",objID);
	return NTS_SUCCESS;
}

//M_NC_DeleteCommObject
M_NC_DeleteCommObject::M_NC_DeleteCommObject()
{
	sprintf(m_MethodScript,"销毁通讯对象");
	m_InputDeviceName = CreateParamStruct();
	m_InputObjID = CreateParamStruct();
	init();
}
M_NC_DeleteCommObject::~M_NC_DeleteCommObject()
{
//	free(m_InputDeviceName);
//	free(m_InputObjID);
}
int M_NC_DeleteCommObject::init()
{
	INIT_DEV_NAME;
	sprintf(m_InputObjID->paramName, "ObjID");
	m_InputObjID->paramType = NTSInt32;
	m_InputObjID->paramCount = 1;
	sprintf(m_InputObjID->paramUnit , "");
	sprintf(m_InputObjID->paramVal,"");
	m_InputParamVector.push_back(m_InputObjID);
	return NTS_SUCCESS;
}
int M_NC_DeleteCommObject::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if (it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	int res = NC_DeleteCommObject(it->second.DevHandle,atoi(m_InputObjID->paramVal));
	if (res != NTS_SUCCESS)
	{
		return res;
	}
	return NTS_SUCCESS;
}

//M_NC_Read
M_NC_Read::M_NC_Read()
{
	sprintf(m_MethodScript,"通讯对象的读操作---dataFormat: 0:字符串格式;10:十进制; 16:十六进制");
	m_InputDeviceName = CreateParamStruct();
	m_InputObjID = CreateParamStruct();
	m_InputExpLen = CreateParamStruct();
	m_InputDataFormat = CreateParamStruct();
	m_OutputRead = CreateParamStruct();
	m_OutputRealLen = CreateParamStruct();
	init();
}
M_NC_Read::~M_NC_Read()
{
//	free(m_InputDeviceName);
//	free(m_InputObjID);
//	free(m_InputExpLen);
//	free(m_InputDataFormat);
//	free(m_OutputRead);
//	free(m_OutputRealLen);
}
int M_NC_Read::init()
{
	INIT_DEV_NAME;
	sprintf(m_InputObjID->paramName, "ObjID");
	m_InputObjID->paramType = NTSInt32;
	m_InputObjID->paramCount = 1;
	sprintf(m_InputObjID->paramUnit , "");
	sprintf(m_InputObjID->paramVal,"");
	m_InputParamVector.push_back(m_InputObjID);
	
	sprintf(m_InputExpLen->paramName, "ExpLen");
	m_InputExpLen->paramType = NTSInt32;
	m_InputExpLen->paramCount = 1;
	sprintf(m_InputExpLen->paramUnit , "");
	sprintf(m_InputExpLen->paramVal, "");
	m_InputParamVector.push_back(m_InputExpLen);

	sprintf(m_InputDataFormat->paramName, "dataFormat");
	m_InputDataFormat->paramType = NTSInt32;
	m_InputDataFormat->paramCount = 1;
	sprintf(m_InputDataFormat->paramUnit , "");
	sprintf(m_InputDataFormat->paramVal, "%d",0);
	m_InputParamVector.push_back(m_InputDataFormat);

	sprintf(m_OutputRead->paramName, "RetStr");
	m_OutputRead->paramType = NTSString;
	m_OutputRead->paramCount = 1;
	sprintf(m_OutputRead->paramUnit , "");
	sprintf(m_OutputRead->paramVal,"");
	m_OutputParamVector.push_back(m_OutputRead);
	
	sprintf(m_OutputRealLen->paramName, "RealLen");
	m_OutputRealLen->paramType = NTSInt32;
	m_OutputRealLen->paramCount = 1;
	sprintf(m_OutputRealLen->paramUnit , "");
	sprintf(m_OutputRealLen->paramVal,"");
	m_OutputParamVector.push_back(m_OutputRealLen);
	return NTS_SUCCESS;
}
int M_NC_Read::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if (it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	char RetStr[4000] = {0};
	unsigned long realLen = 0;
	int res = NC_Read(it->second.DevHandle,atoi(m_InputObjID->paramVal),atoi(m_InputExpLen->paramVal),atoi(m_InputDataFormat->paramVal),RetStr,&realLen);
	if (res != NTS_SUCCESS)
	{
		return res;
	}
	if (strlen(RetStr) > PARALENGTH)
	{		
		m_OutputRead->LparamVal = (char *)malloc((strlen(RetStr) + 10)*sizeof(char));
		sprintf(m_OutputRead->LparamVal, "%s", RetStr);
	}
	else
	{
		sprintf(m_OutputRead->paramVal, "%s", RetStr);
	}
	sprintf(m_OutputRealLen->paramVal,"%d",realLen);
	return NTS_SUCCESS;
}

//M_NC_Write
M_NC_Write::M_NC_Write()
{
sprintf(m_MethodScript,"通讯对象写操作---dataFormat: 0:字符串格式；\
		10:十进制(-128~127)；16:十六进制(0~FF),其中,数字之间可用逗号或空格分隔");
	m_InputDeviceName = CreateParamStruct();
	m_InputObjID = CreateParamStruct();
	m_InputExpLen = CreateParamStruct();
	m_InputWrite = CreateParamStruct();
	m_InputDataFormat = CreateParamStruct();
	m_OutputRealLen = CreateParamStruct();
	init();
}
M_NC_Write::~M_NC_Write()
{
//	free(m_InputDeviceName);
//	free(m_InputObjID);
//	free(m_InputExpLen);
//	free(m_InputDataFormat);
//	free(m_InputWrite);
//	free(m_OutputRealLen);
}
int M_NC_Write::init()
{
	INIT_DEV_NAME;
	sprintf(m_InputObjID->paramName, "ObjID");
	m_InputObjID->paramType = NTSInt32;
	m_InputObjID->paramCount = 1;
	sprintf(m_InputObjID->paramUnit , "");
	sprintf(m_InputObjID->paramVal,"");
	m_InputParamVector.push_back(m_InputObjID);
	
	sprintf(m_InputExpLen->paramName, "ExpLen");
	m_InputExpLen->paramType = NTSInt32;
	m_InputExpLen->paramCount = 1;
	sprintf(m_InputExpLen->paramUnit , "");
	sprintf(m_InputExpLen->paramVal,"");
	m_InputParamVector.push_back(m_InputExpLen);
	
	sprintf(m_InputDataFormat->paramName, "dataFormat");
	m_InputDataFormat->paramType = NTSInt32;
	m_InputDataFormat->paramCount = 1;
	sprintf(m_InputDataFormat->paramUnit , "");
	sprintf(m_InputDataFormat->paramVal, "%d",0);
	m_InputParamVector.push_back(m_InputDataFormat);
	
	sprintf(m_InputWrite->paramName, "WriteStr");
	m_InputWrite->paramType = NTSString;
	m_InputWrite->paramCount = 1;
	sprintf(m_InputWrite->paramUnit , "");
	sprintf(m_InputWrite->paramVal,"");
	m_InputParamVector.push_back(m_InputWrite);

	sprintf(m_OutputRealLen->paramName, "RealLen");
	m_OutputRealLen->paramType = NTSInt32;
	m_OutputRealLen->paramCount = 1;
	sprintf(m_OutputRealLen->paramUnit , "");
	sprintf(m_OutputRealLen->paramVal,"");
	m_OutputParamVector.push_back(m_OutputRealLen);
	return NTS_SUCCESS;
}
int M_NC_Write::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if (it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	unsigned long realLen = 0;
	int res = NC_Write(it->second.DevHandle,atoi(m_InputObjID->paramVal),atoi(m_InputExpLen->paramVal),atoi(m_InputDataFormat->paramVal),m_InputWrite->paramVal,&realLen);
	if (res != NTS_SUCCESS)
	{
		return res;
	}
	sprintf(m_OutputRealLen->paramVal,"%d",realLen);
	return NTS_SUCCESS;
}

//M_NC_SetBufSize
M_NC_SetBufSize::M_NC_SetBufSize()
{
	sprintf(m_MethodScript,"设置通讯对象缓冲区大小(Type 0:all 1:Read 2:Write)");
	m_InputDeviceName = CreateParamStruct();
	m_InputObjID = CreateParamStruct();
	m_InputType = CreateParamStruct();
	m_InputSize = CreateParamStruct();
	init();
}
M_NC_SetBufSize::~M_NC_SetBufSize()
{
//	free(m_InputDeviceName);
//	free(m_InputObjID);
//	free(m_InputType);
//	free(m_InputSize);
}
int M_NC_SetBufSize::init()
{
	INIT_DEV_NAME;
	sprintf(m_InputObjID->paramName, "ObjID");
	m_InputObjID->paramType = NTSInt32;
	m_InputObjID->paramCount = 1;
	sprintf(m_InputObjID->paramUnit , "");
	sprintf(m_InputObjID->paramVal,"");
	m_InputParamVector.push_back(m_InputObjID);
	
	sprintf(m_InputType->paramName, "Type");
	m_InputType->paramType = NTSInt32;
	m_InputType->paramCount = 1;
	sprintf(m_InputType->paramUnit , "");
	sprintf(m_InputType->paramVal,"");
	m_InputParamVector.push_back(m_InputType);
	
	sprintf(m_InputSize->paramName, "BufSize");
	m_InputSize->paramType = NTSInt32;
	m_InputSize->paramCount = 1;
	sprintf(m_InputSize->paramUnit , "");
	sprintf(m_InputSize->paramVal,"");
	m_InputParamVector.push_back(m_InputSize);
	return NTS_SUCCESS;
}
int M_NC_SetBufSize::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if (it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	int res = NC_SetBufSize(it->second.DevHandle,atoi(m_InputObjID->paramVal),atoi(m_InputType->paramVal),atoi(m_InputSize->paramVal));
	if (res != NTS_SUCCESS)
	{
		return res;
	}
	return NTS_SUCCESS;
}

//M_NC_ClearBuf
M_NC_ClearBuf::M_NC_ClearBuf()
{
	sprintf(m_MethodScript,"清除通讯对象缓冲区(Type 0:all 1:Read 2:Write)");
	m_InputDeviceName = CreateParamStruct();
	m_InputObjID = CreateParamStruct();
	m_InputType = CreateParamStruct();
	init();
}
M_NC_ClearBuf::~M_NC_ClearBuf()
{
//	free(m_InputDeviceName);
//	free(m_InputObjID);
//	free(m_InputType);
}
int M_NC_ClearBuf::init()
{
	INIT_DEV_NAME;
	sprintf(m_InputObjID->paramName, "ObjID");
	m_InputObjID->paramType = NTSInt32;
	m_InputObjID->paramCount = 1;
	sprintf(m_InputObjID->paramUnit , "");
	sprintf(m_InputObjID->paramVal,"");
	m_InputParamVector.push_back(m_InputObjID);
	
	sprintf(m_InputType->paramName, "Type");
	m_InputType->paramType = NTSInt32;
	m_InputType->paramCount = 1;
	sprintf(m_InputType->paramUnit , "");
	sprintf(m_InputType->paramVal,"");
	m_InputParamVector.push_back(m_InputType);
	return NTS_SUCCESS;	
}
int M_NC_ClearBuf::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if (it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	int res = NC_ClearBuf(it->second.DevHandle,atoi(m_InputObjID->paramVal),atoi(m_InputType->paramVal));
	if(res != NTS_SUCCESS)
	{
		return res;
	}
	return NTS_SUCCESS;
}

//M_NC_Sprintf
M_NC_Sprintf::M_NC_Sprintf()
{
	sprintf(m_MethodScript,"通讯对象写操作——字符串");
	m_InputDeviceName = CreateParamStruct();
	m_InputObjID = CreateParamStruct();
	m_InputCommand = CreateParamStruct();
	init();
}
M_NC_Sprintf::~M_NC_Sprintf()
{
//	free(m_InputDeviceName);
//	free(m_InputObjID);
//	free(m_InputCommand);
}
int M_NC_Sprintf::init()
{
	INIT_DEV_NAME;
	sprintf(m_InputObjID->paramName, "ObjID");
	m_InputObjID->paramType = NTSInt32;
	m_InputObjID->paramCount = 1;
	sprintf(m_InputObjID->paramUnit , "");
	sprintf(m_InputObjID->paramVal,"");
	m_InputParamVector.push_back(m_InputObjID);
	
	sprintf(m_InputCommand->paramName, "CommandStr");
	m_InputCommand->paramType = NTSString;
	m_InputCommand->paramCount = 1;
	sprintf(m_InputCommand->paramUnit , "");
	sprintf(m_InputCommand->paramVal,"");
	m_InputParamVector.push_back(m_InputCommand);
	return NTS_SUCCESS;
}
int M_NC_Sprintf::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if (it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	int res = NC_Sprintf((*it).second.DevHandle,atoi(m_InputObjID->paramVal),m_InputCommand->paramVal);
	if (res != NTS_SUCCESS)
	{
		return res;
	}
	return NTS_SUCCESS;
}

//M_NC_Query
M_NC_Query::M_NC_Query()
{
	sprintf(m_MethodScript,"通讯对象读操作——字符串");
	m_InputDeviceName = CreateParamStruct();
	m_InputObjID = CreateParamStruct();
	m_InputCommand = CreateParamStruct();
	m_OutputRetStr = CreateParamStruct();
	init();
}
M_NC_Query::~M_NC_Query()
{
//	free(m_InputDeviceName);
//	free(m_InputObjID);
//	free(m_InputCommand);
//	free(m_OutputRetStr);
}
int M_NC_Query::init()
{
	INIT_DEV_NAME;
	sprintf(m_InputObjID->paramName, "ObjID");
	m_InputObjID->paramType = NTSInt32;
	m_InputObjID->paramCount = 1;
	sprintf(m_InputObjID->paramUnit , "");
	sprintf(m_InputObjID->paramVal,"");
	m_InputParamVector.push_back(m_InputObjID);
	
	sprintf(m_InputCommand->paramName, "CommandStr");
	m_InputCommand->paramType = NTSString;
	m_InputCommand->paramCount = 1;
	sprintf(m_InputCommand->paramUnit , "");
	sprintf(m_InputCommand->paramVal,"");
	m_InputParamVector.push_back(m_InputCommand);

	sprintf(m_OutputRetStr->paramName, "RetStr");
	m_OutputRetStr->paramType = NTSString;
	m_OutputRetStr->paramCount = 1;
	sprintf(m_OutputRetStr->paramUnit , "");
	sprintf(m_OutputRetStr->paramVal,"");
	m_OutputParamVector.push_back(m_OutputRetStr);
	return NTS_SUCCESS;
}
int M_NC_Query::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if (it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	char RetStr[4000] = {0};
	int res = NC_Query((*it).second.DevHandle,atoi(m_InputObjID->paramVal),m_InputCommand->paramVal,RetStr);
	if (res != NTS_SUCCESS)
	{
		return res;
	}
	if (strlen(RetStr) > PARALENGTH)
	{		
		m_OutputRetStr->LparamVal = (char *)malloc((strlen(RetStr) + 10)*sizeof(char));
		sprintf(m_OutputRetStr->LparamVal, "%s", RetStr);
	}
	else
	{
		sprintf(m_OutputRetStr->paramVal, "%s", RetStr);
	}
	return NTS_SUCCESS;
}
//M_NC_QueryContextInfo
M_NC_QueryContextInfo::M_NC_QueryContextInfo()
{
	sprintf(m_MethodScript,"环境信息查询");
	m_InputDeviceName = CreateParamStruct();
	m_OutputSysparam = CreateParamStruct();
	init();
}
M_NC_QueryContextInfo::~M_NC_QueryContextInfo()
{
//	free(m_InputDeviceName);
//	free(m_OutputSysparam);
}
int M_NC_QueryContextInfo::init()
{
	INIT_DEV_NAME;
	
	sprintf(m_OutputSysparam->paramName, "ContextInfo");
	m_OutputSysparam->paramType = NTSString;
	m_OutputSysparam->paramCount = 1;
	sprintf(m_OutputSysparam->paramVal,"");
	sprintf(m_OutputSysparam->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputSysparam);
	return NTS_SUCCESS;
}
int M_NC_QueryContextInfo::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	char RetStr[40000] = {0};
	int res = NC_QueryContextInfo(it->second.DevHandle,RetStr);
	if (res != NTS_SUCCESS)
	{
		return res;
	}
	if (strlen(RetStr) > PARALENGTH)
	{		
		m_OutputSysparam->LparamVal = (char *)malloc((strlen(RetStr) + 10)*sizeof(char));
		sprintf(m_OutputSysparam->LparamVal, "%s", RetStr);
	}
	else
	{
		sprintf(m_OutputSysparam->paramVal, "%s", RetStr);
	}
	return res;
}
//M_NC_QueryVersionInfo
M_NC_QueryVersionInfo::M_NC_QueryVersionInfo()
{
	sprintf(m_MethodScript,"版本信息查询");
	m_InputDeviceName = CreateParamStruct();
	m_OutputSysparam = CreateParamStruct();
	init();
}
M_NC_QueryVersionInfo::~M_NC_QueryVersionInfo()
{
//	free(m_InputDeviceName);
//	free(m_OutputSysparam);
}
int M_NC_QueryVersionInfo::init()
{
	INIT_DEV_NAME;
	
	sprintf(m_OutputSysparam->paramName, "VerInfo");
	m_OutputSysparam->paramType = NTSString;
	m_OutputSysparam->paramCount = 1;
	sprintf(m_OutputSysparam->paramVal,"");
	sprintf(m_OutputSysparam->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputSysparam);
	return NTS_SUCCESS;
}
int M_NC_QueryVersionInfo::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	char RetStr[40000] = {0};
	int res = NC_QueryVersionInfo(it->second.DevHandle,RetStr);
	if (res != NTS_SUCCESS)
	{
		return res;
	}
	if (strlen(RetStr) > PARALENGTH)
	{		
		m_OutputSysparam->LparamVal = (char *)malloc((strlen(RetStr) + 10)*sizeof(char));
		sprintf(m_OutputSysparam->LparamVal, "%s", RetStr);
	}
	else
	{
		sprintf(m_OutputSysparam->paramVal, "%s", RetStr);
	}
	return res;
}
//M_NC_SetIPAddress
M_NC_SetIPAddress::M_NC_SetIPAddress()
{
	sprintf(m_MethodScript,"设置IP地址(netType: 0：LAN口；1：DUT口)");
	m_InputDeviceName = CreateParamStruct();
	m_InputNetType = CreateParamStruct();
	m_InputIPAdress = CreateParamStruct();
	init();
}
M_NC_SetIPAddress::~M_NC_SetIPAddress()
{
//	free(m_InputDeviceName);
//	free(m_InputNetType);
//	free(m_InputIPAdress);
}
int M_NC_SetIPAddress::init()
{
	INIT_DEV_NAME;
	sprintf(m_InputNetType->paramName, "netType");
	m_InputNetType->paramType = NTSInt32;
	m_InputNetType->paramCount = 1;
	sprintf(m_InputNetType->paramUnit , "");
	sprintf(m_InputNetType->paramVal,"");
	m_InputParamVector.push_back(m_InputNetType);
	
	sprintf(m_InputIPAdress->paramName, "IPAddress");
	m_InputIPAdress->paramType = NTSString;
	m_InputIPAdress->paramCount = 1;
	sprintf(m_InputIPAdress->paramUnit , "");
	sprintf(m_InputIPAdress->paramVal,"");
	m_InputParamVector.push_back(m_InputIPAdress);
	return NTS_SUCCESS;
}
int M_NC_SetIPAddress::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if (it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	int res = NC_SetIPAddress(it->second.DevHandle,atoi(m_InputNetType->paramVal),m_InputIPAdress->paramVal);
	if(res != NTS_SUCCESS)
	{
		return res;
	}
	return NTS_SUCCESS;
}
//M_NC_Reset
M_NC_Reset::M_NC_Reset()
{
	sprintf(m_MethodScript,"重启NCard设备");
	m_InputDeviceName = CreateParamStruct();
	init();
}
M_NC_Reset::~M_NC_Reset()
{
//	free(m_InputDeviceName);
}
int M_NC_Reset::init()
{
	INIT_DEV_NAME;
	return NTS_SUCCESS;
}
int M_NC_Reset::Run()
{
	TDeviceManagerMap::iterator it = gDeviceManagerMap.find(m_InputDeviceName->paramVal);
	if (it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	int res = NC_Reset(it->second.DevHandle);
	if(res != NTS_SUCCESS)
	{
		return res;
	}
	return NTS_SUCCESS;
}