#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"


/************************************************************************
* 版本：3.0.2.22
* 作者：dolby.jiang
* 完成日期：2011年12月27日
* 更改：新建
*
************************************************************************/


/************************************************************************/
/*  通用接口卡驱动程序方法类                                            */
/************************************************************************/
// M_NC_OpenDev 打开并初始化NCard
class M_NC_OpenDev:public BaseMethod
{
public:
	M_NC_OpenDev();
	virtual ~M_NC_OpenDev();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
};
//关闭NCard设备
class M_NC_CloseDev : public BaseMethod
{
public:
	M_NC_CloseDev();
	virtual ~M_NC_CloseDev();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
};
//系统参数查询
class M_NC_QuerySysParam : public BaseMethod
{
public:
	M_NC_QuerySysParam();
	virtual ~M_NC_QuerySysParam();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputSysparam;
};
//系统状态查询
class M_NC_QuerySysState : public BaseMethod
{
public:
	M_NC_QuerySysState();
	virtual ~M_NC_QuerySysState();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputSysState;
};
//创建通讯对象
class M_NC_CreateCommObject : public BaseMethod
{
public:
	M_NC_CreateCommObject();
	virtual ~M_NC_CreateCommObject();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputConnStr;    //char* (object connection string)
	TParamSetStruct m_OutputObjID;  //long (object ID)
};
//销毁通讯对象
class M_NC_DeleteCommObject : public BaseMethod
{
public:
	M_NC_DeleteCommObject();
	virtual ~M_NC_DeleteCommObject();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
};
//通讯对象读操作
class M_NC_Read : public BaseMethod
{
public:
	M_NC_Read();
	virtual ~M_NC_Read();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
	TParamSetStruct m_InputExpLen;
	TParamSetStruct m_InputDataFormat;
	TParamSetStruct m_OutputRead;
	TParamSetStruct m_OutputRealLen;
};
//通信对象写操作
class M_NC_Write : public BaseMethod
{
public:
	M_NC_Write();
	virtual ~M_NC_Write();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
	TParamSetStruct m_InputExpLen;
	TParamSetStruct m_InputDataFormat;
	TParamSetStruct m_InputWrite;
	TParamSetStruct m_OutputRealLen;
};
//设置通讯对象缓冲区
class M_NC_SetBufSize : public BaseMethod
{
public:
	M_NC_SetBufSize();
	virtual ~M_NC_SetBufSize();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
	TParamSetStruct m_InputType;
	TParamSetStruct m_InputSize;
};
//清除通讯对象缓冲区
class M_NC_ClearBuf : public BaseMethod
{
public:
	M_NC_ClearBuf();
	virtual ~M_NC_ClearBuf();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
	TParamSetStruct m_InputType;
};
//通讯对象写操作（字符串）
class M_NC_Sprintf : public BaseMethod
{
public:
	M_NC_Sprintf();
	virtual ~M_NC_Sprintf();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
	TParamSetStruct m_InputCommand;
};
//通讯对象读操作（字符串）
class M_NC_Query : public BaseMethod
{
public:
	M_NC_Query();
	virtual ~M_NC_Query();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputObjID;
	TParamSetStruct m_InputCommand;
	TParamSetStruct m_OutputRetStr;
};
//环境信息查询
class M_NC_QueryContextInfo : public BaseMethod
{
public:
	M_NC_QueryContextInfo();
	virtual ~M_NC_QueryContextInfo();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputSysparam;
};
//版本信息查询
class M_NC_QueryVersionInfo : public BaseMethod
{
public:
	M_NC_QueryVersionInfo();
	virtual ~M_NC_QueryVersionInfo();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputSysparam;
};
//设置IP地址
class M_NC_SetIPAddress : public BaseMethod
{
public:
	M_NC_SetIPAddress();
	virtual ~M_NC_SetIPAddress();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputNetType;
	TParamSetStruct m_InputIPAdress;
};
//重启
class M_NC_Reset : public BaseMethod
{
public:
	M_NC_Reset();
	virtual ~M_NC_Reset();
	virtual int init();
	virtual int Run();
protected:
	TParamSetStruct m_InputDeviceName;
};