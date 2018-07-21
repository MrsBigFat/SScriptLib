
#include "stdafx.h"
#include "SGMethod.h"
#include <assert.h>
#include "stdio.h"
#include <map>


extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

//class M_SG_Reset
M_SG_Reset::M_SG_Reset()
:BaseMethod()
{
	sprintf(m_MethodScript, "信号源设备复位");
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_SG_Reset::~M_SG_Reset()
{
//	free(m_InputDeviceName);
}
int M_SG_Reset::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_SG_Reset::Run(void)
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
	
	return SG_Reset(vHandle);
}


//class M_SG_SetWaveFile
M_SG_SetWaveFile::M_SG_SetWaveFile()
:BaseMethod()
{
	sprintf(m_MethodScript, "加载信号源波形文件(文件名)");
	
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}

M_SG_SetWaveFile::~M_SG_SetWaveFile()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetWaveFile::Init()
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "WaveFileName");
	m_InputPara->paramType = NTSString;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}

int M_SG_SetWaveFile::Run()
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char vWaveFile[200];

	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	sprintf(vWaveFile, "%s", m_InputPara->paramVal);
	return SG_SetWaveFile(vHandle, vWaveFile);
}

//Class M_SG_SetArbWaveState
M_SG_SetArbWaveState::M_SG_SetArbWaveState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置波形调用状态(0:off 1:on)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}

M_SG_SetArbWaveState::~M_SG_SetArbWaveState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetArbWaveState::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "state");
	m_InputPara->paramType = NTSUInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_SG_SetArbWaveState::Run(void)
{
	unsigned short workstate;
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

	workstate = atoi(m_InputPara->paramVal);
	return SG_SetArbWaveState(vHandle, workstate);
}

//class M_SG_SetRFFreq
M_SG_SetRFFreq::M_SG_SetRFFreq()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源频率");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_SG_SetRFFreq::~M_SG_SetRFFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_SG_SetRFFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "frequency");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"2017.4");
	sprintf(m_InputPara->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_SG_SetRFFreq::Run(void)
{
	float frequency;
	
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

	frequency = atof(m_InputPara->paramVal);
	return SG_SetRFFreq(vHandle,frequency);
}
//class M_SG_SetRFAmplitu
M_SG_SetRFAmplitu::M_SG_SetRFAmplitu()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源幅度值(<=20dBm)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_SG_SetRFAmplitu::~M_SG_SetRFAmplitu()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_SG_SetRFAmplitu::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "level");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"-20");
	sprintf(m_InputPara->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_SG_SetRFAmplitu::Run(void)
{
	float level;
	
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
	
	level = atof(m_InputPara->paramVal);
	return SG_SetRFAmplitu(vHandle,level);
	return NTS_SUCCESS;
}
//class M_SG_GetRFAmplitu
M_SG_GetRFAmplitu::M_SG_GetRFAmplitu()
:BaseMethod()
{
	sprintf(m_MethodScript, "读取信号源幅度值");	
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara= CreateParamStruct();
	Init();
}
M_SG_GetRFAmplitu::~M_SG_GetRFAmplitu()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara);
}
int M_SG_GetRFAmplitu::Init()
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara->paramName, "level");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "dBm");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_SG_GetRFAmplitu::Run()
{
	double level;
	int resval;
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

	resval = SG_GetRFAmplitu(vHandle, &level);
	if (resval==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%e",level);
			return NTS_SUCCESS;
	}
	else
		return resval;
}

//class M_SG_SetRFAmplituOffset
M_SG_SetRFAmplituOffset::M_SG_SetRFAmplituOffset()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源幅度偏移值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}

M_SG_SetRFAmplituOffset::~M_SG_SetRFAmplituOffset()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetRFAmplituOffset::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "level");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "dB");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_SG_SetRFAmplituOffset::Run(void)
{
	float level;
	
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
	
	level = atof(m_InputPara->paramVal);
	return SG_SetRFAmplituOffset(vHandle,level);
	return NTS_SUCCESS;
}

