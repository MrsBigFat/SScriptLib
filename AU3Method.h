#pragma warning( disable : 4786)

#include <windows.h>
#include "Method.h"
#include "NTSDin.h"



/************************************************************************
* 作者：will.wang
* 完成日期：2016年02月18日
* 新样AU3oIT 三方软件控制函数
*
************************************************************************/

  

/************************************************************************/
/*  AU3oIT 函数方法类                                                  */
/************************************************************************/
//class M_AU3_Run 软件运行
class M_AU3_Run:public BaseMethod
{
public:
	M_AU3_Run();
	virtual ~M_AU3_Run();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputProgram;
	TParamSetStruct m_InputDir;
	TParamSetStruct m_InputShowFlag;
	TParamSetStruct m_OutputPara;
};

//Runs an external program and pauses script execution until the program finishes.
class M_AU3_RunWait:public BaseMethod
{
public:
	M_AU3_RunWait();
	virtual ~M_AU3_RunWait();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputProgram;
	TParamSetStruct m_InputDir;
	TParamSetStruct m_InputShowFlag;
	TParamSetStruct m_OutputPara;
};


//class M_AU3_WinWaitActive 暂停脚本执行,直到请求的窗口激活.
class M_AU3_WinWaitActive:public BaseMethod
{
public:
	M_AU3_WinWaitActive();
	virtual ~M_AU3_WinWaitActive();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputTitle;
	TParamSetStruct m_InputText;
	TParamSetStruct m_InputTimeout;
};
//class M_AU3_Send 发送模拟键击操作到激活窗口
class M_AU3_Send:public BaseMethod
{
public:
	M_AU3_Send();
	virtual ~M_AU3_Send();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputSendText;
	TParamSetStruct m_InputMode;
};

//class M_AU3_ControlClick 发送鼠标点击命令到指定控件
class M_AU3_ControlClick:public BaseMethod
{
public:
	M_AU3_ControlClick();
	virtual ~M_AU3_ControlClick();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputTitle;
	TParamSetStruct m_InputText;
	TParamSetStruct m_InputControl;
	TParamSetStruct m_InputButton;
	TParamSetStruct m_InputClicks;
	TParamSetStruct m_InputX;
	TParamSetStruct m_InputY;
};

//class M_AU3_ControlSetText 设置控件文本
class M_AU3_ControlSetText:public BaseMethod
{
public:
	M_AU3_ControlSetText();
	virtual ~M_AU3_ControlSetText();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputTitle;
	TParamSetStruct m_InputText;
	TParamSetStruct m_InputControl;
	TParamSetStruct m_InputControlText;
};

//class M_AU3_ControlGetText 获取控件文本
class M_AU3_ControlGetText:public BaseMethod
{
public:
	M_AU3_ControlGetText();
	virtual ~M_AU3_ControlGetText();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputTitle;
	TParamSetStruct m_InputText;
	TParamSetStruct m_InputControl;
	TParamSetStruct m_InputParanBufSize;
	TParamSetStruct m_OutputPara;
};



//class M_AU3_ControlCommand  发送命令到控件ListBox or ComboBox
class M_AU3_ControlCommand:public BaseMethod
{
public:
	M_AU3_ControlCommand(void);
	virtual ~M_AU3_ControlCommand();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputTitle;
	TParamSetStruct m_InputText;
	TParamSetStruct m_InputControl;
	TParamSetStruct m_InputCommand;
	TParamSetStruct m_InputExtra1;
	TParamSetStruct m_OutputPara;
};
//class M_AU3_ControlListView  ListView控件操作
class M_AU3_ControlListView:public BaseMethod
{
public:
	M_AU3_ControlListView(void);
	virtual ~M_AU3_ControlListView();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputTitle;
	TParamSetStruct m_InputText;
	TParamSetStruct m_InputControl;
	TParamSetStruct m_InputCommand;
	TParamSetStruct m_InputExtra1;
	TParamSetStruct m_InputExtra2;
	TParamSetStruct m_OutputPara;
};

//class M_AU3_ClipGet  从剪切板中获取文本
class M_AU3_ClipGet:public BaseMethod
{
public:
	M_AU3_ClipGet(void);
	virtual ~M_AU3_ClipGet();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputBufSize;
	TParamSetStruct m_OutputPara;
};


