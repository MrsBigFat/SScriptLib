

/************************************************************************
* 版本：2.1.0.2
* 作者：dolby.jiang
* 完成日期：2009年10月19日
* 更改：修改Create_PRM_SetMeasUnit
*
************************************************************************/


/************************************************************************
* 版本：2.1.0.6
* 作者：dolby.jiang
* 完成日期：2009年12月24日
* 更改：增加IRU 驱动库接口类
*
************************************************************************/

/************************************************************************
* 版本：2.1.0.7
* 作者：dolby.jiang
* 完成日期：2009年12月24日
* 更改：1) 增加 Create_NTS_SetStarAndStopFlash
		2) 增加 Create_NTS_GetStarAndStopFlash
		3) 增加 Create_NTS_SetStarAndStopEEPROM
		4) 增加 Create_NTS_GetStarAndStopEEPROM		
*
************************************************************************/

/************************************************************************
* 版本：2.1.0.7
* 作者：dolby.jiang
* 完成日期：2010年1月25日
* 更改：1) 增加 Create_AD_SetCRC		
*
************************************************************************/

/************************************************************************
* 版本：2.1.0.8
* 作者：dolby.jiang
* 完成日期：2010年2月24日
* 更改：1) 增加 Create_SPE_PolyFit		
*
************************************************************************/

/************************************************************************
* 版本：2.1.0.8
* 作者：dolby.jiang
* 完成日期：2010年2月26日
* 更改：1) 增加 Create_NTS_SetPID 设置电流调试参数		
		2) 增加 Create_NTS_SetGainWorkPara 设置功放的静态工作参数
		3) 增加 Create_NTS_GainDebug 在电流表下调试单级功放的静态工作电流
*
************************************************************************/

/************************************************************************
* 版本：2.1.0.9
* 作者：dolby.jiang
* 完成日期：2010年3月19日
* 更改：1 增加 Create_ENA_GetTraceDataX
		2 增加 Create_SPE_GetIDN
*
************************************************************************/

/************************************************************************
* 版本：3.0.0.0
* 作者：dolby.jiang
* 完成日期：2010年4月16日
* 更改：1 增加 Create_PSA_GetSEMPower
		2 增加 Create_PSA_GetEVMPower
		3 增加 Create_PSA_SaveFile
		4 增加 Create_DPD_SetRFOutPower
		5 增加 Create_DPD_GetRFOutPower
		6 增加 Create_DPD_SetCFR
		7 增加 Create_DPD_GetCFR
		8 增加 Create_DPD_GetRDAtten
		9 增加 Create_DPD_GetTxAtten
*
************************************************************************/

/************************************************************************
* 版本：3.0.0.3
* 作者：dolby.jiang
* 完成日期：2010年5月6日
* 更改：1 增加 Create_PSA_SetSweepPoint

*
************************************************************************/


/************************************************************************
* 版本：3.0.0.4
* 作者：dolby.jiang
* 完成日期：2010年5月12日
* 更改：
	1 增加 Create_NFA_GetTraceMax接口
	2 增加 Create_NFA_GetTraceMin接口
	3 增加 Create_NFA_GetTraceFreqValue接口
*
************************************************************************/

/************************************************************************
* 版本：3.0.0.8
* 作者：dolby.jiang
* 完成日期：2010年7月12日
* 更改：
	1 增加 Create_GetPowerState 接口	
*
************************************************************************/

/************************************************************************
* 版本：3.0.0.9
* 作者：dolby.jiang
* 完成日期：2010年7月20日
* 更改：
	1 增加 M_NTS_SetStartAndStopRAM 接口	
*
************************************************************************/

/************************************************************************
* 版本：3.0.2.1
* 作者：dolby.jiang
* 完成日期：2010年10月15日
* 更改：
	1 增加 M_SPE_WriteDev 接口
	2 增加 M_SPE_ReadDev 接口
	3 增加 M_SPE_QueryDev 接口
*
************************************************************************/
/************************************************************************
* 版本：3.0.2.2
* 作者：dolby.jiang
* 完成日期：2010年10月20日
* 更改：
	1) 增加 M_SPE_SetCom 设置串口通讯参数
	2) 增加 M_SPE_SetDTR 设置RTS(数据终端就绪)标志  硬件流控制 0:Low 1:Hight
	3) 增加 M_SPE_SetRTS 设置RTS(设置请求数据发送)标志  硬件流控制 0:Low 1:Hight
	4) 增加 M_SPE_SetXOFF 设置XOFF(设置流数据停止发送)标志 软件流控制
	5) 增加 M_SPE_SetXON 设置XON(设置流数据继续发送)标志 软件流控制
*
************************************************************************/

/************************************************************************
* 版本：3.0.2.5
* 作者：dolby.jiang
* 完成日期：2010年12月29日
* 更改：1) 增加 M_NTS_GetVoltage 获取通道的电压(单位:bit)
		2) 增加 M_NTS_SetActiveObject 设置当前需要的监控的对象
*
************************************************************************/

/************************************************************************
* 版本：3.0.2.8
* 作者：dolby.jiang
* 完成日期：2011年4月13日
* 更改：1) 增加 M_NTS_SetFourGAOutputVol 设置第四级功放的输出电压
		2) 增加 M_NTS_GetFourGAOutputVol 获取第四级功放的输出电压
*
************************************************************************/

/************************************************************************
* 版本：3.0.2.8
* 作者：dolby.jiang
* 完成日期：2011年4月13日
* 更改： 增加 Create_SG_SetRFAmplituOffset 
*
************************************************************************/
/************************************************************************/
/* 波形发生器驱动方法创建方法                                               */
/************************************************************************/
//波形发生器设备复位
BaseMethod * Create_DWG_Reset()
{
	return new M_DWG_Reset;
}

// 发送指令
BaseMethod * Create_DWG_SendCmd()
{
	return new M_DWG_SendCmd;
}

// 获取返回指令值
BaseMethod * Create_DWG_GetCmd()
{
	return new M_DWG_GetCmd;
}

// 获取设备型号信息
BaseMethod * Create_DWG_GetIDN()
{
	return new M_DWG_GetIDN;
}

// 加载状态文件
BaseMethod * Create_DWG_LoadFile()
{
	return new M_DWG_LoadFile;
}

// 设置通道开关
BaseMethod * Create_DWG_SetCHSwitch()
{
	return new M_DWG_SetCHSwitch;
}

// 设置总开关
BaseMethod * Create_DWG_SetAllSwitch()
{
	return new M_DWG_SetAllSwitch;
}

// 设置电平
BaseMethod * Create_DWG_SetAmpLevel()
{
	return new M_DWG_SetAmpLevel;
}

/************************************************************************/
/* 示波器驱动方法创建方法                                               */
/************************************************************************/
//示波器设备复位
BaseMethod * Create_OSC_Reset()
{
	return new M_OSC_Reset;
}

//设置DTimeLevel
BaseMethod * Create_OSC_SetDTLEVParam()
{
	return new M_OSC_SetDTLEVParam;
}

//设置Grid
BaseMethod * Create_OSC_SetGrid()
{
	return new M_OSC_SetGrid;
}

//设置Trig类型
BaseMethod * Create_OSC_SetTrigType()
{
	return new M_OSC_SetTrigType;
}

//设置TrigCoupling
BaseMethod * Create_OSC_SetTrigCoupling()
{
	return new M_OSC_SetTrigCoupling;
}

//设置TrigSlope
BaseMethod * Create_OSC_SetTrigSlope()
{
	return new M_OSC_SetTrigSlope;
}

//设置TrigLevel
BaseMethod * Create_OSC_SetTrigLevel()
{
	return new M_OSC_SetTrigLevel;
}

//设置Vertical Scale
BaseMethod * Create_OSC_SetScaleVDIV()
{
	return new M_OSC_SetScaleVDIV;
}

//设置Timebase Scale
BaseMethod * Create_OSC_SetScaleTDIV()
{
	return new M_OSC_SetScaleTDIV;
}

//获取DTL值
BaseMethod * Create_OSC_GetMeaValue()
{
	return new M_OSC_GetMeaValue;
}

//设置TrigMode
BaseMethod * Create_OSC_SetTrigMode()
{
	return new M_OSC_SetTrigMode;
}

// 发送指令
BaseMethod * Create_OSC_SendCmd()
{
	return new M_OSC_SendCmd;
}

//获取返回指令值
BaseMethod * Create_OSC_GetCmd()
{
	return new M_OSC_GetCmd;
}

//设置DeltaDelay模式参数
BaseMethod * Create_OSC_SetDeltaDelay()
{
	return new M_OSC_SetDeltaDelay;
}

//OSC_SetTraceDis
BaseMethod * Create_OSC_SetTraceDis()
{
	return new M_OSC_SetTraceDis;
}
/************************************************************************/
/* 信号源驱动方法创建方法                                               */
/************************************************************************/
//信号源设备复位
BaseMethod * Create_SG_Reset()
{
	return new M_SG_Reset;
}

// 设置信号源波形文件
BaseMethod * Create_SG_SetWaveFile()
{
	return new M_SG_SetWaveFile;
}

// 设置波形文件状态
BaseMethod * Create_SG_SetArbWaveState()
{
	return new M_SG_SetArbWaveState;
}

// 设置参考频率值
BaseMethod * Create_SG_SetRFFreq()
{
	return new M_SG_SetRFFreq;
}

// 设置信号源幅度值
BaseMethod * Create_SG_SetRFAmplitu()
{
	return new M_SG_SetRFAmplitu;
}

// 读取信号源幅度值
BaseMethod * Create_SG_GetRFAmplitu()
{
	return new M_SG_GetRFAmplitu;
}

// 设置信号源幅度偏移值
BaseMethod * Create_SG_SetRFAmplituOffset()
{
	return new M_SG_SetRFAmplituOffset;
}

// 设置信号源解调状态
BaseMethod * Create_SG_SetIQModulationState()
{
	return new M_SG_SetIQModulationState;
}

// 设置信号源输出状态
BaseMethod * Create_SG_SetRFPowerOnState()
{
	return new M_SG_SetRFPowerOnState;
}

// 设置信号源扫描点数
BaseMethod * Create_SG_SetSweepPoint()
{
	return new M_SG_SetSweepPoint;
}

// 设置信号源扫描触发方式
BaseMethod * Create_SG_SetSweepTriMode()
{
	return new M_SG_SetSweepTriMode;
}

