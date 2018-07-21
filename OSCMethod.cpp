
#include "stdafx.h"
#include "OSCMethod.h"
#include <assert.h>
#include "stdio.h"
#include <map>


extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

/************************************************************************/
/*  驱动程序方法类                                            */
/************************************************************************/
//class M_OSC_SetDTLEVParam
M_OSC_SetDTLEVParam::M_OSC_SetDTLEVParam()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Dtime@level模式参数，Slope(1:POS,2:NEG,3:BOTH)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara0 = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	m_InputPara4 = CreateParamStruct();
	m_InputPara5 = CreateParamStruct();
	m_InputPara6 = CreateParamStruct();

	Init();
}
M_OSC_SetDTLEVParam::~M_OSC_SetDTLEVParam()
{
	//	free(m_InputDeviceName);
	//	free(m_OutputPara);
}
 
int M_OSC_SetDTLEVParam::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara0->paramName, "P");
	m_InputPara0->paramType = NTSInt8;
	m_InputPara0->paramCount = 1;
	sprintf(m_InputPara0->paramVal,"1");
	sprintf(m_InputPara0->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara0);	

	sprintf(m_InputPara1->paramName, "Source1");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "Slope1");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "level1");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"50");
	sprintf(m_InputPara3->paramUnit , "%");
	m_InputParamVector.push_back(m_InputPara3);

	sprintf(m_InputPara4->paramName, "Source2");
	m_InputPara4->paramType = NTSInt8;
	m_InputPara4->paramCount = 1;
	sprintf(m_InputPara4->paramVal,"2");
	sprintf(m_InputPara4->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara4);

	sprintf(m_InputPara5->paramName, "Slope2");
	m_InputPara5->paramType = NTSInt8;
	m_InputPara5->paramCount = 1;
	sprintf(m_InputPara5->paramVal,"1");
	sprintf(m_InputPara5->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara5);

	sprintf(m_InputPara6->paramName, "level2");
	m_InputPara6->paramType = NTSReal32;
	m_InputPara6->paramCount = 1;
	sprintf(m_InputPara6->paramVal,"50");
	sprintf(m_InputPara6->paramUnit , "%");
	m_InputParamVector.push_back(m_InputPara6);

	return NTS_SUCCESS;
}
int M_OSC_SetDTLEVParam::Run(void)
{
	double abslev1,abslev2;	
	short int channel1,channel2,slope1,slope2,pos;	
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

	pos = atoi(m_InputPara0->paramVal);
	channel1 = atoi(m_InputPara1->paramVal);
	slope1 = atoi(m_InputPara2->paramVal);
	abslev1 = atof(m_InputPara3->paramVal);
	channel2 = atoi(m_InputPara4->paramVal);
	slope2 = atoi(m_InputPara5->paramVal);
	abslev2 = atof(m_InputPara6->paramVal);

	return OSC_SetDTLEVParam(vHandle,pos,channel1,slope1,abslev1,channel2,slope2,abslev2);
	return NTS_SUCCESS;
} 
//class M_OSC_Reset
M_OSC_Reset::M_OSC_Reset()
:BaseMethod()
{
	sprintf(m_MethodScript, "示波器复位");
	m_InputDeviceName = CreateParamStruct();
	Init();
}
M_OSC_Reset::~M_OSC_Reset()
{
//	free(m_InputDeviceName);
}

int M_OSC_Reset::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	return NTS_SUCCESS;
}
int M_OSC_Reset::Run(void)
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

	return OSC_Reset(vHandle);
	return NTS_SUCCESS;
	
}

//class M_OSC_SetGrid
M_OSC_SetGrid::M_OSC_SetGrid()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Grid,参数(1:Single Grid,2:Dual Grid,3:Quad Grid,4:Octal Grid,5:Auto Grid)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	Init();
}
M_OSC_SetGrid::~M_OSC_SetGrid()
{
}

int M_OSC_SetGrid::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "gridType");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	return NTS_SUCCESS;
}
int M_OSC_SetGrid::Run(void)
{
	short int gridType;	
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

	gridType = atoi(m_InputPara1->paramVal);
	return OSC_SetGrid(vHandle,gridType);
	return NTS_SUCCESS;
	
}

