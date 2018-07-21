#pragma warning( disable : 4786)

#include <windows.h>
#include <Vector>
#include <map>
#include <string>
#include <algorithm>

#include "Method.h"
#include "NTSDin.h"
#include "NTSScriptLib.h"

//#include ".\include\ENADriver.h"
//#pragma comment(lib,".\\lib\\ENADriver.lib")


/************************************************************************
* 版本：2.0.0.45
* 作者：dolby.jiang
* 完成日期：2009年10月10日
* 更改：第一次整理
*
************************************************************************/


/************************************************************************
* 版本：2.1.0.7
* 作者：dolby.jiang
* 完成日期：2010年1月26日
* 更改：1、增加M_ENA_GetTraceData
*
************************************************************************/


/************************************************************************
* 版本：2.1.0.9
* 作者：dolby.jiang
* 完成日期：2010年3月19日
* 更改：1、增加M_ENA_GetTraceDataX
*
************************************************************************/

/************************************************************************/
/*  矢量网络分析仪驱动程序方法类                                        */
/************************************************************************/
//M_ENA_Reset 设备复位
class M_ENA_Reset:public BaseMethod
{
public:
	M_ENA_Reset();
	virtual ~M_ENA_Reset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	
};
//M_ENA_LoadFile 加载矢网工作状态文件
class M_ENA_LoadFile:public BaseMethod
{
public:
	M_ENA_LoadFile();
	virtual ~M_ENA_LoadFile();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};
//M_ENA_SetChannelTrace 设置矢网通道和曲线
class M_ENA_SetChannelTrace:public BaseMethod
{
public:
	M_ENA_SetChannelTrace();
	virtual ~M_ENA_SetChannelTrace();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_InputPara2;	
};
//M_ENA_GetMarkerMin 获取指定通道和曲线的最小MARKER值
class M_ENA_GetMarkerMin:public BaseMethod
{
public:
	M_ENA_GetMarkerMin();
	virtual ~M_ENA_GetMarkerMin();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};
