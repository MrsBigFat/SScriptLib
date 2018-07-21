/************************************************************************
* Copyright (c) 2009,芯通科技有限公司
* All rights reserved.
* 文件名称：PSADriver.h
* 文件标识：reserved
* 摘要：PSADriver.dll的外部接口文件
*
************************************************************************/

// The following ifdef block is the standard way of creating macros whiCh make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PSADRIVER_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PSADRIVER_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
#ifdef PSADRIVER_EXPORTS
#define PSADRIVER_API __declspec(dllimport)
#else
#define PSADRIVER_API __declspec(dllexport)
#endif

#pragma warning(disable:4786)
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
* 更改：增加手动配置ACPR的方法接口
*
************************************************************************/


/************************************************************************
* 版本：2.0.1.2
* 作者：dolby.jiang
* 完成日期：2009年9月25日
* 更改：修改SetMeasNoiseBW接口
*
************************************************************************/


/************************************************************************
* 版本：2.0.1.3
* 作者：dolby.jiang
* 完成日期：2009年9月30日
* 更改：修改函数加载位置
*
************************************************************************/


/************************************************************************
* 版本：2.0.1.4
* 作者：dolby.jiang
* 完成日期：2009年11月23日
* 更改：修改打开函数
*
************************************************************************/

/************************************************************************
* 版本：3.0.0.0
* 作者：dolby.jiang
* 完成日期：2010年5月6日
* 更改：增加PSA_SetSweepPoint
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.1
* 作者：dolby.jiang
* 完成日期：2011年5月10日
* 更改：
1 增加 PSA_SaveTraceByName
2 增加 PSA_SetTraceMathTypeByName
3 增加 PSA_DeleteTraceByName
4 增加 PSA_DeleteAllTrace
5 增加 PSA_SetMarkerSearchFreqByName
6 增加 PSA_GetMarkerValueByName
7 增加 PSA_GetFluctuateByName
8 增加 PSA_GetMarkerFreqByName
*
************************************************************************/

/************************************************************************
* 版本：3.0.0.7
* 作者：dolby.jiang
* 完成日期：2011年8月5日
* 更改：
1 增加 PSA_GetTraceDataXByName
2 增加 PSA_GetTraceDataYByName
*
************************************************************************/


