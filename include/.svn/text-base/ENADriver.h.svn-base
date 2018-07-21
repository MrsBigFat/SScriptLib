/************************************************************************
* Copyright (c) 2009,芯通科技有限公司
* All rights reserved.
* 文件名称：ENADriver.h
* 文件标识：reserved
* 摘要：ENADriver.dll的外部接口文件
*
************************************************************************/

// The following ifdef block is the standard way of creating macros whiCh make exporting 
// from a DLL simpler. All files within this DLL are compiled with the ENADRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// ENADRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef ENADRIVER_EXPORTS
#define ENADRIVER_API __declspec(dllexport)
#else
#define ENADRIVER_API __declspec(dllimport)
#endif

/************************************************************************
* 版本：2.0.1.0
* 作者：dolby.jiang
* 完成日期：2009年8月26日
* 更改：文件建立
*
************************************************************************/

/************************************************************************
* 版本：2.0.1.1
* 作者：dolby.jiang
* 完成日期：2009年9月23日
* 更改：增加发送命令，获取返回数据函数
*
************************************************************************/


/************************************************************************
* 版本：2.0.1.2
* 作者：dolby.jiang
* 完成日期：2009年10月13日
* 更改：修改方法加载位置
*
************************************************************************/

/************************************************************************
* 版本：2.0.1.3
* 作者：dolby.jiang
* 完成日期：2009年10月25日
* 更改：增加ENA_GetMarkerXValue ENA_GetMarkerFreqOfPC函数
*
************************************************************************/

/************************************************************************
* 版本：2.0.1.4
* 作者：dolby.jiang
* 完成日期：2009年11月3日
* 更改：修改ENA_SetStartandStopFreq函数
*
************************************************************************/


/************************************************************************
* 版本：2.0.1.5
* 作者：dolby.jiang
* 完成日期：2009年11月23日
* 更改：修改打开函数
*
************************************************************************/


/************************************************************************
* 版本：2.0.1.6
* 作者：dolby.jiang
* 完成日期：2009年12月14日
* 更改：修改方法执行句柄
*
************************************************************************/


/************************************************************************
* 版本：2.0.1.7
* 作者：dolby.jiang
* 完成日期：2010年3月18日
* 更改：增加ENA_GetTraceDataX
*
************************************************************************/

