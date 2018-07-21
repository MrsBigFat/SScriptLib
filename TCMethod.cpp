
#include "stdafx.h"
#include "TCMethod.h"
#include <assert.h>
#include "stdio.h"


extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

//class M_TC_GetCardMCUVersion
M_TC_GetCardMCUVersion::M_TC_GetCardMCUVersion()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取测试卡MCU的软件版本");
	m_OutputPara = CreateParamStruct();
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_TC_GetCardMCUVersion::~M_TC_GetCardMCUVersion()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara);
}

int M_TC_GetCardMCUVersion::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara->paramName, "Version");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_TC_GetCardMCUVersion::Run()
{
	char Version[20];
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
	
	retVal= TC_GetCardMCUVersion(vHandle, Version);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,Version);	
	}
	return retVal;
}

// class M_TC_GetCardCPLDVersion 
M_TC_GetCardCPLDVersion::M_TC_GetCardCPLDVersion()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取测试卡CPLD版本号");
	m_OutputPara = CreateParamStruct();
	m_InputDeviceName = CreateParamStruct();
	Init();
}

M_TC_GetCardCPLDVersion::~M_TC_GetCardCPLDVersion()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara);
}

int M_TC_GetCardCPLDVersion::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara->paramName, "Version");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}

int M_TC_GetCardCPLDVersion::Run()
{
	char Version[20];
	int retVal;
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
	
	retVal= TC_GetCardCPLDVersion(vHandle, Version);
	if(retVal==NTS_SUCCESS)
	{
		sprintf(m_OutputPara->paramVal,Version);	
	}
	return retVal;
}

// class M_TC_SetCardProductNo 
M_TC_SetCardProductNo::M_TC_SetCardProductNo()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置测试卡产品号");
	
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();
	Init();
}

M_TC_SetCardProductNo::~M_TC_SetCardProductNo()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);
}

int M_TC_SetCardProductNo::Init()
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "ProductN0");
	m_InputPara->paramType = NTSString;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_TC_SetCardProductNo::Run()
{
	int vProductNo;
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
	vProductNo = atoi(m_InputPara->paramVal);
	retVal= TC_SetCardProductNo(vHandle, vProductNo);	
	return retVal;
}

// M_TC_SetCardStartAndStopFlash 
M_TC_SetCardStartAndStopFlash::M_TC_SetCardStartAndStopFlash()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置测试卡FLASH起止地址的数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();
	m_InputPara[3] = CreateParamStruct();
	
	Init();
}

M_TC_SetCardStartAndStopFlash::~M_TC_SetCardStartAndStopFlash()
{
//	free(m_InputDeviceName);
//	free(m_InputPara[0]);	
//	free(m_InputPara[1]);	
//	free(m_InputPara[2]);	
//	free(m_InputPara[3]);
}

int M_TC_SetCardStartAndStopFlash::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "%s", "FlashIndex");
	m_InputPara[0]->paramType = NTSInt16;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"");
	sprintf(m_InputPara[0]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[0]);	
		
	sprintf(m_InputPara[1]->paramName, "%s", "StartAddress");
	m_InputPara[1]->paramType = NTSInt16;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"");
	sprintf(m_InputPara[1]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[1]);

	sprintf(m_InputPara[2]->paramName, "%s", "Count");
	m_InputPara[2]->paramType = NTSInt16;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"");
	sprintf(m_InputPara[2]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[2]);

	sprintf(m_InputPara[3]->paramName, "%s", "FlashData");
	m_InputPara[3]->paramType = NTSString;
	m_InputPara[3]->paramCount = 1;
	sprintf(m_InputPara[3]->paramVal,"");
	sprintf(m_InputPara[3]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[3]);
	return NTS_SUCCESS;
}
int M_TC_SetCardStartAndStopFlash::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	short FlashIndex;
	int StartAddress;
	long Count;
	int i, j, strLength;
	char *TmpStr = NULL;
	int FlashData[1024] = {0};
	int res;


	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	FlashIndex = atoi(m_InputPara[0]->paramVal);
	StartAddress = atoi(m_InputPara[1]->paramVal);
	Count = atoi(m_InputPara[2]->paramVal);
	if (m_InputPara[3]->LparamVal != NULL)
	{
		strLength = strlen(m_InputPara[3]->LparamVal);
		TmpStr = (char *) malloc((strLength + 10)*sizeof(char));
		sprintf(TmpStr , "%s", m_InputPara[3]->LparamVal);		
	}
	else
	{
		strLength = strlen(m_InputPara[3]->paramVal);
		TmpStr = (char *) malloc((strLength + 10)*sizeof(char));
		sprintf(TmpStr , "%s", m_InputPara[3]->paramVal);
	}
	//分离DA值
	FlashData[0] = atoi(&TmpStr[0]);
	for(i = 1, j = 1; i<strLength; i++)
	{
		if (TmpStr[i] == ',')
		{
			FlashData[j] = atoi(&TmpStr[i+1]);
			j++;
		}
	}
	//释放内存
	free(TmpStr);
	res = TC_SetCardStartAndStopFlash(vHandle, FlashIndex, StartAddress, Count, FlashData);
	return res;
}

