
#include "stdafx.h"
#include "VSA89600.H"
#include <assert.h>
#include "stdio.h"
#include <map>

extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

/************************************************************************/
/*  VSA89600驱动程序方法类                                            */
/************************************************************************/

// class M_PSA_VSAOpen
M_PSA_VSAOpen::M_PSA_VSAOpen()
:BaseMethod()
{
	sprintf(m_MethodScript, "加载VSA配置文件(Visible 0:不可见 1:可见)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	
	Init();
}
M_PSA_VSAOpen::~M_PSA_VSAOpen()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_VSAOpen::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit = " ";
	m_InputParamVector.push_back(m_InputDeviceName);


	sprintf(m_InputPara1->paramName, "ConfigFileName");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	m_InputPara1->paramUnit = " ";
	m_InputParamVector.push_back(m_InputPara1);

	
	sprintf(m_InputPara2->paramName, "Visable");
	m_InputPara2->paramType = NTSInt32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	m_InputPara2->paramUnit = " ";
	m_InputParamVector.push_back(m_InputPara2);
	
	
	return NTS_SUCCESS;
}
int M_PSA_VSAOpen::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char vFileName[1000];
	int vVisable;
		
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);

/*
		if(it == gDeviceManagerMap.end())
		{
			return NTS_INVALID_DEVICE;
		}
		vHandle = it->second.DevHandle;
*/
	sprintf(vFileName, m_InputPara1->paramVal);
	vVisable = atoi(m_InputPara2->paramVal);
	res = PSA_VSAOpen(vHandle, vFileName, vVisable);
	return res;
}

// class M_PSA_VSAClose
M_PSA_VSAClose::M_PSA_VSAClose()
:BaseMethod()
{
	sprintf(m_MethodScript, "关闭进程,退出VSA)");
	m_InputDeviceName = CreateParamStruct();
	
	Init();
}
M_PSA_VSAClose::~M_PSA_VSAClose()
{
//	free(m_InputDeviceName);

}

int M_PSA_VSAClose::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit = " ";
	m_InputParamVector.push_back(m_InputDeviceName);

	return NTS_SUCCESS;
}
int M_PSA_VSAClose::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
/*
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
*/

	res = PSA_VSAClose(vHandle);
	return res;
}

// class M_PSA_VSARunAndSaveData
M_PSA_VSARunAndSaveData::M_PSA_VSARunAndSaveData()
:BaseMethod()
{
	sprintf(m_MethodScript, "启动VSA测量,并保存测试结果到文件");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	
	Init();
}
M_PSA_VSARunAndSaveData::~M_PSA_VSARunAndSaveData()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_VSARunAndSaveData::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit = " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Channel");
	m_InputPara1->paramType = NTSInt32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	m_InputPara1->paramUnit = " ";
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "RecordFileName");
	m_InputPara2->paramType = NTSString;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	m_InputPara2->paramUnit = " ";
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_PSA_VSARunAndSaveData::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char vFileName[200];
	int vChannel;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
/*
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
*/
	vChannel = atoi(m_InputPara1->paramVal);
	sprintf(vFileName, m_InputPara2->paramVal);
	res = PSA_VSARunAndSaveData(vHandle, vChannel, vFileName);
	return res;
}

// class M_PSA_VSASetCenterFreq
M_PSA_VSASetCenterFreq::M_PSA_VSASetCenterFreq()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置中心频率(MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	
	Init();
}
M_PSA_VSASetCenterFreq::~M_PSA_VSASetCenterFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
	
}

int M_PSA_VSASetCenterFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit = " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	
	sprintf(m_InputPara1->paramName, "CenterFreq");
	m_InputPara1->paramType = NTSReal64;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1785");
	m_InputPara1->paramUnit = "MHz";
	m_InputParamVector.push_back(m_InputPara1);
		
	return NTS_SUCCESS;
}
int M_PSA_VSASetCenterFreq::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	double Freq;

	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	/*
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	*/
	Freq = atof(m_InputPara1->paramVal);
	res = PSA_VSASetCenterFreq(vHandle, Freq);
	return res;
}

// class M_PSA_VSASetStartandStopFreq
M_PSA_VSASetStartandStopFreq::M_PSA_VSASetStartandStopFreq()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置起止频率(MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	
	Init();
}
M_PSA_VSASetStartandStopFreq::~M_PSA_VSASetStartandStopFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_VSASetStartandStopFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit = " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	
	sprintf(m_InputPara1->paramName, "StartFreq");
	m_InputPara1->paramType = NTSReal64;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1780");
	sprintf(m_InputPara1->paramUnit,"MHz");
	m_InputParamVector.push_back(m_InputPara1);
	
	
	sprintf(m_InputPara2->paramName, "StopFreq");
	m_InputPara2->paramType = NTSReal64;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1785");
	sprintf(m_InputPara2->paramUnit,"MHz");
	m_InputParamVector.push_back(m_InputPara2);
	
	
	return NTS_SUCCESS;
}
int M_PSA_VSASetStartandStopFreq::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	double StartFreq, StopFreq;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	/*
	if(it == gDeviceManagerMap.end())
		{
			return NTS_INVALID_DEVICE;
		}
		vHandle = it->second.DevHandle;
	*/
	StartFreq = atof(m_InputPara1->paramVal);
	StopFreq = atof(m_InputPara2->paramVal);
	res = PSA_VSASetStartandStopFreq(vHandle, StartFreq, StopFreq);
	return res;
}

