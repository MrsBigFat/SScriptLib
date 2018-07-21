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
* 函数名称:  AnalysisExportFunction
* 作者:	 dolob.jiang
* 日期  2009.08.25
* 参数: void *pAddBase, const char* szDllName
* 功能:  从Map文件中获取DLL的函数名称
* 返回值:  
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
	// 检查是不是PE文件
	if(pdosHdr->e_magic != IMAGE_DOS_SIGNATURE)
		return;
	// 计算偏移量，跳过DOS检查代码
	pntHdr = (PIMAGE_NT_HEADERS)(pdosHdr->e_lfanew + (DWORD)pAddBase);
	if(pntHdr->Signature != IMAGE_NT_SIGNATURE)
		return;
	PIMAGE_EXPORT_DIRECTORY pExport;
	DWORD dwSize;
	// 得到导出表的地址
	pExport = (PIMAGE_EXPORT_DIRECTORY)ImageDirectoryEntryToData(pAddBase, false, 
		IMAGE_DIRECTORY_ENTRY_EXPORT, &dwSize);
	// 有没有导出表
	if(pExport == NULL)
		return ;
	DWORD pExportBegin, pExportEnd;
	// 得到导出表的在内存中的地址和大小
	pExportBegin = (DWORD)pntHdr->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT].VirtualAddress;
	pExportEnd = pExportBegin + dwSize;
	PWORD pOrdFun;
	// 得到函数名指针
	char** spName = (char**)ImageRvaToVa(pntHdr, pAddBase, pExport->AddressOfNames, 0);
	// 得到函数的入口地址指针
	PDWORD pFun = (PDWORD)ImageRvaToVa(pntHdr, pAddBase, 
		pExport->AddressOfFunctions, 0);
	// 得到函数顺序表指针
	pOrdFun = (PWORD)ImageRvaToVa(pntHdr, pAddBase, pExport->AddressOfNameOrdinals, 0);
	if(pFun == 0)
		return;
	// 得到函数名及函数入口地址
	for(DWORD i = 0; i < pExport->NumberOfFunctions; i++)
	{
		char *pName = 0;
		// 得到函数入口指针
		DWORD pFunPoint = *(pFun + i);
		if(pFunPoint == 0)
			continue;
		// DLL的Forword函数不处理
		if(pFunPoint > pExportBegin && pFunPoint < pExportEnd)
			continue;
		// 根据顺序号得到函数名
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
* 函数名称:  AnalysisFunction
* 作者:	 dolob.jiang
* 日期  2009.08.25
* 参数: const char* szDllName, char **FunctionList, int *Count
* 功能:  获取DLL的函数名称
* 返回值:  
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
	if(hMap == 0) // 失败
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
* 函数名称:  GetSubStr
* 作者:	 dolob.jiang
* 日期  2009.09.30
* 参数: const char *SourceStr, char *Substr, int *Count
* 功能:  分离_stdcall定义的API函数方法名和函数参数个数
* 返回值:  
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