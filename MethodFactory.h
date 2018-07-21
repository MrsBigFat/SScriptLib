// MethodFactory.h: interface for the MethodFactory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(_METHODFACTORY_H_)
#define _METHODFACTORY_H_
#pragma warning( disable : 4786)

#include "Method.h"
#include "NTSMethod.h"
#include "ENAMethod.h"
#include "NFAMethod.h"
#include "PSAMethod.h"
#include "SGMethod.h"
#include "SPEMethod.h"
#include "MMTMethod.h"
#include "ADJMethod.h"
#include "DADebugMethod.h"
#include "SWMethod.h"
#include "DPDMethod.h"
#include "PRMMethod.h"
#include "IRUMethod.h"
#include "TCMethod.h"
#include "VSA89600.h"
#include "NCardMethod.h"
#include "AU3Method.h"
#include "DWGMethod.h"
#include "OSCMethod.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/************************************************************************
* �汾��2.1.0.0
* ���ߣ�dolby.jiang
* ������ڣ�2009��10��12��
* ���ģ��¿��
*
************************************************************************/

/*
class MethodFactory  
{
public:
	MethodFactory();
	virtual ~MethodFactory();
	BaseMethod *CreateMethod(int MethodId);
private:
	MethodNameStruct m_MethodSet;
public:
	TMethodMap m_MethodMap;
};*/


//���嵥����
class MethodFactory  
{
public:
	typedef BaseMethod* (*CreateMethodCallBack) ();
private:
//	typedef std::map<int, CreateMethodCallBack> CallBackMap;
	typedef std::map<std::string, CreateMethodCallBack> CallBackMap;

private:
	MethodFactory();
	virtual ~MethodFactory();
	static MethodFactory *m_pInstance;						//Ωһʵ��

	
public:
	static MethodFactory* GetInstance();				//��������(�������ʵ��)
	
	//ע����������
	bool RegisterMethod(std::string MethodName, CreateMethodCallBack CreatFn);

	//ע����������
	bool UnregisterMehtod(std::string MethodName);

	//��������
	BaseMethod *CreateMethod(int MethodId, char *MethodName);

	//ע��������������
	void RegisterAllMethod();
	
private:
	CallBackMap m_MethodCallBackMap;
	MethodNameStruct m_MethodSet;
	
public:
	TMethodMap m_MethodMap;
};


#endif // !defined(_METHODFACTORY_H_)
