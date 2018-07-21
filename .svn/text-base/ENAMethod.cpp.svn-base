
#include "stdafx.h"
#include "ENAMethod.h"
#include <assert.h>
#include "stdio.h"
#include <map>

extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

//矢量网络分析驱动方法类
//class M_ENA_Reset
M_ENA_Reset::M_ENA_Reset()
:BaseMethod()
{
	sprintf(m_MethodScript, "设备复位");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_ENA_Reset::~M_ENA_Reset()
{
//	free(m_InputDeviceName);
}
int M_ENA_Reset::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_ENA_Reset::Run(void)
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
	
	return ENA_Reset(vHandle);
}
//class M_ENA_LoadFile
M_ENA_LoadFile::M_ENA_LoadFile()
:BaseMethod()
{
	sprintf(m_MethodScript, "加载矢网状态文件");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_ENA_LoadFile::~M_ENA_LoadFile()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_ENA_LoadFile::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "filename");
	m_InputPara->paramType = NTSString;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_ENA_LoadFile::Run(void)
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
	return ENA_LoadFile(vHandle,filename);
}
//class M_ENA_SetChannelTrace
M_ENA_SetChannelTrace::M_ENA_SetChannelTrace()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置矢网指定通道(1~4)和曲线(1~4)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_ENA_SetChannelTrace::~M_ENA_SetChannelTrace()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_ENA_SetChannelTrace::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "traceindex");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_ENA_SetChannelTrace::Run(void)
{
	unsigned short chindex;
	int traceindex;
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
	
	chindex = atoi(m_InputPara1->paramVal);
	traceindex = atoi(m_InputPara2->paramVal);	
	return ENA_SetChannelTrace(vHandle,chindex,traceindex);
}
//class M_ENA_GetMarkerMin
M_ENA_GetMarkerMin::M_ENA_GetMarkerMin()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取矢网指定通道(1~4)的最小Marker点(1~10)值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_ENA_GetMarkerMin::~M_ENA_GetMarkerMin()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}
int M_ENA_GetMarkerMin::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "markerindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_OutputPara->paramName, "value");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_ENA_GetMarkerMin::Run(void)
{
	unsigned short chindex,markerindex;
	double data;
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

	chindex = atoi(m_InputPara1->paramVal);
	markerindex = atoi(m_InputPara2->paramVal);	
	retVal = ENA_GetMarkerMin(vHandle,chindex,markerindex,&data);
	if(retVal==NTS_SUCCESS)
	{
		if(data>0.0001)
		{
			sprintf(m_OutputPara->paramVal,"%e",data);
		}
		else
		{
			sprintf(m_OutputPara->paramVal,"%e",data);
		}
	}
	return retVal;
}
//class M_ENA_GetMarkerMax
M_ENA_GetMarkerMax::M_ENA_GetMarkerMax()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取矢网指定通道(1~4)的最大Marker点值(1~10)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_ENA_GetMarkerMax::~M_ENA_GetMarkerMax()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}
int M_ENA_GetMarkerMax::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "markerindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara->paramName, "value");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_ENA_GetMarkerMax::Run(void)
{
	unsigned short chindex,markerindex;
	double data;
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

	chindex = atoi(m_InputPara1->paramVal);
	markerindex = atoi(m_InputPara2->paramVal);	
	retVal = ENA_GetMarkerMax(vHandle,chindex,markerindex,&data);
	if(retVal==NTS_SUCCESS)
	{
		if(data>0.0001)
		{
			sprintf(m_OutputPara->paramVal,"%e",data);
		}
		else
		{
			sprintf(m_OutputPara->paramVal,"%e",data);
		}
	}
	return retVal;
}
//class M_ENA_GetMarkerFreq
M_ENA_GetMarkerFreq::M_ENA_GetMarkerFreq()
:BaseMethod()
{
	sprintf(m_MethodScript, "获得矢网指定通道(1~4)和频点的marker(1~10)点值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_ENA_GetMarkerFreq::~M_ENA_GetMarkerFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
//	free(m_OutputPara);
}
int M_ENA_GetMarkerFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);	

	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "markerindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "freq");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"2017.4");
	sprintf(m_InputPara3->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara3);

	sprintf(m_OutputPara->paramName, "value");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_ENA_GetMarkerFreq::Run(void)
{
	unsigned short chindex,markerindex;
	float freq;
	double data;
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
	
	chindex = atoi(m_InputPara1->paramVal);
	markerindex = atoi(m_InputPara2->paramVal);	
	freq = atof(m_InputPara3->paramVal);

	retVal = ENA_GetMarkerFreq(vHandle,chindex,markerindex,freq,&data);
	if(retVal==NTS_SUCCESS)
	{
		if(data>0.0001)
		{
			sprintf(m_OutputPara->paramVal,"%e",data);
		}
		else
		{
			sprintf(m_OutputPara->paramVal,"%e",data);
		}
	}
	return retVal;
}
//class M_ENA_SetAverageState
M_ENA_SetAverageState::M_ENA_SetAverageState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置矢网指定通道(1~4)的平均状态(0:off 1:on)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_ENA_SetAverageState::~M_ENA_SetAverageState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_ENA_SetAverageState::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "state");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_ENA_SetAverageState::Run(void)
{
	unsigned short chindex,state;
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

	chindex = atoi(m_InputPara1->paramVal);
	state = atoi(m_InputPara2->paramVal);	
	return ENA_SetAverageState(vHandle,chindex,state);
}
//M_ENA_SetScaleAuto
M_ENA_SetScaleAuto::M_ENA_SetScaleAuto()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置矢网指定通道(1~4)和曲线(1~4)为AutoScale模式");
	m_InputDeviceName  = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_ENA_SetScaleAuto::~M_ENA_SetScaleAuto()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_ENA_SetScaleAuto::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "traceindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_ENA_SetScaleAuto::Run(void)
{
	unsigned short chindex,traceindex;
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
	
	chindex = atoi(m_InputPara1->paramVal);
	traceindex = atoi(m_InputPara2->paramVal);	
	return ENA_SetScaleAuto(vHandle,chindex,traceindex);
}
//M_ENA_SetMarkerStartandStopFreq
M_ENA_SetMarkerStartandStopFreq::M_ENA_SetMarkerStartandStopFreq()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置矢网Marker Search 频率范围(单位:MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();
	m_InputPara[3] = CreateParamStruct();
	m_InputPara[4] = CreateParamStruct();
	
	Init();
}
M_ENA_SetMarkerStartandStopFreq::~M_ENA_SetMarkerStartandStopFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara[0]);
//	free(m_InputPara[1]);
//	free(m_InputPara[2]);
//	free(m_InputPara[3]);
//	free(m_InputPara[4]);

}
int M_ENA_SetMarkerStartandStopFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "chindex");
	m_InputPara[0]->paramType = NTSUInt8;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"1");
	sprintf(m_InputPara[0]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[0]);
	
	sprintf(m_InputPara[1]->paramName, "traceindex");
	m_InputPara[1]->paramType = NTSUInt8;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"1");
	sprintf(m_InputPara[1]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[1]);

	sprintf(m_InputPara[2]->paramName, "markerindex");
	m_InputPara[2]->paramType = NTSUInt8;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"1");
	sprintf(m_InputPara[2]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[2]);

	sprintf(m_InputPara[3]->paramName, "start");
	m_InputPara[3]->paramType = NTSReal32;
	m_InputPara[3]->paramCount = 1;
	sprintf(m_InputPara[3]->paramVal,"");
	sprintf(m_InputPara[3]->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara[3]);

	sprintf(m_InputPara[4]->paramName, "stop");
	m_InputPara[4]->paramType = NTSReal32;
	m_InputPara[4]->paramCount = 1;
	sprintf(m_InputPara[4]->paramVal,"");
	sprintf(m_InputPara[4]->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara[4]);
	return NTS_SUCCESS;
}
int M_ENA_SetMarkerStartandStopFreq::Run(void)
{
	unsigned short chindex,traceindex,markerindex;
	float startfreq,stopfreq;
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
	
	chindex = atoi(m_InputPara[0]->paramVal);
	traceindex = atoi(m_InputPara[1]->paramVal);	
	markerindex = atoi(m_InputPara[2]->paramVal);
	startfreq = atof(m_InputPara[3]->paramVal);
	stopfreq = atof(m_InputPara[4]->paramVal);

	return ENA_SetMarkerStartandStopFreq(vHandle,chindex,traceindex,markerindex,startfreq,stopfreq);
}
//M_ENA_SaveDataToMemory
M_ENA_SaveDataToMemory::M_ENA_SaveDataToMemory()
:BaseMethod()
{
	sprintf(m_MethodScript, "保存矢网指定通道(1~4)和曲线(1~4)的数据到内存中");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_ENA_SaveDataToMemory::~M_ENA_SaveDataToMemory()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_ENA_SaveDataToMemory::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "traceindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_ENA_SaveDataToMemory::Run(void)
{
	unsigned short chindex,traceindex;
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
	
	chindex = atoi(m_InputPara1->paramVal);
	traceindex = atoi(m_InputPara2->paramVal);	
	return ENA_SaveDataToMemory(vHandle,chindex,traceindex);
}
//M_ENA_SetTraceMathType
M_ENA_SetTraceMathType::M_ENA_SetTraceMathType()
:BaseMethod()
{
	sprintf(m_MethodScript, "保存矢网数据的处理方式 (0:Off 1:Data/Mem 2:Data*Mem 3:Data-Mem 4:Data+Mem)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}
M_ENA_SetTraceMathType::~M_ENA_SetTraceMathType()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}
int M_ENA_SetTraceMathType::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "traceindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "type");
	m_InputPara3->paramType = NTSInt8;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"0");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_ENA_SetTraceMathType::Run(void)
{
	unsigned short chindex,traceindex;
	short type;
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
	
	chindex = atoi(m_InputPara1->paramVal);
	traceindex = atoi(m_InputPara2->paramVal);	
	type = atoi(m_InputPara3->paramVal);	
	
	return ENA_SetTraceMathType(vHandle,chindex,traceindex,type);
}

//class M_ENA_SetTraceFormat

M_ENA_SetTraceFormat::M_ENA_SetTraceFormat()
:BaseMethod()
{

	sprintf(m_MethodScript, "设置矢网通道曲线形式 (0:logarithmic magnitude 1:phase 2:group delay 3:smith chart(Lin/phase)");
	sprintf(m_MethodScript,"%s%s",m_MethodScript," 4:smith chart(Log/phase) 5:smith chart(Real/Imag) 6:smith chart(R+jX) 7:smith chart(G+jB)");
	sprintf(m_MethodScript,"%s%s",m_MethodScript," 8:polar(Lin) 9:polar(Log) 10:polar(Re/Im) 11:linear magnitude 12:SWR");
	sprintf(m_MethodScript,"%s%s",m_MethodScript," 13:real 14:imaginary 15:expanded phase 16:positive phase)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}
M_ENA_SetTraceFormat::~M_ENA_SetTraceFormat()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}
int M_ENA_SetTraceFormat::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "traceindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "format");
	m_InputPara3->paramType = NTSInt8;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"0");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);

	return NTS_SUCCESS;
}
int M_ENA_SetTraceFormat::Run(void)
{
	unsigned short chindex,traceindex;
	short type;
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

	chindex = atoi(m_InputPara1->paramVal);
	traceindex = atoi(m_InputPara2->paramVal);	
	type = atoi(m_InputPara3->paramVal);	
	
	return ENA_SetTraceFormat(vHandle,chindex,traceindex,type);
//	return NTS_SUCCESS;
}


