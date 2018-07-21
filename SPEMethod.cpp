
#include "stdafx.h"
#include "SPEMethod.h"
#include <assert.h>
#include "stdio.h"
//#include <map>
#include <stdlib.h>
#include "math.h"
#include "windows.h"
#include "resource.h"
#include "NTSScriptLib.h"

extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器
extern BOOL gCommIsStr;						// 通用读写函数数据发送方式 True:字符串	false:数据流

typedef struct
{
	HDC 	hdc ;
	int 	xText ;
	int 	yText ;
	int 	xStart ;
	int 	yStart ;
	int 	xIncr ;
	int 	yIncr ;
	int 	xMax ;
	int 	yMax ;
}
CBPARAM;


/************************************************************************/
/* 特殊功能函数方法类                                                    */
/************************************************************************/
//class M_SPE_Pause
M_SPE_Pause::M_SPE_Pause()
:BaseMethod()
{
	sprintf(m_MethodScript, "系统暂停");
	m_InputPara = CreateParamStruct();
	Init();
}
M_SPE_Pause::~M_SPE_Pause()
{
//	free(m_InputPara);
}
int M_SPE_Pause::Init(void)
{
	sprintf(m_InputPara->paramName, "MsgInfomation");
	m_InputPara->paramType = NTSString;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
 }
