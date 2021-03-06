
#include "stdafx.h"
#include "PSAMethod.h"
#include <assert.h>
#include "stdio.h"
#include <map>


extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

/************************************************************************/
/*  频谱分析仪驱动程序方法类                                            */
/************************************************************************/
//class M_PSA_SetPreset
M_PSA_SetPreset::M_PSA_SetPreset()
:BaseMethod()
{
	sprintf(m_MethodScript, "频谱仪复位");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetPreset::~M_PSA_SetPreset()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetPreset::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	return NTS_SUCCESS;
}
int M_PSA_SetPreset::Run(void)
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

	return PSA_SetPreset(vHandle);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetCenterFrq
M_PSA_SetCenterFrq::M_PSA_SetCenterFrq()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪中心频率");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_PSA_SetCenterFrq::~M_PSA_SetCenterFrq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetCenterFrq::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "centerFreq");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"2017.4");
	sprintf(m_InputPara->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetCenterFrq::Run(void)
{
	double centerFreq;
	
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

	centerFreq = atof(m_InputPara->paramVal);
	return PSA_SetCenterFrq(vHandle,centerFreq);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetCenterFrqandSpan
M_PSA_SetCenterFrqandSpan::M_PSA_SetCenterFrqandSpan()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪中心频率和SPAN值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	m_InputPara2= CreateParamStruct();
	Init();
}
M_PSA_SetCenterFrqandSpan::~M_PSA_SetCenterFrqandSpan()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_SetCenterFrqandSpan::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "centerFreq");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"2017.4");
	sprintf(m_InputPara1->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "span");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "MHz ");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_PSA_SetCenterFrqandSpan::Run(void)
{
	double centerFreq,span;	
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

	centerFreq = atof(m_InputPara1->paramVal);
	span = atof(m_InputPara2->paramVal);
	return PSA_SetCenterFrqandSpan(vHandle,centerFreq,span);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetRefLevel
M_PSA_SetRefLevel::M_PSA_SetRefLevel()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪参考电平");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_PSA_SetRefLevel::~M_PSA_SetRefLevel()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetRefLevel::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "reflevel");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"-30");
	sprintf(m_InputPara->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetRefLevel::Run(void)
{
	double reflevel;
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

	reflevel = atoi(m_InputPara->paramVal);
	return PSA_SetRefLevel(vHandle,reflevel);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetRFAttenuation
M_PSA_SetRFAttenuation::M_PSA_SetRFAttenuation()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪内部衰减值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_PSA_SetRFAttenuation::~M_PSA_SetRFAttenuation()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetRFAttenuation::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit ," ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName,"atten");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit, "dB");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetRFAttenuation::Run(void)
{
	double atten;
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

	atten = atof(m_InputPara->paramVal);
	return PSA_SetRFAttenuation(vHandle,atten);
	return NTS_SUCCESS;
	
}

//class M_PSA_SetRFAttenAuto
M_PSA_SetRFAttenAuto::M_PSA_SetRFAttenAuto()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪自动内部衰减");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetRFAttenAuto::~M_PSA_SetRFAttenAuto()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetRFAttenAuto::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetRFAttenAuto::Run(void)
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

	return PSA_SetRFAttenAuto(vHandle);
	return NTS_SUCCESS;
	
}

//class M_PSA_SetRefLevelOff
M_PSA_SetRefLevelOff::M_PSA_SetRefLevelOff()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪内部衰减偏移量");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetRefLevelOff::~M_PSA_SetRefLevelOff()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetRefLevelOff::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "refLevOffs");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "dB");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetRefLevelOff::Run(void)
{
	double refLevOffs;
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

	refLevOffs = atof(m_InputPara->paramVal);
	return PSA_SetRefLevelOff(vHandle,refLevOffs);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetExtAtten
M_PSA_SetExtAtten::M_PSA_SetExtAtten()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪外部衰减偏移量");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetExtAtten::~M_PSA_SetExtAtten()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetExtAtten::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "exatten");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetExtAtten::Run(void)
{
	double exatten;
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

	exatten = atof(m_InputPara->paramVal);
	return PSA_SetExtAtten(vHandle,exatten);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetIntPreampOff
M_PSA_SetIntPreampOff::M_PSA_SetIntPreampOff()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪预放状态(0:Off 1:On)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetIntPreampOff::~M_PSA_SetIntPreampOff()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetIntPreampOff::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "state");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetIntPreampOff::Run(void)
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
	return PSA_SetIntPreampOff(vHandle,state);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetLevelRange
M_PSA_SetLevelRange::M_PSA_SetLevelRange()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪Y轴显示电平范围(//R&S 10~200dB)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetLevelRange::~M_PSA_SetLevelRange()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetLevelRange::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "levelrange");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"100");
	sprintf(m_InputPara->paramUnit , "dB");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetLevelRange::Run(void)
{
	short levelrange;
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

	levelrange = atoi(m_InputPara->paramVal);
	return PSA_SetLevelRange(vHandle,levelrange);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetAverCount
M_PSA_SetAverCount::M_PSA_SetAverCount()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪平均次数");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetAverCount::~M_PSA_SetAverCount()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetAverCount::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "count");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetAverCount::Run(void)
{
	unsigned short count;
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

	count = atoi(m_InputPara->paramVal);
	return PSA_SetAverCount(vHandle,count);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetAverType
M_PSA_SetAverType::M_PSA_SetAverType()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪平均类型(安捷伦 0:RMS 1:SCAL 2:LOG; 罗德 0:VIDeo 1:LINear)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetAverType::~M_PSA_SetAverType()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetAverType::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "type");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetAverType::Run(void)
{
	unsigned short type;
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
	return PSA_SetAverType(vHandle,type);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetAverState
M_PSA_SetAverState::M_PSA_SetAverState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪平均状态(0:off 1:on)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetAverState::~M_PSA_SetAverState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetAverState::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "state");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetAverState::Run(void)
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
	return PSA_SetAverState(vHandle,state);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetRBW
M_PSA_SetRBW::M_PSA_SetRBW()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪RBW值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetRBW::~M_PSA_SetRBW()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetRBW::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "RBWvalue");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"100000");
	sprintf(m_InputPara->paramUnit , "Hz");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetRBW::Run(void)
{
	double value;
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
	
	value = atof(m_InputPara->paramVal);
	return PSA_SetRBW(vHandle,value);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetVBW
M_PSA_SetVBW::M_PSA_SetVBW()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪VBW值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetVBW::~M_PSA_SetVBW()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetVBW::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "VBWvalue");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"100000");
	sprintf(m_InputPara->paramUnit , "Hz");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetVBW::Run(void)
{
	double value;
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

	value = atof(m_InputPara->paramVal);
	return PSA_SetVBW(vHandle,value);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetDetectorMode
M_PSA_SetDetectorMode::M_PSA_SetDetectorMode()
:BaseMethod()
{
	sprintf(m_MethodScript,	"设置频谱仪检波模式(//Agilent 0:normal|Auto 1:average 2:Peak 3:sample 4:negative Peak 5:Quasi peak 6:EMI average 7:EMI  8:MIL 9:RMS\n");
	sprintf(m_MethodScript,	"%s%s", m_MethodScript, " //R&S 0:Auto On 1:Average 2:Peak 3:sample 4:Negative 5:Quasi peak 9:RMS");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetDetectorMode::~M_PSA_SetDetectorMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetDetectorMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "mode");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"9");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetDetectorMode::Run(void)
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
	return PSA_SetDetectorMode(vHandle,mode);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetSweepTime
M_PSA_SetSweepTime::M_PSA_SetSweepTime()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪扫描时间");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetSweepTime::~M_PSA_SetSweepTime()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetSweepTime::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "sweeptime");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetSweepTime::Run(void)
{
	double sweeptime;
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

	sweeptime = atof(m_InputPara->paramVal);
	return PSA_SetSweepTime(vHandle,sweeptime);
		
}
//class M_PSA_SetAUTOSweepTime
M_PSA_SetAUTOSweepTime::M_PSA_SetAUTOSweepTime()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪自动扫描状态(0:off 1:on)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetAUTOSweepTime::~M_PSA_SetAUTOSweepTime()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetAUTOSweepTime::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "state");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetAUTOSweepTime::Run(void)
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
	return PSA_SetAUTOSweepTime(vHandle,state);
	return NTS_SUCCESS;
	
}
//class M_PSA_SetSweepTimeMode
M_PSA_SetSweepTimeMode::M_PSA_SetSweepTimeMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪扫描模式(0:single 1:continous)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetSweepTimeMode::~M_PSA_SetSweepTimeMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetSweepTimeMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "mode");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetSweepTimeMode::Run(void)
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
	return PSA_SetSweepTimeMode(vHandle,mode);
	return NTS_SUCCESS;
}
//class M_PSA_SetTraceMaxHold
M_PSA_SetTraceMaxHold::M_PSA_SetTraceMaxHold()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置踪迹为MAX HOLD估值方式");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetTraceMaxHold::~M_PSA_SetTraceMaxHold()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetTraceMaxHold::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetTraceMaxHold::Run(void)
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

	return PSA_SetTraceMaxHold(vHandle);
}
//class M_PSA_SetTraceMinHold
M_PSA_SetTraceMinHold::M_PSA_SetTraceMinHold()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置踪迹为MIN HOLD估值方式");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetTraceMinHold::~M_PSA_SetTraceMinHold()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetTraceMinHold::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetTraceMinHold::Run(void)
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
	
	return PSA_SetTraceMinHold(vHandle);
	return NTS_SUCCESS;
}
//class M_PSA_SetTraceClearWrite
M_PSA_SetTraceClearWrite::M_PSA_SetTraceClearWrite()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置踪迹为Clear Write估值方式");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetTraceClearWrite::~M_PSA_SetTraceClearWrite()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetTraceClearWrite::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetTraceClearWrite::Run(void)
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

	return PSA_SetTraceClearWrite(vHandle);
	return NTS_SUCCESS;
}
//class M_PSA_GetTraceData
M_PSA_GetTraceData::M_PSA_GetTraceData()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取整条踪迹数据值");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	

	Init();
}
M_PSA_GetTraceData::~M_PSA_GetTraceData()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara);

}

