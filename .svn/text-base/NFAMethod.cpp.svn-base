
#include "stdafx.h"
#include "NFAMethod.h"
#include <assert.h>
#include "stdio.h"


extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

/************************************************************************/
/*  噪声分析仪驱动方法类                                                */
/************************************************************************/
//class M_NFA_Reset
M_NFA_Reset::M_NFA_Reset()
:BaseMethod()
{
	sprintf(m_MethodScript, "噪声仪复位");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_NFA_Reset::~M_NFA_Reset()
{
//	free(m_InputDeviceName);
}
int M_NFA_Reset::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_NFA_Reset::Run(void)
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
	
	return NFA_Reset(vHandle);
}
//class M_NFA_SetFreqMode
M_NFA_SetFreqMode::M_NFA_SetFreqMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置噪声仪频率模式(0:SWEep 1:LIST 2:FIXed)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_NFA_SetFreqMode::~M_NFA_SetFreqMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_NFA_SetFreqMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "freqmode");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_NFA_SetFreqMode::Run(void)
{
	unsigned short freqmode;
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
	
	freqmode = atoi(m_InputPara->paramVal);
	return NFA_SetFreqMode(vHandle,freqmode);
}
//class NFA_SetStartAndStopFreq
M_NFA_SetStartAndStopFreq::M_NFA_SetStartAndStopFreq()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置噪声仪起止频率(10MHz~3GHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_NFA_SetStartAndStopFreq::~M_NFA_SetStartAndStopFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_NFA_SetStartAndStopFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "startfreq");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"2010");
	sprintf(m_InputPara1->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "stopfreq");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"2025");
	sprintf(m_InputPara2->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_NFA_SetStartAndStopFreq::Run(void)
{
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
	
	startfreq = atof(m_InputPara1->paramVal);
	stopfreq = atof(m_InputPara2->paramVal);
	return NFA_SetStartAndStopFreq(vHandle,startfreq,stopfreq);
}
//class M_NFA_SetDispFormat
M_NFA_SetDispFormat::M_NFA_SetDispFormat()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置噪声仪显示模式(0:GRAPh 1:TABLe 2:METer)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_NFA_SetDispFormat::~M_NFA_SetDispFormat()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_NFA_SetDispFormat::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "format");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_NFA_SetDispFormat::Run(void)
{
	unsigned short format;
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
	
	format = atoi(m_InputPara->paramVal);
	return NFA_SetDispFormat(vHandle,format);
}
//class M_NFA_GetFreqNfigure
M_NFA_GetFreqNfigure::M_NFA_GetFreqNfigure()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取指定频率点的噪声系数值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_NFA_GetFreqNfigure::~M_NFA_GetFreqNfigure()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
//	free(m_OutputPara);
	
}
int M_NFA_GetFreqNfigure::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "startfreq");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"2010");
	sprintf(m_InputPara->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara);
	
	sprintf(m_OutputPara->paramName, "Nfigure");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "dB");
	m_OutputParamVector.push_back(m_OutputPara);	

	return NTS_SUCCESS;
}
int M_NFA_GetFreqNfigure::Run(void)
{
	float freq;
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
	
	freq = atof(m_InputPara->paramVal);
	
	retVal = NFA_GetFreqNfigure(vHandle,freq,&data);
	if(retVal==NTS_SUCCESS)
	{	
		sprintf(m_OutputPara->paramVal,"%e",data);
	}
	return retVal;
}
//class M_NFA_SetSweepMode
M_NFA_SetSweepMode::M_NFA_SetSweepMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置噪声仪扫描模式(0:Single 1:Continous)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_NFA_SetSweepMode::~M_NFA_SetSweepMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_NFA_SetSweepMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "sweepmode");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_NFA_SetSweepMode::Run(void)
{
	unsigned short sweepmode;
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
	sweepmode = atoi(m_InputPara->paramVal);
	return NFA_SetSweepMode(vHandle,sweepmode);
}
//class M_NFA_LoadFile
M_NFA_LoadFile::M_NFA_LoadFile()
:BaseMethod()
{
	sprintf(m_MethodScript, "加载噪声仪工作状态文件");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_NFA_LoadFile::~M_NFA_LoadFile()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_NFA_LoadFile::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
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
int M_NFA_LoadFile::Run(void)
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
	
	return NFA_LoadFile(vHandle,m_InputPara->paramVal);
}
//class M_NFA_GetFixedFreqValue 
M_NFA_GetListMax::M_NFA_GetListMax()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取最大噪声系数值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_NFA_GetListMax::~M_NFA_GetListMax()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
//	free(m_OutputPara);
}
int M_NFA_GetListMax::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "startfreq");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"2010");
	sprintf(m_InputPara1->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "step");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "freqcount");
	m_InputPara3->paramType = NTSUInt32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"1");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);

	sprintf(m_OutputPara->paramName, "MaxNF");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "dB");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_NFA_GetListMax::Run(void)
{
	int retVal;
	float startfreq,step;
	unsigned long count;
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
	
	startfreq = atof(m_InputPara1->paramVal);
	step = atof(m_InputPara2->paramVal);
	count = atoi(m_InputPara3->paramVal);
	retVal = NFA_GetListMax(vHandle,startfreq,step,count,&data);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%e",data);
	}
	return retVal;
}