//class M_OSC_SetTrigType
M_OSC_SetTrigType::M_OSC_SetTrigType()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Trig类型,参数(1:Edge, 2:Width, 3:Pattern, 4:Smart, 5:Measurement, 6:TV, 7:Multistage, 8:Serial),Source(1:C1, 2:C2, 3:C3, 4:C4, 5:EXT, 6:Line, 7:FastEdge)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	m_InputPara2= CreateParamStruct();
	Init();
}
M_OSC_SetTrigType::~M_OSC_SetTrigType()
{
}

int M_OSC_SetTrigType::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "trigType");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "source");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"2");
	sprintf(m_InputPara2->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara2);


	return NTS_SUCCESS;
}
int M_OSC_SetTrigType::Run(void)
{
	short int trigType;	
	short int source;
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

	trigType = atoi(m_InputPara1->paramVal);
	source = atoi(m_InputPara2->paramVal);
	return OSC_SetTrigType(vHandle,trigType,source);
	return NTS_SUCCESS;
	
}

//class M_OSC_SetTrigCoupling
M_OSC_SetTrigCoupling::M_OSC_SetTrigCoupling()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置TrigCoupling,source参数(1:C1, 2:C2, 3:C3, 4:C4, 5:EXT),coupling参数(1:DC, 2:AC, 3:LFREJ, 4:HFREJ)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	m_InputPara2= CreateParamStruct();
	Init();
}
M_OSC_SetTrigCoupling::~M_OSC_SetTrigCoupling()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_OSC_SetTrigCoupling::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "source");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "coupling");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_OSC_SetTrigCoupling::Run(void)
{
	double source,coupling;	
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

	source = atoi(m_InputPara1->paramVal);
	coupling = atof(m_InputPara2->paramVal);
	return OSC_SetTrigCoupling(vHandle,source,coupling);
	return NTS_SUCCESS;
	
}


//class M_OSC_SetTrigSlope
M_OSC_SetTrigSlope::M_OSC_SetTrigSlope()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置TrigSlope,source参数(1:C1, 2:C2, 3:C3, 4:C4, 5:EXT),slope参数(1:Positive, 2:Negative, 3:Either)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	m_InputPara2= CreateParamStruct();
	Init();
}
M_OSC_SetTrigSlope::~M_OSC_SetTrigSlope()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_OSC_SetTrigSlope::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "source");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "slope");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_OSC_SetTrigSlope::Run(void)
{
	double source,slope;	
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

	source = atoi(m_InputPara1->paramVal);
	slope = atoi(m_InputPara2->paramVal);
	return OSC_SetTrigSlope(vHandle,source,slope);
	return NTS_SUCCESS;
}

//class M_OSC_SetTrigLevel
M_OSC_SetTrigLevel::M_OSC_SetTrigLevel()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置TrigLevel,source参数(1:C1, 2:C2, 3:C3, 4:C4, 5:EXT, 6:Line, 7:FastEdge),Level单位为mv");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	m_InputPara2= CreateParamStruct();
	Init();
}
M_OSC_SetTrigLevel::~M_OSC_SetTrigLevel()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_OSC_SetTrigLevel::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "source");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "level");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "mV");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_OSC_SetTrigLevel::Run(void)
{
	double source,level;	
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

	source = atof(m_InputPara1->paramVal);
	level = atof(m_InputPara2->paramVal);
	return OSC_SetTrigLevel(vHandle,source,level);
	return NTS_SUCCESS;
}

//class M_OSC_SetScaleVDIV
M_OSC_SetScaleVDIV::M_OSC_SetScaleVDIV()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Vertical Scale,V/Div单位为mv");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	m_InputPara2= CreateParamStruct();
	Init();
}
M_OSC_SetScaleVDIV::~M_OSC_SetScaleVDIV()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_OSC_SetScaleVDIV::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "channel");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "V/Div");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "mv");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_OSC_SetScaleVDIV::Run(void)
{
	double channel,VDIV;	
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

	channel = atof(m_InputPara1->paramVal);
	VDIV = atof(m_InputPara2->paramVal);
	return OSC_SetScaleVDIV(vHandle,channel,VDIV);
	return NTS_SUCCESS;
}

//class M_OSC_SetScaleTDIV
M_OSC_SetScaleTDIV::M_OSC_SetScaleTDIV()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Timebase Scale,T/Div单位为NS");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	Init();
}
M_OSC_SetScaleTDIV::~M_OSC_SetScaleTDIV()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_OSC_SetScaleTDIV::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "T/Div");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "ns");
	m_InputParamVector.push_back(m_InputPara1);
	return NTS_SUCCESS;
}
int M_OSC_SetScaleTDIV::Run(void)
{
	double TDIV;	
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

	TDIV = atof(m_InputPara1->paramVal);
	return OSC_SetScaleTDIV(vHandle, TDIV);
	return NTS_SUCCESS;
}