int M_PSA_GetTraceData::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	
	sprintf(m_OutputPara->paramName, "TraceData");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
	
}
int M_PSA_GetTraceData::Run(void)
{
	double Data[1024*10] = {0};
	long Count;
	int retVal,i = 0;
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
	
	retVal = PSA_GetTraceData(vHandle, Data, &Count);
	if(retVal == NTS_SUCCESS)
	{
		m_OutputPara->LparamVal = (char *) malloc(Count * 20 * sizeof(char));
		memset(m_OutputPara->LparamVal, 0, Count * 20);
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
//class M_PSA_SetTrigSource
M_PSA_SetTrigSource::M_PSA_SetTrigSource()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪触发源(0:IMM 1:EXT1 2:RF Burst 3:EXT2)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetTrigSource::~M_PSA_SetTrigSource()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetTrigSource::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "mode");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");	
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetTrigSource::Run(void)
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
	return PSA_SetTrigSource(vHandle,mode);
	
}
//class M_PSA_SetMarkMax
M_PSA_SetMarkMax::M_PSA_SetMarkMax()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪最大MARKER点");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetMarkMax::~M_PSA_SetMarkMax()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetMarkMax::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "markerindex");
	m_InputPara->paramType = NTSInt32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetMarkMax::Run(void)
{
	long index;
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
	return PSA_SetMarkMax(vHandle,index);
	return NTS_SUCCESS;
}
//class M_PSA_SetMarkMin
M_PSA_SetMarkMin::M_PSA_SetMarkMin()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪最小MARKER点");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetMarkMin::~M_PSA_SetMarkMin()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetMarkMin::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "markerindex");
	m_InputPara->paramType = NTSInt32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetMarkMin::Run(void)
{
	long index;
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
	return PSA_SetMarkMin(vHandle,index);
	return NTS_SUCCESS;
}
//class M_PSA_SetMaxNext 
M_PSA_SetMaxNext::M_PSA_SetMaxNext()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪下一个最大MARKER点");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetMaxNext::~M_PSA_SetMaxNext()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetMaxNext::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "markerindex");
	m_InputPara->paramType = NTSInt32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetMaxNext::Run(void)
{
	long index;
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
	return PSA_SetMaxNext(vHandle,index);
	return NTS_SUCCESS;
}
//class M_PSA_SetMarkState
M_PSA_SetMarkState::M_PSA_SetMarkState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪MARKER点状态(0:off 1:on)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();	
	m_InputPara2= CreateParamStruct();
	Init();
}
M_PSA_SetMarkState::~M_PSA_SetMarkState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_SetMarkState::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "markerindex");
	m_InputPara1->paramType = NTSInt32;
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
int M_PSA_SetMarkState::Run(void)
{
	long index;
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

	index = atoi(m_InputPara1->paramVal);
	state = atoi(m_InputPara2->paramVal);
	return PSA_SetMarkState(vHandle,index,state);
	return NTS_SUCCESS;
}
//class M_PSA_SetMarkPosition
M_PSA_SetMarkPosition::M_PSA_SetMarkPosition()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪MARKER点频率");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();	
	m_InputPara2= CreateParamStruct();	
	Init();
}
M_PSA_SetMarkPosition::~M_PSA_SetMarkPosition()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_SetMarkPosition::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "markerindex");
	m_InputPara1->paramType = NTSInt32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "freqence");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"2017.4");
	sprintf(m_InputPara2->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_PSA_SetMarkPosition::Run(void)
{
	long index;
	double freq;
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
	freq = atof(m_InputPara2->paramVal);
	return PSA_SetMarkPosition(vHandle,index,freq);
	return NTS_SUCCESS;
}
//class M_PSA_SetMarkerMode
M_PSA_SetMarkerMode::M_PSA_SetMarkerMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪MARKER点类型(0:normal 1:delta)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();	
	m_InputPara2= CreateParamStruct();	
	Init();
}
M_PSA_SetMarkerMode::~M_PSA_SetMarkerMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_SetMarkerMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "markerindex");
	m_InputPara1->paramType = NTSInt32;
	m_InputPara1->paramCount =1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "mode");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_PSA_SetMarkerMode::Run(void)
{
	long index;
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

	index = atoi(m_InputPara1->paramVal);
	mode = atoi(m_InputPara2->paramVal);
	return PSA_SetMarkerMode(vHandle,index,mode);
}
//class M_PSA_GetMarkValue
M_PSA_GetMarkValue::M_PSA_GetMarkValue()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取频谱仪MARKER点值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	m_OutputPara= CreateParamStruct();	
	Init();
}
M_PSA_GetMarkValue::~M_PSA_GetMarkValue()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
//	free(m_OutputPara);
}

int M_PSA_GetMarkValue::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "markerindex");
	m_InputPara->paramType = NTSInt32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	sprintf(m_OutputPara->paramName, "value");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_PSA_GetMarkValue::Run(void)
{
	long index;
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

	index = atoi(m_InputPara->paramVal);
	retVal = PSA_GetMarkValue(vHandle,index,&data);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%e",data);
	}
	return retVal;
}
/*
//class M_PSA_SetTDPWRMODE
M_PSA_SetTDPWRMODE::M_PSA_SetTDPWRMODE()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪为TD功率模式，在此之前请先调用OpenDevice(PSADevice,...)创建频谱仪设备句柄。");
	Init();
}
M_PSA_SetTDPWRMODE::~M_PSA_SetTDPWRMODE()
{

}

int M_PSA_SetTDPWRMODE::Init(void)
{
	return NTS_SUCCESS;
}
int M_PSA_SetTDPWRMODE::Run(void)
{
	if(vHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	return PSA_SetTDPWRMODE(vHandle);
	return NTS_SUCCESS;
}
*/
//class M_PSA_SetTDPOWSLOT
M_PSA_SetTDPOWSLOT::M_PSA_SetTDPOWSLOT()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪TD功率模式下的时隙值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetTDPOWSLOT::~M_PSA_SetTDPOWSLOT()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetTDPOWSLOT::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "slot");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetTDPOWSLOT::Run(void)
{
	short slot;
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

	slot = atoi(m_InputPara->paramVal);
	return PSA_SetTDPOWSLOT(vHandle,slot);
}
/*
//class M_PSA_SetTDMODMODE
M_PSA_SetTDMODMODE::M_PSA_SetTDMODMODE()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪为TD解调模式，在此之前请先调用OpenDevice(PSADevice,...)创建频谱仪设备句柄。");

	Init();
}
M_PSA_SetTDMODMODE::~M_PSA_SetTDMODMODE()
{
}

int M_PSA_SetTDMODMODE::Init(void)
{
	return NTS_SUCCESS;
}
int M_PSA_SetTDMODMODE::Run(void)
{

	if(vHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	return PSA_SetTDMODMODE(vHandle);

}
*/
//class M_PSA_GetEVMandPCDE
M_PSA_GetEVMandPCDE::M_PSA_GetEVMandPCDE()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取频谱仪的EVM和PCDE值");
	m_OutputPara1= CreateParamStruct();	
	m_OutputPara2= CreateParamStruct();	
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_GetEVMandPCDE::~M_PSA_GetEVMandPCDE()
{
//	free(m_OutputPara1);
//	free(m_OutputPara2);
//	free(m_InputDeviceName);
}

int M_PSA_GetEVMandPCDE::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_OutputPara1->paramName, "EVM");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
		
	sprintf(m_OutputPara2->paramName, "PCDE");
	m_OutputPara2->paramType = NTSReal32;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara2);
	
	return NTS_SUCCESS;
}
int M_PSA_GetEVMandPCDE::Run(void)
{
	double evm,pcde;
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

	retVal = PSA_GetEVMandPCDE(vHandle,&evm,&pcde);
	if(retVal==NTS_SUCCESS)
	{
		sprintf( m_OutputPara1->paramVal,"%e",evm);
		sprintf( m_OutputPara2->paramVal,"%e",pcde);
	}
	return retVal;
}

//class M_PSA_SetSPECMODE
M_PSA_SetSPECMODE::M_PSA_SetSPECMODE()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪为频谱模式");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetSPECMODE::~M_PSA_SetSPECMODE()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetSPECMODE::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetSPECMODE::Run(void)
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

	return PSA_SetSPECMODE(vHandle);

}
//class M_PSA_SetStarandStopFreq
M_PSA_SetStarandStopFreq::M_PSA_SetStarandStopFreq()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪起止频率");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();	
	m_InputPara2= CreateParamStruct();
	Init();
}
M_PSA_SetStarandStopFreq::~M_PSA_SetStarandStopFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_SetStarandStopFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "startfreq");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"500");
	sprintf(m_InputPara1->paramUnit , "Hz");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "stopfreq");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"3000000000");
	sprintf(m_InputPara2->paramUnit , "Hz");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_PSA_SetStarandStopFreq::Run(void)
{
	double startfreq,stopfreq;
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
	return PSA_SetStarandStopFreq(vHandle,startfreq,stopfreq);
}
//class M_PSA_SetMULACPRMeas
M_PSA_SetMULACPRMeas::M_PSA_SetMULACPRMeas()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪为多载波测量模式(TD-MCP)");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetMULACPRMeas::~M_PSA_SetMULACPRMeas()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetMULACPRMeas::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetMULACPRMeas::Run(void)
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

	return PSA_SetMULACPRMeas(vHandle);
}
//class M_PSA_SetMCCOUNT
M_PSA_SetMCCOUNT::M_PSA_SetMCCOUNT()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪多载波模式下的载波数");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetMCCOUNT::~M_PSA_SetMCCOUNT()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetMCCOUNT::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "count");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetMCCOUNT::Run(void)
{
	unsigned short count;
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

	count = atoi(m_InputPara->paramVal);
	return PSA_SetMCCOUNT(vHandle,count);
}
//class M_PSA_GetMULACPR
M_PSA_GetMULACPR::M_PSA_GetMULACPR()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取频谱仪多载波模式的测量值");
	m_InputDeviceName = CreateParamStruct();
	for(int i = 0 ;i<5;i++)
	{
		m_OutputPara[i]= CreateParamStruct();	
	}
	Init();
}
M_PSA_GetMULACPR::~M_PSA_GetMULACPR()
{
/*	free(m_InputDeviceName);
	for(int i = 0 ;i<5;i++)
	{
		free(m_OutputPara[i]);
	}
	*/
}

int M_PSA_GetMULACPR::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_OutputPara[0]->paramName, "totalpower");
	m_OutputPara[0]->paramType = NTSReal32;
	m_OutputPara[0]->paramCount = 1;
	sprintf(m_OutputPara[0]->paramVal,"0");
	sprintf(m_OutputPara[0]->paramUnit , "dBm");
	m_OutputParamVector.push_back(m_OutputPara[0]);

	sprintf(m_OutputPara[1]->paramName, "ACPR_-1.6MHz");
	m_OutputPara[1]->paramType = NTSReal32;
	m_OutputPara[1]->paramCount = 1;
	sprintf(m_OutputPara[1]->paramVal,"");
	sprintf(m_OutputPara[1]->paramUnit , "dB");
	m_OutputParamVector.push_back(m_OutputPara[1]);

	sprintf(m_OutputPara[2]->paramName, "ACPR_+1.6MHz");
	m_OutputPara[2]->paramType = NTSReal32;
	m_OutputPara[2]->paramCount = 1;
	sprintf(m_OutputPara[2]->paramVal,"");
	sprintf(m_OutputPara[2]->paramUnit , "dB");
	m_OutputParamVector.push_back(m_OutputPara[2]);

	sprintf(m_OutputPara[3]->paramName, "ACPR_-3.2MHz");
	m_OutputPara[3]->paramType = NTSReal32;
	m_OutputPara[3]->paramCount = 1;
	sprintf(m_OutputPara[3]->paramVal,"");
	sprintf(m_OutputPara[3]->paramUnit , "dB");
	m_OutputParamVector.push_back(m_OutputPara[3]);

	sprintf(m_OutputPara[4]->paramName, "ACPR_+3.2MHz");
	m_OutputPara[4]->paramType = NTSReal32;
	m_OutputPara[4]->paramCount = 1;
	sprintf(m_OutputPara[4]->paramVal,"");
	sprintf(m_OutputPara[4]->paramUnit , "dB");
	m_OutputParamVector.push_back(m_OutputPara[4]);
	
	return NTS_SUCCESS;
}
int M_PSA_GetMULACPR::Run(void)
{
	double data[300];
	long count;
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

	retVal = PSA_GetMULACPR(vHandle, data, &count);
	if(retVal==NTS_SUCCESS)
	{
//		sprintf(m_OutputPara[0]->paramVal, "%e",data[35]);//total power
//		sprintf(m_OutputPara[1]->paramVal, "%e",data[23]);//-1.6MHz
//		sprintf(m_OutputPara[2]->paramVal, "%e",data[25]);//+1.6MHz
//		sprintf(m_OutputPara[3]->paramVal, "%e",data[27]);//-3.2MHz
//		sprintf(m_OutputPara[4]->paramVal, "%e",data[29]);//+3.2MHz
		sprintf(m_OutputPara[0]->paramVal, "%e",data[0]); //total power
		sprintf(m_OutputPara[1]->paramVal, "%e",data[1]); //-1.6MHz
		sprintf(m_OutputPara[2]->paramVal, "%e",data[2]); //+1.6MHz
		sprintf(m_OutputPara[3]->paramVal, "%e",data[3]); //-3.2MHz
		sprintf(m_OutputPara[4]->paramVal, "%e",data[4]); //+3.2MHz
	}
	return retVal;
}
//class M_PSA_SetMCPAVER
M_PSA_SetMCPAVER::M_PSA_SetMCPAVER()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪多载波模式下平均次数和平均状态(0:off 1:on)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();	
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_PSA_SetMCPAVER::~M_PSA_SetMCPAVER()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_SetMCPAVER::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "state");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "count");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_PSA_SetMCPAVER::Run(void)
{
	unsigned short state;
	long count;
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

	state = atoi(m_InputPara1->paramVal);
	count = atoi(m_InputPara2->paramVal);
	return PSA_SetMCPAVER(vHandle,state,count);
}
//class M_PSA_SetSEMMeas
M_PSA_SetSEMMeas::M_PSA_SetSEMMeas()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪为频谱发射模板测试模式(TD-SEM)");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetSEMMeas::~M_PSA_SetSEMMeas()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetSEMMeas::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetSEMMeas::Run(void)
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

	return PSA_SetSEMMeas(vHandle);
}
//class M_PSA_SetInitSEM
M_PSA_SetInitSEM::M_PSA_SetInitSEM()
:BaseMethod()
{
	sprintf(m_MethodScript, "触发一次频谱发射模板测试");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetInitSEM::~M_PSA_SetInitSEM()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetInitSEM::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	return NTS_SUCCESS;
}
int M_PSA_SetInitSEM::Run(void)
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

	return PSA_SetInitSEM(vHandle);
}
//class M_PSA_SetSEMAverageEnable
M_PSA_SetSEMAverageEnable::M_PSA_SetSEMAverageEnable()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪频谱发射模板模式下的平均状态(0:off 1:on)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetSEMAverageEnable::~M_PSA_SetSEMAverageEnable()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetSEMAverageEnable::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "state");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetSEMAverageEnable::Run(void)
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
	return PSA_SetSEMAverageEnable(vHandle,state);
}
//class M_PSA_SetSEMLimits
M_PSA_SetSEMLimits::M_PSA_SetSEMLimits()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪频谱发射模板的类型(0:STD 1:MAN)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetSEMLimits::~M_PSA_SetSEMLimits()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetSEMLimits::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "type");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetSEMLimits::Run(void)
{
	unsigned short type;
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
	return PSA_SetSEMLimits(vHandle,type);
}
//class M_PSA_GetSEM
M_PSA_GetSEM::M_PSA_GetSEM()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取频谱仪频谱发射模板测量的结果(0:PASS 1:FAIL)");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara= CreateParamStruct();	
	Init();
}
M_PSA_GetSEM::~M_PSA_GetSEM()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara);
}

