#include "StdAfx.h"
#include "stdio.h"
#include <stdlib.h>
//#include <conio.h>
#include <imagehlp.h>
#include "DllAnalyse.h"

#pragma comment(lib,"kernel32.lib")
#pragma comment(lib,"user32.lib")
#pragma comment(lib,"imagehlp.lib")


/******************************************************************************
* ��������:  AnalysisExportFunction
* ����:	 dolob.jiang
* ����  2009.08.25
* ����: void *pAddBase, const char* szDllName
* ����:  ��Map�ļ��л�ȡDLL�ĺ�������
* ����ֵ:  
******************************************************************************/
void AnalysisExportFunction(void *pAddBase, const char* szDllName, char **FunctionList, int *Count)
{
	PIMAGE_DOS_HEADER pdosHdr;
	PIMAGE_NT_HEADERS pntHdr;
	char decodestr[256];
	char funnames[1024][100] = {0};
	int FunCount = 0;
	
	*Count = 0;
	memset(decodestr,0,256);
	pdosHdr = (PIMAGE_DOS_HEADER)pAddBase;
	// ����ǲ���PE�ļ�
	if(pdosHdr->e_magic != IMAGE_DOS_SIGNATURE)
		return;
	// ����ƫ����������DOS������
	pntHdr = (PIMAGE_NT_HEADERS)(pdosHdr->e_lfanew + (DWORD)pAddBase);
	if(pntHdr->Signature != IMAGE_NT_SIGNATURE)
		return;
	PIMAGE_EXPORT_DIRECTORY pExport;
	DWORD dwSize;
	// �õ�������ĵ�ַ
	pExport = (PIMAGE_EXPORT_DIRECTORY)ImageDirectoryEntryToData(pAddBase, false, 
		IMAGE_DIRECTORY_ENTRY_EXPORT, &dwSize);
	// ��û�е�����
	if(pExport == NULL)
		return ;
	DWORD pExportBegin, pExportEnd;
	// �õ�����������ڴ��еĵ�ַ�ʹ�С
	pExportBegin = (DWORD)pntHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	pExportEnd = pExportBegin + dwSize;
	PWORD pOrdFun;
	// �õ�������ָ��
	char** spName = (char**)ImageRvaToVa(pntHdr, pAddBase, pExport->AddressOfNames, 0);
	// �õ���������ڵ�ַָ��
	PDWORD pFun = (PDWORD)ImageRvaToVa(pntHdr, pAddBase, 
		pExport->AddressOfFunctions, 0);
	// �õ�����˳���ָ��
	pOrdFun = (PWORD)ImageRvaToVa(pntHdr, pAddBase, pExport->AddressOfNameOrdinals, 0);
	if(pFun == 0)
		return;
	// �õ���������������ڵ�ַ
	for(DWORD i = 0; i < pExport->NumberOfFunctions; i++)
	{
		char *pName = 0;
		// �õ��������ָ��
		DWORD pFunPoint = *(pFun + i);
		if(pFunPoint == 0)
			continue;
		// DLL��Forword����������
		if(pFunPoint > pExportBegin && pFunPoint < pExportEnd)
			continue;
		// ����˳��ŵõ�������
		for(DWORD j = 0; j<pExport->NumberOfNames; j++)
		{
			if(*(pOrdFun + j) == i)
			{
				pName = (char*)ImageRvaToVa(pntHdr, pAddBase, (ULONG)*(spName + j), 0);
				
				sprintf(funnames[i], "%s", pName);
				*(FunctionList+i) = *(funnames + i);
//				sprintf(&FunctionList[i][0], "%s", pName);
				FunCount++;				
				break;
			}
		}
		if(pName)
		{
			UnDecorateSymbolName(pName,decodestr,256,UNDNAME_COMPLETE);
			//			printf("%s\n",decodestr); 
		}
	}
	*Count = FunCount;
}

/******************************************************************************
* ��������:  AnalysisFunction
* ����:	 dolob.jiang
* ����  2009.08.25
* ����: const char* szDllName, char **FunctionList, int *Count
* ����:  ��ȡDLL�ĺ�������
* ����ֵ:  
******************************************************************************/
void _stdcall AnalysisFunction(const char* szDllName, char **FunctionList, int *Count)
{
	HANDLE hFile = CreateFile(szDllName, GENERIC_READ, FILE_SHARE_READ |FILE_SHARE_WRITE,
		0, OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, 0);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		return;
	}
	HANDLE hMap = CreateFileMapping(hFile, 0, PAGE_READONLY, 0, 0, 0);
	if(hMap == 0) // ʧ��
	{
		CloseHandle(hFile);
		return;
	}
	LPVOID pMap = MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
	if(pMap)
	{
		AnalysisExportFunction(pMap, szDllName, FunctionList, Count);
	}
	UnmapViewOfFile(pMap);
	CloseHandle(hMap);
	CloseHandle(hFile);
}

/******************************************************************************
* ��������:  GetSubStr
* ����:	 dolob.jiang
* ����  2009.09.30
* ����: const char *SourceStr, char *Substr, int *Count
* ����:  ����_stdcall�����API�����������ͺ�����������
* ����ֵ:  
******************************************************************************/
void _stdcall GetSubStr(const char *SourceStr, char *Substr, int *Count)
{
	char tempstr[1024] = {0};

	int length = strlen(SourceStr);

	for(int i = 1; i< length; i++)
	{
		if (SourceStr[i] != '@')
		{
			tempstr[i-1] = SourceStr[i];
		}
		else
		{
			//
			*Count = atoi(&SourceStr[i+1]);
			break;
		}
	}
	sprintf(Substr, "%s", tempstr);
}