int M_SPE_Pause::Run(void)
{
	int retVal = -1;
	
	if(strlen(m_InputPara->paramVal)==0)
	{
 		retVal = MessageBox(0,"请重新输入提示信息！  ","提示信息",MB_OK);
		return -1;
	}
	retVal = MessageBox(0,m_InputPara->paramVal,"提示信息",MB_OK);
	if(retVal==1)
	{
		return NTS_SUCCESS;
	}
	else 
	{
		return -1;
	}
}
//class M_SPE_SetDelayTime
M_SPE_SetDelayTime::M_SPE_SetDelayTime()
:BaseMethod()
{
	sprintf(m_MethodScript,"设置系统延时时间(单位:ms)");
	m_InputPara = CreateParamStruct();
	Init();
}
M_SPE_SetDelayTime::~M_SPE_SetDelayTime()
{
//	free(m_InputPara);
}
int M_SPE_SetDelayTime::Init(void)
{
	sprintf(m_InputPara->paramName, "DelayTime");
	m_InputPara->paramType = NTSUInt32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara);
	return NTS_SUCCESS;
}
int M_SPE_SetDelayTime::Run(void)
{
	unsigned long delaytime;
	delaytime = atoi(m_InputPara->paramVal);
	if(delaytime<0)
	{
		return NTS_INVALID_PARA;
	}
	Sleep(delaytime);
	return NTS_SUCCESS;
}
//class M_SPE_ACPRPowerDebug
M_SPE_ACPRPowerDebug::M_SPE_ACPRPowerDebug()
:BaseMethod()
{
	sprintf(m_MethodScript,"ACPR测试调整输出功率(refpower:目标功率值 maxpower:信号源电平上限值)");
	m_SGDevName = CreateParamStruct();
	m_PSADevName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_SPE_ACPRPowerDebug::~M_SPE_ACPRPowerDebug()
{
//	free(m_SGDevName);
//	free(m_PSADevName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_SPE_ACPRPowerDebug::Init(void)
{
	sprintf(m_SGDevName->paramName, "SG_ConnectStr");
	m_SGDevName->paramType = SGDevice;
	m_SGDevName->paramCount = 1;
	sprintf(m_SGDevName->paramVal,"");
	sprintf(m_SGDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_SGDevName);
	
	sprintf(m_PSADevName->paramName, "PSA_ConnectStr");
	m_PSADevName->paramType = PSADevice;
	m_PSADevName->paramCount = 1;
	sprintf(m_PSADevName->paramVal,"");
	sprintf(m_PSADevName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADevName);

	sprintf(m_InputPara1->paramName, "refpower");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "maxpower");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_SPE_ACPRPowerDebug::Run(void)
{
	int retVal;
	double currentlevel,power,maxpower;
	double diffpower;
	double value[300];
	long count;
	short int vSGHandle = 0,vPSAHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int k;
	
	//信号源句柄
	sprintf(vDeviveName, m_SGDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vSGHandle = it->second.DevHandle;
	
	//频谱仪句柄
	sprintf(vDeviveName,m_PSADevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vPSAHandle = it->second.DevHandle;

	power = atof(m_InputPara1->paramVal);
	maxpower = atof(m_InputPara2->paramVal);
	
	if(vPSAHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	if(vSGHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	retVal = PSA_GetMULACPR(vPSAHandle,value,&count);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	if((value[0]>=power-0.1)&&(value[0]<=(power+0.1))) 
	{
		return NTS_SUCCESS;
	}   
	else
	{
		retVal =SG_GetRFAmplitu(vSGHandle, &currentlevel);
		if(retVal==NTS_SUCCESS)
		{
			diffpower=value[0]-(power+0.05);  
			if((currentlevel-diffpower)>maxpower||(currentlevel-diffpower)<-110)      
			{
				return NTS_POWER_EXTMAXPOWER_WARNING;
			}
			retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-diffpower);
		}
		for(k=1;k<10;k++)
		{ 
			retVal =PSA_GetMULACPR(vPSAHandle,value,&count);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
			retVal =SG_GetRFAmplitu(vSGHandle,&currentlevel);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
			if(value[0]>(power+0.08)) 
			{
				retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-0.05);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				Sleep(500);     
   		     } 
			else if(value[0]<power)
			{
				retVal =SG_SetRFAmplitu(vSGHandle,currentlevel+0.05);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				Sleep(500);   
			}
			else
			{
				return NTS_SUCCESS;	
			}
		}
	}
	if (k == 10)
	{
		return NTS_POWER_EXTMAXPOWER_WARNING;
	}
	return NTS_SUCCESS;
}
//class M_SPE_GetTimeSwitch
M_SPE_GetTimeSwitch::M_SPE_GetTimeSwitch()
:BaseMethod()
{
	sprintf(m_MethodScript,"获得开关时间量");
	m_SGDevName = CreateParamStruct();
	m_PSADevName = CreateParamStruct();

	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputParaMaxNum = 4;
	for(int i=0;i<m_OutputParaMaxNum;i++)
	{
		m_OutputPara[i] = CreateParamStruct();
	}
	Init();
}
M_SPE_GetTimeSwitch::~M_SPE_GetTimeSwitch()
{
/*	free(m_SGDevName);
	free(m_PSADevName);
	for(int i=0;i<m_OutputParaMaxNum;i++)
	{
		free(m_OutputPara[i]);
	}*/
}
int M_SPE_GetTimeSwitch::Init(void)
{
	sprintf(m_SGDevName->paramName, "SG_ConnectStr");
	m_SGDevName->paramType = SGDevice;
	m_SGDevName->paramCount = 1;
	sprintf(m_SGDevName->paramVal,"");
	sprintf(m_SGDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_SGDevName);
	
	sprintf(m_PSADevName->paramName, "PSA_ConnectStr");
	m_PSADevName->paramType = PSADevice;
	m_PSADevName->paramCount = 1;
	sprintf(m_PSADevName->paramVal,"");
	sprintf(m_PSADevName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADevName);

	sprintf(m_InputPara1->paramName, "DelaytimeofUpEdge");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "DelaytimeofDownEdge");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_OutputPara[0]->paramName, "DelaytimeofUpEdge");
	m_OutputPara[0]->paramType = NTSReal32;
	m_OutputPara[0]->paramCount = 1;
	sprintf(m_OutputPara[0]->paramVal,"");
	sprintf(m_OutputPara[0]->paramUnit , "ns");
	m_OutputParamVector.push_back(m_OutputPara[0]);
	
	sprintf(m_OutputPara[1]->paramName, "timeofUpEdge");
	m_OutputPara[1]->paramType = NTSReal32;
	m_OutputPara[1]->paramCount = 1;
	sprintf(m_OutputPara[1]->paramVal,"");
	sprintf(m_OutputPara[1]->paramUnit , "ns");
	m_OutputParamVector.push_back(m_OutputPara[1]);

	sprintf(m_OutputPara[2]->paramName, "DelaytimeofDownEdge");
	m_OutputPara[2]->paramType = NTSReal32;
	m_OutputPara[2]->paramCount = 1;
	sprintf(m_OutputPara[2]->paramVal,"");
	sprintf(m_OutputPara[2]->paramUnit , "ns");
	m_OutputParamVector.push_back(m_OutputPara[2]);
	
	sprintf(m_OutputPara[3]->paramName, "timeofDownEdge");
	m_OutputPara[3]->paramType = NTSReal32;
	m_OutputPara[3]->paramCount = 1;
	sprintf(m_OutputPara[3]->paramVal,"");
	sprintf(m_OutputPara[3]->paramUnit , "ns");
	m_OutputParamVector.push_back(m_OutputPara[3]);
	return NTS_SUCCESS;
}
int M_SPE_GetTimeSwitch::Run(void)
{
	int retVal, i=0;
	double data[1024];
	double max=0,min=0,tempdata1,tempdata2;
	long count =0,upindex =0,downindex = 0;
	double trigdelaytime,currenttrigdaleytime,currentsweeptime,precision,difftrigtime;
	double tmpdiff1,tmpdiff2,orgdiff1,orgdiff2;
	double realdaleytime,realswitchtime;

	short int vSGHandle = 0,vPSAHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	//信号源句柄
	sprintf(vDeviveName,m_SGDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vSGHandle = it->second.DevHandle;
	
	//频谱仪句柄
	sprintf(vDeviveName,m_PSADevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vPSAHandle = it->second.DevHandle;

	if(vPSAHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	//上升沿
	trigdelaytime = atof(m_InputPara1->paramVal);
	retVal = PSA_SetSweepEgatePolarity(vPSAHandle,0);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_SetTrigDelayTime(vPSAHandle,trigdelaytime);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_SetTraceAverage(vPSAHandle);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	Sleep(2000);
	retVal = PSA_GetTraceData(vPSAHandle,data,&count);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_GetSweepTime(vPSAHandle,&currentsweeptime);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_GetTrigDelayTime(vPSAHandle,&currenttrigdaleytime);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	difftrigtime = currenttrigdaleytime - trigdelaytime/1000; //实际触发延迟时间与理论触发延迟时间的差量
	precision =currentsweeptime/(count-1);		 //踪迹每点时间量
	for(i=0;i<count;i++)
	{
		if(data[i]>max) 
			max = data[i]; 
		if(data[i]<min) 
			min = data[i]; 
	}
	tempdata1=(max-min)*0.85+min;	//有效值范围高点
	tempdata2=(max-min)*0.15+min;	//有效值范围低点
	
	//计算单前点与有效范围的绝对差量
	orgdiff1 =fabs(tempdata1-data[0]); 
	orgdiff2=fabs(tempdata2-data[0]); 
	for(i=1;i<count;i++)
	{
		tmpdiff1=fabs(tempdata1-data[i]); 
		tmpdiff2=fabs(tempdata2-data[i]); 
		 
		if(tmpdiff1 < orgdiff1 )  
		{ 
			upindex = i;    
			orgdiff1 = tmpdiff1 ;    
		}
		if(tmpdiff2 < orgdiff2 )  
		{ 
			downindex = i;    
			orgdiff2 = tmpdiff2 ;   
		}
	}
	//单位:ns
	realdaleytime=(downindex*precision+difftrigtime)*1000000000;		//上升沿延迟时间
	realswitchtime=fabs((upindex-downindex)*precision*1000000000);				//上升沿时间
	sprintf(m_OutputPara[0]->paramVal,"%e",realdaleytime);
	sprintf(m_OutputPara[1]->paramVal,"%e",realswitchtime);
		
	//下降沿
	trigdelaytime = atof(m_InputPara2->paramVal);
	retVal = PSA_SetSweepEgatePolarity(vPSAHandle,1);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_SetTrigDelayTime(vPSAHandle,trigdelaytime);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_SetTraceAverage(vPSAHandle);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	Sleep(1000);
	retVal = PSA_GetTraceData(vPSAHandle,data,&count);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_GetSweepTime(vPSAHandle,&currentsweeptime);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_GetTrigDelayTime(vPSAHandle,&currenttrigdaleytime);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	difftrigtime = currenttrigdaleytime - trigdelaytime/1000; //实际触发延迟时间与理论触发延迟时间的差量
	precision =currentsweeptime/count;		 //踪迹每点时间量
	for(i=0;i<count;i++)
	{
		if(data[i]>max) 
			max = data[i]; 
		if(data[i]<min) 
			min = data[i]; 
	}
	tempdata1=(max-min)*0.85+min;	//有效值范围高点
	tempdata2=(max-min)*0.15+min;	//有效值范围低点
	
	//计算单前点与有效范围的绝对差量
	orgdiff1 =fabs(tempdata1-data[0]); 
	orgdiff2=fabs(tempdata2-data[0]); 
	for(i=1;i<count;i++)
	{
		tmpdiff1=fabs(tempdata1-data[i]); 
		tmpdiff2=fabs(tempdata2-data[i]); 
		
		if(tmpdiff1 < orgdiff1 )  
		{ 
			upindex = i;    
			orgdiff1 = tmpdiff1 ;    
		}
		if(tmpdiff2 < orgdiff2 )  
		{ 
			downindex = i;    
			orgdiff2 = tmpdiff2 ;   
		}
	}
	//单位:ns
	realdaleytime=((upindex)*precision+difftrigtime)*1000000000;		//下降沿延迟时间
	realswitchtime=fabs((upindex-downindex)*precision*1000000000);		//下降沿时间
	sprintf(m_OutputPara[2]->paramVal,"%e",realdaleytime);
	sprintf(m_OutputPara[3]->paramVal,"%e",realswitchtime);

	return NTS_SUCCESS;
}
//class M_SPE_ACPPowerDebug
M_SPE_ACPPowerDebug::M_SPE_ACPPowerDebug()
:BaseMethod()
{
	sprintf(m_MethodScript,"单载波测试调整输出功率(refpower:目标功率值 maxpower:信号源电平上限值)");
	m_SGDevName = CreateParamStruct();
	m_PSADevName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_SPE_ACPPowerDebug::~M_SPE_ACPPowerDebug()
{
//	free(m_SGDevName);
//	free(m_PSADevName);
//
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_SPE_ACPPowerDebug::Init(void)
{
	sprintf(m_SGDevName->paramName, "SG_ConnectStr");
	m_SGDevName->paramType = SGDevice;
	m_SGDevName->paramCount = 1;
	sprintf(m_SGDevName->paramVal,"");
	sprintf(m_SGDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_SGDevName);

	sprintf(m_PSADevName->paramName, "PSA_ConnectStr");
	m_PSADevName->paramType = PSADevice;
	m_PSADevName->paramCount = 1;
	sprintf(m_PSADevName->paramVal,"");
	sprintf(m_PSADevName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADevName);

	sprintf(m_InputPara1->paramName, "refpower");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "maxpower");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_SPE_ACPPowerDebug::Run(void)
{
	int retVal;
	double currentlevel,power,maxpower;
	double diffpower;
	double value[300];
	long count;	
	int k;
	
	short int vSGHandle = 0,vPSAHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	//信号源句柄
	sprintf(vDeviveName,m_SGDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vSGHandle = it->second.DevHandle;

	//频谱仪句柄
	sprintf(vDeviveName,m_PSADevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vPSAHandle = it->second.DevHandle;

	power = atof(m_InputPara1->paramVal);
	maxpower = atof(m_InputPara2->paramVal);
	retVal = PSA_GetACP(vPSAHandle,value,&count);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	if((value[0]>=power-0.1)&&(value[0]<=(power+0.1))) 
	{
		return NTS_SUCCESS;
	}   
	else
	{
		retVal =SG_GetRFAmplitu(vSGHandle,&currentlevel);
		if(retVal==NTS_SUCCESS)
		{
			diffpower=value[0]-(power+0.05);  
			if((currentlevel-diffpower)>maxpower||(currentlevel-diffpower)<-110)      
			{
				return NTS_POWER_EXTMAXPOWER_WARNING;     
			}
			retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-diffpower);
		}
		for(k=1;k<10;k++)
		{ 
			retVal =PSA_GetACP(vPSAHandle,value,&count);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
			retVal =SG_GetRFAmplitu(vSGHandle, &currentlevel);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
			if(value[0]>(power+0.08)) 
			{
				retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-0.05);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				Sleep(500);     
   		     } 
			else if(value[0]<power)
			{
				retVal =SG_SetRFAmplitu(vSGHandle,currentlevel+0.05);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				Sleep(500);   
			}
			else
			{
				return NTS_SUCCESS;	
			}
		}
	}
	if (k == 10)
	{
		return NTS_POWER_EXTMAXPOWER_WARNING;
	}
	return NTS_SUCCESS;
}
//class M_SPE_SEMPowerDebug
M_SPE_SEMPowerDebug::M_SPE_SEMPowerDebug()
:BaseMethod()
{
	sprintf(m_MethodScript,"频谱发射模板模式下调整输出功率(refpower:目标功率值 maxpower:信号源电平上限值)");
	m_SGDevName = CreateParamStruct();
	m_PSADevName = CreateParamStruct();

	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_SPE_SEMPowerDebug::~M_SPE_SEMPowerDebug()
{
//	free(m_SGDevName);
//	free(m_PSADevName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_SPE_SEMPowerDebug::Init(void)
{
	sprintf(m_SGDevName->paramName, "SG_ConnectStr");
	m_SGDevName->paramType = SGDevice;
	m_SGDevName->paramCount = 1;
	sprintf(m_SGDevName->paramVal,"");
	sprintf(m_SGDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_SGDevName);
	
	sprintf(m_PSADevName->paramName, "PSA_ConnectStr");
	m_PSADevName->paramType = PSADevice;
	m_PSADevName->paramCount = 1;
	sprintf(m_PSADevName->paramVal,"");
	sprintf(m_PSADevName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADevName);

	sprintf(m_InputPara1->paramName, "refpower");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "maxpower");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_SPE_SEMPowerDebug::Run(void)
{
	int retVal;
	double currentlevel,power,maxpower;
	double diffpower;
	double value[300];
	
	short int vSGHandle = 0,vPSAHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	//信号源句柄
	sprintf(vDeviveName,m_SGDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vSGHandle = it->second.DevHandle;
	
	//频谱仪句柄
	sprintf(vDeviveName,m_PSADevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vPSAHandle = it->second.DevHandle;
	
	power = atof(m_InputPara1->paramVal);
	maxpower = atof(m_InputPara2->paramVal);
	
	if(vPSAHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	if(vSGHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	retVal = PSA_GetSEMPower(vPSAHandle,value);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	if((value[0]>=power-0.15)&&(value[0]<=(power+0.15))) 
	{
		return NTS_SUCCESS;
	}   
	else
	{
		retVal =SG_GetRFAmplitu(vSGHandle,&currentlevel);
		if(retVal==NTS_SUCCESS)
		{
			diffpower=value[0]-(power+0.05);  
			if((currentlevel-diffpower)>maxpower||(currentlevel-diffpower)<-110)      
			{
				return NTS_POWER_EXTMAXPOWER_WARNING;     
			}
			retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-diffpower);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
			retVal = PSA_SetInitSEM(vPSAHandle);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
		}
		Sleep(500);    
		retVal =PSA_GetSEMPower(vPSAHandle, value);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}
		retVal =SG_GetRFAmplitu(vSGHandle, &currentlevel);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}
		if(value[0]>(power+0.1)||value[0]<(power-0.1)) 
		{
			if(value[0]>(power+0.1))
			{
				retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-0.1);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				retVal = PSA_SetInitSEM(vPSAHandle);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				Sleep(500);
			}
			else
			{
				retVal =SG_SetRFAmplitu(vSGHandle,currentlevel+0.1);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				retVal = PSA_SetInitSEM(vPSAHandle);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				Sleep(500);
			}
		} 
		else
		{
			return NTS_SUCCESS;	
		}
	/*
		for(int k=1;k<3;k++)
			{ 
				Sleep(1000);    
				retVal =PSA_GetSEMPower(vPSAHandle,value);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				retVal =SG_GetRFAmplitu(vSGHandle,&currentlevel);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				retVal = PSA_SetInitSEM(vPSAHandle);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				if(value[0]>(power+0.5)) 
				{
					retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-0.05);
					if(retVal!=NTS_SUCCESS)
					{
						return retVal;
					}
					retVal = PSA_SetInitSEM(vPSAHandle);
					if(retVal!=NTS_SUCCESS)
					{
						return retVal;
					}
					Sleep(500);     
	   		     } 
				else if(value[0]<power)
				{
					retVal =SG_SetRFAmplitu(vSGHandle,currentlevel+0.05);
					if(retVal!=NTS_SUCCESS)
					{
						return retVal;
					}
					retVal = PSA_SetInitSEM(vPSAHandle);
					if(retVal!=NTS_SUCCESS)
					{
						return retVal;
					}
					Sleep(500);   
				}	
				else
				{
					return NTS_SUCCESS;	
				}
			}
		*/
	
	}
	return NTS_SUCCESS;
}
//class M_SPE_EVMandPCDEPowerDebug
M_SPE_EVMandPCDEPowerDebug::M_SPE_EVMandPCDEPowerDebug()
:BaseMethod()
{
	sprintf(m_MethodScript,"EVM和PCDE模式下调整输出功率(refpower:目标功率值 maxpower:信号源电平上限值)");
	m_SGDevName = CreateParamStruct();
	m_PSADevName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_SPE_EVMandPCDEPowerDebug::~M_SPE_EVMandPCDEPowerDebug()
{
//	free(m_SGDevName);
//	free(m_PSADevName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_SPE_EVMandPCDEPowerDebug::Init(void)
{
	sprintf(m_SGDevName->paramName, "SG_ConnectStr");
	m_SGDevName->paramType = SGDevice;
	m_SGDevName->paramCount = 1;
	sprintf(m_SGDevName->paramVal,"");
	sprintf(m_SGDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_SGDevName);
	
	sprintf(m_PSADevName->paramName, "PSA_ConnectStr");
	m_PSADevName->paramType = PSADevice;
	m_PSADevName->paramCount = 1;
	sprintf(m_PSADevName->paramVal,"");
	sprintf(m_PSADevName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADevName);

	sprintf(m_InputPara1->paramName, "refpower");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "maxpower");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_SPE_EVMandPCDEPowerDebug::Run(void)
{
	int retVal;
	double currentlevel,power,maxpower;
	double diffpower;
	double value[300];
	short int vSGHandle = 0,vPSAHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int k;
	
	//信号源句柄
	sprintf(vDeviveName,m_SGDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vSGHandle = it->second.DevHandle;
	
	//频谱仪句柄
	sprintf(vDeviveName,m_PSADevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vPSAHandle = it->second.DevHandle;
	
	power = atof(m_InputPara1->paramVal);
	maxpower = atof(m_InputPara2->paramVal);
	
	if(vPSAHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	if(vSGHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	retVal = PSA_GetEVMPower(vPSAHandle,value);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	if((value[0]>=power-0.1)&&(value[0]<=(power+0.1))) 
	{
		return NTS_SUCCESS;
	}   
	else
	{
		retVal =SG_GetRFAmplitu(vSGHandle,&currentlevel);
		if(retVal==NTS_SUCCESS)
		{
			diffpower=value[0]-(power+0.05);  
			if((currentlevel-diffpower)>maxpower||(currentlevel-diffpower)<-110)      
			{
				return NTS_POWER_EXTMAXPOWER_WARNING;     
			}
			retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-diffpower);
		}
		for(k=1;k<20;k++)
		{ 
			retVal =PSA_GetEVMPower(vPSAHandle,value);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
			retVal =SG_GetRFAmplitu(vSGHandle, &currentlevel);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
			if(value[0]>(power+0.08)) 
			{
				retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-0.05);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				Sleep(500);     
   		     } 
			else if(value[0]<power)
			{
				retVal =SG_SetRFAmplitu(vSGHandle,currentlevel+0.05);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				Sleep(500);   
			}
			else
			{
				return NTS_SUCCESS;	
			}
		}
	}
	if (k == k)
	{
		return NTS_POWER_EXTMAXPOWER_WARNING;
	}
	return NTS_SUCCESS;
}
//class M_SPE_Add	
M_SPE_Add::M_SPE_Add()
:BaseMethod()
{
	sprintf(m_MethodScript,"相加运算");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_SPE_Add::~M_SPE_Add()
{
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}
int M_SPE_Add::Init(void)
{
	sprintf(m_InputPara1->paramName, "para1");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "para2");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_OutputPara->paramName, "result");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_SPE_Add::Run(void)
{
	double para1,para2,result;
		
	para1 = atof(m_InputPara1->paramVal);
	para2 = atof(m_InputPara2->paramVal);
	result = para1+para2;
	sprintf(m_OutputPara->paramVal,"%e",result);
	return NTS_SUCCESS;

}
//class M_SPE_Subtract	
M_SPE_Subtract::M_SPE_Subtract()
:BaseMethod()
{
	sprintf(m_MethodScript,"相减运算");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_SPE_Subtract::~M_SPE_Subtract()
{
///	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}
int M_SPE_Subtract::Init(void)
{
	sprintf(m_InputPara1->paramName, "minuend");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "subtrahend");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara->paramName, "result");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_SPE_Subtract::Run(void)
{
	double minuend,subtrahend,result;
	
	minuend = atof(m_InputPara1->paramVal);
	subtrahend = atof(m_InputPara2->paramVal);
	result = minuend-subtrahend;
	sprintf(m_OutputPara->paramVal,"%e",result);
	return NTS_SUCCESS;
	
}
//class M_SPE_Multiply	
M_SPE_Multiply::M_SPE_Multiply()
:BaseMethod()
{
	sprintf(m_MethodScript,"相乘运算");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_SPE_Multiply::~M_SPE_Multiply()
{
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}
int M_SPE_Multiply::Init(void)
{
	sprintf(m_InputPara1->paramName, "multiply1");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "multiply2");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara->paramName, "result");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_SPE_Multiply::Run(void)
{
	double multiply1,multiply2,result;
	
	multiply1 = atof(m_InputPara1->paramVal);
	multiply2 = atof(m_InputPara2->paramVal);
	result = multiply1*multiply2;
	sprintf(m_OutputPara->paramVal,"%e",result);
	return NTS_SUCCESS;
}
//class M_SPE_Divide	
M_SPE_Divide::M_SPE_Divide()
:BaseMethod()
{
	sprintf(m_MethodScript,"相除运算");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_SPE_Divide::~M_SPE_Divide()
{
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}
int M_SPE_Divide::Init(void)
{
	sprintf(m_InputPara1->paramName, "dividend");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "divisor");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara->paramName, "result");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_SPE_Divide::Run(void)
{
	double dividend,divisor,result;
	
	dividend = atof(m_InputPara1->paramVal);
	divisor = atof(m_InputPara2->paramVal);
	if(divisor==0)
	{
		return NTS_INVALID_PARA;
	}
	result = dividend/divisor;
	sprintf(m_OutputPara->paramVal,"%e",result);
	return NTS_SUCCESS;
}
//class M_SPE_Compare	
M_SPE_Compare::M_SPE_Compare()
:BaseMethod()
{
	sprintf(m_MethodScript,"比较");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();

	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	m_OutputPara3 = CreateParamStruct();
	Init();
}
M_SPE_Compare::~M_SPE_Compare()
{
//	free(m_InputPara1);
///	free(m_InputPara2);
//	free(m_OutputPara1);
//	free(m_OutputPara2);
//	free(m_OutputPara3);
}
int M_SPE_Compare::Init(void)
{
	sprintf(m_InputPara1->paramName, "para1");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "para2");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara1->paramName, "bigger");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);

	sprintf(m_OutputPara2->paramName, "smaller");
	m_OutputPara2->paramType = NTSReal32;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara2);

	sprintf(m_OutputPara3->paramName, "state");
	m_OutputPara3->paramType = NTSInt16;
	m_OutputPara3->paramCount = 1;
	sprintf(m_OutputPara3->paramVal,"");
	sprintf(m_OutputPara3->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara3);
	return NTS_SUCCESS;
}
int M_SPE_Compare::Run(void)
{
	double para1,para2,bigger,smaller;
	int state;

	para1 = atof(m_InputPara1->paramVal);
	para2 = atof(m_InputPara2->paramVal);
	if(para1>para2)
	{
		bigger = para1;
		smaller = para2;
		state = 1;
	}
	if(para1<para2)
	{
		bigger = para2;
		smaller = para1;
		state = -1;
	}
	if(para1==para2)
	{
		bigger = para1;
		smaller = para2;
		state = 0;
	}
	sprintf(m_OutputPara1->paramVal,"%e",bigger);
	sprintf(m_OutputPara2->paramVal,"%e",smaller);
	sprintf(m_OutputPara3->paramVal,"%d",state);
	return NTS_SUCCESS;
}
//class M_SPE_CompareA	
M_SPE_CompareA::M_SPE_CompareA()
:BaseMethod()
{
	sprintf(m_MethodScript,"比较");
	for(int i=0;i<12;i++)
	{
		m_InputPara[i] = CreateParamStruct();
	}	
	
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();	
	Init();
}
M_SPE_CompareA::~M_SPE_CompareA()
{
/*	for(int i=0;i<12;i++)
	{
		free(m_InputPara[i]);	
	}
	free(m_OutputPara1);
	free(m_OutputPara2);*/	
}
int M_SPE_CompareA::Init(void)
{
	sprintf(m_InputPara[0]->paramName, "Count");
	m_InputPara[0]->paramType = NTSInt16;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"");
	sprintf(m_InputPara[0]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[0]);
	
	sprintf(m_InputPara[1]->paramName, "Para1");
	m_InputPara[1]->paramType = NTSReal32;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"");
	sprintf(m_InputPara[1]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[1]);

	sprintf(m_InputPara[2]->paramName, "Para2");
	m_InputPara[2]->paramType = NTSReal32;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"");
	sprintf(m_InputPara[2]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[2]);

	sprintf(m_InputPara[3]->paramName, "Para3");
	m_InputPara[3]->paramType = NTSReal32;
	m_InputPara[3]->paramCount = 1;
	sprintf(m_InputPara[3]->paramVal,"");
	sprintf(m_InputPara[3]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[3]);

	sprintf(m_InputPara[4]->paramName, "Para4");
	m_InputPara[4]->paramType = NTSReal32;
	m_InputPara[4]->paramCount = 1;
	sprintf(m_InputPara[4]->paramVal,"");
	sprintf(m_InputPara[4]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[4]);

	sprintf(m_InputPara[5]->paramName, "Para5");
	m_InputPara[5]->paramType = NTSReal32;
	m_InputPara[5]->paramCount = 1;
	sprintf(m_InputPara[5]->paramVal,"");
	sprintf(m_InputPara[5]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[5]);

	sprintf(m_InputPara[6]->paramName, "Para6");
	m_InputPara[6]->paramType = NTSReal32;
	m_InputPara[6]->paramCount = 1;
	sprintf(m_InputPara[6]->paramVal,"");
	sprintf(m_InputPara[6]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[6]);

	sprintf(m_InputPara[7]->paramName, "Para7");
	m_InputPara[7]->paramType = NTSReal32;
	m_InputPara[7]->paramCount = 1;
	sprintf(m_InputPara[7]->paramVal,"");
	sprintf(m_InputPara[7]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[7]);

	sprintf(m_InputPara[8]->paramName, "Para8");
	m_InputPara[8]->paramType = NTSReal32;
	m_InputPara[8]->paramCount = 1;
	sprintf(m_InputPara[8]->paramVal,"");
	sprintf(m_InputPara[8]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[8]);

	sprintf(m_InputPara[9]->paramName, "Para9");
	m_InputPara[9]->paramType = NTSReal32;
	m_InputPara[9]->paramCount = 1;
	sprintf(m_InputPara[9]->paramVal,"");
	sprintf(m_InputPara[9]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[9]);

	sprintf(m_InputPara[10]->paramName, "Para10");
	m_InputPara[10]->paramType = NTSReal32;
	m_InputPara[10]->paramCount = 1;
	sprintf(m_InputPara[10]->paramVal,"");
	sprintf(m_InputPara[10]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[10]);

	sprintf(m_InputPara[11]->paramName, "Para11");
	m_InputPara[11]->paramType = NTSReal32;
	m_InputPara[11]->paramCount = 1;
	sprintf(m_InputPara[11]->paramVal,"");
	sprintf(m_InputPara[11]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[11]);
	
	sprintf(m_OutputPara1->paramName, "bigger");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	sprintf(m_OutputPara2->paramName, "smaller");
	m_OutputPara2->paramType = NTSReal32;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara2);	
	
	return NTS_SUCCESS;
}
int M_SPE_CompareA::Run(void)
{
	double para[12],bigger,smaller;
	int count;
	int i;
	
	count = atoi(m_InputPara[0]->paramVal);
	if(count<=0||count>11)
	{
		return NTS_INVALID_PARA;
	}
	for(i =1;i<=count;i++)
	{
		para[i-1] = atof(m_InputPara[i]->paramVal);
	}	
	bigger = para[0];
	smaller = para[0];
	for(i = 1;i<count;i++)
	{
		if(bigger<para[i])
		{
			bigger = para[i];
		}
		if (smaller>para[i])
		{
			smaller = para[i];
		}
	}

	sprintf(m_OutputPara1->paramVal,"%.12f",bigger);
	sprintf(m_OutputPara2->paramVal,"%.12f",smaller);
	
	return NTS_SUCCESS;
}
//class M_SPE_Equal
M_SPE_Equal::M_SPE_Equal()
:BaseMethod()
{
	sprintf(m_MethodScript,"赋值");
	m_InputPara = CreateParamStruct();

	m_OutputPara = CreateParamStruct();

	Init();
}
M_SPE_Equal::~M_SPE_Equal()
{
//	free(m_InputPara);

//	free(m_OutputPara);
}
int M_SPE_Equal::Init(void)
{
	sprintf(m_InputPara->paramName, "inputvalue");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	

	sprintf(m_OutputPara->paramName, "outputvalue");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_SPE_Equal::Run(void)
{
	float inputpara,outputpara;
		
	inputpara = atof(m_InputPara->paramVal);

	outputpara =inputpara; 
	sprintf(m_OutputPara->paramVal,"%e",outputpara);
	
	return NTS_SUCCESS;
}
//class M_SPE_Absolute
M_SPE_Absolute::M_SPE_Absolute()
:BaseMethod()
{
	sprintf(m_MethodScript,"绝对值");
	m_InputPara = CreateParamStruct();
	
	m_OutputPara = CreateParamStruct();
	
	Init();
}
M_SPE_Absolute::~M_SPE_Absolute()
{
//	free(m_InputPara);
	
//	free(m_OutputPara);
}
int M_SPE_Absolute::Init(void)
{
	sprintf(m_InputPara->paramName, "inputvalue");
	m_InputPara->paramType = NTSReal32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	
	sprintf(m_OutputPara->paramName, "outputvalue");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_SPE_Absolute::Run(void)
{
	float inputpara,outputpara;
	
	inputpara = atof(m_InputPara->paramVal);

	outputpara =fabs(inputpara); 
	sprintf(m_OutputPara->paramVal,"%e",outputpara);
	
	return NTS_SUCCESS;
}
//class M_SPE_SpectrumPowerDebug
M_SPE_SpectrumPowerDebug::M_SPE_SpectrumPowerDebug()
:BaseMethod()
{
	sprintf(m_MethodScript,"频谱模式下调整输出功率(refpower:目标功率值 maxpower:信号源电平上限值)");
	m_SGDevName = CreateParamStruct();
	m_PSADevName = CreateParamStruct();

	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_SPE_SpectrumPowerDebug::~M_SPE_SpectrumPowerDebug()
{
//	free(m_SGDevName);
//	free(m_PSADevName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_SPE_SpectrumPowerDebug::Init(void)
{
	sprintf(m_SGDevName->paramName, "SG_ConnectStr");
	m_SGDevName->paramType = SGDevice;
	m_SGDevName->paramCount = 1;
	sprintf(m_SGDevName->paramVal,"");
	sprintf(m_SGDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_SGDevName);
	
	sprintf(m_PSADevName->paramName, "PSA_ConnectStr");
	m_PSADevName->paramType = PSADevice;
	m_PSADevName->paramCount = 1;
	sprintf(m_PSADevName->paramVal,"");
	sprintf(m_PSADevName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADevName);

	sprintf(m_InputPara1->paramName, "refpower");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "maxpower");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara2);
	return NTS_SUCCESS;
}
int M_SPE_SpectrumPowerDebug::Run(void)
{
	int retVal;
	double currentlevel,power,maxpower;
	double diffpower;
	double value;
	
	short int vSGHandle = 0,vPSAHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	//信号源句柄
	sprintf(vDeviveName,m_SGDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vSGHandle = it->second.DevHandle;
	
	//频谱仪句柄
	sprintf(vDeviveName,m_PSADevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vPSAHandle = it->second.DevHandle;

	power = atof(m_InputPara1->paramVal);
	maxpower = atof(m_InputPara2->paramVal);
	
	if(vPSAHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	if(vSGHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	retVal = PSA_SetMarkMax(vPSAHandle,1);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	Sleep(500); 
	retVal = PSA_GetMarkValue(vPSAHandle,1,&value);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	if((value>=power-0.1)&&(value<=(power+0.1))) 
	{
		return NTS_SUCCESS;
	}   
	else
	{
		retVal =SG_GetRFAmplitu(vSGHandle, &currentlevel);
		if(retVal==NTS_SUCCESS)
		{
			diffpower=value-(power+0.05);  
			if((currentlevel-diffpower)>maxpower||(currentlevel-diffpower)<-110)      
			{
				return NTS_POWER_EXTMAXPOWER_WARNING;     
			}
			retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-diffpower - 0.6);
		}
		Sleep(500);     
		for(int k=1;k<100;k++)
		{ 
			retVal =PSA_GetMarkValue(vPSAHandle,1,&value);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
			retVal =SG_GetRFAmplitu(vSGHandle, &currentlevel);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
			if(value>(power+0.08)) 
			{
				if (value - (power + 0.08) >= 1)
				{
					retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-0.1);
					if(retVal!=NTS_SUCCESS)
					{
						return retVal;
					}
					Sleep(50);     
				}
				else
				{
					retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-0.05);
					if(retVal!=NTS_SUCCESS)
					{
						return retVal;
					}
					Sleep(50);     
				}		
   		     } 
			else if(value<power)
			{
				if (value - power <= 1)
				{
					retVal =SG_SetRFAmplitu(vSGHandle,currentlevel+0.1);
					if(retVal!=NTS_SUCCESS)
					{
						return retVal;
					}
					Sleep(50);   
				}
				else
				{
					retVal =SG_SetRFAmplitu(vSGHandle,currentlevel+0.05);
				    if(retVal!=NTS_SUCCESS)
					{
						return retVal;
					}
					Sleep(50);   
				}
			}
			else
			{
				return NTS_SUCCESS;	
			}
		}
	}
	return NTS_SUCCESS;
}
//class M_SPE_ACPRDebug
M_SPE_ACPRDebug::M_SPE_ACPRDebug()
:BaseMethod()
{
	sprintf(m_MethodScript,"ACPR自动调试");
	m_SGDevName = CreateParamStruct();
	m_PSADevName = CreateParamStruct();
	m_NTSDevName = CreateParamStruct();
	for (int i = 0; i < 9; i++)
	{
		m_InputPara[i] = CreateParamStruct();
	}
	Init();
	ACPRDebug = NULL;
}

M_SPE_ACPRDebug::~M_SPE_ACPRDebug()
{
//	free(m_SGDevName);
/*	free(m_PSADevName);
	free(m_NTSDevName);
	for (int i = 0; i < 9; i++)
	{
		free(m_InputPara[i]);		
	}*/
}

int M_SPE_ACPRDebug::Init(void)
{
	//信号源连接符
	sprintf(m_SGDevName->paramName, "SG_ConnectStr");
	m_SGDevName->paramType = SGDevice;
	m_SGDevName->paramCount = 1;
	sprintf(m_SGDevName->paramVal,"");
	sprintf(m_SGDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_SGDevName);
	//频谱仪连接符
	sprintf(m_PSADevName->paramName, "PSA_ConnectStr");
	m_PSADevName->paramType = PSADevice;
	m_PSADevName->paramCount = 1;
	sprintf(m_PSADevName->paramVal,"");
	sprintf(m_PSADevName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADevName);	
	//芯通产品
	sprintf(m_NTSDevName->paramName, "NTS_ConnectStr");
	m_NTSDevName->paramType = NTSDevice;
	m_NTSDevName->paramCount = 1;
	sprintf(m_NTSDevName->paramVal,"");
	sprintf(m_NTSDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_NTSDevName);
	
	sprintf(m_InputPara[0]->paramName, "ProduceName");
	m_InputPara[0]->paramType = NTSString;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"T2263ZX");
	sprintf(m_InputPara[0]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[0]);
	
	sprintf(m_InputPara[1]->paramName, "MMTPort");
	m_InputPara[1]->paramType = NTSInt8;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"1");
	sprintf(m_InputPara[1]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[1]);

	sprintf(m_InputPara[2]->paramName, "Channel");
	m_InputPara[2]->paramType = NTSInt8;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"1");
	sprintf(m_InputPara[2]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[2]);

	sprintf(m_InputPara[3]->paramName, "Refpower");
	m_InputPara[3]->paramType = NTSReal32;
	m_InputPara[3]->paramCount = 1;
	sprintf(m_InputPara[3]->paramVal,"36.5");
	sprintf(m_InputPara[3]->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara[3]);

	sprintf(m_InputPara[4]->paramName, "SGMaxPower");
	m_InputPara[4]->paramType = NTSReal32;
	m_InputPara[4]->paramCount = 1;
	sprintf(m_InputPara[4]->paramVal,"0");
	sprintf(m_InputPara[4]->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara[4]);

	sprintf(m_InputPara[5]->paramName, "Intervaltime");
	m_InputPara[5]->paramType = NTSUInt16;
	m_InputPara[5]->paramCount = 1;
	sprintf(m_InputPara[5]->paramVal,"1000");
	sprintf(m_InputPara[5]->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara[5]);

	sprintf(m_InputPara[6]->paramName, "UpLimit16M");
	m_InputPara[6]->paramType = NTSReal32;
	m_InputPara[6]->paramCount = 1;
	sprintf(m_InputPara[6]->paramVal,"-45");
	sprintf(m_InputPara[6]->paramUnit , "dB");
	m_InputParamVector.push_back(m_InputPara[6]);

	sprintf(m_InputPara[7]->paramName, "UpLimit32M");
	m_InputPara[7]->paramType = NTSReal32;
	m_InputPara[7]->paramCount = 1;
	sprintf(m_InputPara[7]->paramVal,"-49");
	sprintf(m_InputPara[7]->paramUnit , "dB");
	m_InputParamVector.push_back(m_InputPara[7]);

	sprintf(m_InputPara[8]->paramName, "ErrorRange");
	m_InputPara[8]->paramType = NTSReal32;
	m_InputPara[8]->paramCount = 1;
	sprintf(m_InputPara[8]->paramVal,"0.5");
	sprintf(m_InputPara[8]->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara[8]);
	return NTS_SUCCESS;
}
int M_SPE_ACPRDebug::Run(void)
{
	HINSTANCE ACPRDllHandle;
	int RetVal;
	char DllName[256];
	int comport,delaytime,ch;
	float refpower,SGMaxPower;
	float uplimit16m,uplimit32m,errorRange;
	
	short int vSGHandle = 0,vPSAHandle, vNTSHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	//信号源句柄
	sprintf(vDeviveName,m_SGDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vSGHandle = it->second.DevHandle;
	
	//频谱仪句柄
	sprintf(vDeviveName,m_PSADevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vPSAHandle = it->second.DevHandle;

	//芯通产品句柄
	sprintf(vDeviveName,m_NTSDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vNTSHandle = it->second.DevHandle;

    sprintf(DllName, "%sAD.dll", m_InputPara[0]->paramVal);
	//电流表串口号
	comport = atoi(m_InputPara[1]->paramVal);
	if (comport<0||comport>255)
	{
		return NTS_INVALID_PARA;
	}
	//通道号
	ch = atoi(m_InputPara[2]->paramVal);
	//模块工作的额定功率
	refpower  = atof(m_InputPara[3]->paramVal);
	//信号源上限功率值
	SGMaxPower = atof(m_InputPara[4]->paramVal);
	if (SGMaxPower>20)
	{
		return NTS_INVALID_PARA;
	}
	delaytime = atoi(m_InputPara[5]->paramVal);
	if (delaytime<=0)
	{
		return NTS_INVALID_PARA;
	}
	uplimit16m = atof(m_InputPara[6]->paramVal);
	uplimit32m = atof(m_InputPara[7]->paramVal);
	errorRange = atof(m_InputPara[8]->paramVal);

	ACPRDllHandle = LoadLibrary(DllName);
	if (ACPRDllHandle == INVALID_HANDLE_VALUE||ACPRDllHandle==0)
	{
		FreeLibrary(ACPRDllHandle);
		return NTS_LOADDLL_ERROR;
	}
	ACPRDebug = (_ACPRDebug *)::GetProcAddress(ACPRDllHandle,"_DEB_SetAutoACPR@44");
    if(ACPRDebug == NULL)
	{
		FreeLibrary(ACPRDllHandle);
		return NTS_INVALID_METHOD;
	}
	RetVal = ACPRDebug(
		vNTSHandle,
		comport ,
		vSGHandle,
		vPSAHandle, 
		ch,
		refpower,
		SGMaxPower,
		delaytime,
		uplimit16m,
		uplimit32m,
		errorRange
		);
	FreeLibrary(ACPRDllHandle);
	return RetVal;
}

//class M_SPE_ShowDialog
HWND hwndDLG = 0;
BOOL IsOK = FALSE;
char szString[DLGTEXT_MAXLENGTH];

M_SPE_ShowDialog::M_SPE_ShowDialog()
:BaseMethod()
{
	sprintf(m_MethodScript, "输入对话框,输入数据范围(0.2~1)");
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	if (hwndDLG != 0)
	{
		EndDialog(hwndDLG, TRUE);
		DestroyWindow(hwndDLG);
		PostQuitMessage(0);
		hwndDLG = NULL;
		IsOK = FALSE;
	}
	Init();
}

M_SPE_ShowDialog::~M_SPE_ShowDialog()
{
	
	if (hwndDLG != 0)
	{
		EndDialog(hwndDLG, TRUE);
		DestroyWindow(hwndDLG);
		PostQuitMessage(0);
		hwndDLG = NULL;
		IsOK = FALSE;
	}
//	free(m_InputPara);
//	free(m_OutputPara);
}

int M_SPE_ShowDialog::Init(void)
{
	sprintf(m_InputPara->paramName, "Hide");
	m_InputPara->paramType = NTSString;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"输入：");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	
	sprintf(m_OutputPara->paramName, "outputvalue");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT message, 
					  WPARAM wParam, LPARAM lParam) ;

int M_SPE_ShowDialog::Run(void)
{

	MSG msg;
	double tempVal;
	HFONT hFont;
	HANDLE hModule;

	hModule = GetModuleHandle(NULL);
	IsOK = FALSE;
	
	if (hwndDLG == 0)
	{
		hwndDLG = CreateDialog((HINSTANCE)hModule, MAKEINTRESOURCE(IDD_DLG_SHOW), 
						NULL, (DLGPROC)DlgProc);

		ShowWindow(hwndDLG, SW_SHOW);		
		SetDlgItemText(hwndDLG, IDC_EDIT2, m_InputPara->paramVal);
		SetFocus(GetDlgItem(hwndDLG, IDC_EDIT1));
		hFont = CreateFont(-14,0,0,0,FW_EXTRABOLD,0,0,0,GB2312_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"宋体"); 
		SendMessage(GetDlgItem(hwndDLG, IDC_EDIT2), WM_SETFONT, (WPARAM)hFont,0); 
		UpdateWindow(hwndDLG);
		
		while (GetMessage (&msg, NULL, 0, 0))
		{			
			if (IsOK)
			{
				GetDlgItemText (hwndDLG, IDC_EDIT1, szString, DLGTEXT_MAXLENGTH);
				
				if (strcmp(szString, "0") != 0)
				{
					if (atof(szString) ==0||atof(szString)<0.2||atof(szString)>1)
					{
						IsOK = FALSE;
						MessageBox (NULL, TEXT ("输入电流超出范围,请重新输入"),
									TEXT ("输入信息"), MB_ICONERROR);
						SetDlgItemText(hwndDLG, IDC_EDIT1, "");
						SetFocus(GetDlgItem(hwndDLG, IDC_EDIT1));
						continue;
					}
				}
				tempVal = atof(szString);
				sprintf(m_OutputPara->paramVal, "%e", tempVal);
				EndDialog(hwndDLG, TRUE);
				DestroyWindow(hwndDLG);
				hwndDLG = NULL;
				IsOK = FALSE;
				return NTS_SUCCESS;
			}

			
			TranslateMessage (&msg) ;
			DispatchMessage (&msg) ;
			
			
			Sleep(1);
		}
	}
	
	
	return NTS_SUCCESS;
}

BOOL CALLBACK DlgProc(HWND hDlg, UINT message, 
					  WPARAM wParam, LPARAM lParam) 
{ 
	char space[DLGTEXT_MAXLENGTH];
	switch(message) 
	{ 
    case WM_INITDIALOG: 
		{
			SetFocus(hDlg);   
			return TRUE; 
		}
	case   WM_SETFOCUS:   
		return   TRUE;   
	case   WM_KEYDOWN:   
		MessageBox(hDlg,   "",   "",   MB_OK);   
		return   TRUE;   
		
	
    case WM_COMMAND: 
		{
			GetDlgItemText (hwndDLG, IDC_EDIT1, space, DLGTEXT_MAXLENGTH);

			if(space[strlen(space)-1]==' ')
			{
				IsOK = TRUE;
			}
			if(LOWORD(wParam)==IDOK) 
			{
				IsOK = TRUE;
			}
			if(LOWORD(wParam)==IDC_EDIT1)
			{
				return FALSE;
			}
			return TRUE;
		}
    case WM_CLOSE: 
		{
			DestroyWindow(hDlg); 
			hwndDLG = NULL; 
			return TRUE; 
		}


	} 

	return FALSE;
} 

//class M_SPE_SpectrumPowerDebugEx
M_SPE_SpectrumPowerDebugEx::M_SPE_SpectrumPowerDebugEx()
:BaseMethod()
{
	sprintf(m_MethodScript,"频谱模式下调整输出功率(refpower:目标功率值 maxpower:信号源电平上限值 IntervalTime:间隔时间)");
	m_SGDevName = CreateParamStruct();
	m_PSADevName = CreateParamStruct();

	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}
M_SPE_SpectrumPowerDebugEx::~M_SPE_SpectrumPowerDebugEx()
{
//	free(m_SGDevName);
//	free(m_PSADevName);
//
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}
int M_SPE_SpectrumPowerDebugEx::Init(void)
{
	sprintf(m_SGDevName->paramName, "SG_ConnectStr");
	m_SGDevName->paramType = SGDevice;
	m_SGDevName->paramCount = 1;
	sprintf(m_SGDevName->paramVal,"");
	sprintf(m_SGDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_SGDevName);
	
	sprintf(m_PSADevName->paramName, "PSA_ConnectStr");
	m_PSADevName->paramType = PSADevice;
	m_PSADevName->paramCount = 1;
	sprintf(m_PSADevName->paramVal,"");
	sprintf(m_PSADevName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADevName);

	sprintf(m_InputPara1->paramName, "refpower");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "maxpower");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "intervaltime");
	m_InputPara3->paramType = NTSUInt32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"500");
	sprintf(m_InputPara3->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara3);

	return NTS_SUCCESS;
}
int M_SPE_SpectrumPowerDebugEx::Run(void)
{
	int retVal;
	double currentlevel,power,maxpower;
	double diffpower;
	double value;
	int intervaltime;
	short int vSGHandle = 0,vPSAHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int k;
	
	//信号源句柄
	sprintf(vDeviveName,m_SGDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vSGHandle = it->second.DevHandle;
	
	//频谱仪句柄
	sprintf(vDeviveName,m_PSADevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vPSAHandle = it->second.DevHandle;
	
	power = atof(m_InputPara1->paramVal);
	maxpower = atof(m_InputPara2->paramVal);
	intervaltime = atoi(m_InputPara3->paramVal);
	
	if(vPSAHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	if(vSGHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	retVal = PSA_SetMarkMax(vPSAHandle,1);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	Sleep(intervaltime); 
	retVal = PSA_GetMarkValue(vPSAHandle,1,&value);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	if((value>=power-0.1)&&(value<=(power+0.1))) 
	{
		return NTS_SUCCESS;
	}  
	//粗调
	for(k = 0 ; k < 5; k++)
	{
	
		retVal =SG_GetRFAmplitu(vSGHandle, &currentlevel);
		if(retVal==NTS_SUCCESS)
		{
			
			diffpower = value - power;					//偏移量
			if((currentlevel - diffpower) > maxpower||(currentlevel - diffpower) < -110)      
			{
				return NTS_POWER_EXTMAXPOWER_WARNING;     
			}
			retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-diffpower);
		}
		Sleep(intervaltime); 
		retVal = PSA_SetMarkMax(vPSAHandle,1);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}
		Sleep(intervaltime);     
		retVal =PSA_GetMarkValue(vPSAHandle,1,&value);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}
		if( (value >= power - 0.5)&&(value <= (power + 0.5))) 
		{
			break;
		}  
	}
	//细调
	for(k = 0; k<10; k++)
	{ 
		diffpower = value - power;			//偏移量
		if (fabs(diffpower) <= 0.1)
		{
			return NTS_SUCCESS;
		}
		retVal =SG_GetRFAmplitu(vSGHandle, &currentlevel);
		if(retVal != NTS_SUCCESS)
		{									
			return retVal;	
		}
		if((currentlevel - diffpower) > maxpower||(currentlevel - diffpower) < -110)      
		{
			return NTS_POWER_EXTMAXPOWER_WARNING;     
		}
		if (diffpower < 0)
		{
			currentlevel = currentlevel+0.1;
			retVal = SG_SetRFAmplitu(vSGHandle, currentlevel);
		}
		else
		{
			currentlevel = currentlevel-0.1;
			retVal = SG_SetRFAmplitu(vSGHandle, currentlevel);
		}
		Sleep(intervaltime); 
		retVal = PSA_SetMarkMax(vPSAHandle,1);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}
		Sleep(intervaltime);     
		retVal = PSA_GetMarkValue(vPSAHandle, 1, &value);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}
		if( (value >= power - 0.1)&&(value <= (power + 0.1))) 
		{
			return NTS_SUCCESS;
		}  
	}	
	if (k == 10)
	{
		return NTS_POWER_EXTMAXPOWER_WARNING;  
	}
	return NTS_SUCCESS;
}
//class M_SPE_ACPRPowerDebugEx
M_SPE_ACPRPowerDebugEx::M_SPE_ACPRPowerDebugEx()
:BaseMethod()
{
	sprintf(m_MethodScript,"ACPR测试调整输出功率(refpower:目标功率值 maxpower:信号源电平上限值 IntervalTime:间隔时间)");
	m_SGDevName = CreateParamStruct();
	m_PSADevName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}
M_SPE_ACPRPowerDebugEx::~M_SPE_ACPRPowerDebugEx()
{
//	free(m_SGDevName);
//	free(m_PSADevName);
//	free(m_InputPara1);
//	free(m_InputPara2);
}
int M_SPE_ACPRPowerDebugEx::Init(void)
{
	sprintf(m_SGDevName->paramName, "SG_ConnectStr");
	m_SGDevName->paramType = SGDevice;
	m_SGDevName->paramCount = 1;
	sprintf(m_SGDevName->paramVal,"");
	sprintf(m_SGDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_SGDevName);
	
	sprintf(m_PSADevName->paramName, "PSA_ConnectStr");
	m_PSADevName->paramType = PSADevice;
	m_PSADevName->paramCount = 1;
	sprintf(m_PSADevName->paramVal,"");
	sprintf(m_PSADevName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADevName);

	sprintf(m_InputPara1->paramName, "refpower");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "maxpower");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "intervaltime");
	m_InputPara3->paramType = NTSUInt32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"500");
	sprintf(m_InputPara3->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara3);
	
	return NTS_SUCCESS;
}
int M_SPE_ACPRPowerDebugEx::Run(void)
{
	int retVal;
	double currentlevel,power,maxpower;
	double diffpower;
	double value[300];
	long count;
	unsigned long intervaltime;
	short int vSGHandle = 0,vPSAHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int k; 

	//信号源句柄
	sprintf(vDeviveName,m_SGDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vSGHandle = it->second.DevHandle;
	
	//频谱仪句柄
	sprintf(vDeviveName,m_PSADevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vPSAHandle = it->second.DevHandle;

	power = atof(m_InputPara1->paramVal);
	maxpower = atof(m_InputPara2->paramVal);
	intervaltime = atoi(m_InputPara3->paramVal);
	
	if(vPSAHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	if(vSGHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	retVal = PSA_GetMULACPR(vPSAHandle,value,&count);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	if((value[0]>=power-0.1)&&(value[0]<=(power+0.1))) 
	{
		return NTS_SUCCESS;
	}   
	else
	{
		retVal =SG_GetRFAmplitu(vSGHandle, &currentlevel);
		if(retVal==NTS_SUCCESS)
		{
			diffpower=value[0]-(power+0.05);  
			if((currentlevel-diffpower)>maxpower||(currentlevel-diffpower)<-110)      
			{
				return NTS_POWER_EXTMAXPOWER_WARNING;     
			}
			retVal =SG_SetRFAmplitu(vSGHandle,currentlevel-diffpower);
		}
		Sleep(intervaltime);
		for(k =0;k<3;k++)
		{ 
			retVal =PSA_GetMULACPR(vPSAHandle,value,&count);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
			retVal =SG_GetRFAmplitu(vSGHandle, &currentlevel);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
			if(value[0]>(power+0.1)) 
			{
				retVal =SG_SetRFAmplitu(vSGHandle, currentlevel-0.1);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				Sleep(intervaltime);    
   		     } 
			else if(value[0]<power)
			{
				retVal =SG_SetRFAmplitu(vSGHandle,currentlevel+0.1);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				Sleep(intervaltime); 
			}
			else
			{
				return NTS_SUCCESS;	
			}
		}
	}
	if(k == 3)
	{
		return NTS_POWER_EXTMAXPOWER_WARNING;     
	}
	return NTS_SUCCESS;
}
//class M_SPE_GetUpTimeSwitch
M_SPE_GetUpTimeSwitch::M_SPE_GetUpTimeSwitch()
:BaseMethod()
{
	sprintf(m_MethodScript,"获得上升沿时间和上升沿延迟时间量");
	m_SGDevName = CreateParamStruct();
	m_PSADevName = CreateParamStruct();

	m_InputPara1 =CreateParamStruct(); 
	m_InputPara2 =CreateParamStruct(); 
	m_InputPara3 =CreateParamStruct(); 
	
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	
	Init();
}
M_SPE_GetUpTimeSwitch::~M_SPE_GetUpTimeSwitch()
{
//	free(m_SGDevName);
//	free(m_PSADevName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);

//	free(m_OutputPara1);
//	free(m_OutputPara2);

}
int M_SPE_GetUpTimeSwitch::Init(void)
{
	sprintf(m_SGDevName->paramName, "SG_ConnectStr");
	m_SGDevName->paramType = SGDevice;
	m_SGDevName->paramCount = 1;
	sprintf(m_SGDevName->paramVal,"");
	sprintf(m_SGDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_SGDevName);
	
	sprintf(m_PSADevName->paramName, "PSA_ConnectStr");
	m_PSADevName->paramType = PSADevice;
	m_PSADevName->paramCount = 1;
	sprintf(m_PSADevName->paramVal,"");
	sprintf(m_PSADevName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADevName);

	sprintf(m_InputPara1->paramName, "trigDelaytime");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "LowLimitedofEdge");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0.1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "UpLimitedofEdge");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"0.9");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);

	sprintf(m_OutputPara1->paramName, "DelaytimeofUpEdge");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "ns");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	sprintf(m_OutputPara2->paramName, "timeofUpEdge");
	m_OutputPara2->paramType = NTSReal32;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , "ns");
	m_OutputParamVector.push_back(m_OutputPara2);

	return NTS_SUCCESS;
}
int M_SPE_GetUpTimeSwitch::Run(void)
{
	int retVal, i=0;
	double data[1024];
	double max=0,min=0,tempdata1,tempdata2;
	long count =0,upindex =0,downindex = 0;
	double trigdelaytime,currenttrigdaleytime,currentsweeptime,precision,difftrigtime;
	double tmpdiff1,tmpdiff2,orgdiff1,orgdiff2;
	double realdaleytime,realswitchtime;
	double lowrange,uprange;

	short int vSGHandle = 0,vPSAHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	//信号源句柄
	sprintf(vDeviveName,m_SGDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vSGHandle = it->second.DevHandle;
	
	//频谱仪句柄
	sprintf(vDeviveName,m_PSADevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vPSAHandle = it->second.DevHandle;

	lowrange =atof(m_InputPara2->paramVal); 
	uprange =atof(m_InputPara3->paramVal); 
	
	//上升沿
	trigdelaytime = atof(m_InputPara1->paramVal);
	retVal = PSA_SetTrigDelayTime(vPSAHandle,trigdelaytime);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_SetTraceAverage(vPSAHandle);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	Sleep(2000);
	retVal = PSA_GetTraceData(vPSAHandle,data,&count);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_GetSweepTime(vPSAHandle,&currentsweeptime);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_GetTrigDelayTime(vPSAHandle,&currenttrigdaleytime);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	difftrigtime = currenttrigdaleytime - trigdelaytime/1000; //实际触发延迟时间与理论触发延迟时间的差量
	precision =currentsweeptime/(count-1);		 //踪迹每点时间量
	max = data[0];
	min = data[0];

	for(i=1;i<count;i++)
	{
		if(data[i]>max) 
			max = data[i]; 
		if(data[i]<min) 
			min = data[i]; 
	}
	tempdata1=(max-min)*uprange+min;	//有效值范围高点
	tempdata2=(max-min)*lowrange+min;	//有效值范围低点
	
	//计算单前点与有效范围的绝对差量
	orgdiff1 =fabs(tempdata1-data[0]); 
	orgdiff2=fabs(tempdata2-data[0]); 
	upindex = 0;
	downindex = 0;
	for(i=1;i<count;i++)
	{
		tmpdiff1=fabs(tempdata1-data[i]); 
		tmpdiff2=fabs(tempdata2-data[i]); 
		if(tmpdiff1 < orgdiff1 )  
		{ 
			upindex = i;    
			orgdiff1 = tmpdiff1 ;    
		}
		if(tmpdiff2 < orgdiff2 )  
		{ 
			downindex = i;    
			orgdiff2 = tmpdiff2 ;   
		}
	}
	retVal = PSA_SetMarkTime(vPSAHandle, 1, fabs(downindex*precision*1000));
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}

	retVal = PSA_SetMarkTime(vPSAHandle, 2, fabs(upindex*precision*1000));
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	//单位:ns
	realswitchtime=fabs((upindex-downindex)*precision*1000000000);				//上升沿时间
	realdaleytime=(downindex*precision+difftrigtime)*1000000000+realswitchtime;		//上升沿延迟时间

	sprintf(m_OutputPara1->paramVal,"%e",realdaleytime);
	sprintf(m_OutputPara2->paramVal,"%e",realswitchtime);
		
	return NTS_SUCCESS;
}

//class M_SPE_GetDownTimeSwitch
M_SPE_GetDownTimeSwitch::M_SPE_GetDownTimeSwitch()
:BaseMethod()
{
	sprintf(m_MethodScript,"获得下降沿时间和下降沿延迟时间量");
	m_SGDevName = CreateParamStruct();
	m_PSADevName = CreateParamStruct();
	
	m_InputPara1 =CreateParamStruct(); 
	m_InputPara2 =CreateParamStruct(); 
	m_InputPara3 =CreateParamStruct(); 
	
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	
	Init();
}
M_SPE_GetDownTimeSwitch::~M_SPE_GetDownTimeSwitch()
{
//	free(m_SGDevName);
//	free(m_PSADevName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
	
//	free(m_OutputPara1);
//	free(m_OutputPara2);
	
}
int M_SPE_GetDownTimeSwitch::Init(void)
{
	sprintf(m_SGDevName->paramName, "SG_ConnectStr");
	m_SGDevName->paramType = SGDevice;
	m_SGDevName->paramCount = 1;
	sprintf(m_SGDevName->paramVal,"");
	sprintf(m_SGDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_SGDevName);
	
	sprintf(m_PSADevName->paramName, "PSA_ConnectStr");
	m_PSADevName->paramType = PSADevice;
	m_PSADevName->paramCount = 1;
	sprintf(m_PSADevName->paramVal,"");
	sprintf(m_PSADevName->paramUnit , " ");
	m_InputParamVector.push_back(m_PSADevName);

	sprintf(m_InputPara1->paramName, "trigDelaytime");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "LowLimitedofEdge");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0.1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "UpLimitedofEdge");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"0.9");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);

	sprintf(m_OutputPara1->paramName, "DelaytimeofDownEdge");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "ns");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	sprintf(m_OutputPara2->paramName, "timeofDownEdge");
	m_OutputPara2->paramType = NTSReal32;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , "ns");
	m_OutputParamVector.push_back(m_OutputPara2);
	return NTS_SUCCESS;
}
int M_SPE_GetDownTimeSwitch::Run(void)
{
	int retVal, i=0;
	double data[1024];
	double max=0,min=0,tempdata1,tempdata2;
	long count =0,upindex =0,downindex = 0;
	double trigdelaytime,currenttrigdaleytime,currentsweeptime,precision,difftrigtime;
	double tmpdiff1,tmpdiff2,orgdiff1,orgdiff2;
	double realdaleytime,realswitchtime;
	double lowrange,uprange;

	short int vSGHandle = 0,vPSAHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	//信号源句柄
	sprintf(vDeviveName,m_SGDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vSGHandle = it->second.DevHandle;
	
	//频谱仪句柄
	sprintf(vDeviveName,m_PSADevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vPSAHandle = it->second.DevHandle;

	if(vPSAHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	lowrange =atof(m_InputPara2->paramVal); 
	uprange =atof(m_InputPara3->paramVal); 
	//下降沿
	trigdelaytime = atof(m_InputPara1->paramVal);
	retVal = PSA_SetTrigDelayTime(vPSAHandle,trigdelaytime);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_SetTraceAverage(vPSAHandle);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	Sleep(2000);
	retVal = PSA_GetTraceData(vPSAHandle,data,&count);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_GetSweepTime(vPSAHandle,&currentsweeptime);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	retVal = PSA_GetTrigDelayTime(vPSAHandle,&currenttrigdaleytime);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	difftrigtime = currenttrigdaleytime - trigdelaytime/1000; //实际触发延迟时间与理论触发延迟时间的差量
	precision =currentsweeptime/(count-1);		 //踪迹每点时间量
	max = data[0];
	min = data[0];
	
	for(i=1;i<count;i++)
	{
		if(data[i]>max) 
			max = data[i]; 
		if(data[i]<min) 
			min = data[i]; 
	}
	tempdata1=(max-min)*uprange+min;	//有效值范围高点
	tempdata2=(max-min)*lowrange+min;	//有效值范围低点
	
	//计算单前点与有效范围的绝对差量
	orgdiff1 =fabs(tempdata1-data[0]); 
	orgdiff2=fabs(tempdata2-data[0]); 
	for(i=1;i<count;i++)
	{
		tmpdiff1=fabs(tempdata1-data[i]); 
		tmpdiff2=fabs(tempdata2-data[i]); 
		
		if(tmpdiff1 < orgdiff1 )  
		{ 
			upindex = i;    
			orgdiff1 = tmpdiff1 ;    
		}
		if(tmpdiff2 < orgdiff2 )  
		{ 
			downindex = i;    
			orgdiff2 = tmpdiff2 ;   
		}
	}
	retVal = PSA_SetMarkTime(vPSAHandle, 1, fabs(downindex*precision*1000));
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	
	retVal = PSA_SetMarkTime(vPSAHandle, 2, fabs(upindex*precision*1000));
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	//单位:ns
	realswitchtime=fabs((upindex-downindex)*precision*1000000000);		//下降沿时间
	realdaleytime=((upindex)*precision+difftrigtime)*1000000000+realswitchtime;		//下降沿延迟时间
	sprintf(m_OutputPara1->paramVal,"%e",realdaleytime);
	sprintf(m_OutputPara2->paramVal,"%e",realswitchtime);

	return NTS_SUCCESS;
}

//class M_SPE_ShowPromptDialog
M_SPE_ShowPromptDialog::M_SPE_ShowPromptDialog()
:BaseMethod()
{
	sprintf(m_MethodScript, "输入对话框");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	if (hwndDLG != 0)
	{
		EndDialog(hwndDLG, TRUE);
		DestroyWindow(hwndDLG);
		PostQuitMessage(0);
		hwndDLG = NULL;
		IsOK = FALSE;
	}
	Init();
}

M_SPE_ShowPromptDialog::~M_SPE_ShowPromptDialog()
{
	
	if (hwndDLG != 0)
	{
		EndDialog(hwndDLG, TRUE);
		DestroyWindow(hwndDLG);
		PostQuitMessage(0);
		hwndDLG = NULL;
		IsOK = FALSE;
	}
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
//	free(m_OutputPara);
}

int M_SPE_ShowPromptDialog::Init(void)
{
	sprintf(m_InputPara1->paramName, "title");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"输入：");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "Lowlimited");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "Uplimited");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"999999");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);

	sprintf(m_OutputPara->paramName, "outputvalue");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}

