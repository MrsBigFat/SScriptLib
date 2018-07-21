
#include "stdafx.h"
#include "DADebugMethod.h"
#include <assert.h>
#include "stdio.h"
//#include <map>

extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

//class M_DEB_WriteDebug
M_DEB_WriteDebug::M_DEB_WriteDebug()
:BaseMethod()
{
	sprintf(m_MethodScript, "DA调试");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	m_OutputPara3 = CreateParamStruct();
	m_OutputPara4 = CreateParamStruct();
	Init();
}
M_DEB_WriteDebug::~M_DEB_WriteDebug()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
	
//	free(m_OutputPara1);
//	free(m_OutputPara2);
//	free(m_OutputPara3);
//	free(m_OutputPara4);
}
int M_DEB_WriteDebug::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara1->paramName, "MMTComPort");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "ParaTypeName");
	m_InputPara2->paramType = NTSString;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "CHIndex");
	m_InputPara3->paramType = NTSInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara3);
	
	sprintf(m_OutputPara1->paramName, "GainCount");
	m_OutputPara1->paramType = NTSInt16;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	sprintf(m_OutputPara2->paramName, "RFTemperature");
	m_OutputPara2->paramType = NTSInt16Array;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara2);
	
	sprintf(m_OutputPara3->paramName, "DACount");
	m_OutputPara3->paramType = NTSInt16;
	m_OutputPara3->paramCount = 1;
	sprintf(m_OutputPara3->paramVal,"");
	sprintf(m_OutputPara3->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara3);
	
	sprintf(m_OutputPara4->paramName, "DAVaule");
	m_OutputPara4->paramType = NTSInt16Array;
	m_OutputPara4->paramCount = 1;
	sprintf(m_OutputPara4->paramVal,"");
	sprintf(m_OutputPara4->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara4);
	
	return NTS_SUCCESS;
}
int M_DEB_WriteDebug::Run(void)
{
	int res,i;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	char RetStr[4000] = {0};

	int MMTComPort,chIndex;
	char TerminalParaName[100];
	int GainCount, DACount;
	float RFTemperature[4094],DAVaule[4094];

	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	//电流表串口号
	MMTComPort = atoi(m_InputPara1->paramVal);
	//调试参数名
	sprintf( TerminalParaName, m_InputPara2->paramVal);
	//通道号
	chIndex = atoi(m_InputPara3->paramVal);

	res = AD_WriteDebug(vHandle,MMTComPort,TerminalParaName,chIndex,
		&GainCount, RFTemperature,&DACount, DAVaule);
	if (res != NTS_SUCCESS) 
	{
		return res;
	}
	///////////////////////////组织返回数据///////////////////////////////////	
	//功放级数
	sprintf(m_OutputPara1->paramVal , "%d", GainCount);
	//参考温度和DA
	sprintf(m_OutputPara2->paramVal, "%0.3f", RFTemperature[0]);
	for(i = 1;i< 2*GainCount;i++)
	{
		sprintf(m_OutputPara2->paramVal,"%s%s%0.3f",m_OutputPara2->paramVal, ",",RFTemperature[i]);
	}
	//温度点数
	sprintf(m_OutputPara3->paramVal, "%d", DACount);
	
	//计算出来的DA值(数量等于温度点数*功放个数)
	sprintf(RetStr,"%d", (int)DAVaule[0]);
	for(i = 1;i< GainCount*DACount ; i++)
	{
		sprintf(RetStr,"%s%s%d", RetStr, "," , (int)DAVaule[i]);
	}	
	if (strlen(RetStr) > PARALENGTH)
	{		
		m_OutputPara4->LparamVal = (char *)malloc((strlen(RetStr) + 10)*sizeof(char));
		sprintf(m_OutputPara4->LparamVal, "%s", RetStr);
	}
	else
	{
		sprintf(m_OutputPara4->paramVal, "%s", RetStr);
	}
	return res;
}

//M_DEB_ReadDebug
M_DEB_ReadDebug::M_DEB_ReadDebug()
:BaseMethod()
{
	sprintf(m_MethodScript, "读取调试数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	
	
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	m_OutputPara3 = CreateParamStruct();

	Init();
}
M_DEB_ReadDebug::~M_DEB_ReadDebug()
{
//	free(m_InputDeviceName);
//	free(m_InputPara1);

//	free(m_OutputPara1);
//	free(m_OutputPara2);
//	free(m_OutputPara3);

}
int M_DEB_ReadDebug::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);

	sprintf(m_InputPara1->paramName, "CHIndex");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_OutputPara1->paramName, "GainCount");
	m_OutputPara1->paramType = NTSInt16;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);

	sprintf(m_OutputPara2->paramName, "DACount");
	m_OutputPara2->paramType = NTSInt16;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara2);

	sprintf(m_OutputPara3->paramName, "DAVaule");
	m_OutputPara3->paramType = NTSInt16Array;
	m_OutputPara3->paramCount = 1;
	sprintf(m_OutputPara3->paramVal,"");
	sprintf(m_OutputPara3->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara3);
	
	return NTS_SUCCESS;
}
int M_DEB_ReadDebug::Run(void)
{
	int res = 0;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	

	int chIndex;
	int GainCount = 0, DACount;
	float DAVaule[4094];
	char RetStr[LPARALENGTH] = {0};
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	
	chIndex = atoi(m_InputPara1->paramVal);
	res = AD_ReadDebug(vHandle,chIndex,&GainCount, &DACount, DAVaule);
	if (res != NTS_SUCCESS)
	{
		return res;		
	}

	//组织返回数据
	sprintf(m_OutputPara1->paramVal , "%d", GainCount);	
	sprintf(m_OutputPara2->paramVal, "%d", DACount);
	sprintf(RetStr, "%e", DAVaule[0]);
	for(int i = 1;i< GainCount*DACount ; i++)
	{
		sprintf(RetStr, "%s%s%e", RetStr, ",", DAVaule[i]);
	}
	if (strlen(RetStr) > PARALENGTH)
	{		
		m_OutputPara3->LparamVal = (char *)malloc((strlen(RetStr) + 10)*sizeof(char));
		sprintf(m_OutputPara3->LparamVal, "%s", RetStr);
	}
	else
	{
		sprintf(m_OutputPara3->paramVal, "%s", RetStr);
	}
	return res;
}