//class M_ENA_SetDisplayTrace

M_ENA_SetDisplayTrace::M_ENA_SetDisplayTrace()
:BaseMethod()
{
	
	sprintf(m_MethodScript, "设置矢网通道数据显示方式 (0:Data 1:Mem 2:Data&Mem 3:OFF)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}
M_ENA_SetDisplayTrace::~M_ENA_SetDisplayTrace()
{
///	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}
int M_ENA_SetDisplayTrace::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);


	sprintf(m_InputPara2->paramName, "traceindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "type");
	m_InputPara3->paramType = NTSInt8;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"0");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	
	return NTS_SUCCESS;
}
int M_ENA_SetDisplayTrace::Run(void)
{
	unsigned short chindex,traceindex;
	short type;
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
	
	chindex = atoi(m_InputPara1->paramVal);
	traceindex = atoi(m_InputPara2->paramVal);	
	type = atoi(m_InputPara3->paramVal);	
	
	return ENA_SetDisplayTrace(vHandle,chindex, traceindex,type);

}


//class M_ENA_GetSearchOutputPowerPosition

M_ENA_GetSearchOutputPowerPosition::M_ENA_GetSearchOutputPowerPosition()
:BaseMethod()
{
	
	sprintf(m_MethodScript, "获取功率范围内数据点的X和Y坐标值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	m_InputPara4 = CreateParamStruct();
	m_InputPara5 = CreateParamStruct();
	m_InputPara6 = CreateParamStruct();
	m_InputPara7 = CreateParamStruct();
	m_InputPara8 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	
	Init();
}
M_ENA_GetSearchOutputPowerPosition::~M_ENA_GetSearchOutputPowerPosition()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
//	free(m_InputPara4);
//	free(m_InputPara5);
//	free(m_InputPara6);
//	free(m_InputPara7);
//	free(m_InputPara8);
//	free(m_OutputPara1);
//	free(m_OutputPara2);
	
}
int M_ENA_GetSearchOutputPowerPosition::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
		
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "traceindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	
	sprintf(m_InputPara3->paramName, "MarkerIndex");
	m_InputPara3->paramType = NTSUInt8;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"1");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	
	sprintf(m_InputPara4->paramName, "StartValue");
	m_InputPara4->paramType = NTSReal32;
	m_InputPara4->paramCount = 1;
	sprintf(m_InputPara4->paramVal,"0");
	sprintf(m_InputPara4->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara4);

	sprintf(m_InputPara5->paramName, "StopValue");
	m_InputPara5->paramType = NTSReal32;
	m_InputPara5->paramCount = 1;
	sprintf(m_InputPara5->paramVal,"1");
	sprintf(m_InputPara5->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara5);
	
	sprintf(m_InputPara6->paramName, "SearchStep");
	m_InputPara6->paramType = NTSReal32;
	m_InputPara6->paramCount = 1;
	sprintf(m_InputPara6->paramVal,"0.1");
	sprintf(m_InputPara6->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara6);
	
	
	m_InputPara7->paramName, "TargetOutputPower";
	m_InputPara7->paramType = NTSReal32;
	m_InputPara7->paramCount = 1;
	sprintf(m_InputPara7->paramVal,"1");
	m_InputPara7->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara7);
	
	m_InputPara8->paramName, "Tolerance";
	m_InputPara8->paramType = NTSReal32;
	m_InputPara8->paramCount = 1;
	sprintf(m_InputPara8->paramVal,"0.1");
	m_InputPara8->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara8);

	m_OutputPara1->paramName, "XValue";
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	m_OutputPara1->paramUnit , "";
	m_OutputParamVector.push_back(m_OutputPara1);

	m_OutputPara2->paramName, "YValue";
	m_OutputPara2->paramType = NTSReal32;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	m_OutputPara2->paramUnit , "";
	m_OutputParamVector.push_back(m_OutputPara2);
	
	return NTS_SUCCESS;
}
int M_ENA_GetSearchOutputPowerPosition::Run(void)
{
	unsigned short chindex,traceindex,MarkerIndex;
	double StartValue,StopValue,SearchStep,TargetOutputPower,Tolerance,XValue,YValue;
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
	
	chindex = atoi(m_InputPara1->paramVal);
	traceindex = atoi(m_InputPara2->paramVal);	
	MarkerIndex = atoi(m_InputPara3->paramVal);	
	StartValue = atof(m_InputPara4->paramVal);
	StopValue = atof(m_InputPara5->paramVal);
	SearchStep = atof(m_InputPara6->paramVal);
	TargetOutputPower = atof(m_InputPara7->paramVal);
	Tolerance = atof(m_InputPara8->paramVal);
	
	
	retVal = ENA_GetSearchOutputPowerPosition(vHandle, chindex,traceindex,MarkerIndex, StartValue, StopValue, 
		SearchStep,TargetOutputPower, Tolerance, &XValue, &YValue);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal,"%e",XValue);
		sprintf(m_OutputPara2->paramVal,"%e",YValue);
	}
	return retVal;
	
}

