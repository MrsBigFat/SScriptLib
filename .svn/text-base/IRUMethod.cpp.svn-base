
#include "stdafx.h"
#include "IRUMethod.h"
#include <assert.h>
#include "stdio.h"
#include <map>


extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

/************************************************************************/
/*  IRU驱动方法类														*/
/************************************************************************/

//class M_IRU_Reboot
M_IRU_Reboot::M_IRU_Reboot()
:BaseMethod()
{
	sprintf(m_MethodScript, "重启");
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_IRU_Reboot::~M_IRU_Reboot()
{
//	free(m_InputDeviceName);
}

int M_IRU_Reboot::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = IRUDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}

int M_IRU_Reboot::Run(void)
{
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
	
	return IRU_Reboot(vHandle);
}

//class M_IRU_Reset
M_IRU_Reset::M_IRU_Reset()
:BaseMethod()
{
	sprintf(m_MethodScript, "复位");
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_IRU_Reset::~M_IRU_Reset()
{
//	free(m_InputDeviceName);
}

int M_IRU_Reset::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = IRUDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}

int M_IRU_Reset::Run(void)
{
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
	
	return IRU_Reset(vHandle);
}

//class M_IRU_SendCmd 
M_IRU_SendCmd::M_IRU_SendCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	
	Init();
}

M_IRU_SendCmd::~M_IRU_SendCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);	
}

int M_IRU_SendCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = IRUDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "Command");
	m_InputPara->paramType = NTSString;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara);
	
	return NTS_SUCCESS;
}
int M_IRU_SendCmd::Run(void)
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

	sprintf(CmdStr, "%s", m_InputPara->paramVal);
	return IRU_SendCmd(vHandle, CmdStr);
}

//class M_IRU_GetCmd 
M_IRU_GetCmd::M_IRU_GetCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令并获取指令的返回数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_IRU_GetCmd::~M_IRU_GetCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);	
//	free(m_OutputPara);
}

int M_IRU_GetCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = IRUDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "Command");
	m_InputPara->paramType = NTSString;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara);

	sprintf(m_OutputPara->paramName, "RetStr");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_IRU_GetCmd::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char CmdStr[500] = {0};
	char RetStr[40000] = {0};
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	//获取输入参数值 
	if (m_InputPara->LparamVal != NULL)
	{
		sprintf(CmdStr, "%s", m_InputPara->LparamVal);
	}
	else
	{
		sprintf(CmdStr, "%s", m_InputPara->paramVal);
	}	
	res = IRU_GetCmd(vHandle, CmdStr, RetStr);
	if (res != NTS_SUCCESS)
	{
		return res;		
	}
	if (strlen(RetStr) > PARALENGTH)
	{		
		m_OutputPara->LparamVal = (char *)malloc((strlen(RetStr) + 10)*sizeof(char));
		sprintf(m_OutputPara->LparamVal, "%s", RetStr);
	}
	else
	{
		sprintf(m_OutputPara->paramVal, "%s", RetStr);
	}	
	return res;
}

//class M_IRU_GetIDN 
M_IRU_GetIDN::M_IRU_GetIDN()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取设备型号信息");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_IRU_GetIDN::~M_IRU_GetIDN()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara);
}

int M_IRU_GetIDN::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = IRUDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara->paramName, "IDN");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_IRU_GetIDN::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char IDN[500] = {0};	
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	res = IRU_GetIDN(vHandle, IDN);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal, "%s", IDN);
	}
	return res;
}

//M_IRU_LoadFile 
M_IRU_LoadFile::M_IRU_LoadFile()
:BaseMethod()
{
	sprintf(m_MethodScript, "加载文件");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}

M_IRU_LoadFile::~M_IRU_LoadFile()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);	
}

int M_IRU_LoadFile::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = IRUDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName , "FileName");
	m_InputPara->paramType = NTSString;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	return NTS_SUCCESS;
}
int M_IRU_LoadFile::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char FileName[1024] = {0};
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	//获取输入参数值 
	if (m_InputPara->LparamVal != NULL)
	{
		sprintf(FileName, "%s", m_InputPara->LparamVal);
	}
	else
	{
		sprintf(FileName, "%s", m_InputPara->paramVal);
	}	
	res = IRU_LoadFile(vHandle, FileName);
	if (res != NTS_SUCCESS)
	{
		return res;		
	}
	return res;
}