
#include "stdafx.h"
#include "ADJMethod.h"
#include <assert.h>
#include "stdio.h"


extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

//M_ADJ_WriteCal 写校准
M_ADJ_WriteCal::M_ADJ_WriteCal()
:BaseMethod()
{
	sprintf(m_MethodScript, "写校准");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();
	m_InputPara[3] = CreateParamStruct();

	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	m_OutputPara3 = CreateParamStruct();
	Init();
}
M_ADJ_WriteCal::~M_ADJ_WriteCal()
{
//	free(m_InputDeviceName);
//	free(m_InputPara[0]);
//	free(m_InputPara[1]);
//	free(m_InputPara[2]);
//	free(m_InputPara[3]);
	
//	free(m_OutputPara1);
//	free(m_OutputPara2);
//	free(m_OutputPara3);
}
int M_ADJ_WriteCal::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "ParaTypeName");
	m_InputPara[0]->paramType = NTSString;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"");
	sprintf(m_InputPara[0]->paramUnit,  " ");
	m_InputParamVector.push_back(m_InputPara[0]);

	sprintf(m_InputPara[1]->paramName, "FlowSN");
	m_InputPara[1]->paramType = NTSInt16;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"0");
	sprintf(m_InputPara[1]->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara[1]);

	sprintf(m_InputPara[2]->paramName, "SMTSN");
	m_InputPara[2]->paramType = NTSString;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"");
	sprintf(m_InputPara[2]->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara[2]);

	sprintf(m_InputPara[3]->paramName, "ClientSN");
	m_InputPara[3]->paramType = NTSString;
	m_InputPara[3]->paramCount = 1;
	sprintf(m_InputPara[3]->paramVal,"");
	sprintf(m_InputPara[3]->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara[3]);

	sprintf(m_OutputPara1->paramName, "Count");
	m_OutputPara1->paramType = NTSInt16;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara1);

	sprintf(m_OutputPara2->paramName, "CalDatas");
	m_OutputPara2->paramType = NTSInt16;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara2);
	
	sprintf(m_OutputPara3->paramName, "CalAddrs");
	m_OutputPara3->paramType = NTSInt16;
	m_OutputPara3->paramCount = 1;
	sprintf(m_OutputPara3->paramVal,"");
	sprintf(m_OutputPara3->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara3);
	
	return NTS_SUCCESS;
}
int M_ADJ_WriteCal::Run(void)
{
	int i;
	int res;
	int FlowSN;
	char SMTSN[50], ClientSN[50],ParaTypeName[100];
	int Count, Address[0x5000];
	float CalData[0x5000];
	short int vHandle = 0;
	//gDeviceManagerMap::iterator it; 	
	TDeviceManagerMap::iterator it;
	char vDeviveName[100];	
	char *pRetStr = NULL;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	sprintf(ParaTypeName ,m_InputPara[0]->paramVal);
	FlowSN = atoi(m_InputPara[1]->paramVal);
	sprintf(SMTSN ,m_InputPara[2]->paramVal);
	sprintf(ClientSN ,m_InputPara[3]->paramVal);
	
	res = AD_WriteCal(vHandle, ParaTypeName, FlowSN, SMTSN, ClientSN, &Count,CalData, Address);	
	if (res != NTS_SUCCESS)
	{
		return res;		
	}
	pRetStr = (char *)malloc(Count*20*sizeof(char));
	sprintf(m_OutputPara1->paramVal, "%d",Count);
	//组织校准数据
	sprintf(pRetStr, "%e",CalData[0]);
	for(int i = 1;i< Count;i++)
	{
		sprintf(pRetStr, "%s%s%e",pRetStr, ",", CalData[i]);	
	}
	if (strlen(pRetStr) > PARALENGTH)
	{		
		m_OutputPara2->LparamVal = (char *)malloc((strlen(pRetStr) + 10)*sizeof(char));
		sprintf(m_OutputPara2->LparamVal, "%s", pRetStr);
	}
	else
	{
		sprintf(m_OutputPara2->paramVal, "%s", pRetStr);
	}
	//组织校准地址数据
	sprintf(pRetStr, "%d",Address[0]);
	for(i = 1;i< Count;i++)
	{		
		sprintf(pRetStr, "%s%s%d", pRetStr, ",", Address[i]);
	}
	if (strlen(pRetStr) > PARALENGTH)
	{		
		m_OutputPara3->LparamVal = (char *)malloc((strlen(pRetStr) + 10)*sizeof(char));
		sprintf(m_OutputPara3->LparamVal, "%s", pRetStr);
	}
	else
	{
		sprintf(m_OutputPara3->paramVal, "%s", pRetStr);
	}
	free(pRetStr);
	return res;
}

