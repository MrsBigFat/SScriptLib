
#include "stdafx.h"
#include "AU3Method.h"
#include <assert.h>
#include "stdio.h"
#include <stdlib.h>
#include "math.h"
#include "windows.h"
#include "resource.h"
#include "NTSScriptLib.h"
using namespace std;

extern TDeviceManagerMap gDeviceManagerMap; //设备句柄管理器
extern BOOL gCommIsStr;						// 通用读写函数数据发送方式 True:字符串	false:数据流

 
  
wstring ANSIToUnicode( const string& str )
{
	int len = 0;
	len = str.length();
	int unicodeLen = MultiByteToWideChar( CP_ACP,
		0,
		str.c_str(),
		-1,
		NULL,
		0 ); 
	wchar_t * pUnicode; 
	pUnicode = new wchar_t[unicodeLen+1]; 
	memset(pUnicode,0,(unicodeLen+1)*sizeof(wchar_t)); 
	MultiByteToWideChar( CP_ACP,
		0,
		str.c_str(),
		-1,
		(LPWSTR)pUnicode,
		unicodeLen ); 
	wstring rt; 
	rt = ( wchar_t* )pUnicode;
	delete[] pUnicode; 
	return rt; 
}
 
string UnicodeToANSI( const wstring& str )
{
	char*     pElementText;
	int    iTextLen;
	// wide char to multi char
	iTextLen = WideCharToMultiByte( CP_ACP,
		0,
		str.c_str(),
		-1,
		NULL,
		0,
		NULL,
		NULL );
	pElementText = new char[iTextLen + 1];
	memset( ( void* )pElementText, 0, sizeof( char ) * ( iTextLen + 1 ) );
	::WideCharToMultiByte( CP_ACP,
		0,
		str.c_str(),
		-1,
		pElementText,
		iTextLen,
		NULL,
		NULL );
	string strText;
	strText = pElementText;
	delete[] pElementText;
	return strText;
}
/************************************************************************/
/* 特殊功能函数方法类                                                    */
/************************************************************************/
//class M_AU3_Run
M_AU3_Run::M_AU3_Run()
:BaseMethod()
{
	sprintf(m_MethodScript, "程序运行");
	m_InputProgram = CreateParamStruct();
	m_InputDir = CreateParamStruct();
	m_InputShowFlag = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
 
}
M_AU3_Run::~M_AU3_Run()
{
//	free(m_InputPara);
}
int M_AU3_Run::Init(void)
{
	sprintf(m_InputProgram->paramName, "运行文件");
	m_InputProgram->paramType = NTSString;
	m_InputProgram->paramCount = 1;
	sprintf(m_InputProgram->paramVal,"launcher.exe");
	sprintf(m_InputProgram->paramUnit , "");
	m_InputParamVector.push_back(m_InputProgram);


	sprintf(m_InputDir->paramName, "工作目录");
	m_InputDir->paramType = NTSString;
	m_InputDir->paramCount = 1;
	sprintf(m_InputDir->paramVal,"");
	sprintf(m_InputDir->paramUnit , "");
	m_InputParamVector.push_back(m_InputDir);

	sprintf(m_InputShowFlag->paramName, "显示状态");
	m_InputShowFlag->paramType = NTSInt16;
	m_InputShowFlag->paramCount = 1;
	sprintf(m_InputShowFlag->paramVal,"1");
	sprintf(m_InputShowFlag->paramUnit , "");
	m_InputParamVector.push_back(m_InputShowFlag);
	
	sprintf(m_OutputPara->paramName, "PID进程号");
	m_OutputPara->paramType = NTSInt32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);

	return NTS_SUCCESS;
 }

int M_AU3_Run::Run(void)
{
	wchar_t InputProgram[2000],InputDir[2000];
	int nShowFlag =  atoi(m_InputShowFlag->paramVal);
	wcscpy(InputProgram,ANSIToUnicode(m_InputProgram->paramVal).c_str());
	wcscpy(InputDir,ANSIToUnicode(m_InputDir->paramVal).c_str());
	int ret = AU3_Run(InputProgram,InputDir,nShowFlag);
	sprintf(m_OutputPara->paramVal, "%d",ret);
	return NTS_SUCCESS;
} 

//Runs an external program and pauses script execution until the program finishes.
M_AU3_RunWait::M_AU3_RunWait()
:BaseMethod()
{
	sprintf(m_MethodScript, "程序运行,并等待其运行结束(Runs an external program and pauses script execution until the program finishes.)");
	m_InputProgram = CreateParamStruct();
	m_InputDir = CreateParamStruct();
	m_InputShowFlag = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
	
}
M_AU3_RunWait::~M_AU3_RunWait()
{
	//	free(m_InputPara);
}
int M_AU3_RunWait::Init(void)
{
	sprintf(m_InputProgram->paramName, "运行文件");
	m_InputProgram->paramType = NTSString;
	m_InputProgram->paramCount = 1;
	sprintf(m_InputProgram->paramVal,"launcher.exe");
	sprintf(m_InputProgram->paramUnit , "");
	m_InputParamVector.push_back(m_InputProgram);
	
	
	sprintf(m_InputDir->paramName, "工作目录");
	m_InputDir->paramType = NTSString;
	m_InputDir->paramCount = 1;
	sprintf(m_InputDir->paramVal,"");
	sprintf(m_InputDir->paramUnit , "");
	m_InputParamVector.push_back(m_InputDir);
	
	sprintf(m_InputShowFlag->paramName, "显示状态");
	m_InputShowFlag->paramType = NTSInt16;
	m_InputShowFlag->paramCount = 1;
	sprintf(m_InputShowFlag->paramVal,"1");
	sprintf(m_InputShowFlag->paramUnit , "");
	m_InputParamVector.push_back(m_InputShowFlag);
	
	sprintf(m_OutputPara->paramName, "PID进程号");
	m_OutputPara->paramType = NTSInt32;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}

int M_AU3_RunWait::Run(void)
{
	wchar_t InputProgram[2000],InputDir[2000];
	int nShowFlag =  atoi(m_InputShowFlag->paramVal);
	wcscpy(InputProgram,ANSIToUnicode(m_InputProgram->paramVal).c_str());
	wcscpy(InputDir,ANSIToUnicode(m_InputDir->paramVal).c_str());
	int ret = AU3_RunWait(InputProgram,InputDir,nShowFlag);
	sprintf(m_OutputPara->paramVal, "%d",ret);
	return NTS_SUCCESS;
} 

//
M_AU3_WinWaitActive::M_AU3_WinWaitActive()
:BaseMethod()
{
	sprintf(m_MethodScript, "暂停脚本执行,直到请求的窗口激活");
	m_InputTitle = CreateParamStruct();
	m_InputText = CreateParamStruct();
	m_InputTimeout = CreateParamStruct();
	Init();
	
}
M_AU3_WinWaitActive::~M_AU3_WinWaitActive()
{
	//	free(m_InputPara);
}
int M_AU3_WinWaitActive::Init(void)
{
	sprintf(m_InputTitle->paramName, "目标窗口标题");
	m_InputTitle->paramType = NTSString;
	m_InputTitle->paramCount = 1;
	sprintf(m_InputTitle->paramVal,"Title");
	sprintf(m_InputTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputTitle);
	
	
	sprintf(m_InputText->paramName, "文本(可为空)");
	m_InputText->paramType = NTSString;
	m_InputText->paramCount = 1;
	sprintf(m_InputText->paramVal,"Text");
	sprintf(m_InputText->paramUnit , "");
	m_InputParamVector.push_back(m_InputText);
	
	sprintf(m_InputTimeout->paramName, "超时时间(s)");
	m_InputTimeout->paramType = NTSInt16;
	m_InputTimeout->paramCount = 1;
	sprintf(m_InputTimeout->paramVal,"10");
	sprintf(m_InputTimeout->paramUnit , "");
	m_InputParamVector.push_back(m_InputTimeout);

	return NTS_SUCCESS;
}

int M_AU3_WinWaitActive::Run(void)
{
	wchar_t title[2000], name[2000];
	int nTimeout =  atoi(m_InputTimeout->paramVal);
	wcscpy(title,ANSIToUnicode(m_InputTitle->paramVal).c_str());
	wcscpy(name,ANSIToUnicode(m_InputText->paramVal).c_str());
	int ret = AU3_WinWaitActive(title,name,nTimeout);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 *	发送模拟键击操作到激活窗口
 */
M_AU3_Send::M_AU3_Send()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送模拟键击操作到激活窗口");
	m_InputSendText = CreateParamStruct();
	m_InputMode = CreateParamStruct();
 
//	m_OutputPara = CreateParamStruct();
	Init();	
}

M_AU3_Send::~M_AU3_Send()
{
	//	free(m_InputPara);
}
int M_AU3_Send::Init(void)
{
	sprintf(m_InputSendText->paramName, "按键");
	m_InputSendText->paramType = NTSString;
	m_InputSendText->paramCount = 1;
	sprintf(m_InputSendText->paramVal,"key");
	sprintf(m_InputSendText->paramUnit , "");
	m_InputParamVector.push_back(m_InputSendText);
	
	
	sprintf(m_InputMode->paramName, "标志");
	m_InputMode->paramType = NTSInt32;
	m_InputMode->paramCount = 1;
	sprintf(m_InputMode->paramVal,"%d", 0);
	sprintf(m_InputMode->paramUnit , "");
	m_InputParamVector.push_back(m_InputMode);
 
	return NTS_SUCCESS;
}
int M_AU3_Send::Run(void)
{
	wchar_t  sendText[2000];
	int nMode = atoi(m_InputMode->paramVal);
	wcscpy(sendText,ANSIToUnicode(m_InputSendText->paramVal).c_str());
	AU3_Send(sendText, nMode);
//	sprintf(m_OutputPara->paramVal, "%d",ret); 
	return NTS_SUCCESS;
} 

/*************************************************************************
 *	发送鼠标点击命令到指定控件
 */