// 设置信号源扫描起始频率和截止频率
BaseMethod * Create_SG_SetStartandStopFreq()
{
	return new M_SG_SetStartandStopFreq;
}

// 设置扫描模式
BaseMethod * Create_SG_SetSweepMode()
{
	return new M_SG_SetSweepMode;
}

// 设置信号源Mark模式
BaseMethod * Create_SG_SetARBMarkMode()
{
	return new M_SG_SetARBMarkMode;
}

// 设置信号源频率偏移量
BaseMethod * Create_SG_SetFreqOffset()
{
	return new M_SG_SetFreqOffset;
}

// 设置信号源Mark延迟时间
BaseMethod * Create_SG_SetARBMarkDelay()
{
	return new M_SG_SetARBMarkDelay;
}

// 设置信号源连续触发类型 0:FREE 1:TRIGger 2:RESet
BaseMethod * Create_SG_SetTrigInContinuousType()
{
	return new M_SG_SetTrigInContinuousType;
}

// 设置信号源触发源类型 0:KEY 1:EXT 2:BUS
BaseMethod * Create_SG_SetTrigInSourceType()
{
	return new M_SG_SetTrigInSourceType;
}

//  设置信号源触发极性 0:POSitive 1:NEGative
BaseMethod * Create_SG_SetTrigInPolarity()
{
	return new M_SG_SetTrigInPolarity;
}

//  设置信号源触发延迟时间(单位:ms)
BaseMethod * Create_SG_SetTrigInDelay()
{
	return new M_SG_SetTrigInDelay;
}

//  设置信号源Marker ALC Hold值 0:NONE 1:M1 2:M2 3:M3 4:M4
BaseMethod * Create_SG_SetMarkerALCHold()
{
	return new M_SG_SetMarkerALCHold;
}

// 设置信号源电平 ALC状态 0:Off 1:On 
BaseMethod * Create_SG_SetAmpALCMode()
{
	return new M_SG_SetAmpALCMode;
}

// 设置时钟频率(单位:MHz)
BaseMethod * Create_SG_SetClockFreq()
{
	return new M_SG_SetClockFreq;
}

// 设置功率检测方式(0:Normal 1:Minimum)
BaseMethod * Create_SG_SetRFPowerSearchMode()
{
	return new M_SG_SetRFPowerSearchMode;
}

// 发送指令
BaseMethod * Create_SG_SendCmd()
{
	return new M_SG_SendCmd;
}

//获取返回指令值
BaseMethod * Create_SG_GetCmd()
{
	return new M_SG_GetCmd;
}

//获取设备型号信息
BaseMethod * Create_SG_GetIDN()
{
	return new M_SG_GetIDN;
}

//获取设备型号信息
BaseMethod * Create_SG_SetCwCarrier()
{
	return new M_SG_SetCwCarrier;
}


/************************************************************************/
/* 频谱仪驱动方法创建方法                                               */
/************************************************************************/
// 频谱仪复位
BaseMethod * Create_PSA_SetPreset()
{
	return new M_PSA_SetPreset;
}

// 设置频谱仪中心频率
BaseMethod * Create_PSA_SetCenterFrq()
{
	return new M_PSA_SetCenterFrq;
}

// 设置频谱仪中心频率和span
BaseMethod * Create_PSA_SetCenterFrqandSpan()
{
	return new M_PSA_SetCenterFrqandSpan;
}

// 设置频谱仪参考电平
BaseMethod * Create_PSA_SetRefLevel()
{
	return new M_PSA_SetRefLevel;
}

// 设置频谱仪内部衰减值
BaseMethod * Create_PSA_SetRFAttenuation()
{
	return new M_PSA_SetRFAttenuation;
}

// 设置频谱仪自动内部衰减值
BaseMethod * Create_PSA_SetRFAttenAuto()
{
	return new M_PSA_SetRFAttenAuto;
}

// 设置频谱仪内部衰减偏移量
BaseMethod * Create_PSA_SetRefLevelOff()
{
	return new M_PSA_SetRefLevelOff;
}

// 设置频谱仪外部衰减偏移量
BaseMethod * Create_PSA_SetExtAtten()
{
	return new M_PSA_SetExtAtten;
}

// 设置频谱仪预放状态
BaseMethod * Create_PSA_SetIntPreampOff()
{
	return new M_PSA_SetIntPreampOff;
}

// 设置频谱仪Y轴显示电平范围
BaseMethod * Create_PSA_SetLevelRange()
{
	return new M_PSA_SetLevelRange;
}

// 设置频谱仪平均次数
BaseMethod * Create_PSA_SetAverCount()
{
	return new M_PSA_SetAverCount;
}

// 设置频谱仪平均类型
BaseMethod * Create_PSA_SetAverType()
{
	return new M_PSA_SetAverType;
}

// 设置频谱仪平均状态
BaseMethod * Create_PSA_SetAverState()
{
	return new M_PSA_SetAverState;
}

// 设置频谱仪RBW值
BaseMethod * Create_PSA_SetRBW()
{
	return new M_PSA_SetRBW;
}

// 设置频谱仪VBW值
BaseMethod * Create_PSA_SetVBW()
{
	return new M_PSA_SetVBW;
}

// 设置频谱仪检波模式
BaseMethod * Create_PSA_SetDetectorMode()
{
	return new M_PSA_SetDetectorMode;
}

// 设置频谱仪扫描时间
BaseMethod * Create_PSA_SetSweepTime()
{
	return new M_PSA_SetSweepTime;
}

// 设置频谱仪自动扫描状态
BaseMethod * Create_PSA_SetAUTOSweepTime()
{
	return new M_PSA_SetAUTOSweepTime;
}

// 设置频谱仪扫描模式
BaseMethod * Create_PSA_SetSweepTimeMode()
{
	return new M_PSA_SetSweepTimeMode;
}

// 设置频谱仪为MAX HOLD模式
BaseMethod * Create_PSA_SetTraceMaxHold()
{
	return new M_PSA_SetTraceMaxHold;
}

// 设置频谱仪为MIN HOLD模式
BaseMethod * Create_PSA_SetTraceMinHold()
{
	return new M_PSA_SetTraceMinHold;
}

//设置频谱仪为Cleat write模式
BaseMethod * Create_PSA_SetTraceClearWrite()
{
	return new M_PSA_SetTraceClearWrite;
}

// 读会整条曲线数据
BaseMethod * Create_PSA_GetTraceData()
{
	return new M_PSA_GetTraceData;
}

// 设置频谱仪触发源
BaseMethod * Create_PSA_SetTrigSource()
{
	return new M_PSA_SetTrigSource;
}

// 设置频谱仪最大MARKER点
BaseMethod * Create_PSA_SetMarkMax()
{
	return new M_PSA_SetMarkMax;
}

// 设置频谱仪最小MARKER点
BaseMethod * Create_PSA_SetMarkMin()
{
	return new M_PSA_SetMarkMin;
}

// 设置频谱仪下一最大MARKER点
BaseMethod * Create_PSA_SetMaxNext()
{
	return new M_PSA_SetMaxNext;
}

// 设置频谱仪MARKER点的状态
BaseMethod * Create_PSA_SetMarkState()
{
	return new M_PSA_SetMarkState;
}

// 设置频谱仪MARKER点的频率
BaseMethod * Create_PSA_SetMarkPosition()
{
	return new M_PSA_SetMarkPosition;
}

// 设置频谱仪MARKER点的模式
BaseMethod * Create_PSA_SetMarkerMode()
{
	return new M_PSA_SetMarkerMode;
}

//获取频谱仪MARKER点的值
BaseMethod * Create_PSA_GetMarkValue()
{
	return new M_PSA_GetMarkValue;
}

// 设置频谱仪TD功率模式下的测试时隙
BaseMethod * Create_PSA_SetTDPOWSLOT()
{
	return new M_PSA_SetTDPOWSLOT;
}

// 获取频谱仪TD解调模式下的时隙功率值
BaseMethod * Create_PSA_GetEVMandPCDE()
{
	return new M_PSA_GetEVMandPCDE;
}

// 设置频谱仪为频谱模式
BaseMethod * Create_PSA_SetSPECMODE()
{
	return new M_PSA_SetSPECMODE;
}

// 设置频谱仪起止频率
BaseMethod * Create_PSA_SetStarandStopFreq()
{
	return new M_PSA_SetStarandStopFreq;
}

// 设置频谱仪为多载波测试模式
BaseMethod * Create_PSA_SetMULACPRMeas()
{
	return new M_PSA_SetMULACPRMeas;
}

// 设置频谱仪载波数
BaseMethod * Create_PSA_SetMCCOUNT()
{
	return new M_PSA_SetMCCOUNT;
}

// 获取频谱仪在多载波模式下的所有测量值
BaseMethod * Create_PSA_GetMULACPR()
{
	return new M_PSA_GetMULACPR;
}

// 设置频谱仪在多载波模式下的平均次数
BaseMethod * Create_PSA_SetMCPAVER()
{
	return new M_PSA_SetMCPAVER;
}

// 设置频谱仪为频谱发射模板测试模式
BaseMethod * Create_PSA_SetSEMMeas()
{
	return new M_PSA_SetSEMMeas;
}

// 初始化频频仪频谱发射模板测试
BaseMethod * Create_PSA_SetInitSEM()
{
	return new M_PSA_SetInitSEM;
}

// 设置频谱仪频谱发射模板模式下平均状态
BaseMethod * Create_PSA_SetSEMAverageEnable()
{
	return new M_PSA_SetSEMAverageEnable;
}

// 设置频谱仪频谱发射模板类型
BaseMethod * Create_PSA_SetSEMLimits()
{
	return new M_PSA_SetSEMLimits;
}

// 获得频谱仪频谱发射模板测量模式下的测量值
BaseMethod * Create_PSA_GetSEM()
{
	return new M_PSA_GetSEM;
}

// 设置频谱仪为EVM和PCDE测量模式
BaseMethod * Create_PSA_SetEVMMeas()
{
	return new M_PSA_SetEVMMeas;
}

// 设置频谱仪EVM和PCDE模式下的时隙值
BaseMethod * Create_PSA_SetEVMSlot()
{
	return new M_PSA_SetEVMSlot;
}

// 初始化频谱仪EVM和PCDE测量模式
BaseMethod * Create_PSA_SetInitEVM()
{
	return new M_PSA_SetInitEVM;
}