int M_PSA_GetSEM::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_OutputPara->paramName, "state");
	m_OutputPara->paramType = NTSInt16;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_PSA_GetSEM::Run(void)
{
	int state;
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

	retVal = PSA_GetSEM(vHandle,&state);
	if(retVal ==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%d",state);

	}
	return retVal;
}
//class M_PSA_SetEVMMeas
M_PSA_SetEVMMeas::M_PSA_SetEVMMeas()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪为EVM和PCDE测量模式");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetEVMMeas::~M_PSA_SetEVMMeas()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetEVMMeas::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	return NTS_SUCCESS;
}
int M_PSA_SetEVMMeas::Run(void)
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

	return PSA_SetEVMMeas(vHandle);
}
//class M_PSA_SetEVMSlot
M_PSA_SetEVMSlot::M_PSA_SetEVMSlot()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置EVM和PCDE模式下的时隙");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetEVMSlot::~M_PSA_SetEVMSlot()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetEVMSlot::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "slot");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetEVMSlot::Run(void)
{
	unsigned short slot;
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

	slot = atoi(m_InputPara->paramVal);
	return PSA_SetEVMSlot(vHandle,slot);
}
//class M_PSA_SetInitEVM
M_PSA_SetInitEVM::M_PSA_SetInitEVM()
:BaseMethod()
{
	sprintf(m_MethodScript, "触发一次EVM和PCDE测量");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetInitEVM::~M_PSA_SetInitEVM()
{
//	free(m_InputDeviceName);
	
}

int M_PSA_SetInitEVM::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetInitEVM::Run(void)
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

	
	return PSA_SetInitEVM(vHandle);
}
/*
//class M_PSA_GetEVM
M_PSA_GetEVM::M_PSA_GetEVM()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取频谱仪EVM和PCDE模式下的EVM值，在此之前请先调用OpenDevice(PSADevice,...)创建频谱仪设备句柄。");
	m_OutputPara= CreateParamStruct();	
	Init();
}
M_PSA_GetEVM::~M_PSA_GetEVM()
{
	free(m_OutputPara);
}

int M_PSA_GetEVM::Init(void)
{
	m_OutputPara->paramName, "evm";
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	m_OutputPara->paramUnit , "";
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_PSA_GetEVM::Run(void)
{
	double evm;
	int retVal;
	if(vHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	
	retVal = PSA_GetEVM(vHandle,&evm);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%e",evm);
	}
	return retVal;
}
//class M_PSA_GetPCDE
M_PSA_GetPCDE::M_PSA_GetPCDE()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取频谱仪EVM和PCDE模式下的PCDE值，在此之前请先调用OpenDevice(PSADevice,...)创建频谱仪设备句柄。");
	m_OutputPara= CreateParamStruct();	
	Init();
}
M_PSA_GetPCDE::~M_PSA_GetPCDE()
{
	free(m_OutputPara);
}

int M_PSA_GetPCDE::Init(void)
{
	m_OutputPara->paramName, "pcde";
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	m_OutputPara->paramUnit , "";
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_PSA_GetPCDE::Run(void)
{
	double pcde;
	int retVal;
	if(vHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	
	retVal = PSA_GetPCDE(vHandle,&pcde);
	if(retVal == NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%e",pcde);
	}
	return retVal;
}
*/

//class M_PSA_SetSyncType
M_PSA_SetSyncType::M_PSA_SetSyncType()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪EVM和PCDE模式下的同步类型(0:PILot 1:MIDamble)和同步触发方式(0:DPTS 1:UPTS 2:TRIG)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_PSA_SetSyncType::~M_PSA_SetSyncType()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_SetSyncType::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "type");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "trigmode");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_PSA_SetSyncType::Run(void)
{
	unsigned short type,mode;
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

	type = atoi(m_InputPara1->paramVal);
	mode = atoi(m_InputPara2->paramVal);
	return PSA_SetSyncType(vHandle,type,mode);
}
//class M_PSA_SetTOI
M_PSA_SetTOI::M_PSA_SetTOI()
:BaseMethod()
{
	sprintf(m_MethodScript, "打开频谱仪的三阶截取点");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetTOI::~M_PSA_SetTOI()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetTOI::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetTOI::Run(void)
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

	return PSA_SetTOI(vHandle);
}
//class M_PSA_GetTOI
M_PSA_GetTOI::M_PSA_GetTOI()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取频谱仪三阶交调模式下的测量值");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara[0]= CreateParamStruct();	
	m_OutputPara[1]= CreateParamStruct();	
	m_OutputPara[2]= CreateParamStruct();	
	m_OutputPara[3]= CreateParamStruct();	
	Init();
}
M_PSA_GetTOI::~M_PSA_GetTOI()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara[0]);
//	free(m_OutputPara[1]);
//	free(m_OutputPara[2]);
//	free(m_OutputPara[3]);
}

int M_PSA_GetTOI::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_OutputPara[0]->paramName, "value1");
	m_OutputPara[0]->paramType = NTSReal32;
	m_OutputPara[0]->paramCount = 1;
	sprintf(m_OutputPara[0]->paramVal,"");
	sprintf(m_OutputPara[0]->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara[0]);

	sprintf(m_OutputPara[1]->paramName, "value2");
	m_OutputPara[1]->paramType = NTSReal32;
	m_OutputPara[1]->paramCount = 1;
	sprintf(m_OutputPara[1]->paramVal,"");
	sprintf(m_OutputPara[1]->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara[1]);

	sprintf(m_OutputPara[2]->paramName, "value3");
	m_OutputPara[2]->paramType = NTSReal32;
	m_OutputPara[2]->paramCount = 1;
	sprintf(m_OutputPara[2]->paramVal,"");
	sprintf(m_OutputPara[2]->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara[2]);

	sprintf(m_OutputPara[3]->paramName, "value4");
	m_OutputPara[3]->paramType = NTSReal32;
	m_OutputPara[3]->paramCount = 1;
	sprintf(m_OutputPara[3]->paramVal,"");
	sprintf(m_OutputPara[3]->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara[3]);
	return NTS_SUCCESS;
}
int M_PSA_GetTOI::Run(void)
{
	double data[100];
	int retVal;
	long count;
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
	
	retVal = PSA_GetTOI(vHandle,data,&count);
	if(retVal ==NTS_SUCCESS)
	{
		sprintf(m_OutputPara[0]->paramVal,"%e",data[0]);
		sprintf(m_OutputPara[1]->paramVal,"%e",data[1]);
		sprintf(m_OutputPara[2]->paramVal,"%e",data[2]);
		sprintf(m_OutputPara[3]->paramVal,"%e",data[3]);
		
	}
	return retVal;
}
/*
//class M_PSA_SetTOIAVGState
M_PSA_SetTOIAVGState::M_PSA_SetTOIAVGState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪三阶交调模式下平均状态(0:off 1:on)");
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetTOIAVGState::~M_PSA_SetTOIAVGState()
{
	free(m_InputPara);
}

int M_PSA_SetTOIAVGState::Init(void)
{
	m_InputPara->paramName, "state";
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	m_InputPara->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetTOIAVGState::Run(void)
{
	unsigned short state;
	if(vHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	state = atoi(m_InputPara->paramVal);
	return PSA_SetTOIAVGState(vHandle,state);
}
*/

//class M_PSA_SetPVTMeas
M_PSA_SetPVTMeas::M_PSA_SetPVTMeas()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪为时间开关测量模式(TD-PVT)");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetPVTMeas::~M_PSA_SetPVTMeas()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetPVTMeas::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetPVTMeas::Run(void)
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

	return PSA_SetPVTMeas(vHandle);
}
//class M_PSA_SetInitPVT
M_PSA_SetInitPVT::M_PSA_SetInitPVT()
:BaseMethod()
{
	sprintf(m_MethodScript, "触发一次时间开关模板测量");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetInitPVT::~M_PSA_SetInitPVT()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetInitPVT::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetInitPVT::Run(void)
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
	
	return PSA_SetInitPVT(vHandle);
}
//class M_PSA_GetPVT
M_PSA_GetPVT::M_PSA_GetPVT()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取频谱仪时间开关模板模式下的功率值");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara= CreateParamStruct();	
	Init();
}
M_PSA_GetPVT::~M_PSA_GetPVT()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara);
}

int M_PSA_GetPVT::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_OutputPara->paramName, "power");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "dBm");
	m_OutputParamVector.push_back(m_OutputPara);

	return NTS_SUCCESS;
}
int M_PSA_GetPVT::Run(void)
{
	double data[100];
	long count;
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

	retVal = PSA_GetPVT(vHandle,data,&count);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%e",data[0]);
	}
	return retVal;
}
//class M_PSA_SetPVTAverageEnable
M_PSA_SetPVTAverageEnable::M_PSA_SetPVTAverageEnable()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪时间开关模板模式平均状态(0:off 1:on)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetPVTAverageEnable::~M_PSA_SetPVTAverageEnable()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetPVTAverageEnable::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "state");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetPVTAverageEnable::Run(void)
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
	return PSA_SetPVTAverageEnable(vHandle,state);
}
//class M_PSA_SetPVTMEASTimes
M_PSA_SetPVTMEASTimes::M_PSA_SetPVTMEASTimes()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪时间开关模板测量的时隙总数");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetPVTMEASTimes::~M_PSA_SetPVTMEASTimes()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetPVTMEASTimes::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "times");
	m_InputPara->paramType = NTSInt32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetPVTMEASTimes::Run(void)
{
	long times;
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

	times = atoi(m_InputPara->paramVal);
	return PSA_SetPVTMEASTimes(vHandle,times);
}
//class M_PSA_SetACPMeas
M_PSA_SetACPMeas::M_PSA_SetACPMeas()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪为单载波测量模式(TD-ACP)");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetACPMeas::~M_PSA_SetACPMeas()
{
//  free(m_InputDeviceName);
}

int M_PSA_SetACPMeas::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	return NTS_SUCCESS;
}
int M_PSA_SetACPMeas::Run(void)
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

	return PSA_SetACPMeas(vHandle);
}
//class M_PSA_GetACP
M_PSA_GetACP::M_PSA_GetACP()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取频谱仪单载波模式下的功率值");
	
	m_InputDeviceName  = CreateParamStruct();
	m_OutputPara[0]= CreateParamStruct();	
	m_OutputPara[1]= CreateParamStruct();	
	m_OutputPara[2]= CreateParamStruct();	
	m_OutputPara[3]= CreateParamStruct();	
	m_OutputPara[4]= CreateParamStruct();	
	Init();
}
M_PSA_GetACP::~M_PSA_GetACP()
{
	
//	free(m_InputDeviceName);
//	free(m_OutputPara[0]);
//	free(m_OutputPara[1]);
//	free(m_OutputPara[2]);
//	free(m_OutputPara[3]);
//	free(m_OutputPara[4]);
}