M_AU3_ControlClick::M_AU3_ControlClick()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送鼠标点击命令到指定控件(成功:1 失败:0) \
		鼠标按键:left, right, middle, main, menu, primary, secondary");
	m_InputTitle = CreateParamStruct();
	m_InputText = CreateParamStruct();
	m_InputControl = CreateParamStruct();
	m_InputButton = CreateParamStruct();
	m_InputClicks = CreateParamStruct();
	m_InputX = CreateParamStruct();
	m_InputY = CreateParamStruct();
	Init();
	
}

M_AU3_ControlClick::~M_AU3_ControlClick()
{
	//	free(m_InputPara);
}
int M_AU3_ControlClick::Init(void)
{
	sprintf(m_InputTitle->paramName, "目标窗口标题");
	m_InputTitle->paramType = NTSString;
	m_InputTitle->paramCount = 1;
	sprintf(m_InputTitle->paramVal,"title");
	sprintf(m_InputTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputTitle);
	
	
	sprintf(m_InputText->paramName, "文本(可为空)");
	m_InputText->paramType = NTSString;
	m_InputText->paramCount = 1;
	sprintf(m_InputText->paramVal,"text");
	sprintf(m_InputText->paramUnit , "");
	m_InputParamVector.push_back(m_InputText);
	
	sprintf(m_InputControl->paramName, "控件ID");
	m_InputControl->paramType = NTSString;
	m_InputControl->paramCount = 1;
	sprintf(m_InputControl->paramVal,"ControlId");
	sprintf(m_InputControl->paramUnit , "");
	m_InputParamVector.push_back(m_InputControl);
	
	sprintf(m_InputButton->paramName, "鼠标按键");
	m_InputButton->paramType = NTSString;
	m_InputButton->paramCount = 1;
	sprintf(m_InputButton->paramVal,"left");
	sprintf(m_InputButton->paramUnit, " ");
	m_InputParamVector.push_back(m_InputButton);
	
	sprintf(m_InputClicks->paramName, "点击次数");
	m_InputClicks->paramType = NTSInt32;
	m_InputClicks->paramCount = 1;
	sprintf(m_InputClicks->paramVal,"1");
	sprintf(m_InputClicks->paramUnit , "");
	m_InputParamVector.push_back(m_InputClicks);
	
	sprintf(m_InputX->paramName, "x 坐标");
	m_InputX->paramType = NTSInt32;
	m_InputX->paramCount = 1;
	sprintf(m_InputX->paramVal,"%d", AU3_INTDEFAULT);
	sprintf(m_InputX->paramUnit , "");
	m_InputParamVector.push_back(m_InputX);
	
	sprintf(m_InputY->paramName, "Y 坐标");
	m_InputY->paramType = NTSInt32;
	m_InputY->paramCount = 1;
	sprintf(m_InputY->paramVal,"%d", AU3_INTDEFAULT);
	sprintf(m_InputY->paramUnit, " ");
	m_InputParamVector.push_back(m_InputY);
	
	return NTS_SUCCESS;
}
int M_AU3_ControlClick::Run(void)
{
	wchar_t title[2000],text[2000],controlID[2000],button[2000];
	int nNumClicks = atoi(m_InputClicks->paramVal);
	int nX = atoi(m_InputX->paramVal);
	int nY = atoi(m_InputY->paramVal);
	wcscpy(title,ANSIToUnicode(m_InputTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputText->paramVal).c_str());
	wcscpy(controlID,ANSIToUnicode(m_InputControl->paramVal).c_str());
	wcscpy(button,ANSIToUnicode(m_InputButton->paramVal).c_str());
	
	int ret = AU3_ControlClick(title, text, controlID, button, nNumClicks, nX, nY);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 *	设置控件文本
 */
M_AU3_ControlSetText::M_AU3_ControlSetText()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置控件文本(Sets text of a control.) ");
	m_InputTitle = CreateParamStruct();
	m_InputText = CreateParamStruct();
	m_InputControl = CreateParamStruct();
	m_InputControlText = CreateParamStruct();
	Init();	
}

M_AU3_ControlSetText::~M_AU3_ControlSetText()
{
	//	free(m_InputPara);
}
int M_AU3_ControlSetText::Init(void)
{
	sprintf(m_InputTitle->paramName, "目标窗口标题");
	m_InputTitle->paramType = NTSString;
	m_InputTitle->paramCount = 1;
	sprintf(m_InputTitle->paramVal,"title");
	sprintf(m_InputTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputTitle);
	
	
	sprintf(m_InputText->paramName, "文本(可为空)");
	m_InputText->paramType = NTSString;
	m_InputText->paramCount = 1;
	sprintf(m_InputText->paramVal,"text");
	sprintf(m_InputText->paramUnit , "");
	m_InputParamVector.push_back(m_InputText);
	
	sprintf(m_InputControl->paramName, "控件ID");
	m_InputControl->paramType = NTSString;
	m_InputControl->paramCount = 1;
	sprintf(m_InputControl->paramVal,"ControlId");
	sprintf(m_InputControl->paramUnit , "");
	m_InputParamVector.push_back(m_InputControl);
	
	sprintf(m_InputControlText->paramName, "发送文本");
	m_InputControlText->paramType = NTSString;
	m_InputControlText->paramCount = 1;
	sprintf(m_InputControlText->paramVal,"");
	sprintf(m_InputControlText->paramUnit, " ");
	m_InputParamVector.push_back(m_InputControlText);
	
	return NTS_SUCCESS;
}
int M_AU3_ControlSetText::Run(void)
{
	wchar_t title[2000],text[2000],controlID[2000],ControlText[2000];
	wcscpy(title,ANSIToUnicode(m_InputTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputText->paramVal).c_str());
	wcscpy(controlID,ANSIToUnicode(m_InputControl->paramVal).c_str());
	wcscpy(ControlText,ANSIToUnicode(m_InputControlText->paramVal).c_str());
	int ret = AU3_ControlSetText(title, text, controlID, ControlText);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 
/*************************************************************************
 *	获取控件文本
 */
M_AU3_ControlGetText::M_AU3_ControlGetText()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取控件文本");
	m_InputTitle = CreateParamStruct();
	m_InputText = CreateParamStruct();
	m_InputControl = CreateParamStruct();
	m_InputParanBufSize = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
	
}

M_AU3_ControlGetText::~M_AU3_ControlGetText()
{
	//	free(m_InputPara);
}
int M_AU3_ControlGetText::Init(void)
{
	sprintf(m_InputTitle->paramName, "目标窗口标题");
	m_InputTitle->paramType = NTSString;
	m_InputTitle->paramCount = 1;
	sprintf(m_InputTitle->paramVal,"title");
	sprintf(m_InputTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputTitle);
	
	
	sprintf(m_InputText->paramName, "文本(可为空)");
	m_InputText->paramType = NTSString;
	m_InputText->paramCount = 1;
	sprintf(m_InputText->paramVal,"Text");
	sprintf(m_InputText->paramUnit , "");
	m_InputParamVector.push_back(m_InputText);
	
	sprintf(m_InputControl->paramName, "控件ID");
	m_InputControl->paramType = NTSString;
	m_InputControl->paramCount = 1;
	sprintf(m_InputControl->paramVal,"controlId");
	sprintf(m_InputControl->paramUnit , "");
	m_InputParamVector.push_back(m_InputControl);

	sprintf(m_InputParanBufSize->paramName, "获取文本长度");
	m_InputParanBufSize->paramType = NTSInt32;
	m_InputParanBufSize->paramCount = 1;
	sprintf(m_InputParanBufSize->paramVal, "5000");
	sprintf(m_InputParanBufSize->paramUnit , "");
	m_InputParamVector.push_back(m_InputParanBufSize);
	
	sprintf(m_OutputPara->paramName, "返回值");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_AU3_ControlGetText::Run(void)
{
	wchar_t title[2000],text[2000],controlID[2000];

	wcscpy(title,ANSIToUnicode(m_InputTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputText->paramVal).c_str());
	wcscpy(controlID,ANSIToUnicode(m_InputControl->paramVal).c_str());
	int nBufSize = atoi(m_InputParanBufSize->paramVal);
	wchar_t* result = new wchar_t[nBufSize];
 
	AU3_ControlGetText(title, text, controlID, result, nBufSize);
	strcpy(m_OutputPara->paramVal,UnicodeToANSI(result).c_str());  
	
	delete[] result;
	return NTS_SUCCESS;
} 

/*************************************************************************
 *   发送命令到控件ListBox or ComboBox	
 */
M_AU3_ControlCommand::M_AU3_ControlCommand()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送命令到控件ListBox 、ComboBox、Edit、SysTabControl32、radio、Button等");
	m_InputTitle = CreateParamStruct();
	m_InputText = CreateParamStruct();
	m_InputControl = CreateParamStruct();
	m_InputCommand = CreateParamStruct();
	m_InputExtra1 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
	
}
M_AU3_ControlCommand::~M_AU3_ControlCommand()
{
	//	free(m_InputPara);
}
int M_AU3_ControlCommand::Init(void)
{
	sprintf(m_InputTitle->paramName, "目标窗口标题");
	m_InputTitle->paramType = NTSString;
	m_InputTitle->paramCount = 1;
	sprintf(m_InputTitle->paramVal,"title");
	sprintf(m_InputTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputTitle);
	

	sprintf(m_InputText->paramName, "文本(可为空)");
	m_InputText->paramType = NTSString;
	m_InputText->paramCount = 1;
	sprintf(m_InputText->paramVal,"Test");
	sprintf(m_InputText->paramUnit , "");
	m_InputParamVector.push_back(m_InputText);
		
	sprintf(m_InputControl->paramName, "控件ID");
	m_InputControl->paramType = NTSString;
	m_InputControl->paramCount = 1;
	sprintf(m_InputControl->paramVal,"ControlId");
	sprintf(m_InputControl->paramUnit , "");
	m_InputParamVector.push_back(m_InputControl);

	sprintf(m_InputCommand->paramName, "发送到控件的命令");
	m_InputCommand->paramType = NTSString;
	m_InputCommand->paramCount = 1;
	sprintf(m_InputCommand->paramVal,"Command");
	sprintf(m_InputCommand->paramUnit , "");
	m_InputParamVector.push_back(m_InputCommand);
 
	sprintf(m_InputExtra1->paramName, "附加参数1");
	m_InputExtra1->paramType = NTSString;
	m_InputExtra1->paramCount = 1;
	sprintf(m_InputExtra1->paramVal,"option1");
	sprintf(m_InputExtra1->paramUnit , "");
	m_InputParamVector.push_back(m_InputExtra1);

 
	sprintf(m_OutputPara->paramName, "返回值");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
 	
	return NTS_SUCCESS;
}
int M_AU3_ControlCommand::Run(void)
{
	wchar_t title[2000],text[2000],controlID[2000],command[2000],extra1[2000];
	wchar_t result[5000];
	int nBufSize = 5000;
	wcscpy(title,ANSIToUnicode(m_InputTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputText->paramVal).c_str());
	wcscpy(controlID,ANSIToUnicode(m_InputControl->paramVal).c_str());
	wcscpy(command,ANSIToUnicode(m_InputCommand->paramVal).c_str());
	wcscpy(extra1,ANSIToUnicode(m_InputExtra1->paramVal).c_str());

 	AU3_ControlCommand(title, text, controlID, command, extra1, result, nBufSize);
	strcpy(m_OutputPara->paramVal,UnicodeToANSI(result).c_str());  
	return NTS_SUCCESS;
} 