// 设置频谱仪EVM和PCDE模式下的同步类型
BaseMethod * Create_PSA_SetSyncType()
{
	return new M_PSA_SetSyncType;
}

// 设置频谱仪为三阶交调测试模式
BaseMethod * Create_PSA_SetTOI()
{
	return new M_PSA_SetTOI;
}

// 获得频谱仪三阶交调模式下的测量值
BaseMethod * Create_PSA_GetTOI()
{
	return new M_PSA_GetTOI;
}

// 设置频谱仪为时间开关模板测试模式
BaseMethod * Create_PSA_SetPVTMeas()
{
	return new M_PSA_SetPVTMeas;
}

// 触发一次时间开关模板测试
BaseMethod * Create_PSA_SetInitPVT()
{
	return new M_PSA_SetInitPVT;
}

// 获取频谱仪时间开关模板模式的功率值
BaseMethod * Create_PSA_GetPVT()
{
	return new M_PSA_GetPVT;
}

// 设置频谱仪时间开关模板模式下平均的状态
BaseMethod * Create_PSA_SetPVTAverageEnable()
{
	return new M_PSA_SetPVTAverageEnable;
}

// 设置频谱仪时间开关模板模式下的测量次数
BaseMethod * Create_PSA_SetPVTMEASTimes()
{
	return new M_PSA_SetPVTMEASTimes;
}

// 设置频谱仪为单载波测量模式、
BaseMethod * Create_PSA_SetACPMeas()
{
	return new M_PSA_SetACPMeas;
}

// 获取频谱仪单载波模式下个的测量功率值
BaseMethod * Create_PSA_GetACP()
{
	return new M_PSA_GetACP;
}

// 设置频谱仪触发延迟时间
BaseMethod * Create_PSA_SetTrigDelayTime()
{
	return new M_PSA_SetTrigDelayTime;
}

// 设置踪迹为平均估值方式
BaseMethod * Create_PSA_SetTraceAverage()
{
	return new M_PSA_SetTraceAverage;
}

//	设置EVM和PCDE模式下的平均状态和平均次数
BaseMethod * Create_PSA_SetEVMAver()
{
	return new M_PSA_SetEVMAver;
}

//	设置频谱耦合方式
BaseMethod * Create_PSA_SetFilterType()
{
	return new M_PSA_SetFilterType;
}

// 设置EVM和PCDE模式下的扰码
BaseMethod * Create_PSA_SetScrambleCode()
{
	return new M_PSA_SetScrambleCode;
}

// 获取指定带宽范围内的波动
BaseMethod * Create_PSA_GetFluctuate()
{
	return new M_PSA_GetFluctuate;
}

// 设置频谱仪在时域下MARKER点的位置
BaseMethod * Create_PSA_SetMarkTime()
{
	return new M_PSA_SetMarkTime;
}

// 设置外部门信号极性
BaseMethod * Create_PSA_SetSweepEgatePolarity()
{
	return new M_PSA_SetSweepEgatePolarity;
}

// 设置门扫描有效时间 (单位:ms)
BaseMethod * Create_PSA_SetSweepEgateLength()
{
	return new M_PSA_SetSweepEgateLength;
}

// 设置外部触发电平(-5V ~ 5V)
BaseMethod * Create_PSA_SetTrigLevel()
{
	return new M_PSA_SetTrigLevel;
}

// 设置ACP模式下起止时隙
BaseMethod * Create_PSA_SetStartAndStopSlot()
{
	return new M_PSA_SetStartAndStopSlot;
}

// 设置频谱仪的测试模式(0:SA 1:TDSCDMA_ACP 2:TDSCDMA_MCP 3:TDSCDMA_SEM 4:TDSCDMA_EVM 5:SA_Harmonic 6:SA_CCDF)
BaseMethod * Create_PSA_SetMeasMode()
{
	return new M_PSA_SetMeasMode;
}

// 获取SA_CCDF模式下的测量值
BaseMethod * Create_PSA_GetPST()
{
	return new M_PSA_GetPST;
}

// 获取SA_Harmonic模式下的测量值(dBm)(HarmonicNum:(0~10)  0:所有谐波值)
BaseMethod * Create_PSA_GetHarmonic()
{
	return new M_PSA_GetHarmonic;
}

// 设置载波间隔
BaseMethod * Create_PSA_SetCarrierSpaceList()
{
	return new M_PSA_SetCarrierSpaceList;
}

// 设置Offset Freqence列表(MHz)
BaseMethod * Create_PSA_SetOffsetFreqList()
{
	return new M_PSA_SetOffsetFreqList;
}

// 设置Offset Freqence列表状态(0:Off 1:On)
BaseMethod * Create_PSA_SetOffsetFreqState()
{
	return new M_PSA_SetOffsetFreqState;
}

// 设置 Offset Integ BW列表(KHz)
BaseMethod * Create_PSA_SetOffsetIBWList()
{
	return new M_PSA_SetOffsetIBWList;
}

// 设置Gate View状态(0:Off 1:On)
BaseMethod * Create_PSA_SetGateViewState()
{
	return new M_PSA_SetGateViewState;
}

// 设置扫描Gate Delay(ms)
BaseMethod * Create_PSA_SetSweepEgatDelay()
{
	return new M_PSA_SetSweepEgatDelay;
}

// 设置噪声修正状态(0: Off 1:On)
BaseMethod * Create_PSA_SetNoiseCorrState()
{
	return new M_PSA_SetNoiseCorrState;
}

// 设置Measurement Noise Bandwidth(MHz)
BaseMethod * Create_PSA_SetMeasNoiseBW()
{
	return new M_PSA_SetMeasNoiseBW;
}

// 设置参考载波
BaseMethod * Create_PSA_SetRefCarrier()
{
	return new M_PSA_SetRefCarrier;
}

// 设置参考载波频率(MHz)
BaseMethod * Create_PSA_SetRefCarrierFreq()
{
	return new M_PSA_SetRefCarrierFreq;
}

// 发送指令
BaseMethod * Create_PSA_SendCmd()
{
	return new M_PSA_SendCmd;
}

// 获取返回指令值
BaseMethod * Create_PSA_GetCmd()
{
	return new M_PSA_GetCmd;
}

// 获取设备型号信息
BaseMethod * Create_PSA_GetIDN()
{
	return new M_PSA_GetIDN;
}

// 加载状态文件
BaseMethod * Create_PSA_LoadFile()
{
	return new M_PSA_LoadFile;
}

// 保存文件
BaseMethod * Create_PSA_SaveFile()
{
	return new M_PSA_SaveFile;
}

// 获取SEM模式下的功率值
BaseMethod * Create_PSA_GetSEMPower()
{
	return new M_PSA_GetSEMPower;
}

// 获取EVM模式下的功率值
BaseMethod * Create_PSA_GetEVMPower()
{
	return new M_PSA_GetEVMPower;
}

// 设置扫描点数
BaseMethod * Create_PSA_SetSweepPoint()
{
	return new M_PSA_SetSweepPoint;
}


// 以命名方式将测试曲线数据保存到PC内存中
BaseMethod * Create_PSA_SaveTraceByName()
{
	return new  M_PSA_SaveTraceByName;
}

// 以命名方式处理PC内存数据(0:Off 1:Trace1/Trace2 2:Trace1*Trace2 3:Trace1-Trace2 4:Trace1+Trace2)
BaseMethod * Create_PSA_SetTraceMathTypeByName()
{
	return new  M_PSA_SetTraceMathTypeByName;
}

// 删除一条PC内存曲线
BaseMethod * Create_PSA_DeleteTraceByName()
{
	return new  M_PSA_DeleteTraceByName;
}

// 删除所有PC内存曲线
BaseMethod * Create_PSA_DeleteAllTrace()
{
	return new  M_PSA_DeleteAllTrace;
}

// 在PC内存数据中设置MARKER 的查找范围(MHz) 
BaseMethod * Create_PSA_SetMarkerSearchFreqByName()
{
	return new  M_PSA_SetMarkerSearchFreqByName;
}

// 从PC内存数据中获取最大值和最小值
BaseMethod * Create_PSA_GetMarkerValueByName()
{
	return new  M_PSA_GetMarkerValueByName;
}

// 从PC内存数据中获取指定带宽范围内的平坦度(MHz) 
BaseMethod * Create_PSA_GetFluctuateByName()
{
	return new  M_PSA_GetFluctuateByName;
}

// 从PC内存数据获取指定频率点Marker值
BaseMethod * Create_PSA_GetMarkerFreqByName()
{
	return new  M_PSA_GetMarkerFreqByName;
}

// 从PC内存数据获取X轴数据
BaseMethod * Create_PSA_GetTraceDataXByName()
{
	return new  M_PSA_GetTraceDataXByName;
}

// 从PC内存数据获取Y轴数据
BaseMethod * Create_PSA_GetTraceDataYByName()
{
	return new  M_PSA_GetTraceDataYByName;
}

//获取扫描时间值(s)
BaseMethod * Create_PSA_GetSweepTime()
{
	return new  M_PSA_GetSweepTime;
}

//获取触发时延(ms)
BaseMethod * Create_PSA_GetTrigDelayTime()
{
	return new  M_PSA_GetTrigDelayTime;
}

// 设置触发极性(0:Positive 1:Negative)
BaseMethod * Create_PSA_SetTrigPolarity()
{
	return new  M_PSA_SetTrigPolarity;
}
 
// 读取设备的测试数据
BaseMethod * Create_PSA_ReadDev()
{
	return new  M_PSA_ReadDev;
}

// 触发一次测量
BaseMethod * Create_PSA_SetTrigOnce()
{
	return new  M_PSA_SetTrigOnce;
}

// 重新测量一次
BaseMethod * Create_PSA_Restart()
{
	return new  M_PSA_Restart;
}

// 设置 绝对功率List
BaseMethod * Create_PSA_SetOffsetAbsList()
{
	return new  M_PSA_SetOffsetAbsList;
}

// 设置 Egat State
BaseMethod * Create_PSA_SetEgatState()
{
	return new  M_PSA_SetEgatState;
}
 
  
// 获取OBW值
BaseMethod * Create_PSA_GetOBW()
{
	return new  M_PSA_GetOBW;
}


// 设置Span
BaseMethod * Create_PSA_SetSpan()
{
	return new  M_PSA_SetSpan;
}


