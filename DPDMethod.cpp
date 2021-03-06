#include "stdafx.h"
#include "DPDMethod.h"
#include <assert.h>
#include "stdio.h"
#include <map>
#include "math.h"

extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

//class M_DPD_SetDPDState
M_DPD_SetDPDState::M_DPD_SetDPDState()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置DPD开关状态(0:关 1:开)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_DPD_SetDPDState::~M_DPD_SetDPDState()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_DPD_SetDPDState::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "State");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_DPD_SetDPDState::Run(void)
{
	short int state;
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
	return DPD_SetDPDState(vHandle,state);
}

//class M_DPD_SetTxAtten
M_DPD_SetTxAtten::M_DPD_SetTxAtten()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置发射通道衰减值(0x3f:不衰，0:全衰，步进0.5dB)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_DPD_SetTxAtten::~M_DPD_SetTxAtten()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_DPD_SetTxAtten::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "Atten");
	m_InputPara->paramType = NTSInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"63");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_DPD_SetTxAtten::Run(void)
{
	int Atten;
	
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
		
	Atten = atoi(m_InputPara->paramVal);
	return DPD_SetTxAtten(vHandle,Atten);
}

//class M_DPD_SetSmallTxAtten
M_DPD_SetSmallTxAtten::M_DPD_SetSmallTxAtten()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置输出TX链路细调功率值(步进0.1dB)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_DPD_SetSmallTxAtten::~M_DPD_SetSmallTxAtten()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_DPD_SetSmallTxAtten::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "Atten");
	m_InputPara->paramType = NTSReal64;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_DPD_SetSmallTxAtten::Run(void)
{
	double Atten;
	
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
	
	Atten = atof(m_InputPara->paramVal);
	return DPD_SetSmallTxAtten(vHandle, Atten);
}

//class M_DPD_SetRDAtten
M_DPD_SetRDAtten::M_DPD_SetRDAtten()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置反馈通道衰减值(0x3f:不衰，0:全衰，步进0.5dB)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_DPD_SetRDAtten::~M_DPD_SetRDAtten()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_DPD_SetRDAtten::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara->paramName, "Atten");
	m_InputPara->paramType = NTSInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"63");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_DPD_SetRDAtten::Run(void)
{
	int Atten;
	
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
	
	Atten = atoi(m_InputPara->paramVal);
	return DPD_SetRDAtten(vHandle,Atten);
}

//class M_DPD_GetErrPower
M_DPD_GetErrPower::M_DPD_GetErrPower()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取偏差功率");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_DPD_GetErrPower::~M_DPD_GetErrPower()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara);
}
int M_DPD_GetErrPower::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_OutputPara->paramName, "ErrPwr");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"0");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_DPD_GetErrPower::Run(void)
{
	int res;
	float errpwr;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	
	//DPD板
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	
	 res = DPD_GetErrPower(vHandle,&errpwr);
	 if (res == NTS_SUCCESS)
	 {
		 sprintf(m_OutputPara->paramVal, "%e", errpwr);
	 }
	 return res;
}

//class M_DPD_SetSixPwrFpg
M_DPD_SetSixPwrFpg::M_DPD_SetSixPwrFpg()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置6载波功率因子");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_DPD_SetSixPwrFpg::~M_DPD_SetSixPwrFpg()
{
//	free(m_InputDeviceName);
}
int M_DPD_SetSixPwrFpg::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	return NTS_SUCCESS;
}
int M_DPD_SetSixPwrFpg::Run(void)
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

	return DPD_SetSixPwrFpg(vHandle);
}

//class M_DPD_SetNinePwrFpg
M_DPD_SetNinePwrFpg::M_DPD_SetNinePwrFpg()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置9载功率波因子");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_DPD_SetNinePwrFpg::~M_DPD_SetNinePwrFpg()
{
//	free(m_InputDeviceName);
}
int M_DPD_SetNinePwrFpg::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	return NTS_SUCCESS;
}
int M_DPD_SetNinePwrFpg::Run(void)
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
		
	return DPD_SetNinePwrFpg(vHandle);
}