//M_ADJ_ReadCal 读校准
M_ADJ_ReadCal::M_ADJ_ReadCal()
:BaseMethod()
{
	sprintf(m_MethodScript, "读校准");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	m_OutputPara3 = CreateParamStruct();
	Init();
}
M_ADJ_ReadCal::~M_ADJ_ReadCal()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);
//	free(m_OutputPara2);
//	free(m_OutputPara3);
}
int M_ADJ_ReadCal::Init(void)
{
	sprintf(m_InputDeviceName->paramName , "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit , " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "Count");
	m_OutputPara1->paramType = NTSInt16;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	sprintf(m_OutputPara2->paramName, "CalDatas");
	m_OutputPara2->paramType = NTSInt16;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara2);
	
	sprintf(m_OutputPara3->paramName, "CalAddrs");
	m_OutputPara3->paramType = NTSInt16;
	m_OutputPara3->paramCount = 1;
	sprintf(m_OutputPara3->paramVal,"");
	sprintf(m_OutputPara3->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara3);
	return NTS_SUCCESS;
}
int M_ADJ_ReadCal::Run(void)
{
	int res;
	int i;
	int Count, Address[40000];
	float CalData[40000];
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	char *pRetStr = NULL;
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;

	res = AD_ReadCal(vHandle, &Count,CalData, Address);
	if (res != NTS_SUCCESS)
	{
		return res;		
	}
	pRetStr = (char *)malloc(Count * 20*sizeof(char));
	sprintf(m_OutputPara1->paramVal, "%d",Count);
	//组织校准数据
	sprintf(pRetStr, "%e",CalData[0]);
	for(int i = 1;i< Count;i++)
	{
		sprintf(pRetStr, "%s%s%e", pRetStr, ",", CalData[i]);	
	}
	if (strlen(pRetStr) > PARALENGTH)
	{		
		m_OutputPara2->LparamVal = (char *)malloc((strlen(pRetStr) + 10)*sizeof(char));
		sprintf(m_OutputPara2->LparamVal, "%s", pRetStr);
	}
	else
	{
		sprintf(m_OutputPara2->paramVal, "%s", pRetStr);
	}
	//组织校准地址数据
	sprintf(pRetStr, "%d",Address[0]);
	for(i = 1;i< Count;i++)
	{		
		sprintf(pRetStr, "%s%s%d", pRetStr, ",", Address[i]);
	}
	if (strlen(pRetStr) > PARALENGTH)
	{		
		m_OutputPara3->LparamVal = (char *)malloc((strlen(pRetStr) + 10)*sizeof(char));
		sprintf(m_OutputPara3->LparamVal, "%s", pRetStr);
	}
	else
	{
		sprintf(m_OutputPara3->paramVal, "%s", pRetStr);
	}
	free(pRetStr);
	return res;
}

//M_ADJ_GetClientSNRelate 
M_ADJ_GetClientSNRelate::M_ADJ_GetClientSNRelate()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取产品的客户SN与校准数据是否有关系(0:无  1:有)");
	m_InputDeviceName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	Init();
}
M_ADJ_GetClientSNRelate::~M_ADJ_GetClientSNRelate()
{
//	free(m_InputDeviceName);
//	free(m_OutputPara1);
}
int M_ADJ_GetClientSNRelate::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSDevice;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_OutputPara1->paramName, "State");
	m_OutputPara1->paramType = NTSInt16;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara1);
	return NTS_SUCCESS;
}
int M_ADJ_GetClientSNRelate::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	int State;
	
	
	sprintf(vDeviveName,m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	res = AD_GetClientSNRelate(vHandle,&State);
	if (res == NTS_SUCCESS )  
	{
		sprintf(m_OutputPara1->paramVal,"%d",State);
	}
	return res;
}