//M_TC_GetCardStartAndStopFlash 
M_TC_GetCardStartAndStopFlash::M_TC_GetCardStartAndStopFlash()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取测试卡FLAST起止地址的数据");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	
	Init();
}

M_TC_GetCardStartAndStopFlash::~M_TC_GetCardStartAndStopFlash()
{
//	free(m_InputDeviceName);
//	free(m_InputPara[0]);	
//	free(m_InputPara[1]);	
//	free(m_InputPara[2]);	
//	free(m_OutputPara1);
}

int M_TC_GetCardStartAndStopFlash::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "%s", "FlashIndex");
	m_InputPara[0]->paramType = NTSInt16;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"");
	sprintf(m_InputPara[0]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[0]);	
		
	sprintf(m_InputPara[1]->paramName, "%s", "StartAddress");
	m_InputPara[1]->paramType = NTSInt16;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"");
	sprintf(m_InputPara[1]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[1]);

	sprintf(m_InputPara[2]->paramName, "%s", "Count");
	m_InputPara[2]->paramType = NTSInt16;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"");
	sprintf(m_InputPara[2]->paramUnit ,"%s", "");
	m_InputParamVector.push_back(m_InputPara[2]);

	sprintf(m_OutputPara1->paramName, "%s", "FlashData");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit ,"%s", "");
	m_OutputParamVector.push_back(m_OutputPara1);
	return NTS_SUCCESS;
}
int M_TC_GetCardStartAndStopFlash::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	short FlashIndex;
	int StartAddress;
	long Count;
	int i;
	char *TmpStr = NULL;
	int FlashData[1024] = {0};
	int res;


	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	FlashIndex = atoi(m_InputPara[0]->paramVal);
	StartAddress = atoi(m_InputPara[1]->paramVal);
	Count = atoi(m_InputPara[2]->paramVal);
	if (Count > 1024) 
	{
		Count = 1024;
	}
	res = TC_GetCardStartAndStopFlash(vHandle, FlashIndex, StartAddress, Count, FlashData);
	if (res != NTS_SUCCESS)
	{
		return res;			
	}
	TmpStr = (char *) malloc((Count*7 + 10)*sizeof(char));	
	for(i = 0 ; i< Count; i++)
	{
		if (i == 0)
		{
			sprintf(TmpStr, "%d", FlashData[i]);
		}
		else
		{
			sprintf(TmpStr, "%s ,%d", TmpStr, FlashData[i]);
		}
	}
	if (strlen(TmpStr) > PARALENGTH)
	{		
		m_OutputPara1->LparamVal = (char *)malloc((strlen(TmpStr) + 10)*sizeof(char));
		sprintf(m_OutputPara1->LparamVal, "%s", TmpStr);
	}
	else
	{
		sprintf(m_OutputPara1->paramVal, "%s", TmpStr);
	}	
	//释放内存
	free(TmpStr);
	
	return res;
}