/************************************************************************
* 版本：3.0.0.1
* 作者：dolby.jiang
* 完成日期：2011年5月10日
* 更改：
	1 增加 ENA_GetSweepType
	2 增加 ENA_SetTrigSource
	3 增加 ENA_SetTrigMode
	4 增加 ENA_SaveTraceByName
	5 增加 ENA_SetTraceMathTypeByName
	6 增加 ENA_DeleteTraceByName
	7 增加 ENA_DeleteAllTrace
	8 增加 ENA_SetMarkerSearchFreqByName
	9 增加 ENA_GetMarkerValueByName
	10 增加 ENA_GetFluctuateByName
	11 增加 ENA_GetMarkerFreqByName
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.3
* 作者：dolby.jiang
* 完成日期：2011年8月12日
* 更改：
	1 将所有函数参数中double->double 
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.5
* 作者：dolby.jiang
* 完成日期：2011年11月16日
* 更改：
1 增加 SetMarkerFreq
*
************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
	
	//打开并初始化设备
	ENADRIVER_API short int	_stdcall	ENA_OpenDev(char *ConnectStr, short int *devHandle);

	//关闭设备
	ENADRIVER_API short int	_stdcall	ENA_CloseDev(short int Handle);

	//复位
	ENADRIVER_API short int	_stdcall	ENA_Reset(short int Handle);

	//加载文件
	ENADRIVER_API short int	_stdcall	ENA_LoadFile(short int Handle, char *FileName);

	//保存文件(FileType(0:State 1:CST 2:DST 3:CDST 4:FDAT 5:IMAG))
	ENADRIVER_API short int	_stdcall	ENA_SaveFile(short int Handle,char *FileName, int FileType);
	
	//选择曲线
	ENADRIVER_API short int	_stdcall	ENA_SetChannelTrace(short int Handle, unsigned short Ch, int TraceIndex);
	//获取最小Marker值
	ENADRIVER_API short int	_stdcall	ENA_GetMarkerMin(short int Handle, unsigned short Ch, 
		unsigned short MarkerIndex, double*value);
	
	//获取最大Marker值
	ENADRIVER_API short int	_stdcall	ENA_GetMarkerMax(short int Handle, unsigned short Ch, 
		unsigned short MarkerIndex, double *value);

	//获取指定频率点的Marker值
	ENADRIVER_API short int	_stdcall	ENA_GetMarkerFreq(short int Handle, 
		unsigned short Ch, unsigned short MarkerIndex, double Freq, double *value);
	
	//设置平均状态 0:ON;1:OFF:
	ENADRIVER_API short int	_stdcall	ENA_SetAverageState(short int Handle, unsigned short Ch, unsigned short State); 

	//设置仪器为AutoSclae模式
	ENADRIVER_API short int	_stdcall	ENA_SetScaleAuto(short int Handle, unsigned short Ch, int TraceIndex);

	//设置Marker SearCh 频率范围(单位:MHz)
	ENADRIVER_API short int	_stdcall	ENA_SetMarkerStartandStopFreq(short int Handle,	unsigned short Ch, int TraceIndex,
		unsigned short markerindex,	double start, double stop);

	//保存测试数据到内存中
	ENADRIVER_API short int	_stdcall	ENA_SaveDataToMemory(short int Handle, unsigned short Ch, int TraceIndex);

	//设置数据的处理方式 (0:Off 1:Data/Mem 2:Data*Mem 3:Data-Mem 4:Data+Mem)
	ENADRIVER_API short int	_stdcall	ENA_SetTraceMathType(short int Handle, unsigned short Ch, int TraceIndex,	short type);

	//设置曲线形式 0:logarithmic magnitude 1:phase 2:group delay 3:smith chart(Lin/phase)
	//4:smith chart(Log/phase) 5:smith chart(Real/Imag) 6:smith chart(R+jX) 7:smith chart(G+jB)
	//8:polar(Lin) 9:polar(Log) 10:polar(Re/Im) 11:linear magnitude 12:SWR
	//13:real 14:imaginary 15:expanded phase 16:positive phase
	ENADRIVER_API short int _stdcall ENA_SetTraceFormat( short int Handle,	unsigned short Ch ,	int TraceIndex,	short type);

	//设置曲线显示类型 0:data 1:memery 2:data&memery 3:off
	ENADRIVER_API short int _stdcall ENA_SetDisplayTrace(short int Handle, unsigned short Ch, int TraceIndex, short type);

	//获取功率范围内数据点的X和Y坐标值
	ENADRIVER_API short int _stdcall ENA_GetSearchOutputPowerPosition(short int Handle, unsigned short Ch, int TraceIndex,
		int MarkerIndex, double Start, double Stop, double SearChStep, double TargetOutputPower, double Tolerance, 
		double *XValue, double *YValue);

	//获取功率偏移量数据点的X和Y坐标值
	ENADRIVER_API short int _stdcall ENA_GetSearchYDiffPosition(short int Handle, unsigned short Ch, int TraceIndex,
		int MarkerOriginal, int MarkerIndex, double Start, double Stop,	double SearChStep, double Diff,
		double Tolerance, double *XValue,	double *YValue);

	//获取指定Marker点的值
	ENADRIVER_API short int _stdcall ENA_GetMarkerValue(short int Handle, unsigned short Ch, unsigned short markerindex, 
		double*value);

	//设置RF输出端口的状态(0:off 1:on)
	ENADRIVER_API	short int _stdcall ENA_SetRFOutputState(short int Handle,short State);
	
	//设置RF输出端口的功率值
	ENADRIVER_API	short int _stdcall ENA_SetRFOutPower(short int Handle,unsigned short Ch,double pwr);

	//获取指定带宽范围内的平坦度
	ENADRIVER_API	short int _stdcall ENA_GetFluctuate(short int Handle,unsigned short Ch,int TraceIndex,
		double bandwidth, double *fluctuate);

	//获取曲线的Y轴数据
	ENADRIVER_API	short int _stdcall ENA_GetTraceData(short int Handle,unsigned short Ch,int TraceIndex,double *data, int *Count);

	//获取曲线的X轴数据
	ENADRIVER_API	short int _stdcall ENA_GetTraceDataX(short int Handle,unsigned short Ch,int TraceIndex,double *data, int *Count);
	
	//设置起止频率
	ENADRIVER_API	short int _stdcall ENA_SetStartandStopFreq(short int Handle,unsigned short Ch,double startFreq, double stopFreq);
	
	//把曲线数据保存到PC内存中
	ENADRIVER_API	short int _stdcall ENA_SaveTraceToMemoryOfPC(short int Handle,unsigned short Ch,int TraceIndex);

	//设置PC内存数据的处理方式 (0:Off 1:Data/Mem 2:Data*Mem 3:Data-Mem 4:Data+Mem)
	ENADRIVER_API	short int _stdcall ENA_SetTraceMathTypeOfPC(short int Handle,unsigned short Ch,int TraceIndex,short type);

	//设置MARKER 在PC内存数据上查找范围(MHz) 
	ENADRIVER_API	short int _stdcall ENA_SetMarkerSearchFreqOfPC(short int Handle,int TraceIndex,double start,double stop);

	//从PC内存数据获取最大值和最小值
	ENADRIVER_API	short int _stdcall ENA_GetMarkerValueOfPC(short int Handle,int TraceIndex,double*max, double *min);

	//从PC内存数据中获取指定带宽范围内的平坦度
	ENADRIVER_API	short int _stdcall ENA_GetFluctuateOfPC(short int Handle, int TraceIndex,double bandwidth, double *fluctuate);

	//开启|关闭曲线平滑 (0:OFF	1:ON)
	ENADRIVER_API	short int _stdcall ENA_SetSmooth(short int Handle, unsigned short Ch,int TraceIndex,short State);

	//设置端口方向(Type: 0:S12 1:S21)
	ENADRIVER_API	short int _stdcall ENA_SetCalPortForward(short int Handle, unsigned short Ch, int Type);
	
	//设置校准类型(1:Open 2:Short 3:Thru 4:Enhanced Response 5:Full 1-Port 6:Full 2-Port)
	ENADRIVER_API	short int _stdcall ENA_SetCalType(short int Handle, unsigned short Ch, int Type);
	
	//获得校准原始数据(1:Open 2:Short 3:Load 4:Thru  5:Isolation)
	ENADRIVER_API	short int _stdcall ENA_GetCalibrationData(short int Handle, unsigned short Ch, int Type);
	
	//设置电子校准类型(1:Full 1-Port 2:Full 2-Port 3:Enhanced Response 4:Response(Thru))
	ENADRIVER_API	short int _stdcall ENA_SetECalType(short int Handle, unsigned short Ch, int Type);	
	
	//保存校准数据
	ENADRIVER_API	short int _stdcall ENA_SaveCalibration(short int Handle, unsigned short Ch);
	
	//设置校准件类型
	ENADRIVER_API	short int _stdcall ENA_SetCalKit(short int Handle, unsigned short Ch, int Type);

	//获取设备型号信息
	ENADRIVER_API	short int _stdcall ENA_GetIDN(short int Handle, char *IDN);
	
	//发送指令
	ENADRIVER_API	short int _stdcall	ENA_SendCmd(short int Handle, char *Command);
	
	//获取返回指令值
	ENADRIVER_API	short int _stdcall	ENA_GetCmd(short int Handle, char *Command, char *RetStr);

	//获取指定Marker点X轴值
	ENADRIVER_API	short int _stdcall	ENA_GetMarkerXValue(short int Handle, unsigned short Ch, unsigned short Marker, double *XValue);
	
	//从PC内存数据获取指定频率点Marker值
	ENADRIVER_API	short int _stdcall	ENA_GetMarkerFreqOfPC(short int Handle, int Traceindex, unsigned short Marker, double Freq, double *Value);
	
	// 获取扫描类型 (0:Linear 1: Log 2: Segment 3:Power)
	ENADRIVER_API	short int _stdcall	ENA_GetSweepType(short int Handle, unsigned short Ch, int *Type);
	
	// 设置触发源(0:Internal 1:External 2:Bus)
	ENADRIVER_API	short int _stdcall	ENA_SetTrigSource(short int Handle, int TrigSourcr);
	
	// 设置触发类型(0:IMMediate 1:Single 2:Contine)
	ENADRIVER_API	short int _stdcall	ENA_SetTrigMode(short int Handle, int Mode);
	
	// 以命名方式将测试曲线数据保存到PC内存中
	ENADRIVER_API	short int _stdcall	ENA_SaveTraceByName(short int Handle, unsigned short ch, int traceindex, char *Name) ;
	
	// 以命名方式处理PC内存数据(0:Off 1:Trace1/Trace2 2:Trace1*Trace2 3:Trace1-Trace2 4:Trace1+Trace2)
	ENADRIVER_API	short int _stdcall	ENA_SetTraceMathTypeByName(short int Handle, char *Trace1, char *Trace2, short type, char *NewName);
	
	// 删除一条PC内存曲线
	ENADRIVER_API	short int _stdcall	ENA_DeleteTraceByName(short int Handle, char *Name) ;
	
	// 删除所有PC内存曲线
	ENADRIVER_API	short int _stdcall	ENA_DeleteAllTrace(short int Handle);
	
	// 在PC内存数据中设置MARKER 的查找范围(MHz) 
	ENADRIVER_API	short int _stdcall	ENA_SetMarkerSearchFreqByName(short int Handle, char *Name, double Start, double Stop);
	
	// 从PC内存数据中获取最大值和最小值
	ENADRIVER_API	short int _stdcall	ENA_GetMarkerValueByName(short int Handle, char *Name, double *Max, double *Min);
	
	// 从PC内存数据中获取指定带宽范围内的平坦度(MHz) 
	ENADRIVER_API	short int _stdcall	ENA_GetFluctuateByName(short int Handle, char *Name, double BandWidth, double *Fluctuate);
	
	// 从PC内存数据获取指定频率点Marker值
	ENADRIVER_API	short int _stdcall	ENA_GetMarkerFreqByName(short int Handle, char *Name, unsigned short Marker, double Freq, double *Value);

	// 从PC内存获取曲线的Y轴数据
	ENADRIVER_API	short int _stdcall	ENA_GetTraceDataYByName(short int Handle, char *Name, double *Data, int *Count);
	
	// 从PC内存获取曲线的X轴数据
	ENADRIVER_API	short int _stdcall	ENA_GetTraceDataXByName(short int Handle, char *Name, double *Data, int *Count);
	
	// 设置指定Marker点频率值(MHz)
	ENADRIVER_API	short int _stdcall	ENA_SetMarkerFreq(short int Handle, unsigned short ch, unsigned short Marker, double Freq);
	
		
#ifdef __cplusplus
}
#endif