int M_PSA_GetACP::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_OutputPara[0]->paramName, "totalpower");
	m_OutputPara[0]->paramType = NTSReal32;
	m_OutputPara[0]->paramCount = 1;
	sprintf(m_OutputPara[0]->paramVal,"0");
	sprintf(m_OutputPara[0]->paramUnit , "dBm");
	m_OutputParamVector.push_back(m_OutputPara[0]);
	
	sprintf(m_OutputPara[1]->paramName, "ACPR_-1.6MHz");
	m_OutputPara[1]->paramType = NTSReal32;
	m_OutputPara[1]->paramCount = 1;
	sprintf(m_OutputPara[1]->paramVal,"");
	sprintf(m_OutputPara[1]->paramUnit , "dB");
	m_OutputParamVector.push_back(m_OutputPara[1]);
	
	sprintf(m_OutputPara[2]->paramName, "ACPR_+1.6MHz");
	m_OutputPara[2]->paramType = NTSReal32;
	m_OutputPara[2]->paramCount = 1;
	sprintf(m_OutputPara[2]->paramVal,"");
	sprintf(m_OutputPara[2]->paramUnit , "dB");
	m_OutputParamVector.push_back(m_OutputPara[2]);
	
	sprintf(m_OutputPara[3]->paramName, "ACPR_-3.2MHz");
	m_OutputPara[3]->paramType = NTSReal32;
	m_OutputPara[3]->paramCount = 1;
	sprintf(m_OutputPara[3]->paramVal,"");
	sprintf(m_OutputPara[3]->paramUnit , "dB");
	m_OutputParamVector.push_back(m_OutputPara[3]);
	
	sprintf(m_OutputPara[4]->paramName, "ACPR_+3.2MHz");
	m_OutputPara[4]->paramType = NTSReal32;
	m_OutputPara[4]->paramCount = 1;
	sprintf(m_OutputPara[4]->paramVal,"");
	sprintf(m_OutputPara[4]->paramUnit , "dB");
	m_OutputParamVector.push_back(m_OutputPara[4]);

	
	return NTS_SUCCESS;
}
int M_PSA_GetACP::Run(void)
{
	double data[100];
	long count;
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

	retVal = PSA_GetACP(vHandle,data,&count);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara[0]->paramVal, "%e", data[0]); //total power
		sprintf(m_OutputPara[1]->paramVal, "%e", data[1]); //-1.6MHz
		sprintf(m_OutputPara[2]->paramVal, "%e", data[2]); //+1.6MHz
		sprintf(m_OutputPara[3]->paramVal, "%e", data[3]); //-3.2MHz
		sprintf(m_OutputPara[4]->paramVal, "%e", data[4]); //+3.2MHz
	}
	return retVal;
}
/*
//class M_PSA_SetWindow
M_PSA_SetWindow::M_PSA_SetWindow()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪显示窗口(1 or 2)，默认为1，在此之前请先调用OpenDevice(PSADevice,...)创建频谱仪设备句柄。");
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetWindow::~M_PSA_SetWindow()
{
	free(m_InputPara);
}

int M_PSA_SetWindow::Init(void)
{
	m_InputPara->paramName, "windowindex";
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	m_InputPara->paramUnit , "";
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetWindow::Run(void)
{
	unsigned short index;
	
	if(vHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	index = atoi(m_InputPara->paramVal);
	return PSA_SetWindow(vHandle,index);
}
*/

//class M_PSA_SetTrigDelayTime
M_PSA_SetTrigDelayTime::M_PSA_SetTrigDelayTime()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪触发延迟时间");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetTrigDelayTime::~M_PSA_SetTrigDelayTime()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetTrigDelayTime::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
int M_PSA_SetTrigDelayTime::Run(void)
{
	double delaytime;
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
	return PSA_SetTrigDelayTime(vHandle,delaytime);
}
//class M_PSA_SetTraceAverage
M_PSA_SetTraceAverage::M_PSA_SetTraceAverage()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪踪迹为平均估值模式");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetTraceAverage::~M_PSA_SetTraceAverage()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetTraceAverage::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetTraceAverage::Run(void)
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

	return PSA_SetTraceAverage(vHandle);
}

//M_PSA_SetEVMAver
M_PSA_SetEVMAver::M_PSA_SetEVMAver()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪EVM和PCDE模式下的平均次数和状态(0:off 1:on)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_PSA_SetEVMAver::~M_PSA_SetEVMAver()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_SetEVMAver::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "count");
	m_InputPara1->paramType = NTSUInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "State");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_PSA_SetEVMAver::Run(void)
{
	unsigned short count,state;
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

	count = atoi(m_InputPara1->paramVal);
	state = atoi(m_InputPara2->paramVal);
	return PSA_SetEVMAver(vHandle,count,state);
}
//M_PSA_SetFilterType
M_PSA_SetFilterType::M_PSA_SetFilterType()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪的耦合方式(//R&S 0:NORMal1:FFT 2:CFILter 3:RRC 4:NOISe 5:PULSe 6:P5 //Agilent:无效)");
	m_InputDeviceName  = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_PSA_SetFilterType::~M_PSA_SetFilterType()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetFilterType::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "type");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	return NTS_SUCCESS;
}
int M_PSA_SetFilterType::Run(void)
{
	unsigned short type;
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
	return PSA_SetFilterType(vHandle,type);
}
//M_PSA_SetScrambleCode
M_PSA_SetScrambleCode::M_PSA_SetScrambleCode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置EVM和PCDE模式下的扰码(//Agilent: N9010A支持 //罗德:有效)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_PSA_SetScrambleCode::~M_PSA_SetScrambleCode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetScrambleCode::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "ScrambleCode");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	return NTS_SUCCESS;
}
int M_PSA_SetScrambleCode::Run(void)
{
	short scramblecode;
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

	scramblecode = atoi(m_InputPara->paramVal);
	return PSA_SetScrambleCode(vHandle,scramblecode);
}
//class M_PSA_GetFluctuate
M_PSA_GetFluctuate::M_PSA_GetFluctuate()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取指定带宽范围内的波动");
	m_InputPara = CreateParamStruct();
	m_InputDeviceName = CreateParamStruct();
	
	m_OutputPara = CreateParamStruct();
	Init();
}
M_PSA_GetFluctuate::~M_PSA_GetFluctuate()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
//	free(m_OutputPara);
}

int M_PSA_GetFluctuate::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "bandwidtd");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara);

	sprintf(m_OutputPara->paramName, "fluctuate");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "dB");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_PSA_GetFluctuate::Run(void)
{
	int retval;
	double bandwidth;
	double fluctuate;
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

	bandwidth = atof(m_InputPara->paramVal);
	
	retval = PSA_GetFluctuate(vHandle, bandwidth, &fluctuate);
	if(retval==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%e",fluctuate);
	}
	return retval;
}

//class M_PSA_SetMarkTime
M_PSA_SetMarkTime::M_PSA_SetMarkTime()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪在时域下MARKER点的位置");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();	
	m_InputPara2= CreateParamStruct();	
	Init();
}
M_PSA_SetMarkTime::~M_PSA_SetMarkTime()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_SetMarkTime::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "markerindex");
	m_InputPara1->paramType = NTSInt32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "time");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_PSA_SetMarkTime::Run(void)
{
	long index;
	double time;
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
	time = atof(m_InputPara2->paramVal);
	return PSA_SetMarkTime(vHandle,index,time);
	return NTS_SUCCESS;
}
//class M_PSA_SetSweepEgatePolarity
M_PSA_SetSweepEgatePolarity::M_PSA_SetSweepEgatePolarity()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪外部门信号的极性(0:positive 1:negative)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();	
	Init();
}
M_PSA_SetSweepEgatePolarity::~M_PSA_SetSweepEgatePolarity()
{
///	free(m_InputDeviceName);
//	free(m_InputPara1);
}

int M_PSA_SetSweepEgatePolarity::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "polarity");
	m_InputPara1->paramType = NTSUInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetSweepEgatePolarity::Run(void)
{
	unsigned short polarity;
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

	polarity = atoi(m_InputPara1->paramVal);
	return PSA_SetSweepEgatePolarity(vHandle,polarity);
	return NTS_SUCCESS;
}
//class M_PSA_SetSweepEgateLength
M_PSA_SetSweepEgateLength::M_PSA_SetSweepEgateLength()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置门扫描有效时间(单位:ms)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();	
	Init();
}
M_PSA_SetSweepEgateLength::~M_PSA_SetSweepEgateLength()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
}

int M_PSA_SetSweepEgateLength::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "gatelength");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetSweepEgateLength::Run(void)
{
	double gatelength;
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

	gatelength = atof(m_InputPara1->paramVal);
	return PSA_SetSweepEgateLength(vHandle,gatelength);
}

//class M_PSA_SetTrigLevel 
M_PSA_SetTrigLevel::M_PSA_SetTrigLevel()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置外部触发电平(-5V ~ 5V)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();	
	Init();
}
M_PSA_SetTrigLevel::~M_PSA_SetTrigLevel()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
}

int M_PSA_SetTrigLevel::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "TrigLevel");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "V");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetTrigLevel::Run(void)
{
	double TrigLevel;
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

	TrigLevel = atof(m_InputPara1->paramVal);
	return PSA_SetTrigLevel(vHandle,TrigLevel);
}

//M_PSA_SetStartAndStopSlot 
M_PSA_SetStartAndStopSlot::M_PSA_SetStartAndStopSlot()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置ACP模式下起止时隙");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_PSA_SetStartAndStopSlot::~M_PSA_SetStartAndStopSlot()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_PSA_SetStartAndStopSlot::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "StartSlot");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "StopSlot");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"6");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_PSA_SetStartAndStopSlot::Run(void)
{
	short StartSlot, StopSlot;
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

	StartSlot = atoi(m_InputPara1->paramVal);
	StopSlot = atoi(m_InputPara2->paramVal);
	return PSA_SetStartAndStopSlot(vHandle,StartSlot,StopSlot);
}

//class M_PSA_SetMeasMode 
M_PSA_SetMeasMode::M_PSA_SetMeasMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪的测试模式(0:SA 1:TDSCDMA_ACP 2:TDSCDMA_MCP 3:TDSCDMA_SEM 4:TDSCDMA_EVM 5:SA_Harmonic ");
	sprintf(m_MethodScript, "%s %s", m_MethodScript, "6:SA_CCDF 7:SA_ACP|MCP 8:SA_Channel Power 9:SA_Burst Power)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();	
	Init();
}
M_PSA_SetMeasMode::~M_PSA_SetMeasMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_PSA_SetMeasMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "MeasMode");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetMeasMode::Run(void)
{
	int MeasMode;
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

	MeasMode = atoi(m_InputPara1->paramVal);	
	return PSA_SetMeasMode(vHandle,MeasMode);
}

//class M_PSA_GetPST 
M_PSA_GetPST::M_PSA_GetPST()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取SA_CCDF模式下的测量值(1. Average input power (in dBm) 2. Probability at the average input power");
	sprintf(m_MethodScript, "%s%s",m_MethodScript," 3. Power level that has 10 percent of the power");
	sprintf(m_MethodScript, "%s%s",m_MethodScript," 4. Power level that has 1 percent of the power");
	sprintf(m_MethodScript, "%s%s",m_MethodScript," 5. Power level that has 0.1 percent of the power");
	sprintf(m_MethodScript, "%s%s",m_MethodScript," 6. Power level that has 0.01 percent of the power");
	sprintf(m_MethodScript, "%s%s",m_MethodScript," 7. Power level that has 0.001 percent of the power");
	sprintf(m_MethodScript, "%s%s",m_MethodScript," 8. Power level that has 0.0001 percent  of the power");
	sprintf(m_MethodScript, "%s%s",m_MethodScript," 9. Peak power (in dB))");
	m_InputDeviceName = CreateParamStruct();
	for(int i = 0; i< 10; i++)
	{
		m_OutputPara[i]= CreateParamStruct();	
	}
	Init();
}
M_PSA_GetPST::~M_PSA_GetPST()
{
/*	free(m_InputDeviceName);
	for(int i = 0 ;i<10 ;i++)
	{
		free(m_OutputPara[i]);
	}*/
}