//M_ENA_GetSearchYDiffPosition
M_ENA_GetSearchYDiffPosition::M_ENA_GetSearchYDiffPosition()
:BaseMethod()
{
	
	sprintf(m_MethodScript, "获取功率偏移量数据点的X和Y坐标值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	m_InputPara4 = CreateParamStruct();
	m_InputPara5 = CreateParamStruct();
	m_InputPara6 = CreateParamStruct();
	m_InputPara7 = CreateParamStruct();
	m_InputPara8 = CreateParamStruct();
	m_InputPara9 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	
	Init();
}
M_ENA_GetSearchYDiffPosition::~M_ENA_GetSearchYDiffPosition()
{
/*	free(m_InputDeviceName);
	free(m_InputPara1);
	free(m_InputPara2);
	free(m_InputPara3);
	free(m_InputPara4);
	free(m_InputPara5);
	free(m_InputPara6);
	free(m_InputPara7);
	free(m_InputPara8);
	free(m_InputPara9);
	free(m_OutputPara1);
	free(m_OutputPara2);*/
	
}
int M_ENA_GetSearchYDiffPosition::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "traceindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "MarkerOriginal");
	m_InputPara3->paramType = NTSUInt8;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"1");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	
	sprintf(m_InputPara4->paramName, "MarkerIndex");
	m_InputPara4->paramType = NTSUInt8;
	m_InputPara4->paramCount = 1;
	sprintf(m_InputPara4->paramVal,"1");
	sprintf(m_InputPara4->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara4);
	
	sprintf(m_InputPara5->paramName, "StartValue");
	m_InputPara5->paramType = NTSReal32;
	m_InputPara5->paramCount = 1;
	sprintf(m_InputPara5->paramVal,"0");
	sprintf(m_InputPara5->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara5);

	sprintf(m_InputPara6->paramName, "StopValue");
	m_InputPara6->paramType = NTSReal32;
	m_InputPara6->paramCount = 1;
	sprintf(m_InputPara6->paramVal,"1");
	sprintf(m_InputPara6->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara6);
	
	sprintf(m_InputPara7->paramName, "SearchStep");
	m_InputPara7->paramType = NTSReal32;
	m_InputPara7->paramCount = 1;
	sprintf(m_InputPara7->paramVal,"0.1");
	sprintf(m_InputPara7->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara7);
	
	
	sprintf(m_InputPara8->paramName, "Diff");
	m_InputPara8->paramType = NTSReal32;
	m_InputPara8->paramCount = 1;
	sprintf(m_InputPara8->paramVal,"1");
	sprintf(m_InputPara8->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara8);
	
	sprintf(m_InputPara9->paramName, "Tolerance");
	m_InputPara9->paramType = NTSReal32;
	m_InputPara9->paramCount = 1;
	sprintf(m_InputPara9->paramVal,"0.1");
	sprintf(m_InputPara9->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara9);

	sprintf(m_OutputPara1->paramName, "XValue");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);

	sprintf(m_OutputPara2->paramName, "YValue");
	m_OutputPara2->paramType = NTSReal32;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara2);
	
	return NTS_SUCCESS;
}
int M_ENA_GetSearchYDiffPosition::Run(void)
{
	unsigned short chindex,traceindex,MarkerOriginal,MarkerIndex;
	double StartValue,StopValue,SearchStep,Diff,Tolerance,XValue,YValue;
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
	
	chindex        =  atoi(m_InputPara1->paramVal);
	traceindex     =  atoi(m_InputPara2->paramVal);	
	MarkerOriginal =  atoi(m_InputPara3->paramVal);	
	MarkerIndex    =  atoi(m_InputPara4->paramVal);	
	StartValue     =  atof(m_InputPara5->paramVal);
	StopValue      =  atof(m_InputPara6->paramVal);
	SearchStep     =  atof(m_InputPara7->paramVal);
	Diff           =  atof(m_InputPara8->paramVal);
	Tolerance      =  atof(m_InputPara9->paramVal);
	
	retVal = ENA_GetSearchYDiffPosition(vHandle, chindex,traceindex,MarkerOriginal,MarkerIndex, StartValue, StopValue, 
		SearchStep,Diff, Tolerance, &XValue, &YValue);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal,"%e",XValue);
		sprintf(m_OutputPara2->paramVal,"%e",YValue);
	}
	return retVal;
	
}
//class M_ENA_GetMarkerValue
M_ENA_GetMarkerValue::M_ENA_GetMarkerValue()
:BaseMethod()
{
	
	sprintf(m_MethodScript, "获取指定Marker点的值");
	m_InputDeviceName =  CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	
	m_OutputPara = CreateParamStruct();
		
	Init();
}
M_ENA_GetMarkerValue::~M_ENA_GetMarkerValue()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
	
