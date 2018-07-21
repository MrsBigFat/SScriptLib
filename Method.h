/************************************************************************
* Copyright (c) 2010,оͨ�Ƽ����޹�˾
* All rights reserved.
* �ļ����ƣ� BaseMethod.h
* �ļ���ʶ��reserved
* ժҪ��BaseMethod.h: interface for the BaseMethod class.
*
************************************************************************/

#if !defined _BaseMETHOD_H_
#define _BaseMETHOD_H_
#pragma warning( disable : 4786)

#include <windows.h>
#include <algorithm>

#include "NTSDin.h"
#include "DGL.h"
#include "ComFunction.h"
#include "resource.h"


#include <visa.h>
#pragma  comment(lib,"visa32.lib")

// ���ڲ���
#include ".\include\ComDriver.h"
#pragma  comment(lib, ".\\lib\\ComDriver.lib")

// Lan����
#include ".\include\LanDriver.h"
#pragma  comment(lib, ".\\lib\\LanDriver.lib")

#include ".\include\NTSAD.h"
#pragma comment(lib,".\\lib\\NTSAD.lib")

#include ".\include\NTSProducts.h"
#pragma comment(lib,".\\lib\\NTSProducts.lib")

#include ".\include\PSADriver.h"
#pragma comment(lib,".\\lib\\PSADriver.lib")

#include ".\include\SGDriver.h"
#pragma comment(lib,".\\lib\\SGDriver.lib")

#include ".\include\ENADriver.h"
#pragma comment(lib,".\\lib\\ENADriver.lib")

#include ".\include\DWGDriver.h"
#pragma comment(lib,".\\lib\\DWGDriver.lib")

#include ".\include\OSCDriver.h"
#pragma comment(lib,".\\lib\\OSCDriver.lib")

#include ".\include\PRMDriver.h"
#pragma comment(lib, ".\\lib\\PRMDriver.lib")

#include ".\include\DPDDriver.h"
#pragma comment(lib,".\\lib\\DPDDriver.lib")

#include ".\include\NFADriver.h"
#pragma comment(lib,".\\lib\\NFADriver.lib")

#include ".\include\IRUDriver.h"
#pragma comment(lib,".\\lib\\IRUDriver.lib")

// 
#include ".\include\MMTDriver.h"
#pragma comment(lib,".\\lib\\MMTDriver.lib")

#include ".\include\SWDriver.h"
#pragma comment(lib,".\\lib\\SWDriver.lib")

// 
#include ".\include\TestCardDriver.h"
#pragma comment(lib,".\\lib\\TestCardDriver.lib")

// NCard
#include ".\include\NCardDriver.h"
#pragma comment(lib,".\\lib\\NCardDriver.lib")

// ���� LPT
#include ".\include\LPTDriver.h"
#pragma comment(lib,".\\lib\\LPTDriver.lib")

// AutoIt ��̬��
#include ".\include\AutoItX3_DLL.h"
#pragma comment(lib,".\\lib\\AutoItX3_DLL.lib")

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


//class Base Method
class BaseMethod  
{
public:
	BaseMethod();
	virtual ~BaseMethod();
	virtual int SetInputParam(TParamSetVector Param);
	virtual int GetInputParam(TParamSetVector *Param);
	
	virtual int GetOutputParam(TParamSetVector *Param);
	
	virtual int GetMethodScript(char *script);
	virtual int SetMethodScript(char *script);
	virtual int Run(void) {return NTS_SUCCESS;};
	virtual int Init(void) {return NTS_SUCCESS;};

	//��������������������ṹ��
	ParamSetStruct * CreateParamStruct();
	
	//�������
	void ClearInputParamSetVector();
	//����һ����¼
	void AddInputParamSetVector(ParamSetStruct *ParamInfoStruct);

protected:
	TParamSetVector m_InputParamVector;
	TParamSetVector m_OutputParamVector;
	char m_MethodScript[1024];	
	char m_ErrMsg[2000];	
	
};

#endif // !defined(AFX_NTSMETHOD_H__25160711_8D49_4D81_95AE_BC7FCF418D71__INCLUDED_)