//class M_DPD_SetTwelvePwrFpg
M_DPD_SetTwelvePwrFpg::M_DPD_SetTwelvePwrFpg()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置12载功率波因子");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_DPD_SetTwelvePwrFpg::~M_DPD_SetTwelvePwrFpg()
{
//	free(m_InputDeviceName);
}
int M_DPD_SetTwelvePwrFpg::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	return NTS_SUCCESS;
}
int M_DPD_SetTwelvePwrFpg::Run(void)
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

	return DPD_SetTwelvePwrFpg(vHandle);
}

//M_DPD_SetErrPwrDebug
M_DPD_SetErrPwrDebug::M_DPD_SetErrPwrDebug()
:BaseMethod()
{
	sprintf(m_MethodScript, "DPD偏差功率调试(ErrPower:误差范围)");
	m_DPDDeviceName = CreateParamStruct();
	m_PSADeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}
M_DPD_SetErrPwrDebug::~M_DPD_SetErrPwrDebug()
{
//	free(m_DPDDeviceName);
//	free(m_PSADeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}
int M_DPD_SetErrPwrDebug::Init(void)
{
	sprintf(m_DPDDeviceName->paramName, "DPDConnectStr");
	m_DPDDeviceName->paramType = DPDDevice;
	m_DPDDeviceName->paramCount = 1;
	sprintf(m_DPDDeviceName->paramVal,"");
	sprintf(m_DPDDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_DPDDeviceName);
	
	sprintf(m_PSADeviceName->paramName, "PSAConnectStr");
	m_PSADeviceName->paramType = PSADevice;
	m_PSADeviceName->paramCount = 1;
	sprintf(m_PSADeviceName->paramVal,"");
	sprintf(m_PSADeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADeviceName);

	sprintf(m_InputPara1->paramName, "refpower");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "intervaltime");
	m_InputPara2->paramType = NTSUInt32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"500");
	sprintf(m_InputPara2->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "ErrPower");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"0.5");
	sprintf(m_InputPara3->paramUnit , "dB");
	m_InputParamVector.push_back(m_InputPara3);
	
	return NTS_SUCCESS;
}
int M_DPD_SetErrPwrDebug::Run(void)
{
	int res;
	float ErrPower, refpower,RealErrPwr;
	double diffpower;
	double value[300];
	long count;
	unsigned long intervaltime;
	int atten;
	int Amp;
	
	short int m_DPDHandle = 0, m_PSAHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	
	//DPD板
	sprintf(vDeviveName,m_DPDDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	m_DPDHandle = it->second.DevHandle;
	
	//频谱仪
	sprintf(vDeviveName,m_PSADeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	m_PSAHandle = it->second.DevHandle;
		
	refpower = atof(m_InputPara1->paramVal);
	intervaltime = atoi(m_InputPara2->paramVal);
	ErrPower = atof(m_InputPara3->paramVal);
	res = DPD_SetErrPwrDebug(m_DPDHandle,ErrPower,&RealErrPwr);
	if (res != NTS_SUCCESS) 
	{
		return res;
	}
	for(int i = 0 ;i < 5 ;i++)
	{
		res = DPD_GetErrPower(m_DPDHandle, &RealErrPwr);
		if(res !=NTS_SUCCESS)
		{
			return res;
		}
		Sleep(intervaltime);
		res = PSA_GetMULACPR(m_PSAHandle,value,&count);
		if(res !=NTS_SUCCESS)
		{
			return res;
		}
		diffpower = value[35] + RealErrPwr - refpower;
		if( diffpower >=0 && diffpower < 0.5)
		{
			if (diffpower >= 0.2)
			{
				//进行微调 步进 0.1dBm
				res = DPD_GetRFOutPower(m_DPDHandle, &Amp);
				if(res !=NTS_SUCCESS)
				{
					return res;
				}
				Amp = Amp + (diffpower - 0.1)/0.1;
				res = DPD_SetRFOutPower(m_DPDHandle, Amp);
				if(res !=NTS_SUCCESS)
				{
					return res;
				}
			}
			return NTS_SUCCESS;
		}
		res = DPD_GetRDAtten(m_DPDHandle, &atten);
		if(res != NTS_SUCCESS)
		{
			return res;
		}
		diffpower = value[35] + RealErrPwr - refpower;
		if (diffpower >= 0.5) 
		{
			atten = atten + 1;		
		}
		else 
		{
			atten = atten - 1;
		}
		res = DPD_SetRDAtten(m_DPDHandle, atten);
		if(res !=NTS_SUCCESS)
		{
			return res;
		}
	}
	return res;
}

//class M_DPD_ACPRPowerDebug
M_DPD_ACPRPowerDebug::M_DPD_ACPRPowerDebug()
:BaseMethod()
{
	sprintf(m_MethodScript,"ZX产品ACPR测试调整输出功率(refpower:目标功率值 IntervalTime:间隔时间)");
	m_DPDDeviceName = CreateParamStruct();
	m_PSADeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_DPD_ACPRPowerDebug::~M_DPD_ACPRPowerDebug()
{
//	free(m_DPDDeviceName);
//	free(m_PSADeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_DPD_ACPRPowerDebug::Init(void)
{
	sprintf(m_DPDDeviceName->paramName, "DPDConnectStr");
	m_DPDDeviceName->paramType = DPDDevice;
	m_DPDDeviceName->paramCount = 1;
	sprintf(m_DPDDeviceName->paramVal,"");
	sprintf(m_DPDDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_DPDDeviceName);

	sprintf(m_PSADeviceName->paramName, "PSAConnectStr");
	m_PSADeviceName->paramType = PSADevice;
	m_PSADeviceName->paramCount = 1;
	sprintf(m_PSADeviceName->paramVal,"");
	sprintf(m_PSADeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADeviceName);

	sprintf(m_InputPara1->paramName, "refpower");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "intervaltime");
	m_InputPara2->paramType = NTSUInt32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"500");
	sprintf(m_InputPara2->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_DPD_ACPRPowerDebug::Run(void)
{
	int retVal;
	double power;
	int TxAtten = 0x38, Offset;
	double diffpower;
	double value[300];
	long count;
	unsigned long intervaltime;
	
	short int m_DPDHandle = 0, m_PSAHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	
	//DPD板
	sprintf(vDeviveName,m_DPDDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	m_DPDHandle = it->second.DevHandle;
	
	//频谱仪
	sprintf(vDeviveName,m_PSADeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	m_PSAHandle = it->second.DevHandle;
	
	power = atof(m_InputPara1->paramVal);
	intervaltime = atoi(m_InputPara2->paramVal);	
	
	retVal = PSA_GetMULACPR(m_PSAHandle,value,&count);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	if((value[0] >= power )&&(value[0] <= (power+0.3))) 
	{
		return NTS_SUCCESS;
	}   

	retVal =DPD_GetTxAtten(m_DPDHandle,&TxAtten);
	if(retVal==NTS_SUCCESS)
	{
		diffpower = value[0]-power; 
		Offset = (short int )(diffpower/0.5);
		TxAtten = TxAtten - Offset;
		if((TxAtten)< 0||(TxAtten) > 0x3f)      
		{
			return NTS_POWER_EXTMAXPOWER_WARNING;     
		}
		retVal =DPD_SetTxAtten(m_DPDHandle,TxAtten);
	}
	
	for(int k=0; k < 10; k++)
	{ 
		Sleep(intervaltime);
		retVal =PSA_GetMULACPR(m_PSAHandle,value,&count);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}
		if((value[0] >= power )&&(value[0] <= (power+0.5))) 
		{
			return NTS_SUCCESS;
		}
		retVal =DPD_GetTxAtten(m_DPDHandle,&TxAtten);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}
		diffpower = value[0]-power; 
		if (fabs(diffpower) < 0.5)
		{
			return NTS_SUCCESS;
		}		
		if (diffpower > 0.5) 
		{
			TxAtten = TxAtten - 1;
		}
		else
		{
			TxAtten = TxAtten + 1;
		}	
		
		if((TxAtten)< 0||(TxAtten) > 0x3f)      
		{
			return NTS_POWER_EXTMAXPOWER_WARNING;     
		}
		retVal =DPD_SetTxAtten(m_DPDHandle,TxAtten);				
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}		
	}
	return NTS_SUCCESS;
}
//M_DPD_SetErrPwrDebugDT
M_DPD_SetErrPwrDebugDT::M_DPD_SetErrPwrDebugDT()
:BaseMethod()
{
	sprintf(m_MethodScript, "DT DPD偏差功率调试(ErrPower:误差范围)");
	m_DPDDeviceName = CreateParamStruct();
	m_PSADeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}
M_DPD_SetErrPwrDebugDT::~M_DPD_SetErrPwrDebugDT()
{
//	free(m_DPDDeviceName);
//	free(m_PSADeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}
int M_DPD_SetErrPwrDebugDT::Init(void)
{
	sprintf(m_DPDDeviceName->paramName, "DPDConnectStr");
	m_DPDDeviceName->paramType = DPDDevice;
	m_DPDDeviceName->paramCount = 1;
	sprintf(m_DPDDeviceName->paramVal,"");
	sprintf(m_DPDDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_DPDDeviceName);
	
	sprintf(m_PSADeviceName->paramName, "PSAConnectStr");
	m_PSADeviceName->paramType = PSADevice;
	m_PSADeviceName->paramCount = 1;
	sprintf(m_PSADeviceName->paramVal,"");
	sprintf(m_PSADeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADeviceName);

	sprintf(m_InputPara1->paramName, "refpower");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "intervaltime");
	m_InputPara2->paramType = NTSUInt32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"500");
	sprintf(m_InputPara2->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "ErrPower");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"0.5");
	sprintf(m_InputPara3->paramUnit , "dB");
	m_InputParamVector.push_back(m_InputPara3);
	
	return NTS_SUCCESS;
}
int M_DPD_SetErrPwrDebugDT::Run(void)
{
	int res;
	float ErrPower, refpower,RealErrPwr;
//	float diffpower;
//	float value[300];
//	long count;
	unsigned long intervaltime;
//	int atten;
//	int Amp;
	
	short int m_DPDHandle = 0, m_PSAHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	
	//DPD板
	sprintf(vDeviveName,m_DPDDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	m_DPDHandle = it->second.DevHandle;
		
	//频谱仪
	sprintf(vDeviveName,m_PSADeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	m_PSAHandle = it->second.DevHandle;
	
	refpower = atof(m_InputPara1->paramVal);
	intervaltime = atoi(m_InputPara2->paramVal);
	ErrPower = atof(m_InputPara3->paramVal);
	res = DPD_SetErrPwrDebug(m_DPDHandle,ErrPower,&RealErrPwr);
	if (res != NTS_SUCCESS) 
	{
		return res;
	}	
	return res;
}
//class M_DPD_SetWorkFreq
M_DPD_SetWorkFreq::M_DPD_SetWorkFreq()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置DPD工作频率(1:2017.5M 2:1890M 3:875/930/1810/1935");
	sprintf(m_MethodScript, "%s%s", m_MethodScript, " 4:880/946.8/1830/1960  5:885/955/1855/1985");
	sprintf(m_MethodScript, "%s%s", m_MethodScript, " 6:1830M 7:1850M 8:1875M 9:1910M 10:1890M)");
		sprintf(m_MethodScript, "%s%s", m_MethodScript, " 11:2336M 12:2365M)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_DPD_SetWorkFreq::~M_DPD_SetWorkFreq()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_DPD_SetWorkFreq::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "FreqMode");
	m_InputPara->paramType = NTSInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_DPD_SetWorkFreq::Run(void)
{
	int FreqMode;
	
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
	
	FreqMode = atoi(m_InputPara->paramVal);
	return DPD_SetWorkFreq(vHandle,FreqMode);
}
//class M_DPD_ACPRPowerDebugDT
M_DPD_ACPRPowerDebugDT::M_DPD_ACPRPowerDebugDT()
:BaseMethod()
{
	sprintf(m_MethodScript,"DT产品ACPR测试调整输出功率(refpower:目标功率值 IntervalTime:间隔时间)");
	m_DPDDeviceName = CreateParamStruct();
	m_PSADeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_DPD_ACPRPowerDebugDT::~M_DPD_ACPRPowerDebugDT()
{
//	free(m_DPDDeviceName);
//	free(m_PSADeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_DPD_ACPRPowerDebugDT::Init(void)
{
	sprintf(m_DPDDeviceName->paramName, "DPDConnectStr");
	m_DPDDeviceName->paramType = DPDDevice;
	m_DPDDeviceName->paramCount = 1;
	sprintf(m_DPDDeviceName->paramVal,"");
	sprintf(m_DPDDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_DPDDeviceName);

	sprintf(m_PSADeviceName->paramName, "PSAConnectStr");
	m_PSADeviceName->paramType = PSADevice;
	m_PSADeviceName->paramCount = 1;
	sprintf(m_PSADeviceName->paramVal,"");
	sprintf(m_PSADeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADeviceName);

	sprintf(m_InputPara1->paramName, "refpower");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "intervaltime");
	m_InputPara2->paramType = NTSUInt32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"500");
	sprintf(m_InputPara2->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}
int M_DPD_ACPRPowerDebugDT::Run(void)
{
	int retVal;
	int k;
	float power;
	int TxAtten = 31, Offset;
	double SmallAtten;
	float diffpower;
	double value[300];
	long count;
	unsigned long intervaltime;
	
	short int m_DPDHandle = 0, m_PSAHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	
	//DPD板
	sprintf(vDeviveName,m_DPDDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	m_DPDHandle = it->second.DevHandle;
	
	//频谱仪
	sprintf(vDeviveName,m_PSADeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	m_PSAHandle = it->second.DevHandle;

	power = atof(m_InputPara1->paramVal);
	intervaltime = atoi(m_InputPara2->paramVal);	
	//粗调输出功率值 步进 1dB
	for(int k=0; k < 10; k++)
	{ 
		Sleep(intervaltime);
		retVal = PSA_GetMULACPR(m_PSAHandle,value,&count);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}
		if((value[35] >= (power - 0.67) )&&(value[35] <= (power+0.67))) 
		{
			break;
		}   
		retVal =DPD_GetTxAtten(m_DPDHandle,&TxAtten);
		if(retVal==NTS_SUCCESS)
		{
			diffpower = power - value[35]; 
			Offset = (short int )(diffpower);
			//四舍五入
			if (diffpower - Offset > 0.5)
			{
				Offset = Offset + 1;
			}
			else if (diffpower - Offset < -0.5)
			{
				Offset = Offset - 1;
			}
			TxAtten = TxAtten - Offset;
			if((TxAtten)< 0||(TxAtten) > 31)      
			{
				return NTS_POWER_EXTMAXPOWER_WARNING;     
			}
			retVal =DPD_SetTxAtten(m_DPDHandle,TxAtten);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
		}
	}
	
	//细调输出功率值 [-2,2]
	for(k=0; k < 10; k++)
	{ 		
		if((value[35] >= power - 0.1 )&&(value[35] <= (power+0.15))) 
		{			
			return NTS_SUCCESS;
		}
		diffpower =  power - value[35];		
		retVal = DPD_GetSmallTxAtten(m_DPDHandle,&SmallAtten);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}			
		SmallAtten = SmallAtten + diffpower; 		
		retVal =DPD_SetSmallTxAtten(m_DPDHandle,SmallAtten);				
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}	
		Sleep(intervaltime);
		retVal =PSA_GetMULACPR(m_PSAHandle,value,&count);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}
	}
	return NTS_SUCCESS;
}

//class M_DPD_SetSGMode
M_DPD_SetSGMode::M_DPD_SetSGMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置DPD信号模式(0:GMSK  1:8PSK 2:GMSK+8PSK)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_DPD_SetSGMode::~M_DPD_SetSGMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_DPD_SetSGMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "SGMode");
	m_InputPara->paramType = NTSInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_DPD_SetSGMode::Run(void)
{
	int Mode;
	
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
		
	Mode = atoi(m_InputPara->paramVal);
	return DPD_SetSGMode(vHandle, Mode);
}

//class M_DPD_SetCarriedMode
M_DPD_SetCarriedMode::M_DPD_SetCarriedMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "%s","设置DPD载波模式(0:3M等间隔 1:3M不等间隔 2:5M等间隔 3:5M不等间隔 4:10M等间隔");
	sprintf(m_MethodScript, "%s%s", m_MethodScript, " 5:10M不等间隔	6:15M等间隔 7:15M不等间隔 8:1.8M 9:19.8M 10:20M)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_DPD_SetCarriedMode::~M_DPD_SetCarriedMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_DPD_SetCarriedMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "CarriedMode");
	m_InputPara->paramType = NTSInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_DPD_SetCarriedMode::Run(void)
{
	int Mode;
	
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
	
	Mode = atoi(m_InputPara->paramVal);
	return DPD_SetCarriedMode(vHandle,Mode);
}

//class M_DPD_SetCarriedCount
M_DPD_SetCarriedCount::M_DPD_SetCarriedCount()
:BaseMethod()
{
	sprintf(m_MethodScript, "%s","设置载波个数(0:3载波	1:4载波	2:6载波  3:12载波 4:18载波)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}
M_DPD_SetCarriedCount::~M_DPD_SetCarriedCount()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}
int M_DPD_SetCarriedCount::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "CarriedCount");
	m_InputPara->paramType = NTSInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_DPD_SetCarriedCount::Run(void)
{
	int Count;
	
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
	
	Count = atoi(m_InputPara->paramVal);
	return DPD_SetCarriedCount(vHandle,Count);
}

//class M_DPD_Reset
M_DPD_Reset::M_DPD_Reset()
:BaseMethod()
{
	sprintf(m_MethodScript, "复位");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_DPD_Reset::~M_DPD_Reset()
{
//	free(m_InputDeviceName);
}
int M_DPD_Reset::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	return NTS_SUCCESS;
}
int M_DPD_Reset::Run(void)
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
		
	return DPD_Reset(vHandle);
}


//class M_DPD_PRMPowerDebug
M_DPD_PRMPowerDebug::M_DPD_PRMPowerDebug()
:BaseMethod()
{
	sprintf(m_MethodScript,"在功率计下调整输出功率(refpower:目标功率值 IntervalTime:间隔时间)");
	m_DPDDevName = CreateParamStruct();
	m_PRMDevName = CreateParamStruct();

	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_DPD_PRMPowerDebug::~M_DPD_PRMPowerDebug()
{
//	free(m_DPDDevName);
//	free(m_PRMDevName);

//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_DPD_PRMPowerDebug::Init(void)
{
	sprintf(m_DPDDevName->paramName, "DPD_ConnectStr");
	m_DPDDevName->paramType = DPDDevice;
	m_DPDDevName->paramCount = 1;
	sprintf(m_DPDDevName->paramVal,"");
	sprintf(m_DPDDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_DPDDevName);
	
	sprintf(m_PRMDevName->paramName, "PRM_ConnectStr");
	m_PRMDevName->paramType = PRMDevice;
	m_PRMDevName->paramCount = 1;
	sprintf(m_PRMDevName->paramVal,"");
	sprintf(m_PRMDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_PRMDevName);

	sprintf(m_InputPara1->paramName, "refpower");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "intervaltime");
	m_InputPara2->paramType = NTSUInt32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"500");
	sprintf(m_InputPara2->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara2);

	return NTS_SUCCESS;
}
int M_DPD_PRMPowerDebug::Run(void)
{
	int retVal;
	float power, diffpower;
	float m_Pwr, m_Swr;
	int intervaltime;
	int TxAtten, Offset;
	short int m_DPDHandle = 0,m_PRMHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	//DPD工装板句柄
	sprintf(vDeviveName,m_DPDDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	m_DPDHandle = it->second.DevHandle;
	
	//功率计句柄
	sprintf(vDeviveName,m_PRMDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	m_PRMHandle = it->second.DevHandle;
	
	power = atof(m_InputPara1->paramVal);	
	intervaltime = atoi(m_InputPara2->paramVal);
	
	if(m_DPDHandle < 0)
	{		
		return NTS_INVALID_DEVICE;
	}
	if(m_PRMHandle < 0)
	{		
		return NTS_INVALID_DEVICE;
	}
	
	//粗调输出功率值 步进 0.5dB
	for(int k=0; k < 10; k++)
	{ 
		Sleep(intervaltime);
		retVal = PRM_GetPower(m_PRMHandle,&m_Pwr, &m_Swr);
		if(retVal!=NTS_SUCCESS)
		{
			return NTS_POWER_EXTMAXPOWER_WARNING;
		}
		if((m_Pwr >= (power - 0.25) )&&(m_Pwr <= (power+0.25))) 
		{
			break;
		}   
		retVal =DPD_GetTxAtten(m_DPDHandle,&TxAtten);
		if(retVal==NTS_SUCCESS)
		{
			diffpower =  m_Pwr - power; 
			Offset = (short int )(diffpower/0.5 * 5);			
			TxAtten = TxAtten + Offset;
			
			if(TxAtten<0 ||TxAtten > 300)      
			{
				return NTS_POWER_EXTMAXPOWER_WARNING;     
			}
			retVal =DPD_SetTxAtten(m_DPDHandle,TxAtten);
			if(retVal!=NTS_SUCCESS)
			{
				return NTS_POWER_EXTMAXPOWER_WARNING;
			}
		}
	}

	return NTS_SUCCESS;
}

//M_DPD_GetIDN 
M_DPD_GetIDN::M_DPD_GetIDN()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取生产信息");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	Init();
}
M_DPD_GetIDN::~M_DPD_GetIDN()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);
}
int M_DPD_GetIDN::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "IDN");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_DPD_GetIDN::Run(void)
{
	int res;
	short int vHandle = 0;	
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char IDN[100] = {0};
	
	return NTS_INVALID_METHOD;

	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	res = DPD_GetIDN(vHandle, IDN);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%s", IDN);
	}
	return res;
}