int M_SPE_ShowPromptDialog::Run(void)
{

	MSG msg;
	double tempVal;
	HFONT hFont;
	float low,up;
	HANDLE hModule;
	
	hModule = GetModuleHandle(NULL);

	IsOK = FALSE;
	low = atof(m_InputPara2->paramVal);
	up = atof(m_InputPara3->paramVal);
	
	if (hwndDLG == 0)
	{
		hwndDLG = CreateDialog((HINSTANCE)hModule, MAKEINTRESOURCE(IDD_DLG_SHOW), 
						NULL, (DLGPROC)DlgProc);

		ShowWindow(hwndDLG, SW_SHOW);		
		SetDlgItemText(hwndDLG, IDC_EDIT2, m_InputPara1->paramVal);
		SetFocus(GetDlgItem(hwndDLG, IDC_EDIT1));
		hFont = CreateFont(-14,0,0,0,FW_EXTRABOLD,0,0,0,GB2312_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH | FF_DONTCARE,"宋体"); 
		SendMessage(GetDlgItem(hwndDLG, IDC_EDIT2), WM_SETFONT, (WPARAM)hFont,0); 
		UpdateWindow(hwndDLG);
		
		while (GetMessage (&msg, NULL, 0, 0))
		{			
			if (IsOK)
			{
				GetDlgItemText (hwndDLG, IDC_EDIT1, szString, DLGTEXT_MAXLENGTH);
				
				if (strcmp(szString, "0") != 0)
				{
					if (atof(szString) ==0||atof(szString)<low||atof(szString)>up)
					{
						IsOK = FALSE;
						MessageBox (NULL, TEXT ("输入参数超出范围,请重新输入"),
									TEXT ("输入信息"), MB_ICONERROR);
						SetDlgItemText(hwndDLG, IDC_EDIT1, "");
						SetFocus(GetDlgItem(hwndDLG, IDC_EDIT1));
						continue;
					}
				}
				tempVal = atof(szString);
				sprintf(m_OutputPara->paramVal, "%e", tempVal);
				EndDialog(hwndDLG, TRUE);
				DestroyWindow(hwndDLG);
				hwndDLG = NULL;
				IsOK = FALSE;
				return NTS_SUCCESS;
			}

			
			TranslateMessage (&msg) ;
			DispatchMessage (&msg) ;
			
			
			Sleep(1);
		}
	}
	
	
	return NTS_SUCCESS;
}