//class M_NFA_SendCmd 
M_NFA_SendCmd::M_NFA_SendCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_NFA_SendCmd::~M_NFA_SendCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_NFA_SendCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
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
int M_NFA_SendCmd::Run(void)
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
	return NFA_SendCmd(vHandle, CmdStr);
}
//class M_NFA_GetCmd 
M_NFA_GetCmd::M_NFA_GetCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令并获取指令的返回数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_NFA_GetCmd::~M_NFA_GetCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara1);
}

int M_NFA_GetCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
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
int M_NFA_GetCmd::Run(void)
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
	res = NFA_GetCmd(vHandle, CmdStr, RetStr);
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

//class M_NFA_GetIDN 
M_NFA_GetIDN::M_NFA_GetIDN()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取设备型号信息");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_NFA_GetIDN::~M_NFA_GetIDN()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);
}

int M_NFA_GetIDN::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
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
int M_NFA_GetIDN::Run(void)
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
	
	res = NFA_GetIDN(vHandle, IDN);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%s", IDN);
	}
	return res;
}

// class M_NFA_GetTraceMax 
M_NFA_GetTraceMax::M_NFA_GetTraceMax()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取曲线数据的最大值(TraceIndex 1:NFIGure 2:GAIN 3:PHOT 4:PCOLd 5:TEFFective)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_NFA_GetTraceMax::~M_NFA_GetTraceMax()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_OutputPara1);
}

int M_NFA_GetTraceMax::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TraceIndex");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_OutputPara1->paramName, "MaxValue");
	m_OutputPara1->paramType = NTSReal64;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_NFA_GetTraceMax::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int TraceIndex;
	double Max;
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	TraceIndex = atoi(m_InputPara1->paramVal);
	res = NFA_GetTraceMax(vHandle, TraceIndex, &Max);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", Max);
	}
	return res;
}

// class M_NFA_GetTraceMin 
M_NFA_GetTraceMin::M_NFA_GetTraceMin()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取曲线数据的最小值(TraceIndex 1:NFIGure 2:GAIN 3:PHOT 4:PCOLd 5:TEFFective)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_NFA_GetTraceMin::~M_NFA_GetTraceMin()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_OutputPara1);
}

int M_NFA_GetTraceMin::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TraceIndex");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_OutputPara1->paramName, "MinValue");
	m_OutputPara1->paramType = NTSReal64;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_NFA_GetTraceMin::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int TraceIndex;
	double Min;
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	TraceIndex = atoi(m_InputPara1->paramVal);
	res = NFA_GetTraceMin(vHandle, TraceIndex, &Min);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", Min);
	}
	return res;
}

// class M_NFA_GetTraceFreqValue 
M_NFA_GetTraceFreqValue::M_NFA_GetTraceFreqValue()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取曲线指定频率点的值(TraceIndex 1:NFIGure 2:GAIN 3:PHOT 4:PCOLd 5:TEFFective Freq:单位:MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_NFA_GetTraceFreqValue::~M_NFA_GetTraceFreqValue()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara1);
}

int M_NFA_GetTraceFreqValue::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NFADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TraceIndex");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "Frequency");
	m_InputPara2->paramType = NTSReal64;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"2017.4");
	sprintf(m_InputPara2->paramUnit, "MHz");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_OutputPara1->paramName, "Value");
	m_OutputPara1->paramType =  NTSReal64;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_NFA_GetTraceFreqValue::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int TraceIndex;
	double Freq, Value;
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	TraceIndex = atoi(m_InputPara1->paramVal);
	Freq = atof(m_InputPara2->paramVal);
	res = NFA_GetTraceFreqValue(vHandle, TraceIndex, Freq, &Value);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", Value);
	}
	return res;
}