//	free(m_OutputPara);
	
	
}
int M_ENA_GetMarkerValue::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "markerindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara->paramName, "Value");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_ENA_GetMarkerValue::Run(void)
{
	unsigned short chindex,markerindex;
	double Value;
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

	chindex =  atoi(m_InputPara1->paramVal);
	markerindex =  atoi(m_InputPara2->paramVal);	
	
	retVal = ENA_GetMarkerValue(vHandle, chindex,markerindex,&Value);
	if(retVal==NTS_SUCCESS)
	{
		if(Value>0.0001)
		{
			sprintf(m_OutputPara->paramVal,"%e",Value);
		}
		else
		{
			sprintf(m_OutputPara->paramVal,"%e",Value);
		}
	}
	return retVal;
	
}

//M_ENA_SetRFOutputState
M_ENA_SetRFOutputState::M_ENA_SetRFOutputState()
:BaseMethod()
{
	
	sprintf(m_MethodScript, "设置RF输出端口的状态(0:OFF 1:ON)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
		
	Init();
}
M_ENA_SetRFOutputState::~M_ENA_SetRFOutputState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);		
}
int M_ENA_SetRFOutputState::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "State");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
		
	return NTS_SUCCESS;
}
int M_ENA_SetRFOutputState::Run(void)
{
	short state;
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
	
	state =  atoi(m_InputPara1->paramVal);
	
	retVal = ENA_SetRFOutputState(vHandle, state);	
	return retVal;	
}

//M_ENA_SetRFOutPower
M_ENA_SetRFOutPower::M_ENA_SetRFOutPower()
:BaseMethod()
{
	
	sprintf(m_MethodScript, "设置RF输出端口的功率值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();	
	Init();
}
M_ENA_SetRFOutPower::~M_ENA_SetRFOutPower()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_InputPara2);
}
int M_ENA_SetRFOutPower::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "ChIndex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "OutPower");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_ENA_SetRFOutPower::Run(void)
{
	unsigned short ch;
	float power;
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
	
	ch =  atoi(m_InputPara1->paramVal);
	power = atof(m_InputPara2->paramVal);
	retVal = ENA_SetRFOutPower(vHandle, ch,power);	
	return retVal;	
}

//M_ENA_GetFluctuate
M_ENA_GetFluctuate::M_ENA_GetFluctuate()
:BaseMethod()
{
	
	sprintf(m_MethodScript, "获取指定带宽范围内的平坦度");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();

	m_OutputPara = CreateParamStruct();
	Init();
}
M_ENA_GetFluctuate::~M_ENA_GetFluctuate()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_InputPara2);
//	free(m_InputPara3);
//	free(m_OutputPara);
}
int M_ENA_GetFluctuate::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
		
	sprintf(m_InputPara1->paramName, "ChIndex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "TraceIndex");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "BandWidth");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara3);

	sprintf(m_OutputPara->paramName, "Fluctuate");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"0");
	sprintf(m_OutputPara->paramUnit , "dB");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_ENA_GetFluctuate::Run(void)
{
	unsigned short ch;
	int traceindex;
	double bandwidth, fluctuate;
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
	
	ch =  atoi(m_InputPara1->paramVal);
	traceindex = atoi(m_InputPara2->paramVal);
	bandwidth = atof(m_InputPara3->paramVal);

	retVal = ENA_GetFluctuate(vHandle, ch,traceindex, bandwidth, &fluctuate);
	if (retVal == NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal, "%e", fluctuate);
	}
	return retVal;	
}

//M_ENA_SetStartandStopFreq
M_ENA_SetStartandStopFreq::M_ENA_SetStartandStopFreq()
:BaseMethod()
{
	
	sprintf(m_MethodScript, "设置起止频率");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();	
	
	Init();
}
M_ENA_SetStartandStopFreq::~M_ENA_SetStartandStopFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_InputPara2);
//	free(m_InputPara3);
}
int M_ENA_SetStartandStopFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "ChIndex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "StatrFreq");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"2010");
	sprintf(m_InputPara2->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "StopFreq");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"2025");
	sprintf(m_InputPara3->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara3);
	
	
	return NTS_SUCCESS;
}
int M_ENA_SetStartandStopFreq::Run(void)
{
	unsigned short ch;	
	float startfreq, stopfreq;
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
	
	ch =  atoi(m_InputPara1->paramVal);
	startfreq = atof(m_InputPara2->paramVal);
	stopfreq = atof(m_InputPara3->paramVal);
	
	retVal = ENA_SetStartandStopFreq(vHandle, ch,startfreq, stopfreq);	
	return retVal;	
}

//M_ENA_SaveTraceToMemoryOfPC
M_ENA_SaveTraceToMemoryOfPC::M_ENA_SaveTraceToMemoryOfPC()
:BaseMethod()
{
	sprintf(m_MethodScript, "保存矢网指定通道(1~4)和曲线(1~4)的数据到PC内存中");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_ENA_SaveTraceToMemoryOfPC::~M_ENA_SaveTraceToMemoryOfPC()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_ENA_SaveTraceToMemoryOfPC::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "traceindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_ENA_SaveTraceToMemoryOfPC::Run(void)
{
	unsigned short chindex,traceindex;
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
	
	chindex = atoi(m_InputPara1->paramVal);
	traceindex = atoi(m_InputPara2->paramVal);	
	return ENA_SaveTraceToMemoryOfPC(vHandle,chindex,traceindex);
}

//M_ENA_SetTraceMathTypeOfPC
M_ENA_SetTraceMathTypeOfPC::M_ENA_SetTraceMathTypeOfPC()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置PC内存数据的处理方式(0:Off 1:Data/Mem 2:Data*Mem 3:Data-Mem 4:Data+Mem)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}
M_ENA_SetTraceMathTypeOfPC::~M_ENA_SetTraceMathTypeOfPC()
{
//	free(m_InputDeviceName);
///	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}
int M_ENA_SetTraceMathTypeOfPC::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "traceindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "type");
	m_InputPara3->paramType = NTSInt8;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"0");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_ENA_SetTraceMathTypeOfPC::Run(void)
{
	unsigned short chindex,traceindex;
	short type;
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
	
	chindex = atoi(m_InputPara1->paramVal);
	traceindex = atoi(m_InputPara2->paramVal);	
	type = atoi(m_InputPara3->paramVal);	
	
	return ENA_SetTraceMathTypeOfPC(vHandle,chindex,traceindex,type);
}

//M_ENA_SetMarkerSearchFreqOfPC 
M_ENA_SetMarkerSearchFreqOfPC::M_ENA_SetMarkerSearchFreqOfPC()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置MARKER 在PC内存中指定曲线(1~4)数据上查找范围(单位:MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	
	Init();
}
M_ENA_SetMarkerSearchFreqOfPC::~M_ENA_SetMarkerSearchFreqOfPC()
{
//	free(m_InputDeviceName);	
//	free(m_InputPara1);
//	free(m_InputPara2);	
//	free(m_InputPara3);
}