//class M_OSC_GetMeaValue
M_OSC_GetMeaValue::M_OSC_GetMeaValue()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取DTime@Level值");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	Init();
}
M_OSC_GetMeaValue::~M_OSC_GetMeaValue()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_OSC_GetMeaValue::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "P");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_OutputPara1->paramName, "DTLValue");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	return NTS_SUCCESS;
}
int M_OSC_GetMeaValue::Run(void)
{
	int retVal;
	short int point;	
	char dtlvalue[200000] = {0};
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

	point = atoi(m_InputPara1->paramVal);
	retVal = OSC_GetMeaValue(vHandle,point,dtlvalue);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal,"%s",dtlvalue);
	}
	return retVal;
}

//class M_OSC_SetTrigMode
M_OSC_SetTrigMode::M_OSC_SetTrigMode()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置TrigMode,Mode:(1:Auto,2:Normal,3:Single,4:Stop)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1= CreateParamStruct();
	Init();
}
M_OSC_SetTrigMode::~M_OSC_SetTrigMode()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_OSC_SetTrigMode::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "Mode");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);
	return NTS_SUCCESS;
}
int M_OSC_SetTrigMode::Run(void)
{
	double mode;	
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

	mode = atoi(m_InputPara1->paramVal);
	return OSC_SetTrigMode(vHandle, mode);
	return NTS_SUCCESS;
}
//class M_OSC_SendCmd 
M_OSC_SendCmd::M_OSC_SendCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	Init();
}

M_OSC_SendCmd::~M_OSC_SendCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
}

int M_OSC_SendCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
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
int M_OSC_SendCmd::Run(void)
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
	return OSC_SendCmd(vHandle, CmdStr);
}
//class M_OSC_GetCmd 
M_OSC_GetCmd::M_OSC_GetCmd()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送指令并获取指令的返回数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_OSC_GetCmd::~M_OSC_GetCmd()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);	
//	free(m_OutputPara1);
}

int M_OSC_GetCmd::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
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
int M_OSC_GetCmd::Run(void)
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
	res = OSC_GetCmd(vHandle, CmdStr, RetStr);
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

//class M_OSC_SetDeltaDelay
M_OSC_SetDeltaDelay::M_OSC_SetDeltaDelay()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置DeltaDelay模式参数");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara0 = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_OSC_SetDeltaDelay::~M_OSC_SetDeltaDelay()
{
	//	free(m_InputDeviceName);
	//	free(m_OutputPara);
}
 
int M_OSC_SetDeltaDelay::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara0->paramName, "P");
	m_InputPara0->paramType = NTSInt8;
	m_InputPara0->paramCount = 1;
	sprintf(m_InputPara0->paramVal,"1");
	sprintf(m_InputPara0->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara0);	

	sprintf(m_InputPara1->paramName, "Source1");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"2");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "Source1");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"3");
	sprintf(m_InputPara2->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara2);


	return NTS_SUCCESS;
}
int M_OSC_SetDeltaDelay::Run(void)
{
	short int channel1,channel2,pos;	
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

	pos = atoi(m_InputPara0->paramVal);
	channel1 = atoi(m_InputPara1->paramVal);
	channel2 = atoi(m_InputPara2->paramVal);


	return OSC_SetDeltaDelay(vHandle,pos,channel1,channel2);
	return NTS_SUCCESS;
} 


//class M_OSC_SetTraceDis
M_OSC_SetTraceDis::M_OSC_SetTraceDis()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置Trace显示,Switch(0:OFF, 1:ON)");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_OSC_SetTraceDis::~M_OSC_SetTraceDis()
{
	//	free(m_InputDeviceName);
	//	free(m_OutputPara);
}
 
int M_OSC_SetTraceDis::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = OSCDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "Channel");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"2");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "ON/OFF");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara2);


	return NTS_SUCCESS;
}
int M_OSC_SetTraceDis::Run(void)
{
	short int channel,Switch;	
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

	channel = atoi(m_InputPara1->paramVal);
	Switch = atoi(m_InputPara2->paramVal);


	return OSC_SetTraceDis(vHandle,channel,Switch);
	return NTS_SUCCESS;
} 