int M_PSA_GetPST::Init(void)
{
	char ParaName[20];
	
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);	
	
	for(int i= 0 ;i<9;i++)
	{
		sprintf(ParaName, "%s%d", "PSTValue", i+1);
		m_OutputPara[i]->paramName, new char[strlen(ParaName) + 1];		
		sprintf(m_OutputPara[i]->paramName ,ParaName);
		m_OutputPara[i]->paramType = NTSReal32;
		m_OutputPara[i]->paramCount = 1;
		sprintf(m_OutputPara[i]->paramVal,"");
		m_OutputPara[i]->paramUnit , "";
		m_OutputParamVector.push_back(m_OutputPara[i]);	
	}		
	return NTS_SUCCESS;
}
int M_PSA_GetPST::Run(void)
{
	double PST[100] = {0};
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int res, i;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	res = PSA_GetPST(vHandle,PST);
	if (res == NTS_SUCCESS)
	{
		for(i =0 ;i<9;i++)
		{
			sprintf(m_OutputPara[i]->paramVal, "%e", PST[i]);
		}
		
	}
	return res;
}

//class M_PSA_GetHarmonic
M_PSA_GetHarmonic::M_PSA_GetHarmonic()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取SA_Harmonic模式下的测量值(dBm)(HarmonicNum:谐波次数(0~10 0:所有谐波值)");	
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();

	for(int i = 0; i< 10; i++)
	{
		m_OutputPara[i]= CreateParamStruct();	
	}
	Init();
}
M_PSA_GetHarmonic::~M_PSA_GetHarmonic()
{
/*	free(m_InputDeviceName);
	free(m_InputPara1);

	for(int i = 0 ;i<10 ;i++)
	{
		free(m_OutputPara[i]);
	}*/
}

int M_PSA_GetHarmonic::Init(void)
{
	char ParaName[50];
	
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);	

	sprintf(m_InputPara1->paramName, "HarmonicNum");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	for(int i= 0 ;i<10;i++)
	{
		sprintf(ParaName, "%s%d", "HarmonicValue", i+1);
		m_OutputPara[i]->paramName, new char[strlen(ParaName) + 1];		
		sprintf(m_OutputPara[i]->paramName ,ParaName);
		m_OutputPara[i]->paramType = NTSReal32;
		m_OutputPara[i]->paramCount = 1;
		sprintf(m_OutputPara[i]->paramVal,"0");
		m_OutputPara[i]->paramUnit , "dBm";
		m_OutputParamVector.push_back(m_OutputPara[i]);	
	}		
	return NTS_SUCCESS;
}
int M_PSA_GetHarmonic::Run(void)
{
	double Values[100] = {0};
	int HarmonicNum;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int res, i;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	HarmonicNum = atoi(m_InputPara1->paramVal);	
	res = PSA_GetHarmonic(vHandle,HarmonicNum, Values);
	if (res == NTS_SUCCESS)
	{
		if (HarmonicNum <=0)
		{
			//所有谐波测试值
			for(i =0 ; i<10; i++)
			{
				sprintf(m_OutputPara[i]->paramVal, "%e", Values[i]);
			}
		}
		else if(HarmonicNum >10)
		{
			//十次谐波值
			HarmonicNum = 10;
			sprintf(m_OutputPara[HarmonicNum - 1]->paramVal, "%e", Values[0]);
		}
		else
		{
			//指定次数谐波值
			sprintf(m_OutputPara[HarmonicNum - 1]->paramVal, "%e", Values[0]);
		}
		
	}
	return res;
}

//M_PSA_SetGateViewState
M_PSA_SetGateViewState::M_PSA_SetGateViewState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Gate View状态(0:Off 1:On)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_SetGateViewState::~M_PSA_SetGateViewState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
	
}

int M_PSA_SetGateViewState::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "GateViewState");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetGateViewState::Run(void)
{
	int GateViewState;
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

	GateViewState = atoi(m_InputPara1->paramVal);	
	return PSA_SetGateViewState(vHandle,GateViewState);
}

//class M_PSA_SetNoiseCorrState
M_PSA_SetNoiseCorrState::M_PSA_SetNoiseCorrState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置噪声修正状态(0: Off 1:On)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_SetNoiseCorrState::~M_PSA_SetNoiseCorrState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
	
}

int M_PSA_SetNoiseCorrState::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "State");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetNoiseCorrState::Run(void)
{
	int State;
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

	State = atoi(m_InputPara1->paramVal);	
	return PSA_SetNoiseCorrState(vHandle, State);
}

//M_PSA_SetSweepEgatDelay
M_PSA_SetSweepEgatDelay::M_PSA_SetSweepEgatDelay()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置扫描Gate Delay(ms)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_SetSweepEgatDelay::~M_PSA_SetSweepEgatDelay()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);		
}

int M_PSA_SetSweepEgatDelay::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "GateDelay");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetSweepEgatDelay::Run(void)
{
	double GateDelay;
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

	GateDelay = atof(m_InputPara1->paramVal);	
	return PSA_SetSweepEgatDelay(vHandle,GateDelay);
}
//class M_PSA_SetCarrierSpaceList 
M_PSA_SetCarrierSpaceList::M_PSA_SetCarrierSpaceList()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置载波间隔(MHz 如: 4载波间隔 2,2,2,2)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_SetCarrierSpaceList::~M_PSA_SetCarrierSpaceList()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_PSA_SetCarrierSpaceList::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "OffsetFreqList");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetCarrierSpaceList::Run(void)
{
	double Spaces[100] = {0};
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char str[20000] = {0};
	int strlength, count;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	//获取输入参数值 
	sprintf(str, "%s", m_InputPara1->paramVal);
	strlength = strlen(str);
	Spaces[0] = atof(str);
	count = 1;
	for(int i=0; i<strlength; i++)
	{
		if(str[i] == ',')
		{
			Spaces[count] = atof(&str[i+1]);
			count++;
		}
	}	
	return PSA_SetCarrierSpaceList(vHandle, Spaces, count);
}

// class M_PSA_SetOffsetFreqList
M_PSA_SetOffsetFreqList::M_PSA_SetOffsetFreqList()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Offset Freqence列表(MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_SetOffsetFreqList::~M_PSA_SetOffsetFreqList()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_PSA_SetOffsetFreqList::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "OffsetFreqList");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"3,6,0,0,0,0");
	sprintf(m_InputPara1->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetOffsetFreqList::Run(void)
{
	double OffsetFreqs[100] = {0};
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char str[20000] = {0};
	int strlength, count;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	//获取输入参数值 
	sprintf(str, "%s", m_InputPara1->paramVal);
	strlength = strlen(str);
	OffsetFreqs[0] = atof(str);
	count = 1;
	for(int i=0; i<strlength; i++)
	{
		if(str[i] == ',')
		{
			OffsetFreqs[count] = atof(&str[i+1]);
			count++;
		}
	}	
	return PSA_SetOffsetFreqList(vHandle, OffsetFreqs, count);
}

// class M_PSA_SetOffsetFreqState
M_PSA_SetOffsetFreqState::M_PSA_SetOffsetFreqState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Offset Freqence列表状态(0:Off 1:On)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_SetOffsetFreqState::~M_PSA_SetOffsetFreqState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_PSA_SetOffsetFreqState::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "States");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1,1,0,0,0,0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetOffsetFreqState::Run(void)
{
	int States[100] = {0};
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char str[20000] = {0};
	int strlength, count;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	//获取输入参数值 
	sprintf(str, "%s", m_InputPara1->paramVal);
	strlength = strlen(str);
	States[0] = atoi(str);
	count = 1;
	for(int i=0; i<strlength; i++)
	{
		if(str[i] == ',')
		{
			States[count] = atoi(&str[i+1]);
			count++;
		}
	}	
	return PSA_SetOffsetFreqState(vHandle, States, count);
}

//M_PSA_SetOffsetIBWList
M_PSA_SetOffsetIBWList::M_PSA_SetOffsetIBWList()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Offset Integ BW列表(MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_SetOffsetIBWList::~M_PSA_SetOffsetIBWList()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_PSA_SetOffsetIBWList::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "IBWList");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"2,2,2,2,2,2");
	sprintf(m_InputPara1->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetOffsetIBWList::Run(void)
{
	double IBWList[100] = {0};
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char str[20000] = {0};
	int strlength, count;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	//获取输入参数值 
	sprintf(str, "%s", m_InputPara1->paramVal);
	strlength = strlen(str);
	IBWList[0] = atof(str);
	count = 1;
	for(int i=0; i<strlength; i++)
	{
		if(str[i] == ',')
		{
			IBWList[count] = atof(&str[i+1]);
			count++;
		}
	}	
	return PSA_SetOffsetIBWList(vHandle, IBWList, count);
}

//M_PSA_SetMeasNoiseBW
M_PSA_SetMeasNoiseBW::M_PSA_SetMeasNoiseBW()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Measurement Noise Bandwidth(MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_SetMeasNoiseBW::~M_PSA_SetMeasNoiseBW()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_PSA_SetMeasNoiseBW::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "MeasNoiseBW");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"2,2,2,2,2,2");
	sprintf(m_InputPara1->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetMeasNoiseBW::Run(void)
{
	double MeasNoiseBW[100] = {0};
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char str[20000] = {0};
	int strlength, count;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	//获取输入参数值 
	sprintf(str, "%s", m_InputPara1->paramVal);
	strlength = strlen(str);
	MeasNoiseBW[0] = atof(str);
	count = 1;
	for(int i=0; i<strlength; i++)
	{
		if(str[i] == ',')
		{
			MeasNoiseBW[count] = atof(&str[i+1]);
			count++;
		}
	}	
	return PSA_SetMeasNoiseBW(vHandle, MeasNoiseBW, count);
}

//M_PSA_SetRefCarrier
M_PSA_SetRefCarrier::M_PSA_SetRefCarrier()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置参考载波");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_SetRefCarrier::~M_PSA_SetRefCarrier()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_PSA_SetRefCarrier::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "CarrierNo");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetRefCarrier::Run(void)
{
	int CarrierNo;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char str[20000] = {0};
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	CarrierNo = atoi(m_InputPara1->paramVal);	
	
	return PSA_SetRefCarrier(vHandle, CarrierNo);
}

//M_PSA_SetRefCarrierFreq
M_PSA_SetRefCarrierFreq::M_PSA_SetRefCarrierFreq()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置参考载波频率(MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_SetRefCarrierFreq::~M_PSA_SetRefCarrierFreq()
{
///	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_PSA_SetRefCarrierFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "RefCarrierFreq");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"2017.4");
	sprintf(m_InputPara1->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetRefCarrierFreq::Run(void)
{
	double RefCarrierFreq;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char str[20000] = {0};
//	int strlength, count;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	//获取输入参数值 
	RefCarrierFreq = atof(m_InputPara1->paramVal);
	return PSA_SetRefCarrierFreq(vHandle, RefCarrierFreq);
}

//class M_PSA_SendCmd 
M_PSA_SendCmd::M_PSA_SendCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_SendCmd::~M_PSA_SendCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_PSA_SendCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
int M_PSA_SendCmd::Run(void)
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
	return PSA_SendCmd(vHandle, CmdStr);
}
//class M_PSA_GetCmd 
M_PSA_GetCmd::M_PSA_GetCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令并获取指令的返回数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_GetCmd::~M_PSA_GetCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara1);
}

int M_PSA_GetCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
int M_PSA_GetCmd::Run(void)
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
	res = PSA_GetCmd(vHandle, CmdStr, RetStr);
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

//class M_PSA_GetIDN 
M_PSA_GetIDN::M_PSA_GetIDN()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取设备型号信息");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_GetIDN::~M_PSA_GetIDN()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);
}

int M_PSA_GetIDN::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
int M_PSA_GetIDN::Run(void)
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

	res = PSA_GetIDN(vHandle, IDN);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%s", IDN);
	}
	return res;
}

//class M_PSA_LoadFile
M_PSA_LoadFile::M_PSA_LoadFile()
:BaseMethod()
{
	sprintf(m_MethodScript, "加载文件");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_PSA_LoadFile::~M_PSA_LoadFile()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_PSA_LoadFile::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
int M_PSA_LoadFile::Run(void)
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
	return PSA_LoadFile(vHandle,filename);
}

