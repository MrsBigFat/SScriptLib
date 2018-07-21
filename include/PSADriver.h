/************************************************************************
* Copyright (c) 2009,оͨ�Ƽ����޹�˾
* All rights reserved.
* �ļ����ƣ�PSADriver.h
* �ļ���ʶ��reserved
* ժҪ��PSADriver.dll���ⲿ�ӿ��ļ�
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
* �汾��2.0.1.0
* ���ߣ�dolby.jiang
* ������ڣ�2009��8��26��
* ���ģ��ļ�����
*
************************************************************************/

/************************************************************************
* �汾��2.0.1.1
* ���ߣ�dolby.jiang
* ������ڣ�2009��9��23��
* ���ģ������ֶ�����ACPR�ķ����ӿ�
*
************************************************************************/


/************************************************************************
* �汾��2.0.1.2
* ���ߣ�dolby.jiang
* ������ڣ�2009��9��25��
* ���ģ��޸�SetMeasNoiseBW�ӿ�
*
************************************************************************/


/************************************************************************
* �汾��2.0.1.3
* ���ߣ�dolby.jiang
* ������ڣ�2009��9��30��
* ���ģ��޸ĺ�������λ��
*
************************************************************************/


/************************************************************************
* �汾��2.0.1.4
* ���ߣ�dolby.jiang
* ������ڣ�2009��11��23��
* ���ģ��޸Ĵ򿪺���
*
************************************************************************/

/************************************************************************
* �汾��3.0.0.0
* ���ߣ�dolby.jiang
* ������ڣ�2010��5��6��
* ���ģ�����PSA_SetSweepPoint
*
************************************************************************/


/************************************************************************
* �汾��3.0.0.1
* ���ߣ�dolby.jiang
* ������ڣ�2011��5��10��
* ���ģ�
1 ���� PSA_SaveTraceByName
2 ���� PSA_SetTraceMathTypeByName
3 ���� PSA_DeleteTraceByName
4 ���� PSA_DeleteAllTrace
5 ���� PSA_SetMarkerSearchFreqByName
6 ���� PSA_GetMarkerValueByName
7 ���� PSA_GetFluctuateByName
8 ���� PSA_GetMarkerFreqByName
*
************************************************************************/

/************************************************************************
* �汾��3.0.0.7
* ���ߣ�dolby.jiang
* ������ڣ�2011��8��5��
* ���ģ�
1 ���� PSA_GetTraceDataXByName
2 ���� PSA_GetTraceDataYByName
*
************************************************************************/