//class M_SG_SetIQModulationState
M_SG_SetIQModulationState::M_SG_SetIQModulationState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源解调状态(0:off 1:on)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_SG_SetIQModulationState::~M_SG_SetIQModulationState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetIQModulationState::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "state");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);

	return NTS_SUCCESS;
}
int M_SG_SetIQModulationState::Run(void)
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
	return SG_SetIQModulationState(vHandle,state);
	return NTS_SUCCESS;
	
}

//class M_SG_SetRFPowerOnState
M_SG_SetRFPowerOnState::M_SG_SetRFPowerOnState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源输出状态(0:off 1:on)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_SG_SetRFPowerOnState::~M_SG_SetRFPowerOnState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetRFPowerOnState::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "state");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_SG_SetRFPowerOnState::Run(void)
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
	return SG_SetRFPowerOnState(vHandle,state);
	return NTS_SUCCESS;
}

//class M_SG_SetSweepPoint
M_SG_SetSweepPoint::M_SG_SetSweepPoint()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源扫描点数");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_SG_SetSweepPoint::~M_SG_SetSweepPoint()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetSweepPoint::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "point");
	m_InputPara->paramType = NTSUInt32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_SG_SetSweepPoint::Run(void)
{
	unsigned long point;
	
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
	
	point = atoi(m_InputPara->paramVal);
	return SG_SetSweepPoint(vHandle,point);
	return NTS_SUCCESS;
}
//class M_SG_SetSweepTriMode
M_SG_SetSweepTriMode::M_SG_SetSweepTriMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源扫描触发状态(0:SINGle 1:CONTtinuous)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_SG_SetSweepTriMode::~M_SG_SetSweepTriMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetSweepTriMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "trigmod");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_SG_SetSweepTriMode::Run(void)
{
	unsigned short trigmod;
	
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

	trigmod = atoi(m_InputPara->paramVal);
	return SG_SetSweepTriMode(vHandle,trigmod);
	return NTS_SUCCESS;
}
//class M_SG_SetStartandStopFreq
M_SG_SetStartandStopFreq::M_SG_SetStartandStopFreq()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源扫描起始和截止频率(10MHz~3GHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	m_InputPara2= CreateParamStruct();
	Init();
}
M_SG_SetStartandStopFreq::~M_SG_SetStartandStopFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_SG_SetStartandStopFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "startfreqence");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"2010");
	sprintf(m_InputPara1->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "stopfreqence");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"2025");
	sprintf(m_InputPara2->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_SG_SetStartandStopFreq::Run(void)
{
	float startfreqence,stopfreqence;
	
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

	startfreqence = atof(m_InputPara1->paramVal);
	stopfreqence = atof(m_InputPara2->paramVal);
	return SG_SetStartandStopFreq(vHandle,startfreqence,stopfreqence);
	return NTS_SUCCESS;
}
//class M_SG_SetSweepMode
M_SG_SetSweepMode::M_SG_SetSweepMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源扫描模式(0:CW 1:FIXed 2:LIST/扫频");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_SG_SetSweepMode::~M_SG_SetSweepMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetSweepMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "mode");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_SG_SetSweepMode::Run(void)
{
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

	mode = atoi(m_InputPara->paramVal);
	return SG_SetSweepMode(vHandle,mode);
	return NTS_SUCCESS;
	
}
//class M_SG_SetARBMarkMode
M_SG_SetARBMarkMode::M_SG_SetARBMarkMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源Mark通道模式(//R&S 0:Unchanged 1:Restart 2:pulse 3:pattern 4:on/off Ratio)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	m_InputPara2= CreateParamStruct();
	Init();
}
M_SG_SetARBMarkMode::~M_SG_SetARBMarkMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_SG_SetARBMarkMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "markindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "mode");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_SG_SetARBMarkMode::Run(void)
{
	short markindex;
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

	markindex = atoi(m_InputPara1->paramVal);
	mode = atoi(m_InputPara2->paramVal);
	return SG_SetARBMarkMode(vHandle,markindex,mode);
}

//class M_SG_SetFreqOffset
M_SG_SetFreqOffset::M_SG_SetFreqOffset()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源频率偏移量");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_SG_SetFreqOffset::~M_SG_SetFreqOffset()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetFreqOffset::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "freqoffset");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_SG_SetFreqOffset::Run(void)
{
	float freqoffset;
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

	freqoffset = atof(m_InputPara->paramVal);
	return SG_SetFreqOffset(vHandle,freqoffset);
}
//class M_SG_SetARBMarkDelay
M_SG_SetARBMarkDelay::M_SG_SetARBMarkDelay()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源Mark延迟时间(//R&S:有效 //Agilent:无效 ) ");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	m_InputPara2= CreateParamStruct();
	Init();
}
M_SG_SetARBMarkDelay::~M_SG_SetARBMarkDelay()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_SG_SetARBMarkDelay::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "markindex");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "delaytime");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_SG_SetARBMarkDelay::Run(void)
{
	short index;
	float delaytime;
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

	index = atoi(m_InputPara1->paramVal);
	delaytime = atof(m_InputPara2->paramVal);
	return SG_SetARBMarkDelay(vHandle,index,delaytime);
}
//M_SG_SetTrigInContinuousType
M_SG_SetTrigInContinuousType::M_SG_SetTrigInContinuousType()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源连续触发类型 (//R&S: 0:AUTO 1:RETRigger 2:AAUT 3:ARET  //Agilent: 0:FREE 1:TRIGger 2:RESet) ");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_SG_SetTrigInContinuousType::~M_SG_SetTrigInContinuousType()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetTrigInContinuousType::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "type");
	m_InputPara->paramType = NTSUInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);

	return NTS_SUCCESS;
}
int M_SG_SetTrigInContinuousType::Run(void)
{
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
	type = atoi(m_InputPara->paramVal);
	return SG_SetTrigInContinuousType(vHandle,type);
}
// M_SG_SetTrigInSourceType
M_SG_SetTrigInSourceType::M_SG_SetTrigInSourceType()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源触发源类型 (//R&S: 0:OBA 1:EXT 2:INT 3:BEXT  //Agilent: 0:KEY 1:EXT 2:BUS) ");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_SG_SetTrigInSourceType::~M_SG_SetTrigInSourceType()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetTrigInSourceType::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "type");
	m_InputPara->paramType = NTSUInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	return NTS_SUCCESS;
}
int M_SG_SetTrigInSourceType::Run(void)
{
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

	type = atoi(m_InputPara->paramVal);
	return SG_SetTrigInSourceType(vHandle,type);
}
//M_SG_SetTrigInPolarity
M_SG_SetTrigInPolarity::M_SG_SetTrigInPolarity()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源触发极性 (//R&S:无效  //Agilent:0:POSitive 1:NEGative) ");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_SG_SetTrigInPolarity::~M_SG_SetTrigInPolarity()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetTrigInPolarity::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "polarity");
	m_InputPara->paramType = NTSUInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	return NTS_SUCCESS;
}
int M_SG_SetTrigInPolarity::Run(void)
{
	short polarity;
	
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

	polarity = atoi(m_InputPara->paramVal);
	return SG_SetTrigInPolarity(vHandle,polarity);
}
//M_SG_SetTrigInDelay
M_SG_SetTrigInDelay::M_SG_SetTrigInDelay()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源触发延迟时间(//R&S:有效  //Agilent:有效) ");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_SG_SetTrigInDelay::~M_SG_SetTrigInDelay()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetTrigInDelay::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "delaytime");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara);
	
	return NTS_SUCCESS;
}
int M_SG_SetTrigInDelay::Run(void)
{
	float delaytime;
	
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

	delaytime = atof(m_InputPara->paramVal);
	return SG_SetTrigInDelay(vHandle,delaytime);
}
//M_SG_SetMarkerALCHold
M_SG_SetMarkerALCHold::M_SG_SetMarkerALCHold()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源Marker ALC Hold值 (//R&S:无效  //Agilent: 0:NONE 1:M1 2:M2 3:M3 4:M4) ");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_SG_SetMarkerALCHold::~M_SG_SetMarkerALCHold()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetMarkerALCHold::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "marker");
	m_InputPara->paramType = NTSUInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	return NTS_SUCCESS;
}
int M_SG_SetMarkerALCHold::Run(void)
{
	short marker;
	
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

	marker = atoi(m_InputPara->paramVal);
	return SG_SetMarkerALCHold(vHandle,marker);
}
//M_SG_SetAmpALCMode
M_SG_SetAmpALCMode::M_SG_SetAmpALCMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源电平 ALC状态 (//R&S:无效  //Agilent: 0:Off 1:On ) ");
	m_InputPara= CreateParamStruct();
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_SG_SetAmpALCMode::~M_SG_SetAmpALCMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetAmpALCMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "mode");
	m_InputPara->paramType = NTSUInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	return NTS_SUCCESS;
}
int M_SG_SetAmpALCMode::Run(void)
{
	short mode;
	
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
	return SG_SetAmpALCMode(vHandle,mode);
}

