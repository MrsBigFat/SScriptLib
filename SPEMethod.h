#pragma warning( disable : 4786)

#include <windows.h>
//#include <Vector>
//#include <map>
//#include <string>
//#include <algorithm>

#include "Method.h"
#include "NTSDin.h"



/************************************************************************
* 版本：2.0.0.45
* 作者：dolby.jiang
* 完成日期：2009年10月10日
* 更改：增加
*		M_SPE_IntToString 把整型数据转化成字符串
*		M_SPE_FloatToString 把浮点型数据转化成字符串
*		M_SPE_GetConditionData 获取指定范围内的数据
*		M_SPE_GetMaxPosition 获取Max值的位置
*		M_SPE_StrCat 字符串连接
*
************************************************************************/

/************************************************************************
* 版本：2.1.0.0
* 作者：dolby.jiang
* 完成日期：2009年10月13日
* 更改：增加M_SPE_GetMinPosition 获取Min值的位置
*
************************************************************************/


/************************************************************************
* 版本：2.1.0.0
* 作者：dolby.jiang
* 完成日期：2009年10月13日
* 更改：修改M_SPE_SpectrumPowerDebugEx
*
************************************************************************/

/************************************************************************
* 版本：2.1.0.7
* 作者：dolby.jiang
* 完成日期：2010年1月18日
* 更改：修改M_SPE_OpenDev
*
************************************************************************/


/************************************************************************
* 版本：2.1.0.9
* 作者：dolby.jiang
* 完成日期：2010年3月25日
* 更改：增加 SPE_GetIDN
*
************************************************************************/


/************************************************************************
* 版本：3.0.2.2
* 作者：dolby.jiang
* 完成日期：2010年11月20日
* 更改：	
	1) 增加 M_NTS_SetCom 设置串口通讯参数	
	2) 增加 M_NTS_SetDTR 设置RTS(数据终端就绪)标志  硬件流控制 0:Low 1:Hight
	3) 增加 M_NTS_SetRTS 设置RTS(设置请求数据发送)标志  硬件流控制 0:Low 1:Hight
	4) 增加 M_NTS_SetXOFF 设置XOFF(设置流数据停止发送)标志 软件流控制
	5) 增加 M_NTS_SetXON 设置XON(设置流数据继续发送)标志 软件流控制
	6) 增加 M_SPE_WriteDev 向自定义设备写数据
	7) 增加 M_SPE_ReadDev 从自定义设备读取数据
	8) 增加 M_SPE_QueryDev 查询
*
************************************************************************/

/************************************************************************
* 版本：3.0.2.18
* 作者：dolby.jiang
* 完成日期：2011年11月20日
* 更改：	
	1) 增加 M_SPE_SprintfDev 向自定义设备写字符串数据
	2) 增加 M_SPE_SetAttribute  设置通信属性参数
*
************************************************************************/

/************************************************************************
* 版本：3.0.2.25
* 作者：dolby.jiang
* 完成日期：2011年11月20日
* 更改：	
	1) 增加 M_SPE_AgePowerOn 节点上电
	2) 增加 M_SPE_AgePowerOff 节点关电
	3) 增加 M_SPE_AgeRead 读取数据
*
************************************************************************/

/************************************************************************
* 版本：3.0.2.29
* 作者：dolby.jiang
* 完成日期：2021年12月12日
* 更改：	
	1) 增加 M_SPE_SetIOPortVal 
	2) 增加 M_SPE_GetIOPortVal
*
************************************************************************/