int M_ENA_SetMarkerSearchFreqOfPC::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TraceIndex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "start");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "stop");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_ENA_SetMarkerSearchFreqOfPC::Run(void)
{
	float startfreq,stopfreq;
	int traceIndex;
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
	
	traceIndex = atoi(m_InputPara1->paramVal);
	startfreq = atof(m_InputPara2->paramVal);
	stopfreq = atof(m_InputPara3->paramVal);
	
	return ENA_SetMarkerSearchFreqOfPC(vHandle,traceIndex, startfreq,stopfreq);
}

//M_ENA_GetMarkerValueOfPC 
M_ENA_GetMarkerValueOfPC::M_ENA_GetMarkerValueOfPC()
:BaseMethod()
{
	sprintf(m_MethodScript, "从PC内存数据获取指定曲线(1~4)的最大值和最小值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();	
	
	Init();
}
M_ENA_GetMarkerValueOfPC::~M_ENA_GetMarkerValueOfPC()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_OutputPara1);
//	free(m_OutputPara2);	
}

int M_ENA_GetMarkerValueOfPC::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TraceIndex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_OutputPara1->paramName, "Max");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	sprintf(m_OutputPara2->paramName, "Min");
	m_OutputPara2->paramType = NTSReal32;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara2);
	return NTS_SUCCESS;
}
int M_ENA_GetMarkerValueOfPC::Run(void)
{
	int res;
	int traceIndex;
	double Max = 0,Min = 0;
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
	
	traceIndex = atoi(m_InputPara1->paramVal);
	res = ENA_GetMarkerValueOfPC(vHandle,traceIndex, &Max, &Min);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", Max);
		sprintf(m_OutputPara2->paramVal, "%e", Min);
	}
	return res;
}

//M_ENA_GetFluctuateOfPC
M_ENA_GetFluctuateOfPC::M_ENA_GetFluctuateOfPC()
:BaseMethod()
{
	
	sprintf(m_MethodScript, "从PC内存数据中获取指定曲线(1~4)带宽范围内的平坦度");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_ENA_GetFluctuateOfPC::~M_ENA_GetFluctuateOfPC()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);	
//	free(m_OutputPara);
}
int M_ENA_GetFluctuateOfPC::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "ChIndex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "BandWidth");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara->paramName, "Fluctuate");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"0");
	sprintf(m_OutputPara->paramUnit , "dB");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_ENA_GetFluctuateOfPC::Run(void)
{
	double bandwidth, fluctuate;
	int traceIndex;
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
	
	traceIndex = atoi(m_InputPara1->paramVal);
	bandwidth = atof(m_InputPara2->paramVal);
	
	retVal = ENA_GetFluctuateOfPC(vHandle, traceIndex,bandwidth, &fluctuate);
	if (retVal == NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal, "%e", fluctuate);
	}
	return retVal;	
}

//M_ENA_SetSmooth
M_ENA_SetSmooth::M_ENA_SetSmooth()
:BaseMethod()
{
	sprintf(m_MethodScript, "开启|关闭曲线平滑(0:OFF 1:ON)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}
M_ENA_SetSmooth::~M_ENA_SetSmooth()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}
int M_ENA_SetSmooth::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "traceindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "State");
	m_InputPara3->paramType = NTSInt8;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"0");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	return NTS_SUCCESS;
}
int M_ENA_SetSmooth::Run(void)
{
	unsigned short chindex,traceindex;
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
	
	chindex = atoi(m_InputPara1->paramVal);
	traceindex = atoi(m_InputPara2->paramVal);	
	state = atoi(m_InputPara3->paramVal);	
	
	return ENA_SetSmooth(vHandle,chindex,traceindex,state);
}

//M_ENA_SaveFile 
M_ENA_SaveFile::M_ENA_SaveFile()
:BaseMethod()
{
	sprintf(m_MethodScript, "保存文件(filetype(0:STATE 1:CST 2:DST 3:CDST 4:FDAT 5:IMAG))");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_ENA_SaveFile::~M_ENA_SaveFile()
{
//	free(m_InputDeviceName);
///	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_ENA_SaveFile::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "FileName");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"Name1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "FileType");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	return NTS_SUCCESS;
}
int M_ENA_SaveFile::Run(void)
{
	char FileName[500];
	int FileType;
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
	
	sprintf(FileName, "%s", m_InputPara1->paramVal);
	FileType = atoi(m_InputPara2->paramVal);
	
	return ENA_SaveFile(vHandle, FileName, FileType);
}

//M_ENA_SetCalPortForward 
M_ENA_SetCalPortForward::M_ENA_SetCalPortForward()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置端口方向(Type: 0:S12 1:S21)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_ENA_SetCalPortForward::~M_ENA_SetCalPortForward()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_ENA_SetCalPortForward::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "type");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_ENA_SetCalPortForward::Run(void)
{
	unsigned short ch;
	int type;
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
	type = atoi(m_InputPara2->paramVal);
	
	return ENA_SetCalPortForward(vHandle, ch, type);
}

//M_ENA_SetCalType 
M_ENA_SetCalType::M_ENA_SetCalType()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置校准类型(1:Open 2:Short 3:Thru 4:Enhanced Response 5:Full 1-Port 6:Full 2-Port)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_ENA_SetCalType::~M_ENA_SetCalType()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_ENA_SetCalType::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "type");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_ENA_SetCalType::Run(void)
{
	unsigned short ch;
	int type;
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
	type = atoi(m_InputPara2->paramVal);	
	
	return ENA_SetCalType(vHandle, ch, type);
}

//M_ENA_GetCalibrationData 
M_ENA_GetCalibrationData::M_ENA_GetCalibrationData()
:BaseMethod()
{
	sprintf(m_MethodScript, "获得校准原始数据(1:Open 2:Short 3:Load 4:Thru  5:Isolation)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_ENA_GetCalibrationData::~M_ENA_GetCalibrationData()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_ENA_GetCalibrationData::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "type");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_ENA_GetCalibrationData::Run(void)
{
	unsigned short ch;
	int type;
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
	type = atoi(m_InputPara2->paramVal);
	
	return ENA_GetCalibrationData(vHandle, ch, type);
}

//M_ENA_SetECalType 
M_ENA_SetECalType::M_ENA_SetECalType()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置电子校准类型(1:Full 1-Port 2:Full 2-Port 3:Enhanced Response 4:Response(Thru))");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_ENA_SetECalType::~M_ENA_SetECalType()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_ENA_SetECalType::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "type");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_ENA_SetECalType::Run(void)
{
	unsigned short ch;
	int type;
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
	type = atoi(m_InputPara2->paramVal);
	
	return ENA_SetECalType(vHandle, ch, type);
}

//M_ENA_SaveCalibration 
M_ENA_SaveCalibration::M_ENA_SaveCalibration()
:BaseMethod()
{
	sprintf(m_MethodScript, "保存校准数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	Init();
}
M_ENA_SaveCalibration::~M_ENA_SaveCalibration()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}
int M_ENA_SaveCalibration::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_ENA_SaveCalibration::Run(void)
{
	unsigned short ch;	
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
	
	return ENA_SaveCalibration(vHandle, ch);
}

//M_ENA_SetCalKit 
M_ENA_SetCalKit::M_ENA_SetCalKit()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置校准件类型");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_ENA_SetCalKit::~M_ENA_SetCalKit()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_ENA_SetCalKit::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Ch");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "type");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_ENA_SetCalKit::Run(void)
{
	unsigned short ch;
	int type;
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
	type = atoi(m_InputPara2->paramVal);
	
	return ENA_SetCalKit(vHandle, ch, type);
}