//class M_DPD_SendCmd 
M_DPD_SendCmd::M_DPD_SendCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_DPD_SendCmd::~M_DPD_SendCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_DPD_SendCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
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
int M_DPD_SendCmd::Run(void)
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
	return DPD_SendCmd(vHandle, CmdStr);
}

//class M_DPD_GetCmd 获取返回指令值
M_DPD_GetCmd::M_DPD_GetCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令并获取指令的返回数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();	
	Init();
}

M_DPD_GetCmd::~M_DPD_GetCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara1);
}

int M_DPD_GetCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
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
int M_DPD_GetCmd::Run(void)
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
	res = DPD_GetCmd(vHandle, CmdStr, RetStr);
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

//class M_DPD_SetRFOutPower 
M_DPD_SetRFOutPower::M_DPD_SetRFOutPower()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置DPD输出功率");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}
M_DPD_SetRFOutPower::~M_DPD_SetRFOutPower()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_DPD_SetRFOutPower::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "Power");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_DPD_SetRFOutPower::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int vPower;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	vPower = atoi(m_InputPara1->paramVal);
	return DPD_SetRFOutPower(vHandle, vPower);
}

//class M_DPD_GetRFOutPower 
M_DPD_GetRFOutPower::M_DPD_GetRFOutPower()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取DPD输出功率");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}
M_DPD_GetRFOutPower::~M_DPD_GetRFOutPower()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);	
}