/************************************************************************/
/*  特殊功能函数方法类                                                  */
/************************************************************************/
//class M_SPE_Pause 系统停止
class M_SPE_Pause:public BaseMethod
{
public:
	M_SPE_Pause();
	virtual ~M_SPE_Pause();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
};
//class M_SPE_SetDelayTime 系统延时
class M_SPE_SetDelayTime:public BaseMethod
{
public:
	M_SPE_SetDelayTime();
	virtual ~M_SPE_SetDelayTime();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
};
//class M_SPE_ACPRPowerDebug ACPR功率调试
class M_SPE_ACPRPowerDebug:public BaseMethod
{
public:
	M_SPE_ACPRPowerDebug();
	virtual ~M_SPE_ACPRPowerDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_SGDevName,m_PSADevName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_SPE_GetTimeSwitch 开关时间计算
class M_SPE_GetTimeSwitch:public BaseMethod
{
public:
	M_SPE_GetTimeSwitch();
	virtual ~M_SPE_GetTimeSwitch();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_SGDevName,m_PSADevName;
	int m_OutputParaMaxNum;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara[4];
};
//class M_SPE_ACPPowerDebug ACP功率调试
class M_SPE_ACPPowerDebug:public BaseMethod
{
public:
	M_SPE_ACPPowerDebug();
	virtual ~M_SPE_ACPPowerDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_SGDevName,m_PSADevName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_SPE_SEMPowerDebug SEM功率调试
class M_SPE_SEMPowerDebug:public BaseMethod
{
public:
	M_SPE_SEMPowerDebug();
	virtual ~M_SPE_SEMPowerDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_SGDevName,m_PSADevName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_SPE_EVMandPCDEPowerDebug EVM和PCDE功率调试
class M_SPE_EVMandPCDEPowerDebug:public BaseMethod
{
public:
	M_SPE_EVMandPCDEPowerDebug();
	virtual ~M_SPE_EVMandPCDEPowerDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_SGDevName,m_PSADevName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//class M_SPE_Add 相加运算
class M_SPE_Add:public BaseMethod
{
public:
	M_SPE_Add();
	virtual ~M_SPE_Add();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};	
//class M_SPE_Subtract	相减运算
class M_SPE_Subtract:public BaseMethod
{
public:
	M_SPE_Subtract();
	virtual ~M_SPE_Subtract();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};	
//class M_SPE_Multiply	相乘运算
class M_SPE_Multiply:public BaseMethod
{
public:
	M_SPE_Multiply();
	virtual ~M_SPE_Multiply();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};	
//class M_SPE_Divide 相除运算
class M_SPE_Divide:public BaseMethod
{
public:
	M_SPE_Divide();
	virtual ~M_SPE_Divide();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};	
//class M_SPE_Compare 比较
class M_SPE_Compare:public BaseMethod
{
public:
	M_SPE_Compare();
	virtual ~M_SPE_Compare();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara1,m_OutputPara2,m_OutputPara3;
};	
//class M_SPE_Equal 赋值
class M_SPE_Equal:public BaseMethod
{
public:
	M_SPE_Equal();
	virtual ~M_SPE_Equal();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};	
//class M_SPE_Absolute 绝对值
class M_SPE_Absolute:public BaseMethod
{
public:
	M_SPE_Absolute();
	virtual ~M_SPE_Absolute();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};
//class M_SPE_SpectrumPowerDebug 频谱模式功率调试
class M_SPE_SpectrumPowerDebug:public BaseMethod
{
public:
	M_SPE_SpectrumPowerDebug();
	virtual ~M_SPE_SpectrumPowerDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_SGDevName,m_PSADevName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};	
//class M_SPE_ACPRDebug ACPR调试
class M_SPE_ACPRDebug:public BaseMethod
{
public:
	M_SPE_ACPRDebug();
	virtual ~M_SPE_ACPRDebug();
	virtual int Init(void);
	virtual int Run(void);
private:
	typedef short int (_stdcall _ACPRDebug)(
		short int ,		//模块句柄
		short int ,		//电流表串口号
		short int ,		//信号源句柄	
		short int ,		//频谱仪句柄
		short,			//通道号
		float ,			//模块额定功率
		float ,			//信号源的上限幅度值
		int ,			//读取频谱仪的间隔时间(ms)
		float ,			//1.6MHz APCR上限指标
		float, 			//3.2MHz APCR上限指标
		float			//仪器误差范围
		);	