//class M_ENA_SendCmd 
M_ENA_SendCmd::M_ENA_SendCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_ENA_SendCmd::~M_ENA_SendCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_ENA_SendCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Command");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_ENA_SendCmd::Run(void)
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
	return ENA_SendCmd(vHandle, CmdStr);
}
//class M_ENA_GetCmd 获取返回指令值
M_ENA_GetCmd::M_ENA_GetCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令并获取指令的返回数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_ENA_GetCmd::~M_ENA_GetCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara1);
}

int M_ENA_GetCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
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
int M_ENA_GetCmd::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char CmdStr[500] = {0};
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
	res = ENA_GetCmd(vHandle, CmdStr, RetStr);
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

//class M_ENA_GetIDN 
M_ENA_GetIDN::M_ENA_GetIDN()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取设备型号信息");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_ENA_GetIDN::~M_ENA_GetIDN()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);
}

int M_ENA_GetIDN::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
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
int M_ENA_GetIDN::Run(void)
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
	
	res = ENA_GetIDN(vHandle, IDN);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%s", IDN);
	}
	return res;
}

//class M_ENA_GetMarkerXValue
M_ENA_GetMarkerXValue::M_ENA_GetMarkerXValue()
:BaseMethod()
{
	
	sprintf(m_MethodScript, "获取指定Marker点X轴值");
	m_InputDeviceName =  CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	
	m_OutputPara = CreateParamStruct();
	
	Init();
}
M_ENA_GetMarkerXValue::~M_ENA_GetMarkerXValue()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
	
//	free(m_OutputPara);
	
	
}
int M_ENA_GetMarkerXValue::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "markerindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara->paramName, "Value");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_ENA_GetMarkerXValue::Run(void)
{
	unsigned short chindex,markerindex;
	double Value;
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
	
	chindex =  atoi(m_InputPara1->paramVal);
	markerindex =  atoi(m_InputPara2->paramVal);	
	
	retVal = ENA_GetMarkerXValue(vHandle, chindex,markerindex,&Value);
	if(retVal==NTS_SUCCESS)
	{
		if(Value>0.0001)
		{
			sprintf(m_OutputPara->paramVal,"%e",Value);
		}
		else
		{
			sprintf(m_OutputPara->paramVal,"%e",Value);
		}
	}
	return retVal;
	
}

//class M_ENA_GetMarkerFreqOfPC
M_ENA_GetMarkerFreqOfPC::M_ENA_GetMarkerFreqOfPC()
:BaseMethod()
{
	sprintf(m_MethodScript, "从PC内存数据获取指定频率点Marker值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_ENA_GetMarkerFreqOfPC::~M_ENA_GetMarkerFreqOfPC()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
//	free(m_OutputPara);
}
int M_ENA_GetMarkerFreqOfPC::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);	
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "markerindex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "freq");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"2017.4");
	sprintf(m_InputPara3->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara3);

	sprintf(m_OutputPara->paramName, "value");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_ENA_GetMarkerFreqOfPC::Run(void)
{
	unsigned short chindex,markerindex;
	double freq;
	double data;
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

	chindex = atoi(m_InputPara1->paramVal);
	markerindex = atoi(m_InputPara2->paramVal);	
	freq = atof(m_InputPara3->paramVal);
	
	retVal = ENA_GetMarkerFreqOfPC(vHandle, chindex, markerindex, freq, &data);
	if(retVal==NTS_SUCCESS)
	{		
		sprintf(m_OutputPara->paramVal,"%e",data);		
	}
	return retVal;
}

//class M_ENA_GetTraceData
M_ENA_GetTraceData::M_ENA_GetTraceData()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取整条曲线数据值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();	
	Init();
}
M_ENA_GetTraceData::~M_ENA_GetTraceData()
{
//	free(m_InputDeviceName);
///	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
	
}

int M_ENA_GetTraceData::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "Traceindex");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara->paramName, "TraceData");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
	
}
int M_ENA_GetTraceData::Run(void)
{
	double Data[1024*10] = {0};
	int Count;
	int retVal,i = 0;
	int ChIndex, TraceIndex;
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
	
	ChIndex = atoi(m_InputPara1->paramVal);
	TraceIndex = atoi(m_InputPara2->paramVal);

	retVal = ENA_GetTraceData(vHandle,ChIndex, TraceIndex, Data, &Count);
	if(retVal == NTS_SUCCESS)
	{
		m_OutputPara->LparamVal = (char *) malloc(Count * 30 * sizeof(char));
		for(i=0; i<Count; i++)
		{
			if (i == 0 )
			{
				sprintf(m_OutputPara->LparamVal,"%e", Data[i]);
			}
			else
			{
				sprintf(m_OutputPara->LparamVal, "%s,%e", m_OutputPara->LparamVal, Data[i]);
			}
			
		}
	}
	return retVal;
}

//class M_ENA_GetTraceDataX
M_ENA_GetTraceDataX::M_ENA_GetTraceDataX()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取整条曲线X轴数据值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();	
	Init();
}
M_ENA_GetTraceDataX::~M_ENA_GetTraceDataX()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
	
}

int M_ENA_GetTraceDataX::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "Traceindex");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara->paramName, "TraceData");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
	
}
int M_ENA_GetTraceDataX::Run(void)
{
	double Data[1024*10] = {0};
	int Count;
	int retVal,i = 0;
	int ChIndex, TraceIndex;
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
	
	ChIndex = atoi(m_InputPara1->paramVal);
	TraceIndex = atoi(m_InputPara2->paramVal);
	
	retVal = ENA_GetTraceDataX(vHandle,ChIndex, TraceIndex, Data, &Count);
	if(retVal == NTS_SUCCESS)
	{
		m_OutputPara->LparamVal = (char *) malloc(Count * 30 * sizeof(char));
		for(i=0; i<Count; i++)
		{
			if (i == 0 )
			{
				sprintf(m_OutputPara->LparamVal,"%e", Data[i]);
			}
			else
			{
				sprintf(m_OutputPara->LparamVal, "%s,%e", m_OutputPara->LparamVal, Data[i]);
			}
			
		}
	}
	return retVal;
}

// class M_ENA_GetSweepType 
M_ENA_GetSweepType::M_ENA_GetSweepType()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取扫描类型 (0:Linear 1: Log 2: Segment 3:Power)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	m_OutputPara = CreateParamStruct();	
	Init();
}
M_ENA_GetSweepType::~M_ENA_GetSweepType()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara);	
}

