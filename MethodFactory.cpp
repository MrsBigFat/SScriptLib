// MethodFactory.cpp: implementation of the MethodFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MethodFactory.h"
#include "MethodCreator.h"
#include "DllAnalyse.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
//字符串直接连接
//#define Create_Instance(MethodInstance, ClassName) MethodInstance = new M_##ClassName

MethodFactory::MethodFactory()
{
	
	//获取驱动库中的函数名
	char fileName[1024];
	char *Fns[1024] = {0};
	char SubFn[1024] = {0};
	int i, FnCount, FnParaCount;
	HMODULE DllHandle;

	m_MethodMap.clear();
	
	//波形发生器驱动方法类
	DllHandle = NULL;
	DllHandle = LoadLibrary("DWGDriver.dll") ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return ;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}
	
	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		m_MethodSet.MethodID = 2201 + i;
		m_MethodSet.Visable = 1;
		m_MethodMap[SubFn] = m_MethodSet;			
	}
	//手动确立映射关系
/*	m_MethodSet.MethodID = 201 + FnParaCount;
	m_MethodSet.Visable = 1;
	m_MethodMap["DWG_SetMarkFreq"] = m_MethodSet;*/


	//示波器驱动方法类
	DllHandle = NULL;
	DllHandle = LoadLibrary("OSCDriver.dll") ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return ;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}
	
	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		m_MethodSet.MethodID = 2401 + i;
		m_MethodSet.Visable = 1;
		m_MethodMap[SubFn] = m_MethodSet;			
	}


	//信号源驱动方法类
	DllHandle = NULL;
	DllHandle = LoadLibrary("SGDriver.dll") ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return ;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}
	
	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		m_MethodSet.MethodID = 101 + i;
		m_MethodSet.Visable = 1;
		m_MethodMap[SubFn] = m_MethodSet;			
	}
  
	//频谱仪驱动方法类
	DllHandle = NULL;
	DllHandle = LoadLibrary("PSADriver.dll") ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return ;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}
	
	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		m_MethodSet.MethodID = 201 + i;
		m_MethodSet.Visable = 1;
		m_MethodMap[SubFn] = m_MethodSet;			
	}
	//手动确立映射关系
	m_MethodSet.MethodID = 201 + FnParaCount;
	m_MethodSet.Visable = 1;
	m_MethodMap["PSA_SetMarkFreq"] = m_MethodSet;


	///////////////////////////矢量网络仪驱动方法类/////////////////////////////
	DllHandle = NULL;
	DllHandle = LoadLibrary("ENADriver.dll") ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return ;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}

	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		m_MethodSet.MethodID = 301 + i;
		m_MethodSet.Visable = 1;
		m_MethodMap[SubFn] = m_MethodSet;			
	}	

	//噪声分析仪驱动方法类	
	DllHandle = NULL;
	DllHandle = LoadLibrary("NFADriver.dll") ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return ;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}
	
	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		m_MethodSet.MethodID = 401 + i;
		m_MethodSet.Visable = 1;
		m_MethodMap[SubFn] = m_MethodSet;			
	}	

	//特殊功能方法类，必须手动确立映射关系	
	m_MethodSet.MethodID = 501;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_ShowDialog"] = m_MethodSet;
	
	m_MethodSet.MethodID = 502;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_Pause"] = m_MethodSet;
	
	m_MethodSet.MethodID = 503;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_SetDelayTime"] = m_MethodSet;
	
	m_MethodSet.MethodID = 504;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_ACPRPowerDebug"] = m_MethodSet;
	
	m_MethodSet.MethodID = 520;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_ACPRPowerDebugEx"] = m_MethodSet;
	
	m_MethodSet.MethodID = 506;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_ACPPowerDebug"] = m_MethodSet;
	
	m_MethodSet.MethodID = 507;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SEMPowerDebug"] = m_MethodSet;
	
	m_MethodSet.MethodID = 508;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_EVMandPCDEPowerDebug"] = m_MethodSet;
	
	m_MethodSet.MethodID = 516;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_SpectrumPowerDebug"] = m_MethodSet;
	
	m_MethodSet.MethodID = 519;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SpectrumPowerDebugEx"] = m_MethodSet;
	
	m_MethodSet.MethodID = 517;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_ACPRDebug"] = m_MethodSet;
	
	m_MethodSet.MethodID = 509;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_Add"] = m_MethodSet;
	
	m_MethodSet.MethodID = 510;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_Subtract"] = m_MethodSet;
	
	m_MethodSet.MethodID = 511;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_Multiply"] = m_MethodSet;
	
	m_MethodSet.MethodID = 512;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_Divide"] = m_MethodSet;
	
	m_MethodSet.MethodID = 513;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_Compare"] = m_MethodSet;
	
	m_MethodSet.MethodID = 525;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_CompareA"] = m_MethodSet;
	
	m_MethodSet.MethodID = 514;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_Equal"] = m_MethodSet;
	
	m_MethodSet.MethodID = 515;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_Absolute"] = m_MethodSet;
	
/*
	m_MethodSet.MethodID = 523;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SetLastDAOffset"] = m_MethodSet;
*/
	
	m_MethodSet.MethodID = 524;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_Power"] = m_MethodSet;	
	
	m_MethodSet.MethodID = 701;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_GetCurrent"] = m_MethodSet;
	
	m_MethodSet.MethodID = 505;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_GetTimeSwitch"] = m_MethodSet;
	
	m_MethodSet.MethodID = 518;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_GetUpTimeSwitch"] = m_MethodSet;
	
	m_MethodSet.MethodID = 521;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_GetDownTimeSwitch"] = m_MethodSet;
	
	m_MethodSet.MethodID = 522;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_ShowPromptDialog"] = m_MethodSet;

	m_MethodSet.MethodID = 526;
	m_MethodSet.Visable = 1;	
	m_MethodMap["SPE_DevReset"] = m_MethodSet;		
	
	m_MethodSet.MethodID = 527;
	m_MethodSet.Visable = 1;	
	m_MethodMap["SPE_PRMPowerDebug"] = m_MethodSet;	
	
	m_MethodSet.MethodID = 528;
	m_MethodSet.Visable = 1;	
	m_MethodMap["SPE_SeparateData"] = m_MethodSet;	

	m_MethodSet.MethodID = 529;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_IntToString"] = m_MethodSet;
	
	m_MethodSet.MethodID = 530;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_FloatToString"] = m_MethodSet;
	
	m_MethodSet.MethodID = 531;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_GetConditionData"] = m_MethodSet;
	
	m_MethodSet.MethodID = 532;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_GetMaxPosition"] = m_MethodSet;
	
	m_MethodSet.MethodID = 533;
	m_MethodSet.Visable = 0;
	m_MethodMap["SPE_StrCat"] = m_MethodSet;

	m_MethodSet.MethodID = 534;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_GetMinPosition"] = m_MethodSet;	//特殊方法必须手动确立映射关系

	m_MethodSet.MethodID = 535;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_GainDebugWithENA"] = m_MethodSet;	//特殊方法必须手动确立映射关系

	m_MethodSet.MethodID = 536;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_OpenDev"] = m_MethodSet;
	
	m_MethodSet.MethodID = 537;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_CloseDev"] = m_MethodSet;

	m_MethodSet.MethodID = 538;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_PolyFit"] = m_MethodSet;

	m_MethodSet.MethodID = 539;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_GetIDN"] = m_MethodSet;

	m_MethodSet.MethodID = 540;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_WriteDev"] = m_MethodSet;

	m_MethodSet.MethodID = 541;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_ReadDev"] = m_MethodSet;

	m_MethodSet.MethodID = 542;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_QueryDev"] = m_MethodSet;

	m_MethodSet.MethodID = 543;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SprintfDev"] = m_MethodSet;
	
	
	m_MethodSet.MethodID = 544;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SetCom"] = m_MethodSet;
	
	m_MethodSet.MethodID = 545;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SetDTR"] = m_MethodSet;
	
	m_MethodSet.MethodID = 546;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SetRTS"] = m_MethodSet;
	
	m_MethodSet.MethodID = 547;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SetXOFF"] = m_MethodSet;
	
	m_MethodSet.MethodID = 548;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SetXON"] = m_MethodSet;

	m_MethodSet.MethodID = 549;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_FFT"] = m_MethodSet;

	m_MethodSet.MethodID = 550;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SetBufSize"] = m_MethodSet;
	
	m_MethodSet.MethodID = 551;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_ClearBuf"] = m_MethodSet;

	m_MethodSet.MethodID = 552;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_GetLastErrStr"] = m_MethodSet;

	m_MethodSet.MethodID = 553;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SetAttributeDev"] = m_MethodSet;

	m_MethodSet.MethodID = 554;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_AgePowerOn"] = m_MethodSet; 
	
	m_MethodSet.MethodID = 555;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_AgePowerOff"] = m_MethodSet; 
		
	m_MethodSet.MethodID = 556;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_AgeRead"] = m_MethodSet; 

	m_MethodSet.MethodID = 557;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SetIOPortVal"] = m_MethodSet; 

	m_MethodSet.MethodID = 558;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_GetIOPortVal"] = m_MethodSet; 

	m_MethodSet.MethodID = 559;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SetIOTRBits"] = m_MethodSet; 	

	m_MethodSet.MethodID = 560;
	m_MethodSet.Visable = 1;
	m_MethodMap["SPE_SetIOTrigPolarity"] = m_MethodSet; 
	
		
	//公司模块方法类

	DllHandle = NULL;
	DllHandle = LoadLibrary("NTSProducts.dll") ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return ;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}
	
	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		m_MethodSet.MethodID = 601 + i;
		m_MethodSet.Visable = 1;
		m_MethodMap[SubFn] = m_MethodSet;			
	}

	// 外部客户驱动库系统固定函数