// 设置自动电平
BaseMethod * Create_PSA_RefLevelAuto()
{
	return new  M_PSA_RefLevelAuto;
}

// 设置ACLR模式
BaseMethod * Create_PSA_SetACLRMEAS()
{
	return new  M_PSA_SetACLRMEAS;
}

// 设置ACLR模式TX带宽
BaseMethod * Create_PSA_SetACPTXBW()
{
	return new  M_PSA_SetACPTXBW;
}

// 设置ACLR模式TXCount
BaseMethod * Create_PSA_SetACPTXCount()
{
	return new  M_PSA_SetACPTXCount;
}

// 设置TrigSource
BaseMethod * Create_PSA_SetTriggerSource()
{
	return new  M_PSA_SetTriggerSource;
}

// 设置TrigLevel
BaseMethod * Create_PSA_SetTriggerLevel()
{
	return new  M_PSA_SetTriggerLevel;
}

// 设置GateTrigSwitch
BaseMethod * Create_PSA_SetGateTrigSwitch()
{
	return new  M_PSA_SetGateTrigSwitch;
}

// 设置GateDelay
BaseMethod * Create_PSA_SetGateDelay()
{
	return new  M_PSA_SetGateDelay;
}

// 设置GateLength
BaseMethod * Create_PSA_SetGateLength()
{
	return new  M_PSA_SetGateLength;
}

// 获取ACLR值
BaseMethod * Create_PSA_GetACLR()
{
	return new  M_PSA_GetACLR;
}

// 设置VSA模式
BaseMethod * Create_PSA_SetVSAMODE()
{
	return new  M_PSA_SetVSAMODE;
}

// 设置PULSE模式
BaseMethod * Create_PSA_SetPULSEMODE()
{
	return new  M_PSA_SetPULSEMODE;
}

// 设置OBWPowerBandWidth
BaseMethod * Create_PSA_SetOBWPOWERBW()
{
	return new  M_PSA_SetOBWPOWERBW;
}

// 获得VSA模式下的EVM值
BaseMethod * Create_PSA_GetEVMValue()
{
	return new  M_PSA_GetEVMValue;
}

// 获得PULSE模式下的值
BaseMethod * Create_PSA_GetPULSEValue()
{
	return new  M_PSA_GetPULSEValue;
}

// 设置SingalCountFunction
BaseMethod * Create_PSA_SetSignCountFunc()
{
	return new  M_PSA_SetSignCountFunc;
}

// 获取Mark点频率
BaseMethod * Create_PSA_GetMarkFreq()
{
	return new  M_PSA_GetMarkFreq;
}

// 设置TriggerOffSet
BaseMethod * Create_PSA_SetTriggerOffSet()
{
	return new  M_PSA_SetTriggerOffSet;
}

// 设置Timing参数显示
BaseMethod * Create_PSA_SetTimingPara()
{
	return new  M_PSA_SetTimingPara;
}

// 设置Transmit Filter
BaseMethod * Create_PSA_SetTransFilter()
{
	return new  M_PSA_SetTransFilter;
}

// 设置ModulationSetting
BaseMethod * Create_PSA_SetModulation()
{
	return new  M_PSA_SetModulation;
}

// 设置CaptureLengthAuto
BaseMethod * Create_PSA_SetCaptureLengthAuto()
{
	return new  M_PSA_SetCaptureLengthAuto;
}

// 获取PulseNumber
BaseMethod * Create_PSA_GetPULSENumber()
{
	return new  M_PSA_GetPULSENumber;
}

/************************************************************************/
/* 网络仪驱动方法创建方法                                                */
/************************************************************************/
// 设备复位
BaseMethod * Create_ENA_Reset()
{
	return new M_ENA_Reset;
}

// 加载矢网工作状态文件
BaseMethod * Create_ENA_LoadFile()
{
	return new M_ENA_LoadFile;
}

// 设置矢网通道和曲线
BaseMethod * Create_ENA_SetChannelTrace()
{
	return new M_ENA_SetChannelTrace;
}

// 获取指定通道和曲线的最小MARKER值
BaseMethod * Create_ENA_GetMarkerMin()
{
	return new M_ENA_GetMarkerMin;
}

// 获取指定通道和曲线的最大MARKER值
BaseMethod * Create_ENA_GetMarkerMax()
{
	return new M_ENA_GetMarkerMax;
}

// 获取指定通道、曲线和频率点MARKER点的值
BaseMethod * Create_ENA_GetMarkerFreq()
{
	return new M_ENA_GetMarkerFreq;
}

// 设置矢网的平均状态
BaseMethod * Create_ENA_SetAverageState()
{
	return new M_ENA_SetAverageState;
}

// 设置矢网为AutoScale模式
BaseMethod * Create_ENA_SetScaleAuto()
{
	return new M_ENA_SetScaleAuto;
}

// 设置Marker Search 频率范围(单位:MHz)
BaseMethod * Create_ENA_SetMarkerStartandStopFreq()
{
	return new M_ENA_SetMarkerStartandStopFreq;
}

// 保存测试数据到内存中
BaseMethod * Create_ENA_SaveDataToMemory()
{
	return new M_ENA_SaveDataToMemory;
}

// 设置数据的处理方式 (0:Off 1:Data/Mem 2:Data*Mem 3:Data-Mem 4:Data+Mem)
BaseMethod * Create_ENA_SetTraceMathType()
{
	return new M_ENA_SetTraceMathType;
}

// 设置曲线形式 
BaseMethod * Create_ENA_SetTraceFormat()
{
	return new M_ENA_SetTraceFormat;
}

// 设置曲线显示类型 0:data 1:MEM 2:DATA&MEN 3:OFF
BaseMethod * Create_ENA_SetDisplayTrace()
{
	return new M_ENA_SetDisplayTrace;
}

// 获取功率范围内数据点的X和Y坐标值
BaseMethod * Create_ENA_GetSearchOutputPowerPosition()
{
	return new M_ENA_GetSearchOutputPowerPosition;
}

// 获取功率偏移量数据点的X和Y坐标值
BaseMethod * Create_ENA_GetSearchYDiffPosition()
{
	return new M_ENA_GetSearchYDiffPosition;
}

// 获取指定Marker点的指
BaseMethod * Create_ENA_GetMarkerValue()
{
	return new M_ENA_GetMarkerValue;
}

// 设置RF输出端口的状态
BaseMethod * Create_ENA_SetRFOutputState()
{
	return new M_ENA_SetRFOutputState;
}

// 设置RF输出端口的功率值
BaseMethod * Create_ENA_SetRFOutPower()
{
	return new M_ENA_SetRFOutPower;
}

// 获取指定带宽范围内的平坦度
BaseMethod * Create_ENA_GetFluctuate()
{
	return new M_ENA_GetFluctuate;
}

// 设置起止频率
BaseMethod * Create_ENA_SetStartandStopFreq()
{
	return new M_ENA_SetStartandStopFreq;
}

// 把曲线数据保存到PC内存中
BaseMethod * Create_ENA_SaveTraceToMemoryOfPC()
{
	return new M_ENA_SaveTraceToMemoryOfPC;
}

// 设置PC内存数据的处理方式 (0:Off 1:Data/Mem 2:Data*Mem 3:Data-Mem 4:Data+Mem)
BaseMethod * Create_ENA_SetTraceMathTypeOfPC()
{
	return new M_ENA_SetTraceMathTypeOfPC;
}

// 设置MARKER 在PC内存数据上查找范围(MHz) 
BaseMethod * Create_ENA_SetMarkerSearchFreqOfPC()
{
	return new M_ENA_SetMarkerSearchFreqOfPC;
}

// 从PC内存数据获取最大值和最小值
BaseMethod * Create_ENA_GetMarkerValueOfPC()
{
	return new M_ENA_GetMarkerValueOfPC;
}

// 从PC内存数据中获取指定带宽范围内的平坦度(MHz) 
BaseMethod * Create_ENA_GetFluctuateOfPC()
{
	return new M_ENA_GetFluctuateOfPC;
}

// 开启|关闭曲线平滑 (0:OFF	1:ON)
BaseMethod * Create_ENA_SetSmooth()
{
	return new M_ENA_SetSmooth;
}

// 保存文件(filetype(0:STATE 1:CST 2:DST 3:CDST 4:FDAT 5:IMAG))
BaseMethod * Create_ENA_SaveFile()
{
	return new M_ENA_SaveFile;
}

// 设置端口方向(Type: 0:S12 1:S21)
BaseMethod * Create_ENA_SetCalPortForward()
{
	return new M_ENA_SetCalPortForward;
}

// 设置校准类型(1:Open 2:Short 3:Thru 4:Enhanced Response 5:Full 1-Port 6:Full 2-Port)
BaseMethod * Create_ENA_SetCalType()
{
	return new M_ENA_SetCalType;
}

// 获得校准原始数据(1:Open 2:Short 3:Load 4:Thru  5:Isolation)
BaseMethod * Create_ENA_GetCalibrationData()
{
	return new M_ENA_GetCalibrationData;
}

// 设置电子校准类型(1:Full 1-Port 2:Full 2-Port 3:Enhanced Response 4:Response(Thru))
BaseMethod * Create_ENA_SetECalType()
{
	return new M_ENA_SetECalType;
}

// 保存校准数据
BaseMethod * Create_ENA_SaveCalibration()
{
	return new M_ENA_SaveCalibration;
}

// 设置校准件类型
BaseMethod * Create_ENA_SetCalKit()
{
	return new M_ENA_SetCalKit;
}

// 发送指令
BaseMethod * Create_ENA_SendCmd()
{
	return new M_ENA_SendCmd;
}

// 获取返回指令值
BaseMethod * Create_ENA_GetCmd()
{
	return new M_ENA_GetCmd;
}

// 获取设备型号信息
BaseMethod * Create_ENA_GetIDN()
{
	return new M_ENA_GetIDN;
}

//获取指定Marker点X轴值
BaseMethod * Create_ENA_GetMarkerXValue()
{
	return new M_ENA_GetMarkerXValue;
}

//从PC内存数据获取指定频率点Marker值
BaseMethod * Create_ENA_GetMarkerFreqOfPC()
{
	return new M_ENA_GetMarkerFreqOfPC;
}

// 获取曲线的数据
BaseMethod * Create_ENA_GetTraceData()
{
	return new  M_ENA_GetTraceData;
}

