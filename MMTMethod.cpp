#include "stdafx.h"
#include "MMTMethod.h"
#include <assert.h>
#include "stdio.h"
#include <map>


extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器

//class M_MMT_GetCurrent
M_MMT_GetCurrent::M_MMT_GetCurrent()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取万用表的电流值");
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_MMT_GetCurrent::~M_MMT_GetCurrent()
{
//	free(m_InputPara);
//	free(m_OutputPara);
}
int M_MMT_GetCurrent::Init()
{
	sprintf(m_InputPara->paramName, "ComPort");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);

	sprintf(m_OutputPara->paramName, "current");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "A");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_MMT_GetCurrent::Run()
{
	int retval;
	float current = 0;
	short port;

	port = atoi(m_InputPara->paramVal);
	retval = MMT_GetCurrent(NULL,port,&current);
	if(retval!=NTS_SUCCESS)
	{
		return NTS_INVALID_OPERATE;
	}
	sprintf(m_OutputPara->paramVal,"%0.6f",current);
	return NTS_SUCCESS;
	
}

//class M_MMT_GetZn 
M_MMT_GetZn::M_MMT_GetZn()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取电阻(Ω)");
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_MMT_GetZn::~M_MMT_GetZn()
{
//	free(m_InputPara);
//	free(m_OutputPara);
}
int M_MMT_GetZn::Init()
{
	sprintf(m_InputPara->paramName, "ComPort");
	m_InputPara->paramType = NTSInt8;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"1");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	sprintf(m_OutputPara->paramName, "Zn");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "Ω");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_MMT_GetZn::Run()
{
	int retval;
	float Zn = 0;
	short port;
	
	port = atoi(m_InputPara->paramVal);
	retval = MMT_GetZn(NULL,port,&Zn);
	if(retval!=NTS_SUCCESS)
	{
		return NTS_INVALID_OPERATE;
	}
	sprintf(m_OutputPara->paramVal,"%0.6f",Zn);
	return NTS_SUCCESS;	
}