/************************************************************************
* �汾��3.0.0.8
* ���ߣ�dolby.jiang
* ������ڣ�2011��9��9��
* ���ģ�
1 ���� Vsa 89600 Method
*
************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
	
	//�򿪲���ʼ���豸
	PSADRIVER_API short int	_stdcall	PSA_OpenDev(char *ConnectStr, short int *Handle);

	//�ر��豸
	PSADRIVER_API short int	_stdcall	PSA_CloseDev(short int Handle);

	//������λ	
	PSADRIVER_API short int	_stdcall	PSA_SetPreset(short int Handle);

	//��������Ƶ��
	PSADRIVER_API short int	_stdcall	PSA_SetCenterFrq(short int Handle, double CenterFreq);	
	
	//��������Ƶ�ʺ�SPAN	
	PSADRIVER_API short int	_stdcall	PSA_SetCenterFrqandSpan(short int Handle, double CenterFreq, double Span);
	
	//���òο���ƽ
	PSADRIVER_API short int	_stdcall	PSA_SetRefLevel(short int Handle, double RefLevel);	
	
	//�����ڲ�˥��
	PSADRIVER_API short int	_stdcall	PSA_SetRFAttenuation(short int Handle, double Atten);	

	//����Ϊ�Զ�˥��ģʽ	
	PSADRIVER_API short int	_stdcall	PSA_SetRFAttenAuto(short int Handle);	
	
	//�����ڲ�˥��ƫ����	
	PSADRIVER_API short int	_stdcall	PSA_SetRefLevelOff(short int Handle, double RefLevOffs);
	
	//�����ⲿ˥��ƫ����	
	PSADRIVER_API short int	_stdcall	PSA_SetExtAtten(short int Handle, double Atten);

	//����Ԥ��״̬(0:Off 1:On)
	PSADRIVER_API short int	_stdcall	PSA_SetIntPreampOff(short int Handle, unsigned short State);  

	//����Y�����ʾ��ƽ��Χ	
	PSADRIVER_API short int	_stdcall	PSA_SetLevelRange(short int Handle, short LevelRange);

	//����ƽ������
	PSADRIVER_API short int	_stdcall	PSA_SetAverCount(short int Handle, unsigned short Count);

	//����ƽ������(0:RMS 1:SCALe 2:LOG)	
	PSADRIVER_API short int	_stdcall	PSA_SetAverType(short int Handle, unsigned short Type);

	//����ƽ��״̬(0:Off 1:On)
	PSADRIVER_API short int	_stdcall	PSA_SetAverState(short int Handle, unsigned short State);

	//����RBWֵ	
	PSADRIVER_API short int	_stdcall	PSA_SetRBW(short int Handle, double RBW);

	//����VBWֵ	
	PSADRIVER_API short int	_stdcall	PSA_SetVBW(short int Handle, double VBW);

	//���ü첨��ʽ(0:normal 1:average 2:Peak 3:sample 4:negative Peak 5:Quasi peak 9:RMS)
	PSADRIVER_API short int	_stdcall	PSA_SetDetectorMode(short int Handle, unsigned short Mode);

	//����ɨ��ʱ��(ms)
	PSADRIVER_API short int	_stdcall	PSA_SetSweepTime(short int Handle, double SweepTime);

	//����ɨ��ʱ��Ϊ�Զ�
	PSADRIVER_API short int	_stdcall	PSA_SetAUTOSweepTime(short int Handle, unsigned short State);

	//����ɨ��ģʽ(0:single 1:continous)
	PSADRIVER_API short int	_stdcall	PSA_SetSweepTimeMode(short int Handle, unsigned short Mode);

	//����ΪMax Holdģʽ
	PSADRIVER_API short int	_stdcall	PSA_SetTraceMaxHold(short int Handle);

	//����ΪMin Holdģʽ
	PSADRIVER_API short int	_stdcall	PSA_SetTraceMinHold(short int Handle);

	//����ΪClear Writeģʽ
	PSADRIVER_API short int	_stdcall	PSA_SetTraceClearWrite(short int Handle);

	//����������������
	PSADRIVER_API short int	_stdcall	PSA_GetTraceData(short int Handle, double *TraceData, long *Count);

	//���ô�������(0:IMM 1:EXT 2:RF Burst)
	PSADRIVER_API short int	_stdcall	PSA_SetTrigSource(short int Handle, unsigned short Mode);

	//�������MARKER��
	PSADRIVER_API short int	_stdcall	PSA_SetMarkMax(short int Handle, long MarkerIndex);

	//������СMARKER��
	PSADRIVER_API short int	_stdcall	PSA_SetMarkMin(short int Handle, long MarkerIndex);

	//������һ�����MARKER��
	PSADRIVER_API short int	_stdcall	PSA_SetMaxNext(short int Handle, long MarkerIndex);

	//����MARKER���״̬
	PSADRIVER_API short int	_stdcall	PSA_SetMarkState(short int Handle, long MarkerIndex, unsigned short State);

	//����MARKER���Ƶ��ֵ
	PSADRIVER_API short int	_stdcall	PSA_SetMarkPosition(short int Handle, long MarkerIndex, double Freq);

	//����MARKER�������(0:NORMal 1:DELTa )
	PSADRIVER_API short int	_stdcall	PSA_SetMarkerMode(short int Handle, long MarkerIndex, unsigned short Mode);

	//��ȡMARKER��ֵ
	PSADRIVER_API short int	_stdcall	PSA_GetMarkValue(short int Handle, long MarkerIndex, double *Value);	

	//����ΪTD���ʲ���ģʽ
//	PSADRIVER_API short int	_stdcall	PSA_SetTDPWRMODE(short int Handle);	

	//����TD����ģʽ�µ�ʱ϶
	PSADRIVER_API short int	_stdcall	PSA_SetTDPOWSLOT(short int Handle, short Slot);	

	//����Ϊ���ģʽ
//	PSADRIVER_API short int	_stdcall	PSA_SetTDMODMODE(short int Handle);

	//��ȡ���ģʽ�µ�EVM��PCDEֵ
	PSADRIVER_API short int	_stdcall	PSA_GetEVMandPCDE(short int Handle, double *EVM, double *PCDE);

	//����Ƶ�ײ���ģʽ
	PSADRIVER_API short int	_stdcall	PSA_SetSPECMODE(short int Handle);

	//������ֹƵ��
	PSADRIVER_API short int	_stdcall	PSA_SetStarandStopFreq(short int Handle, double StartFreq, double StopFreq);	

	//����Ϊ���ز�����ģʽ
	PSADRIVER_API short int	_stdcall	PSA_SetMULACPRMeas(short int Handle);	

	//���ö��ز�ģʽ�µ��ز���
	PSADRIVER_API short int	_stdcall	PSA_SetMCCOUNT(short int Handle, unsigned short Count);

	//��ȡ���ز�ģʽ�µĲ���ֵ
	PSADRIVER_API short int	_stdcall	PSA_GetMULACPR(short int Handle, double *Value, long *Count);

	//���ö��ز�ģʽ�µ�ƽ��������ƽ��״̬
	PSADRIVER_API short int	_stdcall	PSA_SetMCPAVER(short int Handle, unsigned short State, long Count);

	//����ΪƵ�׷���ģ�����ģʽ
	PSADRIVER_API short int	_stdcall	PSA_SetSEMMeas(short int Handle);

	//����Ƶ�׷���ģ��ģʽ
	PSADRIVER_API short int	_stdcall	PSA_SetInitSEM(short int Handle);
	
	//����Ƶ�׷���ģ��ģʽ�µ�ƽ��״̬
	PSADRIVER_API short int	_stdcall	PSA_SetSEMAverageEnable(short int Handle, unsigned short State);   

	//����Ƶ�׷���ģ��ģʽ�µ�ģ������
	PSADRIVER_API short int	_stdcall	PSA_SetSEMLimits(short int Handle, unsigned short Limit); 

	//��ȡƵ�׷���ģ��ģʽ�µĲ���ֵ(0:PASS 1:FAIL)
	PSADRIVER_API short int	_stdcall	PSA_GetSEM(short int Handle, int *State);

	//����ΪEVM��PCDE����ģʽ
	PSADRIVER_API short int	_stdcall	PSA_SetEVMMeas(short int Handle);	

	//����EVM��PCDE����ģʽ�µĲ���ʱ϶
	PSADRIVER_API short int	_stdcall	PSA_SetEVMSlot(short int Handle, unsigned short Slot);

	//��ʼ��EVM��PCDE����ģʽ
	PSADRIVER_API short int	_stdcall	PSA_SetInitEVM(short int Handle); 

	//����ͬ����������
	PSADRIVER_API short int	_stdcall	PSA_SetSyncType(short int Handle, unsigned short Type, unsigned short Timingref);

	//�����׻�����ȡ��
	PSADRIVER_API short int	_stdcall	PSA_SetTOI(short int Handle);
	
	//��ȡΪ���׻���ģʽ�µĲ���ֵ
	PSADRIVER_API short int	_stdcall	PSA_GetTOI(short int Handle, double *Value, long *Count); 

	//����Ϊ���׻���ģʽ�µ�ƽ��״̬(0:Off 1:On)
	PSADRIVER_API short int	_stdcall	PSA_SetTOIAVGState(short int Handle, unsigned short State);

	//����Ƶ����Ϊʱ�俪��ģ�����
	PSADRIVER_API short int	_stdcall	PSA_SetPVTMeas(short int Handle);

	//����һ��ʱ�俪��ģ�����
	PSADRIVER_API short int	_stdcall	PSA_SetInitPVT(short int Handle);

	//��ȡʱ�俪��ģ�����ģʽ�µĲ���ֵ
	PSADRIVER_API short int	_stdcall	PSA_GetPVT(short int Handle, double *Value, long *Count);

	//����ʱ�俪��ģ��ģʽ�µ�ƽ������
	PSADRIVER_API short int	_stdcall	PSA_SetPVTAverageEnable(short int Handle, unsigned short State);  

	//����ʱ�俪��ģ�����ģʽ�µĲ���ʱ϶����
	PSADRIVER_API short int	_stdcall	PSA_SetPVTMEASTimes(short int Handle, long Times);

	//����Ϊ���ز�����ģʽ
	PSADRIVER_API short int	_stdcall	PSA_SetACPMeas(short int Handle);

	//��õ��ز�ģʽ�µĲ���ֵ
	PSADRIVER_API short int	_stdcall	PSA_GetACP(short int Handle, double *Value, long *Count);

	//������ʾ����
	PSADRIVER_API short int _stdcall    PSA_SetWindow(short int Handle, unsigned short Window);

	//���ô����ӳ�ʱ��(��λ:s)
	PSADRIVER_API short int _stdcall    PSA_SetTrigDelayTime(short int Handle,double TrigDelayTime);

	//�����ⲿ���źŵļ���(0:POSitive 1:NEGative)
	PSADRIVER_API short int _stdcall	PSA_SetSweepEgatePolarity(short int Handle, unsigned short Polarity);

	//�����ټ�Ϊƽ����ֵ��ʽ
	PSADRIVER_API short int _stdcall	PSA_SetTraceAverage(short int Handle);

	//��ȡɨ��ʱ��ֵ
	PSADRIVER_API short int _stdcall	PSA_GetSweepTime(short int Handle, double *SweepTime);

	//��ȡ�����ӳ�ʱ��
	PSADRIVER_API short int _stdcall	PSA_GetTrigDelayTime(short int Handle, double *TrigDelayTime);

	//���Ƶ�׷���ģ��ģʽ�µĹ��ʲ������
	PSADRIVER_API short int _stdcall	PSA_GetSEMPower(short int Handle, double *ChPower);

	//���EVM��PCDEģʽ�µĹ��ʲ������
	PSADRIVER_API short int _stdcall	PSA_GetEVMPower(short int Handle, double *ChPower);

	//����EVM��PCDEģʽ�µ�ƽ��������״̬
	PSADRIVER_API short int _stdcall	PSA_SetEVMAver(short int Handle, unsigned short Count, unsigned short State);

	//����Ƶ����Ϸ�ʽ R&S 0:NORMal	1:FFT 2:CFILter 3:RRC 4:NOISe 5:PULSe 6:P5
	PSADRIVER_API short int _stdcall	PSA_SetFilterType(short int Handle, unsigned short Type);

	//����EVM��PCDEģʽ�µ�����
	PSADRIVER_API short int _stdcall	PSA_SetScrambleCode(short int Handle, short ScrambleCode);

	//��ȡָ������Χ�ڵĲ���
	PSADRIVER_API short int _stdcall    PSA_GetFluctuate(short int Handle, double BandWidth, double *Fluctuate);
	
	//��ʱ��ģʽ������Marker��λ��(��λ:ms)
	PSADRIVER_API short int _stdcall    PSA_SetMarkTime(short int Handle,long MarkerIndex, double Time);

	//������ɨ����Чʱ��(��λ:ms)
	PSADRIVER_API short int _stdcall    PSA_SetSweepEgateLength(short int Handle, double GateLength);

	//�����ⲿ������ƽ(-5V ~ 5V)
	PSADRIVER_API short int _stdcall	PSA_SetTrigLevel(short int Handle, double TrigLevel);
	
	//����ACPģʽ����ֹʱ϶
	PSADRIVER_API short int _stdcall	PSA_SetStartAndStopSlot(short int Handle, short StartSlot, short StopSlot);

	//����Ƶ���ǵĲ���ģʽ(0:SA 1:TDSCDMA_ACP 2:TDSCDMA_MCP 3:TDSCDMA_SEM 
	//4:TDSCDMA_EVM 5:SA_Harmonic 6:SA_CCDF 7:SA_ACP)
	PSADRIVER_API short int _stdcall	PSA_SetMeasMode(short int Handle, int MeasureMode);

	//��ȡSA_CCDFģʽ�µĲ���ֵ
	PSADRIVER_API short int _stdcall	PSA_GetPST(short int Handle, double *Values);

	//��ȡSA_Harmonicģʽ�µĲ���ֵ(dBm)(HarmonicNum:(0~10)  0:����г��ֵ)
	PSADRIVER_API short int _stdcall	PSA_GetHarmonic(short int Handle, int HarmonicNum, double *Values);

	//��ȡ�豸�ͺ���Ϣ
	PSADRIVER_API short int _stdcall	PSA_GetIDN(short int Handle, char *IDN);

	//����״̬�ļ�
	PSADRIVER_API short int _stdcall	PSA_LoadFile(short int Handle, char *FileName);	
	
	//����״̬�ļ�
	PSADRIVER_API short int _stdcall	PSA_SaveFile(short int Handle, char *FileName, int FileType);
	
	//�����ز����
	PSADRIVER_API short int _stdcall	PSA_SetCarrierSpaceList(short int Handle, double *SpaceList, int Count);
	
	//������������״̬(0: Off 1:On)
	PSADRIVER_API short int _stdcall	PSA_SetNoiseCorrState(short int Handle, int State);
	
	//����Offset Freqence�б�(MHz)
	PSADRIVER_API short int _stdcall	PSA_SetOffsetFreqList(short int Handle, double *FreqList, int Count);
	
	//����Offset Freqence�б�״̬(0:Off 1:On)
	PSADRIVER_API short int _stdcall	PSA_SetOffsetFreqState(short int Handle, int *StateList, int Count);
	
	//����Offset Integ BW�б�(MHz)
	PSADRIVER_API short int _stdcall	PSA_SetOffsetIBWList(short int Handle, double *IBWList, int Count);
	
	//����Gate View״̬(0:Off 1:On)
	PSADRIVER_API short int _stdcall	PSA_SetGateViewState(short int Handle, int State);
	
	//����ɨ��Gate Delay(ms)
	PSADRIVER_API short int _stdcall	PSA_SetSweepEgatDelay(short int Handle, double Time);
	
	//����Measurement Noise Bandwidth(MHz)
	PSADRIVER_API short int _stdcall	PSA_SetMeasNoiseBW(short int Handle, double *MNBWList, int Count);
	
	//���òο��ز�
	PSADRIVER_API short int _stdcall	PSA_SetRefCarrier(short int Handle, int CarrierNo);
	
	//���òο��ز�Ƶ��(MHz)
	PSADRIVER_API short int _stdcall	PSA_SetRefCarrierFreq(short int Handle, double Freq);
	
	//����ָ��
	PSADRIVER_API short int _stdcall	PSA_SendCmd(short int Handle, char *Command);
	
	//��ȡ����ָ��ֵ
	PSADRIVER_API short int _stdcall	PSA_GetCmd(short int Handle, char *Command, char *RetStr);

	// ����ɨ�����
	PSADRIVER_API short int _stdcall	PSA_SetSweepPoint(short int Handle, int Points);
		
	// ��������ʽ�������������ݱ��浽PC�ڴ���
	PSADRIVER_API	short int _stdcall	PSA_SaveTraceByName(short int Handle, unsigned short ch, int traceindex, char *Name) ;
	
	// ��������ʽ����PC�ڴ�����(0:Off 1:Trace1/Trace2 2:Trace1*Trace2 3:Trace1-Trace2 4:Trace1+Trace2)
	PSADRIVER_API	short int _stdcall	PSA_SetTraceMathTypeByName(short int Handle, char *Trace1, char *Trace2, short type, char *NewName);
	
	// ɾ��һ��PC�ڴ�����
	PSADRIVER_API	short int _stdcall	PSA_DeleteTraceByName(short int Handle, char *Name) ;
	
	// ɾ������PC�ڴ�����
	PSADRIVER_API	short int _stdcall	PSA_DeleteAllTrace(short int Handle);
	
	// ��PC�ڴ�����������MARKER �Ĳ��ҷ�Χ(MHz) 
	PSADRIVER_API	short int _stdcall	PSA_SetMarkerSearchFreqByName(short int Handle, char *Name, double Start, double Stop);
	
	// ��PC�ڴ������л�ȡ���ֵ����Сֵ
	PSADRIVER_API	short int _stdcall	PSA_GetMarkerValueByName(short int Handle, char *Name, double *Max, double *Min);
	
	// ��PC�ڴ������л�ȡָ������Χ�ڵ�ƽ̹��(MHz) 
	PSADRIVER_API	short int _stdcall	PSA_GetFluctuateByName(short int Handle, char *Name, double BandWidth, double *Fluctuate);
	
	// ��PC�ڴ����ݻ�ȡָ��Ƶ�ʵ�Markerֵ
	PSADRIVER_API	short int _stdcall	PSA_GetMarkerFreqByName(short int Handle, char *Name, unsigned short Marker, double Freq, double *Value);
	
	// ���ô�������(0:Positive 1:Negative)
	PSADRIVER_API	short int _stdcall	PSA_SetTrigPolarity(short int Handle, int Polarity);

	// ��PC�ڴ����ݻ�ȡX������
	PSADRIVER_API	short int _stdcall	PSA_GetTraceDataXByName(short int Handle, char *Name, double *TraceDataX, long *Count);
	
	// ��PC�ڴ����ݻ�ȡY������
	PSADRIVER_API	short int _stdcall	PSA_GetTraceDataYByName(short int Handle, char *Name, double *TraceDataY, long *Count);
	
	// ��ȡ�豸�Ĳ�������
	PSADRIVER_API	short int _stdcall	PSA_ReadDev(short int Handle, int ResultPara, char *RetStr, int ReadCount, int *RealCount);
	
	// ����һ�β���
	PSADRIVER_API	short int _stdcall	PSA_SetTrigOnce(short int Handle);
	
	// ���²���һ��
	PSADRIVER_API	short int _stdcall	PSA_Restart(short int Handle);

	//���� Offs List Abs (dBm)
	PSADRIVER_API   short int _stdcall  PSA_SetOffsetAbsList(short int Handle, double *OffsAbsList, int Count);

	// ����sweep egat ״̬
	PSADRIVER_API   short int _stdcall  PSA_SetEgatState(short int Handle, int State);	
	
	//��ȡOBW
	PSADRIVER_API short int	_stdcall	PSA_GetOBW(short int Handle, double *OBWValue);
	
	//����Marker Function
	PSADRIVER_API short int	_stdcall	PSA_SetMarkFunction(short int Handle,long MarkerIndex, unsigned short state);
	//��ȡmarker��Ƶ��
/*	PSADRIVER_API short int	_stdcall	PSA_GetMarkFreq(short int Handle, long MarkerIndex, double *Freq);*/
	//���ô���Slope
	PSADRIVER_API short int	_stdcall	PSA_SetTrigSlope(short int Handle,unsigned short mode);	
	//����Span
	PSADRIVER_API short int	_stdcall	PSA_SetSpan(short int Handle,double span);	

	//�����Զ���ƽ
	PSADRIVER_API short int	_stdcall	PSA_RefLevelAuto(short int Handle);	
	
	//����ACLRģʽ
	PSADRIVER_API short int	_stdcall	PSA_SetACLRMEAS(short int Handle);
	
	//����ACLRģʽTX����
	PSADRIVER_API short int	_stdcall	PSA_SetACPTXBW(short int Handle, short int channel, double freq);

	//����ACLRģʽTXCount
	PSADRIVER_API short int	_stdcall	PSA_SetACPTXCount(short int Handle, short int count);

	//����TrigSource
	PSADRIVER_API short int	_stdcall	PSA_SetTriggerSource(short int Handle, short int source);

	//����TrigLevel
	PSADRIVER_API short int	_stdcall	PSA_SetTriggerLevel(short int Handle, short int source, double level);

	//����GateTrigSwitch
	PSADRIVER_API short int	_stdcall	PSA_SetGateTrigSwitch(short int Handle, short int Switch);

	//����GateDelay
	PSADRIVER_API short int	_stdcall	PSA_SetGateDelay(short int Handle, double delay);

	//����GateLength
	PSADRIVER_API short int	_stdcall	PSA_SetGateLength(short int Handle, double length);

	//��ȡACLRֵ
	PSADRIVER_API short int	_stdcall	PSA_GetACLR(short int Handle, char *Value);

	//����VSAģʽ
	PSADRIVER_API short int	_stdcall	PSA_SetVSAMODE(short int Handle);

	//����PULSEģʽ
	PSADRIVER_API short int	_stdcall	PSA_SetPULSEMODE(short int Handle);
		
	//����OBWPowerBandWidth
	PSADRIVER_API short int	_stdcall	PSA_SetOBWPOWERBW(short int Handle, double power);

	//��ȡEVMValue
	PSADRIVER_API short int	_stdcall	PSA_GetEVMValue(short int Handle, double *RetStr);

	//��ȡPULSEValue
	PSADRIVER_API short int	_stdcall	PSA_GetPULSEValue(short int Handle, char *RetStr1, char *RetStr2);

	//����SignCountFunction
	PSADRIVER_API short int	_stdcall	PSA_SetSignCountFunc(short int Handle);

	//���Mark��Ƶ��
	PSADRIVER_API short int	_stdcall	PSA_GetMarkFreq(short int Handle, long MarkerIndex, double *Freq);

	//����TriggerOffSet
	PSADRIVER_API short int	_stdcall	PSA_SetTriggerOffSet(short int Handle, double offset);

	//����Timing������ʾ
	PSADRIVER_API short int	_stdcall	PSA_SetTimingPara(short int Handle, short int offtime, short int dutycycle);

	//����Transmit Filter
	PSADRIVER_API short int	_stdcall	PSA_SetTransFilter(short int Handle, short int type, double alpha);

	//����ModulationSetting
	PSADRIVER_API short int	_stdcall	PSA_SetModulation(short int Handle, short int type, short int order, short int map, double rate);

	//����CaptureLengthAuto
	PSADRIVER_API short int	_stdcall	PSA_SetCaptureLengthAuto(short int Handle, short int Switch);

	//��ȡPulseNumber
	PSADRIVER_API short int	_stdcall	PSA_GetPULSENumber(short int Handle, int *RetStr);

#ifdef __cplusplus
}
#endif