//class M_AU3_ClipGet  Writes text to the clipboard.
class M_AU3_ClipPut:public BaseMethod
{
public:
	M_AU3_ClipPut(void);
	virtual ~M_AU3_ClipPut();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
}; 

//Disables or "grays-out" a control.
class M_AU3_ControlDisable:public BaseMethod
{
public:
	M_AU3_ControlDisable(void);
	virtual ~M_AU3_ControlDisable();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputParaTitle;
	TParamSetStruct m_InputParaText;
	TParamSetStruct m_InputParaControlID;
}; 

//Enables a "grayed-out" control.
class M_AU3_ControlEnable:public BaseMethod
{
public:
	M_AU3_ControlEnable(void);
	virtual ~M_AU3_ControlEnable();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputParaTitle;
	TParamSetStruct m_InputParaText;
	TParamSetStruct m_InputParaControlID;
}; 
 
//Sets input focus to a given control on a window.
class M_AU3_ControlFocus:public BaseMethod
{
public:
	M_AU3_ControlFocus(void);
	virtual ~M_AU3_ControlFocus();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputParaTitle;
	TParamSetStruct m_InputParaText;
	TParamSetStruct m_InputParaControlID;
}; 

//Returns the ControlRef# of the control that has keyboard focus within a specified window.
class M_AU3_ControlGetFocus:public BaseMethod
{
public:
	M_AU3_ControlGetFocus(void);
	virtual ~M_AU3_ControlGetFocus();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputParaTitle;
	TParamSetStruct m_InputParaText;
	TParamSetStruct m_InputParanBufSize;
	TParamSetStruct m_OutputPara;
}; 

//Retrieves the position and size of a control relative to its window.
class M_AU3_ControlGetPos:public BaseMethod
{
public:
	M_AU3_ControlGetPos(void);
	virtual ~M_AU3_ControlGetPos();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputParaTitle;
	TParamSetStruct m_InputParaText;
	TParamSetStruct m_InputParaControlID;
	TParamSetStruct m_OutputPara;
}; 

//Hides a control.
class M_AU3_ControlHide:public BaseMethod
{
public:
	M_AU3_ControlHide(void);
	virtual ~M_AU3_ControlHide();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputParaTitle;
	TParamSetStruct m_InputParaText;
	TParamSetStruct m_InputParaControlID;
}; 

//Moves a control within a window.
class M_AU3_ControlMove:public BaseMethod
{
public:
	M_AU3_ControlMove(void);
	virtual ~M_AU3_ControlMove();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputParaTitle;
	TParamSetStruct m_InputParaText;
	TParamSetStruct m_InputParaControlID;
	TParamSetStruct m_InputnX;
	TParamSetStruct m_InputnY;
	TParamSetStruct m_InputnWidth;
	TParamSetStruct m_InputnHeight;
}; 


//Sends a string of characters to a control.
class M_AU3_ControlSend:public BaseMethod
{
public:
	M_AU3_ControlSend(void);
	virtual ~M_AU3_ControlSend();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputParaTitle;
	TParamSetStruct m_InputParaText;
	TParamSetStruct m_InputParaControlID;
	TParamSetStruct m_InputSendText;
	TParamSetStruct m_InputnMode;
}; 

//Shows a control that was hidden.
class M_AU3_ControlShow:public BaseMethod
{
public:
	M_AU3_ControlShow(void);
	virtual ~M_AU3_ControlShow();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputParaTitle;
	TParamSetStruct m_InputParaText;
	TParamSetStruct m_InputParaControlID;
}; 

//Perform a mouse click operation.
class M_AU3_MouseClick:public BaseMethod
{
public:
	M_AU3_MouseClick();
	virtual ~M_AU3_MouseClick();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputButton;
	TParamSetStruct m_InputX;
	TParamSetStruct m_InputY;
	TParamSetStruct m_InputClicks;
	TParamSetStruct m_InputSpeed;
};

//Perform a mouse click and drag operation.
class M_AU3_MouseClickDrag:public BaseMethod
{
public:
	M_AU3_MouseClickDrag();
	virtual ~M_AU3_MouseClickDrag();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputButton;
	TParamSetStruct m_InputX1;
	TParamSetStruct m_InputY1;
	TParamSetStruct m_InputX2;
	TParamSetStruct m_InputY2;
	TParamSetStruct m_InputSpeed;
};