// 获取曲线的X轴数据
BaseMethod * Create_ENA_GetTraceDataX()
{
	return new  M_ENA_GetTraceDataX;
}
// 获取扫描类型 (0:Linear 1: Log 2: Segment 3:Power)
BaseMethod * Create_ENA_GetSweepType()
{
	return new  M_ENA_GetSweepType;
}

// 设置触发源(0:Internal 1:External 2:Bus)
BaseMethod * Create_ENA_SetTrigSource()
{
	return new  M_ENA_SetTrigSource;
}

// 设置触发类型(0:IMMediate 1:Single 2:Contine)
BaseMethod * Create_ENA_SetTrigMode()
{
	return new  M_ENA_SetTrigMode;
}

// 以命名方式将测试曲线数据保存到PC内存中
BaseMethod * Create_ENA_SaveTraceByName()
{
	return new  M_ENA_SaveTraceByName;
}

// 以命名方式处理PC内存数据(0:Off 1:Trace1/Trace2 2:Trace1*Trace2 3:Trace1-Trace2 4:Trace1+Trace2)
BaseMethod * Create_ENA_SetTraceMathTypeByName()
{
	return new  M_ENA_SetTraceMathTypeByName;
}

// 删除一条PC内存曲线
BaseMethod * Create_ENA_DeleteTraceByName()
{
	return new  M_ENA_DeleteTraceByName;
}

// 删除所有PC内存曲线
BaseMethod * Create_ENA_DeleteAllTrace()
{
	return new  M_ENA_DeleteAllTrace;
}

// 在PC内存数据中设置MARKER 的查找范围(MHz) 
BaseMethod * Create_ENA_SetMarkerSearchFreqByName()
{
	return new  M_ENA_SetMarkerSearchFreqByName;
}

// 从PC内存数据中获取最大值和最小值
BaseMethod * Create_ENA_GetMarkerValueByName()
{
	return new  M_ENA_GetMarkerValueByName;
}

// 从PC内存数据中获取指定带宽范围内的平坦度(MHz) 
BaseMethod * Create_ENA_GetFluctuateByName()
{
	return new  M_ENA_GetFluctuateByName;
}

// 从PC内存数据获取指定频率点Marker值
BaseMethod * Create_ENA_GetMarkerFreqByName()
{
	return new  M_ENA_GetMarkerFreqByName;
}

// 从PC内存获取曲线的Y轴数据
BaseMethod * Create_ENA_GetTraceDataYByName()
{
	return new  M_ENA_GetTraceDataYByName;
}

// 从PC内存获取曲线的X轴数据
BaseMethod * Create_ENA_GetTraceDataXByName()
{
	return new  M_ENA_GetTraceDataXByName;
}

// 设置指定Marker点频率值(MHz)
BaseMethod * Create_ENA_SetMarkerFreq()
{
	return new  M_ENA_SetMarkerFreq;
}

/************************************************************************/
/* 噪声仪驱动方法创建方法                                               */
/************************************************************************/
// 噪声仪复位
BaseMethod * Create_NFA_Reset()
{
	return new M_NFA_Reset;
}

// 设置噪声仪频率模式
BaseMethod * Create_NFA_SetFreqMode()
{
	return new M_NFA_SetFreqMode;
}

//  设置噪声仪起止频率
BaseMethod * Create_NFA_SetStartAndStopFreq()
{
	return new M_NFA_SetStartAndStopFreq;
}

// 设置噪声仪数据显示方式
BaseMethod * Create_NFA_SetDispFormat()
{
	return new M_NFA_SetDispFormat;
}

// 获取指定频率点的噪声系数值
BaseMethod * Create_NFA_GetFreqNfigure()
{
	return new M_NFA_GetFreqNfigure;
}

// 设置噪声仪扫描模式
BaseMethod * Create_NFA_SetSweepMode()
{
	return new M_NFA_SetSweepMode;
}

// 加载噪声仪校准状态文件
BaseMethod * Create_NFA_LoadFile()
{
	return new M_NFA_LoadFile;
}

// 获取最大噪声系数
BaseMethod * Create_NFA_GetListMax()
{
	return new M_NFA_GetListMax;
}

// 发送指令
BaseMethod * Create_NFA_SendCmd()
{
	return new M_NFA_SendCmd;
}

// 获取返回指令值
BaseMethod * Create_NFA_GetCmd()
{
	return new M_NFA_GetCmd;
}

// 获取设备型号信息
BaseMethod * Create_NFA_GetIDN()
{
	return new M_NFA_GetIDN;
}

// 获取曲线数据的最大值(TraceIndex 1:NFIGure 2:GAIN 3:PHOT 4:PCOLd 5:TEFFective)
BaseMethod * Create_NFA_GetTraceMax()
{
	return new M_NFA_GetTraceMax;
}


// 获取曲线数据的最小值(TraceIndex 1:NFIGure 2:GAIN 3:PHOT 4:PCOLd 5:TEFFective)
BaseMethod * Create_NFA_GetTraceMin()
{
	return new M_NFA_GetTraceMin;
}


// 获取曲线指定频率点的值(TraceIndex 1:NFIGure 2:GAIN 3:PHOT 4:PCOLd 5:TEFFective Freq:单位:MHz)
BaseMethod * Create_NFA_GetTraceFreqValue()
{
	return new M_NFA_GetTraceFreqValue;
}




/************************************************************************/
/* 芯通产品驱动方法创建方法                                             */
/************************************************************************/
// 打开设备 
BaseMethod * Create_NTS_OpenDev()
{
	return new M_NTS_OpenDev;
}

// 关闭设备
BaseMethod * Create_NTS_CloseDev()
{
	return new M_NTS_CloseDev;
}

// 设置模块功能号
/*
BaseMethod * Create_NTS_SetModuleFuncNo()
{
	return new M_NTS_SetModuleFuncNo;
}*/


//设置模块编号
/*
BaseMethod * Create_NTS_SetModuleNo()
{
	return new M_NTS_SetModuleNo;
}
*/

// 设置通道的上行衰减值
/*
BaseMethod * Create_NTS_SetUpAtten()
{
	return new M_NTS_SetUpAtten;
}*/


// 获取通道的上行衰减值
/*
BaseMethod * Create_NTS_GetUpAtten()
{
	return new M_NTS_GetUpAtten;
}*/


// 设置通道的下行衰减值
/*
BaseMethod * Create_NTS_SetDownAtten()
{
	return new M_NTS_SetDownAtten;
}*/


// 获取通道的下行衰减值
/*
BaseMethod * Create_NTS_GetDownAtten()
{
	return new M_NTS_GetDownAtten;
}*/


// 获取通道的上行OPD
/*
BaseMethod * Create_NTS_GetUpOpd()
{
	return new M_NTS_GetUpOpd;
}*/


// 获取通道的下行OPD
/*
BaseMethod * Create_NTS_GetDownOpd()
{
	return new M_NTS_GetDownOpd;
}*/


// 获取通道的下行IPD
/*
BaseMethod * Create_NTS_GetDownIpd()
{
	return new M_NTS_GetDownIpd;
}*/


// 获取模块MCU的软件版本
BaseMethod * Create_NTS_GetModuleVersion()
{
	return new M_NTS_GetModuleVersion;
}

// 获取测试卡MCU的软件版本
BaseMethod * Create_NTS_GetCardVersion()
{
	return new M_NTS_GetCardVersion;
}

// 设置通道的温度补偿数据
BaseMethod * Create_NTS_SetTmpCompensationData()
{
	return new M_NTS_SetTmpCompensationData;
}

// 获取通道的温度补偿温度传感器数据
BaseMethod * Create_NTS_GetTmpCompensationSense()
{
	return new M_NTS_GetTmpCompensationSense;
}

// 设置通道的推动级调整输出电压(DA值)
BaseMethod * Create_NTS_SetPushOutputVol()
{
	return new M_NTS_SetPushOutputVol;
}

// 获取通道的推动级调整输出电压(DA值)
BaseMethod * Create_NTS_GetPushOutPutVol()
{
	return new M_NTS_GetPushOutPutVol;
}

// 设置通道的末级调整输出电压(DA值)
BaseMethod * Create_NTS_SetLastOutputVol()
{
	return new M_NTS_SetLastOutputVol;
}

// 获取通道的末级调整输出电压(DA值)
BaseMethod * Create_NTS_GetLastOutputVol()
{
	return new M_NTS_GetLastOutputVol;
}

// 设置模块工作模式和检测模式(0:OPD 1:RPD)
BaseMethod * Create_NTS_SetWorkMode()
{
	return new M_NTS_SetWorkMode;
}

// 获取模块的工作模式
BaseMethod * Create_NTS_GetWorkMode()
{
	return new M_NTS_GetWorkMode;
}

// 设置1位PCB条码
BaseMethod * Create_NTS_SetOneBytePCB()
{
	return new M_NTS_SetOneBytePCB;
}

// 获取1位PCB条码
BaseMethod * Create_NTS_GetOneBytePCB()
{
	return new M_NTS_GetOneBytePCB;
}

// 设置PCB条码到FLASH中
BaseMethod * Create_NTS_SetPCB()
{
	return new M_NTS_SetPCB;
}

// 获取PCB条码
BaseMethod * Create_NTS_GetPCB()
{
	return new M_NTS_GetPCB;
}

// 设置EEPROM数据
BaseMethod * Create_NTS_SetEEPROM()
{
	return new M_NTS_SetEEPROM;
}

// 获取EEPROM数据
BaseMethod * Create_NTS_GetEEPROM()
{
	return new M_NTS_GetEEPROM;
}

// 设置矩阵开关的模式
BaseMethod * Create_NTS_SetSwtichMode()
{
	return new M_NTS_SetSwtichMode;
}

// 设置模块的供给电源状态
BaseMethod * Create_NTS_SetPowerState()
{
	return new M_NTS_SetPowerState;
}

// 获取通道的温度
BaseMethod * Create_NTS_GetTemperature()
{
	return new M_NTS_GetTemperature;
}

// 获取模块的驻波比
BaseMethod * Create_NTS_GetDownVSWR()
{
	return new M_NTS_GetDownVSWR;
}

// 设置模块的本振频率
BaseMethod * Create_NTS_SetLOFreq()
{
	return new M_NTS_SetLOFreq;
}

// 获取模块CPLD的软件版本
BaseMethod * Create_NTS_GetModuleCPLDVersion()
{
	return new M_NTS_GetModuleCPLDVersion;
}