	_ACPRDebug *ACPRDebug;
protected:
	TParamSetStruct m_SGDevName,m_PSADevName, m_NTSDevName;
	TParamSetStruct m_InputPara[9];	
};	

//class M_SPE_ShowDialog 输入对话框
class M_SPE_ShowDialog:public BaseMethod
{
public:
	M_SPE_ShowDialog();
	virtual ~M_SPE_ShowDialog();
	virtual int Init(void);
	virtual int Run(void);
private:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
};

//class M_SPE_SpectrumPowerDebugEx 频谱模式功率调试
class M_SPE_SpectrumPowerDebugEx:public BaseMethod
{
public:
	M_SPE_SpectrumPowerDebugEx();
	virtual ~M_SPE_SpectrumPowerDebugEx();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_SGDevName,m_PSADevName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//class M_SPE_ACPRPowerDebugEx ACPR功率调试
class M_SPE_ACPRPowerDebugEx:public BaseMethod
{
public:
	M_SPE_ACPRPowerDebugEx();
	virtual ~M_SPE_ACPRPowerDebugEx();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_SGDevName,m_PSADevName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//class M_SPE_GetUpTimeSwitch 获取上升沿时间和上升延迟时间
class M_SPE_GetUpTimeSwitch:public BaseMethod
{
public:
	M_SPE_GetUpTimeSwitch();
	virtual ~M_SPE_GetUpTimeSwitch();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_SGDevName,m_PSADevName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
	TParamSetStruct m_OutputPara1,m_OutputPara2;
};
//class M_SPE_GetDownTimeSwitch 获取下降沿时间和下降延迟时间
class M_SPE_GetDownTimeSwitch:public BaseMethod
{
public:
	M_SPE_GetDownTimeSwitch();
	virtual ~M_SPE_GetDownTimeSwitch();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_SGDevName,m_PSADevName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
	TParamSetStruct m_OutputPara1,m_OutputPara2;
};

//class M_SPE_ShowPromptDialog 显示预定义对话框
class M_SPE_ShowPromptDialog:public BaseMethod
{
public:
	M_SPE_ShowPromptDialog();
	virtual ~M_SPE_ShowPromptDialog();
	virtual int Init(void);
	virtual int Run(void);
private:
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
	TParamSetStruct m_OutputPara;
};
//class M_SPE_SetLastDAOffset	修改指定温度范围内末级DA的偏移量
class M_SPE_SetLastDAOffset:public BaseMethod
{
public:
	M_SPE_SetLastDAOffset();
	virtual ~M_SPE_SetLastDAOffset();
	virtual int Init(void);
	virtual int Run(void);
private:
	TParamSetStruct m_NTSDevName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3,m_InputPara4;
	TParamSetStruct m_OutputPara[1024];
};	
/*
//class M_SPE_SetAutoACPR	ACPR自动调试
class M_SPE_SetAutoACPR:public BaseMethod
{
public:
	M_SPE_SetAutoACPR();
	virtual ~M_SPE_SetAutoACPR();
	virtual int Init(void);
	virtual int Run(void);
private:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_InputPara5,m_InputPara6,m_InputPara7;
};	*/

//class M_SPE_CompareA 比较
class M_SPE_CompareA:public BaseMethod
{
public:
	M_SPE_CompareA();
	virtual ~M_SPE_CompareA();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara[12];
	TParamSetStruct m_OutputPara1,m_OutputPara2;
};	

//class M_SPE_Power 某个数的多少次方
class M_SPE_Power:public BaseMethod
{
public:
	M_SPE_Power();
	virtual ~M_SPE_Power();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};	

//class M_SPE_DevReset	仪器复位
class M_SPE_DevReset:public BaseMethod
{
public:
	M_SPE_DevReset();
	virtual ~M_SPE_DevReset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DevType,m_DevName;
};	

//class M_SPE_PRMPowerDebug 功率计下功率调试
class M_SPE_PRMPowerDebug:public BaseMethod
{
public:
	M_SPE_PRMPowerDebug();
	virtual ~M_SPE_PRMPowerDebug();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_SGDevName, m_PRMDevName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;
};

//M_SPE_SeparateData 按照特定字符分离字符串，并获取指定位置的数据
class M_SPE_SeparateData:public BaseMethod
{
public:
	M_SPE_SeparateData();
	virtual ~M_SPE_SeparateData();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;	
	TParamSetStruct m_OutputPara1;	
};

//M_SPE_IntToString 把整型数据转化成字符串
class M_SPE_IntToString:public BaseMethod
{
public:
	M_SPE_IntToString();
	virtual ~M_SPE_IntToString();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;	
};	

//M_SPE_FloatToString 把浮点型数据转化成字符串
class M_SPE_FloatToString:public BaseMethod
{
public:
	M_SPE_FloatToString();
	virtual ~M_SPE_FloatToString();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;	
};	

//M_SPE_GetConditionData 获取指定范围内的数据
class M_SPE_GetConditionData:public BaseMethod
{
public:
	M_SPE_GetConditionData();
	virtual ~M_SPE_GetConditionData();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3, m_InputPara4;	
	TParamSetStruct m_OutputPara1;	
};	

//M_SPE_GetMaxPosition 获取Max值的位置
class M_SPE_GetMaxPosition:public BaseMethod
{
public:
	M_SPE_GetMaxPosition();
	virtual ~M_SPE_GetMaxPosition();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputPara1, m_InputPara2;	
	TParamSetStruct m_OutputPara1, m_OutputPara2;	
};

//M_SPE_GetMinPosition 获取Min值的位置
class M_SPE_GetMinPosition:public BaseMethod
{
public:
	M_SPE_GetMinPosition();
	virtual ~M_SPE_GetMinPosition();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputPara1, m_InputPara2;	
	TParamSetStruct m_OutputPara1, m_OutputPara2;	
};

//M_SPE_StrCat 字符串连接
class M_SPE_StrCat:public BaseMethod
{
public:
	M_SPE_StrCat();
	virtual ~M_SPE_StrCat();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputPara1, m_InputPara2;	
	TParamSetStruct m_OutputPara1;	
};	

//M_SPE_GainDebugWithENA 在网络分析仪下改变功放DA值来调试产品的增益
class M_SPE_GainDebugWithENA:public BaseMethod
{
public:
	M_SPE_GainDebugWithENA();
	virtual ~M_SPE_GainDebugWithENA();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_NTSDevName, m_ENADevName, m_ENATraceNo, m_MaxMarkerNo, m_MinMarkerNo;	
	TParamSetStruct m_LimitedDown, m_LimitedUp, m_LimitedDownOffset, m_MemeryNo, m_DAStartAddr, m_DACount, m_DAStep, m_DAUpLimited;	
	TParamSetStruct m_DelayTime;
};	

//M_SPE_OpenDev 打开设备
class M_SPE_OpenDev: public BaseMethod
{
public:
	M_SPE_OpenDev();
	virtual ~M_SPE_OpenDev();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1, m_InputPara2;	
	TParamSetStruct m_OutputPara1;
};
	
//M_SPE_CloseDev 关闭设备
class M_SPE_CloseDev: public BaseMethod
{
public:
	M_SPE_CloseDev();
	virtual ~M_SPE_CloseDev();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1, m_InputPara2;	
};
// M_SPE_SetBufSize 设置缓冲区长度(Mask 0:ALL 1:Tx_Buffer 2:Rx_Buffer)
class M_SPE_SetBufSize: public BaseMethod
{
public:
	M_SPE_SetBufSize();
	virtual ~M_SPE_SetBufSize();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DevName;
	TParamSetStruct m_InputPara1, m_InputPara2;	
};

// M_SPE_ClearBuf 清除缓冲区(Mask 0:ALL 1:Tx_Buffer 2:Rx_Buffer)
class M_SPE_ClearBuf: public BaseMethod
{
public:
	M_SPE_ClearBuf();
	virtual ~M_SPE_ClearBuf();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DevName;
	TParamSetStruct m_InputPara1;	
};

// M_SPE_WriteDev 向自定义设备写数据
class M_SPE_WriteDev: public BaseMethod
{
public:
	M_SPE_WriteDev();
	virtual ~M_SPE_WriteDev();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DevName;
	TParamSetStruct m_InputPara1;	
};

// M_SPE_ReadDev 从自定义设备读取数据
class M_SPE_ReadDev: public BaseMethod
{
public:
	M_SPE_ReadDev();
	virtual ~M_SPE_ReadDev();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DevName;	
	TParamSetStruct m_OutputPara1;
};

// M_SPE_QueryDev 查询
class M_SPE_QueryDev: public BaseMethod
{
public:
	M_SPE_QueryDev();
	virtual ~M_SPE_QueryDev();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DevName;	
	TParamSetStruct m_InputPara, m_OutputPara1;
};

// M_SPE_SprintfDev 向自定义设备写入数据(字符串)
class M_SPE_SprintfDev: public BaseMethod
{
public:
	M_SPE_SprintfDev();
	virtual ~M_SPE_SprintfDev();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DevName;
	TParamSetStruct m_InputPara1;	
};

/*
// M_SPE_ScanfDev 从自定义设备读取数据
class M_SPE_ReadDev: public BaseMethod
{
public:
	M_SPE_ReadDev();
	virtual ~M_SPE_ReadDev();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_DevName;	
	TParamSetStruct m_OutputPara1;
};
*/

// M_SPES_SetCom 设置Com通讯参数
class M_SPE_SetCom:public BaseMethod
{
public:
	M_SPE_SetCom();
	virtual ~M_SPE_SetCom();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[4];
};

// M_SPE_SetDTR 设置RTS(数据终端就绪)标志  硬件流控制 0:Low 1:Hight
class M_SPE_SetDTR:public BaseMethod
{
public:
	M_SPE_SetDTR();
	virtual ~M_SPE_SetDTR();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_SPE_SetRTS 设置RTS(设置请求数据发送)标志  硬件流控制 0:Low 1:Hight
class M_SPE_SetRTS:public BaseMethod
{
public:
	M_SPE_SetRTS();
	virtual ~M_SPE_SetRTS();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

// M_SPE_SetXOFF 设置XOFF(设置流数据停止发送)标志 软件流控制
class M_SPE_SetXOFF:public BaseMethod
{
public:
	M_SPE_SetXOFF();
	virtual ~M_SPE_SetXOFF();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};
// M_SPE_SetXON 设置XON(设置流数据继续发送)标志 软件流控制
class M_SPE_SetXON:public BaseMethod
{
public:
	M_SPE_SetXON();
	virtual ~M_SPE_SetXON();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_SPE_PolyFit 多项式拟合
class M_SPE_PolyFit:public BaseMethod
{
public:
	M_SPE_PolyFit();
	virtual ~M_SPE_PolyFit();
	virtual int Init(void);
	virtual int Run(void);
	
protected:	
	TParamSetStruct m_InputPara[4];
	TParamSetStruct m_OutputPara[3];