//Perform a mouse down event at the current mouse position.
class M_AU3_MouseDown:public BaseMethod
{
public:
	M_AU3_MouseDown();
	virtual ~M_AU3_MouseDown();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputButton;
};

//Perform a mouse up event at the current mouse position.
class M_AU3_MouseUp:public BaseMethod
{
public:
	M_AU3_MouseUp();
	virtual ~M_AU3_MouseUp();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputButton;
};

//Moves the mouse pointer.
class M_AU3_MouseMove:public BaseMethod
{
public:
	M_AU3_MouseMove();
	virtual ~M_AU3_MouseMove();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputX;
	TParamSetStruct m_InputY;
	TParamSetStruct m_InputSpeed;
};

//Moves the mouse wheel up or down.
class M_AU3_MouseWheel:public BaseMethod
{
public:
	M_AU3_MouseWheel();
	virtual ~M_AU3_MouseWheel();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_Inputdirection;
	TParamSetStruct m_InputClicks;
};

//Changes the operation of various AutoIt functions/parameters.
class M_AU3_AutoItSetOption:public BaseMethod
{
public:
	M_AU3_AutoItSetOption();
	virtual ~M_AU3_AutoItSetOption();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputOption;
	TParamSetStruct m_InputValue;
};

//Terminates a named process.
class M_AU3_ProcessClose:public BaseMethod
{
public:
	M_AU3_ProcessClose();
	virtual ~M_AU3_ProcessClose();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputProcess;
};

//Checks to see if a specified process exists.
class M_AU3_ProcessExists:public BaseMethod
{
public:
	M_AU3_ProcessExists();
	virtual ~M_AU3_ProcessExists();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputProcess;
	TParamSetStruct m_OutputPara;
};

//Pauses script execution until a given process does not exist.
class M_AU3_ProcessWait:public BaseMethod
{
public:
	M_AU3_ProcessWait();
	virtual ~M_AU3_ProcessWait();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputProcess;
	TParamSetStruct m_InputTimeout;
};

//Pauses script execution until a given process does not exist.
class M_AU3_ProcessWaitClose:public BaseMethod
{
public:
	M_AU3_ProcessWaitClose();
	virtual ~M_AU3_ProcessWaitClose();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputProcess;
	TParamSetStruct m_InputTimeout;
};

//Activates (gives focus to) a window.
class M_AU3_WinActivate:public BaseMethod
{
public:
	M_AU3_WinActivate();
	virtual ~M_AU3_WinActivate();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputTitle;
	TParamSetStruct m_InputText;
	TParamSetStruct m_OutputPara;
};

//Checks to see if a specified window exists and is currently active.
class M_AU3_WinActive:public BaseMethod
{
public:
	M_AU3_WinActive();
	virtual ~M_AU3_WinActive();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputTitle;
	TParamSetStruct m_InputText;
	TParamSetStruct m_OutputPara;
};

//Closes a window.
class M_AU3_WinClose:public BaseMethod
{
public:
	M_AU3_WinClose();
	virtual ~M_AU3_WinClose();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputTitle;
	TParamSetStruct m_InputText;
};

//Checks to see if a specified window exists.
class M_AU3_WinExists:public BaseMethod
{
public:
	M_AU3_WinExists();
	virtual ~M_AU3_WinExists();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputTitle;
	TParamSetStruct m_InputText;
	TParamSetStruct m_OutputPara;
};

//Forces a window to close.
class M_AU3_WinKill:public BaseMethod
{
public:
	M_AU3_WinKill();
	virtual ~M_AU3_WinKill();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputTitle;
	TParamSetStruct m_InputText;
};

//Change a window's "Always On Top" attribute.
class M_AU3_WinSetOnTop:public BaseMethod
{
public:
	M_AU3_WinSetOnTop();
	virtual ~M_AU3_WinSetOnTop();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputTitle;
	TParamSetStruct m_InputText;
	TParamSetStruct m_Inputflag;
};

//Shows, hides, minimizes, maximizes, or restores a window.
class M_AU3_WinSetState:public BaseMethod
{
public:
	M_AU3_WinSetState();
	virtual ~M_AU3_WinSetState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputTitle;
	TParamSetStruct m_InputText;
	TParamSetStruct m_Inputflag;
};