//class M_SPE_SetLastDAOffset
M_SPE_SetLastDAOffset::M_SPE_SetLastDAOffset()
:BaseMethod()
{
	sprintf(m_MethodScript,"设置起止温度范围内的末级DA的偏移量");
	m_NTSDevName = CreateParamStruct();
	m_InputPara1 =CreateParamStruct(); 
	m_InputPara2 =CreateParamStruct(); 
	m_InputPara3 =CreateParamStruct(); 
	m_InputPara4 =CreateParamStruct();
	
	for(int i=0;i<1024;i++)
	{
		m_OutputPara[i] = CreateParamStruct();

		m_OutputPara[i]->paramName, "Value";
		m_OutputPara[i]->paramType = NTSUInt16;
		m_OutputPara[i]->paramCount = 1;
		sprintf(m_OutputPara[i]->paramVal,"");
		m_OutputPara[i]->paramUnit , "";
	
	}
	
	Init();
}
M_SPE_SetLastDAOffset::~M_SPE_SetLastDAOffset()
{
/*	free(m_NTSDevName);

	free(m_InputPara1);
	free(m_InputPara2);
	free(m_InputPara3);
	free(m_InputPara4);	
	for(int i=0;i<1024;i++)
	{
		free(m_OutputPara[i]);
	}*/
		
}
int M_SPE_SetLastDAOffset::Init(void)
{
	//芯通产品
	sprintf(m_NTSDevName->paramName, "NTS_ConnectStr");
	m_NTSDevName->paramType = NTSDevice;
	m_NTSDevName->paramCount = 1;
	sprintf(m_NTSDevName->paramVal,"");
	sprintf(m_NTSDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_NTSDevName);
	
	sprintf(m_InputPara1->paramName, "chindex");
	m_InputPara1->paramType = NTSInt8;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit , " ");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "StartTMP");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"-40");
	sprintf(m_InputPara2->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "StopTMP");
	m_InputPara3->paramType = NTSInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"87");
	sprintf(m_InputPara3->paramUnit , "℃");
	m_InputParamVector.push_back(m_InputPara3);
	
	sprintf(m_InputPara4->paramName, "Offset");
	m_InputPara4->paramType = NTSInt16;
	m_InputPara4->paramCount = 1;
	sprintf(m_InputPara4->paramVal,"0");
	sprintf(m_InputPara4->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara4);
	
	return NTS_SUCCESS;
}
int M_SPE_SetLastDAOffset::Run(void)
{
	int retVal, i=0;
	short ch;
	int offset = 0 ;
	unsigned short DAvalue;
	float startTMP,stopTMP,currentTMP;
	short int vNTSHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	
	//芯通产品句柄
	sprintf(vDeviveName,m_NTSDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vNTSHandle = it->second.DevHandle;
	
	ch = atoi(m_InputPara1->paramVal);
	startTMP = atof(m_InputPara2->paramVal);
	stopTMP = atof(m_InputPara3->paramVal);
	offset = atoi(m_InputPara4->paramVal);
	if(startTMP>stopTMP)
	{
		return NTS_INVALID_PARA;
	}
	for(i=0,currentTMP =startTMP;currentTMP<=stopTMP;i++,currentTMP++)
	{
		retVal = NTS_GetLastOutputVol(vNTSHandle,ch,currentTMP,&DAvalue);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}
		DAvalue = DAvalue+offset;
		retVal = NTS_SetLastOutputVol(vNTSHandle,ch,currentTMP,DAvalue);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}
		/*
		retVal = NTS_GetLastOutputVol(vNTSHandle,ch,currentTMP,&DAvalue);
				if(retVal!=NTS_SUCCESS)
				{
					return retVal;
				}
				sprintf(m_OutputPara[i]->paramVal,"%d",DAvalue);
				m_OutputParamVector.push_back(m_OutputPara[i]);
		*/
		
	}
	return retVal;
}

/*
//class M_SPE_SetAutoACPR
M_SPE_SetAutoACPR::M_SPE_SetAutoACPR()
:BaseMethod()
{
	sprintf(m_MethodScript,"ACPR自动调试");
	m_InputPara1 =CreateParamStruct(); 
	m_InputPara2 =CreateParamStruct(); 
//	m_InputPara3 = CreateParamStruct();
//	m_InputPara4 = CreateParamStruct();
	m_InputPara5 = CreateParamStruct();
	m_InputPara6 = CreateParamStruct();
	m_InputPara7 = CreateParamStruct();
	Init();
}
M_SPE_SetAutoACPR::~M_SPE_SetAutoACPR()
{
	free(m_InputPara1);
	free(m_InputPara2);	
//	free(m_InputPara3);
//	free(m_InputPara4);
	free(m_InputPara5);
	free(m_InputPara6);
	free(m_InputPara7);
}
int M_SPE_SetAutoACPR::Init(void)
{
	m_InputPara1->paramName, "ProductName";
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal," ");
	m_InputPara1->paramUnit , " ";
	m_InputParamVector.push_back(m_InputPara1);

	m_InputPara2->paramName, "MMTPortNo";
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	m_InputPara2->paramUnit , " ";
	m_InputParamVector.push_back(m_InputPara2);

/ *
	m_InputPara3->paramName, "DriverCurrent";
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"0");
	m_InputPara3->paramUnit , "A";
	m_InputParamVector.push_back(m_InputPara3);
* /

/ *
	m_InputPara4->paramName, "FinalCurrent";
	m_InputPara4->paramType = NTSReal32;
	m_InputPara4->paramCount = 1;
	sprintf(m_InputPara4->paramVal,"0");
	m_InputPara4->paramUnit , "A";
	m_InputParamVector.push_back(m_InputPara4);
* /

	m_InputPara5->paramName, "RefPower";
	m_InputPara5->paramType = NTSReal32;
	m_InputPara5->paramCount = 1;
	sprintf(m_InputPara5->paramVal,"3");
	m_InputPara5->paramUnit , "dBm";
	m_InputParamVector.push_back(m_InputPara5);
	
	m_InputPara6->paramName, "SGMaxPower";
	m_InputPara6->paramType = NTSReal32;
	m_InputPara6->paramCount = 1;
	sprintf(m_InputPara6->paramVal,"0");
	m_InputPara6->paramUnit , "dBm";
	m_InputParamVector.push_back(m_InputPara6);

	m_InputPara7->paramName, "Intervaltime";
	m_InputPara7->paramType = NTSInt8;
	m_InputPara7->paramCount = 1;
	sprintf(m_InputPara7->paramVal,"1000");
	m_InputPara7->paramUnit , "ms";
	m_InputParamVector.push_back(m_InputPara7);

	return NTS_SUCCESS;
}
int M_SPE_SetAutoACPR::Run(void)
{
	int retVal;
	float drivercurrent,finalcurrent;
	short mmtport;
	char productname[50],str[50];
	float refpower,maxpower;
	int delaytime;

	
	typedef   short int   (_stdcall *deb_SetAutoACPR)(short int,short int,
		short int,	
		short int,	
		float ,	
		float ,
		int );
	deb_SetAutoACPR DEB_SetAutoACPR = NULL;

	sprintf(productname,m_InputPara1->paramVal);

	mmtport = atoi(m_InputPara2->paramVal);
		
	refpower  = atof(m_InputPara5->paramVal);
	maxpower  = atof(m_InputPara6->paramVal);
	delaytime  = atoi(m_InputPara7->paramVal);
	if(strlen(productname)<=0)
	{
		return NTS_INVALID_PARA;
	}
	sprintf(str,"%s%s",productname,"AD.dll");
	HINSTANCE hInst = LoadLibrary(str);
	if(hInst)
	{
		DEB_SetAutoACPR = (deb_SetAutoACPR)GetProcAddress(hInst, "_DEB_SetAutoACPR@28");
	}
	else
	{
		return NTS_LOADDLL_ERROR;
	}
		
	retVal = DEB_SetAutoACPR(
		m_deviceHandle[NTSDevice],
		mmtport,
		vSGHandle,
		vPSAHandle,
		refpower,
		maxpower,
		delaytime);
	if(hInst)
	{
		FreeLibrary(hInst);
		hInst = NULL;
	}
	return retVal;


	
}
*/

//class M_SPE_Power 
M_SPE_Power::M_SPE_Power()
:BaseMethod()
{
	sprintf(m_MethodScript,"某个数的多少次方");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_SPE_Power::~M_SPE_Power()
{
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara);
}
int M_SPE_Power::Init(void)
{
	sprintf(m_InputPara1->paramName, "data");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "Exp");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"1");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara->paramName, "result");
	m_OutputPara->paramType = NTSReal32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara);
	return NTS_SUCCESS;
}
int M_SPE_Power::Run(void)
{
	float data,exp,result;
	
	data = atof(m_InputPara1->paramVal);
	exp = atof(m_InputPara2->paramVal);	
	result = pow(data,exp);	
	sprintf(m_OutputPara->paramVal,"%e",result);
	return NTS_SUCCESS;
}

//class M_SPE_DevReset
M_SPE_DevReset::M_SPE_DevReset()
:BaseMethod()
{
	sprintf(m_MethodScript, "仪器复位");
	m_DevType = CreateParamStruct();
	m_DevName = CreateParamStruct();
	Init();
}
M_SPE_DevReset::~M_SPE_DevReset()
{
//	free(m_DevType);
//	free(m_DevName);
		
}

int M_SPE_DevReset::Init(void)
{
	sprintf(m_DevType->paramName, "DevType");
	m_DevType->paramType = NTSInt8;
	m_DevType->paramCount = 1;
	sprintf(m_DevType->paramVal,"");
	sprintf(m_DevType->paramUnit , "");
	m_InputParamVector.push_back(m_DevType);

	sprintf(m_DevName->paramName, "ConnectStr");
	m_DevName->paramType = NTSString;
	m_DevName->paramCount = 1;
	sprintf(m_DevName->paramVal,"");
	sprintf(m_DevName->paramUnit , "");
	m_InputParamVector.push_back(m_DevName);

	return NTS_SUCCESS;
}
int M_SPE_DevReset::Run(void)
{
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int devType;
	int retVal;
	
	devType = atoi(m_DevType->paramVal);
	if (devType < 101) 
	{
		return NTS_INVALID_PARA;
	}
	sprintf(vDeviveName,m_DevName->paramVal);	
	if (strlen(vDeviveName) <5) 
	{
		return NTS_INVALID_PARA;
	}
	
	switch(devType) {
	case NTS:				//芯通产品	
		retVal = NTS_SUCCESS;
		break;
	case SG:				//信号源
		it = gDeviceManagerMap.find(vDeviveName);
		if(it == gDeviceManagerMap.end())
		{
			return NTS_INVALID_DEVICE;
		}	
		vHandle = it->second.DevHandle;
	
		retVal = SG_Reset(vHandle);	
		break;
	case PSA:				//频谱仪
		it = gDeviceManagerMap.find(vDeviveName);
		if(it == gDeviceManagerMap.end())
		{
			return NTS_INVALID_DEVICE;
		}
		vHandle = it->second.DevHandle;
		
		retVal = PSA_SetPreset(vHandle);
		break;
	case ENA:				//网络仪
		it = gDeviceManagerMap.find(vDeviveName);
		if(it == gDeviceManagerMap.end())
		{
			return NTS_INVALID_DEVICE;
		}
		vHandle = it->second.DevHandle;
	
		retVal = ENA_Reset(vHandle);
		break;
	case NFA:				//噪声仪
		it = gDeviceManagerMap.find(vDeviveName);
		if(it == gDeviceManagerMap.end())
		{
			return NTS_INVALID_DEVICE;
		}
		vHandle = it->second.DevHandle;
		
		retVal = NTS_SUCCESS;		
		break;
	case MMT:				//万用表
		retVal = NTS_SUCCESS;
		break;
	case SWI:				//矩阵开关
		retVal = NTS_SUCCESS;
		break;
	case DPD:				//DPD
		it = gDeviceManagerMap.find(vDeviveName);
		if(it == gDeviceManagerMap.end())
		{
			return NTS_INVALID_DEVICE;
		}
		vHandle = it->second.DevHandle;
			
		retVal = DPD_Reset(vHandle);
		return retVal;
		break;
	case PRM:				//功率计
		retVal = NTS_SUCCESS;
		break;
	}

	return retVal;	
}

//M_SPE_PRMPowerDebug
M_SPE_PRMPowerDebug::M_SPE_PRMPowerDebug()
:BaseMethod()
{
	sprintf(m_MethodScript,"功率计下功率调试(refpower:目标功率值 maxpower:信号源电平上限值 IntervalTime:间隔时间)");
	m_SGDevName = CreateParamStruct();
	m_PRMDevName = CreateParamStruct();

	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}
M_SPE_PRMPowerDebug::~M_SPE_PRMPowerDebug()
{
//	free(m_SGDevName);
//	free(m_PRMDevName);

//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}
int M_SPE_PRMPowerDebug::Init(void)
{
	sprintf(m_SGDevName->paramName, "SG_ConnectStr");
	m_SGDevName->paramType = SGDevice;
	m_SGDevName->paramCount = 1;
	sprintf(m_SGDevName->paramVal,"");
	sprintf(m_SGDevName->paramUnit , " ");
	m_InputParamVector.push_back(m_SGDevName);
	
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

	sprintf(m_InputPara2->paramName, "maxpower");
	m_InputPara2->paramType = NTSReal32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "dBm");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "intervaltime");
	m_InputPara3->paramType = NTSUInt32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"500");
	sprintf(m_InputPara3->paramUnit , "ms");
	m_InputParamVector.push_back(m_InputPara3);

	return NTS_SUCCESS;
}

int M_SPE_PRMPowerDebug::Run(void)
{
	int retVal;
	double currentlevel,power,maxpower;
	double diffpower;
	float value, SWR;
	int intervaltime;
	short int vSGHandle = 0,vPRMHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];
	int k;
	
	//信号源句柄
	sprintf(vDeviveName, m_SGDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vSGHandle = it->second.DevHandle;
	
	//频谱仪句柄
	sprintf(vDeviveName, m_PRMDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vPRMHandle = it->second.DevHandle;
	
	power = atof(m_InputPara1->paramVal);
	maxpower = atof(m_InputPara2->paramVal);
	intervaltime = atoi(m_InputPara3->paramVal);
	
	if(vPRMHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}
	if(vSGHandle < 0)
	{
		assert(0);
		return NTS_INVALID_DEVICE;
	}	
	Sleep(intervaltime); 
	retVal = PRM_GetPower(vPRMHandle, &value, &SWR);
	if(retVal!=NTS_SUCCESS)
	{
		return retVal;
	}
	if((value >= power-0.02)&&(value<=(power+0.02))) 
	{
		return NTS_SUCCESS;
	}  	
	else
	{
		retVal =SG_GetRFAmplitu(vSGHandle,&currentlevel);
		if(retVal==NTS_SUCCESS)
		{
			diffpower = value - power;  
			if((currentlevel-diffpower)>maxpower||(currentlevel-diffpower)<-110)      
			{
				return NTS_POWER_EXTMAXPOWER_WARNING;     
			}
			retVal = SG_SetRFAmplitu(vSGHandle,currentlevel-diffpower);
		}
		Sleep(intervaltime);     
		retVal = PRM_GetPower(vPRMHandle,&value, &SWR);
		if(retVal!=NTS_SUCCESS)
		{
			return retVal;
		}		
		for(k =1;k<10;k++)
		{ 	
			if((value >= power-0.02)&&(value<=(power+0.02))) 
			{
				return NTS_SUCCESS;
			} 
			retVal =SG_GetRFAmplitu(vSGHandle,&currentlevel);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}	
			diffpower = value - power;  
			if((currentlevel-diffpower)>maxpower||(currentlevel-diffpower)<-110)      
			{
				return NTS_POWER_EXTMAXPOWER_WARNING;     
			}
			retVal = SG_SetRFAmplitu(vSGHandle,currentlevel-diffpower);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}
			Sleep(intervaltime);     
			retVal = PRM_GetPower(vPRMHandle,&value, &SWR);
			if(retVal!=NTS_SUCCESS)
			{
				return retVal;
			}		
		}
		
	}
	if(k == 10)
	{
		return NTS_POWER_EXTMAXPOWER_WARNING;     
	}
	return NTS_SUCCESS;
}

//M_SPE_SeparateData 
M_SPE_SeparateData::M_SPE_SeparateData()
:BaseMethod()
{
	sprintf(m_MethodScript,"按照特定字符分离字符串，并获取指定位置的数据");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();

	m_OutputPara1 = CreateParamStruct();
	Init();
}
M_SPE_SeparateData::~M_SPE_SeparateData()
{
//	free(m_OutputPara1);
	
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}
int M_SPE_SeparateData::Init(void)
{

	sprintf(m_InputPara1->paramName, "SourceStr");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "TargetStr");
	m_InputPara2->paramType = NTSString;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal, ",");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "Index");
	m_InputPara3->paramType = NTSInt16;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"1");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);

	sprintf(m_OutputPara1->paramName, "Value");
	m_OutputPara1->paramType = NTSReal64;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}

int M_SPE_SeparateData::Run(void)
{
	char *SourceStr, *SubStr;
	char TargetStr[100] = {0};
	int TotalLength, Index, Offset, Count;
	int i;
	double tempvalue[10000] = {0};

	if (m_InputPara1->LparamVal != NULL)
	{
		TotalLength = strlen(m_InputPara1->LparamVal) + 10;
		SourceStr = (char *)malloc(TotalLength*sizeof(char));
		SubStr = (char *)malloc(TotalLength*sizeof(char));
		sprintf(SourceStr, m_InputPara1->LparamVal);			//标准输入字符串 以','分隔数据
	}
	else
	{
		TotalLength = strlen(m_InputPara1->paramVal) + 10;
		SourceStr = (char *)malloc(TotalLength*sizeof(char));
		SubStr = (char *)malloc(TotalLength*sizeof(char));
		sprintf(SourceStr, m_InputPara1->paramVal);			//标准输入字符串 以','分隔数据
	}
	
	sprintf(TargetStr, "%s", m_InputPara2->paramVal);
	Index = atoi(m_InputPara3->paramVal);	
	TotalLength = strlen(SourceStr);
	Offset = strlen(TargetStr);
	if (TotalLength <=0)
	{
		sprintf(m_OutputPara1->paramVal, "%e", 0.0);
		return NTS_SUCCESS;
	}
	//分离字符串
	tempvalue[0] = atof(&SourceStr[0]);
	Count = 1;
	for(i = 0; i < TotalLength; i++)
	{
		if(SourceStr[i] == TargetStr[0])
		{
			tempvalue[Count] = atof(&SourceStr[i+1]);
			Count++;	
		} 
	}
	if(Index > Count)
	{
		Index = Count;
	}
	if (Index <1)
	{
		Index = 1;
	}
	sprintf(m_OutputPara1->paramVal, "%e", tempvalue[Index -1]);
	return NTS_SUCCESS;
	
}


//M_SPE_IntToString 
M_SPE_IntToString::M_SPE_IntToString()
:BaseMethod()
{
	sprintf(m_MethodScript,"把整型数据转化成字符串");
	m_InputPara1 = CreateParamStruct();
	
	m_OutputPara1 = CreateParamStruct();
	Init();
}
M_SPE_IntToString::~M_SPE_IntToString()
{
//	free(m_InputPara1);
//	free(m_OutputPara1);
}
int M_SPE_IntToString::Init(void)
{
	
	sprintf(m_InputPara1->paramName, "IntData");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_OutputPara1->paramName, "Str");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}

int M_SPE_IntToString::Run(void)
{
	int InData;	
	
	InData = atoi(m_InputPara1->paramVal);			
	//把整型数据转化成字符串
	sprintf(m_OutputPara1->paramVal, "%d", InData);
	return NTS_SUCCESS;	
}

//M_SPE_FloatToString 
M_SPE_FloatToString::M_SPE_FloatToString()
:BaseMethod()
{
	sprintf(m_MethodScript,"把浮点型数据转化成字符串");
	m_InputPara1 = CreateParamStruct();
	
	m_OutputPara1 = CreateParamStruct();
	Init();
}
M_SPE_FloatToString::~M_SPE_FloatToString()
{
//	free(m_InputPara1);
//	free(m_OutputPara1);
//
}
int M_SPE_FloatToString::Init(void)
{
	
	sprintf(m_InputPara1->paramName, "FloatData");
	m_InputPara1->paramType = NTSReal32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_OutputPara1->paramName, "Str");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);	
	return NTS_SUCCESS;
}

int M_SPE_FloatToString::Run(void)
{
	float InData;	
	
	InData = atof(m_InputPara1->paramVal);			
	//把浮点型数据转化成字符串
	sprintf(m_OutputPara1->paramVal, "%e", InData);
	return NTS_SUCCESS;	
	
}

//M_SPE_GetConditionData 
M_SPE_GetConditionData::M_SPE_GetConditionData()
:BaseMethod()
{
	sprintf(m_MethodScript,"获取指定范围内的数据(SourceStr:标准输入字符串,以','分隔数据  SearchColIndex:数据搜索位置 0 一维数据 n:二维数据第n维数据)");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	m_InputPara4 = CreateParamStruct();

	m_OutputPara1 = CreateParamStruct();
	Init();
}
M_SPE_GetConditionData::~M_SPE_GetConditionData()
{
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
//	free(m_InputPara4);

//	free(m_OutputPara1);
	
}
int M_SPE_GetConditionData::Init(void)
{	
	sprintf(m_InputPara1->paramName, "SourceStr");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "SearchColIndex");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	sprintf(m_InputPara3->paramName, "DownLimieted");
	m_InputPara3->paramType = NTSReal32;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal,"");
	sprintf(m_InputPara3->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara3);

	sprintf(m_InputPara4->paramName, "UpLimieted");
	m_InputPara4->paramType = NTSReal32;
	m_InputPara4->paramCount = 1;
	sprintf(m_InputPara4->paramVal,"");
	sprintf(m_InputPara4->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara4);
	
	sprintf(m_OutputPara1->paramName, "Str");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara1);	
	return NTS_SUCCESS;
}