// 获取测试卡CPLD的软件版本
BaseMethod * Create_NTS_GetCardCPLDVersion()
{
	return new M_NTS_GetCardCPLDVersion;
}

// 设置模块指定通道的工作模式
BaseMethod * Create_NTS_SetWorkModeEx()
{
	return new M_NTS_SetWorkModeEx;
}

// 获取模块指定通道的工作模
BaseMethod * Create_NTS_GetWorkModeEx()
{
	return new M_NTS_GetWorkModeEx;
}

// 设置模块指定通道的检测模式
BaseMethod * Create_NTS_SetDetectorMode()
{
	return new M_NTS_SetDetectorMode;
}

// 获取模块指定通道的检测模式
BaseMethod * Create_NTS_GetDetectorMode()
{
	return new M_NTS_GetDetectorMode;
}

// 获取测试卡产品号
BaseMethod * Create_NTS_GetCardProductNo()
{
	return new M_NTS_GetCardProductNo;
}

// 获取模块的产品号
BaseMethod * Create_NTS_GetModuleProductNo()
{
	return new M_NTS_GetModuleProductNo;
}

// 设置模块指定通道的低噪放链路模式
BaseMethod * Create_NTS_SetLanLinkMode()
{
	return new M_NTS_SetLanLinkMode;
}

// 设置指定通道的功率检测使能状态(0:off 1:on)
BaseMethod * Create_NTS_SetDectorState()
{
	return new M_NTS_SetDectorState;
}

// 设置第二级功放的输出电压
BaseMethod * Create_NTS_SetSecGAOutputVol()
{
	return new M_NTS_SetSecGAOutputVol;
}

// 获取第二级功放的输出电压
BaseMethod * Create_NTS_GetSecGAOutputVol()
{
	return new M_NTS_GetSecGAOutputVol;
}

// 设置第三级功放的输出电压
BaseMethod * Create_NTS_SetThirdGAOutputVol()
{
	return new M_NTS_SetThirdGAOutputVol;
}

// 获取第三级功放的输出电压
BaseMethod * Create_NTS_GetThirdGAOutputVol()
{
	return new M_NTS_GetThirdGAOutputVol;
}

// 获取通道的电流值(单位:bit)
BaseMethod * Create_NTS_GetCurrent()
{
	return new M_NTS_GetCurrent;
}

// 设置通道的上下限电流值(单位:bit)
BaseMethod * Create_NTS_SetCurrentLimited()
{
	return new M_NTS_SetCurrentLimited;
}

// 获取通道的上下限电流值(单位:bit)
BaseMethod * Create_NTS_GetCurrentLimited()
{
	return new M_NTS_GetCurrentLimited;
}

// 获取告警信息
BaseMethod * Create_NTS_GetIsWarning()
{
	return new M_NTS_GetIsWarning;
}

// 清除告警信息
BaseMethod * Create_NTS_ClearWarning()
{
	return new M_NTS_ClearWarning;
}

// 获取产品生产信息
BaseMethod * Create_NTS_GetIDN()
{
	return new M_NTS_GetIDN;
}

// 发送指令
BaseMethod * Create_NTS_SendCmd()
{
	return new M_NTS_SendCmd;
}
// 获取返回指令值
BaseMethod * Create_NTS_GetCmd()
{
	return new M_NTS_GetCmd;
}

//设置模块FLASH起止地址的数据
BaseMethod * Create_NTS_SetStarAndStopFlash()
{
	return new M_NTS_SetStarAndStopFlash;
}

//获取模块FLAST起止地址的数据
BaseMethod * Create_NTS_GetStarAndStopFlash()
{
	return new M_NTS_GetStarAndStopFlash;
}


//设置起止地址的RRPROM数据
BaseMethod * Create_NTS_SetStarAndStopEEPROM()
{
	return new M_NTS_SetStarAndStopEEPROM;
}

//获取起止地址的RRPROM数据
BaseMethod * Create_NTS_GetStarAndStopEEPROM()
{
	return new M_NTS_GetStarAndStopEEPROM;
}

// 写EEPROM离线参数的校验码
BaseMethod * Create_NTS_SetCRC()
{
	return new M_NTS_SetCRC;
}

//  设置电流调试参数
BaseMethod * Create_NTS_SetPID()
{
	return new M_NTS_SetPID;
}

//  设置功放的静态工作参数
BaseMethod * Create_NTS_SetGainWorkPara()
{
	return new M_NTS_SetGainWorkPara;
}

//  在电流表下调试单级功放的静态工作电流
BaseMethod * Create_NTS_GainDebug()
{
	return new M_NTS_GainDebug;
}

// 获取模块的供给电源状态
BaseMethod * Create_NTS_GetPowerState()
{
	return new M_NTS_GetPowerState;
}

// 设置模块RAM起止地址的数据
BaseMethod * Create_NTS_SetStartAndStopRAM()
{
	return new M_NTS_SetStartAndStopRAM;
}

// 获取通道的电压(单位:bit)
BaseMethod * Create_NTS_GetVoltage()
{
	return new M_NTS_GetVoltage;
}

// 设置当前需要的监控的对象
BaseMethod * Create_NTS_SetActiveObject()
{
	return new M_NTS_SetActiveObject;
}

// 设置第四级功放的输出电压
BaseMethod * Create_NTS_SetFourGAOutputVol()
{
	return new M_NTS_SetFourGAOutputVol;
}

// 获取第四级功放的输出电压
BaseMethod * Create_NTS_GetFourGAOutputVol()
{
	return new M_NTS_GetFourGAOutputVol;
}

//设置第五级功放的输出电压
BaseMethod * Create_NTS_SetFiveGAOutputVol()
{
	return new M_NTS_SetFiveGAOutputVol;
}

// 获取第五级功放的输出电压
BaseMethod * Create_NTS_GetFiveGAOutputVol()
{
	return new M_NTS_GetFiveGAOutputVol;
}

//设置第六级功放的输出电压
BaseMethod * Create_NTS_SetSixGAOutputVol()
{
	return new M_NTS_SetSixGAOutputVol;
}

// 获取第六级功放的输出电压
BaseMethod * Create_NTS_GetSixGAOutputVol()
{
	return new M_NTS_GetSixGAOutputVol;
}

//设置第七级功放的输出电压
BaseMethod * Create_NTS_SetSevenGAOutputVol()
{
	return new M_NTS_SetSevenGAOutputVol;
}

// 获取第七级功放的输出电压
BaseMethod * Create_NTS_GetSevenGAOutputVol()
{
	return new M_NTS_GetSevenGAOutputVol;
}

//设置第八级功放的输出电压
BaseMethod * Create_NTS_SetEightGAOutputVol()
{
	return new M_NTS_SetEightGAOutputVol;
}

// 获取第八级功放的输出电压
BaseMethod * Create_NTS_GetEightGAOutputVol()
{
	return new M_NTS_GetEightGAOutputVol;
}


//设置第九级功放的输出电压
BaseMethod * Create_NTS_SetNineGAOutputVol()
{
	return new M_NTS_SetNineGAOutputVol;
}

// 获取第九级功放的输出电压
BaseMethod * Create_NTS_GetNineGAOutputVol()
{
	return new M_NTS_GetNineGAOutputVol;
}

/************************************************************************/
/* 综合方法驱动方法创建方法                                             */
/************************************************************************/
// 系统停止
BaseMethod * Create_SPE_Pause()
{
	return new M_SPE_Pause;
}

// 系统延时
BaseMethod * Create_SPE_SetDelayTime()
{
	return new M_SPE_SetDelayTime;
}

// ACPR功率调试
BaseMethod * Create_SPE_ACPRPowerDebug()
{
	return new M_SPE_ACPRPowerDebug;
}

// 开关时间计算
BaseMethod * Create_SPE_GetTimeSwitch()
{
	return new M_SPE_GetTimeSwitch;
}

// ACP功率调试
BaseMethod * Create_SPE_ACPPowerDebug()
{
	return new M_SPE_ACPPowerDebug;
}

// SEM功率调试
BaseMethod * Create_SPE_SEMPowerDebug()
{
	return new M_SPE_SEMPowerDebug;
}

// EVM和PCDE功率调试
BaseMethod * Create_SPE_EVMandPCDEPowerDebug()
{
	return new M_SPE_EVMandPCDEPowerDebug;
}

// 相加运算
BaseMethod * Create_SPE_Add()
{
	return new M_SPE_Add;
}

//	相减运算
BaseMethod * Create_SPE_Subtract()
{
	return new M_SPE_Subtract;
}

//	相乘运算
BaseMethod * Create_SPE_Multiply()
{
	return new M_SPE_Multiply;
}

// 相除运算
BaseMethod * Create_SPE_Divide()
{
	return new M_SPE_Divide;
}

// 比较
BaseMethod * Create_SPE_Compare()
{
	return new M_SPE_Compare;
}

// 赋值
BaseMethod * Create_SPE_Equal()
{
	return new M_SPE_Equal;
}

// 绝对值
BaseMethod * Create_SPE_Absolute()
{
	return new M_SPE_Absolute;
}

// 频谱模式功率调试
BaseMethod * Create_SPE_SpectrumPowerDebug()
{
	return new M_SPE_SpectrumPowerDebug;
}

// ACPR调试
BaseMethod * Create_SPE_ACPRDebug()
{
	return new M_SPE_ACPRDebug;
}

// 输入对话框
BaseMethod * Create_SPE_ShowDialog()
{
	return new M_SPE_ShowDialog;
}

// 频谱模式功率调试
BaseMethod * Create_SPE_SpectrumPowerDebugEx()
{
	return new M_SPE_SpectrumPowerDebugEx;
}

// ACPR功率调试
BaseMethod * Create_SPE_ACPRPowerDebugEx()
{
	return new M_SPE_ACPRPowerDebugEx;
}

// 获取上升沿时间和上升延迟时间
BaseMethod * Create_SPE_GetUpTimeSwitch()
{
	return new M_SPE_GetUpTimeSwitch;
}

// 获取下降沿时间和下降延迟时间
BaseMethod * Create_SPE_GetDownTimeSwitch()
{
	return new M_SPE_GetDownTimeSwitch;
}

// 显示预定义对话框
BaseMethod * Create_SPE_ShowPromptDialog()
{
	return new M_SPE_ShowPromptDialog;
}

//	修改指定温度范围内末级DA的偏移量
BaseMethod * Create_SPE_SetLastDAOffset()
{
	return new M_SPE_SetLastDAOffset;
}

