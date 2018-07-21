// NTSDriver.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#pragma warning( disable : 4786)
#include <string>
#include "NTSScriptLib.h"
#include "Method.h"
#include "MethodFactory.h"
#include <map>
#include "DllAnalyse.h"
#include "ComFunction.h"



// ȫ�ֱ�������
extern BaseMethod *gMethodDev[MAXMETHOD + 1];	// �������
extern TDeviceManagerMap gDeviceManagerMap;	// �豸���������
//void * g_pMemAddr;						// �������Ϊָ��ʱ������ֵ�Ĵ�ȡ��ַ 
extern BOOL gCommIsStr;						// ͨ�ö�д�������ݷ��ͷ�ʽ True:�ַ���	false:������

//��ȡPSA�豸�������ַ���
int GetConnectStrOfPSA(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

//��ȡSG�豸�������ַ���
int GetConnectStrOfSG(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

//��ȡENA�豸�������ַ���
int GetConnectStrOfENA(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

//��ȡNFA�豸�������ַ���
int GetConnectStrOfNFA(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

// ��ȡPRM�豸�������ַ���
int GetConnectStrOfPRM(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

// ��ȡIRU�豸�������ַ���
int GetConnectStrOfIRU(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

//��ȡDPD�豸�������ַ���
int GetConnectStrOfDPD(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

//��ȡDWG�豸�������ַ���
int GetConnectStrOfDWG(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);

//��ȡOSC�豸�������ַ���
int GetConnectStrOfOSC(int Interface, char *inParaStr, char *ProductName, char *ConnentStr);
/******************************************************************************
* ��������:  
* ����:	 dolob.jiang
* ����  2009.12.12
* ����: 
* ����:  ��ʼ��������
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     InitMethodLib()
{	
	MethodFactory *pMethodFactory = NULL;
	pMethodFactory = MethodFactory::GetInstance();	
	//��վ������
	gDeviceManagerMap.clear();
	return NTS_SUCCESS;
}


/******************************************************************************
* ��������:  OpenDevice
* ����:	 dolob.jiang
* ����  2009.12.12
* ����: int devType, char *ConnectStr, short int *devHandle
* ����:  ���豸
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     OpenDevice(int devType, char *ConnectStr, int *devHandle)
{
	int retVal;
	ViSession rmHandle, vDevHandle;
	DeviceInfoStruct vDeviceInfoStruct;
	TDeviceManagerMap::iterator it; 

	std::string protoclString(ConnectStr);
	std::string tmpString, vManalfacotoryName;
	std::vector<std::string> subProtocls;
	std::string::size_type pos = 0, oldPos = 0;
	int SectionCount, i;
	char tmpStr[100], vParentConnStr[200], vSubConnStr[200];
	char ErrMsg[1024] = {0};

	
	if (ConnectStr == 0)
	{
		return NTS_INVALID_PARA;
	}
	*devHandle = -1;
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
	
	// �������ַ���
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
	
	SectionCount = subProtocls.size();
	if(SectionCount != 1 && SectionCount != 5 && SectionCount != 6 && SectionCount != 7)
	{
		sprintf(ErrMsg, "����������ַ�������(����::�ͺ�::�ӿ�::��ַ����::�̶�ֵ)");
		NTS_Error(ErrMsg);
		return NTS_INVALID_PROTOCL;
	}


	switch(devType) 
	{
	case NCARD:				// ͨ�ýӿڿ�
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		
		retVal = NC_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = LAN;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;	
		}
		break;

	case NTS:				//оͨ��Ʒ		
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}				
		sprintf(tmpStr, subProtocls[SectionCount - 1].c_str());		
		if(strcmp(tmpStr, "CAL") == 0 )	       //У׼
		{
			retVal = AD_OpenDev(ConnectStr, (short int *)devHandle);			
		}
		else if(strcmp(tmpStr, "DEB") == 0 )	//����
		{
			retVal = AD_OpenDev(ConnectStr, (short int *)devHandle);	
		}
		else if(strcmp(tmpStr, "TESTCARD") == 0 )	//ͨ�ò��Կ�
		{
			retVal = TC_OpenDev(ConnectStr, (short int *)devHandle);	
		}
		else								   //����
		{
			retVal = NTS_OpenDev(ConnectStr, (short int *)devHandle);		
		}
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = COM;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}
		break;
	case SG:				//�ź�Դ
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
	
		retVal = SG_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;	
		}
		break;
	case PSA:				//Ƶ����
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		retVal = PSA_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;	
		}
		break;
	case ENA:				//������
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		retVal = ENA_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;	
		}
		break;
	case NFA:				//������
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}	
		
		retVal = NFA_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}
		break;
	case MMT:				//���ñ�
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}	
		retVal = MMT_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = COM;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}	
		break;
	case SWI:				//���󿪹�
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}	
		retVal = SW_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = COM;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}	
		break;
	case DPD:				//DPD
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}	
		retVal = DPD_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = LAN;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}	
		break;
	case PRM:				//���ʼ�
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}	
		retVal = PRM_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}	
		break;
	case IRU:				//IRU
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		retVal = IRU_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = LAN;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
		}	
		break;

	case DWG:				//DWG
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		retVal = DWG_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;	
		}
		break;

	case OSC:				//OSC
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		retVal = OSC_OpenDev(ConnectStr, (short int *)devHandle);
		if(retVal == NTS_SUCCESS)
		{
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = GPIB;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;	
		}
		break;

	default:			// �Զ����豸
		it = gDeviceManagerMap.find(ConnectStr);
		if(it != gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "�豸%s%s", ConnectStr, "�Ѿ�����");
			NTS_Info(ErrMsg);
			*devHandle = it->second.DevHandle;
			return NTS_SUCCESS;
		}
		// �ж�ͨѶ�ӿ�����
		if (SectionCount == 1)
		{
			// ֻ��com֧�ֶ�����
			tmpString = subProtocls[0];	
		}
		else
		{
			vManalfacotoryName = subProtocls[0];			
			tmpString = subProtocls[2];			
		}
		
		if (vManalfacotoryName.find("NTS") != std::string::npos) 
		{
			// ����NTS������
			return OpenDevice(101, ConnectStr, devHandle);
		}
		pos = tmpString.find("GPIB");
		if(pos != std::string::npos)					// GPIB
		{
			// ���ݸ�ʽҪ����֯�����ַ���
			for(i = 2; i < SectionCount; i++) 
			{
				if(i == 2)
				{
					sprintf(tmpStr, "%s", subProtocls[i].c_str());
				}
				else
				{
					sprintf(tmpStr, "%s::%s", tmpStr, subProtocls[i].c_str() );
					
				}
			}	
			retVal = viGetDefaultRM(&rmHandle);
			if(retVal < VI_SUCCESS)
			{
				return NTS_INVALID_DEVICE;
			}
			retVal = viOpen(rmHandle, tmpStr, VI_NULL, VI_NULL, &vDevHandle);
			if(retVal == VI_SUCCESS)
			{	
				// �򿪳ɹ�
				*devHandle = vDevHandle;
				sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
				vDeviceInfoStruct.DevHandle = vDevHandle;
				vDeviceInfoStruct.DeviceType = devType;
				vDeviceInfoStruct.InterFaceType = GPIB;
				gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;				
				retVal = NTS_SUCCESS;					
			}
			else
			{
				retVal = NTS_INVALID_DEVICE;
			}
			break;
		}
		pos = tmpString.find("TCPIP");
		if(pos != std::string::npos)					// TCPIP
		{
			tmpString = subProtocls[4];
			pos = tmpString.find("SOCKET");
			if (pos != std::string::npos)				// 
			{
				// ���ݸ�ʽҪ����֯�����ַ���				
				retVal = NTS_OpenLan(ConnectStr, (short int *)devHandle);
				if (retVal != NTS_SUCCESS)
				{
					sprintf(ErrMsg, "��%s�豸ʧ��", ConnectStr);
					NTS_Error(ErrMsg);
					return NTS_INVALID_DEVICE;
				}				
				sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
				vDeviceInfoStruct.DevHandle = *devHandle;
				vDeviceInfoStruct.DeviceType = devType;
				vDeviceInfoStruct.InterFaceType = LAN;
				gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
				break;	
			}
			else 
			{
				// ���ݸ�ʽҪ����֯�����ַ���
				sprintf(tmpStr, "%s::%s::%s", subProtocls[2].c_str(), subProtocls[3].c_str(), subProtocls[4].c_str());
				retVal = viGetDefaultRM(&rmHandle);
				if(retVal < VI_SUCCESS)
				{
					return NTS_INVALID_DEVICE;
				}
				retVal = viOpen(rmHandle, tmpStr, VI_NULL, VI_NULL, &vDevHandle);
				if(retVal == VI_SUCCESS)
				{	
					// �򿪳ɹ�
					*devHandle = vDevHandle;
					sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
					vDeviceInfoStruct.DevHandle = *devHandle;
					vDeviceInfoStruct.DeviceType = devType;
					vDeviceInfoStruct.InterFaceType = LAN;
					gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
					retVal = NTS_SUCCESS;					
				}
				else
				{
					retVal = NTS_INVALID_DEVICE;
				}
			}	
			break;
		}

		pos = tmpString.find("COM");
		if(pos != std::string::npos)					// COM
		{
			// ���ݸ�ʽҪ����֯�����ַ���		
			retVal = NTS_OpenCom(ConnectStr, (short int *)devHandle);
			if (retVal != NTS_SUCCESS)
			{
				sprintf(ErrMsg, "��%s�豸ʧ��", ConnectStr);
				NTS_Error(ErrMsg);
				return NTS_INVALID_DEVICE;
			}			
			sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
			vDeviceInfoStruct.DevHandle = *devHandle;
			vDeviceInfoStruct.DeviceType = devType;
			vDeviceInfoStruct.InterFaceType = COM;
			gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;
			break;			
		}
		pos = tmpString.find("USB");
		if(pos != std::string::npos)					// USB
		{
			// ���ݸ�ʽҪ����֯�����ַ���
			sprintf(tmpStr, "%s::%s::%s::%s::%s", subProtocls[2].c_str(), subProtocls[3].c_str(), subProtocls[4].c_str(),
				subProtocls[5].c_str(), subProtocls[6].c_str());
			retVal = viGetDefaultRM(&rmHandle);
			if(retVal < VI_SUCCESS)
			{
				return NTS_INVALID_DEVICE;
			}
			retVal = viOpen(rmHandle, tmpStr, VI_NULL, VI_NULL, &vDevHandle);
			if(retVal == VI_SUCCESS)
			{	
				// �򿪳ɹ�
				*devHandle = vDevHandle;
				sprintf(vDeviceInfoStruct.ConnectSrt, "%s", ConnectStr);
				vDeviceInfoStruct.DevHandle = vDevHandle;
				vDeviceInfoStruct.DeviceType = devType;
				vDeviceInfoStruct.InterFaceType = GPIB;
				gDeviceManagerMap[ConnectStr] = vDeviceInfoStruct;				
				retVal = NTS_SUCCESS;					
			}
			else
			{
				retVal = NTS_INVALID_DEVICE;
			}
			break;
		}
		else
		{
			sprintf(ErrMsg, "��ʱ����֧�ָýӿ�!");
			NTS_Error(ErrMsg);
			return NTS_INVALID_PARA;
		}
		break;
	}
	if (retVal != NTS_SUCCESS)
	{
		sprintf(ErrMsg, "��%s�豸ʧ��", ConnectStr);
		NTS_Error(ErrMsg);
	}
	return retVal;
}

/******************************************************************************
* ��������:  CloseDevice
* ����:	 dolob.jiang
* ����  2009.12.12
* ����: TDevcieType devType, char *ConnectStr
* ����:  �ر��豸
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     CloseDevice(int devType, char *ConnectStr)
{
	int retVal;
	TDeviceManagerMap::iterator it; 
	unsigned long DevHandle = -1;
	TInterfaceType vIType;

	std::string protoclString(ConnectStr);
	std::string tmpString, vManalfacotoryName;
	std::vector<std::string> subProtocls;
	std::string::size_type pos = 0, oldPos = 0;
	int SectionCount;
	char tmpStr[200] = {0};
	char ErrMsg[1024] = {0};
	char vParentConnectStr[500] = {0};
//	char vChildConnectStr[500] = {0};
	
	if (ConnectStr == 0)
	{
		return NTS_INVALID_PARA;
	}
	// ��ȡ�������ַ���
	NTS_SeparateStr(ConnectStr, "," , &subProtocls);
	if (subProtocls.size() < 1)
	{
		return NTS_INVALID_PROTOCL;
	}
	else
	{
		sprintf(vParentConnectStr, "%s", subProtocls[0].c_str());
		protoclString = vParentConnectStr;
	}
	
	subProtocls.clear();
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
	SectionCount = subProtocls.size();
	if (SectionCount != 1 && SectionCount != 5 && SectionCount != 6 && SectionCount != 7)
	{
		return NTS_INVALID_PROTOCL;
	}
	switch(devType) 
	{
	case NCARD:
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = NC_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;

	case NTS:					//оͨ��Ʒ
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		sprintf(tmpStr, subProtocls[SectionCount - 1].c_str());		
		if(strcmp(tmpStr, "CAL") == 0 )	       //У׼
		{
			retVal = AD_CloseDev(DevHandle);
		}
		else if(strcmp(tmpStr, "DEB") == 0 )	//����
		{
			retVal = AD_CloseDev(DevHandle);
		}
		else if(strcmp(tmpStr, "TESTCARD") == 0 )	//ͨ�ò��Կ�
		{
			retVal = TC_CloseDev(DevHandle);
		}
		else								   //����
		{
			retVal = NTS_CloseDev(DevHandle);
		}
		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;
	case SG:					//�ź�Դ
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = SG_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;
	case PSA:					//Ƶ����
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = PSA_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}		
		break;
	case ENA:					//������
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = ENA_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}		
		break;
	case NFA:					//������
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = NFA_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}		
		break;
	case MMT:					//���ñ�
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = MMT_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;
	case SWI:					//���󿪹�
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = SW_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;
	case DPD:					//���󿪹�
		it = gDeviceManagerMap.find(ConnectStr);
		if (it == gDeviceManagerMap.end() )
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = DPD_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;	
	case PRM:
		it = gDeviceManagerMap.find(ConnectStr);
		if(it == gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = PRM_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;
	case IRU:				//IRU
		it = gDeviceManagerMap.find(ConnectStr);
		if(it == gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = IRU_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;

	case DWG:				//DWG
		it = gDeviceManagerMap.find(ConnectStr);
		if(it == gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = DWG_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;

	case OSC:				//OSC
		it = gDeviceManagerMap.find(ConnectStr);
		if(it == gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		retVal = OSC_CloseDev(DevHandle);		
		if(retVal == NTS_SUCCESS)
		{
			gDeviceManagerMap.erase(it); 
		}
		break;


	default:				// �Զ����豸
		// �ж�ͨѶ�ӿ�����
		if (SectionCount == 1)
		{
			// ֻ��com֧�ֶ�����
			tmpString = subProtocls[0];	
		}
		else
		{
			vManalfacotoryName = subProtocls[0];			
			tmpString = subProtocls[3];			
		}
		if (vManalfacotoryName.find("NTS") != std::string::npos) 
		{
			// ����NTS������
			return CloseDevice(101, ConnectStr);
		}

		it = gDeviceManagerMap.find(ConnectStr);
		if(it == gDeviceManagerMap.end())
		{
			sprintf(ErrMsg, "%s%s", ConnectStr, "�豸û�б��򿪻����Ѿ��ر���");
			NTS_Info(ErrMsg);
			return NTS_INVALID_OPERATE;
		}
		DevHandle = it->second.DevHandle;
		vIType = (TInterfaceType)it->second.InterFaceType;
		switch(vIType)
		{
		case GPIB:
			retVal = viClose(DevHandle);
			if(retVal < VI_SUCCESS)
			{		
				return NTS_INVALID_OPERATE;
			}
			break;

		case LAN:
			tmpString = subProtocls[4];
			pos = tmpString.find("SOCKET");
			if (pos != std::string::npos)				// 
			{
				// ���ݸ�ʽҪ����֯�����ַ���
				retVal = NTS_CloseLan(DevHandle);
				if(retVal != NTS_SUCCESS)
				{		
					return NTS_INVALID_OPERATE;
				}
				break;	
			}
			else 
			{
				retVal = viClose(DevHandle);
				if(retVal < VI_SUCCESS)
				{		
					return NTS_INVALID_OPERATE;
				}
			}
				
			break;

		case COM:
			retVal = NTS_CloseCom(DevHandle);
			if(retVal != NTS_SUCCESS)
			{		
				return NTS_INVALID_OPERATE;
			}
			break;

		case USB:
			retVal = viClose(DevHandle);
			if(retVal < VI_SUCCESS)
			{		
				return NTS_INVALID_OPERATE;
			}
			break;

		default:
			return NTS_INVALID_OPERATE;
			break;
		}
		
		gDeviceManagerMap.erase(it); 
		retVal = NTS_SUCCESS;
		break;
	}

	if (retVal != NTS_SUCCESS)
	{
		sprintf(ErrMsg, "�ر�%s�豸ʧ��", ConnectStr);
		NTS_Error(ErrMsg);
	}
	return retVal;
}

/******************************************************************************
* ��������:  GetDriverTypeName
* ����:	 dolob.jiang
* ����  2009.12.12
* ����: char **name, unsigned long *count
* ����:  ��ȡ������������
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     GetDriverTypeName(char **name, unsigned long *count)
{
	char DevName[50][50] = {0};
	int tmpcount = 0 ;
	
	sprintf(DevName[0],"оͨ��Ʒ����");
	sprintf(DevName[1],"�ź�Դ����");
	sprintf(DevName[2],"Ƶ���Ƿ���");
	sprintf(DevName[3],"�����Ƿ���");
	sprintf(DevName[4],"�����Ƿ���");
	sprintf(DevName[5],"�ۺϷ���");
	sprintf(DevName[6],"�������ñ�����");
	sprintf(DevName[7],"���󿪹ط���");
	sprintf(DevName[8],"DPD�巽��");
	sprintf(DevName[9],"���ʼƷ���");
	sprintf(DevName[10],"IRU����");
	sprintf(DevName[11],"���Կ�����");
	sprintf(DevName[12],"NCARD����");
	sprintf(DevName[13],"AUT����");
	sprintf(DevName[14],"���η���������");
	sprintf(DevName[15],"ʾ��������");
	tmpcount = 16;
	for(int i = 0;i<tmpcount;i++)
	{
		*(name+i)  = *(DevName+i);
	}
	*count = tmpcount;
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetDevice
* ����:	 dolob.jiang
* ����  2009.12.12
* ����: char **name, unsigned long *count
* ����:  ��ȡ�豸����
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     GetDevice(char **name, unsigned long *count)
{
	char DevName[50][100] = {0};
	int tmpcount = 0 ;
/*
	sprintf(DevName[0],"NTSDevice");
	sprintf(DevName[1],"SGDevice(�ź�Դ)");
	sprintf(DevName[2],"PSADevice(Ƶ����)");	
	sprintf(DevName[3],"ENADevice(ʸ��)");
	sprintf(DevName[4],"NFADevice(������)");
	sprintf(DevName[5],"MMTDevice(���ñ�)");
	sprintf(DevName[6],"SWIDevice(NTS���󿪹�)");
	sprintf(DevName[7],"DPDDevice(DPD��װ)");
	sprintf(DevName[8],"PRMDevice(���ʼ�)");
	sprintf(DevName[9],"IRUDevice(BBU��װ)");
	sprintf(DevName[10],"NCardDevice(NTSͨ�ÿ�)");
 	sprintf(DevName[11],"ExDevice(��չ�豸)");
*/

	sprintf(DevName[0],"NTSDevice");
	sprintf(DevName[1],"SGDevice");
	sprintf(DevName[2],"PSADevice");	
	sprintf(DevName[3],"ENADevice");
	sprintf(DevName[4],"NFADevice");
	sprintf(DevName[5],"MMTDevice");
	sprintf(DevName[6],"SWIDevice");
	sprintf(DevName[7],"DPDDevice");
	sprintf(DevName[8],"PRMDevice");
	sprintf(DevName[9],"IRUDevice");
	sprintf(DevName[10],"NCardDevice");
	sprintf(DevName[13],"ExDevice");
	sprintf(DevName[11],"DWGDevice");
	sprintf(DevName[12],"OSCDevice");

	tmpcount = 14;
	for(int i = 0;i<tmpcount;i++)
	{
		*(name+i)  = *(DevName+i);
	}
	*count = tmpcount;
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetAllMethod
* ����:	 dolob.jiang
* ����  2009.12.12
* ����: char *(methodName[50]), unsigned long *count
* ����:  ��ȡ�����������е������ⷽ��
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     GetAllMethod(char *(methodName[50]), unsigned long *count)
{
	TMethodMap::iterator it;
	MethodNameStruct m_MethodSet;
	std::string Key;
	char FunName[3000][100] = {0};
	int i = 0;
	char ErrMsg[1024];
	MethodFactory *pMethodFactory = NULL;
	pMethodFactory = MethodFactory::GetInstance();	
	if ( pMethodFactory == NULL)
	{
		sprintf(ErrMsg, "%s", "������ʵ��δ��ʼ��!");
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}
	it = pMethodFactory->m_MethodMap.begin();
	while(it != pMethodFactory->m_MethodMap.end())
	{
		m_MethodSet = it->second;
		if(m_MethodSet.Visable == 1)
		{
			Key = it->first;
			sprintf(FunName[i], "%s", Key.c_str());
			*(methodName + i) = *(FunName+i);		
			i++;
		}
		it++;
	}
	*count = i;

	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetMethodEx
* ����:	 dolob.jiang
* ����  2009.12.12
* ����: int MethodType, char *(methodName[50]), unsigned long *count
* ����:  ��ȡĳ���豸�������ⷽ��
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     GetMethodEx(int MethodType, char *(methodName[50]), unsigned long *count)
{
	TMethodMap::iterator it;
	std::string tmpStr;
	MethodNameStruct m_MethodSet;
	char FunName[1000][100] = {0};
	char ErrMsg[1024];
	std::string::size_type pos =0;
	char flagHead[10];
	int i = 0;
	int tmpcount;
	

	switch(MethodType)
	{
	case NTSMethod:
		sprintf(flagHead, "NTS_");
		break;
		
	case SGMethod:
		sprintf(flagHead, "SG_");
		break;

	case NFAMethod:
		sprintf(flagHead, "NFA_");
		break;

	case PSAMethod:
		sprintf(flagHead, "PSA_");
		break;

	case ENAMethod:
		sprintf(flagHead, "ENA_");
		break;

	case SPEMethod:
		sprintf(flagHead, "SPE_");
		break;

	case MMTMethod:
		sprintf(flagHead, "MMT_");
		break;

	case DEBMethod:			//����
		sprintf(flagHead, "DEB_");
		break;

	case ADJMethod:			//У׼
		sprintf(flagHead, "ADJ_");
		break;

	case SWIMethod:
		sprintf(flagHead, "SW_");
		break;

	case DPDMethod:
		sprintf(flagHead, "DPD_");
		break;

	case PRMMethod:			//���ʼ�
		sprintf(flagHead, "PRM_");
		break;

	case IRUMethod:			//IRU
		sprintf(flagHead, "IRU_");
		break;

	case TCMethod:			//���Կ�
		sprintf(flagHead, "TC_");
		break;

	case NCMethod:			// NCARD ͨ�ýӿڿ�
		sprintf(flagHead, "NC_");
		break;
		
	case AU3Method:			// AutoIT �ӿ�
		sprintf(flagHead, "AU3_");
		break;

	case DWGMethod:			// DWG�ӿ�
		sprintf(flagHead, "DWG_");
		break;

	case OSCMethod:			// OSC�ӿ�
		sprintf(flagHead, "OSC_");
		break;
	}
	MethodFactory *pMethodFactory = NULL;
	pMethodFactory = MethodFactory::GetInstance();	
	if ( pMethodFactory == NULL)
	{
		sprintf(ErrMsg, "%s", "������ʵ��δ��ʼ��!");
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}
	it = pMethodFactory->m_MethodMap.begin();
	i=0;
	while(it != pMethodFactory->m_MethodMap.end())
	{
		tmpStr = it->first;
		m_MethodSet = it->second;
		pos = tmpStr.find(flagHead);
		if(pos==0 && m_MethodSet.Visable == 1)
		{	
			sprintf(FunName[i], "%s", tmpStr.c_str());
			*(methodName + i) = *(FunName+i);
			i++;
		}	
		it++;
	}
	tmpcount = pMethodFactory->m_MethodMap.size();
	
	*count = i;
	
	//���Ӵ���
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  MethodIsInLib
* ����:	 dolob.jiang
* ����  2009.12.12
* ����: char *methodName, unsigned short *IsInLib
* ����:  ��֤ĳ���������Ƿ�Ϸ�
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     MethodIsInLib(char *methodName, unsigned short *IsInLib)
{
	TMethodMap::iterator it;
	int i = 0;
	char ErrMsg[1024];
	MethodFactory *pMethodFactory = NULL;
	pMethodFactory = MethodFactory::GetInstance();	
	if ( pMethodFactory == NULL)
	{
		sprintf(ErrMsg, "%s", "������ʵ��δ��ʼ��!");
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}

	it = pMethodFactory->m_MethodMap.begin();
	for (int j = 0; j < pMethodFactory->m_MethodMap.size(); j++)
	{
		if (strcmp(it->first.c_str(), methodName) == 0)
		{
			break;
		}
		it++;
	}
	if (it == pMethodFactory->m_MethodMap.end())
	{
		*IsInLib = 0;
	}
	else
	{
		*IsInLib = 1;
	}

	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  CreateMethod
* ����:	 dolob.jiang
* ����  2009.10.12
* ����: char *methodName, int *methodHandle
* ����:  ����һ������
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     CreateMethod(char *methodName, int *methodHandle)
{
	TMethodMap::iterator it;
	MethodNameStruct m_MethodSet;
	char ErrMsg[1024] = {0};

	MethodFactory *pMethodFactory = NULL;
	pMethodFactory = MethodFactory::GetInstance();	
	if ( pMethodFactory == NULL)
	{
		sprintf(ErrMsg, "%s", "������ʵ��δ��ʼ��!");
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}
	
	it = pMethodFactory->m_MethodMap.find(methodName);
	
	if (it == pMethodFactory->m_MethodMap.end())
	{
		sprintf(ErrMsg, "%sΪ�Ƿ�����,�ڷ�������û��ע��", methodName);
		NTS_Error(ErrMsg);
		return NTS_INVALID_PARA;
	}
	for (int i = 0; i <= MAXMETHOD; i++)
	{
		if (!gMethodDev[i])
		{
			m_MethodSet = it->second;
			gMethodDev[i] = pMethodFactory->CreateMethod(m_MethodSet.MethodID, methodName);
			if (!gMethodDev[i])
			{
				sprintf(ErrMsg, "����%s����ʧ��", methodName);
				NTS_Error(ErrMsg);
				return NTS_INVALID_DEVICE;
			}
			*methodHandle = i;
			return NTS_SUCCESS;
		}
	}	
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  DeleteMethod
* ����:	 dolob.jiang
* ����  2009.10.12
* ����: int methodHandle
* ����:  ɾ��һ������
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int __stdcall     DeleteMethod(int methodHandle)
{
	
	if(methodHandle<0)
	{
		return NTS_INVALID_DEVICE;
	}
	if (methodHandle > MAXMETHOD)
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	delete gMethodDev[methodHandle];
	gMethodDev[methodHandle] =0;
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetMethodScript
* ����:	 dolob.jiang
* ����  2009.10.12
* ����: int methodHandle, char *Script
* ����:  ��ȡ��������������
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetMethodScript(int methodHandle, char *Script)
{
	if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	return gMethodDev[methodHandle]->GetMethodScript(Script);
}

/******************************************************************************
* ��������:  SetMethodScript
* ����:	 dolob.jiang
* ����  2009.10.12
* ����: int methodHandle, char *Script
* ����:  ���÷�������������
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	SetMethodScript(int methodHandle, char *Script)
{
	if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	return gMethodDev[methodHandle]->SetMethodScript(Script);
}

/******************************************************************************
* ��������:  GetInputParamNum
* ����:	 dolob.jiang
* ����  2009.10.12
* ����: int methodHandle, unsigned short *inputParamNum
* ����:  ��ȡ�������������
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetInputParamNum(int methodHandle, unsigned short *inputParamNum)
{
	TParamSetVector m_paramSetVector;
	if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	int retVal = gMethodDev[methodHandle]->GetInputParam(&m_paramSetVector);
	if (retVal != NTS_SUCCESS)
	{
		return retVal;
	}
	*inputParamNum = m_paramSetVector.size();
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetInputParaInfo
* ����:	 dolob.jiang
* ����  2009.12.12
* ����: int methodHandle, unsigned short inputParamIndex, char *paramName, int *paramType, 
		unsigned short *paramNum, char *paramVal, char *paramUnit
* ����: ��ȡĳ�������������ϸ��Ϣ(������|��������|��������|����ֵ|��λ) 
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int  __stdcall    GetInputParaInfo(int methodHandle, unsigned short inputParamIndex, 
														 char *paramName, int *paramType, 
														 unsigned short *paramNum, char *paramVal, char *paramUnit)
{
	char ErrMsg[1024];
	TParamSetVector m_paramSetVector;

	try
	{
		if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
		{
			return NTS_INVALID_DEVICE;
		}
		if (!gMethodDev[methodHandle]) 
		{
			return NTS_INVALID_DEVICE;
		}
		int retVal = gMethodDev[methodHandle]->GetInputParam(&m_paramSetVector);
		if (retVal != NTS_SUCCESS)

		{
			return retVal;
		}
		if (inputParamIndex >= m_paramSetVector.size())
		{
			return NTS_INVALID_PARA;
		}
		sprintf(paramName, m_paramSetVector[inputParamIndex]->paramName);
		sprintf(paramVal, m_paramSetVector[inputParamIndex]->paramVal);
		sprintf(paramUnit, m_paramSetVector[inputParamIndex]->paramUnit);
		*paramType = m_paramSetVector[inputParamIndex]->paramType;
		*paramNum = m_paramSetVector[inputParamIndex]->paramCount;
		return NTS_SUCCESS;
	}
	catch (std::exception &e)
	{
		sprintf(ErrMsg, "�쳣����:%s", e.what());
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}

}

/******************************************************************************
* ��������:  SetInputParamVal
* ����:	 dolob.jiang
* ����  2009.10.12
* ����: int methodHandle, unsigned short inputParamIndex, char *paramVal
* ����:  ����ĳ�������Ĳ���ֵ
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int  __stdcall    SetInputParamVal(int methodHandle, unsigned short inputParamIndex, char *paramVal)
{
	TParamSetVector vParamSetVector;
	ParamSetStruct *pParamSetStruct;
	int vLength, vInputParaCount;
	
	vLength = strlen(paramVal);
	//��������еļ�¼
	vParamSetVector.clear();
	
	if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	//��������Ϣ������һ��������
	int retVal = gMethodDev[methodHandle]->GetInputParam(&vParamSetVector);
	if (retVal != NTS_SUCCESS)
	{
		return retVal;
	}
	//�����������
	vInputParaCount = vParamSetVector.size();
	if (inputParamIndex >= vInputParaCount)
	{
		return NTS_INVALID_PARA;
	}
	if( vLength > PARALENGTH)				//�����ݴ���
	{	
		pParamSetStruct = NULL;
		pParamSetStruct = vParamSetVector[inputParamIndex];		
		//Ϊ�����ݶ�̬�����ڴ�ռ�			
		vParamSetVector[inputParamIndex]->LparamVal = (char *)malloc((vLength + 10) * sizeof(char));		
		sprintf(pParamSetStruct->LparamVal, "%s", paramVal);	
	}
	else
	{
		pParamSetStruct = NULL;			
		pParamSetStruct = vParamSetVector[inputParamIndex];
		sprintf(vParamSetVector[inputParamIndex]->paramVal, paramVal);
	}	
	gMethodDev[methodHandle]->SetInputParam(vParamSetVector);
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  SetInputParamVal
* ����:	 dolob.jiang
* ����  2009.10.12
* ����: unsigned short inputParamIndex, char *paramVal, long Len
* ����:  ����ĳ�������Ĳ���ֵ(��չ�ڴ泤��) 
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int  __stdcall    SetInputParamValEx(int methodHandle, unsigned short inputParamIndex, char *paramVal, long Len)
{
	
	TParamSetVector vParamSetVector;
	ParamSetStruct *pParamSetStruct;
	int vLength, vInputParaCount;
	
	vLength = Len;
	if (vLength <= 0) 
	{
		return NTS_INVALID_PARA;
	}
	//��������еļ�¼
	vParamSetVector.clear();
	
	if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	//��������Ϣ������һ��������
	int retVal = gMethodDev[methodHandle]->GetInputParam(&vParamSetVector);
	if (retVal != NTS_SUCCESS)
	{
		return retVal;
	}
	//�����������
	vInputParaCount = vParamSetVector.size();
	if (inputParamIndex >= vInputParaCount)
	{
		return NTS_INVALID_PARA;
	}
	if( vLength > PARALENGTH)				//�����ݴ���
	{	
		pParamSetStruct = NULL;
		pParamSetStruct = vParamSetVector[inputParamIndex];		
		//Ϊ�����ݶ�̬�����ڴ�ռ�			
		vParamSetVector[inputParamIndex]->LparamVal = (char *)malloc((vLength + 10) * sizeof(char));	
		memset(vParamSetVector[inputParamIndex]->LparamVal, 0, vLength + 10);
		memcpy(vParamSetVector[inputParamIndex]->LparamVal, paramVal, vLength);	
	}
	else
	{
		pParamSetStruct = NULL;			
		pParamSetStruct = vParamSetVector[inputParamIndex];
		memset(vParamSetVector[inputParamIndex]->paramVal, 0, sizeof(vParamSetVector[inputParamIndex]->paramVal) );
		memcpy(vParamSetVector[inputParamIndex]->paramVal, paramVal, vLength);
		vParamSetVector[inputParamIndex]->paramCount = vLength;
	}	
	gMethodDev[methodHandle]->SetInputParam(vParamSetVector);
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetOutputParamNum
* ����:	 dolob.jiang
* ����  2009.12.12
* ����: int methodHandle, unsigned short *outputParamNum
* ����:  ��ȡ�����������������
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetOutputParamNum(int methodHandle, unsigned short *outputParamNum)
{
	TParamSetVector m_paramSetVector;

	if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
	{
		return NTS_INVALID_DEVICE;
	}
	if (!gMethodDev[methodHandle]) 
	{
		return NTS_INVALID_DEVICE;
	}
	int retVal = gMethodDev[methodHandle]->GetOutputParam(&m_paramSetVector);
	if (retVal != NTS_SUCCESS)
	{
		return retVal;
	}
	*outputParamNum = m_paramSetVector.size();
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetOutputParaInfo
* ����:	 dolob.jiang
* ����  2009.12.12
* ����: int methodHandle, unsigned short outputParamIndex,char *paramName, int *paramType, 
		unsigned short *paramNum, char *paramVal, char *paramUnit
* ����:  ��ȡĳ����������Ĳ�����ϸ��Ϣ(������|��������|��������|����ֵ|��λ)
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int  __stdcall    GetOutputParaInfo(int methodHandle, unsigned short outputParamIndex, 
																char *paramName, int *paramType, 
																unsigned short *paramNum, char *paramVal, char *paramUnit)
{
	TParamSetVector m_paramSetVector;
	int ParaCount, index;
	char ErrMsg[1024];
	
	try
	{
	
		if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
		{
			return NTS_INVALID_DEVICE;
		}
		if (!gMethodDev[methodHandle]) 
		{
			return NTS_INVALID_DEVICE;
		}
		int retVal = gMethodDev[methodHandle]->GetOutputParam(&m_paramSetVector);
		if (retVal != NTS_SUCCESS)
		{
			return retVal;
		}
		//�����������
		ParaCount = m_paramSetVector.size();
		if (outputParamIndex >= ParaCount )
		{
			return NTS_INVALID_PARA;
		}
		index = outputParamIndex;
		if(m_paramSetVector[index]->LparamVal != NULL)
		{
			
			sprintf(paramName, m_paramSetVector[index]->paramName);
			sprintf(paramVal, m_paramSetVector[index]->LparamVal);
			sprintf(paramUnit, m_paramSetVector[index]->paramUnit);
			*paramType = m_paramSetVector[index]->paramType;
			*paramNum = m_paramSetVector[index]->paramCount;
		}
		else
		{		
			sprintf(paramName, m_paramSetVector[index]->paramName);
			sprintf(paramVal, m_paramSetVector[index]->paramVal);
			sprintf(paramUnit, m_paramSetVector[index]->paramUnit);
			*paramType = m_paramSetVector[index]->paramType;
			*paramNum = m_paramSetVector[index]->paramCount;
		}
	}
	catch (std::exception &e)
	{
		sprintf(ErrMsg, "�쳣����:%s", e.what());
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}

	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  DoMethodRun
* ����:	 dolob.jiang
* ����  2009.12.12
* ����: int methodHandle
* ����:  ���з���
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	DoMethodRun(int methodHandle)
{
	char ErrMsg[1024];
	
	try
	{		
		if ((methodHandle < 0)||(methodHandle > MAXMETHOD))
		{
			return NTS_INVALID_DEVICE;
		}
		if (!gMethodDev[methodHandle]) 
		{
			return NTS_INVALID_DEVICE;
		}
		return gMethodDev[methodHandle]->Run();
	}
	catch (std::exception &e)
	{
		sprintf(ErrMsg, "�쳣����:%s", e.what());
		NTS_Error(ErrMsg);
		return NTS_INVALID_OPERATE;
	}
}

/******************************************************************************
* ��������:  GetADMethodName
* ����:	 dolob.jiang
* ����  2009.12.12
* ����: char *ProductName, char **MethodName, int *Count
* ����:  ��ȡ��Ʒ�ĵ���/У׼����
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetADMethodName(char *ProductName, char **MethodName, int *Count)
{

	char Name[50][50] = {0};
	int tmpcount = 0 ;
	sprintf(Name[0],"DEB_WriteDebug");
	sprintf(Name[1],"ADJ_WriteCal");

	tmpcount = 2;
	for(int i = 0;i<tmpcount;i++)
	{
		*(MethodName+i)  = *(Name+i);
	}
	*Count = tmpcount;
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetParaName
* ����:	 dolob.jiang
* ����  2009.10.12
* ����: char **TypeName ,int *Count
* ����:  ��ȡ��������
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetParaName(char **TypeName ,int *Count)
{
	char Name[50][50] = {0};
	int tmpcount = 0 ;
	
	sprintf(Name[0],"NTSInt16");
	sprintf(Name[1],"NTSInt8");
	sprintf(Name[2],"NTSInt32");
	sprintf(Name[3],"NTSUInt16");
	sprintf(Name[4],"NTSUInt8");
	sprintf(Name[5],"NTSUInt32");
	sprintf(Name[6],"NTSInt16Array");
	sprintf(Name[7],"NTSInt8Array");
	sprintf(Name[8],"NTSInt32Array");
	sprintf(Name[9],"NTSUInt16Array");
	sprintf(Name[10],"NTSUInt8Array");
	sprintf(Name[11],"NTSUInt32Array");
	sprintf(Name[12],"NTSString");
	sprintf(Name[13],"NTSReal32");
	sprintf(Name[14],"NTSReal64");
	sprintf(Name[15],"NTSReal32Array");
	sprintf(Name[16],"NTSReal64Array");
	sprintf(Name[17],"NTSSWLinkString");
	sprintf(Name[18],"NTSPChar");
	
	tmpcount = 19;
	for(int i = 0;i<tmpcount;i++)
	{
		*(TypeName+i)  = *(Name+i);
	}
	*Count = tmpcount;
	return NTS_SUCCESS;	
}

/******************************************************************************
* ��������:  GetConnectStr
* ����:	 dolob.jiang
* ����  2009.10.12
* ����: int DeviceType, int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* ����:  ��ȡ�豸�������ַ���
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetConnectStr(int DeviceType, int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vProductName[50];
	int retVal;
	short int DevHandle;

	char IP[50] = {0};
	char Instrument_Descriptor[500], vInfoStr[200], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i, j, index;	
	int DPDCount;
	std::vector<std::string> vVectorString;
	
	DPDCount = 0;
	Return_Count = 0;
	sprintf(vProductName, ProductName);
	//�豸����
	switch(DeviceType) 
	{
	case NTS:
		break;

	case  SG:
		retVal = GetConnectStrOfSG(Interface, inParaStr, ProductName, vConnectStr);
		break;

	case PSA:
		retVal = GetConnectStrOfPSA(Interface, inParaStr, ProductName, vConnectStr);
		break;

	case ENA:
		retVal = GetConnectStrOfENA(Interface, inParaStr, ProductName, vConnectStr);
		break;

	case NFA:
		retVal = GetConnectStrOfNFA(Interface, inParaStr, ProductName, vConnectStr);
		break;

	case MMT:
		return NTS_INVALID_PARA;		
		break;

	case SWI:
		if (Interface != 3)
		{
			return NTS_INVALID_PARA;
		}
		if (strlen(inParaStr) == 0 )
		{
			return NTS_INVALID_PARA;	
		}
		sprintf(vConnectStr, "%s%s%s","NTS::SW::SW::COM",inParaStr,"::CARD");
		retVal = SW_OpenDev(vConnectStr, &DevHandle);
		if (retVal != NTS_SUCCESS)
		{
			return NTS_INVALID_PARA;	
		}	
		SW_CloseDev(DevHandle);
		break;

	case DPD:
		retVal = GetConnectStrOfDPD(Interface, inParaStr, ProductName, vConnectStr);		
		break;

	case  PRM:
		retVal = GetConnectStrOfPRM(Interface, inParaStr, ProductName, vConnectStr);	
		break;

	case IRU:
		retVal = GetConnectStrOfIRU(Interface, inParaStr, ProductName, vConnectStr);
		break;

	case DWG:
		retVal = GetConnectStrOfDWG(Interface, inParaStr, ProductName, vConnectStr);
		break;

	case OSC:
		retVal = GetConnectStrOfOSC(Interface, inParaStr, ProductName, vConnectStr);
		break;

	default:		
		if(Interface == GPIB)				//GPIB
		{
			retVal = viGetDefaultRM(&Rsmanager);
			if(retVal < VI_SUCCESS)
			{			
				return NTS_INVALID_DEVICE;
			}
			retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
			if(retVal >= 0 &&Return_Count > 0)
			{				
				for(i = 0 ; i< Return_Count; i++)
				{	
					//���豸
					viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
					//������Ϣ
					viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
					sprintf(manfName,"%s", NTS_Trim(vInfoStr));
					
					//�豸�ͺ�
					sprintf(vInfoStr , ""); 
					viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
					sprintf(DevTypeName,"%s", NTS_Trim(vInfoStr));
										
					//�ر��豸
					viClose(vi);
					
					//����������
					if (strcmp(manfName,"Agilent Technologies")== 0)
					{
						sprintf(manfName, "%s", "AGILENT");						
					}
					// R&S����
					else if (strcmp(manfName,"Rohde&Schwarz")== 0)
					{
						sprintf(manfName, "%s", "RS");
					}								
					if(i == 0)
					{
						sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
					}
					else
					{						
						sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
					}			
					viFindNext (Find_Handle,Instrument_Descriptor);
				}
			}
			viClose(Rsmanager);
		}
		else if(Interface == LAN)			//Lan
		{
			sprintf(IP, inParaStr);
			//����IP��ַ����
			if(strlen(IP) <= 9)
			{
				return NTS_INVALID_PARA;
			}
			sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
			retVal = viGetDefaultRM(&Rsmanager);
			if(retVal < VI_SUCCESS)
			{			
				return NTS_INVALID_DEVICE;
			}		
			//���豸
			retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
			if(retVal < VI_SUCCESS)
			{			
				return NTS_INVALID_DEVICE;
			}
			//������Ϣ
			viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
			sprintf(manfName,vInfoStr);
			
			//�豸�ͺ�
			sprintf(vInfoStr , ""); 
			viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
			for(index = 0,j=0; j<strlen(vInfoStr); j++)
			{
				if(vInfoStr[j]!=' ')
				{
					DevTypeName[index] = vInfoStr[j]; 
					index++;
				}
			}
			DevTypeName[index] = '\0';		
			//�ر��豸
			viClose(vi);			
			sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
			
//			return NTS_INVALID_PARA;
		}
		else if(Interface == COM)			//Com
		{				
			retVal = NTS_OpenCom(inParaStr, &DevHandle);
			if(retVal != NTS_SUCCESS)
			{
				return NTS_INVALID_DEVICE;
			}	
			retVal = NTS_SetCom(DevHandle, 9600, 8, 0, 1);
			if(retVal != NTS_SUCCESS)
			{
				NTS_CloseCom(DevHandle);
				return NTS_INVALID_DEVICE;
			}
									
			sprintf(vInfoStr, "%s\n", "*IDN?");			
			retVal = NTS_WriteCom(DevHandle, vInfoStr, strlen(vInfoStr));
			if(retVal != NTS_SUCCESS)
			{
				NTS_CloseCom(DevHandle);
				return NTS_INVALID_DEVICE;
			}
			Sleep(1000);
			retVal = NTS_ReadCom(DevHandle,Instrument_Descriptor, sizeof(Instrument_Descriptor), &Return_Count);
			if(retVal != NTS_SUCCESS)
			{
				NTS_CloseCom(DevHandle);
				return NTS_INVALID_DEVICE;
			}			
			retVal = NTS_CloseCom(DevHandle);
			// �����ַ���
			NTS_SeparateStr(Instrument_Descriptor, ",", &vVectorString);
			if ( vVectorString.size() >= 2)
			{
				sprintf(manfName, "%s", vVectorString[0].c_str());
				NTS_Trim(manfName);
				sprintf(DevTypeName, "%s", vVectorString[1].c_str());
				NTS_Trim(DevTypeName);
				sprintf(vConnectStr, "%s::%s::COM::%s::INSTR", manfName, DevTypeName, inParaStr);
			}						
		}
		if(Interface == USB)				//USB
		{
			retVal = viGetDefaultRM(&Rsmanager);
			if(retVal < VI_SUCCESS)
			{			
				return NTS_INVALID_DEVICE;
			}
			retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
			if(retVal >= 0 &&Return_Count > 0)
			{				
				for(i = 0 ; i< Return_Count; i++)
				{	
					//���豸
					viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
					//������Ϣ
					viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
					sprintf(manfName,"%s", NTS_Trim(vInfoStr));
					
					//�豸�ͺ�
					sprintf(vInfoStr , ""); 
					viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
					sprintf(DevTypeName,"%s", NTS_Trim(vInfoStr));
					
					//�ر��豸
					viClose(vi);
					
					//����������
					if (strcmp(manfName,"Agilent Technologies")== 0)
					{
						sprintf(manfName, "%s", "AGILENT");						
					}
					// R&S����
					else if (strcmp(manfName,"Rohde&Schwarz")== 0)
					{
						sprintf(manfName, "%s", "RS");
					}								
					if(i == 0)
					{
						sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
					}
					else
					{						
						sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
					}			
					viFindNext (Find_Handle,Instrument_Descriptor);
				}
			}
			viClose(Rsmanager);
		}

		break;
	} 
	
	
	if (strlen(vConnectStr) == 0)
	{
		return NTS_INVALID_PARA;	
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetDeviceMethod
* ����:	 dolob.jiang
* ����  2009.12.22
* ����: int DeviceType, char *ConnectStr, char **Name, int *Count
* ����:  ��ȡ�豸������������
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetDeviceMethod(int DeviceType, char *ConnectStr, char **Name, int *Count)
{
	std::string protoclString(ConnectStr);
	std::vector<std::string> subProtocls;
	std::string::size_type pos = 0, oldPos = 0;
	char vMethodName[1024][50] = {0};

	char vDriverName[100] = {0};
	char ProductName[50] = {0};

	//��ȡ�������еĺ�����
	char fileName[1024];
	char *Fns[3000] = {0};
	char SubFn[100] = {0};
	int i, FnCount, FnParaCount;
	HMODULE DllHandle;
	
	do
	{
		pos = protoclString.find("::", oldPos);
		if (pos != std::string::npos)
		{
			subProtocls.push_back(protoclString.substr(oldPos, pos - oldPos));
			oldPos = pos + 2;
		}
		else 
		{
			subProtocls.push_back(protoclString.substr(oldPos, pos));
			break;
		}
	}while(true);
	if (subProtocls.size() == 0)
	{
		return NTS_INVALID_PROTOCL;
	}
	
	switch(DeviceType)
	{
	case NTS:
		if(subProtocls.size() < 4)			//V1
		{
			sprintf(ProductName,"%s",subProtocls[0].c_str());
		}
		else								//V2
		{
			sprintf(ProductName,"%s",subProtocls[1].c_str());
		}		
		//����::�ͺ�::Э����::�ӿ�::�̶�ֵ
		protoclString = ProductName;
		pos = 0;
		oldPos = 0;
		do
		{
			pos = protoclString.find("ComDevice", oldPos);
			if (pos != std::string::npos)
			{
				sprintf(ProductName,(protoclString.substr(oldPos, pos - oldPos)).c_str());
				oldPos = pos + strlen("ComDevice");
			}
			else 
			{				
				break;
			}
		}while(true);
		//����������
		sprintf(vDriverName, "%s%s", ProductName, "Driver.dll");		
		break;
		
	case  SG:
		//��Ʒ����
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//����������
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case PSA:
		//��Ʒ����
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//����������
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;

	case ENA:
		//��Ʒ����
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//����������
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case NFA:
		//��Ʒ����
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//����������
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case MMT:
		//��Ʒ����
		sprintf(ProductName,"%s","MMT");
		//����������
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case SWI:
		//��Ʒ����
		sprintf(ProductName,"%s","SW");
		//����������
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case DPD:
		//����::�ͺ�::Э����::�ӿ�::�̶�ֵ (��:"NTS::ZXDPD::TCPIP::100.191.3.2::T3440ZXDPDCARD")
		//��Ʒ����
		sprintf(ProductName,"%s",subProtocls[4].c_str());
		ProductName[strlen(ProductName) - 4] = '\0';		
		//
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case  PRM:
		//��Ʒ����
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//����������
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
		
	case IRU:
		//��Ʒ����
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//����������
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;

	case DWG:
		//��Ʒ����
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//����������
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;

	case OSC:
		//��Ʒ����
		sprintf(ProductName,"%s",subProtocls[1].c_str());
		//����������
		sprintf(vDriverName, "%s%s", ProductName,"Driver.dll");
		break;
	}
	DllHandle = NULL;
	DllHandle = LoadLibrary(vDriverName) ;
	if(DllHandle != NULL)
	{
		if(GetModuleFileName(DllHandle, fileName, sizeof(fileName)) <= 0)   
		{   
			return NTS_LOADDLL_ERROR;   
		}	
		AnalysisFunction(fileName, Fns, &FnCount);
	}
	
	for(i = 0; i<FnCount; i++)
	{
		GetSubStr(Fns[i], SubFn, &FnParaCount); 
		if(strcmp(SubFn, "NTS_SetWorkModeA") == 0)
		{
			sprintf(vMethodName[i], "%s", "NTS_SetWorkModeEx");	
		}
		else if(strcmp(SubFn, "NTS_GetWorkModeA") == 0)
		{
			sprintf(vMethodName[i], "%s", "NTS_GetWorkModeEx");	
		} 
		else if (strcmp(SubFn, "SG_SetArbWave") == 0)
		{
            sprintf(vMethodName[i], "%s", "SG_SetWaveFile");	
		} 
		else if (strcmp(SubFn, "PSA_SetMarkPosition") == 0)
		{
			sprintf(vMethodName[i], "%s", "PSA_SetMarkFreq");
		}
		else
		{		
			sprintf(vMethodName[i], "%s", SubFn);		
		}
		*(Name + i) = vMethodName[i];
	}
	// �豸��������û�еķ��������ڷ�����Ҳ���ڵķ�������Ҫ�ֶ�����
	switch(DeviceType) 
	{
	case NTS:			
		break;
		
	case  SG:
		break;
		
	case PSA:
		break;

	case OSC:
		break;

	case DWG:
		break;
		
	case ENA:		
		break;
		
	case NFA:		
		break;
		
	case MMT:		
		break;
		
	case SWI:		
		break;
		
	case DPD:
		sprintf(vMethodName[FnCount], "%s", "DPD_SetErrPwrDebug");
		*(Name + FnCount) = vMethodName[FnCount];		
		FnCount++;
		
		sprintf(vMethodName[FnCount], "%s", "DPD_SetErrPwrDebugDT");
		*(Name + FnCount) = vMethodName[FnCount];
		FnCount++;

		sprintf(vMethodName[FnCount], "%s", "DPD_ACPRPowerDebug");
		*(Name + FnCount) = vMethodName[FnCount];
		FnCount++;

		sprintf(vMethodName[FnCount], "%s", "DPD_ACPRPowerDebugDT");
		*(Name + FnCount) = vMethodName[FnCount];
		FnCount++;

		sprintf(vMethodName[FnCount], "%s", "DPD_PRMPowerDebug");
		*(Name + FnCount) = vMethodName[FnCount];
		FnCount++;
		break;
		
	case  PRM:	
		break;
		
	case IRU:		
		break;
	}
	*Count = FnCount;
	
	return NTS_SUCCESS;
}


/******************************************************************************
* ��������:  GetDevicePreName
* ����:	 dolob.jiang
* ����  2009.12.22
* ����: int DeviceType, char **Name, int *Count
* ����:  ��ȡ�豸��ǰ׺��(DeviceType 0:All)
* ����ֵ:  short int
******************************************************************************/
NTSSCRIPTLIB_API short int	__stdcall	GetDevicePreName(int DeviceType, char **Name, int *Count)
{
	char vPreName[100][50] = {0};	
	int i = 0;
	int tmpcount;	
	
	switch(DeviceType)
	{
	case 0:					// All
		sprintf(vPreName[0], "NTS_");			//��Ʒ		
		sprintf(vPreName[1], "SG_");			//�ź�Դ				
		sprintf(vPreName[2], "PSA_");			//Ƶ����			
		sprintf(vPreName[3], "ENA_");			//������				
		sprintf(vPreName[4], "NFA_");			//������				
		sprintf(vPreName[5], "SPE_");			//������					
		sprintf(vPreName[6], "MMT_");			//���ñ�				
		sprintf(vPreName[7], "SW_");			//���󿪹�			
		sprintf(vPreName[8], "DPD_");			//DPD��			
		sprintf(vPreName[9], "PRM_");			//���ʼ�			
		sprintf(vPreName[10], "IRU_");			//IRU
		sprintf(vPreName[11], "NC_");			// NCARD
		sprintf(vPreName[12], "DWG_");			// DWG
		sprintf(vPreName[13], "OSC_");			// OSC
		tmpcount = 14;
		break;

	case NTS:				
		sprintf(vPreName[0], "NTS_");			//��Ʒ
		tmpcount = 1;
		break;

	case SG:				
		sprintf(vPreName[0], "SG_");			//�ź�Դ
		tmpcount = 1;
		break;

	case NFA:			
		sprintf(vPreName[0], "NFA_");			//������
		tmpcount = 1;
		break;

	case PSA:				
		sprintf(vPreName[0], "PSA_");			//Ƶ����
		tmpcount = 1;
		break;

	case ENA:				
		sprintf(vPreName[0], "ENA_");			//������
		tmpcount = 1;
		break;	

	case MMT:				
		sprintf(vPreName[0], "MMT_");			//���ñ�
		tmpcount = 1;
		break;	

	case SWI:				
		sprintf(vPreName[0], "SW_");			//���󿪹�
		tmpcount = 1;
		break;

	case DPD:				
		sprintf(vPreName[0], "DPD_");			//DPD��
		tmpcount = 1;
		break;

	case PRM:				
		sprintf(vPreName[0], "PRM_");			//���ʼ�
		tmpcount = 1;
		break;

	case IRU:				
		sprintf(vPreName[0], "IRU_");			//IRU
		tmpcount = 1;
		break;

	case NCARD:				
		sprintf(vPreName[0], "NC_");			// NCard ͨ�ýӿڿ�
		tmpcount = 1;
		break;

	case DWG:				
		sprintf(vPreName[0], "DWG_");			// DWG ͨ�ýӿڿ�
		tmpcount = 1;
		break;

	case OSC:				
		sprintf(vPreName[0], "OSC_");			// OSC ͨ�ýӿڿ�
		tmpcount = 1;
		break;
	}
	for(i = 0; i<tmpcount; i++)
	{	
		*(Name + i) = vPreName[i];
	}
	*Count = tmpcount;
	return NTS_SUCCESS;
}
#pragma hdrstop
/******************************************************************************
* ��������:  GetConnectStrOfOSC
* ����:	 dolob.jiang
* ����  2009.12.21
* ����: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* ����:  ��ȡOSC�豸�������ַ���
* ����ֵ:  ��
******************************************************************************/
int GetConnectStrOfOSC(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100] = {0};
	char IP[50] = {0};
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i;
	
	int OSCCount;
	
	Return_Count = 0;
	OSCCount = 0;
	
	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//���豸
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//������Ϣ
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", NTS_Trim(vInfoStr));
				
				//�豸�ͺ�
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
				
				//�ر��豸
				viClose(vi);
				
				if(OSCCount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				OSCCount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		sprintf(IP, inParaStr);
		//����IP��ַ����
		if(strlen(IP) <= 9)
		{
			return NTS_INVALID_PARA;
		}
		sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//���豸
		retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//������Ϣ
		viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
		sprintf(manfName,"%s", NTS_Trim(vInfoStr));
		
		//�豸�ͺ�
		sprintf(vInfoStr , ""); 
		viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
		sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
		
		if(OSCCount == 0)
		{
			sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
		}
		else
		{						
			sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
		}
		OSCCount++;	
		//�ر��豸
		viClose(vi);
		viClose(Rsmanager);
		
	}
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}
	else if(Interface == USB)			//USB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//���豸
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//������Ϣ
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName, "%s", NTS_Trim(vInfoStr));
				
				//�豸�ͺ�
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
				
				//�ر��豸
				viClose(vi);
				
				if(OSCCount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				OSCCount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
		
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetConnectStrOfDWG
* ����:	 dolob.jiang
* ����  2009.12.21
* ����: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* ����:  ��ȡDWG�豸�������ַ���
* ����ֵ:  ��
******************************************************************************/
int GetConnectStrOfDWG(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100] = {0};
	char IP[50] = {0};
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i;
	
	int DWGCount;
	
	Return_Count = 0;
	DWGCount = 0;
	
	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//���豸
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//������Ϣ
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", NTS_Trim(vInfoStr));
				
				//�豸�ͺ�
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
				
				//�ر��豸
				viClose(vi);
				
				if(DWGCount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				DWGCount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		sprintf(IP, inParaStr);
		//����IP��ַ����
		if(strlen(IP) <= 9)
		{
			return NTS_INVALID_PARA;
		}
		sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//���豸
		retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//������Ϣ
		viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
		sprintf(manfName,"%s", NTS_Trim(vInfoStr));
		
		//�豸�ͺ�
		sprintf(vInfoStr , ""); 
		viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
		sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
		
		if(DWGCount == 0)
		{
			sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
		}
		else
		{						
			sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
		}
		DWGCount++;	
		//�ر��豸
		viClose(vi);
		viClose(Rsmanager);
		
	}
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}
	else if(Interface == USB)			//USB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//���豸
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//������Ϣ
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName, "%s", NTS_Trim(vInfoStr));
				
				//�豸�ͺ�
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
				
				//�ر��豸
				viClose(vi);
				
				if(DWGCount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				DWGCount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
		
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetConnectStrOfPSA
* ����:	 dolob.jiang
* ����  2009.12.21
* ����: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* ����:  ��ȡPSA�豸�������ַ���
* ����ֵ:  ��
******************************************************************************/
int GetConnectStrOfPSA(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100] = {0};
	char IP[50] = {0};
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i;
	
	int PSACount;
	
	Return_Count = 0;
	PSACount = 0;
	
	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//���豸
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//������Ϣ
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", NTS_Trim(vInfoStr));
				
				//�豸�ͺ�
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
				
				//�ر��豸
				viClose(vi);
				
				if(PSACount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				PSACount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		sprintf(IP, inParaStr);
		//����IP��ַ����
		if(strlen(IP) <= 9)
		{
			return NTS_INVALID_PARA;
		}
		sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//���豸
		retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//������Ϣ
		viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
		sprintf(manfName,"%s", NTS_Trim(vInfoStr));
		
		//�豸�ͺ�
		sprintf(vInfoStr , ""); 
		viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
		sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
		
		if(PSACount == 0)
		{
			sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
		}
		else
		{						
			sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
		}
		PSACount++;	
		//�ر��豸
		viClose(vi);
		viClose(Rsmanager);
		
	}
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}
	else if(Interface == USB)			//USB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//���豸
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//������Ϣ
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName, "%s", NTS_Trim(vInfoStr));
				
				//�豸�ͺ�
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName, "%s", NTS_Trim(vInfoStr));
				
				//�ر��豸
				viClose(vi);
				
				if(PSACount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				PSACount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
		
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetConnectStrOfSG
* ����:	 dolob.jiang
* ����  2009.12.21
* ����: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* ����:  ��ȡSG�豸�������ַ���
* ����ֵ:  ��
******************************************************************************/
int GetConnectStrOfSG(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100] = {0};
	char IP[50];
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i,j,index;
	
	int SGCount;
	
	Return_Count = 0;
	SGCount = 0;
	
	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//���豸
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//������Ϣ
			 	viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s",vInfoStr);

				//�豸�ͺ�
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				memset(DevTypeName, 0, sizeof(DevTypeName));
				for(index = 0,j=0; j<strlen(vInfoStr); j++)
				{
					if(vInfoStr[j]!=' ')
					{
						DevTypeName[index] = vInfoStr[j]; 
						index++;
					}
				}
				DevTypeName[index] = '\0';
 				//�ر��豸
				viClose(vi);
			
				if(SGCount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				SGCount++;	
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		sprintf(IP, inParaStr);
		//����IP��ַ����
		if(strlen(IP) <= 9)
		{
			return NTS_INVALID_PARA;
		}
		sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//���豸
		retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//������Ϣ
		viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
		sprintf(manfName,vInfoStr);
		
		//�豸�ͺ�
		sprintf(vInfoStr , ""); 
		viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
		for(index = 0,j=0; j<strlen(vInfoStr); j++)
		{
			if(vInfoStr[j]!=' ')
			{
				DevTypeName[index] = vInfoStr[j]; 
				index++;
			}
		}
		DevTypeName[index] = '\0';
		if(SGCount == 0)
		{
			sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
		}
		else
		{						
			sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
		}
		SGCount++;	
		//�ر��豸
		viClose(vi);
		viClose(Rsmanager);
		
	}
	else if(Interface == USB)				//USB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//���豸
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//������Ϣ
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", NTS_Trim(vInfoStr));
				
				//�豸�ͺ�
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName,"%s", NTS_Trim(vInfoStr));
				
				//�ر��豸
				viClose(vi);
				
				//����������
				if (strcmp(manfName,"Agilent Technologies")== 0)
				{
					sprintf(manfName, "%s", "AGILENT");						
				}
				// R&S����
				else if (strcmp(manfName,"Rohde&Schwarz")== 0)
				{
					sprintf(manfName, "%s", "RS");
				}								
				if(i == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
					SGCount++;
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
					SGCount++;
				}			
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}	
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetConnectStrOfENA
* ����:	 dolob.jiang
* ����  2009.12.21
* ����: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* ����:  ��ȡENA�豸�������ַ���
* ����ֵ:  ��
******************************************************************************/
int GetConnectStrOfENA(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100] = {0};
	char IP[50] = {0};
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i,j,index;
	
	int ENACount;
	
	Return_Count = 0;
	ENACount = 0;
	
	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//���豸
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//������Ϣ
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", vInfoStr);
				
				//�豸�ͺ�
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				memset(DevTypeName, 0, sizeof(DevTypeName));
				for(index = 0,j=0; j<strlen(vInfoStr); j++)
				{
					if(vInfoStr[j]!=' ')
					{
						DevTypeName[index] = vInfoStr[j]; 
						index++;
					}
				}
				DevTypeName[index] = '\0';
				//�ر��豸
				viClose(vi);
				
				if(strcmp(DevTypeName,"8753ES")== 0) 
				{
					//������
					if(ENACount == 0)
					{
						sprintf(vConnectStr, "%s::HP%s::%s", manfName, DevTypeName, Instrument_Descriptor);
					}
					else
					{						
						sprintf(vConnectStr, "%s,%s::HP%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
					}
					ENACount++;
				}
				else
				{
					//������
					if(ENACount == 0)
					{
						sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
					}
					else
					{						
						sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
					}
					ENACount++;
				}
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		sprintf(IP, inParaStr);
		//����IP��ַ����
		if(strlen(IP) <= 9)
		{
			return NTS_INVALID_PARA;
		}
		sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//���豸
		retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//������Ϣ
		viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
		sprintf(manfName,vInfoStr);
		
		//�豸�ͺ�
		sprintf(vInfoStr , ""); 
		viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
		for(index = 0,j=0; j<strlen(vInfoStr); j++)
		{
			if(vInfoStr[j]!=' ')
			{
				DevTypeName[index] = vInfoStr[j]; 
				index++;
			}
		}
		DevTypeName[index] = '\0';
		if(strcmp(DevTypeName,"8753ES")== 0) 
		{
			//������
			if(ENACount == 0)
			{
				sprintf(vConnectStr, "%s::HP%s::%s", manfName, DevTypeName, Instrument_Descriptor);
			}
			else
			{						
				sprintf(vConnectStr, "%s,%s::HP%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
			}
			ENACount++;
		}
		else
		{
			//������
			if(ENACount == 0)
			{
				sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
			}
			else
			{						
				sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
			}
			ENACount++;
		}
		//�ر��豸
		viClose(vi);
		viClose(Rsmanager);		
	}
	else if(Interface == USB)				//USB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//���豸
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//������Ϣ
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", NTS_Trim(vInfoStr));
				
				//�豸�ͺ�
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName,"%s", NTS_Trim(vInfoStr));
				
				//�ر��豸
				viClose(vi);
				
				//����������
				if (strcmp(manfName,"Agilent Technologies")== 0)
				{
					sprintf(manfName, "%s", "AGILENT");						
				}
				// R&S����
				else if (strcmp(manfName,"Rohde&Schwarz")== 0)
				{
					sprintf(manfName, "%s", "RS");
				}								
				if(i == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}	
				ENACount++;
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}	
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetConnectStrOfNFA
* ����:	 dolob.jiang
* ����  2009.12.21
* ����: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* ����:  ��ȡNFA�豸�������ַ���
* ����ֵ:  ��
******************************************************************************/
int GetConnectStrOfNFA(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100], IP[50];
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i,j,index;
	
	int NFACount;
	
	Return_Count = 0;
	NFACount = 0;

	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//���豸
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//������Ϣ
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,vInfoStr);
				
				//�豸�ͺ�
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				for(index = 0,j=0; j<strlen(vInfoStr); j++)
				{
					if(vInfoStr[j]!=' ')
					{
						DevTypeName[index] = vInfoStr[j]; 
						index++;
					}
				}
				DevTypeName[index] = '\0';
				//�ر��豸
				viClose(vi);

				if(NFACount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				NFACount++;			

				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		sprintf(IP, inParaStr);
		//����IP��ַ����
		if(strlen(IP) <= 9)
		{
			return NTS_INVALID_PARA;
		}
		sprintf(Instrument_Descriptor,"%s%s%s","TCPIP0::",IP, "::INSTR");
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//���豸
		retVal = viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		//������Ϣ
		viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
		sprintf(manfName,vInfoStr);
		
		//�豸�ͺ�
		sprintf(vInfoStr , ""); 
		viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
		for(index = 0,j=0; j<strlen(vInfoStr); j++)
		{
			if(vInfoStr[j]!=' ')
			{
				DevTypeName[index] = vInfoStr[j]; 
				index++;
			}
		}
		DevTypeName[index] = '\0';

		if(NFACount == 0)
		{
			sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
		}
		else
		{						
			sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
		}
		NFACount++;		

		//�ر��豸
		viClose(vi);
		viClose(Rsmanager);
		
	}
	else if(Interface == USB)				//USB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "USB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//���豸
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//������Ϣ
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s", NTS_Trim(vInfoStr));
				
				//�豸�ͺ�
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);  
				sprintf(DevTypeName,"%s", NTS_Trim(vInfoStr));
				
				//�ر��豸
				viClose(vi);
				
				//����������
				if (strcmp(manfName,"Agilent Technologies")== 0)
				{
					sprintf(manfName, "%s", "AGILENT");						
				}
				// R&S����
				else if (strcmp(manfName,"Rohde&Schwarz")== 0)
				{
					sprintf(manfName, "%s", "RS");
				}								
				if(i == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}	
				NFACount++;
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}	
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}

	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetConnectStrOfPRM
* ����:	 dolob.jiang
* ����  2009.12.21
* ����: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* ����:  ��ȡPRM�豸�������ַ���
* ����ֵ:  ��
******************************************************************************/
int GetConnectStrOfPRM(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	char vInfoStr[100];
	int retVal;
	char Instrument_Descriptor[500], manfName[50], DevTypeName[50];
	unsigned long Rsmanager,vi, Find_Handle, Return_Count;
	int i,j,index;
	
	int PRMCount;
	
	Return_Count = 0;
	PRMCount = 0;	
	
	if(Interface == GPIB)				//GPIB
	{
		retVal = viGetDefaultRM(&Rsmanager);
		if(retVal < VI_SUCCESS)
		{			
			return NTS_INVALID_DEVICE;
		}
		retVal = viFindRsrc (Rsmanager, "GPIB?*INSTR",&Find_Handle,&Return_Count,Instrument_Descriptor );     
		if(retVal >= 0 &&Return_Count > 0)
		{				
			for(i = 0 ; i< Return_Count; i++)
			{	
				//���豸
				viOpen(Rsmanager, Instrument_Descriptor, VI_NULL, VI_NULL, &vi);
				//������Ϣ
				viQueryf(vi, "*IDN?\n", "%256[^,]%*T", vInfoStr); 
				sprintf(manfName,"%s",vInfoStr);
				
				//�豸�ͺ�
				sprintf(vInfoStr , ""); 
				viQueryf(vi, "*IDN?\n", "%*[^,],%256[^,]%*T", vInfoStr);   
				for(index = 0,j=0; j<strlen(vInfoStr); j++)
				{
					if(vInfoStr[j]!=' ')
					{
						DevTypeName[index] = vInfoStr[j]; 
						index++;
					}
				}
				DevTypeName[index] = '\0';
				//�ر��豸
				viClose(vi);
				
				if(PRMCount == 0)
				{
					sprintf(vConnectStr, "%s::%s::%s", manfName, DevTypeName, Instrument_Descriptor);
				}
				else
				{						
					sprintf(vConnectStr, "%s,%s::%s::%s", vConnectStr, manfName, DevTypeName, Instrument_Descriptor);
				}
				PRMCount++;				
				viFindNext (Find_Handle,Instrument_Descriptor);
			}
		}
		viClose(Rsmanager);
	}
	else if(Interface == LAN)			//Lan
	{
		return NTS_INVALID_PARA;
	}
	else if(Interface == COM)			//Com
	{
		return NTS_INVALID_PARA;
	}
	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;
}

/******************************************************************************
* ��������:  GetConnectStrOfIRU
* ����:	 dolob.jiang
* ����  2009.12.21
* ����: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* ����:  ��ȡIRU�豸�������ַ���
* ����ֵ:  ��
******************************************************************************/
int GetConnectStrOfIRU(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	int retVal;
	int IP_Addr[4];
	unsigned long Return_Count;
	short int DevHandle;
	int i, j;
	int IRUCount;
	
	Return_Count = 0;
	IRUCount = 0;
	
	if(Interface == GPIB)					//GPIB �ӿ�
	{
		return NTS_INVALID_PROTOCL;
	}
	else if (Interface == LAN)			//LAN �ӿ�
	{
		if (strlen(inParaStr) == 0 )
		{
			return NTS_INVALID_PARA;	
		}
		//����IP��ַ	
		IP_Addr[0] = atoi(&inParaStr[0]);					
		j = 1;
		for(i = 1;i < strlen(inParaStr);i++)
		{
			if (inParaStr[i] == '.') 
			{
				IP_Addr[j] = atoi(&inParaStr[i+1]);
				j++;
			}
		}		
		if (j!=4)
		{
			//����IP��ַ����ȷ
			return NTS_INVALID_PARA;	
		}
		//�ж�IRU������ 
		if (IP_Addr[0] == 192 && IP_Addr[1] == 168)
		{
			//����R809��Ʒ�õ�IRU
			sprintf(vConnectStr, "%s%s%s","NTS::IRU01::TCPIP::",inParaStr,"::INSTR");
		}
	}
	else if (Interface == COM)			//COM �ӿ�
	{
		return NTS_INVALID_PROTOCL;
	}
	else
	{
		return NTS_INVALID_PARA;	
	}
	
	retVal = IRU_OpenDev(vConnectStr, &DevHandle);
	if (retVal != NTS_SUCCESS)
	{
		return NTS_INVALID_PARA;	
	}
	IRU_CloseDev(DevHandle);

	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;

}

/******************************************************************************
* ��������:  GetConnectStrOfDPD
* ����:	 dolob.jiang
* ����  2009.12.21
* ����: int Interface, char *inParaStr, char *ProductName, char *ConnentStr
* ����:  ��ȡDPD�豸�������ַ���
* ����ֵ:  ��
******************************************************************************/
int GetConnectStrOfDPD(int Interface, char *inParaStr, char *ProductName, char *ConnentStr)
{
	char vConnectStr[1024] = {0};
	int retVal;
	unsigned long Return_Count;
	short int DevHandle;
	int i, j;
	int DPDCount;
	
	Return_Count = 0;
	DPDCount = 0;
	
	if (Interface != 2)
	{
		return NTS_INVALID_PARA;
	}
	if (strlen(inParaStr) == 0 )
	{
		return NTS_INVALID_PARA;	
	}
	//����IP��ַ
	int IP_Addr[4];
	IP_Addr[0] = atoi(&inParaStr[0]);					
	j = 1;
	
	for(i = 1;i < strlen(inParaStr);i++)
	{
		if (inParaStr[i] == '.') 
		{
			IP_Addr[j] = atoi(&inParaStr[i+1]);
			j++;
		}
	}		
	if (j!=4)
	{
		//����IP��ַ����ȷ
		return NTS_INVALID_PARA;	
	}
	//�ж�DPD������ 
	////////////////////////////ZX DPD//////////////////////////////////	
	if (IP_Addr[0] == 100 && IP_Addr[1] == 191 && IP_Addr[2] == 2)
	{
		//����T7380ZXģ���õ�DPD��
		sprintf(vConnectStr, "%s%s%s","NTS::ZXDPD::TCPIP::",inParaStr,"::T7380ZXDPDCARD");
	}
	else if (IP_Addr[0] == 100 && IP_Addr[1] == 191 && IP_Addr[2] == 9)
	{
		//����T9390ZXģ���õ�DPD��
		sprintf(vConnectStr, "%s%s%s","NTS::ZXDPD::TCPIP::",inParaStr,"::T9390ZXDPDCARD");
	}
	else if (IP_Addr[0] == 100 && IP_Addr[1] == 191 && IP_Addr[2] == 3)
	{
		//����T3440ZXģ���õ�DPD��
		sprintf(vConnectStr, "%s%s%s","NTS::ZXDPD::TCPIP::",inParaStr,"::T3440ZXDPDCARD");
	}
	else if (IP_Addr[0] == 100 && IP_Addr[1] == 191 && IP_Addr[2] == 1)
	{
		//����T1440ZXģ���õ�DPD��
		sprintf(vConnectStr, "%s%s%s","NTS::ZXDPD::TCPIP::",inParaStr,"::T1440ZXDPDCARD");
	}
	else if (IP_Addr[0] == 199 && IP_Addr[1] == 33 && IP_Addr[2] == 33)
	{
		//����D500ZXģ���õ�DPD��
		sprintf(vConnectStr, "%s%s%s","NTS::ZXDPD::TCPIP::",inParaStr,"::D500ZXDPDCARD");
	}
	else if (IP_Addr[0] == 199 && IP_Addr[1] == 33 && IP_Addr[2] == 34)
	{
		//����W3501ZXģ���õ�DPD��
		sprintf(vConnectStr, "%s%s%s","NTS::ZXDPD::TCPIP::",inParaStr,"::W3501ZXDPDCARD");
	}
	////////////////////////////DT DPD//////////////////////////////////	
	else if (IP_Addr[0] == 172 && IP_Addr[1] == 27 && (IP_Addr[2] == 4 || IP_Addr[2] ==45) )
	{
		//����T4370DTģ���õ�DPD��
		sprintf(vConnectStr, "%s%s%s","NTS::DTDPD::TCPIP::",inParaStr,"::T4370DTDPDCARD");
	}
	else if (IP_Addr[0] == 172 && IP_Addr[1] == 27 && (IP_Addr[2] == 1) )
	{
		//����T1440DTģ���õ�DPD��
		sprintf(vConnectStr, "%s%s%s","NTS::DTDPD::TCPIP::",inParaStr,"::T1440DTDPDCARD");
	}
	else if (IP_Addr[0] == 172 && IP_Addr[1] == 27 && (IP_Addr[2] == 2) )
	{
		//����T2380DTģ���õ�DPD��
		sprintf(vConnectStr, "%s%s%s","NTS::DTDPD::TCPIP::",inParaStr,"::T2380DTDPDCARD");
	}
	else if (IP_Addr[0] == 172 && IP_Addr[1] == 27 && (IP_Addr[2] == 5) )
	{
		//����T5394DTģ���õ�DPD��
		sprintf(vConnectStr, "%s%s%s","NTS::DTDPD::TCPIP::",inParaStr,"::T5394DTDPDCARD");
	}
	////////////////////////////NTS DPD//////////////////////////////////	
	else if (IP_Addr[0] == 192 && IP_Addr[1] == 168 && (IP_Addr[2] == 52) )
	{
		//����T8390ģ���õ�DPD��
		sprintf(vConnectStr, "%s%s%s","NTS::DTDPD::TCPIP::",inParaStr,"::T8390DPDCARD");
	}
	else
	{
		return NTS_INVALID_PARA;	
	}
	retVal = DPD_OpenDev(vConnectStr, &DevHandle);
	if (retVal != NTS_SUCCESS)
	{
		return NTS_INVALID_PARA;	
	}
	DPD_CloseDev(DevHandle);

	sprintf(ConnentStr,"%s",vConnectStr);
	return NTS_SUCCESS;

}

/******************************************************************************
* ��������:  SetAttributeDev
* ����:	 dolob.jiang
* ����  2011.11.02
* ����: char *ConnectStr, char *attrName,  int attrState
* ����:  ����ͨ�����Բ���(CommIsStr)
* ����ֵ:  short int
******************************************************************************/
//  
NTSSCRIPTLIB_API short int	__stdcall	SetAttributeDev(char *ConnectStr, char *attrName,  int attrState)
{
	if (attrState == 0)
	{
		gCommIsStr = false;
	}
	else
	{
		gCommIsStr = true;
	}
	return NTS_SUCCESS;
}


 

// Every DLL has an entry point LibMain || DllEntryPoint
// and an exit point WEP.
BOOL APIENTRY DllMain (HANDLE hModule, DWORD fdwReason, LPVOID lpReserved)
{	
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		{
//			g_Instance = (HINSTANCE)hModule;
//		    g_Instance++;
		    break;
		}
		
	case DLL_THREAD_ATTACH:
		break;
		
	case DLL_THREAD_DETACH:
		break;
		
	case DLL_PROCESS_DETACH:
/*
		if (instance>0)
		{
			for (int i = 0; i < MAXMETHOD + 1; i++)
				if (gMethodDev[i])
				{
					delete gMethodDev[i];
					gMethodDev[i]=0;
				}
				instance--;
		}
*/

		break;
	}
	
	return 1;
}