//M_SG_SetClockFreq
M_SG_SetClockFreq::M_SG_SetClockFreq()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置时钟频率(单位:MHz)(//R&S:有效  //Agilent:有效 ) ");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_SG_SetClockFreq::~M_SG_SetClockFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetClockFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "freq");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara);
	
	return NTS_SUCCESS;
}
int M_SG_SetClockFreq::Run(void)
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
	return SG_SetClockFreq(vHandle,freq);
}

//M_SG_SetRFPowerSearchMode
M_SG_SetRFPowerSearchMode::M_SG_SetRFPowerSearchMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置功率检测方式(//Agilent 0:Normal 1:Minimum //R&S:无效 ) ");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_SG_SetRFPowerSearchMode::~M_SG_SetRFPowerSearchMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_SG_SetRFPowerSearchMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "PwrSearchMode");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	return NTS_SUCCESS;
}
int M_SG_SetRFPowerSearchMode::Run(void)
{
	short mode;
	
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
	return SG_SetRFPowerSearchMode(vHandle,mode);
}


//class M_SG_SendCmd 
M_SG_SendCmd::M_SG_SendCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_SG_SendCmd::~M_SG_SendCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_SG_SendCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
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
int M_SG_SendCmd::Run(void)
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
	return SG_SendCmd(vHandle, CmdStr);
}
//class M_SG_GetCmd 
M_SG_GetCmd::M_SG_GetCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令并获取指令的返回数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	Init();
}