/************************************************************************
* 版本：3.0.0.8
* 作者：dolby.jiang
* 完成日期：2011年9月9日
* 更改：
1 增加 Vsa 89600 Method
*
************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
	
	//打开并初始化设备
	PSADRIVER_API short int	_stdcall	PSA_OpenDev(char *ConnectStr, short int *Handle);

	//关闭设备
	PSADRIVER_API short int	_stdcall	PSA_CloseDev(short int Handle);

	//仪器复位	
	PSADRIVER_API short int	_stdcall	PSA_SetPreset(short int Handle);

	//设置中心频率
	PSADRIVER_API short int	_stdcall	PSA_SetCenterFrq(short int Handle, double CenterFreq);	
	
	//设置中心频率和SPAN	
	PSADRIVER_API short int	_stdcall	PSA_SetCenterFrqandSpan(short int Handle, double CenterFreq, double Span);
	
	//设置参考电平
	PSADRIVER_API short int	_stdcall	PSA_SetRefLevel(short int Handle, double RefLevel);	
	
	//设置内部衰减
	PSADRIVER_API short int	_stdcall	PSA_SetRFAttenuation(short int Handle, double Atten);	

	//设置为自动衰减模式	
	PSADRIVER_API short int	_stdcall	PSA_SetRFAttenAuto(short int Handle);	
	
	//设置内部衰减偏移量	
	PSADRIVER_API short int	_stdcall	PSA_SetRefLevelOff(short int Handle, double RefLevOffs);
	
	//设置外部衰减偏移量	
	PSADRIVER_API short int	_stdcall	PSA_SetExtAtten(short int Handle, double Atten);

	//设置预放状态(0:Off 1:On)
	PSADRIVER_API short int	_stdcall	PSA_SetIntPreampOff(short int Handle, unsigned short State);  

	//设置Y轴的显示电平范围	
	PSADRIVER_API short int	_stdcall	PSA_SetLevelRange(short int Handle, short LevelRange);

	//设置平均次数
	PSADRIVER_API short int	_stdcall	PSA_SetAverCount(short int Handle, unsigned short Count);

	//设置平均类型(0:RMS 1:SCALe 2:LOG)	
	PSADRIVER_API short int	_stdcall	PSA_SetAverType(short int Handle, unsigned short Type);

	//设置平均状态(0:Off 1:On)
	PSADRIVER_API short int	_stdcall	PSA_SetAverState(short int Handle, unsigned short State);

	//设置RBW值	
	PSADRIVER_API short int	_stdcall	PSA_SetRBW(short int Handle, double RBW);

	//设置VBW值	
	PSADRIVER_API short int	_stdcall	PSA_SetVBW(short int Handle, double VBW);

	//设置检波方式(0:normal 1:average 2:Peak 3:sample 4:negative Peak 5:Quasi peak 9:RMS)
	PSADRIVER_API short int	_stdcall	PSA_SetDetectorMode(short int Handle, unsigned short Mode);

	//设置扫描时间(ms)
	PSADRIVER_API short int	_stdcall	PSA_SetSweepTime(short int Handle, double SweepTime);

	//设置扫描时间为自动
	PSADRIVER_API short int	_stdcall	PSA_SetAUTOSweepTime(short int Handle, unsigned short State);

	//设置扫描模式(0:single 1:continous)
	PSADRIVER_API short int	_stdcall	PSA_SetSweepTimeMode(short int Handle, unsigned short Mode);

	//设置为Max Hold模式
	PSADRIVER_API short int	_stdcall	PSA_SetTraceMaxHold(short int Handle);

	//设置为Min Hold模式
	PSADRIVER_API short int	_stdcall	PSA_SetTraceMinHold(short int Handle);

	//设置为Clear Write模式
	PSADRIVER_API short int	_stdcall	PSA_SetTraceClearWrite(short int Handle);

	//读回整条曲线数据
	PSADRIVER_API short int	_stdcall	PSA_GetTraceData(short int Handle, double *TraceData, long *Count);

	//设置触发类型(0:IMM 1:EXT 2:RF Burst)
	PSADRIVER_API short int	_stdcall	PSA_SetTrigSource(short int Handle, unsigned short Mode);

	//设置最大MARKER点
	PSADRIVER_API short int	_stdcall	PSA_SetMarkMax(short int Handle, long MarkerIndex);

	//设置最小MARKER点
	PSADRIVER_API short int	_stdcall	PSA_SetMarkMin(short int Handle, long MarkerIndex);

	//设置下一个最大MARKER点
	PSADRIVER_API short int	_stdcall	PSA_SetMaxNext(short int Handle, long MarkerIndex);

	//设置MARKER点的状态
	PSADRIVER_API short int	_stdcall	PSA_SetMarkState(short int Handle, long MarkerIndex, unsigned short State);

	//设置MARKER点的频率值
	PSADRIVER_API short int	_stdcall	PSA_SetMarkPosition(short int Handle, long MarkerIndex, double Freq);

	//设置MARKER点的类型(0:NORMal 1:DELTa )
	PSADRIVER_API short int	_stdcall	PSA_SetMarkerMode(short int Handle, long MarkerIndex, unsigned short Mode);

	//获取MARKER点值
	PSADRIVER_API short int	_stdcall	PSA_GetMarkValue(short int Handle, long MarkerIndex, double *Value);	

	//设置为TD功率测量模式
//	PSADRIVER_API short int	_stdcall	PSA_SetTDPWRMODE(short int Handle);	

	//设置TD功率模式下的时隙
	PSADRIVER_API short int	_stdcall	PSA_SetTDPOWSLOT(short int Handle, short Slot);	

	//设置为解调模式
//	PSADRIVER_API short int	_stdcall	PSA_SetTDMODMODE(short int Handle);

	//获取解调模式下的EVM和PCDE值
	PSADRIVER_API short int	_stdcall	PSA_GetEVMandPCDE(short int Handle, double *EVM, double *PCDE);

	//设置频谱测量模式
	PSADRIVER_API short int	_stdcall	PSA_SetSPECMODE(short int Handle);

	//设置起止频率
	PSADRIVER_API short int	_stdcall	PSA_SetStarandStopFreq(short int Handle, double StartFreq, double StopFreq);	

	//设置为多载波测量模式
	PSADRIVER_API short int	_stdcall	PSA_SetMULACPRMeas(short int Handle);	

	//设置多载波模式下的载波数
	PSADRIVER_API short int	_stdcall	PSA_SetMCCOUNT(short int Handle, unsigned short Count);

	//获取多载波模式下的测量值
	PSADRIVER_API short int	_stdcall	PSA_GetMULACPR(short int Handle, double *Value, long *Count);

	//设置多载波模式下的平均次数和平均状态
	PSADRIVER_API short int	_stdcall	PSA_SetMCPAVER(short int Handle, unsigned short State, long Count);

	//设置为频谱发射模板测量模式
	PSADRIVER_API short int	_stdcall	PSA_SetSEMMeas(short int Handle);

	//触发频谱发射模板模式
	PSADRIVER_API short int	_stdcall	PSA_SetInitSEM(short int Handle);
	
	//设置频谱发射模板模式下的平均状态
	PSADRIVER_API short int	_stdcall	PSA_SetSEMAverageEnable(short int Handle, unsigned short State);   

	//设置频谱发射模板模式下的模板类型
	PSADRIVER_API short int	_stdcall	PSA_SetSEMLimits(short int Handle, unsigned short Limit); 

	//获取频谱发射模板模式下的测量值(0:PASS 1:FAIL)
	PSADRIVER_API short int	_stdcall	PSA_GetSEM(short int Handle, int *State);

	//设置为EVM和PCDE测量模式
	PSADRIVER_API short int	_stdcall	PSA_SetEVMMeas(short int Handle);	

	//设置EVM和PCDE测量模式下的测量时隙
	PSADRIVER_API short int	_stdcall	PSA_SetEVMSlot(short int Handle, unsigned short Slot);

	//初始化EVM和PCDE测量模式
	PSADRIVER_API short int	_stdcall	PSA_SetInitEVM(short int Handle); 

	//设置同步触发类型
	PSADRIVER_API short int	_stdcall	PSA_SetSyncType(short int Handle, unsigned short Type, unsigned short Timingref);

	//打开三阶互调截取点
	PSADRIVER_API short int	_stdcall	PSA_SetTOI(short int Handle);
	
	//获取为三阶互调模式下的测量值
	PSADRIVER_API short int	_stdcall	PSA_GetTOI(short int Handle, double *Value, long *Count); 

	//设置为三阶互调模式下的平均状态(0:Off 1:On)
	PSADRIVER_API short int	_stdcall	PSA_SetTOIAVGState(short int Handle, unsigned short State);

	//设置频谱仪为时间开关模板测量
	PSADRIVER_API short int	_stdcall	PSA_SetPVTMeas(short int Handle);

	//触发一次时间开关模板测量
	PSADRIVER_API short int	_stdcall	PSA_SetInitPVT(short int Handle);

	//获取时间开关模板测量模式下的测量值
	PSADRIVER_API short int	_stdcall	PSA_GetPVT(short int Handle, double *Value, long *Count);

	//设置时间开关模板模式下的平均次数
	PSADRIVER_API short int	_stdcall	PSA_SetPVTAverageEnable(short int Handle, unsigned short State);  

	//设置时间开关模板测试模式下的测量时隙总数
	PSADRIVER_API short int	_stdcall	PSA_SetPVTMEASTimes(short int Handle, long Times);

	//设置为单载波测试模式
	PSADRIVER_API short int	_stdcall	PSA_SetACPMeas(short int Handle);

	//获得单载波模式下的测量值
	PSADRIVER_API short int	_stdcall	PSA_GetACP(short int Handle, double *Value, long *Count);

	//设置显示窗口
	PSADRIVER_API short int _stdcall    PSA_SetWindow(short int Handle, unsigned short Window);

	//设置触发延迟时间(单位:s)
	PSADRIVER_API short int _stdcall    PSA_SetTrigDelayTime(short int Handle,double TrigDelayTime);

	//设置外部门信号的极性(0:POSitive 1:NEGative)
	PSADRIVER_API short int _stdcall	PSA_SetSweepEgatePolarity(short int Handle, unsigned short Polarity);

	//设置踪迹为平均估值方式
	PSADRIVER_API short int _stdcall	PSA_SetTraceAverage(short int Handle);

	//获取扫描时间值
	PSADRIVER_API short int _stdcall	PSA_GetSweepTime(short int Handle, double *SweepTime);

	//获取触发延迟时间
	PSADRIVER_API short int _stdcall	PSA_GetTrigDelayTime(short int Handle, double *TrigDelayTime);

	//获得频谱发射模板模式下的功率测量结果
	PSADRIVER_API short int _stdcall	PSA_GetSEMPower(short int Handle, double *ChPower);

	//获得EVM和PCDE模式下的功率测量结果
	PSADRIVER_API short int _stdcall	PSA_GetEVMPower(short int Handle, double *ChPower);

	//设置EVM和PCDE模式下的平均次数和状态
	PSADRIVER_API short int _stdcall	PSA_SetEVMAver(short int Handle, unsigned short Count, unsigned short State);

	//设置频谱耦合方式 R&S 0:NORMal	1:FFT 2:CFILter 3:RRC 4:NOISe 5:PULSe 6:P5
	PSADRIVER_API short int _stdcall	PSA_SetFilterType(short int Handle, unsigned short Type);

	//设置EVM和PCDE模式下的扰码
	PSADRIVER_API short int _stdcall	PSA_SetScrambleCode(short int Handle, short ScrambleCode);

	//获取指定带宽范围内的波动
	PSADRIVER_API short int _stdcall    PSA_GetFluctuate(short int Handle, double BandWidth, double *Fluctuate);
	
	//在时域模式下设置Marker的位置(单位:ms)
	PSADRIVER_API short int _stdcall    PSA_SetMarkTime(short int Handle,long MarkerIndex, double Time);

	//设置门扫描有效时间(单位:ms)
	PSADRIVER_API short int _stdcall    PSA_SetSweepEgateLength(short int Handle, double GateLength);

	//设置外部触发电平(-5V ~ 5V)
	PSADRIVER_API short int _stdcall	PSA_SetTrigLevel(short int Handle, double TrigLevel);
	
	//设置ACP模式下起止时隙
	PSADRIVER_API short int _stdcall	PSA_SetStartAndStopSlot(short int Handle, short StartSlot, short StopSlot);

	//设置频谱仪的测试模式(0:SA 1:TDSCDMA_ACP 2:TDSCDMA_MCP 3:TDSCDMA_SEM 
	//4:TDSCDMA_EVM 5:SA_Harmonic 6:SA_CCDF 7:SA_ACP)
	PSADRIVER_API short int _stdcall	PSA_SetMeasMode(short int Handle, int MeasureMode);

	//获取SA_CCDF模式下的测量值
	PSADRIVER_API short int _stdcall	PSA_GetPST(short int Handle, double *Values);

	//获取SA_Harmonic模式下的测量值(dBm)(HarmonicNum:(0~10)  0:所有谐波值)
	PSADRIVER_API short int _stdcall	PSA_GetHarmonic(short int Handle, int HarmonicNum, double *Values);

	//获取设备型号信息
	PSADRIVER_API short int _stdcall	PSA_GetIDN(short int Handle, char *IDN);

	//加载状态文件
	PSADRIVER_API short int _stdcall	PSA_LoadFile(short int Handle, char *FileName);	
	
	//保存状态文件
	PSADRIVER_API short int _stdcall	PSA_SaveFile(short int Handle, char *FileName, int FileType);
	
	//设置载波间隔
	PSADRIVER_API short int _stdcall	PSA_SetCarrierSpaceList(short int Handle, double *SpaceList, int Count);
	
	//设置噪声修正状态(0: Off 1:On)
	PSADRIVER_API short int _stdcall	PSA_SetNoiseCorrState(short int Handle, int State);
	
	//设置Offset Freqence列表(MHz)
	PSADRIVER_API short int _stdcall	PSA_SetOffsetFreqList(short int Handle, double *FreqList, int Count);
	
	//设置Offset Freqence列表状态(0:Off 1:On)
	PSADRIVER_API short int _stdcall	PSA_SetOffsetFreqState(short int Handle, int *StateList, int Count);
	
	//设置Offset Integ BW列表(MHz)
	PSADRIVER_API short int _stdcall	PSA_SetOffsetIBWList(short int Handle, double *IBWList, int Count);
	
	//设置Gate View状态(0:Off 1:On)
	PSADRIVER_API short int _stdcall	PSA_SetGateViewState(short int Handle, int State);
	
	//设置扫描Gate Delay(ms)
	PSADRIVER_API short int _stdcall	PSA_SetSweepEgatDelay(short int Handle, double Time);
	
	//设置Measurement Noise Bandwidth(MHz)
	PSADRIVER_API short int _stdcall	PSA_SetMeasNoiseBW(short int Handle, double *MNBWList, int Count);
	
	//设置参考载波
	PSADRIVER_API short int _stdcall	PSA_SetRefCarrier(short int Handle, int CarrierNo);
	
	//设置参考载波频率(MHz)
	PSADRIVER_API short int _stdcall	PSA_SetRefCarrierFreq(short int Handle, double Freq);
	
	//发送指令
	PSADRIVER_API short int _stdcall	PSA_SendCmd(short int Handle, char *Command);
	
	//获取返回指令值
	PSADRIVER_API short int _stdcall	PSA_GetCmd(short int Handle, char *Command, char *RetStr);

	// 设置扫描点数
	PSADRIVER_API short int _stdcall	PSA_SetSweepPoint(short int Handle, int Points);
		
	// 以命名方式将测试曲线数据保存到PC内存中
	PSADRIVER_API	short int _stdcall	PSA_SaveTraceByName(short int Handle, unsigned short ch, int traceindex, char *Name) ;
	
	// 以命名方式处理PC内存数据(0:Off 1:Trace1/Trace2 2:Trace1*Trace2 3:Trace1-Trace2 4:Trace1+Trace2)
	PSADRIVER_API	short int _stdcall	PSA_SetTraceMathTypeByName(short int Handle, char *Trace1, char *Trace2, short type, char *NewName);
	
	// 删除一条PC内存曲线
	PSADRIVER_API	short int _stdcall	PSA_DeleteTraceByName(short int Handle, char *Name) ;
	
	// 删除所有PC内存曲线
	PSADRIVER_API	short int _stdcall	PSA_DeleteAllTrace(short int Handle);
	
	// 在PC内存数据中设置MARKER 的查找范围(MHz) 
	PSADRIVER_API	short int _stdcall	PSA_SetMarkerSearchFreqByName(short int Handle, char *Name, double Start, double Stop);
	
	// 从PC内存数据中获取最大值和最小值
	PSADRIVER_API	short int _stdcall	PSA_GetMarkerValueByName(short int Handle, char *Name, double *Max, double *Min);
	
	// 从PC内存数据中获取指定带宽范围内的平坦度(MHz) 
	PSADRIVER_API	short int _stdcall	PSA_GetFluctuateByName(short int Handle, char *Name, double BandWidth, double *Fluctuate);
	
	// 从PC内存数据获取指定频率点Marker值
	PSADRIVER_API	short int _stdcall	PSA_GetMarkerFreqByName(short int Handle, char *Name, unsigned short Marker, double Freq, double *Value);
	
	// 设置触发极性(0:Positive 1:Negative)
	PSADRIVER_API	short int _stdcall	PSA_SetTrigPolarity(short int Handle, int Polarity);

	// 从PC内存数据获取X轴数据
	PSADRIVER_API	short int _stdcall	PSA_GetTraceDataXByName(short int Handle, char *Name, double *TraceDataX, long *Count);
	
	// 从PC内存数据获取Y轴数据
	PSADRIVER_API	short int _stdcall	PSA_GetTraceDataYByName(short int Handle, char *Name, double *TraceDataY, long *Count);
	
	// 读取设备的测试数据
	PSADRIVER_API	short int _stdcall	PSA_ReadDev(short int Handle, int ResultPara, char *RetStr, int ReadCount, int *RealCount);
	
	// 触发一次测量
	PSADRIVER_API	short int _stdcall	PSA_SetTrigOnce(short int Handle);
	
	// 重新测量一次
	PSADRIVER_API	short int _stdcall	PSA_Restart(short int Handle);

	//设置 Offs List Abs (dBm)
	PSADRIVER_API   short int _stdcall  PSA_SetOffsetAbsList(short int Handle, double *OffsAbsList, int Count);

	// 设置sweep egat 状态
	PSADRIVER_API   short int _stdcall  PSA_SetEgatState(short int Handle, int State);	
	
	//获取OBW
	PSADRIVER_API short int	_stdcall	PSA_GetOBW(short int Handle, double *OBWValue);
	
	//设置Marker Function
	PSADRIVER_API short int	_stdcall	PSA_SetMarkFunction(short int Handle,long MarkerIndex, unsigned short state);
	//获取marker点频率
/*	PSADRIVER_API short int	_stdcall	PSA_GetMarkFreq(short int Handle, long MarkerIndex, double *Freq);*/
	//设置触发Slope
	PSADRIVER_API short int	_stdcall	PSA_SetTrigSlope(short int Handle,unsigned short mode);	
	//设置Span
	PSADRIVER_API short int	_stdcall	PSA_SetSpan(short int Handle,double span);	

	//设置自动电平
	PSADRIVER_API short int	_stdcall	PSA_RefLevelAuto(short int Handle);	
	
	//设置ACLR模式
	PSADRIVER_API short int	_stdcall	PSA_SetACLRMEAS(short int Handle);
	
	//设置ACLR模式TX带宽
	PSADRIVER_API short int	_stdcall	PSA_SetACPTXBW(short int Handle, short int channel, double freq);

	//设置ACLR模式TXCount
	PSADRIVER_API short int	_stdcall	PSA_SetACPTXCount(short int Handle, short int count);

	//设置TrigSource
	PSADRIVER_API short int	_stdcall	PSA_SetTriggerSource(short int Handle, short int source);

	//设置TrigLevel
	PSADRIVER_API short int	_stdcall	PSA_SetTriggerLevel(short int Handle, short int source, double level);

	//设置GateTrigSwitch
	PSADRIVER_API short int	_stdcall	PSA_SetGateTrigSwitch(short int Handle, short int Switch);

	//设置GateDelay
	PSADRIVER_API short int	_stdcall	PSA_SetGateDelay(short int Handle, double delay);

	//设置GateLength
	PSADRIVER_API short int	_stdcall	PSA_SetGateLength(short int Handle, double length);

	//获取ACLR值
	PSADRIVER_API short int	_stdcall	PSA_GetACLR(short int Handle, char *Value);

	//设置VSA模式
	PSADRIVER_API short int	_stdcall	PSA_SetVSAMODE(short int Handle);

	//设置PULSE模式
	PSADRIVER_API short int	_stdcall	PSA_SetPULSEMODE(short int Handle);
		
	//设置OBWPowerBandWidth
	PSADRIVER_API short int	_stdcall	PSA_SetOBWPOWERBW(short int Handle, double power);

	//获取EVMValue
	PSADRIVER_API short int	_stdcall	PSA_GetEVMValue(short int Handle, double *RetStr);

	//获取PULSEValue
	PSADRIVER_API short int	_stdcall	PSA_GetPULSEValue(short int Handle, char *RetStr1, char *RetStr2);

	//设置SignCountFunction
	PSADRIVER_API short int	_stdcall	PSA_SetSignCountFunc(short int Handle);

	//获得Mark点频率
	PSADRIVER_API short int	_stdcall	PSA_GetMarkFreq(short int Handle, long MarkerIndex, double *Freq);

	//设置TriggerOffSet
	PSADRIVER_API short int	_stdcall	PSA_SetTriggerOffSet(short int Handle, double offset);

	//设置Timing参数显示
	PSADRIVER_API short int	_stdcall	PSA_SetTimingPara(short int Handle, short int offtime, short int dutycycle);

	//设置Transmit Filter
	PSADRIVER_API short int	_stdcall	PSA_SetTransFilter(short int Handle, short int type, double alpha);

	//设置ModulationSetting
	PSADRIVER_API short int	_stdcall	PSA_SetModulation(short int Handle, short int type, short int order, short int map, double rate);

	//设置CaptureLengthAuto
	PSADRIVER_API short int	_stdcall	PSA_SetCaptureLengthAuto(short int Handle, short int Switch);

	//获取PulseNumber
	PSADRIVER_API short int	_stdcall	PSA_GetPULSENumber(short int Handle, int *RetStr);

#ifdef __cplusplus
}
#endif