// 比较
BaseMethod * Create_SPE_CompareA()
{
	return new M_SPE_CompareA;
}

// 某个数的多少次方
BaseMethod * Create_SPE_Power()
{
	return new M_SPE_Power;
}

//	仪器复位
BaseMethod * Create_SPE_DevReset()
{
	return new M_SPE_DevReset;
}

// 功率计下功率调试
BaseMethod * Create_SPE_PRMPowerDebug()
{
	return new M_SPE_PRMPowerDebug;
}

// 按照特定字符分离字符串，并获取指定位置的数据
BaseMethod * Create_SPE_SeparateData()
{
	return new M_SPE_SeparateData;
}

// 把整型数据转化成字符串
BaseMethod * Create_SPE_IntToString()
{
	return new M_SPE_IntToString;
}

// 把浮点型数据转化成字符串
BaseMethod * Create_SPE_FloatToString()
{
	return new M_SPE_FloatToString;
}

// 获取指定范围内的数据
BaseMethod * Create_SPE_GetConditionData()
{
	return new M_SPE_GetConditionData;
}

// 获取Max值的位置
BaseMethod * Create_SPE_GetMaxPosition()
{
	return new M_SPE_GetMaxPosition;
}

//获取Min值的位置
BaseMethod * Create_SPE_GetMinPosition()
{
	return new M_SPE_GetMinPosition;
}

// 字符串连接
BaseMethod * Create_SPE_StrCat()
{
	return new M_SPE_StrCat;
}

// 在网络分析仪下改变功放DA值来调整产品的增益
BaseMethod * Create_SPE_GainDebugWithENA()
{
	return new M_SPE_GainDebugWithENA;
}

// 打开设备
BaseMethod * Create_SPE_OpenDev()
{
	return new M_SPE_OpenDev;
}

// 关闭设备
BaseMethod * Create_SPE_CloseDev()
{
	return new M_SPE_CloseDev;
}
// 多项式拟合
BaseMethod * Create_SPE_PolyFit()
{
	return new M_SPE_PolyFit;
}
// 获取设备厂商信息
BaseMethod * Create_SPE_GetIDN()
{
	return new M_SPE_GetIDN;
}

// 设置缓冲区长度(Mask 0:ALL 1:Tx_Buffer 2:Rx_Buffer)
BaseMethod *Create_SPE_SetBufSize()
{
	return new M_SPE_SetBufSize;
}

// 清除缓冲区(Mask 0:ALL 1:Tx_Buffer 2:Rx_Buffer)
BaseMethod *Create_SPE_ClearBuf()
{
	return new M_SPE_ClearBuf;
}

// 向自定义设备写数据
BaseMethod *Create_SPE_WriteDev()
{
	return new M_SPE_WriteDev;
}

// 从自定义设备读取数据
BaseMethod *Create_SPE_ReadDev()
{
	return new M_SPE_ReadDev;
}

// 向设备写命令并从设备读取命令执行后的数据
BaseMethod *Create_SPE_QueryDev()
{
	return new M_SPE_QueryDev;
}

// 向自定义设备写数据(只支持字符串写入)
BaseMethod *Create_SPE_SprintfDev()
{
	return new M_SPE_SprintfDev;
}

//  设置串口通讯参数
BaseMethod * Create_SPE_SetCom()
{
	return new M_SPE_SetCom;
}

// 设置RTS(数据终端就绪)标志  0:Low 1:Hight
BaseMethod * Create_SPE_SetDTR()
{
	return new M_SPE_SetDTR;
}

// 设置RTS(设置请求数据发送)标志  0:Low 1:Hight
BaseMethod * Create_SPE_SetRTS()
{
	return new M_SPE_SetRTS;
}

// 设置XOFF(设置流数据停止发送)标志 软件流控制
BaseMethod * Create_SPE_SetXOFF()
{
	return new M_SPE_SetXOFF;
}

// 设置XON(设置流数据继续发送)标志 软件流控制
BaseMethod * Create_SPE_SetXON()
{
	return new M_SPE_SetXON;
}

// FFT 算法
BaseMethod * Create_SPE_FFT()
{
	return new M_SPE_FFT;
}

// 获取最近错误信息
BaseMethod * Create_SPE_GetLastErrStr()
{
	return new M_SPE_GetLastErrStr;
}

// 设置通信属性参数
BaseMethod * Create_SPE_SetAttributeDev()
{
	return new M_SPE_SetAttributeDev;
}


// 节点上电
BaseMethod * Create_SPE_AgePowerOn()
{
	return new M_SPE_AgePowerOn;
}

// 节点关电
BaseMethod * Create_SPE_AgePowerOff ()
{
	return new M_SPE_AgePowerOff;
}

// 读取数据
BaseMethod * Create_SPE_AgeRead()
{
	return new M_SPE_AgeRead;
}

// 向I/O口写数据 
BaseMethod * Create_SPE_SetIOPortVal()
{
	return new M_SPE_SetIOPortVal;
}

// 从I/O读取数据
BaseMethod * Create_SPE_GetIOPortVal()
{
	return new M_SPE_GetIOPortVal;
}

// 设置T/R组件并口数据(Pin2:Data Pin3:CLK Pin4:Lock)
BaseMethod * Create_SPE_SetIOTRBits()
{
	return new M_SPE_SetIOTRBits;
}

// 设置IO触发方式 0:Positive(上升沿) 1:Negative(下降沿)
BaseMethod * Create_SPE_SetIOTrigPolarity()
{
	return new M_SPE_SetIOTrigPolarity;
}

/************************************************************************/
/* DPD板驱动方法创建方法                                                */
/************************************************************************/
// 设置DPD开关状态
BaseMethod * Create_DPD_SetDPDState()
{
	return new M_DPD_SetDPDState;
}

// 设置发射通道衰减值
BaseMethod * Create_DPD_SetTxAtten()
{
	return new M_DPD_SetTxAtten;
}

// 设置反馈通道衰减值
BaseMethod * Create_DPD_SetRDAtten()
{
	return new M_DPD_SetRDAtten;
}

// 获取偏差功率
BaseMethod * Create_DPD_GetErrPower()
{
	return new M_DPD_GetErrPower;
}

// 设置6载波功率因子
BaseMethod * Create_DPD_SetSixPwrFpg()
{
	return new M_DPD_SetSixPwrFpg;
}

// 设置9载功率波因子
BaseMethod * Create_DPD_SetNinePwrFpg()
{
	return new M_DPD_SetNinePwrFpg;
}

// 设置12载功率波因子
BaseMethod * Create_DPD_SetTwelvePwrFpg()
{
	return new M_DPD_SetTwelvePwrFpg;
}

// DPD偏差功率调试
BaseMethod * Create_DPD_SetErrPwrDebug()
{
	return new M_DPD_SetErrPwrDebug;
}

// ZX模块产品ACPR功率调试
BaseMethod * Create_DPD_ACPRPowerDebug()
{
	return new M_DPD_ACPRPowerDebug;
}

// 设置DPD工作频率
BaseMethod * Create_DPD_SetWorkFreq()
{
	return new M_DPD_SetWorkFreq;
}

// DT模块产品ACPR功率调试
BaseMethod * Create_DPD_ACPRPowerDebugDT()
{
	return new M_DPD_ACPRPowerDebugDT;
}

//DTDPD偏差功率调试
BaseMethod * Create_DPD_SetErrPwrDebugDT()
{
	return new M_DPD_SetErrPwrDebugDT;
}

// 设置DPD信号模式
BaseMethod * Create_DPD_SetSGMode()
{
	return new M_DPD_SetSGMode;
}

// 设置DPD载波模式	
BaseMethod * Create_DPD_SetCarriedMode()
{
	return new M_DPD_SetCarriedMode;
}

// 设置载波个数
BaseMethod * Create_DPD_SetCarriedCount()
{
	return new M_DPD_SetCarriedCount;
}

// 复位
BaseMethod * Create_DPD_Reset()
{
	return new M_DPD_Reset;
}

// 在功率下调试输出
BaseMethod * Create_DPD_PRMPowerDebug()
{
	return new M_DPD_PRMPowerDebug;
}
// 发送指令
BaseMethod * Create_DPD_SendCmd()
{
	return new M_DPD_SendCmd;
}

// 获取返回指令值
BaseMethod * Create_DPD_GetCmd()
{
	return new M_DPD_GetCmd;
}

// 获取设备型号信息
BaseMethod * Create_DPD_GetIDN()
{
	return new M_DPD_GetIDN;
}

// 设置DPD输出功率
BaseMethod * Create_DPD_SetRFOutPower()
{
	return new M_DPD_SetRFOutPower;
}

// 获取DPD输出功率
BaseMethod * Create_DPD_GetRFOutPower()
{
	return new M_DPD_GetRFOutPower;
}

// 设置CFR门限值
BaseMethod * Create_DPD_SetCFR()
{
	return new M_DPD_SetCFR;
}

// 获取CFR门限值
BaseMethod * Create_DPD_GetCFR()
{
	return new M_DPD_GetCFR;
}

// 获取反馈通道衰减值
BaseMethod * Create_DPD_GetRDAtten()
{
	return new M_DPD_GetRDAtten;
}

// 获取发射通道衰减值
BaseMethod * Create_DPD_GetTxAtten()
{
	return new M_DPD_GetTxAtten;
}

// 设置输出TX链路细调功率值(步进0.1dB)
BaseMethod * Create_DPD_SetSmallTxAtten()
{
	return new M_DPD_SetSmallTxAtten;
}

// 读取输出TX链路细调功率值(步进0.1dB)
BaseMethod * Create_DPD_GetSmallTxAtten()
{
	return new M_DPD_GetSmallTxAtten;
}

// 读取设备返回数据
BaseMethod * Create_DPD_ReadDev()
{
	return new M_DPD_ReadDev;
}

/************************************************************************/
/* 功率计驱动方法创建方法                                               */
/************************************************************************/
//复位 
BaseMethod * Create_PRM_Reset()
{
	return new M_PRM_Reset;
}

//校准
BaseMethod * Create_PRM_Calculate()
{
	return new M_PRM_Calculate;
}

//设置测量方式(0:Load 1:SOURce)
BaseMethod * Create_PRM_SetMeasPos()
{
	return new M_PRM_SetMeasPos;
}


