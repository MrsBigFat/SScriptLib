

#include "stdafx.h"
#include "SWMethod.h"
#include <assert.h>
#include "stdio.h"


extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

//M_SW_SetSwtichState
M_SW_SetSwtichState::M_SW_SetSwtichState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置矩阵开关状态(格式: K1,k2,k3,k4,..,kn)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_SW_SetSwtichState::~M_SW_SetSwtichState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
	
}

int M_SW_SetSwtichState::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = SWIDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "StateStr");
	m_InputPara1->paramType = NTSSWLinkString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_SW_SetSwtichState::Run()
{
	char str[100];
	long strlength,count;
	short state[50];
	
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

	sprintf(str,m_InputPara1->paramVal);
	strlength = strlen(str);
	if(strlength<=0)
	{
		return NTS_INVALID_PARA;
	}
	state[0] = atoi(str);
	count = 1;
	for(int i=0;i<strlength;i++)
	{
		if(str[i] == ',')
		{
			state[count] = atoi(&str[i+1]);
			count++;
		}
	}
	return SW_SetSwtichState(vHandle,count,state);
}

// Class M_SW_SetCtrlPort
M_SW_SetCtrlPort::M_SW_SetCtrlPort()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置矩阵端口号(1~255)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_SW_SetCtrlPort::~M_SW_SetCtrlPort()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
	
}

int M_SW_SetCtrlPort::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = SWIDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit,  "");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "CtrlPort");
	m_InputPara1->paramType = NTSInt32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_SW_SetCtrlPort::Run()
{
	int vPort;	
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
	
	vPort = atoi(m_InputPara1->paramVal);	
	return NTS_INVALID_METHOD;
//		SW_SetCtrlPort(vHandle, vPort);
}