int M_DPD_GetRFOutPower::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "Power");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_DPD_GetRFOutPower::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int vPower;
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	res = DPD_GetRFOutPower(vHandle, &vPower);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%d", vPower);
	}
	return res;
}

//class M_DPD_SetCFR 
M_DPD_SetCFR::M_DPD_SetCFR()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置CFR门限值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}
M_DPD_SetCFR::~M_DPD_SetCFR()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_DPD_SetCFR::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "CFR");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_DPD_SetCFR::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int vCFR;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	vCFR = atoi(m_InputPara1->paramVal);
	return DPD_SetCFR(vHandle, vCFR);
}

//class M_DPD_GetCFR
M_DPD_GetCFR::M_DPD_GetCFR()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取CFR门限值");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}
M_DPD_GetCFR::~M_DPD_GetCFR()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);	
}

int M_DPD_GetCFR::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "CFR");
	m_OutputPara1->paramType = NTSInt16;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_DPD_GetCFR::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	unsigned int vCFR;
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	res = DPD_GetCFR(vHandle, &vCFR);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%d", vCFR);
	}
	return res;
}

//class M_DPD_GetRDAtten
M_DPD_GetRDAtten::M_DPD_GetRDAtten()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取反馈通道衰减值");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}
M_DPD_GetRDAtten::~M_DPD_GetRDAtten()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);	
}