//M_PSA_SaveFile 
M_PSA_SaveFile::M_PSA_SaveFile()
:BaseMethod()
{
	sprintf(m_MethodScript, "保存文件(Type[0:State 1:Screen])");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_PSA_SaveFile::~M_PSA_SaveFile()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_PSA_SaveFile::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "FileName");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "Type");
	m_InputPara2->paramType = NTSString;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_PSA_SaveFile::Run(void)
{
	char filename[100] = {0};
	int vType;
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
	
	sprintf(filename, m_InputPara1->paramVal);
	vType = atoi(m_InputPara2->paramVal);
	return PSA_SaveFile(vHandle,filename, vType);
}

//class M_PSA_GetSEMPower 
M_PSA_GetSEMPower::M_PSA_GetSEMPower()
:BaseMethod()
{
	sprintf(m_MethodScript, "获得频谱发射模板模式下的功率测量结果");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_GetSEMPower::~M_PSA_GetSEMPower()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);
}

int M_PSA_GetSEMPower::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "Power");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, "dB");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_GetSEMPower::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	double vPower;	
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	res = PSA_GetSEMPower(vHandle, &vPower);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", vPower);
	}
	return res;
}

//class M_PSA_GetEVMPower 
M_PSA_GetEVMPower::M_PSA_GetEVMPower()
:BaseMethod()
{
	sprintf(m_MethodScript, "获得EVM模式下的功率测量结果");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_GetEVMPower::~M_PSA_GetEVMPower()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);
}

int M_PSA_GetEVMPower::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "Power");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, "dB");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_GetEVMPower::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	double vPower;	
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	res = PSA_GetEVMPower(vHandle, &vPower);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", vPower);
	}
	return res;
}

//M_PSA_SetSweepPoint 
M_PSA_SetSweepPoint::M_PSA_SetSweepPoint()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置扫描点数");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	
	Init();
}

M_PSA_SetSweepPoint::~M_PSA_SetSweepPoint()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetSweepPoint::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "SweepPoint");
	m_InputPara->paramType = NTSInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1001");
	sprintf(m_InputPara->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara);
	
	return NTS_SUCCESS;
}
int M_PSA_SetSweepPoint::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int  SweepPoint;	
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	SweepPoint = atoi(m_InputPara->paramVal);
	res = PSA_SetSweepPoint(vHandle, SweepPoint);
	return res;
}


// class M_PSA_SaveTraceByName
M_PSA_SaveTraceByName::M_PSA_SaveTraceByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "以命名方式将测试曲线数据保存到PC内存中");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	m_InputPara2 = CreateParamStruct();	
	m_InputPara3 = CreateParamStruct();	
	Init();
}
M_PSA_SaveTraceByName::~M_PSA_SaveTraceByName()
{
///	free(m_InputDeviceName);
//	free(m_InputPara1);		
//	free(m_InputPara2);		
//	free(m_InputPara3);		
}

int M_PSA_SaveTraceByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
int M_PSA_SaveTraceByName::Run(void)
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

	retVal = PSA_SaveTraceByName(vHandle, ChIndex, TraceIndex, vTraceName);
	return retVal;
}

// class M_PSA_SetTraceMathTypeByName
M_PSA_SetTraceMathTypeByName::M_PSA_SetTraceMathTypeByName()
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
M_PSA_SetTraceMathTypeByName::~M_PSA_SetTraceMathTypeByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);		
//	free(m_InputPara2);		
//	free(m_InputPara3);		
//	free(m_InputPara4);		
}

int M_PSA_SetTraceMathTypeByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
int M_PSA_SetTraceMathTypeByName::Run(void)
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
	
	retVal = PSA_SetTraceMathTypeByName(vHandle, vTraceName1, vTraceName2, vType, vNewName);
	return retVal;
}

// class M_PSA_DeleteTraceByName
M_PSA_DeleteTraceByName::M_PSA_DeleteTraceByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "删除一条PC内存曲线");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	Init();
}
M_PSA_DeleteTraceByName::~M_PSA_DeleteTraceByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);			
}

int M_PSA_DeleteTraceByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
int M_PSA_DeleteTraceByName::Run(void)
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
	
	retVal = PSA_DeleteTraceByName(vHandle, vTraceName);
	return retVal;
}

// class M_PSA_DeleteAllTrace
M_PSA_DeleteAllTrace::M_PSA_DeleteAllTrace()
:BaseMethod()
{
	sprintf(m_MethodScript, "删除所有PC内存曲线");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_DeleteAllTrace::~M_PSA_DeleteAllTrace()
{
//	free(m_InputDeviceName);
}

int M_PSA_DeleteAllTrace::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
	
}
int M_PSA_DeleteAllTrace::Run(void)
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
	retVal = PSA_DeleteAllTrace(vHandle);
	return retVal;
}

// class M_PSA_SetMarkerSearchFreqByName
M_PSA_SetMarkerSearchFreqByName::M_PSA_SetMarkerSearchFreqByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "在PC内存数据中设置MARKER 的查找范围(MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	m_InputPara2 = CreateParamStruct();	
	m_InputPara3 = CreateParamStruct();	
	Init();
}
M_PSA_SetMarkerSearchFreqByName::~M_PSA_SetMarkerSearchFreqByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);		
//	free(m_InputPara2);		
//	free(m_InputPara3);				
}

int M_PSA_SetMarkerSearchFreqByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
int M_PSA_SetMarkerSearchFreqByName::Run(void)
{		
	int retVal;
	double Start, Stop;
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
	
	retVal = PSA_SetMarkerSearchFreqByName(vHandle, vTraceName, Start, Stop);
	return retVal;
}

//M_PSA_GetMarkerValueByName
M_PSA_GetMarkerValueByName::M_PSA_GetMarkerValueByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "从PC内存数据中获取最大值和最小值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();	
	
	Init();
}
M_PSA_GetMarkerValueByName::~M_PSA_GetMarkerValueByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_OutputPara1);
//	free(m_OutputPara2);	
}

int M_PSA_GetMarkerValueByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
int M_PSA_GetMarkerValueByName::Run(void)
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
	res = PSA_GetMarkerValueByName(vHandle, vTraceName, &Max, &Min);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", Max);
		sprintf(m_OutputPara2->paramVal, "%e", Min);
	}
	return res;
}

//M_PSA_GetFluctuateByName
M_PSA_GetFluctuateByName::M_PSA_GetFluctuateByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "从PC内存数据中获取指定带宽范围内的平坦度(MHz)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();	
	
	Init();
}
M_PSA_GetFluctuateByName::~M_PSA_GetFluctuateByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara1);	
}

int M_PSA_GetFluctuateByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
int M_PSA_GetFluctuateByName::Run(void)
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

	res = PSA_GetFluctuateByName(vHandle, vTraceName, vBW, &Fluctuate);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", Fluctuate);		
	}
	return res;
}

//M_PSA_GetMarkerFreqByName
M_PSA_GetMarkerFreqByName::M_PSA_GetMarkerFreqByName()
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
M_PSA_GetMarkerFreqByName::~M_PSA_GetMarkerFreqByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
//	free(m_OutputPara1);	
}

int M_PSA_GetMarkerFreqByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
int M_PSA_GetMarkerFreqByName::Run(void)
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

	res = PSA_GetMarkerFreqByName(vHandle, vTraceName,Marker, Freq, &Value);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", Value);		
	}
	return res;
}

// class M_PSA_GetTraceDataXByName 
M_PSA_GetTraceDataXByName::M_PSA_GetTraceDataXByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "从PC内存数据获取X轴数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();	
	
	Init();
}
M_PSA_GetTraceDataXByName::~M_PSA_GetTraceDataXByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_OutputPara1);	
}

int M_PSA_GetTraceDataXByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
	
	sprintf(m_OutputPara1->paramName, "TraceDataX");
	m_OutputPara1->paramType = NTSReal64;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_GetTraceDataXByName::Run(void)
{
	int res;
	char vTraceName[100];
	double vTraceData[10000];
	long i, vCount;
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

	res = PSA_GetTraceDataXByName(vHandle, vTraceName, vTraceData, &vCount);
	if(res == NTS_SUCCESS)
	{
		m_OutputPara1->LparamVal = (char *) malloc(vCount * 20 * sizeof(char));
		memset(m_OutputPara1->LparamVal, 0, vCount * 20);
		for(i=0; i<vCount; i++)
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

// class M_PSA_GetTraceDataYByName 
M_PSA_GetTraceDataYByName::M_PSA_GetTraceDataYByName()
:BaseMethod()
{
	sprintf(m_MethodScript, "从PC内存数据获取Y轴数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();	
	
	Init();
}
M_PSA_GetTraceDataYByName::~M_PSA_GetTraceDataYByName()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_OutputPara1);	
}

int M_PSA_GetTraceDataYByName::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
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
	
	
	sprintf(m_OutputPara1->paramName, "TraceDataY");
	m_OutputPara1->paramType = NTSReal64;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_GetTraceDataYByName::Run(void)
{
	int res;
	char vTraceName[100];
	double vTraceData[10000];
	long i, vCount;
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
	
	res = PSA_GetTraceDataYByName(vHandle, vTraceName, vTraceData, &vCount);
	if(res == NTS_SUCCESS)
	{
		m_OutputPara1->LparamVal = (char *) malloc(vCount * 20 * sizeof(char));
		memset(m_OutputPara1->LparamVal, 0, vCount * 20);
		for(i=0; i<vCount; i++)
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

// M_PSA_GetSweepTime
M_PSA_GetSweepTime::M_PSA_GetSweepTime()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取扫描时间值(s)");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();	
	
	Init();
}
M_PSA_GetSweepTime::~M_PSA_GetSweepTime()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);	
}

int M_PSA_GetSweepTime::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "SweepTime");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "s");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_GetSweepTime::Run(void)
{
	int res;
	double vSweepTime;
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
	
	res = PSA_GetSweepTime(vHandle, &vSweepTime);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", vSweepTime);		
	}
	return res;
}

// class M_PSA_GetTrigDelayTime
M_PSA_GetTrigDelayTime::M_PSA_GetTrigDelayTime()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取触发延迟时间(ms)");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();	
	
	Init();
}
M_PSA_GetTrigDelayTime::~M_PSA_GetTrigDelayTime()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);	
}

int M_PSA_GetTrigDelayTime::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "DelayTime");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "ms");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_GetTrigDelayTime::Run(void)
{
	int res;
	double vDaleyTime;
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
	
	res = PSA_GetTrigDelayTime(vHandle, &vDaleyTime);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", vDaleyTime);		
	}
	return res;
}

// M_PSA_SetTrigPolarity
M_PSA_SetTrigPolarity::M_PSA_SetTrigPolarity()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置触发极性(0:Positive 1:Negative)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	
	Init();
}
M_PSA_SetTrigPolarity::~M_PSA_SetTrigPolarity()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_PSA_SetTrigPolarity::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Polarity");
	m_InputPara1->paramType = NTSInt32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetTrigPolarity::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int vPolarity;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	vPolarity = atoi(m_InputPara1->paramVal);
	res = PSA_SetTrigPolarity(vHandle, vPolarity);
	return res;
}

// 
M_PSA_ReadDev::M_PSA_ReadDev()
:BaseMethod()
{
	sprintf(m_MethodScript, "读取设备的测试数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();	
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}
M_PSA_ReadDev::~M_PSA_ReadDev()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara1);
}

int M_PSA_ReadDev::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "ResultTypePara");
	m_InputPara1->paramType = NTSInt32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_OutputPara1->paramName, "ResultStr");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_ReadDev::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int vResultPara;
	char vBuffer[40000] = {0};
	int vRealCount = 0;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	vResultPara = atoi(m_InputPara1->paramVal);
	res = PSA_ReadDev(vHandle, vResultPara, vBuffer, sizeof(vBuffer), &vRealCount);
	if (res == NTS_SUCCESS)
	{
		if (vRealCount > PARALENGTH) 
		{
			m_OutputPara1->LparamVal = (char *) malloc(vRealCount * sizeof(char));
			memset(m_OutputPara1->LparamVal, 0, vRealCount);
			memcpy(m_OutputPara1->LparamVal, vBuffer, vRealCount);
		}
		else
		{
			memset(m_OutputPara1->paramVal, 0, PARALENGTH);
			memcpy(m_OutputPara1->paramVal, vBuffer, vRealCount);
		}
		
	}
	return res;
}