// class M_PSA_VSASetSpan
M_PSA_VSASetSpan::M_PSA_VSASetSpan()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置SPAN(MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	
	Init();
}
M_PSA_VSASetSpan::~M_PSA_VSASetSpan()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
	
}

int M_PSA_VSASetSpan::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit = " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	
	sprintf(m_InputPara1->paramName, "Span");
	m_InputPara1->paramType = NTSReal64;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"10");
	sprintf(m_InputPara1->paramUnit, "MHz");
	m_InputParamVector.push_back(m_InputPara1);
	
		
	return NTS_SUCCESS;
}
int M_PSA_VSASetSpan::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	double Span;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
/*
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
*/
	Span = atof(m_InputPara1->paramVal);
	res = PSA_VSASetSpan(vHandle, Span);
	return res;
}

// class M_PSA_VSASetRBW
M_PSA_VSASetRBW::M_PSA_VSASetRBW()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置RBW(MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	
	Init();
}
M_PSA_VSASetRBW::~M_PSA_VSASetRBW()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_PSA_VSASetRBW::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit = " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	
	sprintf(m_InputPara1->paramName, "RBW");
	m_InputPara1->paramType = NTSReal64;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0.03");
	sprintf(m_InputPara1->paramUnit, "MHz");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_VSASetRBW::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	double RBW;

	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
/*
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
*/
	RBW = atof(m_InputPara1->paramVal);
	res = PSA_VSASetRBW(vHandle, RBW);
	return res;
}

// class M_PSA_VSASetSweepTime
M_PSA_VSASetSweepTime::M_PSA_VSASetSweepTime()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置扫描时间(mS)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	
	Init();
}
M_PSA_VSASetSweepTime::~M_PSA_VSASetSweepTime()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_PSA_VSASetSweepTime::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit = " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	
	sprintf(m_InputPara1->paramName, "SweepTime");
	m_InputPara1->paramType = NTSReal64;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit, "ms");
	m_InputParamVector.push_back(m_InputPara1);

	
	return NTS_SUCCESS;
}
int M_PSA_VSASetSweepTime::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	double SweepTime;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
/*
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
*/
	SweepTime = atof(m_InputPara1->paramVal);
	res = PSA_VSASetSweepTime(vHandle, SweepTime);
	return res;
}

// class M_PSA_VSASetRefLevel
M_PSA_VSASetRefLevel::M_PSA_VSASetRefLevel()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置参考电平(dB)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	
	Init();
}
M_PSA_VSASetRefLevel::~M_PSA_VSASetRefLevel()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_VSASetRefLevel::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit = " ";
	m_InputParamVector.push_back(m_InputDeviceName);
		
	sprintf(m_InputPara1->paramName, "Channel");
	m_InputPara1->paramType = NTSInt32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "RefLevel");
	m_InputPara2->paramType = NTSReal64;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit, "dB");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_PSA_VSASetRefLevel::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int Channel;
	double RefLevel;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
/*
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
*/
	Channel = atoi(m_InputPara1->paramVal);
	RefLevel = atof(m_InputPara2->paramVal);
	res = PSA_VSASetRefLevel(vHandle, Channel, RefLevel);
	return res;
}

// class M_PSA_VSASetActiveChannel
M_PSA_VSASetActiveChannel::M_PSA_VSASetActiveChannel()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置当前激活通道");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
		
	Init();
}
M_PSA_VSASetActiveChannel::~M_PSA_VSASetActiveChannel()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
}

int M_PSA_VSASetActiveChannel::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit = " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	
	sprintf(m_InputPara1->paramName, "Channel");
	m_InputPara1->paramType = NTSInt32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_VSASetActiveChannel::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int Channel;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
/*
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
*/
	Channel = atoi(m_InputPara1->paramVal);
	res = PSA_VSASetActiveChannel(vHandle, Channel);
	return res;
}

// class M_PSA_VSASetTrigSource
M_PSA_VSASetTrigSource::M_PSA_VSASetTrigSource()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置触发源(0:Freerun 1:External 2:External TTL  3:Channel 4:IF Mag)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
		
	Init();
}
M_PSA_VSASetTrigSource::~M_PSA_VSASetTrigSource()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
}

int M_PSA_VSASetTrigSource::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit = " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	
	sprintf(m_InputPara1->paramName, "TrigSource");
	m_InputPara1->paramType = NTSInt32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_VSASetTrigSource::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int TrigSource;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
/*
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
*/
	TrigSource = atoi(m_InputPara1->paramVal);
	res = PSA_VSASetTrigSource(vHandle, TrigSource);
	return res;
}

//class M_PSA_VSASetTrigDelayTime 
M_PSA_VSASetTrigDelayTime::M_PSA_VSASetTrigDelayTime()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置触发延迟时间(单位:ms)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
		
	Init();
}
M_PSA_VSASetTrigDelayTime::~M_PSA_VSASetTrigDelayTime()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
}

int M_PSA_VSASetTrigDelayTime::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	m_InputDeviceName->paramUnit = " ";
	m_InputParamVector.push_back(m_InputDeviceName);
	
	
	sprintf(m_InputPara1->paramName, "DelayTime");
	m_InputPara1->paramType = NTSReal64;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_VSASetTrigDelayTime::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	double DelayTime;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
/*
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
*/
	DelayTime = atof(m_InputPara1->paramVal);
	res = PSA_VSASetTrigDelayTime(vHandle, DelayTime);
	return res;
}