	//获取a的n次方
	virtual double pow_n(double	a, int n);
	
	//
	int mutiple(double a[][PARALENGTH], double b[][T+1], double c[][T+1], int Count, int N);

	//矩阵行列变换
	int matrix_trans(double a[][T+1], double b[][PARALENGTH], int Count, int N);

	//获得系数扩展矩阵
	int get_A(double matrix_A[][T+1], double x_y[][2], int Count, int N);

	//利用高斯消元法化简矩阵
	//arguA:增广矩阵
	//N:阶数
	int convert(double argu[][T+2], int N) ;

	int compute(double argu[][T+2], int N, double root[]);

	//获得Y值	
	int get_y(double trans_A[][PARALENGTH], double x_y[][2], double y[],int Count, int N) ;

	//追加Y轴值组成增广矩阵
	int cons_formula(double coef_A[][T+1], double y[], double coef_form[][T+2], int N);

	//利用递归求行列式的值 A:行列式 N:阶数	
	virtual double  ComputeMatrix(double *A,int N);
};			

// M_SPE_GetIDN 获取设备厂商信息
class M_SPE_GetIDN:public BaseMethod
{
public:
	M_SPE_GetIDN();
	virtual ~M_SPE_GetIDN();
	virtual int Init(void);
	virtual int Run(void);
	
protected:	
	TParamSetStruct m_InputPara[2];
	TParamSetStruct m_OutputPara;
};

//M_SPE_FFT FFT算法
class M_SPE_FFT:public BaseMethod
{
public:
	M_SPE_FFT();
	virtual ~M_SPE_FFT();
	virtual int Init(void);
	virtual int Run(void);
	
protected:	
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
	