// 设置插损(0~100 dB)
BaseMethod * Create_PRM_SetOffset()
{
	return new M_PRM_SetOffset;
}

// 获取测试测量值
BaseMethod * Create_PRM_GetPower()
{
	return new M_PRM_GetPower;
}

// 设置测量模式(0:平均功率 1:峰值功率 2:脉冲功率 )
BaseMethod * Create_PRM_SetMeasMode()
{
	return new M_PRM_SetMeasMode;
}

// 设置测量单位(0:W 1:DB 2:%)
BaseMethod * Create_PRM_SetMeasUnit()
{
	return new M_PRM_SetMeasUnit;
}
//获取设备型号信息
BaseMethod * Create_PRM_GetIDN()
{
  return new M_PRM_GetIDN;
}
	
//发送指令
BaseMethod * Create_PRM_SendCmd()
{
	return new M_PRM_SendCmd;
}
	
//获取返回指令值
BaseMethod * Create_PRM_GetCmd()
{
	return new M_PRM_GetCmd;
}

/************************************************************************/
/* 万用表驱动方法创建方法                                               */
/************************************************************************/
// 获取电流(A)
BaseMethod * Create_MMT_GetCurrent()
{
	return new M_MMT_GetCurrent;
}
// 获取电阻(Ω)
BaseMethod * Create_MMT_GetZn()
{
	return new M_MMT_GetZn;
}


/************************************************************************/
/* 矩阵开关驱动方法创建方法                                             */
/************************************************************************/
// 设置矩阵开关状态
BaseMethod * Create_SW_SetSwtichState()
{
	return new M_SW_SetSwtichState;
}

// 设置矩阵端口号(1~255)
BaseMethod * Create_SW_SetCtrlPort()
{
	return new M_SW_SetCtrlPort;
}

/************************************************************************/
/* DA调试驱动方法创建方法                                               */
/************************************************************************/
// DA调试并返回调试后的数据
BaseMethod * Create_DEB_WriteDebug()
{
	return new M_DEB_WriteDebug;
}

// 读取调试数据
BaseMethod * Create_DEB_ReadDebug()
{
	return new M_DEB_ReadDebug;
}


/************************************************************************/
/* EEPROM驱动方法创建方法                                               */
/************************************************************************/
// 写校准
BaseMethod * Create_ADJ_WriteCal()
{
	return new M_ADJ_WriteCal;
}

// 读校准
BaseMethod * Create_ADJ_ReadCal()
{
	return new M_ADJ_ReadCal;
}

// 获取产品的客户SN与校准数据是否有关系(0:无  1:有)
BaseMethod * Create_ADJ_GetClientSNRelate()
{
	return new M_ADJ_GetClientSNRelate;
}


/************************************************************************/
/* IRU驱动方法创建方法													*/
/************************************************************************/
//M_IRU_Reboot 重启
BaseMethod * Create_IRU_Reboot()
{
	return new M_IRU_Reboot;
}

//M_IRU_Reset IRU板复位
BaseMethod * Create_IRU_Reset()
{
	return new M_IRU_Reset;
}

//M_IRU_GetIDN 获取生产信息
BaseMethod * Create_IRU_GetIDN()
{
	return new M_IRU_GetIDN;
}

//M_IRU_SendCmd 发送指令
BaseMethod * Create_IRU_SendCmd()
{
	return new M_IRU_SendCmd;
}

//M_IRU_GetCmd 获取返回指令值
BaseMethod * Create_IRU_GetCmd()
{
	return new M_IRU_GetCmd;
}

//M_IRU_LoadFile 加载文件
BaseMethod * Create_IRU_LoadFile()
{
	return new M_IRU_LoadFile;
}


/************************************************************************/
/* 通用测试卡驱动方法创建方法											*/
/************************************************************************/

//获取测试卡MCU的软件版本
BaseMethod * Create_TC_GetCardMCUVersion()
{
	return new M_TC_GetCardMCUVersion;
}

// 获取测试卡CPLD版本号
BaseMethod * Create_TC_GetCardCPLDVersion()
{
	return new M_TC_GetCardCPLDVersion;
}

// 设置测试卡产品号 
BaseMethod * Create_TC_SetCardProductNo()
{
	return new M_TC_SetCardProductNo;
}

//设置测试卡FLASH起止地址的数据
BaseMethod * Create_TC_SetCardStartAndStopFlash()
{
	return new M_TC_SetCardStartAndStopFlash;
}

//获取测试卡FLAST起止地址的数据
BaseMethod * Create_TC_GetCardStartAndStopFlash()
{
	return new M_TC_GetCardStartAndStopFlash;
}

/************************************************************************/
/* NCARD 通用接口卡                                                     */
/************************************************************************/

//  打开并初始化NCard
BaseMethod * Create_NC_OpenDev()
{
	return new M_NC_OpenDev;
}
BaseMethod* Create_NC_CloseDev()
{
	return new M_NC_CloseDev;
}
BaseMethod* Create_NC_QuerySysParam()
{
	return new M_NC_QuerySysParam;
}
BaseMethod* Create_NC_QuerySysState()
{
	return new M_NC_QuerySysState;
}
BaseMethod* Create_NC_CreateCommObject()
{
	return new M_NC_CreateCommObject;
}
BaseMethod* Create_NC_DeleteCommObject()
{
	return new M_NC_DeleteCommObject;
}
BaseMethod* Create_NC_Read()
{
	return new M_NC_Read;
}
BaseMethod* Create_NC_Write()
{
	return new M_NC_Write;
}
BaseMethod* Create_NC_SetBufSize()
{
	return new M_NC_SetBufSize;
}
BaseMethod* Create_NC_ClearBuf()
{
	return new M_NC_ClearBuf;
}
BaseMethod* Create_NC_Sprintf()
{
	return new M_NC_Sprintf;
}
BaseMethod* Create_NC_Query()
{
	return new M_NC_Query;
}
BaseMethod* Create_NC_QueryContextInfo()
{
	return new M_NC_QueryContextInfo;
}
BaseMethod* Create_NC_QueryVersionInfo()
{
	return new M_NC_QueryVersionInfo;
}
BaseMethod* Create_NC_SetIPAddress()
{
	return new M_NC_SetIPAddress;
}
BaseMethod* Create_NC_Reset()
{
	return new M_NC_Reset;
}

/************************************************************************/
/* AutoIT 函数接口                                                     */
/************************************************************************/

BaseMethod* Create_AU3_Run()
{
	return new M_AU3_Run;
}
BaseMethod* Create_AU3_RunWait()
{
	return new M_AU3_RunWait;
}
BaseMethod* Create_AU3_WinWaitActive()
{
	return new M_AU3_WinWaitActive;
}
BaseMethod* Create_AU3_Send()
{
	return new M_AU3_Send;
}
BaseMethod* Create_AU3_ControlClick()
{
	return new M_AU3_ControlClick;
}
BaseMethod* Create_AU3_ControlSetText()
{
	return new M_AU3_ControlSetText;
}
BaseMethod* Create_AU3_ControlGetText()
{
	return new M_AU3_ControlGetText;
}
BaseMethod* Create_AU3_ControlCommand()
{
	return new M_AU3_ControlCommand;
}
BaseMethod* Create_AU3_ControlListView()
{
	return new M_AU3_ControlListView;
}

BaseMethod* Create_AU3_ClipGet()
{
	return new M_AU3_ClipGet;
}

BaseMethod* Create_AU3_ClipPut()
{
	return new M_AU3_ClipPut;
}

BaseMethod* Create_AU3_ControlDisable()
{
	return new M_AU3_ControlDisable;
}

BaseMethod* Create_AU3_ControlEnable()
{
	return new M_AU3_ControlEnable;
}

BaseMethod* Create_AU3_ControlFocus()
{
	return new M_AU3_ControlFocus;
}

BaseMethod* Create_AU3_ControlGetFocus()
{
	return new M_AU3_ControlGetFocus;
}

BaseMethod* Create_AU3_ControlGetPos()
{
	return new M_AU3_ControlGetPos;
}

BaseMethod* Create_AU3_ControlHide()
{
	return new M_AU3_ControlHide;
}

BaseMethod* Create_AU3_ControlMove()
{
	return new M_AU3_ControlMove;
}

BaseMethod* Create_AU3_ControlSend()
{
	return new M_AU3_ControlSend;
}

BaseMethod* Create_AU3_ControlShow()
{
	return new M_AU3_ControlShow;
}

BaseMethod* Create_AU3_MouseClick()
{
	return new M_AU3_MouseClick;
}

BaseMethod* Create_AU3_MouseClickDrag()
{
	return new M_AU3_MouseClickDrag;
}

BaseMethod* Create_AU3_MouseDown()
{
	return new M_AU3_MouseDown;
}

BaseMethod* Create_AU3_MouseUp()
{
	return new M_AU3_MouseUp;
}

BaseMethod* Create_AU3_MouseMove()
{
	return new M_AU3_MouseMove;
}

BaseMethod* Create_AU3_MouseWheel()
{
	return new M_AU3_MouseWheel;
}

BaseMethod* Create_AU3_AutoItSetOption()
{
	return new M_AU3_AutoItSetOption;
}

BaseMethod* Create_AU3_Opt()
{
	return new M_AU3_AutoItSetOption;
}

BaseMethod* Create_AU3_ProcessClose()
{
	return new M_AU3_ProcessClose;
}

BaseMethod* Create_AU3_ProcessExists()
{
	return new M_AU3_ProcessExists;
}

BaseMethod* Create_AU3_ProcessWait()
{
	return new M_AU3_ProcessWait;
}

BaseMethod* Create_AU3_ProcessWaitClose()
{
	return new M_AU3_ProcessWaitClose;
}

BaseMethod* Create_AU3_WinActivate()
{
	return new M_AU3_WinActivate;
}

BaseMethod* Create_AU3_WinActive()
{
	return new M_AU3_WinActive;
}

BaseMethod* Create_AU3_WinClose()
{
	return new M_AU3_WinClose;
}

BaseMethod* Create_AU3_WinExists()
{
	return new M_AU3_WinExists;
}

BaseMethod* Create_AU3_WinKill()
{
	return new M_AU3_WinKill;
}

BaseMethod* Create_AU3_WinSetOnTop()
{
	return new M_AU3_WinSetOnTop;
}

BaseMethod* Create_AU3_WinSetState()
{
	return new M_AU3_WinSetState;
}