int M_ENA_GetSweepType::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Chindex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
		
	sprintf(m_OutputPara->paramName, "SweepType");
	m_OutputPara->paramType = NTSUInt16;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
	
}
int M_ENA_GetSweepType::Run(void)
{	
	int vType;
	int retVal;
	int ChIndex;
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
	
	ChIndex = atoi(m_InputPara1->paramVal);
	
	retVal = ENA_GetSweepType(vHandle, ChIndex, &vType);
	if(retVal == NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal, "%d", vType);	
	}
	return retVal;
}

// class M_ENA_SetTrigSource 
M_ENA_SetTrigSource::M_ENA_SetTrigSource()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置触发源(0:Internal 1:External 2:Bus)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	Init();
}
M_ENA_SetTrigSource::~M_ENA_SetTrigSource()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);		
}

int M_ENA_SetTrigSource::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TrigSource");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
	
}
int M_ENA_SetTrigSource::Run(void)
{	
	int vType;
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
	
	vType = atoi(m_InputPara1->paramVal);
	
	retVal = ENA_SetTrigSource(vHandle, vType);
	return retVal;
}

// class M_ENA_SetTrigMode 
M_ENA_SetTrigMode::M_ENA_SetTrigMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置触发类型(0:IMMediate 1:Single 2:Contine)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	Init();
}
M_ENA_SetTrigMode::~M_ENA_SetTrigMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);		
}

int M_ENA_SetTrigMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TrigMode");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
	
}
int M_ENA_SetTrigMode::Run(void)
{	
	int vType;
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
	
	vType = atoi(m_InputPara1->paramVal);
	
	retVal = ENA_SetTrigMode(vHandle, vType);
	return retVal;
}

// class M_ENA_SaveTraceByName
M_ENA_SaveTraceByName::M_ENA_SaveTraceByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "以命名方式将测试曲线数据保存到PC内存中");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	m_InputPara2 = CreateParamStruct();	
	m_InputPara3 = CreateParamStruct();	
	Init();
}
M_ENA_SaveTraceByName::~M_ENA_SaveTraceByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);		
//	free(m_InputPara2);		
//	free(m_InputPara3);		
}

int M_ENA_SaveTraceByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "CHIndex");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "TraceIndex");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "TraceName");
	m_InputPara3->paramType = NTSString;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"Trace1");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);

	return NTS_SUCCESS;
	
}
int M_ENA_SaveTraceByName::Run(void)
{		
	int retVal;
	int ChIndex, TraceIndex;
	char vTraceName[100];
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
	
	ChIndex = atoi(m_InputPara1->paramVal);
	TraceIndex = atoi(m_InputPara2->paramVal);
	sprintf(vTraceName, "%s", m_InputPara3->paramVal);

	retVal = ENA_SaveTraceByName(vHandle, ChIndex, TraceIndex, vTraceName);
	return retVal;
}

// class M_ENA_SetTraceMathTypeByName
M_ENA_SetTraceMathTypeByName::M_ENA_SetTraceMathTypeByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "以命名方式处理PC内存数据(0:Off 1:Trace1/Trace2 2:Trace1*Trace2 3:Trace1-Trace2 4:Trace1+Trace2)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	m_InputPara2 = CreateParamStruct();	
	m_InputPara3 = CreateParamStruct();	
	m_InputPara4 = CreateParamStruct();	
	Init();
}
M_ENA_SetTraceMathTypeByName::~M_ENA_SetTraceMathTypeByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);		
//	free(m_InputPara2);		
//	free(m_InputPara3);		
//	free(m_InputPara4);		
}

int M_ENA_SetTraceMathTypeByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Trace1");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"Trace1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "Trace2");
	m_InputPara2->paramType = NTSString;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"Trace2");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "Type");
	m_InputPara3->paramType = NTSString;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"0");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);
	
	sprintf(m_InputPara4->paramName, "NewTrace");
	m_InputPara4->paramType = NTSString;
	m_InputPara4->paramCount = 1;
	sprintf(m_InputPara4->paramVal,"Trace3");
	sprintf(m_InputPara4->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara4);
	
	return NTS_SUCCESS;
	
}
int M_ENA_SetTraceMathTypeByName::Run(void)
{		
	int retVal;
	int vType;
	char vTraceName1[100], vTraceName2[100], vNewName[100];
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
	
	sprintf(vTraceName1, "%s", m_InputPara1->paramVal);
	sprintf(vTraceName2, "%s", m_InputPara2->paramVal);
	vType = atoi(m_InputPara3->paramVal);
	sprintf(vNewName, "%s", m_InputPara4->paramVal);
	
	retVal = ENA_SetTraceMathTypeByName(vHandle, vTraceName1, vTraceName2, vType, vNewName);
	return retVal;
}

// class M_ENA_DeleteTraceByName
M_ENA_DeleteTraceByName::M_ENA_DeleteTraceByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "删除一条PC内存曲线");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	Init();
}
M_ENA_DeleteTraceByName::~M_ENA_DeleteTraceByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);			
}

int M_ENA_DeleteTraceByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TraceName");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"Trace1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
	
}
int M_ENA_DeleteTraceByName::Run(void)
{		
	int retVal;	
	char vTraceName[100];
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
	
	sprintf(vTraceName, "%s", m_InputPara1->paramVal);
	
	retVal = ENA_DeleteTraceByName(vHandle, vTraceName);
	return retVal;
}

// class M_ENA_DeleteAllTrace
M_ENA_DeleteAllTrace::M_ENA_DeleteAllTrace()
:BaseMethod()
{
	sprintf(m_MethodScript, "删除所有PC内存曲线");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_ENA_DeleteAllTrace::~M_ENA_DeleteAllTrace()
{
//	free(m_InputDeviceName);
}

int M_ENA_DeleteAllTrace::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
	
}
int M_ENA_DeleteAllTrace::Run(void)
{		
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
	retVal = ENA_DeleteAllTrace(vHandle);
	return retVal;
}

// class M_ENA_SetMarkerSearchFreqByName
M_ENA_SetMarkerSearchFreqByName::M_ENA_SetMarkerSearchFreqByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "在PC内存数据中设置MARKER 的查找范围(MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	m_InputPara2 = CreateParamStruct();	
	m_InputPara3 = CreateParamStruct();	
	Init();
}
M_ENA_SetMarkerSearchFreqByName::~M_ENA_SetMarkerSearchFreqByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);		
//	free(m_InputPara2);		
//	free(m_InputPara3);				
}

int M_ENA_SetMarkerSearchFreqByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TraceName");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"Trace1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "Start");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "Stop");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara3);	
	
	return NTS_SUCCESS;
	
}
int M_ENA_SetMarkerSearchFreqByName::Run(void)
{		
	int retVal;
	float Start, Stop;
	char vTraceName[100];
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
	
	sprintf(vTraceName, "%s", m_InputPara1->paramVal);	
	Start = atof(m_InputPara2->paramVal);
	Stop = atof(m_InputPara3->paramVal);
	
	retVal = ENA_SetMarkerSearchFreqByName(vHandle, vTraceName, Start, Stop);
	return retVal;
}