int M_SPE_GetConditionData::Run(void)
{
	double Down, Up;	
	int i, NewCount, ColIndex, Count, TotalLength;
	char *SourceStr, *SubStr;
	double TmpData[10000] = {0};
	double NewData[10000] = {0};
	int N = 2;					//二维数据


	if (m_InputPara1->LparamVal != NULL)
	{
		TotalLength = strlen(m_InputPara1->LparamVal) + 10;
		SourceStr = (char *)malloc(TotalLength*sizeof(char));
		SubStr = (char *)malloc(TotalLength*sizeof(char));
		sprintf(SourceStr, m_InputPara1->LparamVal);			//标准输入字符串 以','分隔数据
	}
	else
	{
		TotalLength = strlen(m_InputPara1->paramVal) + 10;
		SourceStr = (char *)malloc(TotalLength*sizeof(char));
		SubStr = (char *)malloc(TotalLength*sizeof(char));
		sprintf(SourceStr, m_InputPara1->paramVal);			//标准输入字符串 以','分隔数据
	}
	
	ColIndex = atoi(m_InputPara2->paramVal);			//字符串维度 0:一维数组 n:多维数组第n维
	if(strlen(m_InputPara3->paramVal) == 0)				
	{
		//无下限,则下限为负无穷
		Down = NegInf;
	}
	else
	{	
		Down = atof(m_InputPara3->paramVal);				//条件下限
	}
	if(strlen(m_InputPara4->paramVal) == 0)				
	{
		//无上限,则上限为正无穷
		Up = PosInf;
	}
	else
	{	
		Up = atof(m_InputPara4->paramVal);					//条件上限
	}
	
	//分离字符串
	TotalLength = strlen(SourceStr);
	TmpData[0] = atof(&SourceStr[0]);
	Count = 1;
	for(i = 0; i < TotalLength; i++)
	{
		if(SourceStr[i] == ',')
		{
			TmpData[Count] = atof(&SourceStr[i+1]);
			Count++;	
		} 
	}

	//过滤数据
	if (ColIndex == 0) 
	{
		for(NewCount = 0, i = 0; i< Count; i++)
		{
			if (TmpData[i] >= Down && TmpData[i] <= Up)
			{
				NewData[NewCount] = TmpData[i];
				//格式化成标准字符串
				if (NewCount == 0)
				{
					sprintf(SubStr, "%e", NewData[NewCount]);
				}
				else
				{
					sprintf(SubStr, "%s ,%e", SubStr, NewData[NewCount]);
				}				
				NewCount++;
			}
		}
	}
	else
	{
		switch(ColIndex)
		{
		case 1:							//以第一列数据为基础，过滤数据
			for(NewCount = 0, i = 0; i< Count; i = i + 2)
			{
				if ((i%2 == 0) && (TmpData[i] >= Down) && (TmpData[i] <= Up))
				{					
					//格式化成标准字符串
					if (NewCount == 0)
					{
						sprintf(SubStr, "%e ,%e", TmpData[i], TmpData[i + 1]);
					}
					else
					{
						sprintf(SubStr, "%s ,%e ,%e", SubStr, TmpData[i], TmpData[i + 1]);
					}										
					NewCount++;				
				}
			}	
			break;
		case 2:							//以第二列数据为基础，过滤数据
			for(NewCount = 0, i = 1; i< Count; i = i + 2)
			{
				if ((i%2 == 1) && (TmpData[i] >= Down) && (TmpData[i] <= Up))
				{					
					//格式化成标准字符串
					if (NewCount == 0)
					{
						sprintf(SubStr, "%e ,%e", TmpData[i-1], TmpData[i]);
					}
					else
					{
						sprintf(SubStr, "%s ,%e ,%e", SubStr, TmpData[i-1], TmpData[i]);
					}										
					NewCount++;				
				}
			}	
			break;				
		}	
	}	
	if (strlen(SubStr) > PARALENGTH) 
	{
		m_OutputPara1->LparamVal = (char *)malloc((strlen(SubStr) +10)*sizeof(char));
		sprintf(m_OutputPara1->LparamVal, "%s", SubStr);
	}
	else
	{
		sprintf(m_OutputPara1->paramVal, "%s", SubStr);
	}
	return NTS_SUCCESS;	
	
}

//M_SPE_GetMaxPosition 
M_SPE_GetMaxPosition::M_SPE_GetMaxPosition()
:BaseMethod()
{
	sprintf(m_MethodScript,"获取Max值的位置(SourceStr:标准输入字符串,以','分隔数据  SearchColIndex:数据搜索位置 0 一维数据 n:二维数据第n维数据)");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	Init();
}
M_SPE_GetMaxPosition::~M_SPE_GetMaxPosition()
{
//	free(m_InputPara1);
//	free(m_InputPara2);

//	free(m_OutputPara1);
//	free(m_OutputPara2);
	
}
int M_SPE_GetMaxPosition::Init(void)
{
	
	sprintf(m_InputPara1->paramName, "SourceStr");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "SearchColIndex");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara1->paramName, "MaxValue");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara1);

	sprintf(m_OutputPara2->paramName, "MaxPosition");
	m_OutputPara2->paramType = NTSInt16;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara2);	
	return NTS_SUCCESS;
}

int M_SPE_GetMaxPosition::Run(void)
{
	
	int i, NewCount, ColIndex, Count, TotalLength;
	char *SourceStr, *SubStr;
	double TmpData[10000] = {0};
	double NewData[10000] = {0};
	double MaxValue, MinValue;
	int MaxNo = 1;
	
	
	if (m_InputPara1->LparamVal != NULL)
	{
		TotalLength = strlen(m_InputPara1->LparamVal) + 10;
		SourceStr = (char *)malloc(TotalLength*sizeof(char));
		SubStr = (char *)malloc(TotalLength*sizeof(char));
		sprintf(SourceStr, m_InputPara1->LparamVal);			//标准输入字符串 以','分隔数据
	}
	else
	{
		TotalLength = strlen(m_InputPara1->paramVal) + 10;
		SourceStr = (char *)malloc(TotalLength*sizeof(char));
		SubStr = (char *)malloc(TotalLength*sizeof(char));
		sprintf(SourceStr, m_InputPara1->paramVal);			//标准输入字符串 以','分隔数据
	}
	
	ColIndex = atoi(m_InputPara2->paramVal);			//字符串维度 0:一维数组 n:二维数组第n维
	
	if (ColIndex < 0||ColIndex>2 ) 
	{
		return NTS_INVALID_PARA;
	}
	
	//分离字符串
	TotalLength = strlen(SourceStr);
	TmpData[0] = atof(&SourceStr[0]);
	Count = 1;
	for(i = 0; i < TotalLength; i++)
	{
		if(SourceStr[i] == ',')
		{
			TmpData[Count] = atof(&SourceStr[i+1]);
			Count++;	
		} 
	}
	//取指定列的数据
	switch(ColIndex)
	{
	case 0:						//不作任何处理,数据从TmpData拷贝到NewCount中
		for(i = 0, NewCount = 0; i<Count; i++)
		{
			NewData[NewCount] = TmpData[i];
			NewCount++;			
		}
		break;
	case 1:						//从第一个数据开始起，间隔一个提取数据
		for(i = 0, NewCount = 0; i<Count; i++)
		{
			if (i%2 == 0)
			{
				NewData[NewCount] = TmpData[i];
				NewCount++;
			}
		}
		break;
	case 2:						//从第二个数据开始起，间隔一个提取数据
		for(i = 0, NewCount = 0; i<Count; i++)
		{
			if (i%2 == 1)
			{
				NewData[NewCount] = TmpData[i];
				NewCount++;
			}
		}
		break;		
	}

	MaxValue = NewData[0];
	MinValue = NewData[0];
	
	for(i = 1; i<NewCount; i++)
	{
		if (MaxValue < NewData[i])
		{
			MaxValue = NewData[i];
			MaxNo = i + 1;					//最大值位置
		}
	}
	sprintf(m_OutputPara1->paramVal, "%e", MaxValue);
	sprintf(m_OutputPara2->paramVal, "%d", MaxNo);
	return NTS_SUCCESS;	
	
}


//M_SPE_GetMinPosition 
M_SPE_GetMinPosition::M_SPE_GetMinPosition()
:BaseMethod()
{
	sprintf(m_MethodScript,"获取Min值的位置(SourceStr:标准输入字符串,以','分隔数据  SearchColIndex:数据搜索位置 0 一维数据 n:二维数据第n维数据)");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	Init();
}
M_SPE_GetMinPosition::~M_SPE_GetMinPosition()
{
//	free(m_InputPara1);
//	free(m_InputPara2);

//	free(m_OutputPara1);
//	free(m_OutputPara2);
	
}
int M_SPE_GetMinPosition::Init(void)
{
	
	sprintf(m_InputPara1->paramName, "SourceStr");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "SearchColIndex");
	m_InputPara2->paramType = NTSInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"0");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara1->paramName, "MinValue");
	m_OutputPara1->paramType = NTSReal32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara1);

	sprintf(m_OutputPara2->paramName, "MinPosition");
	m_OutputPara2->paramType = NTSInt16;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal,"");
	sprintf(m_OutputPara2->paramUnit , " ");
	m_OutputParamVector.push_back(m_OutputPara2);	
	return NTS_SUCCESS;
}

int M_SPE_GetMinPosition::Run(void)
{
	
	int i, NewCount, ColIndex, Count, TotalLength;
	char *SourceStr, *SubStr;
	double TmpData[10000] = {0};
	double NewData[10000] = {0};
	double MaxValue, MinValue;
	int MinNo = 1;
	
	
	if (m_InputPara1->LparamVal != NULL)
	{
		TotalLength = strlen(m_InputPara1->LparamVal) + 10;
		SourceStr = (char *)malloc(TotalLength*sizeof(char));
		SubStr = (char *)malloc(TotalLength*sizeof(char));
		sprintf(SourceStr, m_InputPara1->LparamVal);			//标准输入字符串 以','分隔数据
	}
	else
	{
		TotalLength = strlen(m_InputPara1->paramVal) + 10;
		SourceStr = (char *)malloc(TotalLength*sizeof(char));
		SubStr = (char *)malloc(TotalLength*sizeof(char));
		sprintf(SourceStr, m_InputPara1->paramVal);			//标准输入字符串 以','分隔数据
	}
	ColIndex = atoi(m_InputPara2->paramVal);			//字符串维度 0:一维数组 n:二维数组第n维
	
	if (ColIndex < 0||ColIndex>2 ) 
	{
		return NTS_INVALID_PARA;
	}
	
	//分离字符串
	TotalLength = strlen(SourceStr);
	TmpData[0] = atof(&SourceStr[0]);
	Count = 1;
	for(i = 0; i < TotalLength; i++)
	{
		if(SourceStr[i] == ',')
		{
			TmpData[Count] = atof(&SourceStr[i+1]);
			Count++;	
		} 
	}
	//取指定列的数据
	switch(ColIndex)
	{
	case 0:						//不作任何处理,数据从TmpData拷贝到NewCount中
		for(i = 0, NewCount = 0; i<Count; i++)
		{
			NewData[NewCount] = TmpData[i];
			NewCount++;			
		}
		break;
	case 1:						//从第一个数据开始起，间隔一个提取数据
		for(i = 0, NewCount = 0; i<Count; i++)
		{
			if (i%2 == 0)
			{
				NewData[NewCount] = TmpData[i];
				NewCount++;
			}
		}
		break;
	case 2:						//从第二个数据开始起，间隔一个提取数据
		for(i = 0, NewCount = 0; i<Count; i++)
		{
			if (i%2 == 1)
			{
				NewData[NewCount] = TmpData[i];
				NewCount++;
			}
		}
		break;		
	}

	MaxValue = NewData[0];
	MinValue = NewData[0];
	
	for(i = 1; i<NewCount; i++)
	{
		if (MinValue > NewData[i])
		{
			MinValue = NewData[i];
			MinNo = i + 1;					//最小值位置
		}
	}
	sprintf(m_OutputPara1->paramVal, "%d", MinNo);
	return NTS_SUCCESS;		
}

//M_SPE_StrCat 
M_SPE_StrCat::M_SPE_StrCat()
:BaseMethod()
{
	sprintf(m_MethodScript,"字符串连接");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();	
	m_OutputPara1 = CreateParamStruct();
	Init();
}
M_SPE_StrCat::~M_SPE_StrCat()
{
//	free(m_InputPara1);
//	free(m_InputPara2);

//	free(m_OutputPara1);
	
}
int M_SPE_StrCat::Init(void)
{
	
	sprintf(m_InputPara1->paramName, "%s", "SourceStr");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "%s", "SubStr");
	m_InputPara2->paramType = NTSString;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara1->paramName, "%s", "Str");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal, "");
	sprintf(m_OutputPara1->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara1);	
	return NTS_SUCCESS;
}

int M_SPE_StrCat::Run(void)
{		
	int vStrLength = 0;
	char *pTempStr;

	//判断输入参数1是否为大数据
	if (m_InputPara1->LparamVal != NULL)
	{
		vStrLength =  vStrLength + strlen(m_InputPara1->LparamVal) + 2;
	}
	else
	{
		vStrLength =  vStrLength + strlen(m_InputPara1->paramVal) + 2;
	}
	//判断输入参数2是否为大数据
	if (m_InputPara2->LparamVal != NULL)
	{
		vStrLength =  vStrLength + strlen(m_InputPara2->LparamVal) + 2;
	}
	else
	{
		vStrLength =  vStrLength + strlen(m_InputPara2->paramVal) + 2;
	}
	
	pTempStr = (char *)malloc(vStrLength * sizeof(char));
	sprintf(pTempStr, "%s", "");
	//判断输入参数是否为大数据
	if (m_InputPara1->LparamVal != NULL)
	{
		sprintf(pTempStr, "%s%s", pTempStr, m_InputPara1->LparamVal);
	}
	else
	{
		sprintf(pTempStr, "%s%s", pTempStr, m_InputPara1->paramVal);
	}
	//判断输入参数是否为大数据
	if (m_InputPara2->LparamVal != NULL)
	{
		sprintf(pTempStr, "%s%s", pTempStr, m_InputPara2->LparamVal);
	}
	else
	{
		sprintf(pTempStr, "%s%s", pTempStr, m_InputPara2->paramVal);
	}

	vStrLength = strlen(pTempStr) + 10;
	if ( vStrLength > PARALENGTH)
	{
		m_OutputPara1->LparamVal = (char *)malloc(vStrLength * sizeof(char));
		sprintf(m_OutputPara1->LparamVal, "%s", pTempStr);
	}
	else
	{
		sprintf(m_OutputPara1->paramVal, "%s", pTempStr);
	}
	free(pTempStr);
	return NTS_SUCCESS;		
}

//M_SPE_GainDebugOfFirst 
M_SPE_GainDebugWithENA::M_SPE_GainDebugWithENA()
:BaseMethod()
{
	sprintf(m_MethodScript,"在网络分析仪下改变功放DA值来调整产品的功放增益");
	m_NTSDevName = CreateParamStruct();
	m_ENADevName = CreateParamStruct();	
	m_ENATraceNo = CreateParamStruct();
	m_MaxMarkerNo = CreateParamStruct();
	m_MinMarkerNo = CreateParamStruct();
	m_LimitedDown = CreateParamStruct();
	m_LimitedUp = CreateParamStruct();
	m_LimitedDownOffset = CreateParamStruct();
	m_MemeryNo = CreateParamStruct();
	m_DAStartAddr = CreateParamStruct();
	m_DACount = CreateParamStruct();
	m_DAStep = CreateParamStruct();
	m_DelayTime = CreateParamStruct();
	m_DAUpLimited = CreateParamStruct();
	Init();
}
M_SPE_GainDebugWithENA::~M_SPE_GainDebugWithENA()
{
/*	free(m_NTSDevName);
	free(m_ENADevName);
	
	free(m_ENATraceNo);
	free(m_MaxMarkerNo);
	free(m_MinMarkerNo);
	free(m_LimitedDown);
	free(m_LimitedUp);
	free(m_LimitedDownOffset);
	free(m_MemeryNo);
	free(m_DAStartAddr);
	free(m_DACount);
	free(m_DAStep);
	free(m_DelayTime);
	free(m_DAUpLimited);*/

	
}
int M_SPE_GainDebugWithENA::Init(void)
{
	
	sprintf(m_NTSDevName->paramName, "%s", "ConnectStr");
	m_NTSDevName->paramType = NTSDevice;
	m_NTSDevName->paramCount = 1;
	sprintf(m_NTSDevName->paramVal,"");
	sprintf(m_NTSDevName->paramUnit, "");
	m_InputParamVector.push_back(m_NTSDevName);
	
	sprintf(m_ENADevName->paramName, "%s", "ConnectStr");
	m_ENADevName->paramType = ENADevice;
	m_ENADevName->paramCount = 1;
	sprintf(m_ENADevName->paramVal,"");
	sprintf(m_ENADevName->paramUnit, "");
	m_InputParamVector.push_back(m_ENADevName);
	
	//获取增益的曲线号
	sprintf(m_ENATraceNo->paramName, "%s", "TraceIndex");
	m_ENATraceNo->paramType = NTSInt16;
	m_ENATraceNo->paramCount = 1;
	sprintf(m_ENATraceNo->paramVal,"1");
	sprintf(m_ENATraceNo->paramUnit, "");
	m_InputParamVector.push_back(m_ENATraceNo);
	
	//获取增益最大的Marker号
	sprintf(m_MaxMarkerNo->paramName, "%s", "MaxMarkerNo");
	m_MaxMarkerNo->paramType = NTSInt16;
	m_MaxMarkerNo->paramCount = 1;
	sprintf(m_MaxMarkerNo->paramVal,"1");
	sprintf(m_MaxMarkerNo->paramUnit, "");
	m_InputParamVector.push_back(m_MaxMarkerNo);
	
	//获取增益最小的Marker号
	sprintf(m_MinMarkerNo->paramName, "%s", "MinMarkerNo");
	m_MinMarkerNo->paramType = NTSInt16;
	m_MinMarkerNo->paramCount = 1;
	sprintf(m_MinMarkerNo->paramVal,"1");
	sprintf(m_MinMarkerNo->paramUnit, "");
	m_InputParamVector.push_back(m_MinMarkerNo);

	//产品指标下限
	sprintf(m_LimitedDown->paramName, "%s", "LimitedDown");
	m_LimitedDown->paramType = NTSReal32;
	m_LimitedDown->paramCount = 1;
	sprintf(m_LimitedDown->paramVal,"");
	sprintf(m_LimitedDown->paramUnit, "");
	m_InputParamVector.push_back(m_LimitedDown);

	//产品指标上限
	sprintf(m_LimitedUp->paramName, "%s", "LimitedUp");
	m_LimitedUp->paramType = NTSReal32;
	m_LimitedUp->paramCount = 1;
	sprintf(m_LimitedUp->paramVal,"");
	sprintf(m_LimitedUp->paramUnit, "");
	m_InputParamVector.push_back(m_LimitedUp);

	//产品指标下限偏移量
	sprintf(m_LimitedDownOffset->paramName, "%s", "MaxGainOffsetVsLimitedDown");
	m_LimitedDownOffset->paramType = NTSReal32;
	m_LimitedDownOffset->paramCount = 1;
	sprintf(m_LimitedDownOffset->paramVal,"");
	sprintf(m_LimitedDownOffset->paramUnit, "");
	m_InputParamVector.push_back(m_LimitedDownOffset);
	
	//产品保存DA数据的内存序号
	sprintf(m_MemeryNo->paramName, "%s", "FlashBlockNo");
	m_MemeryNo->paramType = NTSInt16;
	m_MemeryNo->paramCount = 1;
	sprintf(m_MemeryNo->paramVal,"1");
	sprintf(m_MemeryNo->paramUnit, "");
	m_InputParamVector.push_back(m_MemeryNo);

	//产品保存DA数据的内存起始地址
	sprintf(m_DAStartAddr->paramName, "%s", "DAStartAddr");
	m_DAStartAddr->paramType = NTSInt16;
	m_DAStartAddr->paramCount = 1;
	sprintf(m_DAStartAddr->paramVal,"0");
	sprintf(m_DAStartAddr->paramUnit, "");
	m_InputParamVector.push_back(m_DAStartAddr);

	//需要修改产品DA数据的个数
	sprintf(m_DACount->paramName, "%s", "DACount");
	m_DACount->paramType = NTSInt16;
	m_DACount->paramCount = 1;
	sprintf(m_DACount->paramVal,"128");
	sprintf(m_DACount->paramUnit, "");
	m_InputParamVector.push_back(m_DACount);

	//修改DA数据步进值
	sprintf(m_DAStep->paramName, "%s", "DAStep");
	m_DAStep->paramType = NTSInt16;
	m_DAStep->paramCount = 1;
	sprintf(m_DAStep->paramVal,"");
	sprintf(m_DAStep->paramUnit, "");
	m_InputParamVector.push_back(m_DAStep);

	//时延参数
	sprintf(m_DelayTime->paramName, "%s", "DelayTime");
	m_DelayTime->paramType = NTSInt16;
	m_DelayTime->paramCount = 1;
	sprintf(m_DelayTime->paramVal,"500");
	sprintf(m_DelayTime->paramUnit, "ms");
	m_InputParamVector.push_back(m_DelayTime);
	
	// DA上限
	sprintf(m_DAUpLimited->paramName, "%s", "DAUpLimited");
	m_DAUpLimited->paramType = NTSInt16;
	m_DAUpLimited->paramCount = 1;
	sprintf(m_DAUpLimited->paramVal,"4095");
	sprintf(m_DAUpLimited->paramUnit, "");
	m_InputParamVector.push_back(m_DAUpLimited);
	return NTS_SUCCESS;
}

int M_SPE_GainDebugWithENA::Run(void)
{	
	int res;
	unsigned short TraceNo, MaxMarkerNo, MinMarkerNo;
	double MaxValue, MinValue;
	double LimitedDown, LimitedUp, MaxGainOffsetVsLimitedDown = 1;
	int FlashIndex = 1, DAStartAddr = 0, DAStep = 1, DelayTime, vDAUpLimited;
	long DACount = 1;
	int ReadDA[1024] = {0};
	int WriteDA[1024] = {0};
	int Forward = 0;
	int i = 0, j;

	short int vNTSHandle = 0, vENAHandle;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];

	//产品句柄
	sprintf(vDeviveName, m_NTSDevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vNTSHandle = it->second.DevHandle;
	if(vNTSHandle < 0)
	{	
		return NTS_INVALID_DEVICE;
	}	
	//网络仪句柄
	sprintf(vDeviveName, m_ENADevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vENAHandle = it->second.DevHandle;
	if(vENAHandle < 0)
	{		
		return NTS_INVALID_DEVICE;
	}
	//
	TraceNo = atoi(m_ENATraceNo->paramVal);
	MaxMarkerNo = atoi(m_MaxMarkerNo->paramVal);
	MinMarkerNo = atoi(m_MinMarkerNo->paramVal);
	LimitedDown = atof(m_LimitedDown->paramVal);
	LimitedUp = atof(m_LimitedUp->paramVal);
	DelayTime = atoi(m_DelayTime->paramVal);
	vDAUpLimited = atoi(m_DAUpLimited->paramVal);
	//判断输入参数参数是否为空，为空的话则按默认值调试
	if (strlen(m_LimitedDownOffset->paramVal) > 0)			
	{
		MaxGainOffsetVsLimitedDown = atof(m_LimitedDownOffset->paramVal);
	}
	//判断输入参数参数是否为空，为空的话则按默认值调试
	if (strlen(m_MemeryNo->paramVal) > 0)			
	{
		FlashIndex = atoi(m_MemeryNo->paramVal);
	}
	//判断输入参数参数是否为空，为空的话则按默认值调试
	if (strlen(m_DAStartAddr->paramVal) > 0)
	{
		DAStartAddr = atoi(m_DAStartAddr->paramVal);
	}
	//判断输入参数参数是否为空，为空的话则按默认值调试
	if (strlen(m_DACount->paramVal) > 0) 
	{
		DACount = atoi(m_DACount->paramVal);
	}
	//判断输入参数参数是否为空，为空的话则按默认值调试
	if (strlen(m_DAStep->paramVal) > 0) 
	{
		DAStep = atoi(m_DAStep->paramVal);
	}	
	//判断输入参数参数是否为空，为空的话则按默认值调试
	if (strlen(m_DAUpLimited->paramVal) > 0) 
	{
		vDAUpLimited = atoi(m_DAUpLimited->paramVal);
	}
	for(i = 0 ; i < 100; i++)
	{		
		res = ENA_GetMarkerMax(vENAHandle, TraceNo, MaxMarkerNo, &MaxValue);
		if (res != NTS_SUCCESS) 
		{
			return res;
		}
		res = ENA_GetMarkerMin(vENAHandle, TraceNo, MinMarkerNo, &MinValue);
		if (res != NTS_SUCCESS) 
		{
			return res;
		}
		//模块调试状态识别
		if (MinValue >= LimitedUp)
		{
			//该产品需要降DA
			Forward = -1;
		}
		else if(MinValue >= LimitedDown && MaxValue > LimitedUp)
		{
			//该产品需要降DA
			Forward = -1;
		}
		else if (MinValue < LimitedDown && MaxValue >LimitedDown && MaxValue <= LimitedUp) 
		{
			//该产品需要升DA
			Forward = 1;
		}
		else if ( LimitedDown - MaxValue >= 0  && LimitedDown - MaxValue <= MaxGainOffsetVsLimitedDown)
		{
			//该产品需要升DA
			Forward = 1;
		}
		else
		{
			//不用调试，如果执行过DA调试的产品，需要判断DA是否写入到FLASH
			if (i == 0) 
			{
				return NTS_SUCCESS;
			}
			res = NTS_GetStarAndStopFlash(vNTSHandle, FlashIndex, DAStartAddr, DACount, ReadDA);
			if (res != NTS_SUCCESS)
			{
				return res;
			}
			for(j = 0; j<DACount; j++)
			{
				if (ReadDA[j] != WriteDA[j])
				{
					return NTS_GAIN_DUBUG_ERROR;
				}
			}
			break;
		}
		//只有第一次才从产品中获取DA值，以提高效率
		if (i == 0)
		{
			res = NTS_GetStarAndStopFlash(vNTSHandle, FlashIndex, DAStartAddr, DACount, ReadDA);
			if (res != NTS_SUCCESS)
			{
				return res;
			}
			for(j = 0 ; j < DACount; j++)
			{
				WriteDA[j] = ReadDA[j];
			}
		}
		for(j = 0 ; j < DACount; j++)
		{
			WriteDA[j] = WriteDA[j] + Forward*DAStep;
		}
		if (WriteDA[64] >vDAUpLimited)
		{
			sprintf(m_ErrMsg, "DA超过规定的范围[0, %d],当前DA:%d", vDAUpLimited, WriteDA[64]);
			NTS_Error(m_ErrMsg);
			return NTS_GAIN_DUBUG_ERROR;
		}
		res = NTS_SetStarAndStopFlash(vNTSHandle, FlashIndex, DAStartAddr, DACount, WriteDA);
		if (res != NTS_SUCCESS)
		{
			return res;
		}		
		Sleep(DelayTime);
	}
	
	return NTS_SUCCESS;
}

//M_SPE_OpenDev 
M_SPE_OpenDev::M_SPE_OpenDev()
:BaseMethod()
{
	sprintf(m_MethodScript,"打开设备(ConnectStr格式(厂商[自定义]::型号[设备型号]::接口[TCPIP|GPIB|COM]::地址参数::固定值))");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	Init();
}

M_SPE_OpenDev::~M_SPE_OpenDev()
{
//	free(m_InputPara1);
//	free(m_InputPara2);
///	free(m_OutputPara1);
	
}

int M_SPE_OpenDev::Init(void)
{
	sprintf(m_InputPara1->paramName, "DevType");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "ConnectStr");
	m_InputPara2->paramType = NTSString;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"NTS::");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	

	sprintf(m_OutputPara1->paramName, "DeviceHandle");
	m_OutputPara1->paramType = NTSInt16;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"-1");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);

	return NTS_SUCCESS;
}