/*************************************************************************
 *   ListView控件操作	
 */
M_AU3_ControlListView::M_AU3_ControlListView()
:BaseMethod()
{
	sprintf(m_MethodScript, "发送命令到 ListView32 控件.");
	m_InputTitle = CreateParamStruct();
	m_InputText = CreateParamStruct();
	m_InputControl = CreateParamStruct();
	m_InputCommand = CreateParamStruct();
	m_InputExtra1 = CreateParamStruct();
	m_InputExtra2 = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
	
}
M_AU3_ControlListView::~M_AU3_ControlListView()
{
	//	free(m_InputPara);
}
int M_AU3_ControlListView::Init(void)
{
	sprintf(m_InputTitle->paramName, "目标窗口标题");
	m_InputTitle->paramType = NTSString;
	m_InputTitle->paramCount = 1;
	sprintf(m_InputTitle->paramVal,"title");
	sprintf(m_InputTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputTitle);
	

	sprintf(m_InputText->paramName, "文本(可为空)");
	m_InputText->paramType = NTSString;
	m_InputText->paramCount = 1;
	sprintf(m_InputText->paramVal,"Text");
	sprintf(m_InputText->paramUnit , "");
	m_InputParamVector.push_back(m_InputText);
		
	sprintf(m_InputControl->paramName, "控件ID");
	m_InputControl->paramType = NTSString;
	m_InputControl->paramCount = 1;
	sprintf(m_InputControl->paramVal,"ControlId");
	sprintf(m_InputControl->paramUnit , "");
	m_InputParamVector.push_back(m_InputControl);

	sprintf(m_InputCommand->paramName, "发送到控件的命令");
	m_InputCommand->paramType = NTSString;
	m_InputCommand->paramCount = 1;
	sprintf(m_InputCommand->paramVal,"Command");
	sprintf(m_InputCommand->paramUnit , "");
	m_InputParamVector.push_back(m_InputCommand);
 
	sprintf(m_InputExtra1->paramName, "附加参数1");
	m_InputExtra1->paramType = NTSString;
	m_InputExtra1->paramCount = 1;
	sprintf(m_InputExtra1->paramVal,"option1");
	sprintf(m_InputExtra1->paramUnit , "");
	m_InputParamVector.push_back(m_InputExtra1);

	sprintf(m_InputExtra2->paramName, "附加参数2");
	m_InputExtra2->paramType = NTSString;
	m_InputExtra2->paramCount = 1;
	sprintf(m_InputExtra2->paramVal,"option2");
	sprintf(m_InputExtra2->paramUnit , "");
	m_InputParamVector.push_back(m_InputExtra2);
	
	sprintf(m_OutputPara->paramName, "返回值");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
 	
	return NTS_SUCCESS;
}
int M_AU3_ControlListView::Run(void)
{
	wchar_t title[2000],text[2000],controlID[2000],command[2000],extra1[2000],extra2[2000];
	wchar_t result[5000];
	int nBufSize = 5000;
	wcscpy(title,ANSIToUnicode(m_InputTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputText->paramVal).c_str());
	wcscpy(controlID,ANSIToUnicode(m_InputControl->paramVal).c_str());
	wcscpy(command,ANSIToUnicode(m_InputCommand->paramVal).c_str());
	wcscpy(extra1,ANSIToUnicode(m_InputExtra1->paramVal).c_str());
	wcscpy(extra2,ANSIToUnicode(m_InputExtra2->paramVal).c_str());
 	AU3_ControlListView(title, text, controlID, command, extra1, extra2, result, nBufSize);
	strcpy(m_OutputPara->paramVal,UnicodeToANSI(result).c_str());  
	return NTS_SUCCESS;
} 


/*************************************************************************
 *   Retrieves text from the clipboard.	
 */
M_AU3_ClipGet::M_AU3_ClipGet()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取剪切板中文本(Retrieves text from the clipboard.)");
	m_InputBufSize = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
	
}
M_AU3_ClipGet::~M_AU3_ClipGet()
{
	//	free(m_InputPara);
}
int M_AU3_ClipGet::Init(void)
{
	sprintf(m_InputBufSize->paramName, "获取文本长度");
	m_InputBufSize->paramType = NTSInt32;
	m_InputBufSize->paramCount = 1;
	sprintf(m_InputBufSize->paramVal,"1024");
	sprintf(m_InputBufSize->paramUnit , "");
	m_InputParamVector.push_back(m_InputBufSize);

	sprintf(m_OutputPara->paramName, "返回值");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
 	
	return NTS_SUCCESS;
}
int M_AU3_ClipGet::Run(void)
{
	int bufSize;

	bufSize = atoi(m_InputBufSize->paramVal);
	wchar_t* result = new wchar_t[bufSize];

	AU3_ClipGet(result, bufSize);
	strcpy(m_OutputPara->paramVal,UnicodeToANSI(result).c_str());  
	
	delete[] result;
	return NTS_SUCCESS;
} 

/*************************************************************************
 *   Writes text to the clipboard.
 */
M_AU3_ClipPut::M_AU3_ClipPut()
:BaseMethod()
{
	sprintf(m_MethodScript, "将文本写入剪切板(Writes text to the clipboard.)");
	m_InputPara = CreateParamStruct();
	Init();
	
}
M_AU3_ClipPut::~M_AU3_ClipPut()
{
	//	free(m_InputPara);
}
int M_AU3_ClipPut::Init(void)
{
	sprintf(m_InputPara->paramName, "写入剪切板文本");
	m_InputPara->paramType = NTSString;
	m_InputPara->paramCount = 1;
	sprintf(m_InputPara->paramVal,"");
	sprintf(m_InputPara->paramUnit , "");
	m_InputParamVector.push_back(m_InputPara);

	return NTS_SUCCESS;
}
int M_AU3_ClipPut::Run(void)
{
	AU3_ClipPut(ANSIToUnicode(m_InputPara->paramVal).c_str());

	return NTS_SUCCESS;
} 

/*************************************************************************
 *   Disables or "grays-out" a control.
 */
