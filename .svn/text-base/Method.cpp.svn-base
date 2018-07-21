// BaseMethod.cpp: implementation of the BaseMethod class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Method.h"
#include <assert.h>
#include "stdio.h"
#include <map>

extern std::map<TDevcieType, short int> m_deviceHandle;

//Class NTSMehod
BaseMethod::BaseMethod()
{
	m_InputParamVector.clear();
	m_OutputParamVector.clear();
//	m_LOutputParamVector.clear();
    sprintf(m_MethodScript, ""); 
//	m_pParamInfoStruct = NULL;
//	m_pParamInfoStruct = CreateParamStruct();
}

BaseMethod::~BaseMethod()
{
	int i, count;

	
	count = m_InputParamVector.size();
	for(i = 0; i< count ; i++)
	{
		if (m_InputParamVector[i]->paramName != NULL) 
		{
			free(m_InputParamVector[i]->paramName);
			m_InputParamVector[i]->paramName = NULL;
		}
		
		if (m_InputParamVector[i]->paramUnit != NULL) 
		{
			free(m_InputParamVector[i]->paramUnit);
			m_InputParamVector[i]->paramUnit = NULL;
		}		
		
		if (m_InputParamVector[i]->LparamVal != NULL) 
		{
			free(m_InputParamVector[i]->LparamVal);	
			m_InputParamVector[i]->LparamVal = NULL;
		}
		delete m_InputParamVector[i];
		m_InputParamVector[i] = NULL;
		
	}
	
	count = m_OutputParamVector.size();
	for(i = 0; i< count ; i++)
	{
		if (m_OutputParamVector[i]->paramName != NULL) 
		{
			free(m_OutputParamVector[i]->paramName);
			m_OutputParamVector[i]->paramName = NULL;
		}
		
		if (m_OutputParamVector[i]->paramUnit != NULL) 
		{
			free(m_OutputParamVector[i]->paramUnit);
			m_OutputParamVector[i]->paramUnit = NULL;
		}		
		
		if (m_OutputParamVector[i]->LparamVal != NULL) 
		{
			free(m_OutputParamVector[i]->LparamVal);	
			m_OutputParamVector[i]->LparamVal = NULL;
		}
		delete m_OutputParamVector[i];
		m_OutputParamVector[i] = NULL;
	}
}

/******************************************************************************
* 函数名称:  BaseMethod::SetInputParam
* 作者:	 dolob.jiang
* 日期  2009.12.2
* 参数: 
* 功能:  BaseMethod::SetInputParam
* 返回值:  int
******************************************************************************/
int BaseMethod::SetInputParam(TParamSetVector Param)
{
	m_InputParamVector = Param;
	return NTS_SUCCESS;
}


/******************************************************************************
* 函数名称:  BaseMethod::GetInputParam
* 作者:	 dolob.jiang
* 日期  2009.12.2
* 参数: 
* 功能:  BaseMethod::GetInputParam
* 返回值:  int
******************************************************************************/
int BaseMethod::GetInputParam(TParamSetVector *Param)
{
	*Param = m_InputParamVector;
	return NTS_SUCCESS;
}


/******************************************************************************
* 函数名称:  BaseMethod::GetOutputParam
* 作者:	 dolob.jiang
* 日期  2009.12.2
* 参数: 
* 功能:  BaseMethod::GetOutputParam
* 返回值:  int
******************************************************************************/
int BaseMethod::GetOutputParam(TParamSetVector *Param)
{
	*Param = m_OutputParamVector;
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  BaseMethod::GetOutputParam
* 作者:	 dolob.jiang
* 日期  2009.12.2
* 参数: 
* 功能:  BaseMethod::GetOutputParam
* 返回值:  int
******************************************************************************/
/*
int BaseMethod::GetOutputParam(TLParamSetVector *Param)
{
	*Param = m_LOutputParamVector;
	return NTS_SUCCESS;
}
*/

/******************************************************************************
* 函数名称:  BaseMethod::SetMethodScript
* 作者:	 dolob.jiang
* 日期  2009.12.2
* 参数: 
* 功能:  BaseMethod::SetMethodScript
* 返回值:  int
******************************************************************************/
int BaseMethod::SetMethodScript(char *script)
{
	sprintf(m_MethodScript, script);
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  BaseMethod::GetMethodScript
* 作者:	 dolob.jiang
* 日期  2009.12.2
* 参数: 
* 功能:  BaseMethod::GetMethodScript
* 返回值:  int
******************************************************************************/
int BaseMethod::GetMethodScript(char *script)
{
	sprintf(script, m_MethodScript);
	return NTS_SUCCESS;
}

/******************************************************************************
* 函数名称:  BaseMethod::CreateParamStruct
* 作者:	 dolob.jiang
* 日期  2009.12.2
* 参数: 
* 功能:  BaseMethod::CreateParamStruct
* 返回值:  int
******************************************************************************/
ParamSetStruct * BaseMethod::CreateParamStruct()
{
	ParamSetStruct *p;
	p = new ParamSetStruct;
	p->LparamVal = NULL;
	p->paramName = (char *)malloc(50*sizeof(char));
	p->paramUnit = (char *)malloc(10*sizeof(char));
	sprintf(p->paramName, "%s", "");
	sprintf(p->paramUnit, "%s", "");
	return p;
}

/******************************************************************************
* 函数名称:  BaseMethod::ClearInputParamSetVector
* 作者:	 dolob.jiang
* 日期  2009.12.2
* 参数: 
* 功能:  BaseMethod::ClearInputParamSetVector
* 返回值:  int
******************************************************************************/
void BaseMethod::ClearInputParamSetVector()
{
	m_InputParamVector.clear();
}

/******************************************************************************
* 函数名称:  BaseMethod::AddInputParamSetVector
* 作者:	 dolob.jiang
* 日期  2009.12.2
* 参数: 
* 功能:  BaseMethod::AddInputParamSetVector
* 返回值:  int
******************************************************************************/
void BaseMethod::AddInputParamSetVector(ParamSetStruct* ParamInfoStruct)
{
	m_InputParamVector.push_back(ParamInfoStruct);
}