M_SG_GetCmd::~M_SG_GetCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara1);
}

int M_SG_GetCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
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
int M_SG_GetCmd::Run(void)
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
	if (m_InputPara1->LparamVal != NULL)
	{
		sprintf(CmdStr, "%s", m_InputPara1->LparamVal);
	}
	else
	{
		sprintf(CmdStr, "%s", m_InputPara1->paramVal);
	}	
	res = SG_GetCmd(vHandle, CmdStr, RetStr);
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

//class M_SG_GetIDN 
M_SG_GetIDN::M_SG_GetIDN()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取设备型号信息");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	Init();
}

M_SG_GetIDN::~M_SG_GetIDN()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);
}

int M_SG_GetIDN::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
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
int M_SG_GetIDN::Run(void)
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

	res = SG_GetIDN(vHandle, IDN);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%s", IDN);
	}
	return res;
}
//class M_SG_SetCwCarrier
M_SG_SetCwCarrier::M_SG_SetCwCarrier()
	:BaseMethod()
{
	sprintf(m_MethodScript, "设置信号源载波");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_SG_SetCwCarrier::~M_SG_SetCwCarrier()
{
	//	free(m_InputDeviceName);
	//	free(m_InputPara);
}
int M_SG_SetCwCarrier::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = SGDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal, "");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "Frequency");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal, "100");
	sprintf(m_InputPara1->paramUnit, "MHz");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "mode");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal, "1");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_SG_SetCwCarrier::Run(void)
{
	double frequency;
	int mode;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it;
	char vDeviveName[100];

	sprintf(vDeviveName, m_InputDeviceName->paramVal);
	it = gDeviceManagerMap.find(vDeviveName);
	if (it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	frequency = atof(m_InputPara1->paramVal);
	mode = atoi(m_InputPara2->paramVal);
	return SG_SetCwCarrier(vHandle, frequency, mode);
}