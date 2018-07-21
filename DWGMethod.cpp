
#include "stdafx.h"
#include "DWGMethod.h"
#include <assert.h>
#include "stdio.h"
#include <map>


extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

/************************************************************************/
/*  驱动程序方法类                                            */
/************************************************************************/
//class M_DWG_Reset
M_DWG_Reset::M_DWG_Reset()
:BaseMethod()
{
	sprintf(m_MethodScript, "波形发生器复位");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_DWG_Reset::~M_DWG_Reset()
{
//	free(m_InputDeviceName);
}

int M_DWG_Reset::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DWGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	return NTS_SUCCESS;
}
int M_DWG_Reset::Run(void)
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

	return DWG_Reset(vHandle);
	return NTS_SUCCESS;
	
}


//class M_DWG_GetIDN
M_DWG_GetIDN::M_DWG_GetIDN()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取设备型号信息");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();	
	Init();
}
M_DWG_GetIDN::~M_DWG_GetIDN()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_DWG_GetIDN::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DWGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "IDN");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"0");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);


	return NTS_SUCCESS;
}
int M_DWG_GetIDN::Run(void)
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

	res = DWG_GetIDN(vHandle, IDN);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%s", IDN);
	}
	return res;

}

//class M_DWG_LoadFile
M_DWG_LoadFile::M_DWG_LoadFile()
:BaseMethod()
{
	sprintf(m_MethodScript, "加载波形文件");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_DWG_LoadFile::~M_DWG_LoadFile()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_DWG_LoadFile::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DWGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "filename");
	m_InputPara->paramType = NTSString;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"C:\\Users\\Public\\zhanght\\HDRCommAngEst\\HDRWaveCommAngEst_El0_Az2.3_EbNo100dB_Dopp0kHz_MaxV881mV_Pwr0dBm.mat");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_DWG_LoadFile::Run(void)
{
	char filename[50];
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
	
	sprintf(filename,m_InputPara->paramVal);
	return DWG_LoadFile(vHandle,filename);
}

//class M_DWG_SendCmd 
M_DWG_SendCmd::M_DWG_SendCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}
M_DWG_SendCmd::~M_DWG_SendCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_DWG_SendCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DWGDevice;
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
int M_DWG_SendCmd::Run(void)
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
	return DWG_SendCmd(vHandle, CmdStr);
}

//class M_DWG_GetCmd 
M_DWG_GetCmd::M_DWG_GetCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令并获取指令的返回数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_DWG_GetCmd::~M_DWG_GetCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara1);
}

int M_DWG_GetCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DWGDevice;
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
int M_DWG_GetCmd::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char CmdStr[500] = {0};
	char RetStr[200000] = {0};
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
	res = DWG_GetCmd(vHandle, CmdStr, RetStr);
	if (res != NTS_SUCCESS)
	{
		return res;		
	}
	if (strlen(RetStr) > PARALENGTH)
	{		
		int len = strlen(RetStr);
		m_OutputPara1->LparamVal = (char *)malloc((len + 10)*sizeof(char));
		sprintf(m_OutputPara1->LparamVal, "%s", RetStr);
	}
	else
	{
		sprintf(m_OutputPara1->paramVal, "%s", RetStr);
	}
	return res;
}

//class M_DWG_SetCHSwitch
M_DWG_SetCHSwitch::M_DWG_SetCHSwitch()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置通道开关,参数(0:关闭,1:打开)");
	m_InputDeviceName = CreateParamStruct();
	//m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	
	Init();
}
M_DWG_SetCHSwitch::~M_DWG_SetCHSwitch()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_DWG_SetCHSwitch::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DWGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	/*sprintf(m_InputPara1->paramName, "channel");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);*/

	sprintf(m_InputPara2->paramName, "ON/OFF");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_DWG_SetCHSwitch::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	short int channel = 1;
	short int select = 0;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	//channel = atoi(m_InputPara1->paramVal);
	select = atoi(m_InputPara2->paramVal);

	return DWG_SetCHSwitch(vHandle, channel, select);
}

//class M_DWG_SetAllSwitch
M_DWG_SetAllSwitch::M_DWG_SetAllSwitch()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置总开关,参数(0:关闭,1:打开)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}
M_DWG_SetAllSwitch::~M_DWG_SetAllSwitch()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_DWG_SetAllSwitch::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DWGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "ON/OFF");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	
	return NTS_SUCCESS;
}
int M_DWG_SetAllSwitch::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	short int select = 0;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	select = atoi(m_InputPara1->paramVal);

	return DWG_SetAllSwitch(vHandle, select);
}

//class M_DWG_SetAmpLevel
M_DWG_SetAmpLevel::M_DWG_SetAmpLevel()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置总开关,参数(0:关闭,1:打开)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}
M_DWG_SetAmpLevel::~M_DWG_SetAmpLevel()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_DWG_SetAmpLevel::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DWGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "ON/OFF");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	
	return NTS_SUCCESS;
}
int M_DWG_SetAmpLevel::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	double level;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	level = atoi(m_InputPara1->paramVal);

	return DWG_SetAmpLevel(vHandle, level);
}