// 
M_PSA_SetTrigOnce::M_PSA_SetTrigOnce()
:BaseMethod()
{
	sprintf(m_MethodScript, "触发一次测量");
	m_InputDeviceName = CreateParamStruct();	
	Init();
}
M_PSA_SetTrigOnce::~M_PSA_SetTrigOnce()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetTrigOnce::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetTrigOnce::Run(void)
{
	int res;
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
	res = PSA_SetTrigOnce(vHandle);
	return res;
}

// 
M_PSA_Restart::M_PSA_Restart()
:BaseMethod()
{
	sprintf(m_MethodScript, "重新测量一次");
	m_InputDeviceName = CreateParamStruct();

	Init();
}
M_PSA_Restart::~M_PSA_Restart()
{
//	free(m_InputDeviceName);
}

int M_PSA_Restart::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_Restart::Run(void)
{
	int res;
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
	res = PSA_Restart(vHandle);
	return res;
}


/******************************************
 *	2015.5.21 新增 设置绝对功率List
 */
//M_PSA_SetOffsetAbsList
M_PSA_SetOffsetAbsList::M_PSA_SetOffsetAbsList()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Offset Abs绝对功率");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_SetOffsetAbsList::~M_PSA_SetOffsetAbsList()
{
	//	free(m_InputDeviceName);
	//	free(m_InputPara1);	
}

int M_PSA_SetOffsetAbsList::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "AbsList");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"-7,-14,-15,-16");
	sprintf(m_InputPara1->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_SetOffsetAbsList::Run(void)
{
	double AbsList[100] = {0};
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char str[20000] = {0};
	int strlength, count;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	//获取输入参数值 
	sprintf(str, "%s", m_InputPara1->paramVal);
	strlength = strlen(str);
	AbsList[0] = atof(str);
	count = 1;
	for(int i=0; i<strlength; i++)
	{
		if(str[i] == ',')
		{
			AbsList[count] = atof(&str[i+1]);
			count++;
		}
	}	   
	return PSA_SetOffsetAbsList(vHandle, AbsList, count);
}


//class M_PSA_SetEgatState
M_PSA_SetEgatState::M_PSA_SetEgatState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪Egat(0:关 1:开");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();	
	Init();
}
M_PSA_SetEgatState::~M_PSA_SetEgatState()
{
	//	free(m_InputDeviceName);
	//	free(m_InputPara);
}

int M_PSA_SetEgatState::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "EgatState");
	m_InputPara->paramType = NTSUInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");	
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetEgatState::Run(void)
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
	return PSA_SetEgatState(vHandle,state);
}


 
//class M_PSA_GetOBW
M_PSA_GetOBW::M_PSA_GetOBW()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取占用带宽OBW值");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara= CreateParamStruct();	
	Init();
}
M_PSA_GetOBW::~M_PSA_GetOBW()
{
	//	free(m_InputDeviceName);
	//	free(m_OutputPara);
}
 
int M_PSA_GetOBW::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara->paramName, "OBWValue");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "MHz");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_PSA_GetOBW::Run(void)
{
	double OBWValue;
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
	
	retVal = PSA_GetOBW(vHandle,&OBWValue);
	if(retVal ==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,"%.6f",OBWValue);
		
	}
	return retVal;
} 
//class M_PSA_SetSpan
M_PSA_SetSpan::M_PSA_SetSpan()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪扫描范围");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara= CreateParamStruct();
	Init();
}
M_PSA_SetSpan::~M_PSA_SetSpan()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetSpan::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "span");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"200");
	sprintf(m_InputPara->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_PSA_SetSpan::Run(void)
{
	double span;
	
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

	span = atof(m_InputPara->paramVal);
	return PSA_SetSpan(vHandle,span);
	return NTS_SUCCESS;
	
}

//class M_PSA_RefLevelAuto
M_PSA_RefLevelAuto::M_PSA_RefLevelAuto()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪频谱仪自动电平");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_RefLevelAuto::~M_PSA_RefLevelAuto()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_RefLevelAuto::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_RefLevelAuto::Run(void)
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

	return PSA_RefLevelAuto(vHandle);
	//return NTS_SUCCESS;
	
}

//class M_PSA_SetACLRMEAS
M_PSA_SetACLRMEAS::M_PSA_SetACLRMEAS()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置ACLP模式");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetACLRMEAS::~M_PSA_SetACLRMEAS()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetACLRMEAS::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetACLRMEAS::Run(void)
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

	return PSA_SetACLRMEAS(vHandle);
	//return NTS_SUCCESS;
	
}

//class M_PSA_SetACPTXBW
M_PSA_SetACPTXBW::M_PSA_SetACPTXBW()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置ACLP模式TX带宽");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_PSA_SetACPTXBW::~M_PSA_SetACPTXBW()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetACPTXBW::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "TX");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);

	sprintf(m_InputPara2->paramName, "freq");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "MHz");
	m_InputParamVector.push_back(m_InputPara2);

	return NTS_SUCCESS;
}
int M_PSA_SetACPTXBW::Run(void)
{
	double freq = 0;
	short int vHandle = 0;
	short int channel = 1;

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	channel = atoi(m_InputPara->paramVal);
	freq = atof(m_InputPara2->paramVal);

	return PSA_SetACPTXBW(vHandle, channel, freq);
	return NTS_SUCCESS;
	
}


//class M_PSA_SetACPTXCount
M_PSA_SetACPTXCount::M_PSA_SetACPTXCount()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置ACLP模式TXCount");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	Init();
}
M_PSA_SetACPTXCount::~M_PSA_SetACPTXCount()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetACPTXCount::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "Count");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);

	return NTS_SUCCESS;
}
int M_PSA_SetACPTXCount::Run(void)
{
	short int vHandle = 0;
	short int count = 1;

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	count = atoi(m_InputPara->paramVal);

	return PSA_SetACPTXCount(vHandle, count);
	return NTS_SUCCESS;
	
}


//class M_PSA_SetTriggerSource
M_PSA_SetTriggerSource::M_PSA_SetTriggerSource()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置TrigSource,Source参数(1:Free RUN, 2:Ext Trigger, 3:Ext Trigger2, 4:Ext Trigger3, 5:IF Power, 6:Time, 7:RF Power, 8:Power Sensor)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	Init();
}
M_PSA_SetTriggerSource::~M_PSA_SetTriggerSource()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetTriggerSource::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "Source");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);

	return NTS_SUCCESS;
}
int M_PSA_SetTriggerSource::Run(void)
{
	short int vHandle = 0;
	short int source = 1;

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	source = atoi(m_InputPara->paramVal);

	return PSA_SetTriggerSource(vHandle, source);
	return NTS_SUCCESS;
	
}

//class M_PSA_SetTriggerLevel
M_PSA_SetTriggerLevel::M_PSA_SetTriggerLevel()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置TriggerLevel,Source参数(1:IF Power, 2:Ext Trigger1, 3:Ext Trigger2, 4:Ext Trigger3, 5:Video, 6:RF Power)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_PSA_SetTriggerLevel::~M_PSA_SetTriggerLevel()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetTriggerLevel::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "Source");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);

	sprintf(m_InputPara2->paramName, "Level");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara2);

	return NTS_SUCCESS;
}
int M_PSA_SetTriggerLevel::Run(void)
{
	double level = 0;
	short int vHandle = 0;
	short int source = 1;

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	source = atoi(m_InputPara->paramVal);
	level = atof(m_InputPara2->paramVal);

	return PSA_SetTriggerLevel(vHandle, source, level);
	return NTS_SUCCESS;
	
}

//class M_PSA_SetGateTrigSwitch
M_PSA_SetGateTrigSwitch::M_PSA_SetGateTrigSwitch()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置GateTrigSwitch,Switch参数(0:OFF, 1:ON)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	Init();
}
M_PSA_SetGateTrigSwitch::~M_PSA_SetGateTrigSwitch()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetGateTrigSwitch::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "Switch");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);


	return NTS_SUCCESS;
}
int M_PSA_SetGateTrigSwitch::Run(void)
{
	short int vHandle = 0;
	short int Switch = 1;

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	Switch = atoi(m_InputPara->paramVal);

	return PSA_SetGateTrigSwitch(vHandle, Switch);
	return NTS_SUCCESS;
	
}

//class M_PSA_SetGateDelay
M_PSA_SetGateDelay::M_PSA_SetGateDelay()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置GateDelay,单位为us");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	Init();
}
M_PSA_SetGateDelay::~M_PSA_SetGateDelay()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetGateDelay::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "delay");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "us");
	m_InputParamVector.push_back(m_InputPara);


	return NTS_SUCCESS;
}
int M_PSA_SetGateDelay::Run(void)
{
	short int vHandle = 0;
	short int delay = 1;

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	delay = atoi(m_InputPara->paramVal);

	return PSA_SetGateDelay(vHandle, delay);
	return NTS_SUCCESS;
	
}

//class M_PSA_SetGateLength
M_PSA_SetGateLength::M_PSA_SetGateLength()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置GateLength,单位为us");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	Init();
}
M_PSA_SetGateLength::~M_PSA_SetGateLength()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetGateLength::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "length");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "us");
	m_InputParamVector.push_back(m_InputPara);


	return NTS_SUCCESS;
}
int M_PSA_SetGateLength::Run(void)
{
	short int vHandle = 0;
	short int length = 1;

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	length = atoi(m_InputPara->paramVal);

	return PSA_SetGateLength(vHandle, length);
	return NTS_SUCCESS;
	
}

//class M_PSA_GetACLR
M_PSA_GetACLR::M_PSA_GetACLR()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取ACLR值");
	
	m_InputDeviceName  = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();	
	Init();
}
M_PSA_GetACLR::~M_PSA_GetACLR()
{

//	free(m_InputDeviceName);
//	free(m_OutputPara);
}

int M_PSA_GetACLR::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_OutputPara1->paramName, "Value");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);

	
	return NTS_SUCCESS;
}
int M_PSA_GetACLR::Run(void)
{
	char value[200000] = {0};
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

	retVal = PSA_GetACLR(vHandle, value);
	if(retVal !=NTS_SUCCESS)
	{
		return retVal;	 
	}
	if (strlen(value) > PARALENGTH)
	{		
		int len = strlen(value);
		m_OutputPara1->LparamVal = (char *)malloc((len + 10)*sizeof(char));
		sprintf(m_OutputPara1->LparamVal, "%s", value);
	}
	else
	{
		sprintf(m_OutputPara1->paramVal, "%s", value);
	}
	return retVal;
}

//class M_PSA_SetVSAMODE
M_PSA_SetVSAMODE::M_PSA_SetVSAMODE()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪为VSA模式");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetVSAMODE::~M_PSA_SetVSAMODE()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetVSAMODE::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetVSAMODE::Run(void)
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

	return PSA_SetVSAMODE(vHandle);
	return NTS_SUCCESS;

}

//class M_PSA_SetPULSEMODE
M_PSA_SetPULSEMODE::M_PSA_SetPULSEMODE()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置频谱仪为PULSE模式");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetPULSEMODE::~M_PSA_SetPULSEMODE()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetPULSEMODE::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetPULSEMODE::Run(void)
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

	return PSA_SetPULSEMODE(vHandle);
	return NTS_SUCCESS;

}


//class M_PSA_SetOBWPOWERBW
M_PSA_SetOBWPOWERBW::M_PSA_SetOBWPOWERBW()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置OBWPowerBandWidth,单位为%");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	Init();
}
M_PSA_SetOBWPOWERBW::~M_PSA_SetOBWPOWERBW()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetOBWPOWERBW::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "power");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"99");
	sprintf(m_InputPara->paramUnit , "%");
	m_InputParamVector.push_back(m_InputPara);


	return NTS_SUCCESS;
}
int M_PSA_SetOBWPOWERBW::Run(void)
{
	short int vHandle = 0;
	short int power = 0;

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	power = atoi(m_InputPara->paramVal);

	return PSA_SetOBWPOWERBW(vHandle, power);
	return NTS_SUCCESS;
	
}