int M_SPE_OpenDev::Run(void)
{		
	int retVal;
	TDevcieType devType;
	int devHandle;
	devHandle = -1;
	devType = (TDevcieType)(atoi(m_InputPara1->paramVal));
    retVal = OpenDevice(devType, m_InputPara2->paramVal, &devHandle);
	if (retVal == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%d", devHandle);
	}
	return retVal;
}

//M_SPE_CloseDev 
M_SPE_CloseDev::M_SPE_CloseDev()
:BaseMethod()
{
	sprintf(m_MethodScript,"关闭设备");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_SPE_CloseDev::~M_SPE_CloseDev()
{
//	free(m_InputPara1);
//	free(m_InputPara2);
	
}

int M_SPE_CloseDev::Init(void)
{
	
	sprintf(m_InputPara1->paramName, "DeviceType");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "ConnectStr");
	m_InputPara2->paramType = NTSString;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}

int M_SPE_CloseDev::Run(void)
{		
	TDevcieType devType;
	devType = TDevcieType(atoi(m_InputPara1->paramVal));
    return CloseDevice(devType, m_InputPara2->paramVal);
}
// M_SPE_SetBufSize 
M_SPE_SetBufSize::M_SPE_SetBufSize()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置缓冲区长度(Mask 0:ALL 1:Tx_Buffer 2:Rx_Buffer)");	
	m_DevName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}
M_SPE_SetBufSize::~M_SPE_SetBufSize()
{	
//	free(m_DevName);
//	free(m_InputPara1);	
//	free(m_InputPara2);
}

int M_SPE_SetBufSize::Init(void)
{
	sprintf(m_DevName->paramName, "ConnectStr");
	m_DevName->paramType = NTSString;
	m_DevName->paramCount = 1;
	sprintf(m_DevName->paramVal,"");
	sprintf(m_DevName->paramUnit , "");
	m_InputParamVector.push_back(m_DevName);
	
	sprintf(m_InputPara1->paramName, "Mask");
	m_InputPara1->paramType = NTSInt32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "Size");
	m_InputPara2->paramType = NTSInt32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal,"4096");
	sprintf(m_InputPara2->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara2);

	return NTS_SUCCESS;
}
int M_SPE_SetBufSize::Run(void)
{
	unsigned long vHandle = 0;
	TDeviceManagerMap::iterator it; 
	TInterfaceType vIType;
	char vDeviveName[100];
	int vMask, vBufSize;
	int retVal;
	
	sprintf(vDeviveName, m_DevName->paramVal);	
	if (strlen(vDeviveName) <5) 
	{
		return NTS_INVALID_PARA;
	}
	vMask = atoi(m_InputPara1->paramVal);
	vBufSize = atoi(m_InputPara2->paramVal);
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;	
	vIType = (TInterfaceType)it->second.InterFaceType;
	switch(vIType)
	{
	case GPIB:
	
		break;
		
	case LAN:
		retVal = NTS_SetLanBufSize(vHandle, vMask, vBufSize);
		if(retVal != NTS_SUCCESS)
		{		
			return NTS_INVALID_OPERATE;
		}
		break;
		
	case COM:

		break;
		
	default:
		return NTS_INVALID_OPERATE;
		break;
	}	
	return NTS_SUCCESS;	
}

// M_SPE_ClearBuf
M_SPE_ClearBuf::M_SPE_ClearBuf()
:BaseMethod()
{
	sprintf(m_MethodScript, "清除缓冲区(Mask 0:ALL 1:Tx_Buffer 2:Rx_Buffer)");	
	m_DevName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	Init();
}
M_SPE_ClearBuf::~M_SPE_ClearBuf()
{	
//	free(m_DevName);
//	free(m_InputPara1);	
}

int M_SPE_ClearBuf::Init(void)
{
	sprintf(m_DevName->paramName, "ConnectStr");
	m_DevName->paramType = NTSString;
	m_DevName->paramCount = 1;
	sprintf(m_DevName->paramVal,"");
	sprintf(m_DevName->paramUnit , "");
	m_InputParamVector.push_back(m_DevName);
	
	sprintf(m_InputPara1->paramName, "Mask");
	m_InputPara1->paramType = NTSInt32;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"0");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);
	
	return NTS_SUCCESS;
}
int M_SPE_ClearBuf::Run(void)
{
	unsigned long vHandle = 0;
	TDeviceManagerMap::iterator it; 
	TInterfaceType vIType;
	char vDeviveName[100];
	int vMask;
	int retVal;
	
	sprintf(vDeviveName, m_DevName->paramVal);	
	if (strlen(vDeviveName) <5) 
	{
		return NTS_INVALID_PARA;
	}
	vMask = atoi(m_InputPara1->paramVal);

	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;	
	vIType = (TInterfaceType)it->second.InterFaceType;
	switch(vIType)
	{
	case GPIB:
		
		break;
		
	case LAN:
		retVal = NTS_FlushLanBuf(vHandle, vMask);
		if(retVal != NTS_SUCCESS)
		{		
			return NTS_INVALID_OPERATE;
		}
		break;
		
	case COM:
		
		break;
		
	default:
		return NTS_INVALID_OPERATE;
		break;
	}	
	return NTS_SUCCESS;	
}

// M_SPE_WriteDev 
M_SPE_WriteDev::M_SPE_WriteDev()
:BaseMethod()
{
	sprintf(m_MethodScript, "向自定义设备写入数据( FCommIsStr := False[以ASCII码方式发送数据];  FCommIsStr := True[以文本方式发送数据] )");	
	m_DevName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	Init();
}
M_SPE_WriteDev::~M_SPE_WriteDev()
{	
//	free(m_DevName);
//	free(m_InputPara1);		
}

int M_SPE_WriteDev::Init(void)
{
	sprintf(m_DevName->paramName, "ConnectStr");
	m_DevName->paramType = NTSString;
	m_DevName->paramCount = 1;
	sprintf(m_DevName->paramVal,"");
	sprintf(m_DevName->paramUnit , "");
	m_InputParamVector.push_back(m_DevName);

	sprintf(m_InputPara1->paramName, "CommandStrOfSCPI");
	m_InputPara1->paramType = NTSPChar;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	return NTS_SUCCESS;
}
int M_SPE_WriteDev::Run(void)
{
	unsigned long vHandle = 0;
	TDeviceManagerMap::iterator it; 
	TInterfaceType vIType;
	char vDeviveName[100];
	int retVal;
	char *pWriteBuf = NULL;
	char RetStr[40000] = {0};
	unsigned long retCnt = 0;
	int vParamLen;

//	if (m_InputPara1->paramType == NTSPChar && m_InputPara1->paramCount > 0) 
	if (!gCommIsStr) 
	{
		// 数据流方式
		vParamLen = m_InputPara1->paramCount;
		pWriteBuf = (char *)malloc(vParamLen*sizeof(char));
		memset(pWriteBuf, 0, vParamLen);
		memcpy(pWriteBuf, m_InputPara1->paramVal, vParamLen);
	}
	else
	{
		// 字符串方式
		pWriteBuf = (char *)malloc( PARALENGTH * sizeof(char));
		memset(pWriteBuf, 0, PARALENGTH);
		sprintf(pWriteBuf, "%s", m_InputPara1->paramVal);
		vParamLen = strlen(pWriteBuf);
		if(vParamLen <= 0)
		{
			// 释放内存
			if (pWriteBuf != NULL) 
			{
				free(pWriteBuf);
				pWriteBuf = NULL;
			}
			return NTS_INVALID_PARA;
		}		
		if (pWriteBuf[vParamLen] != '\n')
		{
			pWriteBuf[vParamLen] = '\n';
			pWriteBuf[vParamLen + 1] = '\0';
		}
		vParamLen = strlen(pWriteBuf);
	}


	// 分离设备连接字符串
	sprintf(vDeviveName, m_DevName->paramVal);	
	std::string protoclString;
	std::string tmpString, vManalfacotoryName;
	std::string::size_type pos = 0, oldPos = 0;
	std::vector<std::string> subProtocls;
	char vParentConnStr[200], vSubConnStr[200];
	
	protoclString = vDeviveName;
	// 
	pos = protoclString.find("," , oldPos);
	if (pos != std::string::npos)
	{
		tmpString = protoclString.substr(oldPos, pos - oldPos);
		sprintf(vParentConnStr, "%s", tmpString.c_str());
		oldPos = pos + 1;
		tmpString = protoclString.substr(oldPos, std::string::npos - oldPos);
		sprintf(vSubConnStr, "%s", tmpString.c_str());
	}
	else 
	{	
		tmpString = protoclString.substr(oldPos, pos - oldPos);	
		sprintf(vParentConnStr, "%s", tmpString.c_str());
	}
	
	// 主连接字符串
	protoclString = vParentConnStr;
	oldPos = 0;
	do
	{
		pos = protoclString.find("::", oldPos);
		if (pos != std::string::npos)
		{
			tmpString = protoclString.substr(oldPos, pos - oldPos);
			subProtocls.push_back(tmpString);
			oldPos = pos + 2;
		}
		else 
		{
			subProtocls.push_back(protoclString.substr(oldPos, pos));
			break;
		}
	}while(true);
	
	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		// 释放内存
		if (pWriteBuf != NULL) 
		{
			free(pWriteBuf);
			pWriteBuf = NULL;
		}
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;	
	vIType = (TInterfaceType)it->second.InterFaceType;

	switch(vIType)
	{
	case GPIB:
//		retVal = viPrintf(vHandle, "*CLS;%s", pWriteBuf);
//		sprintf(RetStr, "*CLS;%s", pWriteBuf);
		retVal = viWrite(vHandle, (unsigned char *)pWriteBuf, strlen(pWriteBuf), &retCnt);
		if(retVal < VI_SUCCESS)
		{
			// 释放内存
			if (pWriteBuf != NULL) 
			{
				free(pWriteBuf);
				pWriteBuf = NULL;
			}
			return NTS_INVALID_OPERATE;
		}
//		retVal = viPrintf(vHandle, "*OPC?\n");
//		if(retVal < VI_SUCCESS)
//		{
//			// 释放内存
//			if (pWriteBuf != NULL) 
//			{
//				free(pWriteBuf);
//				pWriteBuf = NULL;
//			}
//			return NTS_INVALID_OPERATE;
//		}
		
		break;
		
	case LAN:
		tmpString = subProtocls[4];
		pos = tmpString.find("SOCKET");
		if (pos != std::string::npos)				//  
		{
			retVal = NTS_WriteLan(vHandle, pWriteBuf, vParamLen);
			if(retVal != NTS_SUCCESS)
			{	
				// 释放内存
				if (pWriteBuf != NULL) 
				{
					free(pWriteBuf);
					pWriteBuf = NULL;
				}
				return NTS_INVALID_OPERATE;
			}	
		}
		else 
		{
			retVal = viWrite(vHandle, (unsigned char *)pWriteBuf, strlen(pWriteBuf), &retCnt);
			if(retVal < VI_SUCCESS)
			{
				// 释放内存
				if (pWriteBuf != NULL) 
				{
					free(pWriteBuf);
					pWriteBuf = NULL;
				}
				return NTS_INVALID_OPERATE;
			}
		}	
		
		break;
		
	case COM:
		retVal = NTS_WriteCom(vHandle, pWriteBuf, vParamLen);
		if(retVal != NTS_SUCCESS)
		{	
			// 释放内存
			if (pWriteBuf != NULL) 
			{
				free(pWriteBuf);
				pWriteBuf = NULL;
			}
			return NTS_INVALID_OPERATE;
		}
		break;
 
		
	default:
		// 释放内存
		if (pWriteBuf != NULL) 
		{
			free(pWriteBuf);
			pWriteBuf = NULL;
		}
		return NTS_INVALID_OPERATE;
		break;
	}
	// 释放内存
	if (pWriteBuf != NULL) 
	{
		free(pWriteBuf);
		pWriteBuf = NULL;
	}
//	NTS_Info("执行NTSSCRIP_DLL write DEV___7");
	return NTS_SUCCESS;	
}


// M_SPE_ReadDev 
M_SPE_ReadDev::M_SPE_ReadDev()
:BaseMethod()
{
	sprintf(m_MethodScript, "从自定义设备读取数据(以','分隔的开字节数)");	
	m_DevName = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	Init();
}
M_SPE_ReadDev::~M_SPE_ReadDev()
{
//	free(m_DevName);
//	free(m_OutputPara1);
}

int M_SPE_ReadDev::Init(void)
{

	sprintf(m_DevName->paramName, "ConnectStr");
	m_DevName->paramType = NTSString;
	m_DevName->paramCount = 1;
	sprintf(m_DevName->paramVal,"");
	sprintf(m_DevName->paramUnit , "");
	m_InputParamVector.push_back(m_DevName);

	sprintf(m_OutputPara1->paramName, "Result");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);	

	return NTS_SUCCESS;
}

int M_SPE_ReadDev::Run(void)
{
	int retVal;
	unsigned long vHandle = 0;
	TDeviceManagerMap::iterator it; 
	TInterfaceType vIType;
	char vDeviveName[100];	
	char RetStr[20000] = {0};
	unsigned long retCnt = 0;
	int vParamLen;
	
	// 分离设备连接字符串
	sprintf(vDeviveName, m_DevName->paramVal);	
	std::string protoclString;
	std::string tmpString, vManalfacotoryName;
	std::string::size_type pos = 0, oldPos = 0;
	std::vector<std::string> subProtocls;
	char vParentConnStr[200], vSubConnStr[200];
	
	protoclString = vDeviveName;
	// 
	pos = protoclString.find("," , oldPos);
	if (pos != std::string::npos)
	{
		tmpString = protoclString.substr(oldPos, pos - oldPos);
		sprintf(vParentConnStr, "%s", tmpString.c_str());
		oldPos = pos + 1;
		tmpString = protoclString.substr(oldPos, std::string::npos - oldPos);
		sprintf(vSubConnStr, "%s", tmpString.c_str());
	}
	else 
	{	
		tmpString = protoclString.substr(oldPos, pos - oldPos);	
		sprintf(vParentConnStr, "%s", tmpString.c_str());
	}
	
	// 主连接字符串
	protoclString = vParentConnStr;
	oldPos = 0;
	do
	{
		pos = protoclString.find("::", oldPos);
		if (pos != std::string::npos)
		{
			tmpString = protoclString.substr(oldPos, pos - oldPos);
			subProtocls.push_back(tmpString);
			oldPos = pos + 2;
		}
		else 
		{
			subProtocls.push_back(protoclString.substr(oldPos, pos));
			break;
		}
	}while(true);
	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	vIType = (TInterfaceType)it->second.InterFaceType;
	switch(vIType)
	{
	case GPIB:
		//获取输入参数值 
		retVal = viRead(vHandle, (ViBuf)RetStr, sizeof(RetStr), &retCnt);
		if (retVal < VI_SUCCESS)
		{
			return NTS_INVALID_OPERATE;		
		}		
		break;
		
	case LAN:	
		tmpString = subProtocls[4];
		pos = tmpString.find("SOCKET");
		if (pos != std::string::npos)				//  
		{
			retVal = NTS_ReadLan(vHandle, RetStr, sizeof(RetStr), &retCnt);
			if(retVal != NTS_SUCCESS)
			{		
				return NTS_INVALID_OPERATE;
			}	
		}
		else 
		{
			retVal = viRead(vHandle, (ViBuf)RetStr, sizeof(RetStr), &retCnt);
			if (retVal < VI_SUCCESS)
			{
				return NTS_INVALID_OPERATE;		
			}	
		}	
		break;
		
	case COM:
		retVal = NTS_ReadCom(vHandle, RetStr, sizeof(RetStr), &retCnt);
		if(retVal != NTS_SUCCESS)
		{		
			return NTS_INVALID_OPERATE;
		}
		break;
		
	default:
		return NTS_INVALID_OPERATE;
		break;
	}
	
	if (gCommIsStr) 
	{
		// 返回标准的字符串
		if (retCnt > PARALENGTH)
		{		
			m_OutputPara1->LparamVal = (char *)malloc( (retCnt)*sizeof(char));
			memset(m_OutputPara1->LparamVal, 0, retCnt);
			sprintf(m_OutputPara1->LparamVal, "%s", RetStr);		
		}
		else
		{	
			memset(m_OutputPara1->paramVal, 0, sizeof(PARALENGTH));
			sprintf(m_OutputPara1->paramVal, "%s", RetStr);
		}	
	}
	else
	{
		// 返回标准的16进制数据流
		if (retCnt > PARALENGTH/3)
		{		
			m_OutputPara1->LparamVal = (char *)malloc( (retCnt*4)*sizeof(char));
			memset(m_OutputPara1->LparamVal, 0, retCnt*4);
			sprintf(m_OutputPara1->LparamVal, "%02X", RetStr[0]);
			for(vParamLen = 1; vParamLen < retCnt; vParamLen++)
			{
				sprintf(m_OutputPara1->LparamVal, "%s,%02X", m_OutputPara1->paramVal, RetStr[vParamLen]);
			}
		}
		else
		{	
			memset(m_OutputPara1->paramVal, 0, sizeof(PARALENGTH));
			sprintf(m_OutputPara1->paramVal, "%02X", RetStr[0]);
			for(vParamLen = 1; vParamLen < retCnt; vParamLen++)
			{
				sprintf(m_OutputPara1->paramVal, "%s,%02X", m_OutputPara1->paramVal, RetStr[vParamLen]&0xff);
			}
		}
	}

	return NTS_SUCCESS;
}

// M_SPE_QueryDev 
M_SPE_QueryDev::M_SPE_QueryDev()
:BaseMethod()
{
	sprintf(m_MethodScript, "向设备写命令并从设备读取命令执行后的数据");	
	m_DevName = CreateParamStruct();
	m_InputPara	= CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	Init();
}
M_SPE_QueryDev::~M_SPE_QueryDev()
{
//	free(m_DevName);
//	free(m_InputPara);
//	free(m_OutputPara1);
}

int M_SPE_QueryDev::Init(void)
{
	
	sprintf(m_DevName->paramName, "ConnectStr");
	m_DevName->paramType = NTSString;
	m_DevName->paramCount = 1;
	sprintf(m_DevName->paramVal,"");
	sprintf(m_DevName->paramUnit , "");
	m_InputParamVector.push_back(m_DevName);
	
	sprintf(m_InputPara->paramName, "CommandStrOfSCPI");
	m_InputPara->paramType = NTSPChar;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);
	
	sprintf(m_OutputPara1->paramName, "Result");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal,"");
	sprintf(m_OutputPara1->paramUnit , "");
	m_OutputParamVector.push_back(m_OutputPara1);	
	
	return NTS_SUCCESS;
}