/*
	m_MethodSet.MethodID = 601;
	m_MethodSet.Visable = 1;
	m_MethodMap["NTS_OpenDev"] = m_MethodSet;

	m_MethodSet.MethodID = 602;
	m_MethodSet.Visable = 1;
	m_MethodMap["NTS_CloseDev"] = m_MethodSet;

	m_MethodSet.MethodID = 603;
	m_MethodSet.Visable = 1;
	m_MethodMap["NTS_SetPowerState"] = m_MethodSet;

	m_MethodSet.MethodID = 604;
	m_MethodSet.Visable = 1;
	m_MethodMap["NTS_SetPCB"] = m_MethodSet;

	m_MethodSet.MethodID = 605;
	m_MethodSet.Visable = 1;
	m_MethodMap["NTS_GetPCB"] = m_MethodSet;

	m_MethodSet.MethodID = 606;
	m_MethodSet.Visable = 1;
	m_MethodMap["NTS_GetTemperature"] = m_MethodSet;	
*/
	
	//万用表驱动方法类 7
	m_MethodSet.MethodID = 702;
	m_MethodSet.Visable = 1;
	m_MethodMap["MMT_GetCurrent"] = m_MethodSet;

	m_MethodSet.MethodID = 703;
	m_MethodSet.Visable = 1;
	m_MethodMap["MMT_GetZn"] = m_MethodSet;
	
	//DA调试驱动方法类 8
	m_MethodSet.MethodID = 801;
	m_MethodSet.Visable = 0;
	m_MethodMap["DEB_WriteDebug"] = m_MethodSet;	//特殊方法必须手动确立映射关系

	m_MethodSet.MethodID = 802;
	m_MethodSet.Visable = 0;
	m_MethodMap["DEB_ReadDebug"] = m_MethodSet;		//特殊方法必须手动确立映射关系
	

	//EEPROM驱动方法类 9

	m_MethodSet.MethodID = 901;
	m_MethodSet.Visable = 0;
	m_MethodMap["ADJ_WriteCal"] = m_MethodSet;	//特殊方法必须手动确立映射关系
	
	m_MethodSet.MethodID = 902;
	m_MethodSet.Visable = 0;
	m_MethodMap["ADJ_ReadCal"] = m_MethodSet;	//特殊方法必须手动确立映射关系

	m_MethodSet.MethodID = 903;
	m_MethodSet.Visable = 0;
	m_MethodMap["ADJ_GetClientSNRelate"] = m_MethodSet;	//特殊方法必须手动确立映射关系

	//矩阵开关驱动方法类
	m_MethodSet.MethodID = 1000;
	m_MethodSet.Visable = 1;
	m_MethodMap["SW_SetSwtichState"] = m_MethodSet;
	
	m_MethodSet.MethodID = 1001;
	m_MethodSet.Visable = 1;
	m_MethodMap["SW_SetCtrlPort"] = m_MethodSet;

	//DPD板驱动方法库

	DllHandle = NULL;
	DllHandle = LoadLibrary("DPDDriver.dll") ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return ;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}
	
	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		m_MethodSet.MethodID = 1100 + i;
		m_MethodSet.Visable = 1;
		m_MethodMap[SubFn] = m_MethodSet;			
	}

	//特殊方法必须手动确立映射关系
	m_MethodSet.MethodID = 1100 + FnCount;
	m_MethodSet.Visable = 1;
	m_MethodMap["DPD_SetErrPwrDebug"] = m_MethodSet;

	//特殊方法必须手动确立映射关系
	m_MethodSet.MethodID = 1101 + FnCount;
	m_MethodSet.Visable = 1;
	m_MethodMap["DPD_SetErrPwrDebugDT"] = m_MethodSet;

	//特殊方法必须手动确立映射关系
	m_MethodSet.MethodID = 1102 + FnCount;
	m_MethodSet.Visable = 1;
	m_MethodMap["DPD_ACPRPowerDebug"] = m_MethodSet;

	//特殊方法必须手动确立映射关系
	m_MethodSet.MethodID = 1103 + FnCount;
	m_MethodSet.Visable = 1;
	m_MethodMap["DPD_ACPRPowerDebugDT"] = m_MethodSet;
		
	m_MethodSet.MethodID = 1104 + FnCount;
	m_MethodSet.Visable = 1;
	m_MethodMap["DPD_PRMPowerDebug"] = m_MethodSet;		


	//功率计方法类	
	//加载驱动库
	DllHandle = NULL;
	DllHandle = LoadLibrary("PRMDriver.dll") ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return ;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}
	
	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		m_MethodSet.MethodID = 1201 + i;
		m_MethodSet.Visable = 1;
		m_MethodMap[SubFn] = m_MethodSet;			
	}

/*
	//IRU方法类	
	//加载驱动库
	DllHandle = NULL;
	DllHandle = LoadLibrary("IRUDriver.dll") ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return ;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}
	
	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		m_MethodSet.MethodID = 1301 + i;
		m_MethodSet.Visable = 1;
		m_MethodMap[SubFn] = m_MethodSet;			
	}
*/
	//测试卡方法类	
	//加载驱动库
	DllHandle = NULL;
	DllHandle = LoadLibrary("TestCardDriver.dll") ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return ;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}
	
	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		m_MethodSet.MethodID = 1401 + i;
		m_MethodSet.Visable = 0;
		m_MethodMap[SubFn] = m_MethodSet;			
	}

	// 通用接口卡方法类	
	//加载驱动库
	DllHandle = NULL;
	DllHandle = LoadLibrary("NCardDriver.dll") ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return ;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}	
	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		m_MethodSet.MethodID = 1501 + i;
		m_MethodSet.Visable = 1;
		m_MethodMap[SubFn] = m_MethodSet;			
	}

	// AutoIT 接口方法类
	
	
	//加载驱动库
	m_MethodSet.MethodID = 1801;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_Run"] = m_MethodSet; 	

	m_MethodSet.MethodID = 1802;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_RunWait"] = m_MethodSet; 	

	m_MethodSet.MethodID = 1803;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_WinWaitActive"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1804;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_Send"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1805;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlClick"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1806;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlSetText"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1807;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlGetText"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1808;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlCommand"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1809;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlListView"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1810;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ClipGet"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1811;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ClipPut"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1812;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlDisable"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1813;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlEnable"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1814;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlFocus"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1815;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlGetFocus"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1816;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlGetPos"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1817;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlHide"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1818;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlMove"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1819;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlSend"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1820;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ControlShow"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1821;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_MouseClick"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1822;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_MouseClickDrag"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1823;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_MouseDown"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1824;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_MouseUp"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1825;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_MouseMove"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1826;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_MouseWheel"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1827;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_AutoItSetOption"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1828;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_Opt"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1829;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ProcessClose"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1830;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ProcessExists"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1831;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ProcessWait"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1832;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_ProcessWaitClose"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1833;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_WinActivate"] = m_MethodSet; 	

	m_MethodSet.MethodID = 1834;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_WinActive"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1835;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_WinClose"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1836;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_WinExists"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1837;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_WinKill"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1838;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_WinSetOnTop"] = m_MethodSet; 	
	
	m_MethodSet.MethodID = 1839;
	m_MethodSet.Visable = 1;
	m_MethodMap["AU3_WinSetState"] = m_MethodSet; 


	/*
	DllHandle = NULL;
		DllHandle = LoadLibrary("AutoItX3.dll") ;
		if(DllHandle != NULL)
		{
			if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
			{   
				return ;   
			}	
			AnalysisFunction(fileName, Fns, &FnCount);
		}	
		for(i = 0; i<FnCount; i++)
		{
			//GetSubStr(Fns[i], SubFn, &FnParaCount); 
			m_MethodSet.MethodID = 1801 + i;
			m_MethodSet.Visable = 1;
			m_MethodMap[Fns[i]] = m_MethodSet;			
		}*/
	
	//下个类型从2200开始

	//注册所有设备的驱动方法
	RegisterAllMethod();
}
MethodFactory::~MethodFactory()
{
	delete m_pInstance;
}