M_AU3_ControlDisable::M_AU3_ControlDisable()
:BaseMethod()
{
	sprintf(m_MethodScript, "控件去使能(Disables or grays-out a control.)");
	m_InputParaTitle = CreateParamStruct();
	m_InputParaText = CreateParamStruct();
	m_InputParaControlID = CreateParamStruct();
	Init();
}
M_AU3_ControlDisable::~M_AU3_ControlDisable()
{
	//	free(m_InputPara);
}
int M_AU3_ControlDisable::Init(void)
{
	sprintf(m_InputParaTitle->paramName, "目标窗口标题");
	m_InputParaTitle->paramType = NTSString;
	m_InputParaTitle->paramCount = 1;
	sprintf(m_InputParaTitle->paramVal,"title");
	sprintf(m_InputParaTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaTitle);
	
	
	sprintf(m_InputParaText->paramName, "文本(可为空)");
	m_InputParaText->paramType = NTSString;
	m_InputParaText->paramCount = 1;
	sprintf(m_InputParaText->paramVal,"text");
	sprintf(m_InputParaText->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaText);
	
	sprintf(m_InputParaControlID->paramName, "控件ID");
	m_InputParaControlID->paramType = NTSString;
	m_InputParaControlID->paramCount = 1;
	sprintf(m_InputParaControlID->paramVal,"ControlId");
	sprintf(m_InputParaControlID->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaControlID);

	return NTS_SUCCESS;
}
int M_AU3_ControlDisable::Run(void)
{
	wchar_t title[2000],text[2000],controlID[2000];

	wcscpy(title,ANSIToUnicode(m_InputParaTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputParaText->paramVal).c_str());
	wcscpy(controlID,ANSIToUnicode(m_InputParaControlID->paramVal).c_str());

	int ret = AU3_ControlDisable(title, text, controlID);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 *   Enables a "grayed-out" control.
 */
M_AU3_ControlEnable::M_AU3_ControlEnable()
:BaseMethod()
{
	sprintf(m_MethodScript, "控件使能(Enables a grayed-out control.)");
	m_InputParaTitle = CreateParamStruct();
	m_InputParaText = CreateParamStruct();
	m_InputParaControlID = CreateParamStruct();
	Init();
}
M_AU3_ControlEnable::~M_AU3_ControlEnable()
{
	//	free(m_InputPara);
}
int M_AU3_ControlEnable::Init(void)
{
	sprintf(m_InputParaTitle->paramName, "目标窗口标题");
	m_InputParaTitle->paramType = NTSString;
	m_InputParaTitle->paramCount = 1;
	sprintf(m_InputParaTitle->paramVal,"title");
	sprintf(m_InputParaTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaTitle);
	
	
	sprintf(m_InputParaText->paramName, "文本(可为空)");
	m_InputParaText->paramType = NTSString;
	m_InputParaText->paramCount = 1;
	sprintf(m_InputParaText->paramVal,"text");
	sprintf(m_InputParaText->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaText);
	
	sprintf(m_InputParaControlID->paramName, "控件ID");
	m_InputParaControlID->paramType = NTSString;
	m_InputParaControlID->paramCount = 1;
	sprintf(m_InputParaControlID->paramVal,"ControlId");
	sprintf(m_InputParaControlID->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaControlID);

	return NTS_SUCCESS;
}
int M_AU3_ControlEnable::Run(void)
{
	wchar_t title[2000],text[2000],controlID[2000];

	wcscpy(title,ANSIToUnicode(m_InputParaTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputParaText->paramVal).c_str());
	wcscpy(controlID,ANSIToUnicode(m_InputParaControlID->paramVal).c_str());

	int ret = AU3_ControlEnable(title, text, controlID);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 


/*************************************************************************
 * Sets input focus to a given control on a window.
 */
M_AU3_ControlFocus::M_AU3_ControlFocus()
:BaseMethod()
{
	sprintf(m_MethodScript, "设置焦点(Sets input focus to a given control on a window.)");
	m_InputParaTitle = CreateParamStruct();
	m_InputParaText = CreateParamStruct();
	m_InputParaControlID = CreateParamStruct();
	Init();
}
M_AU3_ControlFocus::~M_AU3_ControlFocus()
{
	//	free(m_InputPara);
}
int M_AU3_ControlFocus::Init(void)
{
	sprintf(m_InputParaTitle->paramName, "目标窗口标题");
	m_InputParaTitle->paramType = NTSString;
	m_InputParaTitle->paramCount = 1;
	sprintf(m_InputParaTitle->paramVal,"title");
	sprintf(m_InputParaTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaTitle);
	
	
	sprintf(m_InputParaText->paramName, "文本(可为空)");
	m_InputParaText->paramType = NTSString;
	m_InputParaText->paramCount = 1;
	sprintf(m_InputParaText->paramVal,"text");
	sprintf(m_InputParaText->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaText);
	
	sprintf(m_InputParaControlID->paramName, "控件ID");
	m_InputParaControlID->paramType = NTSString;
	m_InputParaControlID->paramCount = 1;
	sprintf(m_InputParaControlID->paramVal,"ControlId");
	sprintf(m_InputParaControlID->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaControlID);

	return NTS_SUCCESS;
}
int M_AU3_ControlFocus::Run(void)
{
	wchar_t title[2000],text[2000],controlID[2000];

	wcscpy(title,ANSIToUnicode(m_InputParaTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputParaText->paramVal).c_str());
	wcscpy(controlID,ANSIToUnicode(m_InputParaControlID->paramVal).c_str());

	int ret = AU3_ControlFocus(title, text, controlID);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 * Returns the ControlRef# of the control that has keyboard focus within a specified window.
 */
M_AU3_ControlGetFocus::M_AU3_ControlGetFocus()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取焦点控件(Returns the ControlRef# of the control that has keyboard focus within a specified window.\r\n\
Return Value: the ClassNameNN of the control that has keyboard focus within a specified window.)");
	m_InputParaTitle = CreateParamStruct();
	m_InputParaText = CreateParamStruct();
	m_InputParanBufSize = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_AU3_ControlGetFocus::~M_AU3_ControlGetFocus()
{
	//	free(m_InputPara);
}
int M_AU3_ControlGetFocus::Init(void)
{
	sprintf(m_InputParaTitle->paramName, "目标窗口标题");
	m_InputParaTitle->paramType = NTSString;
	m_InputParaTitle->paramCount = 1;
	sprintf(m_InputParaTitle->paramVal,"title");
	sprintf(m_InputParaTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaTitle);
	
	
	sprintf(m_InputParaText->paramName, "文本(可为空)");
	m_InputParaText->paramType = NTSString;
	m_InputParaText->paramCount = 1;
	sprintf(m_InputParaText->paramVal,"text");
	sprintf(m_InputParaText->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaText);
	
	sprintf(m_InputParanBufSize->paramName, "nBufSize");
	m_InputParanBufSize->paramType = NTSInt32;
	m_InputParanBufSize->paramCount = 1;
	sprintf(m_InputParanBufSize->paramVal, "5000");
	sprintf(m_InputParanBufSize->paramUnit , "");
	m_InputParamVector.push_back(m_InputParanBufSize);

	sprintf(m_OutputPara->paramName, "返回值");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_AU3_ControlGetFocus::Run(void)
{
	wchar_t title[2000],text[2000];

	wcscpy(title,ANSIToUnicode(m_InputParaTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputParaText->paramVal).c_str());
	int nBufSize = atoi(m_InputParanBufSize->paramVal);
	wchar_t* controlWithFocus = new wchar_t[nBufSize];
	
	AU3_ControlGetFocus(title, text, controlWithFocus, nBufSize);
	strcpy(m_OutputPara->paramVal,UnicodeToANSI(controlWithFocus).c_str());  

	delete[] controlWithFocus;
	if(strcmp(m_OutputPara->paramVal, "")==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 * Retrieves the position and size of a control relative to its window.
 */
M_AU3_ControlGetPos::M_AU3_ControlGetPos()
:BaseMethod()
{
	sprintf(m_MethodScript, "获取控件大小和相对窗体位置(Retrieves the position and size of a control relative to its window.\r\n\
Return Value:top,bottom,left,right");
	m_InputParaTitle = CreateParamStruct();
	m_InputParaText = CreateParamStruct();
	m_InputParaControlID = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
}
M_AU3_ControlGetPos::~M_AU3_ControlGetPos()
{
	//	free(m_InputPara);
}
int M_AU3_ControlGetPos::Init(void)
{
	sprintf(m_InputParaTitle->paramName, "目标窗口标题");
	m_InputParaTitle->paramType = NTSString;
	m_InputParaTitle->paramCount = 1;
	sprintf(m_InputParaTitle->paramVal,"title");
	sprintf(m_InputParaTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaTitle);
	
	
	sprintf(m_InputParaText->paramName, "文本(可为空)");
	m_InputParaText->paramType = NTSString;
	m_InputParaText->paramCount = 1;
	sprintf(m_InputParaText->paramVal,"text");
	sprintf(m_InputParaText->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaText);
	
	sprintf(m_InputParaControlID->paramName, "控件ID");
	m_InputParaControlID->paramType = NTSString;
	m_InputParaControlID->paramCount = 1;
	sprintf(m_InputParaControlID->paramVal,"ControlId");
	sprintf(m_InputParaControlID->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaControlID);

	sprintf(m_OutputPara->paramName, "返回值");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}
int M_AU3_ControlGetPos::Run(void)
{
	wchar_t title[2000],text[2000],controlID[2000];
	RECT vRect = {0,0,0,0};
	
	wcscpy(title,ANSIToUnicode(m_InputParaTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputParaText->paramVal).c_str());
	wcscpy(controlID,ANSIToUnicode(m_InputParaControlID->paramVal).c_str());
	
	int ret = AU3_ControlGetPos(title, text, controlID, &vRect);
	sprintf(m_OutputPara->paramVal, "%d%s%d%s%d%s%d",vRect.top,",",vRect.bottom, ",",vRect.left,",", vRect.right); 

	if ((vRect.top==0)&&(vRect.bottom==0)&&(vRect.left==0)&&(vRect.right==0))
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 * Hides a control.
 */
M_AU3_ControlHide::M_AU3_ControlHide()
:BaseMethod()
{
	sprintf(m_MethodScript, "隐藏控件(Hides a control.)");
	m_InputParaTitle = CreateParamStruct();
	m_InputParaText = CreateParamStruct();
	m_InputParaControlID = CreateParamStruct();
	Init();
}
M_AU3_ControlHide::~M_AU3_ControlHide()
{
	//	free(m_InputPara);
}
int M_AU3_ControlHide::Init(void)
{
	sprintf(m_InputParaTitle->paramName, "目标窗口标题");
	m_InputParaTitle->paramType = NTSString;
	m_InputParaTitle->paramCount = 1;
	sprintf(m_InputParaTitle->paramVal,"title");
	sprintf(m_InputParaTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaTitle);
	
	
	sprintf(m_InputParaText->paramName, "文本(可为空)");
	m_InputParaText->paramType = NTSString;
	m_InputParaText->paramCount = 1;
	sprintf(m_InputParaText->paramVal,"text");
	sprintf(m_InputParaText->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaText);
	
	sprintf(m_InputParaControlID->paramName, "控件ID");
	m_InputParaControlID->paramType = NTSString;
	m_InputParaControlID->paramCount = 1;
	sprintf(m_InputParaControlID->paramVal,"ControlId");
	sprintf(m_InputParaControlID->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaControlID);

	return NTS_SUCCESS;
}
int M_AU3_ControlHide::Run(void)
{
	wchar_t title[2000],text[2000],controlID[2000];

	wcscpy(title,ANSIToUnicode(m_InputParaTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputParaText->paramVal).c_str());
	wcscpy(controlID,ANSIToUnicode(m_InputParaControlID->paramVal).c_str());

	int ret = AU3_ControlHide(title, text, controlID);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 * Moves a control within a window.
 */
M_AU3_ControlMove::M_AU3_ControlMove()
:BaseMethod()
{
	sprintf(m_MethodScript, "移动控件(Moves a control within a window.)");
	m_InputParaTitle = CreateParamStruct();
	m_InputParaText = CreateParamStruct();
	m_InputParaControlID = CreateParamStruct();
	m_InputnX = CreateParamStruct();
	m_InputnY = CreateParamStruct();
	m_InputnWidth = CreateParamStruct();
	m_InputnHeight = CreateParamStruct();
	Init();
}
M_AU3_ControlMove::~M_AU3_ControlMove()
{
	//	free(m_InputPara);
}
int M_AU3_ControlMove::Init(void)
{
	sprintf(m_InputParaTitle->paramName, "目标窗口标题");
	m_InputParaTitle->paramType = NTSString;
	m_InputParaTitle->paramCount = 1;
	sprintf(m_InputParaTitle->paramVal,"title");
	sprintf(m_InputParaTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaTitle);
	
	
	sprintf(m_InputParaText->paramName, "文本(可为空)");
	m_InputParaText->paramType = NTSString;
	m_InputParaText->paramCount = 1;
	sprintf(m_InputParaText->paramVal,"text");
	sprintf(m_InputParaText->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaText);
	
	sprintf(m_InputParaControlID->paramName, "控件ID");
	m_InputParaControlID->paramType = NTSString;
	m_InputParaControlID->paramCount = 1;
	sprintf(m_InputParaControlID->paramVal,"ControlId");
	sprintf(m_InputParaControlID->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaControlID);

	sprintf(m_InputnX->paramName, "X坐标(相对窗体左上角)");
	m_InputnX->paramType = NTSInt32;
	m_InputnX->paramCount = 1;
	sprintf(m_InputnX->paramVal, "0");
	sprintf(m_InputnX->paramUnit , "");
	m_InputParamVector.push_back(m_InputnX);

	sprintf(m_InputnY->paramName, "Y坐标(相对窗体左上角)");
	m_InputnY->paramType = NTSInt32;
	m_InputnY->paramCount = 1;
	sprintf(m_InputnY->paramVal, "0");
	sprintf(m_InputnY->paramUnit , "");
	m_InputParamVector.push_back(m_InputnY);

	sprintf(m_InputnWidth->paramName, "控件宽度(默认-1)");
	m_InputnWidth->paramType = NTSInt32;
	m_InputnWidth->paramCount = 1;
	sprintf(m_InputnWidth->paramVal, "-1");
	sprintf(m_InputnWidth->paramUnit , "");
	m_InputParamVector.push_back(m_InputnWidth);

	sprintf(m_InputnHeight->paramName, "控件高度(默认-1)");
	m_InputnHeight->paramType = NTSInt32;
	m_InputnHeight->paramCount = 1;
	sprintf(m_InputnHeight->paramVal, "-1");
	sprintf(m_InputnHeight->paramUnit , "");
	m_InputParamVector.push_back(m_InputnHeight);

	return NTS_SUCCESS;
}
int M_AU3_ControlMove::Run(void)
{
	wchar_t title[2000],text[2000],controlID[2000];

	wcscpy(title,ANSIToUnicode(m_InputParaTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputParaText->paramVal).c_str());
	wcscpy(controlID,ANSIToUnicode(m_InputParaControlID->paramVal).c_str());
	int nX = atoi(m_InputnX->paramVal);
	int nY = atoi(m_InputnY->paramVal);
	int nWidth = atoi(m_InputnWidth->paramVal);
	int nHeight = atoi(m_InputnHeight->paramVal);

	int ret = AU3_ControlMove(title, text, controlID, nX, nY, nWidth, nHeight);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 * Sends a string of characters to a control.
 */
M_AU3_ControlSend::M_AU3_ControlSend()
:BaseMethod()
{
	sprintf(m_MethodScript, "向控件发送字符串(Sends a string of characters to a control.)\r\n\
字符串：String of characters to send to the control.\r\n\
模式：0->(default) Text contains special characters like + to indicate SHIFT and {LEFT} to indicate left arrow.  1 -> keys are sent raw.");
	m_InputParaTitle = CreateParamStruct();
	m_InputParaText = CreateParamStruct();
	m_InputParaControlID = CreateParamStruct();
	m_InputSendText = CreateParamStruct();
	m_InputnMode = CreateParamStruct();

	Init();
}
M_AU3_ControlSend::~M_AU3_ControlSend()
{
	//	free(m_InputPara);
}
int M_AU3_ControlSend::Init(void)
{
	sprintf(m_InputParaTitle->paramName, "目标窗口标题");
	m_InputParaTitle->paramType = NTSString;
	m_InputParaTitle->paramCount = 1;
	sprintf(m_InputParaTitle->paramVal,"title");
	sprintf(m_InputParaTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaTitle);
	
	
	sprintf(m_InputParaText->paramName, "文本(可为空)");
	m_InputParaText->paramType = NTSString;
	m_InputParaText->paramCount = 1;
	sprintf(m_InputParaText->paramVal,"text");
	sprintf(m_InputParaText->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaText);
	
	sprintf(m_InputParaControlID->paramName, "控件ID");
	m_InputParaControlID->paramType = NTSString;
	m_InputParaControlID->paramCount = 1;
	sprintf(m_InputParaControlID->paramVal,"ControlId");
	sprintf(m_InputParaControlID->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaControlID);

	sprintf(m_InputSendText->paramName, "字符串");
	m_InputSendText->paramType = NTSString;
	m_InputSendText->paramCount = 1;
	sprintf(m_InputSendText->paramVal,"string");
	sprintf(m_InputSendText->paramUnit , "");
	m_InputParamVector.push_back(m_InputSendText);

	sprintf(m_InputnMode->paramName, "模式");
	m_InputnMode->paramType = NTSInt32;
	m_InputnMode->paramCount = 1;
	sprintf(m_InputnMode->paramVal, "0");
	sprintf(m_InputnMode->paramUnit , "");
	m_InputParamVector.push_back(m_InputnMode);

	return NTS_SUCCESS;
}
int M_AU3_ControlSend::Run(void)
{
	wchar_t title[2000],text[2000],controlID[2000];
	wchar_t SendText[2000] = {0};
	wcscpy(title,ANSIToUnicode(m_InputParaTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputParaText->paramVal).c_str());
	wcscpy(controlID,ANSIToUnicode(m_InputParaControlID->paramVal).c_str());
	wcscpy(SendText,ANSIToUnicode(m_InputSendText->paramVal).c_str());
	int nMode = atoi(m_InputnMode->paramVal);

	int ret = AU3_ControlSend(title, text, controlID, SendText, nMode);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 * Shows a control that was hidden.
 */
M_AU3_ControlShow::M_AU3_ControlShow()
:BaseMethod()
{
	sprintf(m_MethodScript, "显示控件(Shows a control that was hidden.)");
	m_InputParaTitle = CreateParamStruct();
	m_InputParaText = CreateParamStruct();
	m_InputParaControlID = CreateParamStruct();
	Init();
}
M_AU3_ControlShow::~M_AU3_ControlShow()
{
	//	free(m_InputPara);
}
int M_AU3_ControlShow::Init(void)
{
	sprintf(m_InputParaTitle->paramName, "目标窗口标题");
	m_InputParaTitle->paramType = NTSString;
	m_InputParaTitle->paramCount = 1;
	sprintf(m_InputParaTitle->paramVal,"title");
	sprintf(m_InputParaTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaTitle);
	
	
	sprintf(m_InputParaText->paramName, "文本(可为空)");
	m_InputParaText->paramType = NTSString;
	m_InputParaText->paramCount = 1;
	sprintf(m_InputParaText->paramVal,"text");
	sprintf(m_InputParaText->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaText);
	
	sprintf(m_InputParaControlID->paramName, "控件ID");
	m_InputParaControlID->paramType = NTSString;
	m_InputParaControlID->paramCount = 1;
	sprintf(m_InputParaControlID->paramVal,"ControlId");
	sprintf(m_InputParaControlID->paramUnit , "");
	m_InputParamVector.push_back(m_InputParaControlID);

	return NTS_SUCCESS;
}
int M_AU3_ControlShow::Run(void)
{
	wchar_t title[2000],text[2000],controlID[2000];

	wcscpy(title,ANSIToUnicode(m_InputParaTitle->paramVal).c_str());
	wcscpy(text,ANSIToUnicode(m_InputParaText->paramVal).c_str());
	wcscpy(controlID,ANSIToUnicode(m_InputParaControlID->paramVal).c_str());

	int ret = AU3_ControlShow(title, text, controlID);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 


/*************************************************************************
 *	Perform a mouse click operation.
 */
M_AU3_MouseClick::M_AU3_MouseClick()
:BaseMethod()
{
	sprintf(m_MethodScript, "执行鼠标点击操作(Perform a mouse click operation.)\r\n\
鼠标按键: 'left', 'right', 'middle', 'main', 'menu', 'primary', 'secondary'.\r\n\
鼠标移动速度:range 1 (fastest) to 100 (slowest). A speed of 0 will move the mouse instantly. Default speed is 0.");

	m_InputButton = CreateParamStruct();
	m_InputX = CreateParamStruct();
	m_InputY = CreateParamStruct();
	m_InputClicks = CreateParamStruct();
	m_InputSpeed = CreateParamStruct();
	Init();
	
}

M_AU3_MouseClick::~M_AU3_MouseClick()
{
	//	free(m_InputPara);
}
int M_AU3_MouseClick::Init(void)
{
	sprintf(m_InputButton->paramName, "鼠标按键");
	m_InputButton->paramType = NTSString;
	m_InputButton->paramCount = 1;
	sprintf(m_InputButton->paramVal,"left");
	sprintf(m_InputButton->paramUnit, " ");
	m_InputParamVector.push_back(m_InputButton);

	sprintf(m_InputX->paramName, "x 坐标");
	m_InputX->paramType = NTSInt32;
	m_InputX->paramCount = 1;
	sprintf(m_InputX->paramVal,"%d", AU3_INTDEFAULT);
	sprintf(m_InputX->paramUnit , "");
	m_InputParamVector.push_back(m_InputX);
	
	sprintf(m_InputY->paramName, "Y 坐标");
	m_InputY->paramType = NTSInt32;
	m_InputY->paramCount = 1;
	sprintf(m_InputY->paramVal,"%d", AU3_INTDEFAULT);
	sprintf(m_InputY->paramUnit, " ");
	m_InputParamVector.push_back(m_InputY);
	
	sprintf(m_InputClicks->paramName, "点击次数");
	m_InputClicks->paramType = NTSInt32;
	m_InputClicks->paramCount = 1;
	sprintf(m_InputClicks->paramVal,"1");
	sprintf(m_InputClicks->paramUnit , "");
	m_InputParamVector.push_back(m_InputClicks);

	sprintf(m_InputSpeed->paramName, "鼠标移动速度");
	m_InputSpeed->paramType = NTSInt32;
	m_InputSpeed->paramCount = 1;
	sprintf(m_InputSpeed->paramVal,"0");
	sprintf(m_InputSpeed->paramUnit , "");
	m_InputParamVector.push_back(m_InputSpeed);
	
	return NTS_SUCCESS;
}
int M_AU3_MouseClick::Run(void)
{
	wchar_t button[2000];
	int nX = atoi(m_InputX->paramVal);
	int nY = atoi(m_InputY->paramVal);
	int nClicks = atoi(m_InputClicks->paramVal);
	int nSpeed = atoi(m_InputSpeed->paramVal);

	wcscpy(button,ANSIToUnicode(m_InputButton->paramVal).c_str());
	
	int ret = AU3_MouseClick(button, nX, nY, nClicks, nSpeed);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 *	Perform a mouse click and drag operation.
 */
M_AU3_MouseClickDrag::M_AU3_MouseClickDrag()
:BaseMethod()
{
sprintf(m_MethodScript, "执行鼠标点击并拖拉操作(Perform a mouse click and drag operation.)\r\n\
鼠标按键: 'left', 'right', 'middle', 'main', 'menu', 'primary', 'secondary'.\r\n\
鼠标移动速度:range 1 (fastest) to 100 (slowest). A speed of 0 will move the mouse instantly. Default speed is 0.");

	m_InputButton = CreateParamStruct();
	m_InputX1 = CreateParamStruct();
	m_InputY1 = CreateParamStruct();
	m_InputX2 = CreateParamStruct();
	m_InputY2 = CreateParamStruct();
	m_InputSpeed = CreateParamStruct();
	Init();
	
}

M_AU3_MouseClickDrag::~M_AU3_MouseClickDrag()
{
	//	free(m_InputPara);
}
int M_AU3_MouseClickDrag::Init(void)
{
	sprintf(m_InputButton->paramName, "鼠标按键");
	m_InputButton->paramType = NTSString;
	m_InputButton->paramCount = 1;
	sprintf(m_InputButton->paramVal,"left");
	sprintf(m_InputButton->paramUnit, " ");
	m_InputParamVector.push_back(m_InputButton);

	sprintf(m_InputX1->paramName, "x1 坐标");
	m_InputX1->paramType = NTSInt32;
	m_InputX1->paramCount = 1;
	sprintf(m_InputX1->paramVal,"%d", 0);
	sprintf(m_InputX1->paramUnit , "");
	m_InputParamVector.push_back(m_InputX1);
	
	sprintf(m_InputY1->paramName, "Y1 坐标");
	m_InputY1->paramType = NTSInt32;
	m_InputY1->paramCount = 1;
	sprintf(m_InputY1->paramVal,"%d", 0);
	sprintf(m_InputY1->paramUnit, " ");
	m_InputParamVector.push_back(m_InputY1);

	sprintf(m_InputX2->paramName, "x2 坐标");
	m_InputX2->paramType = NTSInt32;
	m_InputX2->paramCount = 1;
	sprintf(m_InputX2->paramVal,"%d", 60);
	sprintf(m_InputX2->paramUnit , "");
	m_InputParamVector.push_back(m_InputX2);
	
	sprintf(m_InputY2->paramName, "Y2 坐标");
	m_InputY2->paramType = NTSInt32;
	m_InputY2->paramCount = 1;
	sprintf(m_InputY2->paramVal,"%d", 70);
	sprintf(m_InputY2->paramUnit, " ");
	m_InputParamVector.push_back(m_InputY2);

	sprintf(m_InputSpeed->paramName, "鼠标移动速度");
	m_InputSpeed->paramType = NTSInt32;
	m_InputSpeed->paramCount = 1;
	sprintf(m_InputSpeed->paramVal,"0");
	sprintf(m_InputSpeed->paramUnit , "");
	m_InputParamVector.push_back(m_InputSpeed);
	
	return NTS_SUCCESS;
}
int M_AU3_MouseClickDrag::Run(void)
{
	wchar_t button[2000];
	int nX1 = atoi(m_InputX1->paramVal);
	int nY1 = atoi(m_InputY1->paramVal);
	int nX2 = atoi(m_InputX2->paramVal);
	int nY2 = atoi(m_InputY2->paramVal);
	int nSpeed = atoi(m_InputSpeed->paramVal);

	wcscpy(button,ANSIToUnicode(m_InputButton->paramVal).c_str());
	
	int ret = AU3_MouseClickDrag(button, nX1, nY1, nX2, nY2, nSpeed);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 *	Perform a mouse down event at the current mouse position.
 */
M_AU3_MouseDown::M_AU3_MouseDown()
:BaseMethod()
{
sprintf(m_MethodScript, "执行鼠标按下操作(Perform a mouse down event at the current mouse position.)\r\n\
鼠标按键: 'left', 'right', 'middle', 'main', 'menu', 'primary', 'secondary'.");

	m_InputButton = CreateParamStruct();
	Init();
	
}

M_AU3_MouseDown::~M_AU3_MouseDown()
{
	//	free(m_InputPara);
}
int M_AU3_MouseDown::Init(void)
{
	sprintf(m_InputButton->paramName, "鼠标按键");
	m_InputButton->paramType = NTSString;
	m_InputButton->paramCount = 1;
	sprintf(m_InputButton->paramVal,"left");
	sprintf(m_InputButton->paramUnit, " ");
	m_InputParamVector.push_back(m_InputButton);

	return NTS_SUCCESS;
}
int M_AU3_MouseDown::Run(void)
{
	wchar_t button[2000];
	wcscpy(button,ANSIToUnicode(m_InputButton->paramVal).c_str());
	
	AU3_MouseDown(button);
	return NTS_SUCCESS;
} 

/*************************************************************************
 *	Perform a mouse up event at the current mouse position.
 */
M_AU3_MouseUp::M_AU3_MouseUp()
:BaseMethod()
{
sprintf(m_MethodScript, "执行鼠标释放操作(Perform a mouse up event at the current mouse position.)\r\n\
鼠标按键: 'left', 'right', 'middle', 'main', 'menu', 'primary', 'secondary'.");

	m_InputButton = CreateParamStruct();
	Init();
	
}

M_AU3_MouseUp::~M_AU3_MouseUp()
{
	//	free(m_InputPara);
}
int M_AU3_MouseUp::Init(void)
{
	sprintf(m_InputButton->paramName, "鼠标按键");
	m_InputButton->paramType = NTSString;
	m_InputButton->paramCount = 1;
	sprintf(m_InputButton->paramVal,"left");
	sprintf(m_InputButton->paramUnit, " ");
	m_InputParamVector.push_back(m_InputButton);

	return NTS_SUCCESS;
}
int M_AU3_MouseUp::Run(void)
{
	wchar_t button[2000];
	wcscpy(button,ANSIToUnicode(m_InputButton->paramVal).c_str());
	
	AU3_MouseUp(button);
	return NTS_SUCCESS;
} 

/*************************************************************************
 *	Moves the mouse pointer.
 */
M_AU3_MouseMove::M_AU3_MouseMove()
:BaseMethod()
{
sprintf(m_MethodScript, "移动鼠标(Moves the mouse pointer.)\r\n\
鼠标移动速度:range 1 (fastest) to 100 (slowest). A speed of 0 will move the mouse instantly. Default speed is 0.");


	m_InputX = CreateParamStruct();
	m_InputY = CreateParamStruct();
	m_InputSpeed = CreateParamStruct();
	Init();
	
}

M_AU3_MouseMove::~M_AU3_MouseMove()
{
	//	free(m_InputPara);
}
int M_AU3_MouseMove::Init(void)
{
	sprintf(m_InputX->paramName, "x 坐标");
	m_InputX->paramType = NTSInt32;
	m_InputX->paramCount = 1;
	sprintf(m_InputX->paramVal,"%d", 0);
	sprintf(m_InputX->paramUnit , "");
	m_InputParamVector.push_back(m_InputX);
	
	sprintf(m_InputY->paramName, "Y 坐标");
	m_InputY->paramType = NTSInt32;
	m_InputY->paramCount = 1;
	sprintf(m_InputY->paramVal,"%d", 0);
	sprintf(m_InputY->paramUnit, " ");
	m_InputParamVector.push_back(m_InputY);

	sprintf(m_InputSpeed->paramName, "鼠标移动速度");
	m_InputSpeed->paramType = NTSInt32;
	m_InputSpeed->paramCount = 1;
	sprintf(m_InputSpeed->paramVal,"0");
	sprintf(m_InputSpeed->paramUnit , "");
	m_InputParamVector.push_back(m_InputSpeed);
	
	return NTS_SUCCESS;
}
int M_AU3_MouseMove::Run(void)
{
	int nX = atoi(m_InputX->paramVal);
	int nY = atoi(m_InputY->paramVal);
	int nSpeed = atoi(m_InputSpeed->paramVal);

	int ret = AU3_MouseMove(nX, nY, nSpeed);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 *	Moves the mouse wheel up or down.
 */
M_AU3_MouseWheel::M_AU3_MouseWheel()
:BaseMethod()
{
sprintf(m_MethodScript, "滚动鼠标滑轮(Moves the mouse wheel up or down.)\r\n\
滑动方向:'up' or 'down'\r\n\
滑动次数:The number of times to move the wheel. Default is 1.");

	m_Inputdirection = CreateParamStruct();
	m_InputClicks = CreateParamStruct();
	Init();
	
}

M_AU3_MouseWheel::~M_AU3_MouseWheel()
{
	//	free(m_InputPara);
}
int M_AU3_MouseWheel::Init(void)
{
	sprintf(m_Inputdirection->paramName, "滑动方向");
	m_Inputdirection->paramType = NTSString;
	m_Inputdirection->paramCount = 1;
	sprintf(m_Inputdirection->paramVal,"down");
	sprintf(m_Inputdirection->paramUnit, " ");
	m_InputParamVector.push_back(m_Inputdirection);

	sprintf(m_InputClicks->paramName, "滑动次数");
	m_InputClicks->paramType = NTSInt32;
	m_InputClicks->paramCount = 1;
	sprintf(m_InputClicks->paramVal,"1");
	sprintf(m_InputClicks->paramUnit , "");
	m_InputParamVector.push_back(m_InputClicks);

	return NTS_SUCCESS;
}
int M_AU3_MouseWheel::Run(void)
{
	wchar_t direction[2000];
	wcscpy(direction,ANSIToUnicode(m_Inputdirection->paramVal).c_str());
	int nClicks = atoi(m_InputClicks->paramVal);
	
	AU3_MouseWheel(direction, nClicks);
	return NTS_SUCCESS;
} 

/*************************************************************************
 *	Changes the operation of various AutoIt functions/parameters.
 */
M_AU3_AutoItSetOption::M_AU3_AutoItSetOption()
:BaseMethod()
{
sprintf(m_MethodScript, "设置autoit操作参数(Changes the operation of various AutoIt functions/parameters.)\r\n\
操作:The option to change. See Remarks.\r\n\
参数:The value to assign to the option. ");

	m_InputOption = CreateParamStruct();
	m_InputValue = CreateParamStruct();
	Init();
	
}

M_AU3_AutoItSetOption::~M_AU3_AutoItSetOption()
{
	//	free(m_InputPara);
}
int M_AU3_AutoItSetOption::Init(void)
{
	sprintf(m_InputOption->paramName, "操作");
	m_InputOption->paramType = NTSString;
	m_InputOption->paramCount = 1;
	sprintf(m_InputOption->paramVal,"option");
	sprintf(m_InputOption->paramUnit, " ");
	m_InputParamVector.push_back(m_InputOption);

	sprintf(m_InputValue->paramName, "参数");
	m_InputValue->paramType = NTSInt32;
	m_InputValue->paramCount = 1;
	sprintf(m_InputValue->paramVal,"0");
	sprintf(m_InputValue->paramUnit, " ");
	m_InputParamVector.push_back(m_InputValue);
	
	return NTS_SUCCESS;
}
int M_AU3_AutoItSetOption::Run(void)
{
	wchar_t option[2000];
	int ret;
	wcscpy(option,ANSIToUnicode(m_InputOption->paramVal).c_str());
	int nValue = atoi(m_InputValue->paramVal);
	
	for(int i=0; i<2; i++)
	{
		ret = AU3_AutoItSetOption(option, nValue);
		if(ret==nValue) break;
	}
	if (ret!=nValue)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 


/*************************************************************************
 *	Terminates a named process.
 */
M_AU3_ProcessClose::M_AU3_ProcessClose()
:BaseMethod()
{
sprintf(m_MethodScript, "关闭进程(ChaTerminates a named process.)\r\n\
进程:The name or PID of the process to terminate.");

	m_InputProcess = CreateParamStruct();
	Init();
	
}

M_AU3_ProcessClose::~M_AU3_ProcessClose()
{
	//	free(m_InputPara);
}
int M_AU3_ProcessClose::Init(void)
{
	sprintf(m_InputProcess->paramName, "进程");
	m_InputProcess->paramType = NTSString;
	m_InputProcess->paramCount = 1;
	sprintf(m_InputProcess->paramVal,"process");
	sprintf(m_InputProcess->paramUnit, " ");
	m_InputParamVector.push_back(m_InputProcess);

	return NTS_SUCCESS;
}
int M_AU3_ProcessClose::Run(void)
{
	wchar_t process[2000];
	wcscpy(process,ANSIToUnicode(m_InputProcess->paramVal).c_str());

	int ret = AU3_ProcessClose(process);

	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 *	Checks to see if a specified process exists.
 */
M_AU3_ProcessExists::M_AU3_ProcessExists()
:BaseMethod()
{
sprintf(m_MethodScript, "检查进程是否存在(Checks to see if a specified process exists.)\r\n\
进程:The name or PID of the process to terminate.\r\n\
返回值:1->存在;0->不存在");

	m_InputProcess = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
	
}

M_AU3_ProcessExists::~M_AU3_ProcessExists()
{
	//	free(m_InputPara);
}
int M_AU3_ProcessExists::Init(void)
{
	sprintf(m_InputProcess->paramName, "进程");
	m_InputProcess->paramType = NTSString;
	m_InputProcess->paramCount = 1;
	sprintf(m_InputProcess->paramVal,"process");
	sprintf(m_InputProcess->paramUnit, " ");
	m_InputParamVector.push_back(m_InputProcess);

	sprintf(m_OutputPara->paramName, "返回值");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);

	return NTS_SUCCESS;
}
int M_AU3_ProcessExists::Run(void)
{
	wchar_t process[2000];
	wcscpy(process,ANSIToUnicode(m_InputProcess->paramVal).c_str());

	int ret = AU3_ProcessExists(process);
	sprintf(m_OutputPara->paramVal,"%d", ret);
	
	return NTS_SUCCESS;
} 

/*************************************************************************
 *	Pauses script execution until a given process does not exist.
 */
M_AU3_ProcessWait::M_AU3_ProcessWait()
:BaseMethod()
{
sprintf(m_MethodScript, "等待进程出现(Pauses script execution until a given process does not exist.)\r\n\
进程:The name or PID of the process to terminate.\r\n\
等待时间: Specifies how long to wait (in seconds). Default is to wait 5 seconds, 0 is to wait indefinitely");

	m_InputProcess = CreateParamStruct();
	m_InputTimeout = CreateParamStruct();
	Init();
	
}

M_AU3_ProcessWait::~M_AU3_ProcessWait()
{
	//	free(m_InputPara);
}
int M_AU3_ProcessWait::Init(void)
{
	sprintf(m_InputProcess->paramName, "进程");
	m_InputProcess->paramType = NTSString;
	m_InputProcess->paramCount = 1;
	sprintf(m_InputProcess->paramVal,"process");
	sprintf(m_InputProcess->paramUnit, " ");
	m_InputParamVector.push_back(m_InputProcess);

	sprintf(m_InputTimeout->paramName, "等待时间");
	m_InputTimeout->paramType = NTSInt32;
	m_InputTimeout->paramCount = 1;
	sprintf(m_InputTimeout->paramVal,"5");
	sprintf(m_InputTimeout->paramUnit, " ");
	m_InputParamVector.push_back(m_InputTimeout);

	return NTS_SUCCESS;
}
int M_AU3_ProcessWait::Run(void)
{
	wchar_t process[2000];
	wcscpy(process,ANSIToUnicode(m_InputProcess->paramVal).c_str());
	int nTimeout = atoi(m_InputTimeout->paramVal);

	int ret = AU3_ProcessWait(process, nTimeout);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 *	Pauses script execution until a given process does not exist.
 */
M_AU3_ProcessWaitClose::M_AU3_ProcessWaitClose()
:BaseMethod()
{
sprintf(m_MethodScript, "等待进程关闭(Pauses script execution until a given process does not exist.)\r\n\
进程:The name or PID of the process to terminate.\r\n\
等待时间: Specifies how long to wait (in seconds). Default is to wait 5 seconds, 0 is to wait indefinitely.");

	m_InputProcess = CreateParamStruct();
	m_InputTimeout = CreateParamStruct();
	Init();
	
}

M_AU3_ProcessWaitClose::~M_AU3_ProcessWaitClose()
{
	//	free(m_InputPara);
}
int M_AU3_ProcessWaitClose::Init(void)
{
	sprintf(m_InputProcess->paramName, "进程");
	m_InputProcess->paramType = NTSString;
	m_InputProcess->paramCount = 1;
	sprintf(m_InputProcess->paramVal,"process");
	sprintf(m_InputProcess->paramUnit, " ");
	m_InputParamVector.push_back(m_InputProcess);

	sprintf(m_InputTimeout->paramName, "等待时间");
	m_InputTimeout->paramType = NTSInt32;
	m_InputTimeout->paramCount = 1;
	sprintf(m_InputTimeout->paramVal,"5");
	sprintf(m_InputTimeout->paramUnit, " ");
	m_InputParamVector.push_back(m_InputTimeout);

	return NTS_SUCCESS;
}
int M_AU3_ProcessWaitClose::Run(void)
{
	wchar_t process[2000];
	wcscpy(process,ANSIToUnicode(m_InputProcess->paramVal).c_str());
	int nTimeout = atoi(m_InputTimeout->paramVal);

	int ret = AU3_ProcessWaitClose(process, nTimeout);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 


/*************************************************************************
 *	Activates (gives focus to) a window.
 */
M_AU3_WinActivate::M_AU3_WinActivate()
:BaseMethod()
{
	sprintf(m_MethodScript, "激活窗口(Activates (gives focus to) a window.)\r\n\
返回值:失败->0;成功->窗口句柄");
	m_InputTitle = CreateParamStruct();
	m_InputText = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
	
}
M_AU3_WinActivate::~M_AU3_WinActivate()
{
	//	free(m_InputPara);
}
int M_AU3_WinActivate::Init(void)
{
	sprintf(m_InputTitle->paramName, "目标窗口标题");
	m_InputTitle->paramType = NTSString;
	m_InputTitle->paramCount = 1;
	sprintf(m_InputTitle->paramVal,"Title");
	sprintf(m_InputTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputTitle);
	
	
	sprintf(m_InputText->paramName, "文本(可为空)");
	m_InputText->paramType = NTSString;
	m_InputText->paramCount = 1;
	sprintf(m_InputText->paramVal,"Text");
	sprintf(m_InputText->paramUnit , "");
	m_InputParamVector.push_back(m_InputText);

	sprintf(m_OutputPara->paramName, "返回值");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}

int M_AU3_WinActivate::Run(void)
{
	wchar_t title[2000], name[2000];
	wcscpy(title,ANSIToUnicode(m_InputTitle->paramVal).c_str());
	wcscpy(name,ANSIToUnicode(m_InputText->paramVal).c_str());
	int ret = AU3_WinActivate(title,name);
	sprintf(m_OutputPara->paramVal,"%d", ret);
	return NTS_SUCCESS;
} 

/*************************************************************************
 *	Checks to see if a specified window exists and is currently active.
 */
M_AU3_WinActive::M_AU3_WinActive()
:BaseMethod()
{
sprintf(m_MethodScript, "检测某窗口是否为活动窗口(Checks to see if a specified window exists and is currently active.)\r\n\
返回值:失败->0;成功->窗口句柄");
	m_InputTitle = CreateParamStruct();
	m_InputText = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
	
}
M_AU3_WinActive::~M_AU3_WinActive()
{
	//	free(m_InputPara);
}
int M_AU3_WinActive::Init(void)
{
	sprintf(m_InputTitle->paramName, "目标窗口标题");
	m_InputTitle->paramType = NTSString;
	m_InputTitle->paramCount = 1;
	sprintf(m_InputTitle->paramVal,"Title");
	sprintf(m_InputTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputTitle);
	
	
	sprintf(m_InputText->paramName, "文本(可为空)");
	m_InputText->paramType = NTSString;
	m_InputText->paramCount = 1;
	sprintf(m_InputText->paramVal,"Text");
	sprintf(m_InputText->paramUnit , "");
	m_InputParamVector.push_back(m_InputText);

	sprintf(m_OutputPara->paramName, "返回值");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}

int M_AU3_WinActive::Run(void)
{
	wchar_t title[2000], name[2000];
	wcscpy(title,ANSIToUnicode(m_InputTitle->paramVal).c_str());
	wcscpy(name,ANSIToUnicode(m_InputText->paramVal).c_str());
	int ret = AU3_WinActive(title,name);
	sprintf(m_OutputPara->paramVal,"%d", ret);
	return NTS_SUCCESS;
} 

/*************************************************************************
 *	Closes a window.
 */
M_AU3_WinClose::M_AU3_WinClose()
:BaseMethod()
{
sprintf(m_MethodScript, "关闭窗口(Closes a window.)");
	m_InputTitle = CreateParamStruct();
	m_InputText = CreateParamStruct();
	Init();
	
}
M_AU3_WinClose::~M_AU3_WinClose()
{
	//	free(m_InputPara);
}
int M_AU3_WinClose::Init(void)
{
	sprintf(m_InputTitle->paramName, "目标窗口标题");
	m_InputTitle->paramType = NTSString;
	m_InputTitle->paramCount = 1;
	sprintf(m_InputTitle->paramVal,"Title");
	sprintf(m_InputTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputTitle);
	
	
	sprintf(m_InputText->paramName, "文本(可为空)");
	m_InputText->paramType = NTSString;
	m_InputText->paramCount = 1;
	sprintf(m_InputText->paramVal,"Text");
	sprintf(m_InputText->paramUnit , "");
	m_InputParamVector.push_back(m_InputText);
	
	return NTS_SUCCESS;
}

int M_AU3_WinClose::Run(void)
{
	wchar_t title[2000], name[2000];
	wcscpy(title,ANSIToUnicode(m_InputTitle->paramVal).c_str());
	wcscpy(name,ANSIToUnicode(m_InputText->paramVal).c_str());
	int ret = AU3_WinClose(title,name);

	return NTS_SUCCESS;

} 

/*************************************************************************
 *	Checks to see if a specified window exists.
 */
M_AU3_WinExists::M_AU3_WinExists()
:BaseMethod()
{
sprintf(m_MethodScript, "检测某窗口是否存在(Checks to see if a specified window exists.)\r\n\
返回值:失败->0;成功->1");
	m_InputTitle = CreateParamStruct();
	m_InputText = CreateParamStruct();
	m_OutputPara = CreateParamStruct();
	Init();
	
}
M_AU3_WinExists::~M_AU3_WinExists()
{
	//	free(m_InputPara);
}
int M_AU3_WinExists::Init(void)
{
	sprintf(m_InputTitle->paramName, "目标窗口标题");
	m_InputTitle->paramType = NTSString;
	m_InputTitle->paramCount = 1;
	sprintf(m_InputTitle->paramVal,"Title");
	sprintf(m_InputTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputTitle);
	
	
	sprintf(m_InputText->paramName, "文本(可为空)");
	m_InputText->paramType = NTSString;
	m_InputText->paramCount = 1;
	sprintf(m_InputText->paramVal,"Text");
	sprintf(m_InputText->paramUnit , "");
	m_InputParamVector.push_back(m_InputText);

	sprintf(m_OutputPara->paramName, "返回值");
	m_OutputPara->paramType = NTSString;
	m_OutputPara->paramCount = 1;
	sprintf(m_OutputPara->paramVal,"");
	sprintf(m_OutputPara->paramUnit, " ");
	m_OutputParamVector.push_back(m_OutputPara);
	
	return NTS_SUCCESS;
}

int M_AU3_WinExists::Run(void)
{
	wchar_t title[2000], name[2000];
	wcscpy(title,ANSIToUnicode(m_InputTitle->paramVal).c_str());
	wcscpy(name,ANSIToUnicode(m_InputText->paramVal).c_str());
	int ret = AU3_WinExists(title,name);
	sprintf(m_OutputPara->paramVal,"%d", ret);
	return NTS_SUCCESS;
} 

/*************************************************************************
 *	Forces a window to close.
 */
M_AU3_WinKill::M_AU3_WinKill()
:BaseMethod()
{
sprintf(m_MethodScript, "强制关闭窗口(Forces a window to close.)");
	m_InputTitle = CreateParamStruct();
	m_InputText = CreateParamStruct();
	Init();
	
}
M_AU3_WinKill::~M_AU3_WinKill()
{
	//	free(m_InputPara);
}
int M_AU3_WinKill::Init(void)
{
	sprintf(m_InputTitle->paramName, "目标窗口标题");
	m_InputTitle->paramType = NTSString;
	m_InputTitle->paramCount = 1;
	sprintf(m_InputTitle->paramVal,"Title");
	sprintf(m_InputTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputTitle);
	
	
	sprintf(m_InputText->paramName, "文本(可为空)");
	m_InputText->paramType = NTSString;
	m_InputText->paramCount = 1;
	sprintf(m_InputText->paramVal,"Text");
	sprintf(m_InputText->paramUnit , "");
	m_InputParamVector.push_back(m_InputText);

	
	return NTS_SUCCESS;
}

int M_AU3_WinKill::Run(void)
{
	wchar_t title[2000], name[2000];
	wcscpy(title,ANSIToUnicode(m_InputTitle->paramVal).c_str());
	wcscpy(name,ANSIToUnicode(m_InputText->paramVal).c_str());
	int ret = AU3_WinKill(title,name);
	return NTS_SUCCESS;
} 


/*************************************************************************
 *	Forces a window to close.
 */
M_AU3_WinSetOnTop::M_AU3_WinSetOnTop()
:BaseMethod()
{
sprintf(m_MethodScript, "窗口top(Change a window's'Always On Top' attribute.\r\n\
标志:1=set on top flag, 0 = remove on top flag)");
	m_InputTitle = CreateParamStruct();
	m_InputText = CreateParamStruct();
	m_Inputflag = CreateParamStruct();
	Init();
	
}
M_AU3_WinSetOnTop::~M_AU3_WinSetOnTop()
{
	//	free(m_InputPara);
}
int M_AU3_WinSetOnTop::Init(void)
{
	sprintf(m_InputTitle->paramName, "目标窗口标题");
	m_InputTitle->paramType = NTSString;
	m_InputTitle->paramCount = 1;
	sprintf(m_InputTitle->paramVal,"Title");
	sprintf(m_InputTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputTitle);
	
	
	sprintf(m_InputText->paramName, "文本(可为空)");
	m_InputText->paramType = NTSString;
	m_InputText->paramCount = 1;
	sprintf(m_InputText->paramVal,"Text");
	sprintf(m_InputText->paramUnit , "");
	m_InputParamVector.push_back(m_InputText);

	sprintf(m_Inputflag->paramName, "标志");
	m_Inputflag->paramType = NTSInt32;
	m_Inputflag->paramCount = 1;
	sprintf(m_Inputflag->paramVal,"1");
	sprintf(m_Inputflag->paramUnit, " ");
	m_InputParamVector.push_back(m_Inputflag);

	
	return NTS_SUCCESS;
}

int M_AU3_WinSetOnTop::Run(void)
{
	wchar_t title[2000], name[2000];
	wcscpy(title,ANSIToUnicode(m_InputTitle->paramVal).c_str());
	wcscpy(name,ANSIToUnicode(m_InputText->paramVal).c_str());
	int nflag = atoi(m_Inputflag->paramVal);
	int ret = AU3_WinSetOnTop(title,name, nflag);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 

/*************************************************************************
 *	Shows, hides, minimizes, maximizes, or restores a window.
 */
M_AU3_WinSetState::M_AU3_WinSetState()
:BaseMethod()
{
sprintf(m_MethodScript, "设置窗口状态(Shows, hides, minimizes, maximizes, or restores a window.)\r\n\
标志:  0 = Hide window\r\n\
1 = Shows a previously hidden window\r\n\
2 = Minimize window\r\n\
3 = Maximize window\r\n\
4 = Undoes a window minimization or maximization\r\n\
5 = Disables the window\r\n\
6 = Enables the window");
	m_InputTitle = CreateParamStruct();
	m_InputText = CreateParamStruct();
	m_Inputflag = CreateParamStruct();
	Init();
	
}
M_AU3_WinSetState::~M_AU3_WinSetState()
{
	//	free(m_InputPara);
}
int M_AU3_WinSetState::Init(void)
{
	sprintf(m_InputTitle->paramName, "目标窗口标题");
	m_InputTitle->paramType = NTSString;
	m_InputTitle->paramCount = 1;
	sprintf(m_InputTitle->paramVal,"Title");
	sprintf(m_InputTitle->paramUnit , "");
	m_InputParamVector.push_back(m_InputTitle);
	
	
	sprintf(m_InputText->paramName, "文本(可为空)");
	m_InputText->paramType = NTSString;
	m_InputText->paramCount = 1;
	sprintf(m_InputText->paramVal,"Text");
	sprintf(m_InputText->paramUnit , "");
	m_InputParamVector.push_back(m_InputText);

	sprintf(m_Inputflag->paramName, "标志");
	m_Inputflag->paramType = NTSInt32;
	m_Inputflag->paramCount = 1;
	sprintf(m_Inputflag->paramVal,"1");
	sprintf(m_Inputflag->paramUnit, " ");
	m_InputParamVector.push_back(m_Inputflag);

	
	return NTS_SUCCESS;
}

int M_AU3_WinSetState::Run(void)
{
	wchar_t title[2000], name[2000];
	wcscpy(title,ANSIToUnicode(m_InputTitle->paramVal).c_str());
	wcscpy(name,ANSIToUnicode(m_InputText->paramVal).c_str());
	int nflag = atoi(m_Inputflag->paramVal);
	int ret = AU3_WinSetState(title,name, nflag);
	if (ret==0)
	{
		return NTS_INVALID_OPERATE;	
	} 
	else
	{
		return NTS_SUCCESS;
	}
} 