int M_DPD_GetRDAtten::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "Atten");
	m_OutputPara1->paramType = NTSInt16;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_DPD_GetRDAtten::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int vAtten;
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	res = DPD_GetRDAtten(vHandle, &vAtten);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%d", vAtten);
	}
	return res;
}

//class M_DPD_GetTxAtten 
M_DPD_GetTxAtten::M_DPD_GetTxAtten()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取发射通道衰减值");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}
M_DPD_GetTxAtten::~M_DPD_GetTxAtten()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);	
}

int M_DPD_GetTxAtten::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "Atten");
	m_OutputPara1->paramType = NTSInt16;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_DPD_GetTxAtten::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int vAtten;
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	res = DPD_GetTxAtten(vHandle, &vAtten);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%d", vAtten);
	}
	return res;
}

//class M_DPD_GetSmallTxAtten 
M_DPD_GetSmallTxAtten::M_DPD_GetSmallTxAtten()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取输出TX链路细调功率值");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}
M_DPD_GetSmallTxAtten::~M_DPD_GetSmallTxAtten()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);	
}

int M_DPD_GetSmallTxAtten::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "Atten");
	m_OutputPara1->paramType = NTSReal64;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_DPD_GetSmallTxAtten::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	double vAtten;
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	res = DPD_GetSmallTxAtten(vHandle, &vAtten);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%e", vAtten);
	}
	return res;
}

// M_DPD_ReadDev
M_DPD_ReadDev::M_DPD_ReadDev()
:BaseMethod()
{
	sprintf(m_MethodScript, "读取设备返回数据");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}
M_DPD_ReadDev::~M_DPD_ReadDev()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);	
}

int M_DPD_ReadDev::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = DPDDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "RetStr");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}
int M_DPD_ReadDev::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	char vBuffer[LPARALENGTH];
	int vRealCount;
	int res;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	res = DPD_ReadDev(vHandle, vBuffer, sizeof(vBuffer), &vRealCount);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%s", vBuffer);
	}
	return res;
}