//初始化静态变量
MethodFactory* MethodFactory::m_pInstance = new MethodFactory();

MethodFactory* MethodFactory::GetInstance()
{
	return m_pInstance;
} 

BaseMethod * MethodFactory::CreateMethod(int MethodId, char *MethodName)
{
	BaseMethod *m_methodInstance = NULL;	

	CallBackMap::const_iterator it = m_MethodCallBackMap.find(MethodName);
	
	if(it == m_MethodCallBackMap.end())
	{
		m_methodInstance = new BaseMethod();
		m_methodInstance->SetMethodScript("未注册, 暂不可用!  ");
//		return m_methodInstance;
//		throw std::runtime_error("Unknow Method ID");
	}
	else
	{
		m_methodInstance = (it->second) ();
	}	
/*
	switch(MethodId)
	{	
	//DA调试驱动方法类 8
	case 801:
		m_methodInstance = new M_DEB_WriteDebug;
		break;
		
	case 802:
		m_methodInstance = new M_DEB_ReadDebug;
		break;		
		
	//EEPROM驱动方法类 9
	case 901:		
		m_methodInstance = new M_ADJ_WriteCal;
		break;
		
	case 902:
		m_methodInstance = new M_ADJ_ReadCal;
		break;
		
	case 903:		
		m_methodInstance = new M_ADJ_GetClientSNRelate;
		break;
	}*/

	return m_methodInstance;
}


bool MethodFactory::RegisterMethod(std::string MethodName, CreateMethodCallBack CreatFn)
{
	return m_MethodCallBackMap.insert(CallBackMap::value_type(MethodName, CreatFn)).second;
}

bool MethodFactory::UnregisterMehtod(std::string MethodName)
{
	return m_MethodCallBackMap.erase(MethodName) == 1;
}