//class M_PSA_GetEVMValue
M_PSA_GetEVMValue::M_PSA_GetEVMValue()
:BaseMethod()
{
	sprintf(m_MethodScript, "获得VSA模式下的EVM值");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();	
	m_OutputPara2 = CreateParamStruct();
	m_OutputPara3 = CreateParamStruct();
	m_OutputPara4 = CreateParamStruct();
	m_OutputPara5 = CreateParamStruct();
	m_OutputPara6 = CreateParamStruct();

	Init();
}
M_PSA_GetEVMValue::~M_PSA_GetEVMValue()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_GetEVMValue::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "RMS-Current");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"0");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);

	sprintf(m_OutputPara2->paramName, "PEAK-Current");
	m_OutputPara2->paramType = NTSReal32;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"0");
	sprintf(m_OutputPara2->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara2);

	sprintf(m_OutputPara3->paramName, "RMS-Mean");
	m_OutputPara3->paramType = NTSReal32;
	m_OutputPara3->paramCount = 1;
	sprintf(m_OutputPara3->paramVal,"0");
	sprintf(m_OutputPara3->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara3);

	sprintf(m_OutputPara4->paramName, "PEAK-Mean");
	m_OutputPara4->paramType = NTSReal32;
	m_OutputPara4->paramCount = 1;
	sprintf(m_OutputPara4->paramVal,"0");
	sprintf(m_OutputPara4->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara4);

	sprintf(m_OutputPara5->paramName, "RMS-Peak");
	m_OutputPara5->paramType = NTSReal32;
	m_OutputPara5->paramCount = 1;
	sprintf(m_OutputPara5->paramVal,"0");
	sprintf(m_OutputPara5->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara5);

	sprintf(m_OutputPara6->paramName, "PEAK-Peak");
	m_OutputPara6->paramType = NTSReal32;
	m_OutputPara6->paramCount = 1;
	sprintf(m_OutputPara6->paramVal,"0");
	sprintf(m_OutputPara6->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara6);

	return NTS_SUCCESS;
}
int M_PSA_GetEVMValue::Run(void)
{
	int retVal;
	short int vHandle = 0;
	double RetStr[6] = {0};

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	retVal = PSA_GetEVMValue(vHandle,RetStr);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", RetStr[0]); 
		sprintf(m_OutputPara2->paramVal, "%e", RetStr[1]); 
		sprintf(m_OutputPara3->paramVal, "%e", RetStr[2]); 
		sprintf(m_OutputPara4->paramVal, "%e", RetStr[3]); 
		sprintf(m_OutputPara5->paramVal, "%e", RetStr[4]); 
		sprintf(m_OutputPara6->paramVal, "%e", RetStr[5]);
	}

	//return PSA_GetEVMValue(vHandle, RetStr);
	return retVal;
	
}

//class M_PSA_GetPULSEValue
M_PSA_GetPULSEValue::M_PSA_GetPULSEValue()
:BaseMethod()
{
	sprintf(m_MethodScript, "获得PULSE模式下的值");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();	
	m_OutputPara2 = CreateParamStruct();

	Init();
}
M_PSA_GetPULSEValue::~M_PSA_GetPULSEValue()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_GetPULSEValue::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "Pulse Width");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"s");
	sprintf(m_OutputPara1->paramUnit , "s");
	m_OutputParamVector.push_back(m_OutputPara1);

	sprintf(m_OutputPara2->paramName, "Off Time");
	m_OutputPara2->paramType = NTSString;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"s");
	sprintf(m_OutputPara2->paramUnit , "s");
	m_OutputParamVector.push_back(m_OutputPara2);

	return NTS_SUCCESS;
}
int M_PSA_GetPULSEValue::Run(void)
{
	int retVal;
	short int vHandle = 0;
	char RetStr1[1024] = {0};
	char RetStr2[1024] = {0};

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	retVal = PSA_GetPULSEValue(vHandle, RetStr1, RetStr2);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%s", RetStr1); 
		sprintf(m_OutputPara2->paramVal, "%s", RetStr2); 
	}

	//return PSA_GetEVMValue(vHandle, RetStr);
	return retVal;
	
}

//class M_PSA_SetSignCountFunc
M_PSA_SetSignCountFunc::M_PSA_SetSignCountFunc()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置SingalCountFunction");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_PSA_SetSignCountFunc::~M_PSA_SetSignCountFunc()
{
//	free(m_InputDeviceName);
}

int M_PSA_SetSignCountFunc::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_PSA_SetSignCountFunc::Run(void)
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

	return PSA_SetSignCountFunc(vHandle);
	return NTS_SUCCESS;

}

//class M_PSA_GetMarkFreq 
M_PSA_GetMarkFreq::M_PSA_GetMarkFreq()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取Mark点频率");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_PSA_GetMarkFreq::~M_PSA_GetMarkFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara1);
}

int M_PSA_GetMarkFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "MarkerIndex");
	m_InputPara1->paramType = NTSInt32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_OutputPara1->paramName, "Freq");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_PSA_GetMarkFreq::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	long MarkerIndex;
	double Freq;
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	//获取输入参数值 
	MarkerIndex = atoi(m_InputPara1->paramVal);
	res = PSA_GetMarkFreq(vHandle, MarkerIndex, &Freq);
	if (res != NTS_SUCCESS)
	{
		return res;		
	}
	sprintf(m_OutputPara1->paramVal, "%.6f", Freq);
	return res;
}


//class M_PSA_SetTriggerOffSet
M_PSA_SetTriggerOffSet::M_PSA_SetTriggerOffSet()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置TriggerOffSet,单位为us");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	Init();
}
M_PSA_SetTriggerOffSet::~M_PSA_SetTriggerOffSet()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetTriggerOffSet::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "Offset");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "us");
	m_InputParamVector.push_back(m_InputPara);


	return NTS_SUCCESS;
}
int M_PSA_SetTriggerOffSet::Run(void)
{
	short int vHandle = 0;
	double offset;

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	offset = atof(m_InputPara->paramVal);

	return PSA_SetTriggerOffSet(vHandle, offset);
	return NTS_SUCCESS;
}


//class M_PSA_SetTimingPara
M_PSA_SetTimingPara::M_PSA_SetTimingPara()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Timing参数,参数OFFTIME(0:OFF, 1:ON), DUTYCYCLE(0:OFF, 1:ON)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_PSA_SetTimingPara::~M_PSA_SetTimingPara()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetTimingPara::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "Offtime");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);

	sprintf(m_InputPara2->paramName, "Dutycycle");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara2);

	return NTS_SUCCESS;
}
int M_PSA_SetTimingPara::Run(void)
{
	short int offtime = 0;
	short int vHandle = 0;
	short int dutycycle = 1;

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	offtime = atoi(m_InputPara->paramVal);
	dutycycle = atoi(m_InputPara2->paramVal);

	return PSA_SetTimingPara(vHandle, offtime, dutycycle);
	return NTS_SUCCESS;
	
}


//class M_PSA_SetTransFilter
M_PSA_SetTransFilter::M_PSA_SetTransFilter()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Transmit Filter,参数Type(1:RRC, 2:RC, 3:Gauss)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_PSA_SetTransFilter::~M_PSA_SetTransFilter()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetTransFilter::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "Type");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);

	sprintf(m_InputPara2->paramName, "Alpha");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0.1");
	sprintf(m_InputPara2->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara2);

	return NTS_SUCCESS;
}
int M_PSA_SetTransFilter::Run(void)
{
	short int type = 1;
	short int vHandle = 0;
	double alpha = 0.1;

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
	alpha = atof(m_InputPara2->paramVal);

	return PSA_SetTransFilter(vHandle, type, alpha);
	return NTS_SUCCESS;
	
}


//class M_PSA_SetModulation
M_PSA_SetModulation::M_PSA_SetModulation()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置ModulationSetting,参数Type(1:PSK, 2:MSK, 3:QAM, 4:FSK, 5:ASK, 6:APSK),Order(PSK:1:BPSK, 2:QPSK, 3:Offset QPSK, 4:Shaped Offset QPSK, 5:3Pi/4QPSK, 6:8PSK, 7:3Pi/8-8PSK, 8:D8PSK, 9:Pi/8-D8PSK, 10:DQPSK, 11:Pi/4-DQPSK, 12:Pi/4-QPSK | MSK:1:MSK, 2:DMSK | QAM:1:16QAM, 2:Pi/4-16QAM, 3:32QAM, 4:-Pi4-32QAM, 5:64QAM, 6:128QAM, 7:256QAM, 8:512QAM, 9:1024QAM, 10:2048QAM, 11:4096QAM | FSK:1:2FSK, 2:4FSK, 3:8FSK, 4:16FSK | ASK:1:2ASK, 2:4ASK | APSK:1:16APSK, 2:32APSK),Mapping(QPSK:1:CDMA2000_FWD, 2:DVB_S2, 3:GRAY, 4:NATURAL, 5:WCDMA | DQPSK:1:INMARSAT, 2:NATURAL | PI/4-DQPSK:1:APCO25, 2:APCO25_Phase_2, 3:NADC, 4:NATURAL, 5:PDC, 6:PHS, 7:TETRA, 8:TFTS | 8PSK:1:DVB_S2, 2:GRAY, 3:NATURAL | D8PSK:1:GRAY, 2:NATURAL, 3:VDL | PI/8-D8PSK:1:APCO25_Phase_2, 2:TETRA | 16QAM:1:DVB-C, 2:GRAY | 4FSK:1:APCO25_C4FM, 2:APCO25_Phase_2, 3:GRAY, 4:NATURAL | 16APSK:1:DVB_S2_23, 2:DVB_S2_34, 3:DVB_S2_45, 4:DVB_S2_56, 5:DVB_S2_89, 6:DVB_S2_910 | 32APSK:1:DVB_S2_34, 2:DVB_S2_45, 3:DVB_S2_56, 4:DVB_S2_89, 5:DVB_S2_910)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();	
	m_InputPara4 = CreateParamStruct();
	Init();
}
M_PSA_SetModulation::~M_PSA_SetModulation()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetModulation::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "Type");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);

	sprintf(m_InputPara2->paramName, "Order");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "Mapping");
	m_InputPara3->paramType = NTSInt8;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"1");
	sprintf(m_InputPara3->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara3);

	sprintf(m_InputPara4->paramName, "SymbolRate");
	m_InputPara4->paramType = NTSReal32;
	m_InputPara4->paramCount = 1;
	sprintf(m_InputPara4->paramVal,"10000");
	sprintf(m_InputPara4->paramUnit , "Hz");
	m_InputParamVector.push_back(m_InputPara4);

	return NTS_SUCCESS;
}
int M_PSA_SetModulation::Run(void)
{
	short int vHandle = 0;
	short int type = 1;
	short int order = 1;
	short int map = 1;
	double rate = 10000;

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
	order = atoi(m_InputPara2->paramVal);
	map = atoi(m_InputPara3->paramVal);
	rate = atof(m_InputPara4->paramVal);

	return PSA_SetModulation(vHandle, type, order, map, rate);
	return NTS_SUCCESS;
	
}


//class M_PSA_SetCaptureLengthAuto
M_PSA_SetCaptureLengthAuto::M_PSA_SetCaptureLengthAuto()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置CaptureLengthAuto,参数(0:OFF, 1:ON)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	Init();
}
M_PSA_SetCaptureLengthAuto::~M_PSA_SetCaptureLengthAuto()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_SetCaptureLengthAuto::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "ON/OFF");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara);

	return NTS_SUCCESS;
}
int M_PSA_SetCaptureLengthAuto::Run(void)
{
	short int vHandle = 0;
	short int Switch;

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	Switch = atoi(m_InputPara->paramVal);

	return PSA_SetCaptureLengthAuto(vHandle, Switch);
	return NTS_SUCCESS;
	
}



//class M_PSA_GetPULSENumber
M_PSA_GetPULSENumber::M_PSA_GetPULSENumber()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取PULSENumber数量");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1= CreateParamStruct();		
	Init();
}
M_PSA_GetPULSENumber::~M_PSA_GetPULSENumber()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_PSA_GetPULSENumber::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = PSADevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "Count");
	m_OutputPara1->paramType = NTSInt16;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);

	return NTS_SUCCESS;
}
int M_PSA_GetPULSENumber::Run(void)
{
	short int vHandle = 0;
	int vCount;
	int retVal;

	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	retVal = PSA_GetPULSENumber(vHandle,&vCount);
	if(retVal==NTS_SUCCESS)
	{
	sprintf(m_OutputPara1->paramVal,"%d",vCount);
	}
	return retVal;;
	
}