//M_ENA_GetMarkerMax 获取指定通道和曲线的最大MARKER值
class M_ENA_GetMarkerMax:public BaseMethod
{
public:
	M_ENA_GetMarkerMax();
	virtual ~M_ENA_GetMarkerMax();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_ENA_GetMarkerFreq 获取指定通道、曲线和频率点MARKER点的值
class M_ENA_GetMarkerFreq:public BaseMethod
{
public:
	M_ENA_GetMarkerFreq();
	virtual ~M_ENA_GetMarkerFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
	TParamSetStruct m_OutputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_ENA_SetAverageState 设置矢网的平均状态
class M_ENA_SetAverageState:public BaseMethod
{
public:
	M_ENA_SetAverageState();
	virtual ~M_ENA_SetAverageState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//M_ENA_SetScaleAuto 设置矢网为AutoScale模式
class M_ENA_SetScaleAuto:public BaseMethod
{
public:
	M_ENA_SetScaleAuto();
	virtual ~M_ENA_SetScaleAuto();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//M_ENA_SetMarkerStartandStopFreq 设置Marker Search 频率范围(单位:MHz)
class M_ENA_SetMarkerStartandStopFreq:public BaseMethod
{
public:
	M_ENA_SetMarkerStartandStopFreq();
	virtual ~M_ENA_SetMarkerStartandStopFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[5];
};
//M_ENA_SaveDataToMemory 保存测试数据到内存中
class M_ENA_SaveDataToMemory:public BaseMethod
{
public:
	M_ENA_SaveDataToMemory();
	virtual ~M_ENA_SaveDataToMemory();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//M_ENA_SetTraceMathType 设置数据的处理方式 (0:Off 1:Data/Mem 2:Data*Mem 3:Data-Mem 4:Data+Mem)
class M_ENA_SetTraceMathType:public BaseMethod
{
public:
	M_ENA_SetTraceMathType();
	virtual ~M_ENA_SetTraceMathType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};
//M_ENA_SetTraceFormat 设置曲线形式 0:logarithmic magnitude 1:phase 2:group delay 3:smith chart(Lin/phase)
//4:smith chart(Log/phase) 5:smith chart(Real/Imag) 6:smith chart(R+jX) 7:smith chart(G+jB)
//8:polar(Lin) 9:polar(Log) 10:polar(Re/Im) 11:linear magnitude 12:SWR
//13:real 14:imaginary 15:expanded phase 16:positive phase

class M_ENA_SetTraceFormat:public BaseMethod
{
public:
	M_ENA_SetTraceFormat();
	virtual ~M_ENA_SetTraceFormat();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};
//M_ENA_SetDisplayTrace 设置曲线显示类型 0:data 1:MEM 2:DATA&MEN 3:OFF
class M_ENA_SetDisplayTrace:public BaseMethod
{
public:
	M_ENA_SetDisplayTrace();
	virtual ~M_ENA_SetDisplayTrace();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};
//M_ENA_GetSearchOutputPowerPosition 获取功率范围内数据点的X和Y坐标值
class M_ENA_GetSearchOutputPowerPosition:public BaseMethod
{
public:
	M_ENA_GetSearchOutputPowerPosition();
	virtual ~M_ENA_GetSearchOutputPowerPosition();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3,m_InputPara4,m_InputPara5,m_InputPara6,m_InputPara7,m_InputPara8;
	TParamSetStruct m_OutputPara1,m_OutputPara2;
};
//M_ENA_GetSearchYDiffPosition 获取功率偏移量数据点的X和Y坐标值
class M_ENA_GetSearchYDiffPosition:public BaseMethod
{
public:
	M_ENA_GetSearchYDiffPosition();
	virtual ~M_ENA_GetSearchYDiffPosition();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3,m_InputPara4,m_InputPara5,m_InputPara6,m_InputPara7,m_InputPara8,m_InputPara9;
	TParamSetStruct m_OutputPara1,m_OutputPara2;
};
//M_ENA_GetMarkerValue 获取指定Marker点的指
class M_ENA_GetMarkerValue:public BaseMethod
{
public:
	M_ENA_GetMarkerValue();
	virtual ~M_ENA_GetMarkerValue();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};

//M_ENA_SetRFOutputState 设置RF输出端口的状态
class M_ENA_SetRFOutputState:public BaseMethod
{
public:
	M_ENA_SetRFOutputState();
	virtual ~M_ENA_SetRFOutputState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//M_ENA_SetRFOutPower 设置RF输出端口的功率值
class M_ENA_SetRFOutPower:public BaseMethod
{
public:
	M_ENA_SetRFOutPower();
	virtual ~M_ENA_SetRFOutPower();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//M_ENA_GetFluctuate 获取指定带宽范围内的平坦度
class M_ENA_GetFluctuate:public BaseMethod
{
public:
	M_ENA_GetFluctuate();
	virtual ~M_ENA_GetFluctuate();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
	TParamSetStruct m_OutputPara;
};

//M_ENA_SetStartandStopFreq 设置起止频率
class M_ENA_SetStartandStopFreq:public BaseMethod
{
public:
	M_ENA_SetStartandStopFreq();
	virtual ~M_ENA_SetStartandStopFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//M_ENA_SaveTraceToMemoryOfPC 把曲线数据保存到PC内存中
class M_ENA_SaveTraceToMemoryOfPC:public BaseMethod
{
public:
	M_ENA_SaveTraceToMemoryOfPC();
	virtual ~M_ENA_SaveTraceToMemoryOfPC();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};
//M_ENA_SetTraceMathTypeOfPC 设置PC内存数据的处理方式 (0:Off 1:Data/Mem 2:Data*Mem 3:Data-Mem 4:Data+Mem)
class M_ENA_SetTraceMathTypeOfPC:public BaseMethod
{
public:
	M_ENA_SetTraceMathTypeOfPC();
	virtual ~M_ENA_SetTraceMathTypeOfPC();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};
//M_ENA_SetMarkerSearchFreqOfPC 设置MARKER 在PC内存数据上查找范围(MHz) 
class M_ENA_SetMarkerSearchFreqOfPC:public BaseMethod
{
public:
	M_ENA_SetMarkerSearchFreqOfPC();
	virtual ~M_ENA_SetMarkerSearchFreqOfPC();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2, m_InputPara3;
};
//M_ENA_GetMarkerValueOfPC 从PC内存数据获取最大值和最小值
class M_ENA_GetMarkerValueOfPC:public BaseMethod
{
public:
	M_ENA_GetMarkerValueOfPC();
	virtual ~M_ENA_GetMarkerValueOfPC();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1,m_OutputPara2;
};
//M_ENA_GetFluctuateOfPC 从PC内存数据中获取指定带宽范围内的平坦度(MHz) 
class M_ENA_GetFluctuateOfPC:public BaseMethod
{
public:
	M_ENA_GetFluctuateOfPC();
	virtual ~M_ENA_GetFluctuateOfPC();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;
	TParamSetStruct m_OutputPara;
};

//M_ENA_SetSmooth 开启|关闭曲线平滑 (0:OFF	1:ON)
class M_ENA_SetSmooth:public BaseMethod
{
public:
	M_ENA_SetSmooth();
	virtual ~M_ENA_SetSmooth();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
};

//M_ENA_SaveFile 保存文件(filetype(0:STATE 1:CST 2:DST 3:CDST 4:FDAT 5:IMAG))
class M_ENA_SaveFile:public BaseMethod
{
public:
	M_ENA_SaveFile();
	virtual ~M_ENA_SaveFile();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};

//M_ENA_SetCalPortForward 设置端口方向(Type: 0:S12 1:S21)
class M_ENA_SetCalPortForward:public BaseMethod
{
public:
	M_ENA_SetCalPortForward();
	virtual ~M_ENA_SetCalPortForward();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};

//M_ENA_SetCalType 设置校准类型(1:Open 2:Short 3:Thru 4:Enhanced Response 5:Full 1-Port 6:Full 2-Port)
class M_ENA_SetCalType:public BaseMethod
{
public:
	M_ENA_SetCalType();
	virtual ~M_ENA_SetCalType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};

//M_ENA_GetCalibrationData 获得校准原始数据(1:Open 2:Short 3:Load 4:Thru  5:Isolation)
class M_ENA_GetCalibrationData:public BaseMethod
{
public:
	M_ENA_GetCalibrationData();
	virtual ~M_ENA_GetCalibrationData();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};

//M_ENA_SetECalType 设置电子校准类型(1:Full 1-Port 2:Full 2-Port 3:Enhanced Response 4:Response(Thru))
class M_ENA_SetECalType:public BaseMethod
{
public:
	M_ENA_SetECalType();
	virtual ~M_ENA_SetECalType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};

//M_ENA_SaveCalibration 保存校准数据
class M_ENA_SaveCalibration:public BaseMethod
{
public:
	M_ENA_SaveCalibration();
	virtual ~M_ENA_SaveCalibration();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

//M_ENA_SetCalKit 设置校准件类型
class M_ENA_SetCalKit:public BaseMethod
{
public:
	M_ENA_SetCalKit();
	virtual ~M_ENA_SetCalKit();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
};

//class M_ENA_SendCmd 发送指令
class M_ENA_SendCmd:public BaseMethod
{
public:
	M_ENA_SendCmd();
	virtual ~M_ENA_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};
//class M_ENA_GetCmd 发送指令并获取指令的返回数据
class M_ENA_GetCmd:public BaseMethod
{
public:
	M_ENA_GetCmd();
	virtual ~M_ENA_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
};

//class M_ENA_GetIDN 获取设备型号信息
class M_ENA_GetIDN:public BaseMethod
{
public:
	M_ENA_GetIDN();
	virtual ~M_ENA_GetIDN();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

//M_ENA_GetMarkerXValue 获取指定Marker点X轴值
class M_ENA_GetMarkerXValue:public BaseMethod
{
public:
	M_ENA_GetMarkerXValue();
	virtual ~M_ENA_GetMarkerXValue();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_OutputPara;
};

//M_ENA_GetMarkerFreqOfPC 从PC内存数据获取指定频率点Marker值
class M_ENA_GetMarkerFreqOfPC:public BaseMethod
{
public:
	M_ENA_GetMarkerFreqOfPC();
	virtual ~M_ENA_GetMarkerFreqOfPC();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2,m_InputPara3;
	TParamSetStruct m_OutputPara;
	TParamSetStruct m_InputDeviceName;
};

// class M_ENA_GetTraceData 获取曲线的数据
class M_ENA_GetTraceData:public BaseMethod
{
public:
	M_ENA_GetTraceData();
	virtual ~M_ENA_GetTraceData();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;	
	TParamSetStruct m_OutputPara;
	
};

// class M_ENA_GetTraceDataX 获取曲线的数据
class M_ENA_GetTraceDataX:public BaseMethod
{
public:
	M_ENA_GetTraceDataX();
	virtual ~M_ENA_GetTraceDataX();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;	
	TParamSetStruct m_OutputPara;
	
};

// class M_ENA_GetSweepType 获取扫描类型 (0:Linear 1: Log 2: Segment 3:Power)
class M_ENA_GetSweepType:public BaseMethod
{
public:
	M_ENA_GetSweepType();
	virtual ~M_ENA_GetSweepType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara;	
};

// 设置触发源(0:Internal 1:External 2:Bus)
class M_ENA_SetTrigSource:public BaseMethod
{
public:
	M_ENA_SetTrigSource();
	virtual ~M_ENA_SetTrigSource();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	
};

// 设置触发类型(0:IMMediate 1:Single 2:Contine)
class M_ENA_SetTrigMode:public BaseMethod
{
public:
	M_ENA_SetTrigMode();
	virtual ~M_ENA_SetTrigMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

// 以命名方式将测试曲线数据保存到PC内存中
class M_ENA_SaveTraceByName:public BaseMethod
{
public:
	M_ENA_SaveTraceByName();
	virtual ~M_ENA_SaveTraceByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;		
};

// 以命名方式处理PC内存数据(0:Off 1:Trace1/Trace2 2:Trace1*Trace2 3:Trace1-Trace2 4:Trace1+Trace2)
class M_ENA_SetTraceMathTypeByName:public BaseMethod
{
public:
	M_ENA_SetTraceMathTypeByName();
	virtual ~M_ENA_SetTraceMathTypeByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3, m_InputPara4;		
};

// 删除一条PC内存曲线
class M_ENA_DeleteTraceByName:public BaseMethod
{
public:
	M_ENA_DeleteTraceByName();
	virtual ~M_ENA_DeleteTraceByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	
};

// 删除所有PC内存曲线
class M_ENA_DeleteAllTrace:public BaseMethod
{
public:
	M_ENA_DeleteAllTrace();
	virtual ~M_ENA_DeleteAllTrace();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;	
};

// 在PC内存数据中设置MARKER 的查找范围(MHz) 
class M_ENA_SetMarkerSearchFreqByName:public BaseMethod
{
public:
	M_ENA_SetMarkerSearchFreqByName();
	virtual ~M_ENA_SetMarkerSearchFreqByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;		
};

// 从PC内存数据中获取最大值和最小值
class M_ENA_GetMarkerValueByName:public BaseMethod
{
public:
	M_ENA_GetMarkerValueByName();
	virtual ~M_ENA_GetMarkerValueByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1, m_OutputPara2;	
};

// 从PC内存数据中获取指定带宽范围内的平坦度(MHz) 
class M_ENA_GetFluctuateByName:public BaseMethod
{
public:
	M_ENA_GetFluctuateByName();
	virtual ~M_ENA_GetFluctuateByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;	
	TParamSetStruct m_OutputPara1;
	
};

// 从PC内存数据获取指定频率点Marker值
class M_ENA_GetMarkerFreqByName:public BaseMethod
{
public:
	M_ENA_GetMarkerFreqByName();
	virtual ~M_ENA_GetMarkerFreqByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;	
	TParamSetStruct m_OutputPara1;
	
};

//  class M_ENA_GetTraceDataYByName 从PC内存获取曲线的Y轴数据	
class M_ENA_GetTraceDataYByName:public BaseMethod
{
public:
	M_ENA_GetTraceDataYByName();
	virtual ~M_ENA_GetTraceDataYByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
	
};

// class M_ENA_GetTraceDataXByName 从PC内存获取曲线的X轴数据
class M_ENA_GetTraceDataXByName:public BaseMethod
{
public:
	M_ENA_GetTraceDataXByName();
	virtual ~M_ENA_GetTraceDataXByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
	
};

// class M_ENA_SetMarkerFreq 设置指定Marker点频率值(MHz)
class M_ENA_SetMarkerFreq:public BaseMethod
{
public:
	M_ENA_SetMarkerFreq();
	virtual ~M_ENA_SetMarkerFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[4];		
	
};