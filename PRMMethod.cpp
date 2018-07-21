#include "stdafx.h"
#include "PRMMethod.h"
#include <assert.h>
#include "stdio.h"
#include <map>
#include "math.h"

extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//class M_PRM_Reset
M_PRM_Reset::M_PRM_Reset()
:BaseMethod()
{
	sprintf(m_MethodScript, "复位");	
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PRM_Reset::~M_PRM_Reset()
{
//	free(m_InputDeviceName);
}
int M_PRM_Reset::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PRMDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	return NTS_SUCCESS;
}
int M_PRM_Reset::Run(void)
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

	return PRM_Reset(vHandle);
}

//class M_PRM_Calculate
M_PRM_Calculate::M_PRM_Calculate()
:BaseMethod()
{
	sprintf(m_MethodScript, "校准");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_PRM_Calculate::~M_PRM_Calculate()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_PRM_Calculate::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PRMDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "freq");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"2017.4");
	sprintf(m_InputPara->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PRM_Calculate::Run(void)
{
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

	freq = atof(m_InputPara->paramVal);
	return PRM_Calculate(vHandle,freq);
}

//class M_PRM_SetMeasPos
M_PRM_SetMeasPos::M_PRM_SetMeasPos()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置测量位置(0:Load 1:SOURce)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_PRM_SetMeasPos::~M_PRM_SetMeasPos()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_PRM_SetMeasPos::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PRMDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "port");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "mode");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_PRM_SetMeasPos::Run(void)
{
	short port, mode ;
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

	port = atoi(m_InputPara1->paramVal);
	mode = atoi(m_InputPara2->paramVal);
	return PRM_SetMeasPos(vHandle,port, mode);
}

//class M_PRM_SetOffset
M_PRM_SetOffset::M_PRM_SetOffset()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置插损(0~100 dB)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_PRM_SetOffset::~M_PRM_SetOffset()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_PRM_SetOffset::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PRMDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "port");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "offset");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "dB");
	m_InputParamVector.push_back(m_InputPara2);

	return NTS_SUCCESS;
}
int M_PRM_SetOffset::Run(void)
{
	short port;
	float offset;
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

	port = atoi(m_InputPara1->paramVal);
	offset = atof(m_InputPara2->paramVal);
	return PRM_SetOffset(vHandle,port, offset);	

}

//class M_PRM_GetPower
M_PRM_GetPower::M_PRM_GetPower()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取测试测量值");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	Init();
}
M_PRM_GetPower::~M_PRM_GetPower()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);
//	free(m_OutputPara2);
}
int M_PRM_GetPower::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PRMDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_OutputPara1->paramName, "Power");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"0");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);

	sprintf(m_OutputPara2->paramName, "SWR");
	m_OutputPara2->paramType = NTSReal32;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"1");
	sprintf(m_OutputPara2->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara2);
	
	return NTS_SUCCESS;
}
int M_PRM_GetPower::Run(void)
{
	int res;
	float pwr, swr;
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

	res = PRM_GetPower(vHandle, &pwr, &swr);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", pwr);
		sprintf(m_OutputPara2->paramVal, "%e", swr);
	}
	return res; 
}

//class M_PRM_SetMeasMode
M_PRM_SetMeasMode::M_PRM_SetMeasMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置测量模式(0:平均功率 1:峰值功率 2:脉冲功率 )");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_PRM_SetMeasMode::~M_PRM_SetMeasMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_PRM_SetMeasMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PRMDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "mode");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);

	return NTS_SUCCESS;
}

int M_PRM_SetMeasMode::Run(void)
{
	short mode ;
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

	mode = atoi(m_InputPara->paramVal);
	return PRM_SetMeasMode(vHandle, mode);
}

//class M_PRM_SetMeasUnit
M_PRM_SetMeasUnit::M_PRM_SetMeasUnit()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置测量单位(0:W, 1:DB, 2:PCT, 3:dbm)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}

M_PRM_SetMeasUnit::~M_PRM_SetMeasUnit()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PRM_SetMeasUnit::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PRMDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "Unit");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	return NTS_SUCCESS;
}

int M_PRM_SetMeasUnit::Run(void)
{
	short Unit;
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

	Unit = atoi(m_InputPara->paramVal);
	return PRM_SetMeasUnit(vHandle, Unit);
}

//class M_PRM_SendCmd 
M_PRM_SendCmd::M_PRM_SendCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_PRM_SendCmd::~M_PRM_SendCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_PRM_SendCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PRMDevice;
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
int M_PRM_SendCmd::Run(void)
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
	return PRM_SendCmd(vHandle, CmdStr);
}
//class M_PRM_GetCmd 获取返回指令值
M_PRM_GetCmd::M_PRM_GetCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令并获取指令的返回数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_PRM_GetCmd::~M_PRM_GetCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara1);
}

int M_PRM_GetCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PRMDevice;
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
int M_PRM_GetCmd::Run(void)
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
	sprintf(CmdStr, "%s", m_InputPara1->paramVal);
	res = PRM_GetCmd(vHandle, CmdStr, RetStr);
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

//class M_PRM_GetIDN 
M_PRM_GetIDN::M_PRM_GetIDN()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取设备型号信息");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_PRM_GetIDN::~M_PRM_GetIDN()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);
}

int M_PRM_GetIDN::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PRMDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "IDN");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_PRM_GetIDN::Run(void)
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

	res = PRM_GetIDN(vHandle, IDN);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%s", IDN);
	}
	return res;
}