int M_SPE_QueryDev::Run(void)
{
	int retVal;
	unsigned long vHandle = 0;
	TDeviceManagerMap::iterator it; 
	TInterfaceType vIType;
	char vDeviveName[100];
	char *pWriteBuf = NULL;
	char RetStr[40000] = {0};
	unsigned long retCnt = 0;
	int vParamLen;

	
//	if (m_InputPara->paramType == NTSPChar && m_InputPara->paramCount > 0)
	if (!gCommIsStr) 
	{
		// 数据流方式
		vParamLen = m_InputPara->paramCount;
		pWriteBuf = (char *)malloc(vParamLen*sizeof(char));
		memset(pWriteBuf, 0, vParamLen);
		memcpy(pWriteBuf, m_InputPara->paramVal, vParamLen);
	}
	else
	{
		// 字符串方式
		pWriteBuf = (char *)malloc( PARALENGTH * sizeof(char));
		memset(pWriteBuf, 0, PARALENGTH);
		sprintf(pWriteBuf, "%s", m_InputPara->paramVal);
		vParamLen = strlen(pWriteBuf);
		if(vParamLen <= 0)
		{
			// 释放内存
			if (pWriteBuf != NULL) 
			{
				free(pWriteBuf);
				pWriteBuf = NULL;
			}
			return NTS_INVALID_PARA;
		}		
		if (pWriteBuf[vParamLen] != '\n')
		{
			pWriteBuf[vParamLen] = '\n';
			pWriteBuf[vParamLen + 1] = '\0';
		}
		vParamLen = strlen(pWriteBuf);
	}

	// 分离设备连接字符串
	sprintf(vDeviveName, m_DevName->paramVal);	
	std::string protoclString;
	std::string tmpString, vManalfacotoryName;
	std::string::size_type pos = 0, oldPos = 0;
	std::vector<std::string> subProtocls;
	char vParentConnStr[200], vSubConnStr[200];

	protoclString = vDeviveName;
	// 
	pos = protoclString.find("," , oldPos);
	if (pos != std::string::npos)
	{
		tmpString = protoclString.substr(oldPos, pos - oldPos);
		sprintf(vParentConnStr, "%s", tmpString.c_str());
		oldPos = pos + 1;
		tmpString = protoclString.substr(oldPos, std::string::npos - oldPos);
		sprintf(vSubConnStr, "%s", tmpString.c_str());
	}
	else 
	{	
		tmpString = protoclString.substr(oldPos, pos - oldPos);	
		sprintf(vParentConnStr, "%s", tmpString.c_str());
	}
	
	// 主连接字符串
	protoclString = vParentConnStr;
	oldPos = 0;
	do
	{
		pos = protoclString.find("::", oldPos);
		if (pos != std::string::npos)
		{
			tmpString = protoclString.substr(oldPos, pos - oldPos);
			subProtocls.push_back(tmpString);
			oldPos = pos + 2;
		}
		else 
		{
			subProtocls.push_back(protoclString.substr(oldPos, pos));
			break;
		}
	}while(true);
	
	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		// 释放内存
		if (pWriteBuf != NULL) 
		{
			free(pWriteBuf);
			pWriteBuf = NULL;
		}
		return NTS_INVALID_DEVICE;
	}	
	vHandle = it->second.DevHandle;
	vIType = (TInterfaceType)it->second.InterFaceType;
	switch(vIType)
	{
	case GPIB:
		
		//获取输入参数值 
		retVal = viQueryf(vHandle, pWriteBuf, "%t", RetStr);
		if (retVal < VI_SUCCESS)
		{
			// 释放内存
			if (pWriteBuf != NULL) 
			{
				free(pWriteBuf);
				pWriteBuf = NULL;
			}
			return NTS_INVALID_DEVICE;		
		}
		retCnt = strlen(RetStr);
		break;
		
	case LAN:
		tmpString = subProtocls[4];
		pos = tmpString.find("SOCKET");
		if (pos != std::string::npos)				//  
		{
			retVal = NTS_QueryLan(vHandle, pWriteBuf, vParamLen, RetStr, &retCnt);
			if(retVal != NTS_SUCCESS)
			{		
				// 释放内存
				if (pWriteBuf != NULL) 
				{
					free(pWriteBuf);
					pWriteBuf = NULL;
				}
				return NTS_INVALID_OPERATE;
			}		
		}
		else 
		{
			//获取输入参数值 
			retVal = viQueryf(vHandle, pWriteBuf, "%t", RetStr);
			if (retVal < VI_SUCCESS)
			{
				// 释放内存
				if (pWriteBuf != NULL) 
				{
					free(pWriteBuf);
					pWriteBuf = NULL;
				}
				return NTS_INVALID_DEVICE;		
			}
			retCnt = strlen(RetStr);
		}	
			
//		NTS_Error("暂时还不支持该接口!");
//		return NTS_INVALID_OPERATE;
		break;
		
	case COM:
		retVal = NTS_QueryCom(vHandle, pWriteBuf, vParamLen, RetStr, &retCnt);
		if(retVal != NTS_SUCCESS)
		{		
			// 释放内存
			if (pWriteBuf != NULL) 
			{
				free(pWriteBuf);
				pWriteBuf = NULL;
			}
			return NTS_INVALID_OPERATE;
		}
		break;
		
	default:
		// 释放内存
		if (pWriteBuf != NULL) 
		{
			free(pWriteBuf);
			pWriteBuf = NULL;
		}
		return NTS_INVALID_OPERATE;
		break;
	}
	if (gCommIsStr) 
	{
		// 返回标准的字符串
		if (retCnt > PARALENGTH)
		{		
			m_OutputPara1->LparamVal = (char *)malloc( (retCnt)*sizeof(char));
			memset(m_OutputPara1->LparamVal, 0, retCnt);
			sprintf(m_OutputPara1->LparamVal, "%s", RetStr);		
		}
		else
		{	
			memset(m_OutputPara1->paramVal, 0, sizeof(PARALENGTH));
			sprintf(m_OutputPara1->paramVal, "%s", RetStr);
		}	
	}
	else
	{
		// 返回标准的16进制数据流
		if (retCnt > PARALENGTH/3)
		{		
			m_OutputPara1->LparamVal = (char *)malloc( (retCnt*4)*sizeof(char));
			memset(m_OutputPara1->LparamVal, 0, retCnt*4);
			sprintf(m_OutputPara1->LparamVal, "%02X", RetStr[0]&0xff);
			for(vParamLen = 1; vParamLen < retCnt; vParamLen++)
			{
				sprintf(m_OutputPara1->LparamVal, "%s,%02X", m_OutputPara1->LparamVal, RetStr[vParamLen]&0xff);
			}
		}
		else
		{	
			memset(m_OutputPara1->paramVal, 0, sizeof(PARALENGTH));
			sprintf(m_OutputPara1->paramVal, "%02X", RetStr[0]&0xff);
			for(vParamLen = 1; vParamLen < retCnt; vParamLen++)
			{
				sprintf(m_OutputPara1->paramVal, "%s,%02X", m_OutputPara1->paramVal, RetStr[vParamLen]&0xff);
			}
			
		}
	}
	
	// 释放内存
	if (pWriteBuf != NULL) 
	{
		free(pWriteBuf);
		pWriteBuf = NULL;
	}
	return NTS_SUCCESS;
}
// class M_SPE_SprintfDev 向自定义设备写入数据(字符串)
M_SPE_SprintfDev::M_SPE_SprintfDev()
:BaseMethod()
{
	sprintf(m_MethodScript, "向自定义设备写入数据(字符串)");	
	m_DevName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	Init();
}
M_SPE_SprintfDev::~M_SPE_SprintfDev()
{	
//	free(m_DevName);
//	free(m_InputPara1);		
}

int M_SPE_SprintfDev::Init(void)
{
	sprintf(m_DevName->paramName, "ConnectStr");
	m_DevName->paramType = NTSString;
	m_DevName->paramCount = 1;
	sprintf(m_DevName->paramVal,"");
	sprintf(m_DevName->paramUnit , "");
	m_InputParamVector.push_back(m_DevName);

	sprintf(m_InputPara1->paramName, "CommandStrOfSCPI");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"*IDN?");
	sprintf(m_InputPara1->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara1);

	return NTS_SUCCESS;
}
int M_SPE_SprintfDev::Run(void)
{
	unsigned long vHandle = 0;
	TDeviceManagerMap::iterator it; 
	TInterfaceType vIType;
	char vDeviveName[100];
	int retVal;
	char *pWriteBuf = NULL;
	char RetStr[40000] = {0};
	unsigned long retCnt = 0;
	int vParamLen;
	
	if (m_InputPara1->LparamVal != NULL)
	{
		vParamLen = strlen(m_InputPara1->LparamVal);
		pWriteBuf = (char *)malloc((vParamLen+10)*sizeof(char));
		memset(pWriteBuf, 0, vParamLen+10);
		memcpy(pWriteBuf, m_InputPara1->LparamVal, vParamLen+10);
	}
	else
	{
		vParamLen = strlen(m_InputPara1->paramVal);
		pWriteBuf = (char *)malloc((vParamLen+10)*sizeof(char));
		memset(pWriteBuf, 0, vParamLen+10);
		memcpy(pWriteBuf, m_InputPara1->paramVal, vParamLen+10);
	}

	if(vParamLen <= 0)
	{
		// 释放内存
		if (pWriteBuf != NULL) 
		{
			free(pWriteBuf);
			pWriteBuf = NULL;
		}
		return NTS_INVALID_PARA;
	}		
	if (pWriteBuf[vParamLen] != '\n')
	{
		pWriteBuf[vParamLen] = '\n';
		pWriteBuf[vParamLen + 1] = '\0';
		vParamLen = strlen(pWriteBuf);
	}

	sprintf(vDeviveName, m_DevName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		// 释放内存
		if (pWriteBuf != NULL) 
		{
			free(pWriteBuf);
			pWriteBuf = NULL;
		}
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;	
	vIType = (TInterfaceType)it->second.InterFaceType;
	switch(vIType)
	{
	case GPIB:
		retVal = viPrintf(vHandle, "*CLS;%s", pWriteBuf);
		if(retVal < VI_SUCCESS)
		{
			// 释放内存
			if (pWriteBuf != NULL) 
			{
				free(pWriteBuf);
				pWriteBuf = NULL;
			}
			return NTS_INVALID_OPERATE;
		}
		retVal = viPrintf(vHandle, "*OPC?\n");
		if(retVal < VI_SUCCESS)
		{
			// 释放内存
			if (pWriteBuf != NULL) 
			{
				free(pWriteBuf);
				pWriteBuf = NULL;
			}
			return NTS_INVALID_OPERATE;
		}
		
		break;
		
	case LAN:
		retVal = NTS_WriteLan(vHandle, pWriteBuf, vParamLen);
		if(retVal != NTS_SUCCESS)
		{	
			// 释放内存
			if (pWriteBuf != NULL) 
			{
				free(pWriteBuf);
				pWriteBuf = NULL;
			}
			return NTS_INVALID_OPERATE;
		}
		break;
		
	case COM:
		retVal = NTS_WriteCom(vHandle, pWriteBuf, vParamLen);
		if(retVal != NTS_SUCCESS)
		{	
			// 释放内存
			if (pWriteBuf != NULL) 
			{
				free(pWriteBuf);
				pWriteBuf = NULL;
			}
			return NTS_INVALID_OPERATE;
		}
		break;
		
	default:
		// 释放内存
		if (pWriteBuf != NULL) 
		{
			free(pWriteBuf);
			pWriteBuf = NULL;
		}
		return NTS_INVALID_OPERATE;
		break;
	}
	// 释放内存
	if (pWriteBuf != NULL) 
	{
		free(pWriteBuf);
		pWriteBuf = NULL;
	}
	return NTS_SUCCESS;	
}

// M_SPE_SetCom 设置Com通讯参数
M_SPE_SetCom::M_SPE_SetCom()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置串口通讯参数");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();
	m_InputPara[3] = CreateParamStruct();

	Init();
}

M_SPE_SetCom::~M_SPE_SetCom()
{
//	free(m_InputDeviceName);
//	free(m_InputPara[0]);
//	free(m_InputPara[1]);
//	free(m_InputPara[2]);
//	free(m_InputPara[3]);

}

int M_SPE_SetCom::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSString;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara[0]->paramName, "BaudRate");
	m_InputPara[0]->paramType = NTSInt32;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"9600");
	sprintf(m_InputPara[0]->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara[0]);	
	
	sprintf(m_InputPara[1]->paramName, "Databit");
	m_InputPara[1]->paramType = NTSInt16;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"8");
	sprintf(m_InputPara[1]->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara[1]);

	sprintf(m_InputPara[2]->paramName, "parity");
	m_InputPara[2]->paramType = NTSInt16;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"0");
	sprintf(m_InputPara[2]->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara[2]);	
	
	sprintf(m_InputPara[3]->paramName, "stopbit");
	m_InputPara[3]->paramType = NTSInt16;
	m_InputPara[3]->paramCount = 1;
	sprintf(m_InputPara[3]->paramVal,"1");
	sprintf(m_InputPara[3]->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara[3]);
	return NTS_SUCCESS;
}
int M_SPE_SetCom::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	int vBaudRate, vDatabit, vParity, vStopbit;
	
	sprintf(vDeviveName, m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	vBaudRate = atoi(m_InputPara[0]->paramVal);
	vDatabit = atoi(m_InputPara[1]->paramVal);
	vParity = atoi(m_InputPara[2]->paramVal);
	vStopbit = atoi(m_InputPara[3]->paramVal);
	res = NTS_SetCom(vHandle, vBaudRate, vDatabit, vParity, vStopbit);
	return res;
}

// M_NTS_SetDTR 
M_SPE_SetDTR::M_SPE_SetDTR()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置RTS(数据终端就绪)标志  0:Low 1:Hight");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	
	Init();
}

M_SPE_SetDTR::~M_SPE_SetDTR()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);	
}

int M_SPE_SetDTR::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSString;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "State");
	m_InputPara->paramType = NTSInt32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara);	
	return NTS_SUCCESS;
}

int M_SPE_SetDTR::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	int vState;
	
	sprintf(vDeviveName, m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	vState = atoi(m_InputPara->paramVal);
	res = NTS_SetDTR(vHandle, vState);
	return res;
}

//M_NTS_SetRTS 
M_SPE_SetRTS::M_SPE_SetRTS()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置RTS(设置请求数据发送)标志  0:Low 1:Hight");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	
	Init();
}

M_SPE_SetRTS::~M_SPE_SetRTS()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);	
}

int M_SPE_SetRTS::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSString;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "State");
	m_InputPara->paramType = NTSInt32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara);	
	return NTS_SUCCESS;
}

int M_SPE_SetRTS::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	int vState;
	
	sprintf(vDeviveName, m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	vState = atoi(m_InputPara->paramVal);
	res = NTS_SetRTS(vHandle, vState);
	return res;
}

// M_SPE_SetXOFF 
M_SPE_SetXOFF::M_SPE_SetXOFF()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置XOFF(设置流数据停止发送)标志 软件流控制");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	
	Init();
}

M_SPE_SetXOFF::~M_SPE_SetXOFF()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);	
}

int M_SPE_SetXOFF::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSString;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "State");
	m_InputPara->paramType = NTSInt32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara);	
	return NTS_SUCCESS;
}

int M_SPE_SetXOFF::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	int vState;
	
	sprintf(vDeviveName, m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	vState = atoi(m_InputPara->paramVal);
	res = NTS_SetXOFF(vHandle);
	return res;
}

// M_SPE_SetXON 
M_SPE_SetXON::M_SPE_SetXON()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置XON(设置流数据继续发送)标志 软件流控制");
	m_InputDeviceName = CreateParamStruct();
	m_InputPara = CreateParamStruct();	
	
	Init();
}

M_SPE_SetXON::~M_SPE_SetXON()
{
//	free(m_InputDeviceName);
//	free(m_InputPara);	
}

int M_SPE_SetXON::Init(void)
{
	sprintf(m_InputDeviceName->paramName, "ConnectStr");
	m_InputDeviceName->paramType = NTSString;
	m_InputDeviceName->paramCount = 1;
	sprintf(m_InputDeviceName->paramVal,"");
	sprintf(m_InputDeviceName->paramUnit, " ");
	m_InputParamVector.push_back(m_InputDeviceName);
	
	sprintf(m_InputPara->paramName, "State");
	m_InputPara->paramType = NTSInt32;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit, " ");
	m_InputParamVector.push_back(m_InputPara);	
	return NTS_SUCCESS;
}

int M_SPE_SetXON::Run(void)
{
	int res;
	short int vHandle = 0;
	TDeviceManagerMap::iterator it; 	
	char vDeviveName[100];	
	int vState;
	
	sprintf(vDeviveName, m_InputDeviceName->paramVal);	
	it = gDeviceManagerMap.find(vDeviveName);
	if(it == gDeviceManagerMap.end())
	{
		return NTS_INVALID_DEVICE;
	}
	vHandle = it->second.DevHandle;
	vState = atoi(m_InputPara->paramVal);
	res = NTS_SetXON(vHandle);
	return res;
}

//M_SPE_PolyFit 
M_SPE_PolyFit::M_SPE_PolyFit()
:BaseMethod()
{
	//其中采取最小二乘法处理数据
	sprintf(m_MethodScript, "多项式拟合(XValuex: 采样点的X轴数据 YValuex: 采样点的Y轴数据,采样点个数(2~2000)	N:拟合次数(1~5) ");
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_InputPara[2] = CreateParamStruct();
	m_InputPara[3] = CreateParamStruct();

	m_OutputPara[0] = CreateParamStruct();
	m_OutputPara[1] = CreateParamStruct();
	m_OutputPara[2] = CreateParamStruct();
	Init();
}

M_SPE_PolyFit::~M_SPE_PolyFit()
{
//	free(m_InputPara[0]);
//	free(m_InputPara[1]);
//	free(m_InputPara[2]);
//	free(m_InputPara[3]);

//	free(m_OutputPara[0]);
//	free(m_OutputPara[1]);
//	free(m_OutputPara[2]);
	
}
int M_SPE_PolyFit::Init(void)
{
	
	sprintf(m_InputPara[0]->paramName, "XValues");
	m_InputPara[0]->paramType = NTSString;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"");
	sprintf(m_InputPara[0]->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara[0]);
	
	sprintf(m_InputPara[1]->paramName, "YValues");
	m_InputPara[1]->paramType = NTSString;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"");
	sprintf(m_InputPara[1]->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara[1]);
	
	sprintf(m_InputPara[2]->paramName, "N");
	m_InputPara[2]->paramType = NTSInt16;
	m_InputPara[2]->paramCount = 1;
	sprintf(m_InputPara[2]->paramVal,"1");
	sprintf(m_InputPara[2]->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara[2]);

	sprintf(m_OutputPara[0]->paramName, "Coefficienes");
	m_OutputPara[0]->paramType = NTSString;
	m_OutputPara[0]->paramCount = 1;
	sprintf(m_OutputPara[0]->paramVal,"");
	sprintf(m_OutputPara[0]->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara[0]);

//	sprintf(m_OutputPara[1]->paramName, "Mean Squared Error");
//	m_OutputPara[1]->paramType = NTSReal32;
//	m_OutputPara[1]->paramCount = 1;
//	sprintf(m_OutputPara[1]->paramVal,"");
//	sprintf(m_OutputPara[1]->paramUnit, "");
//	m_OutputParamVector.push_back(m_OutputPara[1]);

	return NTS_SUCCESS;
}

double  M_SPE_PolyFit::pow_n(double a, int   n) 
{ 
	int   i; 
	double   res;
	
	if(n==0) 
		return(1); 

	res = a; 
	for(i=1; i<n; i++) 
	{ 
		res *= a; 
	} 
	return(res); 
} 

int M_SPE_PolyFit::mutiple(double a[][PARALENGTH], double b[][T+1], double c[][T+1], int Count, int N) 
{ 
	double   res=0; 
	int   i,j,k; 

	for(i=0; i<N+1; i++) 
		for(j=0; j<N+1; j++) 
		{ 
			res=0; 
			for(k=0; k<Count; k++) 
			{ 
				res += a[i][k]*b[k][j]; 
				c[i][j] = res; 
			} 
		} 
	return 0;
} 

int M_SPE_PolyFit::matrix_trans(double a[][T+1], double b[][PARALENGTH], int Count, int N) 
{ 
	int   i,j; 
	for(i=0; i<Count; i++) 
	{ 
		for(j=0;j <N+1;j++) 
		{ 
			b[j][i]=a[i][j]; 
		} 
	} 
	return 0; 
} 

int M_SPE_PolyFit::get_A(double matrix_A[][T+1], double x_y[][2], int Count, int N) 
{ 
	int   i,j; 
	
	for(i=0; i<Count; i++) 
	{ 
		for(j=0; j<N+1; j++) 
		{ 
			matrix_A[i][j] = W*pow_n(x_y[i][0], j); 
		} 		
	} 
	return 0;
} 

int M_SPE_PolyFit::convert(double argu[][T+2], int N) 
{ 
	int   i,j,k; 
	double   rate; 
	double vArgu[PARALENGTH][T+2];

	for(i =0;i<N+1;i++)
		for(j=0;j<N+2;j++)
		{
			vArgu[i][j] = argu[i][j];
		}
	
	for(j=0; j<N; j++) 
	{		
		for(i=j+1; i<N+1; i++) 
		{
			rate = vArgu[i][j]/vArgu[j][j]; 
			for(k = j; k<N+2; k++)
			{
				vArgu[i][k]= vArgu[i][k] - vArgu[j][k]*rate; 
//				if(fabs(vArgu[i][k]) <= PRECISION) 
//					vArgu[i][k]=0; 
			}
		}		
	} 
	for(i =0;i<N+1;i++)
		for(j=0;j<N+2;j++)
		{
			argu[i][j] = vArgu[i][j];
		}
	return NTS_SUCCESS;
} 

int M_SPE_PolyFit::compute(double argu[][T+2], int N, double root[]) 
{ 
	int   i,j; 
	double   temp; 

	for(i=N;i>=0;i--) 
	{ 
		temp = argu[i][N+1]; 
		for(j=N; j> i; j--) 
		{ 
			temp -= argu[i][j]*root[j]; 
		} 
		if(argu[i][i] == 0)
		{
			root[i] = temp;
		}
		else
		{
			root[i] = temp/argu[i][i]; 
		}
		
	} 
	return 0;
} 

int M_SPE_PolyFit::get_y(double trans_A[][PARALENGTH], double x_y[][2], double y[], int Count, int N) 
{ 
	int   i,j; 
	double   temp; 

	for(i=0; i<N+1; i++) 
	{ 
		temp=0; 
		for(j=0; j<Count; j++) 
		{ 
			temp+=trans_A[i][j]*x_y[j][1]; 
		} 
		y[i]=temp; 
	} 
	return 0;
} 

int M_SPE_PolyFit::cons_formula(double coef_A[][T+1], double y[], double coef_form[][T+2], int N) 
{ 
	int   i,j; 

	for(i=0; i<N+1; i++) 
	{ 
		for(j=0; j<N+2; j++) 
		{ 
			if(j== N+1) 
				coef_form[i][j]=y[i]; 
			else 
				coef_form[i][j]=coef_A[i][j]; 
		} 
	}
	return 0;
} 

double  M_SPE_PolyFit::ComputeMatrix(double *A, int N)   
{   
	if( N == 1)   
		return   *A; 
	
	if(N == 2)   
	{   
		double   temp=(*A)*(*(A+3))-(*(A+1))*(*(A+2));   
		return   temp;   
	}   
    
	int   i,j,k;   
	double   sum=0;   
	double *B= new   double[(N-1)*(N-1)];   
	
	for(i=0;i<N;i++)   
	{   
		for(j=0;j<N-1;j++)   
		{   
			for(k=0;k<N-1;k++)   
			{   
				if(k<i)   
					*(B+j*(N-1)+k)=*(A+(j+1)*N+k);   
				else   
					*(B+j*(N-1)+k)=*(A+(j+1)*N+k+1);   
			}   
		}   
		if(i/2*2==i)   
			sum=sum+(*(A+i))*ComputeMatrix(B,N-1);   
		else   
			sum=sum-(*(A+i))*ComputeMatrix(B,N-1);   
	}   
	delete   B;   
	return   sum;   
}   