	//定义旋转因子 N:采样个数
	ComplexStruct Wn(int N, int n);

	//复数加法，out=a+b
	ComplexStruct add(ComplexStruct a, ComplexStruct b);

	//复数减法，out=a-b
	ComplexStruct sub(ComplexStruct a, ComplexStruct b);

	//复数乘法，out=a*b
	ComplexStruct mul(ComplexStruct a, ComplexStruct b);

	//复数求模，out = a*b
	double mod(ComplexStruct a);

	//复数赋值
	ComplexStruct comcpy(ComplexStruct a);
	
	// 倒位
	int reverse(int n, int j);

	// FFT 算法 N:采样个数
	int DoFFT(ComplexStruct *x, ComplexStruct *F, int N);
};	

// M_SPE_GetLastErrStr 获取最近出错信息
class M_SPE_GetLastErrStr:public BaseMethod
{
public:
	M_SPE_GetLastErrStr();
	virtual ~M_SPE_GetLastErrStr();
	virtual int Init(void);
	virtual int Run(void);
	
protected:	
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;	
};

// M_SPE_SetAttributeDev  设置通信属性参数()
class M_SPE_SetAttributeDev:public BaseMethod
{
public:
	M_SPE_SetAttributeDev();
	virtual ~M_SPE_SetAttributeDev();
	virtual int Init(void);
	virtual int Run(void);
	
protected:		
	TParamSetStruct m_DevName;
	TParamSetStruct m_InputPara1, m_InputPara2;
};

// M_SPE_AgePowerOn 节点上电
class M_SPE_AgePowerOn:public BaseMethod
{
public:
	M_SPE_AgePowerOn();
	virtual ~M_SPE_AgePowerOn();
	virtual int Init(void);
	virtual int Run(void);
	
protected:		
//	TParamSetStruct m_DevName;
	TParamSetStruct m_InputPara1, m_InputPara2;
	TParamSetStruct m_OutputPara1;
};

// M_SPE_AgePowerOff 节点关电
class M_SPE_AgePowerOff:public BaseMethod
{
public:
	M_SPE_AgePowerOff();
	virtual ~M_SPE_AgePowerOff();
	virtual int Init(void);
	virtual int Run(void);
	
protected:		
//	TParamSetStruct m_DevName;
	TParamSetStruct m_InputPara1, m_InputPara2;
	TParamSetStruct m_OutputPara1;
};

// M_SPE_AgeRead 读取数据
class M_SPE_AgeRead:public BaseMethod
{
public:
	M_SPE_AgeRead();
	virtual ~M_SPE_AgeRead();
	virtual int Init(void);
	virtual int Run(void);
	
protected:		
//	TParamSetStruct m_DevName;
	TParamSetStruct m_InputPara1, m_InputPara2;
	TParamSetStruct m_OutputPara1, m_OutputPara2, m_OutputPara3 ;
};

// 向I/O口写数据 
class M_SPE_SetIOPortVal:public BaseMethod
{
public:
	M_SPE_SetIOPortVal();
	virtual ~M_SPE_SetIOPortVal();
	virtual int Init(void);
	virtual int Run(void);
	
protected:		
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;
};

// 从I/O读取数据
class M_SPE_GetIOPortVal:public BaseMethod
{
public:
	M_SPE_GetIOPortVal();
	virtual ~M_SPE_GetIOPortVal();
	virtual int Init(void);
	virtual int Run(void);
	
protected:	
	TParamSetStruct m_InputPara1, m_InputPara2;
	TParamSetStruct m_OutputPara1;
};

// 设置T/R组件并口数据(Pin2:Data Pin3:CLK Pin4:Lock)
class M_SPE_SetIOTRBits:public BaseMethod
{
public:
	M_SPE_SetIOTRBits();
	virtual ~M_SPE_SetIOTRBits();
	virtual int Init(void);
	virtual int Run(void);
	
protected:	
	TParamSetStruct m_InputPara1, m_InputPara2;
};

// 设置IO触发方式 0:Positive(上升沿) 1:Negative(下降沿)
class M_SPE_SetIOTrigPolarity:public BaseMethod
{
public:
	M_SPE_SetIOTrigPolarity();
	virtual ~M_SPE_SetIOTrigPolarity();
	virtual int Init(void);
	virtual int Run(void);
	
protected:	
	TParamSetStruct m_InputPara1, m_InputPara2;
};