//注册所有驱动方法
void MethodFactory::RegisterAllMethod()
{
	//////////////////////注册信号源驱动方法///////////////////////////		
	RegisterMethod("SG_Reset", Create_SG_Reset);
	RegisterMethod("SG_SetWaveFile", Create_SG_SetWaveFile);
	RegisterMethod("SG_SetArbWaveState", Create_SG_SetArbWaveState);
	RegisterMethod("SG_SetRFFreq", Create_SG_SetRFFreq);
	RegisterMethod("SG_SetRFAmplitu", Create_SG_SetRFAmplitu);
	RegisterMethod("SG_GetRFAmplitu", Create_SG_GetRFAmplitu);
	RegisterMethod("SG_SetIQModulationState", Create_SG_SetIQModulationState);
	RegisterMethod("SG_SetRFPowerOnState", Create_SG_SetRFPowerOnState);
	RegisterMethod("SG_SetSweepPoint", Create_SG_SetSweepPoint);
	RegisterMethod("SG_SetSweepTriMode", Create_SG_SetSweepTriMode);
	RegisterMethod("SG_SetStartandStopFreq", Create_SG_SetStartandStopFreq);
	RegisterMethod("SG_SetSweepMode", Create_SG_SetSweepMode);
	RegisterMethod("SG_SetARBMarkMode", Create_SG_SetARBMarkMode);
	RegisterMethod("SG_SetFreqOffset", Create_SG_SetFreqOffset);
	RegisterMethod("SG_SetARBMarkDelay", Create_SG_SetARBMarkDelay);
	RegisterMethod("SG_SetTrigInContinuousType", Create_SG_SetTrigInContinuousType);
	RegisterMethod("SG_SetTrigInSourceType", Create_SG_SetTrigInSourceType);
	RegisterMethod("SG_SetTrigInPolarity", Create_SG_SetTrigInPolarity);
	RegisterMethod("SG_SetTrigInDelay", Create_SG_SetTrigInDelay);
	RegisterMethod("SG_SetMarkerALCHold", Create_SG_SetMarkerALCHold);
	RegisterMethod("SG_SetAmpALCMode", Create_SG_SetAmpALCMode);
	RegisterMethod("SG_SetClockFreq", Create_SG_SetClockFreq);
	RegisterMethod("SG_SetRFPowerSearchMode", Create_SG_SetRFPowerSearchMode);
	RegisterMethod("SG_SendCmd", Create_SG_SendCmd);
	RegisterMethod("SG_GetCmd", Create_SG_GetCmd);
	RegisterMethod("SG_GetIDN", Create_SG_GetIDN);
	RegisterMethod("SG_SetRFAmplituOffset", Create_SG_SetRFAmplituOffset);
	RegisterMethod("SG_SetCwCarrier", Create_SG_SetCwCarrier);


	//////////////////////注册波形发生器驱动方法///////////////////////////	
		RegisterMethod("DWG_Reset", Create_DWG_Reset);
		RegisterMethod("DWG_SendCmd", Create_DWG_SendCmd);
		RegisterMethod("DWG_GetCmd", Create_DWG_GetCmd);
		RegisterMethod("DWG_GetIDN", Create_DWG_GetIDN);
		RegisterMethod("DWG_LoadFile", Create_DWG_LoadFile);
		RegisterMethod("DWG_SetCHSwitch", Create_DWG_SetCHSwitch);
		RegisterMethod("DWG_SetAllSwitch", Create_DWG_SetAllSwitch);
		RegisterMethod("DWG_SetAmpLevel", Create_DWG_SetAmpLevel);


	//////////////////////注册示波器驱动方法///////////////////////////	
	RegisterMethod("OSC_Reset", Create_OSC_Reset);
	RegisterMethod("OSC_SetDTLEVParam", Create_OSC_SetDTLEVParam);
	RegisterMethod("OSC_SetGrid", Create_OSC_SetGrid);
	RegisterMethod("OSC_SetTrigType", Create_OSC_SetTrigType);
	RegisterMethod("OSC_SetTrigCoupling", Create_OSC_SetTrigCoupling);
	RegisterMethod("OSC_SetTrigSlope", Create_OSC_SetTrigSlope);
	RegisterMethod("OSC_SetTrigLevel", Create_OSC_SetTrigLevel);
	RegisterMethod("OSC_SetScaleVDIV", Create_OSC_SetScaleVDIV);
	RegisterMethod("OSC_SetScaleTDIV", Create_OSC_SetScaleTDIV);
	RegisterMethod("OSC_GetMeaValue", Create_OSC_GetMeaValue);
	RegisterMethod("OSC_SetTrigMode", Create_OSC_SetTrigMode);
	RegisterMethod("OSC_SendCmd", Create_OSC_SendCmd);
	RegisterMethod("OSC_GetCmd", Create_OSC_GetCmd);
	RegisterMethod("OSC_SetDeltaDelay", Create_OSC_SetDeltaDelay);
	RegisterMethod("OSC_SetTraceDis", Create_OSC_SetTraceDis);


	//////////////////////注册频谱仪驱动方法///////////////////////////	
	RegisterMethod("PSA_SetPreset", Create_PSA_SetPreset);
	RegisterMethod("PSA_SetCenterFrq", Create_PSA_SetCenterFrq);
	RegisterMethod("PSA_SetCenterFrqandSpan", Create_PSA_SetCenterFrqandSpan);
	RegisterMethod("PSA_SetRefLevel", Create_PSA_SetRefLevel);
	RegisterMethod("PSA_SetRFAttenuation", Create_PSA_SetRFAttenuation);
	RegisterMethod("PSA_SetRFAttenAuto", Create_PSA_SetRFAttenAuto);
	RegisterMethod("PSA_SetRefLevelOff", Create_PSA_SetRefLevelOff);
	RegisterMethod("PSA_SetExtAtten", Create_PSA_SetExtAtten);
	RegisterMethod("PSA_SetIntPreampOff", Create_PSA_SetIntPreampOff);
	RegisterMethod("PSA_SetLevelRange", Create_PSA_SetLevelRange);
	RegisterMethod("PSA_SetAverCount", Create_PSA_SetAverCount);
	RegisterMethod("PSA_SetAverType", Create_PSA_SetAverType);
	RegisterMethod("PSA_SetAverState", Create_PSA_SetAverState);
	RegisterMethod("PSA_SetRBW", Create_PSA_SetRBW);
	RegisterMethod("PSA_SetVBW", Create_PSA_SetVBW);
	RegisterMethod("PSA_SetDetectorMode", Create_PSA_SetDetectorMode);
	RegisterMethod("PSA_SetSweepTime", Create_PSA_SetSweepTime);
	RegisterMethod("PSA_SetAUTOSweepTime", Create_PSA_SetAUTOSweepTime);
	RegisterMethod("PSA_SetSweepTimeMode", Create_PSA_SetSweepTimeMode);
	RegisterMethod("PSA_SetTraceMaxHold", Create_PSA_SetTraceMaxHold);
	RegisterMethod("PSA_SetTraceMinHold", Create_PSA_SetTraceMinHold);
	RegisterMethod("PSA_SetTraceClearWrite", Create_PSA_SetTraceClearWrite);
	RegisterMethod("PSA_GetTraceData", Create_PSA_GetTraceData);
	RegisterMethod("PSA_SetTrigSource", Create_PSA_SetTrigSource);
	RegisterMethod("PSA_SetMarkMax", Create_PSA_SetMarkMax);
	RegisterMethod("PSA_SetMarkMin", Create_PSA_SetMarkMin);
	RegisterMethod("PSA_SetMaxNext", Create_PSA_SetMaxNext);
	RegisterMethod("PSA_SetMarkState", Create_PSA_SetMarkState);
	RegisterMethod("PSA_SetMarkFreq", Create_PSA_SetMarkPosition);			 
	RegisterMethod("PSA_SetMarkPosition", Create_PSA_SetMarkPosition);
	RegisterMethod("PSA_SetMarkerMode", Create_PSA_SetMarkerMode);
	RegisterMethod("PSA_GetMarkValue", Create_PSA_GetMarkValue);
	RegisterMethod("PSA_SetTDPOWSLOT", Create_PSA_SetTDPOWSLOT);
	RegisterMethod("PSA_GetEVMandPCDE", Create_PSA_GetEVMandPCDE);
	RegisterMethod("PSA_SetSPECMODE", Create_PSA_SetSPECMODE);
	RegisterMethod("PSA_SetStarandStopFreq", Create_PSA_SetStarandStopFreq);
	RegisterMethod("PSA_SetMULACPRMeas", Create_PSA_SetMULACPRMeas);
	RegisterMethod("PSA_SetMCCOUNT", Create_PSA_SetMCCOUNT);
	RegisterMethod("PSA_GetMULACPR", Create_PSA_GetMULACPR);
	RegisterMethod("PSA_SetMCPAVER", Create_PSA_SetMCPAVER);
	RegisterMethod("PSA_SetSEMMeas", Create_PSA_SetSEMMeas);
	RegisterMethod("PSA_SetInitSEM", Create_PSA_SetInitSEM);
	RegisterMethod("PSA_SetSEMAverageEnable", Create_PSA_SetSEMAverageEnable);
	RegisterMethod("PSA_SetSEMLimits", Create_PSA_SetSEMLimits);
	RegisterMethod("PSA_GetSEM", Create_PSA_GetSEM);
	RegisterMethod("PSA_SetEVMMeas", Create_PSA_SetEVMMeas);
	RegisterMethod("PSA_SetEVMSlot", Create_PSA_SetEVMSlot);
	RegisterMethod("PSA_SetInitEVM", Create_PSA_SetInitEVM);
	RegisterMethod("PSA_SetSyncType", Create_PSA_SetSyncType);
//	RegisterMethod("PSA_SetTOI", Create_PSA_SetTOI);
	RegisterMethod("PSA_GetTOI", Create_PSA_GetTOI);
	RegisterMethod("PSA_SetPVTMeas", Create_PSA_SetPVTMeas);
	RegisterMethod("PSA_SetInitPVT", Create_PSA_SetInitPVT);
	RegisterMethod("PSA_GetPVT", Create_PSA_GetPVT);
	RegisterMethod("PSA_SetPVTAverageEnable", Create_PSA_SetPVTAverageEnable);
	RegisterMethod("PSA_SetPVTMEASTimes", Create_PSA_SetPVTMEASTimes);
	RegisterMethod("PSA_SetACPMeas", Create_PSA_SetACPMeas);
	RegisterMethod("PSA_GetACP", Create_PSA_GetACP);
	RegisterMethod("PSA_SetTrigDelayTime", Create_PSA_SetTrigDelayTime);
	RegisterMethod("PSA_SetTraceAverage", Create_PSA_SetTraceAverage);
	RegisterMethod("PSA_SetEVMAver", Create_PSA_SetEVMAver);
	RegisterMethod("PSA_SetFilterType", Create_PSA_SetFilterType);
	RegisterMethod("PSA_SetScrambleCode", Create_PSA_SetScrambleCode);
	RegisterMethod("PSA_GetFluctuate", Create_PSA_GetFluctuate);
	RegisterMethod("PSA_SetMarkTime", Create_PSA_SetMarkTime);
	RegisterMethod("PSA_SetSweepEgatePolarity", Create_PSA_SetSweepEgatePolarity);
	RegisterMethod("PSA_SetSweepEgateLength", Create_PSA_SetSweepEgateLength);
	RegisterMethod("PSA_SetTrigLevel", Create_PSA_SetTrigLevel);
	RegisterMethod("PSA_SetStartAndStopSlot", Create_PSA_SetStartAndStopSlot);
	RegisterMethod("PSA_SetMeasMode", Create_PSA_SetMeasMode);
	RegisterMethod("PSA_GetPST", Create_PSA_GetPST);
	RegisterMethod("PSA_GetHarmonic", Create_PSA_GetHarmonic);
	RegisterMethod("PSA_SetCarrierSpaceList", Create_PSA_SetCarrierSpaceList);
	RegisterMethod("PSA_SetOffsetFreqList", Create_PSA_SetOffsetFreqList);
	RegisterMethod("PSA_SetOffsetFreqState", Create_PSA_SetOffsetFreqState);
	RegisterMethod("PSA_SetOffsetIBWList", Create_PSA_SetOffsetIBWList);
	RegisterMethod("PSA_SetGateViewState", Create_PSA_SetGateViewState);
	RegisterMethod("PSA_SetSweepEgatDelay", Create_PSA_SetSweepEgatDelay);
	RegisterMethod("PSA_SetNoiseCorrState", Create_PSA_SetNoiseCorrState);
	RegisterMethod("PSA_SetMeasNoiseBW", Create_PSA_SetMeasNoiseBW);
	RegisterMethod("PSA_SetRefCarrier", Create_PSA_SetRefCarrier);
	RegisterMethod("PSA_SetRefCarrierFreq", Create_PSA_SetRefCarrierFreq);
	RegisterMethod("PSA_SendCmd", Create_PSA_SendCmd);
	RegisterMethod("PSA_GetCmd", Create_PSA_GetCmd);
	RegisterMethod("PSA_GetIDN", Create_PSA_GetIDN);
	RegisterMethod("PSA_LoadFile", Create_PSA_LoadFile);
	RegisterMethod("PSA_SaveFile", Create_PSA_SaveFile);
	RegisterMethod("PSA_GetSEMPower", Create_PSA_GetSEMPower);
	RegisterMethod("PSA_GetEVMPower", Create_PSA_GetEVMPower);
	RegisterMethod("PSA_SetSweepPoint", Create_PSA_SetSweepPoint);
	RegisterMethod("PSA_SaveTraceByName", Create_PSA_SaveTraceByName);
	RegisterMethod("PSA_SetTraceMathTypeByName", Create_PSA_SetTraceMathTypeByName);
	RegisterMethod("PSA_DeleteTraceByName", Create_PSA_DeleteTraceByName);
	RegisterMethod("PSA_DeleteAllTrace", Create_PSA_DeleteAllTrace);		
	RegisterMethod("PSA_SetMarkerSearchFreqByName", Create_PSA_SetMarkerSearchFreqByName);		
	RegisterMethod("PSA_GetMarkerValueByName", Create_PSA_GetMarkerValueByName);		
	RegisterMethod("PSA_GetFluctuateByName", Create_PSA_GetFluctuateByName);
	RegisterMethod("PSA_GetMarkerFreqByName", Create_PSA_GetMarkerFreqByName);
	RegisterMethod("PSA_GetTraceDataXByName", Create_PSA_GetTraceDataXByName);
	RegisterMethod("PSA_GetTraceDataYByName", Create_PSA_GetTraceDataYByName);
	RegisterMethod("PSA_GetSweepTime", Create_PSA_GetSweepTime);
	RegisterMethod("PSA_GetTrigDelayTime", Create_PSA_GetTrigDelayTime);
	RegisterMethod("PSA_SetTrigPolarity", Create_PSA_SetTrigPolarity);
	RegisterMethod("PSA_ReadDev", Create_PSA_ReadDev);
	RegisterMethod("PSA_SetTrigOnce", Create_PSA_SetTrigOnce);
	RegisterMethod("PSA_Restart", Create_PSA_Restart);
	RegisterMethod("PSA_SetOffsetAbsList", Create_PSA_SetOffsetAbsList);
	RegisterMethod("PSA_SetEgatState", Create_PSA_SetEgatState);		
 	RegisterMethod("PSA_GetOBW", Create_PSA_GetOBW);
	RegisterMethod("PSA_SetSpan", Create_PSA_SetSpan);
	RegisterMethod("PSA_RefLevelAuto", Create_PSA_RefLevelAuto);
	RegisterMethod("PSA_SetACLRMEAS", Create_PSA_SetACLRMEAS);
	RegisterMethod("PSA_SetACPTXBW", Create_PSA_SetACPTXBW);
	RegisterMethod("PSA_SetACPTXCount", Create_PSA_SetACPTXCount);
	RegisterMethod("PSA_SetTriggerSource", Create_PSA_SetTriggerSource);
	RegisterMethod("PSA_SetTriggerLevel", Create_PSA_SetTriggerLevel);
	RegisterMethod("PSA_SetGateTrigSwitch", Create_PSA_SetGateTrigSwitch);
	RegisterMethod("PSA_SetGateDelay", Create_PSA_SetGateDelay);
	RegisterMethod("PSA_SetGateLength", Create_PSA_SetGateLength);
	RegisterMethod("PSA_GetACLR", Create_PSA_GetACLR);
	RegisterMethod("PSA_SetVSAMODE", Create_PSA_SetVSAMODE);
	RegisterMethod("PSA_SetPULSEMODE", Create_PSA_SetPULSEMODE);
	RegisterMethod("PSA_SetOBWPOWERBW", Create_PSA_SetOBWPOWERBW);
	RegisterMethod("PSA_GetEVMValue", Create_PSA_GetEVMValue);
	RegisterMethod("PSA_GetPULSEValue", Create_PSA_GetPULSEValue);
	RegisterMethod("PSA_SetSignCountFunc", Create_PSA_SetSignCountFunc);
	RegisterMethod("PSA_GetMarkFreq", Create_PSA_GetMarkFreq);
	RegisterMethod("PSA_SetTriggerOffSet", Create_PSA_SetTriggerOffSet);
	RegisterMethod("PSA_SetTimingPara", Create_PSA_SetTimingPara);
	RegisterMethod("PSA_SetTransFilter", Create_PSA_SetTransFilter);
	RegisterMethod("PSA_SetModulation", Create_PSA_SetModulation);
	RegisterMethod("PSA_SetCaptureLengthAuto", Create_PSA_SetCaptureLengthAuto);
	RegisterMethod("PSA_GetPULSENumber", Create_PSA_GetPULSENumber);


	//////////////////////注册网络仪驱动方法///////////////////////////
	RegisterMethod("ENA_Reset", Create_ENA_Reset);
	RegisterMethod("ENA_LoadFile", Create_ENA_LoadFile);
	RegisterMethod("ENA_SetChannelTrace", Create_ENA_SetChannelTrace);
	RegisterMethod("ENA_GetMarkerMin", Create_ENA_GetMarkerMin);
	RegisterMethod("ENA_GetMarkerMax", Create_ENA_GetMarkerMax);
	RegisterMethod("ENA_GetMarkerFreq", Create_ENA_GetMarkerFreq);
	RegisterMethod("ENA_SetAverageState", Create_ENA_SetAverageState);
	RegisterMethod("ENA_SetScaleAuto", Create_ENA_SetScaleAuto);
	RegisterMethod("ENA_SetMarkerStartandStopFreq", Create_ENA_SetMarkerStartandStopFreq);
	RegisterMethod("ENA_SaveDataToMemory", Create_ENA_SaveDataToMemory);
	RegisterMethod("ENA_SetTraceMathType", Create_ENA_SetTraceMathType);
	RegisterMethod("ENA_SetTraceFormat", Create_ENA_SetTraceFormat);
	RegisterMethod("ENA_SetDisplayTrace", Create_ENA_SetDisplayTrace);
	RegisterMethod("ENA_GetSearchOutputPowerPosition", Create_ENA_GetSearchOutputPowerPosition);
	RegisterMethod("ENA_GetSearchYDiffPosition", Create_ENA_GetSearchYDiffPosition);
	RegisterMethod("ENA_GetMarkerValue", Create_ENA_GetMarkerValue);
	RegisterMethod("ENA_SetRFOutputState", Create_ENA_SetRFOutputState);
	RegisterMethod("ENA_SetRFOutPower", Create_ENA_SetRFOutPower);
	RegisterMethod("ENA_GetFluctuate", Create_ENA_GetFluctuate);
	RegisterMethod("ENA_SetStartandStopFreq", Create_ENA_SetStartandStopFreq);
	RegisterMethod("ENA_SaveTraceToMemoryOfPC", Create_ENA_SaveTraceToMemoryOfPC);
	RegisterMethod("ENA_SetTraceMathTypeOfPC", Create_ENA_SetTraceMathTypeOfPC);
	RegisterMethod("ENA_SetMarkerSearchFreqOfPC", Create_ENA_SetMarkerSearchFreqOfPC);
	RegisterMethod("ENA_GetMarkerValueOfPC", Create_ENA_GetMarkerValueOfPC);
	RegisterMethod("ENA_GetFluctuateOfPC", Create_ENA_GetFluctuateOfPC);
	RegisterMethod("ENA_SetSmooth", Create_ENA_SetSmooth);
	RegisterMethod("ENA_SaveFile", Create_ENA_SaveFile);
	RegisterMethod("ENA_SetCalPortForward", Create_ENA_SetCalPortForward);
	RegisterMethod("ENA_SetCalType", Create_ENA_SetCalType);
	RegisterMethod("ENA_GetCalibrationData", Create_ENA_GetCalibrationData);
	RegisterMethod("ENA_SetECalType", Create_ENA_SetECalType);
	RegisterMethod("ENA_SaveCalibration", Create_ENA_SaveCalibration);
	RegisterMethod("ENA_SetCalKit", Create_ENA_SetCalKit);
	RegisterMethod("ENA_SendCmd", Create_ENA_SendCmd);
	RegisterMethod("ENA_GetCmd", Create_ENA_GetCmd);
	RegisterMethod("ENA_GetIDN", Create_ENA_GetIDN);
	RegisterMethod("ENA_GetMarkerXValue", Create_ENA_GetMarkerXValue);
	RegisterMethod("ENA_GetMarkerFreqOfPC", Create_ENA_GetMarkerFreqOfPC);
	RegisterMethod("ENA_GetTraceData", Create_ENA_GetTraceData);
	RegisterMethod("ENA_GetTraceDataX", Create_ENA_GetTraceDataX);	
	RegisterMethod("ENA_GetSweepType", Create_ENA_GetSweepType);	
	RegisterMethod("ENA_SetTrigSource", Create_ENA_SetTrigSource);
	RegisterMethod("ENA_SetTrigMode", Create_ENA_SetTrigMode);
	RegisterMethod("ENA_SaveTraceByName", Create_ENA_SaveTraceByName);
	RegisterMethod("ENA_SetTraceMathTypeByName", Create_ENA_SetTraceMathTypeByName);
	RegisterMethod("ENA_DeleteTraceByName", Create_ENA_DeleteTraceByName);
	RegisterMethod("ENA_DeleteAllTrace", Create_ENA_DeleteAllTrace);		
	RegisterMethod("ENA_SetMarkerSearchFreqByName", Create_ENA_SetMarkerSearchFreqByName);		
	RegisterMethod("ENA_GetMarkerValueByName", Create_ENA_GetMarkerValueByName);		
	RegisterMethod("ENA_GetFluctuateByName", Create_ENA_GetFluctuateByName);
	RegisterMethod("ENA_GetMarkerFreqByName", Create_ENA_GetMarkerFreqByName);	
	RegisterMethod("ENA_GetTraceDataYByName", Create_ENA_GetTraceDataYByName);	
	RegisterMethod("ENA_GetTraceDataXByName", Create_ENA_GetTraceDataXByName);
	RegisterMethod("ENA_SetMarkerFreq", Create_ENA_SetMarkerFreq);

	//////////////////////注册噪声仪驱动方法///////////////////////////
	RegisterMethod("NFA_Reset", Create_NFA_Reset);
	RegisterMethod("NFA_SetFreqMode", Create_NFA_SetFreqMode);
	RegisterMethod("NFA_SetStartAndStopFreq", Create_NFA_SetStartAndStopFreq);
	RegisterMethod("NFA_SetDispFormat", Create_NFA_SetDispFormat);
	RegisterMethod("NFA_GetFreqNfigure", Create_NFA_GetFreqNfigure);
	RegisterMethod("NFA_SetSweepMode", Create_NFA_SetSweepMode);
	RegisterMethod("NFA_LoadFile", Create_NFA_LoadFile);
	RegisterMethod("NFA_GetListMax", Create_NFA_GetListMax);
	RegisterMethod("NFA_SendCmd", Create_NFA_SendCmd);
	RegisterMethod("NFA_GetCmd", Create_NFA_GetCmd);
	RegisterMethod("NFA_GetIDN", Create_NFA_GetIDN);
	RegisterMethod("NFA_GetTraceMax", Create_NFA_GetTraceMax);
	RegisterMethod("NFA_GetTraceMin", Create_NFA_GetTraceMin);
	RegisterMethod("NFA_GetTraceFreqValue", Create_NFA_GetTraceFreqValue);


	//////////////////////注册芯通产品驱动方法///////////////////////////
	RegisterMethod("NTS_OpenDev", Create_NTS_OpenDev);
	RegisterMethod("NTS_CloseDev", Create_NTS_CloseDev);
	RegisterMethod("NTS_SetPowerState", Create_NTS_SetPowerState);
	RegisterMethod("NTS_SetPCB", Create_NTS_SetPCB);
	RegisterMethod("NTS_GetPCB", Create_NTS_GetPCB);
	RegisterMethod("NTS_GetTemperature", Create_NTS_GetTemperature);

//	RegisterMethod("NTS_SetModuleFuncNo", Create_NTS_SetModuleFuncNo);
//	RegisterMethod("NTS_SetModuleNo", Create_NTS_SetModuleNo);
//	RegisterMethod("NTS_SetUpAtten", Create_NTS_SetUpAtten);
//	RegisterMethod("NTS_GetUpAtten", Create_NTS_GetUpAtten);
//	RegisterMethod("NTS_SetDownAtten", Create_NTS_SetDownAtten);
//	RegisterMethod("NTS_GetDownAtten", Create_NTS_GetDownAtten);
//	RegisterMethod("NTS_GetUpOpd", Create_NTS_GetUpOpd);
//	RegisterMethod("NTS_GetDownOpd", Create_NTS_GetDownOpd);
//	RegisterMethod("NTS_GetDownIpd", Create_NTS_GetDownIpd);
	RegisterMethod("NTS_GetModuleVersion", Create_NTS_GetModuleVersion);
	RegisterMethod("NTS_GetCardVersion", Create_NTS_GetCardVersion);
	RegisterMethod("NTS_SetTmpCompensationData", Create_NTS_SetTmpCompensationData);
	RegisterMethod("NTS_GetTmpCompensationSense", Create_NTS_GetTmpCompensationSense);
	RegisterMethod("NTS_SetPushOutputVol", Create_NTS_SetPushOutputVol);
	RegisterMethod("NTS_GetPushOutPutVol", Create_NTS_GetPushOutPutVol);
	RegisterMethod("NTS_SetLastOutputVol", Create_NTS_SetLastOutputVol);
	RegisterMethod("NTS_GetLastOutputVol", Create_NTS_GetLastOutputVol);
	RegisterMethod("NTS_SetWorkMode", Create_NTS_SetWorkMode);
	RegisterMethod("NTS_GetWorkMode", Create_NTS_GetWorkMode);
	RegisterMethod("NTS_SetOneBytePCB", Create_NTS_SetOneBytePCB);
	RegisterMethod("NTS_GetOneBytePCB", Create_NTS_GetOneBytePCB);
	RegisterMethod("NTS_SetEEPROM", Create_NTS_SetEEPROM);
	RegisterMethod("NTS_GetEEPROM", Create_NTS_GetEEPROM);
	RegisterMethod("NTS_SetSwtichMode", Create_NTS_SetSwtichMode);
	RegisterMethod("NTS_GetDownVSWR", Create_NTS_GetDownVSWR);
	RegisterMethod("NTS_SetLOFreq", Create_NTS_SetLOFreq);
	RegisterMethod("NTS_GetModuleCPLDVersion", Create_NTS_GetModuleCPLDVersion);
	RegisterMethod("NTS_GetCardCPLDVersion", Create_NTS_GetCardCPLDVersion);
	RegisterMethod("NTS_SetWorkModeEx", Create_NTS_SetWorkModeEx);
	RegisterMethod("NTS_GetWorkModeEx", Create_NTS_GetWorkModeEx);
	RegisterMethod("NTS_SetDetectorMode", Create_NTS_SetDetectorMode);
	RegisterMethod("NTS_GetDetectorMode", Create_NTS_GetDetectorMode);
	RegisterMethod("NTS_GetCardProductNo", Create_NTS_GetCardProductNo);
	RegisterMethod("NTS_GetModuleProductNo", Create_NTS_GetModuleProductNo);
	RegisterMethod("NTS_SetLanLinkMode", Create_NTS_SetLanLinkMode);
	RegisterMethod("NTS_SetDectorState", Create_NTS_SetDectorState);
	RegisterMethod("NTS_SetSecGAOutputVol", Create_NTS_SetSecGAOutputVol);
	RegisterMethod("NTS_GetSecGAOutputVol", Create_NTS_GetSecGAOutputVol);
	RegisterMethod("NTS_SetThirdGAOutputVol", Create_NTS_SetThirdGAOutputVol);
	RegisterMethod("NTS_GetThirdGAOutputVol", Create_NTS_GetThirdGAOutputVol);
	RegisterMethod("NTS_GetCurrent", Create_NTS_GetCurrent);
	RegisterMethod("NTS_SetCurrentLimited", Create_NTS_SetCurrentLimited);
	RegisterMethod("NTS_GetCurrentLimited", Create_NTS_GetCurrentLimited);
	RegisterMethod("NTS_GetIsWarning", Create_NTS_GetIsWarning);
	RegisterMethod("NTS_ClearWarning", Create_NTS_ClearWarning);
	RegisterMethod("NTS_GetIDN", Create_NTS_GetIDN);
	RegisterMethod("NTS_SendCmd", Create_NTS_SendCmd);
	RegisterMethod("NTS_GetCmd", Create_NTS_GetCmd);
	RegisterMethod("NTS_SetStarAndStopFlash", Create_NTS_SetStarAndStopFlash);	
	RegisterMethod("NTS_GetStarAndStopFlash", Create_NTS_GetStarAndStopFlash);
	RegisterMethod("NTS_SetStarAndStopEEPROM", Create_NTS_SetStarAndStopEEPROM);
	RegisterMethod("NTS_GetStarAndStopEEPROM", Create_NTS_GetStarAndStopEEPROM);
	RegisterMethod("NTS_SetCRC", Create_NTS_SetCRC);
	RegisterMethod("NTS_SetPID", Create_NTS_SetPID);
	RegisterMethod("NTS_SetGainWorkPara", Create_NTS_SetGainWorkPara);
	RegisterMethod("NTS_GainDebug", Create_NTS_GainDebug);
	RegisterMethod("NTS_GetPowerState", Create_NTS_GetPowerState);
	RegisterMethod("NTS_SetStartAndStopRAM", Create_NTS_SetStartAndStopRAM);
	RegisterMethod("NTS_GetVoltage", Create_NTS_GetVoltage);
	RegisterMethod("NTS_SetActiveObject", Create_NTS_SetActiveObject);
	RegisterMethod("NTS_SetFourGAOutputVol", Create_NTS_SetFourGAOutputVol);
	RegisterMethod("NTS_GetFourGAOutputVol", Create_NTS_GetFourGAOutputVol);
	RegisterMethod("NTS_SetFiveGAOutputVol", Create_NTS_SetFiveGAOutputVol);
	RegisterMethod("NTS_GetFiveGAOutputVol", Create_NTS_GetFiveGAOutputVol);
	RegisterMethod("NTS_SetSixGAOutputVol", Create_NTS_SetSixGAOutputVol);
	RegisterMethod("NTS_GetSixGAOutputVol", Create_NTS_GetSixGAOutputVol);
	RegisterMethod("NTS_SetSevenGAOutputVol", Create_NTS_SetSevenGAOutputVol);
	RegisterMethod("NTS_GetSevenGAOutputVol", Create_NTS_GetSevenGAOutputVol);
	RegisterMethod("NTS_SetEightGAOutputVol", Create_NTS_SetEightGAOutputVol);
	RegisterMethod("NTS_GetEightGAOutputVol", Create_NTS_GetEightGAOutputVol);
	RegisterMethod("NTS_SetNineGAOutputVol", Create_NTS_SetNineGAOutputVol);
	RegisterMethod("NTS_GetNineGAOutputVol", Create_NTS_GetNineGAOutputVol);

	//////////////////////注册综合类驱动方法///////////////////////////
	RegisterMethod("SPE_Pause", Create_SPE_Pause);
	RegisterMethod("SPE_SetDelayTime", Create_SPE_SetDelayTime);
	RegisterMethod("SPE_ACPRPowerDebug", Create_SPE_ACPRPowerDebug);
	RegisterMethod("SPE_GetTimeSwitch", Create_SPE_GetTimeSwitch);
	RegisterMethod("SPE_ACPPowerDebug", Create_SPE_ACPPowerDebug);
	RegisterMethod("SPE_SEMPowerDebug", Create_SPE_SEMPowerDebug);
	RegisterMethod("SPE_EVMandPCDEPowerDebug", Create_SPE_EVMandPCDEPowerDebug);
	RegisterMethod("SPE_Add", Create_SPE_Add);
	RegisterMethod("SPE_Subtract", Create_SPE_Subtract);		
	RegisterMethod("SPE_Multiply", Create_SPE_Multiply);		
	RegisterMethod("SPE_Divide", Create_SPE_Divide);
	RegisterMethod("SPE_Compare", Create_SPE_Compare);	
	RegisterMethod("SPE_Equal", Create_SPE_Equal);		
	RegisterMethod("SPE_Absolute", Create_SPE_Absolute);
	RegisterMethod("SPE_SpectrumPowerDebug", Create_SPE_SpectrumPowerDebug);
	RegisterMethod("SPE_ACPRDebug", Create_SPE_ACPRDebug);
	RegisterMethod("SPE_ShowDialog", Create_SPE_ShowDialog);
	RegisterMethod("SPE_SpectrumPowerDebugEx", Create_SPE_SpectrumPowerDebugEx);
	RegisterMethod("SPE_ACPRPowerDebugEx", Create_SPE_ACPRPowerDebugEx);
	RegisterMethod("SPE_GetUpTimeSwitch", Create_SPE_GetUpTimeSwitch);
	RegisterMethod("SPE_GetDownTimeSwitch", Create_SPE_GetDownTimeSwitch);
	RegisterMethod("SPE_ShowPromptDialog", Create_SPE_ShowPromptDialog);
	RegisterMethod("SPE_CompareA", Create_SPE_CompareA);
	RegisterMethod("SPE_Power", Create_SPE_Power);
	RegisterMethod("SPE_DevReset", Create_SPE_DevReset);
	RegisterMethod("SPE_PRMPowerDebug", Create_SPE_PRMPowerDebug);
	RegisterMethod("SPE_SeparateData", Create_SPE_SeparateData);
	RegisterMethod("SPE_IntToString", Create_SPE_IntToString);
	RegisterMethod("SPE_FloatToString", Create_SPE_FloatToString);
	RegisterMethod("SPE_GetConditionData", Create_SPE_GetConditionData);
	RegisterMethod("SPE_GetMaxPosition", Create_SPE_GetMaxPosition);
	RegisterMethod("SPE_StrCat", Create_SPE_StrCat);
	RegisterMethod("SPE_GetMinPosition", Create_SPE_GetMinPosition);
	RegisterMethod("SPE_GainDebugWithENA", Create_SPE_GainDebugWithENA);
	RegisterMethod("SPE_OpenDev", Create_SPE_OpenDev);
	RegisterMethod("SPE_CloseDev", Create_SPE_CloseDev);
	RegisterMethod("SPE_PolyFit", Create_SPE_PolyFit);
	RegisterMethod("SPE_GetIDN", Create_SPE_GetIDN);
	RegisterMethod("SPE_WriteDev", Create_SPE_WriteDev);		
	RegisterMethod("SPE_ReadDev", Create_SPE_ReadDev);
	RegisterMethod("SPE_QueryDev", Create_SPE_QueryDev);
	RegisterMethod("SPE_SprintfDev", Create_SPE_SprintfDev);
	RegisterMethod("SPE_SetCom", Create_SPE_SetCom);
	RegisterMethod("SPE_SetDTR", Create_SPE_SetDTR);
	RegisterMethod("SPE_SetRTS", Create_SPE_SetRTS);
	RegisterMethod("SPE_SetXOFF", Create_SPE_SetXOFF);
	RegisterMethod("SPE_SetXON", Create_SPE_SetXON);
	RegisterMethod("SPE_FFT", Create_SPE_FFT);
	RegisterMethod("SPE_SetBufSize", Create_SPE_SetBufSize);
	RegisterMethod("SPE_ClearBuf", Create_SPE_ClearBuf);
	RegisterMethod("SPE_GetLastErrStr", Create_SPE_GetLastErrStr);	
	RegisterMethod("SPE_SetAttributeDev", Create_SPE_SetAttributeDev);

	RegisterMethod("SPE_AgePowerOn", Create_SPE_AgePowerOn); 
	RegisterMethod("SPE_AgePowerOff", Create_SPE_AgePowerOff); 
	RegisterMethod("SPE_AgeRead", Create_SPE_AgeRead); 

	RegisterMethod("SPE_SetIOPortVal", Create_SPE_SetIOPortVal);
	RegisterMethod("SPE_GetIOPortVal", Create_SPE_GetIOPortVal);
	RegisterMethod("SPE_SetIOTRBits", Create_SPE_SetIOTRBits);
	RegisterMethod("SPE_SetIOTrigPolarity", Create_SPE_SetIOTrigPolarity);
		

	//////////////////////注册DPD板驱动方法///////////////////////////
	RegisterMethod("DPD_SetDPDState", Create_DPD_SetDPDState);
	RegisterMethod("DPD_SetTxAtten", Create_DPD_SetTxAtten);
	RegisterMethod("DPD_SetRDAtten", Create_DPD_SetRDAtten);
	RegisterMethod("DPD_GetErrPower", Create_DPD_GetErrPower);
	RegisterMethod("DPD_SetSixPwrFpg", Create_DPD_SetSixPwrFpg);
	RegisterMethod("DPD_SetNinePwrFpg", Create_DPD_SetNinePwrFpg);
	RegisterMethod("DPD_SetTwelvePwrFpg", Create_DPD_SetTwelvePwrFpg);
	RegisterMethod("DPD_SetErrPwrDebugDT", Create_DPD_SetErrPwrDebugDT);
	RegisterMethod("DPD_ACPRPowerDebug", Create_DPD_ACPRPowerDebug);
	RegisterMethod("DPD_SetWorkFreq", Create_DPD_SetWorkFreq);
	RegisterMethod("DPD_ACPRPowerDebugDT", Create_DPD_ACPRPowerDebugDT);
	RegisterMethod("DPD_SetErrPwrDebug", Create_DPD_SetErrPwrDebug);
	RegisterMethod("DPD_SetSGMode", Create_DPD_SetSGMode);	
	RegisterMethod("DPD_SetCarriedMode", Create_DPD_SetCarriedMode);
	RegisterMethod("DPD_SetCarriedCount", Create_DPD_SetCarriedCount);
	RegisterMethod("DPD_Reset", Create_DPD_Reset);
	RegisterMethod("DPD_PRMPowerDebug", Create_DPD_PRMPowerDebug);
	RegisterMethod("DPD_GetIDN", Create_DPD_GetIDN);
	RegisterMethod("DPD_SendCmd", Create_DPD_SendCmd);
	RegisterMethod("DPD_GetCmd", Create_DPD_GetCmd);
	RegisterMethod("DPD_SetRFOutPower", Create_DPD_SetRFOutPower);
	RegisterMethod("DPD_GetRFOutPower", Create_DPD_GetRFOutPower);
	RegisterMethod("DPD_SetCFR", Create_DPD_SetCFR);
	RegisterMethod("DPD_GetCFR", Create_DPD_GetCFR);
	RegisterMethod("DPD_GetRDAtten", Create_DPD_GetRDAtten);
	RegisterMethod("DPD_GetTxAtten", Create_DPD_GetTxAtten);
	RegisterMethod("DPD_SetSmallTxAtten", Create_DPD_SetSmallTxAtten);
	RegisterMethod("DPD_GetSmallTxAtten", Create_DPD_GetSmallTxAtten);
	RegisterMethod("DPD_ReadDev", Create_DPD_ReadDev);
	
	//////////////////////注册功率计驱动方法///////////////////////////	
	RegisterMethod("PRM_Reset", Create_PRM_Reset);
	RegisterMethod("PRM_Calculate", Create_PRM_Calculate);
	RegisterMethod("PRM_SetMeasPos", Create_PRM_SetMeasPos);
	RegisterMethod("PRM_SetOffset", Create_PRM_SetOffset);
	RegisterMethod("PRM_SetMeasMode", Create_PRM_SetMeasMode);
	RegisterMethod("PRM_GetPower", Create_PRM_GetPower);
	RegisterMethod("PRM_SetMeasUnit", Create_PRM_SetMeasUnit);
	RegisterMethod("PRM_GetIDN", Create_PRM_GetIDN);
	RegisterMethod("PRM_SendCmd", Create_PRM_SendCmd);
	RegisterMethod("PRM_GetCmd", Create_PRM_GetCmd);
	

	//////////////////////注册DA调试驱动方法///////////////////////////
	RegisterMethod("DEB_WriteDebug", Create_DEB_WriteDebug);
	RegisterMethod("DEB_ReadDebug", Create_DEB_ReadDebug);


	//////////////////////注册EEPROM驱动方法///////////////////////////
	RegisterMethod("ADJ_WriteCal", Create_ADJ_WriteCal);
	RegisterMethod("ADJ_ReadCal", Create_ADJ_ReadCal);
	RegisterMethod("ADJ_GetClientSNRelate", Create_ADJ_GetClientSNRelate);

	//////////////////////注册万用表驱动方法///////////////////////////	
	RegisterMethod("SPE_GetCurrent", Create_MMT_GetCurrent);
	RegisterMethod("MMT_GetCurrent", Create_MMT_GetCurrent);
	RegisterMethod("MMT_GetZn", Create_MMT_GetZn);
	
	//////////////////////注册矩阵开关驱动方法///////////////////////////
	RegisterMethod("SW_SetSwtichState", Create_SW_SetSwtichState);
	RegisterMethod("SW_SetCtrlPort", Create_SW_SetCtrlPort);

	//////////////////////注册IRU驱动方法///////////////////////////
	RegisterMethod("IRU_Reboot", Create_IRU_Reboot);
	RegisterMethod("IRU_Reset", Create_IRU_Reset);
	RegisterMethod("IRU_GetIDN", Create_IRU_GetIDN);
	RegisterMethod("IRU_SendCmd", Create_IRU_SendCmd);
	RegisterMethod("IRU_GetCmd", Create_IRU_GetCmd);
	RegisterMethod("IRU_LoadFile", Create_IRU_LoadFile);

	//////////////////////注册TestCard驱动方法///////////////////////////
	RegisterMethod("TC_GetCardCPLDVersion", Create_TC_GetCardMCUVersion);	
	RegisterMethod("TC_GetCardCPLDVersion", Create_TC_GetCardCPLDVersion);	
	RegisterMethod("TC_SetCardProductNo", Create_TC_SetCardProductNo);
	RegisterMethod("TC_SetCardStartAndStopFlash", Create_TC_SetCardStartAndStopFlash);
	RegisterMethod("TC_GetCardStartAndStopFlash", Create_TC_GetCardStartAndStopFlash);	

	////////////////////////////////////NCARD//////////////////////////////////////
	RegisterMethod("NC_OpenDev", Create_NC_OpenDev);
	RegisterMethod("NC_CloseDev", Create_NC_CloseDev);
	RegisterMethod("NC_QuerySysParam", Create_NC_QuerySysParam);
	RegisterMethod("NC_QuerySysState", Create_NC_QuerySysState);
	RegisterMethod("NC_CreateCommObject", Create_NC_CreateCommObject);
	RegisterMethod("NC_DeleteCommObject", Create_NC_DeleteCommObject);
	RegisterMethod("NC_Read", Create_NC_Read);
	RegisterMethod("NC_Write", Create_NC_Write);
	RegisterMethod("NC_SetBufSize", Create_NC_SetBufSize);
	RegisterMethod("NC_ClearBuf", Create_NC_ClearBuf);
	RegisterMethod("NC_Sprintf", Create_NC_Sprintf);
	RegisterMethod("NC_Query", Create_NC_Query);
	RegisterMethod("NC_QueryContextInfo", Create_NC_QueryContextInfo);
	RegisterMethod("NC_QueryVersionInfo", Create_NC_QueryVersionInfo);
	RegisterMethod("NC_SetIPAddress", Create_NC_SetIPAddress);
	RegisterMethod("NC_Reset", Create_NC_Reset);

	////////////////////////////////////AUTOIT//////////////////////////////////////
	RegisterMethod("AU3_Run", Create_AU3_Run);
	RegisterMethod("AU3_RunWait", Create_AU3_RunWait);
	RegisterMethod("AU3_WinWaitActive", Create_AU3_WinWaitActive);
	RegisterMethod("AU3_Send", Create_AU3_Send);
	RegisterMethod("AU3_ControlClick", Create_AU3_ControlClick);
	RegisterMethod("AU3_ControlSetText", Create_AU3_ControlSetText);
	RegisterMethod("AU3_ControlGetText", Create_AU3_ControlGetText);
	RegisterMethod("AU3_ControlCommand", Create_AU3_ControlCommand);
	RegisterMethod("AU3_ControlListView", Create_AU3_ControlListView);
	RegisterMethod("AU3_ClipGet", Create_AU3_ClipGet);
	RegisterMethod("AU3_ClipPut", Create_AU3_ClipPut);
	RegisterMethod("AU3_ControlDisable", Create_AU3_ControlDisable);
	RegisterMethod("AU3_ControlEnable", Create_AU3_ControlEnable);
	RegisterMethod("AU3_ControlFocus", Create_AU3_ControlFocus);
	RegisterMethod("AU3_ControlGetFocus", Create_AU3_ControlGetFocus);
	RegisterMethod("AU3_ControlGetPos", Create_AU3_ControlGetPos);
	RegisterMethod("AU3_ControlHide", Create_AU3_ControlHide);
	RegisterMethod("AU3_ControlMove", Create_AU3_ControlMove);
	RegisterMethod("AU3_ControlSend", Create_AU3_ControlSend);
	RegisterMethod("AU3_ControlShow", Create_AU3_ControlShow);
	RegisterMethod("AU3_MouseClick", Create_AU3_MouseClick);
	RegisterMethod("AU3_MouseClickDrag", Create_AU3_MouseClickDrag);
	RegisterMethod("AU3_MouseDown", Create_AU3_MouseDown);
	RegisterMethod("AU3_MouseUp", Create_AU3_MouseUp);
	RegisterMethod("AU3_MouseMove", Create_AU3_MouseMove);
	RegisterMethod("AU3_MouseWheel", Create_AU3_MouseWheel);
	RegisterMethod("AU3_AutoItSetOption", Create_AU3_AutoItSetOption);
	RegisterMethod("AU3_Opt", Create_AU3_Opt);
	RegisterMethod("AU3_ProcessClose", Create_AU3_ProcessClose);
	RegisterMethod("AU3_ProcessExists", Create_AU3_ProcessExists);
	RegisterMethod("AU3_ProcessWait", Create_AU3_ProcessWait);
	RegisterMethod("AU3_ProcessWaitClose", Create_AU3_ProcessWaitClose);
	RegisterMethod("AU3_WinActivate", Create_AU3_WinActivate);
	RegisterMethod("AU3_WinActive", Create_AU3_WinActive);
	RegisterMethod("AU3_WinClose", Create_AU3_WinClose);
	RegisterMethod("AU3_WinExists", Create_AU3_WinExists);
	RegisterMethod("AU3_WinKill", Create_AU3_WinKill);
	RegisterMethod("AU3_WinSetOnTop", Create_AU3_WinSetOnTop);
	RegisterMethod("AU3_WinSetState", Create_AU3_WinSetState);


}