int M_SPE_PolyFit::Run(void)
{	
	int i;
	char *TempStr;
	int SampleCount;
	double x_point[PARALENGTH], y_point[PARALENGTH];
	int TotalLength, N = 1, PointCountX, PointCountY;
	double x_y[PARALENGTH][2], matrix_A[PARALENGTH][T+1],trans_A[T+1][PARALENGTH],coef_A[T+1][T+1],coef_formu[T+1][T+2],y[T+1],a[T+1]; 
	double tempvalue[10000] = {0};
	
	
	//获取X轴数据
	if (m_InputPara[0]->LparamVal != NULL)
	{
		TotalLength = strlen(m_InputPara[0]->LparamVal) + 10;
		TempStr = (char *)malloc(TotalLength*sizeof(char));	
		sprintf(TempStr, m_InputPara[0]->LparamVal);			//标准输入字符串 以','分隔数据
	}
	else
	{
		TotalLength = strlen(m_InputPara[0]->paramVal) + 10;
		TempStr = (char *)malloc(TotalLength*sizeof(char));
		sprintf(TempStr, m_InputPara[0]->paramVal);			//标准输入字符串 以','分隔数据
	}
	
	//分离字符串
	tempvalue[0] = atof(&TempStr[0]);
	PointCountX = 1;
	for(i = 0; i < TotalLength; i++)
	{
		if(TempStr[i] == ',')
		{
			tempvalue[PointCountX] = atof(&TempStr[i+1]);
			PointCountX++;	
		} 
	}	
	if(PointCountX > PARALENGTH)
	{
		PointCountX = PARALENGTH;
	}
	for(i = 0; i<PointCountX; i++)
	{
		x_point[i] = tempvalue[i];
	}
	free(TempStr);
	
	///////////////////////////获取Y轴数据//////////////////////////////////	 
	if (m_InputPara[1]->LparamVal != NULL)
	{
		TotalLength = strlen(m_InputPara[1]->LparamVal) + 10;
		TempStr = (char *)malloc(TotalLength*sizeof(char));	
		sprintf(TempStr, m_InputPara[1]->LparamVal);			//标准输入字符串 以','分隔数据
	}
	else
	{
		TotalLength = strlen(m_InputPara[1]->paramVal) + 10;
		TempStr = (char *)malloc(TotalLength*sizeof(char));
		sprintf(TempStr, m_InputPara[1]->paramVal);			//标准输入字符串 以','分隔数据
	}
	
	//分离字符串
	tempvalue[0] = atof(&TempStr[0]);
	PointCountY = 1;
	for(i = 0; i < TotalLength; i++)
	{
		if(TempStr[i] == ',')
		{
			tempvalue[PointCountY] = atof(&TempStr[i+1]);
			PointCountY++;	
		} 
	}	
	if(PointCountY > PARALENGTH)
	{
		PointCountY = PARALENGTH;
	}
	for(i = 0; i<PointCountY; i++)
	{
		y_point[i] = tempvalue[i];
	}
	free(TempStr);

	if(PointCountX > PointCountY)
	{
		SampleCount = PointCountY;
	}
	else
	{
		SampleCount = PointCountX;
	}

	// 
	for(i= 0; i<SampleCount; i++)
	{
		x_y[i][0] = x_point[i];
		x_y[i][1] = y_point[i];
	}

	/////////////////////////拟合次数/////////////////////////////////////	 
	N = atoi(m_InputPara[2]->paramVal);

	//开始拟合曲线算法
	get_A(matrix_A , x_y, SampleCount, N); 
	matrix_trans(matrix_A, trans_A, SampleCount, N); 
	mutiple(trans_A, matrix_A , coef_A, SampleCount, N); 
	
	get_y(trans_A, x_y, y, SampleCount, N); 
	cons_formula(coef_A, y, coef_formu, N); 
	convert(coef_formu, N); 
	compute(coef_formu, N, a); 
	
	for(i= 0; i<N+1; i++)
	{
		if(i == 0)
		{
			sprintf(m_OutputPara[0]->paramVal, "%e", a[i]);
		}
		else
		{
			sprintf(m_OutputPara[0]->paramVal, "%s ,%e", m_OutputPara[0]->paramVal, a[i]);
		}
	}
	return NTS_SUCCESS;
}

// M_SPE_GetIDN 
M_SPE_GetIDN::M_SPE_GetIDN()
:BaseMethod()
{
	sprintf(m_MethodScript,"获取设备厂商信息");
	m_InputPara[0] = CreateParamStruct();
	m_InputPara[1] = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_SPE_GetIDN::~M_SPE_GetIDN()
{
//	free(m_InputPara[0]);
//	free(m_InputPara[1]);
//	free(m_OutputPara);
	
}

int M_SPE_GetIDN::Init(void)
{
	sprintf(m_InputPara[0]->paramName, "DevType");
	m_InputPara[0]->paramType = NTSInt16;
	m_InputPara[0]->paramCount = 1;
	sprintf(m_InputPara[0]->paramVal,"");
	sprintf(m_InputPara[0]->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara[0]);
	
	sprintf(m_InputPara[1]->paramName, "ConnectStr");
	m_InputPara[1]->paramType = NTSString;
	m_InputPara[1]->paramCount = 1;
	sprintf(m_InputPara[1]->paramVal,"");
	sprintf(m_InputPara[1]->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara[1]);
	
	
	sprintf(m_OutputPara->paramName, "IDN");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal, "");
	sprintf(m_OutputPara->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}

int M_SPE_GetIDN::Run(void)
{		
	int retVal;
	TDevcieType devType;
	short int vDevHandle = 0;
	TDeviceManagerMap::iterator it; 
	char ConnectStr[100];
	char vIDN[1000] = {0};
	
	devType = (TDevcieType)(atoi(m_InputPara[0]->paramVal));
	sprintf(ConnectStr,m_InputPara[1]->paramVal);	
	switch(devType) 
	{
	case NTS:					//芯通产品
		
	/*
		it = gDeviceManagerMap.find(ConnectStr);
			if (it == gDeviceManagerMap.end() )
			{
				return NTS_INVALID_DEVICE;
			}
			vDevHandle = it->second;
			retVal = NTS_GetIDN(vDevHandle, vIDN);		
			if(retVal != NTS_SUCCESS)
			{
				return retVal;
			}	
	*/	
		sprintf(vIDN, "%s", "");
		break;
	case SG:					//信号源
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{			
			return NTS_INVALID_DEVICE;
		}
		vDevHandle = it->second.DevHandle;
		retVal = SG_GetIDN(vDevHandle, vIDN);		
		if(retVal != NTS_SUCCESS)
		{
			return retVal;
		}		
		break;
	case PSA:					//频谱仪
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{			
			return NTS_INVALID_DEVICE;
		}
		vDevHandle = it->second.DevHandle;
		retVal = PSA_GetIDN(vDevHandle, vIDN);		
		if(retVal != NTS_SUCCESS)
		{
			return retVal;
		}		
		break;
	case ENA:					//网络仪
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{			
			return NTS_INVALID_DEVICE;
		}
		vDevHandle = it->second.DevHandle;
		retVal = ENA_GetIDN(vDevHandle, vIDN);		
		if(retVal != NTS_SUCCESS)
		{
			return retVal;
		}		
		break;
	case NFA:					//噪声仪
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{			
			return NTS_INVALID_DEVICE;
		}
		vDevHandle = it->second.DevHandle;
		retVal = NFA_GetIDN(vDevHandle, vIDN);		
		if(retVal != NTS_SUCCESS)
		{
			return retVal;
		}		
		break;
	case MMT:					//万用表
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{			
			return NTS_INVALID_DEVICE;
		}
		sprintf(vIDN, "%s", "");
		break;
	case SWI:					//矩阵开关
		
		sprintf(vIDN, "%s", "");
		break;
	case DPD:					// 
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{			
			return NTS_INVALID_DEVICE;
		}
		vDevHandle = it->second.DevHandle;
		retVal = DPD_GetIDN(vDevHandle, vIDN);		
		if(retVal != NTS_SUCCESS)
		{
			return retVal;
		}		
		break;	
	case PRM:
		it = gDeviceManagerMap.find(ConnectStr);
		if(it == gDeviceManagerMap.end())
		{			
			return NTS_INVALID_DEVICE;
		}
		vDevHandle = it->second.DevHandle;
		retVal = PRM_GetIDN(vDevHandle, vIDN);		
		if(retVal != NTS_SUCCESS)
		{
			return retVal;
		}		
		break;
	case IRU:				//IRU
	/*
		it = gIRUManager.find(ConnectStr);
			if(it == gIRUManager.end())
			{			
				return NTS_INVALID_DEVICE;
			}
			vDevHandle = it->second;
			retVal = IRU_GetIDN(vDevHandle, vIDN);		
			if(retVal != NTS_SUCCESS)
			{
				return retVal;
			}		
	*/
		sprintf(vIDN, "%s", "");
		break;
	}
	sprintf(m_OutputPara->paramVal, "%s", vIDN);
	return NTS_SUCCESS;
}

// M_SPE_FFT 
M_SPE_FFT::M_SPE_FFT()
:BaseMethod()
{
	sprintf(m_MethodScript,"FFT 算法");
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_SPE_FFT::~M_SPE_FFT()
{
//	free(m_InputPara);
//	free(m_OutputPara);
	
}

int M_SPE_FFT::Init(void)
{
	
	sprintf(m_InputPara->paramName, "TDData");
	m_InputPara->paramType = NTSString;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara);
	
	
	sprintf(m_OutputPara->paramName, "FDData");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal, "");
	sprintf(m_OutputPara->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}

//定义旋转因子
ComplexStruct M_SPE_FFT::Wn(int N, int n)
{
	ComplexStruct out;
	out.re = (float)cos(2*PI*((float)n/(float)N));
	out.im = -(float)sin(2*PI*((float)n/(float)N));
	return out;
}


//复数加法，out=a+b
ComplexStruct M_SPE_FFT::add(ComplexStruct a, ComplexStruct b)
{
	ComplexStruct out;
	out.re=a.re+b.re;
	out.im=a.im+b.im;
	return out;
}

//复数减法，out=a-b
ComplexStruct M_SPE_FFT::sub(ComplexStruct a, ComplexStruct b)
{
	ComplexStruct out;
	out.re=a.re-b.re;
	out.im=a.im-b.im;
	return out;
}
//复数乘法，out=a*b
ComplexStruct M_SPE_FFT::mul(ComplexStruct a, ComplexStruct b)
{
	ComplexStruct out;
	out.re=a.re*b.re-a.im*b.im;
	out.im=a.re*b.im+a.im*b.re;
	return out;
}

//复数求模，out = a*b
double M_SPE_FFT::mod(ComplexStruct a)
{
	double out;
	out = sqrt(a.re*a.re + a.im*a.im);	
	return out;
}

//复数赋值
ComplexStruct M_SPE_FFT::comcpy(ComplexStruct a)
{
	ComplexStruct out;
	out.re=a.re;
	out.im=a.im;
	return out;
}

// 倒位
int M_SPE_FFT::reverse(int n, int j)
{
	int  i,k,power;
	power = (int)(log(n+1)/log(2));
	k=0;
	for(i=0;i<power;i++)//检查每个为0~power-1
		if(j&(1<<i))
			k+=1<<(power-i-1);//如果正序数中位i的值为1，则倒序数中power-i-1的相应位置1。
		return k; 
}

// FFT 算法
int M_SPE_FFT::DoFFT(ComplexStruct *x, ComplexStruct *F, int N)
{
	int K = (int)(log(N+1)/log(2));
	int i,j,m;
	for(m=1;m<=K;m++)
	{
		for(i=0;i<(1<<K);i+=1<<m)
		{
			for(j=0;j<(1<<(m-1));j++)
			{
				F[i+j] = add(x[i+j], mul(x[i+j+(1<<(m-1))], Wn(1<<m,j)));
				F[i+j+(1<<(m-1))] = sub(x[i+j], mul(x[i+j+(1<<(m-1))], Wn(1<<m,j)));
			} 
		}
		for(i=0;i<N;i++)
		{
			x[i] = comcpy(F[i]);
		}
	}
	return NTS_SUCCESS;
}

int M_SPE_FFT::Run(void)
{		
	long Count;
	int power;
	int i, j, strLength;
	char *TmpStr = NULL;
	float Data[10000] = {0};
	char RetStr[40000] = {0};
	int res;
	ComplexStruct *x,*F;
	
	if (m_InputPara->LparamVal != NULL)
	{
		strLength = strlen(m_InputPara->LparamVal);
		TmpStr = (char *) malloc((strLength + 10)*sizeof(char));
		sprintf(TmpStr , "%s", m_InputPara->LparamVal);		
	}
	else
	{
		strLength = strlen(m_InputPara->paramVal);
		TmpStr = (char *) malloc((strLength + 10)*sizeof(char));
		sprintf(TmpStr , "%s", m_InputPara->paramVal);
	}
	__try
	{	
		//分离DA值
		Data[0] = atof(&TmpStr[0]);
		for(i = 1, j = 1; i<strLength; i++)
		{
			if (TmpStr[i] == ',')
			{
				Data[j] = atof(&TmpStr[i+1]);
				j++;
			}
		}
		// 如果采样数N不是2^n的整数倍,则需要将采样数补足整数倍
		Count = j;
		power = (int)(log(Count)/log(2));
		if((long)pow(2, power) < Count)
		{
			Count = pow(2, power + 1);
		}
		x = new ComplexStruct[Count];
		F = new ComplexStruct[Count];
		for(i=0; i<Count; i++)
		{
			x[i].re = Data[i];
			x[i].im = 0;	
		}
		// 倒序
		for(i=0; i<Count; i++)
		{
			F[i] = comcpy(x[reverse(Count, i)]);
		}
		for(i=0; i<Count; i++)
		{
			x[i]=comcpy(F[i]);
		}
		res = DoFFT(x, F, Count);
		if(res == NTS_SUCCESS)
		{
			
			for(i = 0; i < Count; i++)
			{
				Data[0] = mod(F[i]);
				if (i = 0)
				{
					sprintf(RetStr, "%e", Data[i]);
				}
				else
				{
					sprintf(RetStr, "%s,%e", RetStr, Data[i]);
				}
			}
			if (strlen(RetStr) > PARALENGTH)
			{		
				m_OutputPara->LparamVal = (char *)malloc((strlen(RetStr) + 10)*sizeof(char));
				sprintf(m_OutputPara->LparamVal, "%s", RetStr);
			}
			else
			{
				sprintf(m_OutputPara->paramVal, "%s", RetStr);
			}
			//sprintf()	
		}
		return res;
	}
	__finally
	{
		//释放内存
		free(TmpStr);
	}	
	return NTS_SUCCESS;
}

// M_SPE_GetLastErrStr 
M_SPE_GetLastErrStr::M_SPE_GetLastErrStr()
:BaseMethod()
{
	sprintf(m_MethodScript,"获取最近出错信息");
	m_InputPara = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}

M_SPE_GetLastErrStr::~M_SPE_GetLastErrStr()
{
//	free(m_InputPara);
//	free(m_OutputPara);
	
}

int M_SPE_GetLastErrStr::Init(void)
{
	
	sprintf(m_InputPara->paramName, "ErrCode");
	m_InputPara->paramType = NTSInt16;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"0");
	sprintf(m_InputPara->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara);
	
	
	sprintf(m_OutputPara->paramName, "ErrorMessage");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal, "");
	sprintf(m_OutputPara->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}

int M_SPE_GetLastErrStr::Run()
{
	int vErrorCode;
	char vErrorStr[2000] = {0};
	
	vErrorCode = atoi(m_InputPara->paramVal);
	NTS_GetLastErrStr(vErrorCode, vErrorStr);
	sprintf(m_OutputPara->paramVal, "%s", vErrorStr);
	return NTS_SUCCESS;
}


// M_SPE_SetAttributeDev  
M_SPE_SetAttributeDev::M_SPE_SetAttributeDev()
:BaseMethod()
{
	sprintf(m_MethodScript,"设置通信属性参数");
	m_DevName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_SPE_SetAttributeDev::~M_SPE_SetAttributeDev()
{
//	free(m_DevName);
//	free(m_InputPara1);
//	free(m_InputPara2);
	
}

int M_SPE_SetAttributeDev::Init(void)
{	
	sprintf(m_DevName->paramName, "ConnectStr");
	m_DevName->paramType = NTSString;
	m_DevName->paramCount = 1;
	sprintf(m_DevName->paramVal,"");
	sprintf(m_DevName->paramUnit , "");
	m_InputParamVector.push_back(m_DevName);
	
	sprintf(m_InputPara1->paramName, "attrName");
	m_InputPara1->paramType = NTSString;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"CommIsStr");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "AttrState");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal, "0");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	return NTS_SUCCESS;
}

int M_SPE_SetAttributeDev::Run()
{
	int vCommIsStrFlag;
	
	vCommIsStrFlag = atoi(m_InputPara2->paramVal);
	return SetAttributeDev(m_DevName->paramVal, m_InputPara1->paramVal,  vCommIsStrFlag);
	
	
	return NTS_SUCCESS;
}

// M_SPE_AgePowerOn 节点上电
M_SPE_AgePowerOn::M_SPE_AgePowerOn()
:BaseMethod()
{
	sprintf(m_MethodScript,"节点上电");

	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	Init();
}

M_SPE_AgePowerOn::~M_SPE_AgePowerOn()
{
//	free(m_DevName);
///	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara1);
	
}

int M_SPE_AgePowerOn::Init(void)
{	
	sprintf(m_InputPara1->paramName, "CardID");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "NodeID");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal, "1");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara1->paramName, "Result");
	m_OutputPara1->paramType = NTSInt16;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal, "1");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}

int M_SPE_AgePowerOn::Run()
{
	
	return NTS_SUCCESS;
}

// M_SPE_AgePowerOff 
M_SPE_AgePowerOff::M_SPE_AgePowerOff()
:BaseMethod()
{
	sprintf(m_MethodScript,"节点关电");
//	m_DevName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();

	Init();
}

M_SPE_AgePowerOff::~M_SPE_AgePowerOff()
{
//	free(m_DevName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara1);
	
}

int M_SPE_AgePowerOff::Init(void)
{	
	sprintf(m_InputPara1->paramName, "CardID");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "NodeID");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal, "1");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara1->paramName, "Result");
	m_OutputPara1->paramType = NTSInt16;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal, "1");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	return NTS_SUCCESS;
}

int M_SPE_AgePowerOff::Run()
{

	return NTS_SUCCESS;
}

// M_SPE_AgeRead 读取数据
M_SPE_AgeRead::M_SPE_AgeRead()
:BaseMethod()
{
	sprintf(m_MethodScript,"读取数据");
//	m_DevName = CreateParamStruct();
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	m_OutputPara2 = CreateParamStruct();
	m_OutputPara3 = CreateParamStruct();
	Init();
}

M_SPE_AgeRead::~M_SPE_AgeRead()
{
//	free(m_DevName);
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara1);
//	free(m_OutputPara2);
//	free(m_OutputPara3);
	
}

int M_SPE_AgeRead::Init(void)
{	
	sprintf(m_InputPara1->paramName, "CardID");
	m_InputPara1->paramType = NTSInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"1");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "NodeID");
	m_InputPara2->paramType = NTSInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal, "1");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	
	sprintf(m_OutputPara1->paramName, "AgeData");
	m_OutputPara1->paramType = NTSString;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal, "");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);

	sprintf(m_OutputPara2->paramName, "AgeState");
	m_OutputPara2->paramType = NTSInt16;
	m_OutputPara2->paramCount = 1;
	sprintf(m_OutputPara2->paramVal, "1");
	sprintf(m_OutputPara2->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara2);

	sprintf(m_OutputPara3->paramName, "AlarmMsg");
	m_OutputPara3->paramType = NTSString;
	m_OutputPara3->paramCount = 1;
	sprintf(m_OutputPara3->paramVal, "");
	sprintf(m_OutputPara3->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara3);
	
	return NTS_SUCCESS;
}

int M_SPE_AgeRead::Run()
{	
	return NTS_SUCCESS;
}


// 向I/O口写数据 
M_SPE_SetIOPortVal::M_SPE_SetIOPortVal()
:BaseMethod()
{
	sprintf(m_MethodScript,"向I/O口写数据");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_InputPara3 = CreateParamStruct();
	Init();
}

M_SPE_SetIOPortVal::~M_SPE_SetIOPortVal()
{
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_InputPara3);
}

int M_SPE_SetIOPortVal::Init(void)
{	
	sprintf(m_InputPara1->paramName, "PortAddr");
	m_InputPara1->paramType = NTSUInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"888");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "PortVal");
	m_InputPara2->paramType = NTSUInt32;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal, "0");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_InputPara3->paramName, "Size");
	m_InputPara3->paramType = NTSUInt8;
	m_InputPara3->paramCount = 1;
	sprintf(m_InputPara3->paramVal, "1");
	sprintf(m_InputPara3->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara3);
	
	return NTS_SUCCESS;
}

int M_SPE_SetIOPortVal::Run()
{	
	WORD vPortAddr;
	DWORD vPortVal;
	BYTE vSize;

	vPortAddr = atoi(m_InputPara1->paramVal);
	vPortVal = atoi(m_InputPara2->paramVal);
	vSize = atoi(m_InputPara3->paramVal);

	return NTS_SetIOPortVal(vPortAddr, vPortVal, vSize);

	return NTS_SUCCESS;
}

M_SPE_GetIOPortVal::M_SPE_GetIOPortVal()
:BaseMethod()
{
	sprintf(m_MethodScript,"从I/O读取数据");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	m_OutputPara1 = CreateParamStruct();
	Init();
}

M_SPE_GetIOPortVal::~M_SPE_GetIOPortVal()
{
//	free(m_InputPara1);
//	free(m_InputPara2);
//	free(m_OutputPara1);
}

int M_SPE_GetIOPortVal::Init(void)
{	
	sprintf(m_InputPara1->paramName, "PortAddr");
	m_InputPara1->paramType = NTSUInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"888");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);

	sprintf(m_InputPara2->paramName, "Size");
	m_InputPara2->paramType = NTSUInt8;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal, "1");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);
	
	sprintf(m_OutputPara1->paramName, "PortVal");
	m_OutputPara1->paramType = NTSUInt32;
	m_OutputPara1->paramCount = 1;
	sprintf(m_OutputPara1->paramVal, "");
	sprintf(m_OutputPara1->paramUnit, "");
	m_OutputParamVector.push_back(m_OutputPara1);
	
	
	
	return NTS_SUCCESS;
}

int M_SPE_GetIOPortVal::Run()
{	
	WORD vPortAddr;
	DWORD vPortVal = 0;
	BYTE vSize;
	int res;
	
	vPortAddr = atoi(m_InputPara1->paramVal);
	vSize = atoi(m_InputPara2->paramVal);

	res = NTS_GetIOPortVal(vPortAddr, &vPortVal, vSize);
	if (res == NTS_SUCCESS)
	{
		sprintf(m_OutputPara1->paramVal, "%d", vPortVal);
	}
	
	return res;
}

// 设置T/R组件并口数据(Pin2:Data Pin3:CLK Pin4:Lock)
M_SPE_SetIOTRBits::M_SPE_SetIOTRBits()
:BaseMethod()
{
	sprintf(m_MethodScript,"设置T/R组件并口数据(Pin2:Data Pin3:CLK Pin4:Lock)");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_SPE_SetIOTRBits::~M_SPE_SetIOTRBits()
{
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_SPE_SetIOTRBits::Init(void)
{	
	sprintf(m_InputPara1->paramName, "PortAddr");
	m_InputPara1->paramType = NTSUInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"888");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "DataBits");
	m_InputPara2->paramType = NTSString;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal, "");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);	

	return NTS_SUCCESS;
}

int M_SPE_SetIOTRBits::Run()
{	
	WORD vPortAddr;
	DWORD vPortVal = 0;
	int res;
	
	vPortAddr = atoi(m_InputPara1->paramVal);
	
	res = NTS_SetIOTRBits(vPortAddr, m_InputPara2->paramVal);
	return res;
}

// 设置IO触发方式 0:Positive(上升沿) 1:Negative(下降沿)
M_SPE_SetIOTrigPolarity::M_SPE_SetIOTrigPolarity()
:BaseMethod()
{
	sprintf(m_MethodScript,"设置IO触发方式 0:Positive(上升沿) 1:Negative(下降沿)");
	m_InputPara1 = CreateParamStruct();
	m_InputPara2 = CreateParamStruct();
	Init();
}

M_SPE_SetIOTrigPolarity::~M_SPE_SetIOTrigPolarity()
{
//	free(m_InputPara1);
//	free(m_InputPara2);
}

int M_SPE_SetIOTrigPolarity::Init(void)
{	
	sprintf(m_InputPara1->paramName, "PortAddr");
	m_InputPara1->paramType = NTSUInt16;
	m_InputPara1->paramCount = 1;
	sprintf(m_InputPara1->paramVal,"4");
	sprintf(m_InputPara1->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara1);
	
	sprintf(m_InputPara2->paramName, "Polarity");
	m_InputPara2->paramType = NTSUInt16;
	m_InputPara2->paramCount = 1;
	sprintf(m_InputPara2->paramVal, "0");
	sprintf(m_InputPara2->paramUnit, "");
	m_InputParamVector.push_back(m_InputPara2);	
	
	return NTS_SUCCESS;
}

int M_SPE_SetIOTrigPolarity::Run()
{	
	WORD vPin;
	DWORD vPolarity = 0;
	int res;
	
	vPin = atoi(m_InputPara1->paramVal);
	vPolarity = atoi(m_InputPara2->paramVal);
	res = NTS_SetIOTrigPolarity(vPin, vPolarity);
	return res;
}