//M_ENA_GetMarkerValueByName
M_ENA_GetMarkerValueByName::M_ENA_GetMarkerValueByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "从PC内存数据中获取最大值和最小值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();	
	
	Init();
}
M_ENA_GetMarkerValueByName::~M_ENA_GetMarkerValueByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_OutputPara1);
//	free(m_OutputPara2);	
}

int M_ENA_GetMarkerValueByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TraceName");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"Trace1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_OutputPara1->paramName, "Max");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	sprintf(m_OutputPara2->paramName, "Min");
	m_OutputPara2->paramType = NTSReal32;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara2);
	return NTS_SUCCESS;
}
int M_ENA_GetMarkerValueByName::Run(void)
{
	int res;
	char vTraceName[100];
	double Max = 0,Min = 0;
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
	
	sprintf(vTraceName, "%s", m_InputPara1->paramVal);
	res = ENA_GetMarkerValueByName(vHandle, vTraceName, &Max, &Min);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", Max);
		sprintf(m_OutputPara2->paramVal, "%e", Min);
	}
	return res;
}

//M_ENA_GetFluctuateByName
M_ENA_GetFluctuateByName::M_ENA_GetFluctuateByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "从PC内存数据中获取指定带宽范围内的平坦度(MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();	
	
	Init();
}
M_ENA_GetFluctuateByName::~M_ENA_GetFluctuateByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara1);	
}

int M_ENA_GetFluctuateByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TraceName");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"Trace1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "BandWidth");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara2);
	
	
	sprintf(m_OutputPara1->paramName, "Fluctuate");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"0");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_ENA_GetFluctuateByName::Run(void)
{
	int res;
	char vTraceName[100];
	double vBW, Fluctuate = 0;
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
	
	sprintf(vTraceName, "%s", m_InputPara1->paramVal);
	vBW = atof(m_InputPara2->paramVal);

	res = ENA_GetFluctuateByName(vHandle, vTraceName, vBW, &Fluctuate);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", Fluctuate);		
	}
	return res;
}

//M_ENA_GetMarkerFreqByName
M_ENA_GetMarkerFreqByName::M_ENA_GetMarkerFreqByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "从PC内存数据获取指定频率点Marker值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();	
	
	Init();
}
M_ENA_GetMarkerFreqByName::~M_ENA_GetMarkerFreqByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
//	free(m_OutputPara1);	
}

int M_ENA_GetMarkerFreqByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TraceName");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"Trace1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "Marker");
	m_InputPara2->paramType = NTSUInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "Freqence");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara3);
	
	
	sprintf(m_OutputPara1->paramName, "Value");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_ENA_GetMarkerFreqByName::Run(void)
{
	int res;
	int Marker;
	char vTraceName[100];
	double Freq, Value;
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
	
	sprintf(vTraceName, "%s", m_InputPara1->paramVal);
	Marker = atoi(m_InputPara2->paramVal);
	Freq = atof(m_InputPara3->paramVal);

	res = ENA_GetMarkerFreqByName(vHandle, vTraceName,Marker, Freq, &Value);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", Value);		
	}
	return res;
}


//  class M_ENA_GetTraceDataYByName 	
M_ENA_GetTraceDataYByName::M_ENA_GetTraceDataYByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "从PC内存获取曲线的Y轴数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	m_OutputPara1 = CreateParamStruct();	
	
	Init();
}
M_ENA_GetTraceDataYByName::~M_ENA_GetTraceDataYByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara1);	
}

int M_ENA_GetTraceDataYByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TraceName");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"Trace1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
		
	sprintf(m_OutputPara1->paramName, "TraceData_Y");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_ENA_GetTraceDataYByName::Run(void)
{
	int res;
	int vCount;
	char vTraceName[100];
	double vTraceData[20000];
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
	
	sprintf(vTraceName, "%s", m_InputPara1->paramVal);

	res = ENA_GetTraceDataYByName(vHandle, vTraceName, vTraceData, &vCount);
	if(res == NTS_SUCCESS)
	{
		m_OutputPara1->LparamVal = (char *) malloc(vCount * 30 * sizeof(char));
		for(int i=0; i<vCount; i++)
		{
			if (i == 0 )
			{
				sprintf(m_OutputPara1->LparamVal,"%e", vTraceData[i]);
			}
			else
			{
				sprintf(m_OutputPara1->LparamVal, "%s,%e", m_OutputPara1->LparamVal, vTraceData[i]);
			}
			
		}
	}
	return res;
}

// class M_ENA_GetTraceDataXByName 
M_ENA_GetTraceDataXByName::M_ENA_GetTraceDataXByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "从PC内存获取曲线的X轴数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	m_OutputPara1 = CreateParamStruct();	
	
	Init();
}
M_ENA_GetTraceDataXByName::~M_ENA_GetTraceDataXByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara1);	
}

int M_ENA_GetTraceDataXByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TraceName");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"Trace1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	
	sprintf(m_OutputPara1->paramName, "TraceData_X");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_ENA_GetTraceDataXByName::Run(void)
{
	int res;
	int vCount;
	char vTraceName[100];
	double vTraceData[20000];
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
	
	sprintf(vTraceName, "%s", m_InputPara1->paramVal);
	
	res = ENA_GetTraceDataXByName(vHandle, vTraceName, vTraceData, &vCount);
	if(res == NTS_SUCCESS)
	{
		m_OutputPara1->LparamVal = (char *) malloc(vCount * 30 * sizeof(char));
		for(int i=0; i<vCount; i++)
		{
			if (i == 0 )
			{
				sprintf(m_OutputPara1->LparamVal,"%e", vTraceData[i]);
			}
			else
			{
				sprintf(m_OutputPara1->LparamVal, "%s,%e", m_OutputPara1->LparamVal, vTraceData[i]);
			}
			
		}
	}
	return res;
}

// class M_ENA_SetMarkerFreq 
M_ENA_SetMarkerFreq::M_ENA_SetMarkerFreq()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置指定Marker点频率值(MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();	
	
	Init();
}
M_ENA_SetMarkerFreq::~M_ENA_SetMarkerFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara[0]);	
//	free(m_InputPara[1]);	
//	free(m_InputPara[2]);	
	
}

int M_ENA_SetMarkerFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = ENADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "chindex");
	m_InputPara[0]->paramType = NTSUInt8;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal, "1");
	sprintf(m_InputPara[0]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[0]);
	
	sprintf(m_InputPara[1]->paramName, "Markerindex");
	m_InputPara[1]->paramType = NTSUInt8;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"1");
	sprintf(m_InputPara[1]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[1]);
	
	sprintf(m_InputPara[2]->paramName, "Freq");
	m_InputPara[2]->paramType = NTSReal32;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"2017.4");
	sprintf(m_InputPara[2]->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara[2]);	
	
	return NTS_SUCCESS;
}
int M_ENA_SetMarkerFreq::Run(void)
{
	int res;
	unsigned short ch, Marker;
	double Freq;
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
	
	ch = atoi(m_InputPara[0]->paramVal);
	Marker = atoi(m_InputPara[1]->paramVal);
	Freq = atof(m_InputPara[2]->paramVal);

	res = ENA_SetMarkerFreq(vHandle, ch, Marker, Freq);	
	return res;
}