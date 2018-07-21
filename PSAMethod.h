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
* �汾��2.0.0.45
* ���ߣ�dolby.jiang
* ������ڣ�2009��10��10��
* ���ģ�
*
************************************************************************/


/************************************************************************
* �汾��2.1.0.9
* ���ߣ�dolby.jiang
* ������ڣ�2010��3��29��
* ���ģ����� PSA_LoadFile 
*
************************************************************************/

/************************************************************************
* �汾��3.0.0.3
* ���ߣ�dolby.jiang
* ������ڣ�2010��5��6��
* ���ģ����� M_PSA_SetSweepPoint ����ɨ�����
*
************************************************************************/

/************************************************************************/
/*  Ƶ�׷������������򷽷���                                            */
/************************************************************************/
//M_PSA_SetPreset Ƶ���Ǹ�λ
class M_PSA_SetPreset:public BaseMethod
{
public:
	M_PSA_SetPreset();
	virtual ~M_PSA_SetPreset();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
		
};

//M_PSA_SetCenterFrq ����Ƶ��������Ƶ��
class M_PSA_SetCenterFrq:public BaseMethod
{
public:
	M_PSA_SetCenterFrq();
	virtual ~M_PSA_SetCenterFrq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
	
};
//M_PSA_SetCenterFrqandSpan ����Ƶ��������Ƶ�ʺ�span
class M_PSA_SetCenterFrqandSpan:public BaseMethod
{
public:
	M_PSA_SetCenterFrqandSpan();
	virtual ~M_PSA_SetCenterFrqandSpan();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_InputDeviceName;
	
};

//M_PSA_SetRefLevel ����Ƶ���ǲο���ƽ
class M_PSA_SetRefLevel:public BaseMethod
{
public:
	M_PSA_SetRefLevel();
	virtual ~M_PSA_SetRefLevel();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
	
};

//M_PSA_SetRFAttenuation ����Ƶ�����ڲ�˥��ֵ
class M_PSA_SetRFAttenuation:public BaseMethod
{
public:
	M_PSA_SetRFAttenuation();
	virtual ~M_PSA_SetRFAttenuation();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
	
};

//M_PSA_SetRFAttenAuto ����Ƶ�����Զ��ڲ�˥��ֵ
class M_PSA_SetRFAttenAuto:public BaseMethod
{
public:
	M_PSA_SetRFAttenAuto();
	virtual ~M_PSA_SetRFAttenAuto();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	
};
//M_PSA_SetRefLevelOff ����Ƶ�����ڲ�˥��ƫ����
class M_PSA_SetRefLevelOff:public BaseMethod
{
public:
	M_PSA_SetRefLevelOff();
	virtual ~M_PSA_SetRefLevelOff();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
	
};
//M_PSA_SetExtAtten ����Ƶ�����ⲿ˥��ƫ����
class M_PSA_SetExtAtten:public BaseMethod
{
public:
	M_PSA_SetExtAtten();
	virtual ~M_PSA_SetExtAtten();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetIntPreampOff ����Ƶ����Ԥ��״̬
class M_PSA_SetIntPreampOff:public BaseMethod
{
public:
	M_PSA_SetIntPreampOff();
	virtual ~M_PSA_SetIntPreampOff();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetLevelRange ����Ƶ����Y����ʾ��ƽ��Χ
class M_PSA_SetLevelRange:public BaseMethod
{
public:
	M_PSA_SetLevelRange();
	virtual ~M_PSA_SetLevelRange();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetAverCount ����Ƶ����ƽ������
class M_PSA_SetAverCount:public BaseMethod
{
public:
	M_PSA_SetAverCount();
	virtual ~M_PSA_SetAverCount();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetAverType ����Ƶ����ƽ������
class M_PSA_SetAverType:public BaseMethod
{
public:
	M_PSA_SetAverType();
	virtual ~M_PSA_SetAverType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetAverState ����Ƶ����ƽ��״̬
class M_PSA_SetAverState:public BaseMethod
{
public:
	M_PSA_SetAverState();
	virtual ~M_PSA_SetAverState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetRBW ����Ƶ����RBWֵ
class M_PSA_SetRBW:public BaseMethod
{
public:
	M_PSA_SetRBW();
	virtual ~M_PSA_SetRBW();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetVBW ����Ƶ����VBWֵ
class M_PSA_SetVBW:public BaseMethod
{
public:
	M_PSA_SetVBW();
	virtual ~M_PSA_SetVBW();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetDetectorMode ����Ƶ���Ǽ첨ģʽ
class M_PSA_SetDetectorMode:public BaseMethod
{
public:
	M_PSA_SetDetectorMode();
	virtual ~M_PSA_SetDetectorMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetSweepTime ����Ƶ����ɨ��ʱ��
class M_PSA_SetSweepTime:public BaseMethod
{
public:
	M_PSA_SetSweepTime();
	virtual ~M_PSA_SetSweepTime();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetAUTOSweepTime ����Ƶ�����Զ�ɨ��״̬
class M_PSA_SetAUTOSweepTime:public BaseMethod
{
public:
	M_PSA_SetAUTOSweepTime();
	virtual ~M_PSA_SetAUTOSweepTime();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetSweepTimeMode ����Ƶ����ɨ��ģʽ
class M_PSA_SetSweepTimeMode:public BaseMethod
{
public:
	M_PSA_SetSweepTimeMode();
	virtual ~M_PSA_SetSweepTimeMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetTraceMaxHold ����Ƶ����ΪMAX HOLDģʽ
class M_PSA_SetTraceMaxHold:public BaseMethod
{
public:
	M_PSA_SetTraceMaxHold();
	virtual ~M_PSA_SetTraceMaxHold();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetTraceMinHold ����Ƶ����ΪMIN HOLDģʽ
class M_PSA_SetTraceMinHold:public BaseMethod
{
public:
	M_PSA_SetTraceMinHold();
	virtual ~M_PSA_SetTraceMinHold();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_SetTraceClearWrite ����Ƶ����ΪCleat writeģʽ
class M_PSA_SetTraceClearWrite:public BaseMethod
{
public:
	M_PSA_SetTraceClearWrite();
	virtual ~M_PSA_SetTraceClearWrite();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_Gettracedata ����������������
class M_PSA_GetTraceData:public BaseMethod
{
public:
	M_PSA_GetTraceData();
	virtual ~M_PSA_GetTraceData();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara;
};

//M_PSA_SetTrigSource ����Ƶ���Ǵ���Դ
class M_PSA_SetTrigSource:public BaseMethod
{
public:
	M_PSA_SetTrigSource();
	virtual ~M_PSA_SetTrigSource();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMarkMax ����Ƶ�������MARKER��
class M_PSA_SetMarkMax:public BaseMethod
{
public:
	M_PSA_SetMarkMax();
	virtual ~M_PSA_SetMarkMax();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMarkMin ����Ƶ������СMARKER��
class M_PSA_SetMarkMin:public BaseMethod
{
public:
	M_PSA_SetMarkMin();
	virtual ~M_PSA_SetMarkMin();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMaxNext ����Ƶ������һ���MARKER��
class M_PSA_SetMaxNext:public BaseMethod
{
public:
	M_PSA_SetMaxNext();
	virtual ~M_PSA_SetMaxNext();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMarkState ����Ƶ����MARKER���״̬
class M_PSA_SetMarkState:public BaseMethod
{
public:
	M_PSA_SetMarkState();
	virtual ~M_PSA_SetMarkState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMarkPosition ����Ƶ����MARKER���Ƶ��
class M_PSA_SetMarkPosition:public BaseMethod
{
public:
	M_PSA_SetMarkPosition();
	virtual ~M_PSA_SetMarkPosition();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_InputPara2;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMarkerMode ����Ƶ����MARKER���ģʽ
class M_PSA_SetMarkerMode:public BaseMethod
{
public:
	M_PSA_SetMarkerMode();
	virtual ~M_PSA_SetMarkerMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_InputPara2;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_GetMarkValue ��ȡƵ����MARKER���ֵ
class M_PSA_GetMarkValue:public BaseMethod 
{
public:
	M_PSA_GetMarkValue();
	virtual ~M_PSA_GetMarkValue();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
	TParamSetStruct m_InputDeviceName;
};
/*
//M_PSA_SetTDPWRMODE ����Ƶ����ΪTD����ģʽ
class M_PSA_SetTDPWRMODE:public BaseMethod
{
public:
	M_PSA_SetTDPWRMODE();
	virtual ~M_PSA_SetTDPWRMODE();
	virtual int Init(void);
	virtual int Run(void);
};
*/
//M_PSA_SetTDPOWSLOT ����Ƶ����TD����ģʽ�µĲ���ʱ϶
class M_PSA_SetTDPOWSLOT:public BaseMethod
{
public:
	M_PSA_SetTDPOWSLOT();
	virtual ~M_PSA_SetTDPOWSLOT();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
/*
//M_PSA_SetTDMODMODE ����Ƶ����ΪTD���ģʽ
class M_PSA_SetTDMODMODE:public BaseMethod
{
public:
	M_PSA_SetTDMODMODE();
	virtual ~M_PSA_SetTDMODMODE();
	virtual int Init(void);
	virtual int Run(void);
};
*/
//M_PSA_GetEVMandPCDE ��ȡƵ����TD���ģʽ�µ�ʱ϶����ֵ
class M_PSA_GetEVMandPCDE:public BaseMethod
{
public:
	M_PSA_GetEVMandPCDE();
	virtual ~M_PSA_GetEVMandPCDE();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara1;
	TParamSetStruct m_OutputPara2;
	TParamSetStruct m_InputDeviceName;
};

//M_PSA_SetSPECMODE ����Ƶ����ΪƵ��ģʽ
class M_PSA_SetSPECMODE:public BaseMethod 
{
public:
	M_PSA_SetSPECMODE();
	virtual ~M_PSA_SetSPECMODE();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetStarandStopFreq ����Ƶ������ֹƵ��
class M_PSA_SetStarandStopFreq:public BaseMethod
{
public:
	M_PSA_SetStarandStopFreq();
	virtual ~M_PSA_SetStarandStopFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMULACPRMeas ����Ƶ����Ϊ���ز�����ģʽ
class M_PSA_SetMULACPRMeas:public BaseMethod
{
public:
	M_PSA_SetMULACPRMeas();
	virtual ~M_PSA_SetMULACPRMeas();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;

};
//M_PSA_SetMCCOUNT ����Ƶ�����ز���
class M_PSA_SetMCCOUNT:public BaseMethod
{
public:
	M_PSA_SetMCCOUNT();
	virtual ~M_PSA_SetMCCOUNT();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_GetMULACPR ��ȡƵ�����ڶ��ز�ģʽ�µ����в���ֵ
class M_PSA_GetMULACPR:public BaseMethod
{
public:
	M_PSA_GetMULACPR();
	virtual ~M_PSA_GetMULACPR();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara[5];
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetMCPAVER ����Ƶ�����ڶ��ز�ģʽ�µ�ƽ������
class M_PSA_SetMCPAVER:public BaseMethod
{
public:
	M_PSA_SetMCPAVER();
	virtual ~M_PSA_SetMCPAVER();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetSEMMeas ����Ƶ����ΪƵ�׷���ģ�����ģʽ
class M_PSA_SetSEMMeas:public BaseMethod
{
public:
	M_PSA_SetSEMMeas();
	virtual ~M_PSA_SetSEMMeas();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetInitSEM ��ʼ��ƵƵ��Ƶ�׷���ģ�����
class M_PSA_SetInitSEM:public BaseMethod
{
public:
	M_PSA_SetInitSEM();
	virtual ~M_PSA_SetInitSEM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetSEMAverageEnable ����Ƶ����Ƶ�׷���ģ��ģʽ��ƽ��״̬
class M_PSA_SetSEMAverageEnable:public BaseMethod
{
public:
	M_PSA_SetSEMAverageEnable();
	virtual ~M_PSA_SetSEMAverageEnable();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetSEMLimits ����Ƶ����Ƶ�׷���ģ������
class M_PSA_SetSEMLimits:public BaseMethod
{
public:
	M_PSA_SetSEMLimits();
	virtual ~M_PSA_SetSEMLimits();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_GetSEM ���Ƶ����Ƶ�׷���ģ�����ģʽ�µĲ���ֵ
class M_PSA_GetSEM:public BaseMethod
{
public:
	M_PSA_GetSEM();
	virtual ~M_PSA_GetSEM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetEVMMeas ����Ƶ����ΪEVM��PCDE����ģʽ
class M_PSA_SetEVMMeas:public BaseMethod
{
public:
	M_PSA_SetEVMMeas();
	virtual ~M_PSA_SetEVMMeas();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;

};
//M_PSA_SetEVMSlot ����Ƶ����EVM��PCDEģʽ�µ�ʱ϶ֵ
class M_PSA_SetEVMSlot:public BaseMethod
{
public:
	M_PSA_SetEVMSlot();
	virtual ~M_PSA_SetEVMSlot();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetInitEVM ��ʼ��Ƶ����EVM��PCDE����ģʽ
class M_PSA_SetInitEVM:public BaseMethod
{
public:
	M_PSA_SetInitEVM();
	virtual ~M_PSA_SetInitEVM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;

};
/*
//M_PSA_GetEVM ��ȡƵ����EVM��PCDEģʽ�µ�EVMֵ
class M_PSA_GetEVM:public BaseMethod
{
public:
	M_PSA_GetEVM();
	virtual ~M_PSA_GetEVM();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara;
};
//M_PSA_GetPCDE ��ȡƵ����EVM��PCDEģʽ�µ�PCDEֵ
class M_PSA_GetPCDE:public BaseMethod
{
public:
	M_PSA_GetPCDE();
	virtual ~M_PSA_GetPCDE();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara;
};
*/

//M_PSA_SetSyncType ����Ƶ����EVM��PCDEģʽ�µ�ͬ������
class M_PSA_SetSyncType:public BaseMethod
{
public:
	M_PSA_SetSyncType();
	virtual ~M_PSA_SetSyncType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetTOI ����Ƶ����Ϊ���׽�������ģʽ
class M_PSA_SetTOI:public BaseMethod
{
public:
	M_PSA_SetTOI();
	virtual ~M_PSA_SetTOI();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_GetTOI ���Ƶ�������׽���ģʽ�µĲ���ֵ
class M_PSA_GetTOI:public BaseMethod
{
public:
	M_PSA_GetTOI();
	virtual ~M_PSA_GetTOI();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara[4];
	TParamSetStruct m_InputDeviceName;
};
/*
//M_PSA_SetTOIAVGState ����Ƶ�������׽���ģʽ�µ�ƽ��״̬
class M_PSA_SetTOIAVGState:public BaseMethod
{
public:
	M_PSA_SetTOIAVGState();
	virtual ~M_PSA_SetTOIAVGState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
};
*/

//M_PSA_SetPVTMeas ����Ƶ����Ϊʱ�俪��ģ�����ģʽ
class M_PSA_SetPVTMeas:public BaseMethod
{
public:
	M_PSA_SetPVTMeas();
	virtual ~M_PSA_SetPVTMeas();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetInitPVT ����һ��ʱ�俪��ģ�����
class M_PSA_SetInitPVT:public BaseMethod
{
public:
	M_PSA_SetInitPVT();
	virtual ~M_PSA_SetInitPVT();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	
};
//M_PSA_GetPVT ��ȡƵ����ʱ�俪��ģ��ģʽ�Ĺ���ֵ
class M_PSA_GetPVT:public BaseMethod
{
public:
	M_PSA_GetPVT();
	virtual ~M_PSA_GetPVT();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetPVTAverageEnable ����Ƶ����ʱ�俪��ģ��ģʽ��ƽ����״̬
class M_PSA_SetPVTAverageEnable:public BaseMethod
{
public:
	M_PSA_SetPVTAverageEnable();
	virtual ~M_PSA_SetPVTAverageEnable();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;	
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetPVTMEASTimes ����Ƶ����ʱ�俪��ģ��ģʽ�µĲ�������
class M_PSA_SetPVTMEASTimes:public BaseMethod
{
public:
	M_PSA_SetPVTMEASTimes();
	virtual ~M_PSA_SetPVTMEASTimes();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetACPMeas ����Ƶ����Ϊ���ز�����ģʽ��
class M_PSA_SetACPMeas:public BaseMethod
{
public:
	M_PSA_SetACPMeas();
	virtual ~M_PSA_SetACPMeas();
	virtual int Init(void);
	virtual int Run(void);
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_GetACP ��ȡƵ���ǵ��ز�ģʽ�¸��Ĳ�������ֵ
class M_PSA_GetACP:public BaseMethod
{
public:
	M_PSA_GetACP();
	virtual ~M_PSA_GetACP();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara[5];
	
};
/*
//M_PSA_SetWindow ����Ƶ���ǵ���ʾ����
class M_PSA_SetWindow:public BaseMethod
{
public:
	M_PSA_SetWindow();
	virtual ~M_PSA_SetWindow();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
};
*/

//M_PSA_SetTrigDelayTime ����Ƶ���Ǵ����ӳ�ʱ��
class M_PSA_SetTrigDelayTime:public BaseMethod
{
public:
	M_PSA_SetTrigDelayTime();
	virtual ~M_PSA_SetTrigDelayTime();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_M_PSA_SetTraceAverage �����ټ�Ϊƽ����ֵ��ʽ
class M_PSA_SetTraceAverage:public BaseMethod
{
public:
	M_PSA_SetTraceAverage();
	virtual ~M_PSA_SetTraceAverage();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetEVMAver	����EVM��PCDEģʽ�µ�ƽ��״̬��ƽ������
class M_PSA_SetEVMAver:public BaseMethod
{
public:
	M_PSA_SetEVMAver();
	virtual ~M_PSA_SetEVMAver();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1,m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetFilterType	����Ƶ����Ϸ�ʽ
class M_PSA_SetFilterType:public BaseMethod
{
public:
	M_PSA_SetFilterType();
	virtual ~M_PSA_SetFilterType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
//M_PSA_SetScrambleCode ����EVM��PCDEģʽ�µ�����
class M_PSA_SetScrambleCode:public BaseMethod
{
public:
	M_PSA_SetScrambleCode();
	virtual ~M_PSA_SetScrambleCode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

//M_PSA_GetFluctuate ��ȡָ��������Χ�ڵĲ���
class M_PSA_GetFluctuate:public BaseMethod
{
public:
	M_PSA_GetFluctuate();
	virtual ~M_PSA_GetFluctuate();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_OutputPara;
	TParamSetStruct m_InputDeviceName;
};

//M_PSA_SetMarkTime ����Ƶ������ʱ����MARKER���λ��
class M_PSA_SetMarkTime:public BaseMethod
{
public:
	M_PSA_SetMarkTime();
	virtual ~M_PSA_SetMarkTime();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_InputPara2;	
	TParamSetStruct m_InputDeviceName;
};
//class M_PSA_SetSweepEgatePolarity �����ⲿ���źż���
class M_PSA_SetSweepEgatePolarity:public BaseMethod
{
public:
	M_PSA_SetSweepEgatePolarity();
	virtual ~M_PSA_SetSweepEgatePolarity();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_InputDeviceName;
};
//class M_PSA_SetSweepEgateLength ������ɨ����Чʱ�� (��λ:ms)
class M_PSA_SetSweepEgateLength:public BaseMethod
{
public:
	M_PSA_SetSweepEgateLength();
	virtual ~M_PSA_SetSweepEgateLength();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_InputDeviceName;
};

//class M_PSA_SetTrigLevel �����ⲿ������ƽ(-5V ~ 5V)
class M_PSA_SetTrigLevel:public BaseMethod
{
public:
	M_PSA_SetTrigLevel();
	virtual ~M_PSA_SetTrigLevel();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;		
};
//M_PSA_SetStartAndStopSlot ����ACPģʽ����ֹʱ϶
class M_PSA_SetStartAndStopSlot:public BaseMethod
{
public:
	M_PSA_SetStartAndStopSlot();
	virtual ~M_PSA_SetStartAndStopSlot();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;		
};
//����Ƶ���ǵĲ���ģʽ(0:SA 1:TDSCDMA_ACP 2:TDSCDMA_MCP 3:TDSCDMA_SEM 4:TDSCDMA_EVM 5:SA_Harmonic 6:SA_CCDF 7:SA_ACP|MCP 8:SA_Channel Power 9:SA_Burst Power)
class M_PSA_SetMeasMode:public BaseMethod
{
public:
	M_PSA_SetMeasMode();
	virtual ~M_PSA_SetMeasMode();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;		
};
//��ȡSA_CCDFģʽ�µĲ���ֵ
class M_PSA_GetPST:public BaseMethod
{
public:
	M_PSA_GetPST();
	virtual ~M_PSA_GetPST();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara[10];		
};

//��ȡSA_Harmonicģʽ�µĲ���ֵ(dBm)(HarmonicNum:(0~10)  0:����г��ֵ)
class M_PSA_GetHarmonic:public BaseMethod
{
public:
	M_PSA_GetHarmonic();
	virtual ~M_PSA_GetHarmonic();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara[10];		
};

/*
//����Offset\Limit����(0:SA 1:WCDMA 2:C2K 3:WIMAX OFDMA 4:TD-SCDMA 5:1xEVDO)
class M_PSA_SetOffsetLimitType:public BaseMethod
{
public:
	M_PSA_SetOffsetLimitType();
	virtual ~M_PSA_SetOffsetLimitType();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};
*/

//�����ز����
class M_PSA_SetCarrierSpaceList:public BaseMethod
{
public:
	M_PSA_SetCarrierSpaceList();
	virtual ~M_PSA_SetCarrierSpaceList();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

//����Offset Freqence�б�(MHz)
class M_PSA_SetOffsetFreqList:public BaseMethod
{
public:
	M_PSA_SetOffsetFreqList();
	virtual ~M_PSA_SetOffsetFreqList();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

//����Offset Freqence�б�״̬(0:Off 1:On)
class M_PSA_SetOffsetFreqState:public BaseMethod
{
public:
	M_PSA_SetOffsetFreqState();
	virtual ~M_PSA_SetOffsetFreqState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};

//����Offset Integ BW�б�(KHz)
class M_PSA_SetOffsetIBWList:public BaseMethod
{
public:
	M_PSA_SetOffsetIBWList();
	virtual ~M_PSA_SetOffsetIBWList();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;

};

//����Gate View״̬(0:Off 1:On)
class M_PSA_SetGateViewState:public BaseMethod
{
public:
	M_PSA_SetGateViewState();
	virtual ~M_PSA_SetGateViewState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//����ɨ��Gate Delay(ms)
class M_PSA_SetSweepEgatDelay:public BaseMethod
{
public:
	M_PSA_SetSweepEgatDelay();
	virtual ~M_PSA_SetSweepEgatDelay();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//������������״̬(0: Off 1:On)
class M_PSA_SetNoiseCorrState:public BaseMethod
{
public:
	M_PSA_SetNoiseCorrState();
	virtual ~M_PSA_SetNoiseCorrState();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_PSA_SetMeasNoiseBW ����Measurement Noise Bandwidth(MHz)
class M_PSA_SetMeasNoiseBW:public BaseMethod
{
public:
	M_PSA_SetMeasNoiseBW();
	virtual ~M_PSA_SetMeasNoiseBW();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_PSA_SetRefCarrier ���òο��ز�
class M_PSA_SetRefCarrier:public BaseMethod
{
public:
	M_PSA_SetRefCarrier();
	virtual ~M_PSA_SetRefCarrier();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_PSA_SetRefCarrierFreq ���òο��ز�Ƶ��(MHz)
class M_PSA_SetRefCarrierFreq:public BaseMethod
{
public:
	M_PSA_SetRefCarrierFreq();
	virtual ~M_PSA_SetRefCarrierFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_PSA_SendCmd ����ָ��
class M_PSA_SendCmd:public BaseMethod
{
public:
	M_PSA_SendCmd();
	virtual ~M_PSA_SendCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

//class M_PSA_GetCmd ����ָ���ȡָ��ķ�������
class M_PSA_GetCmd:public BaseMethod
{
public:
	M_PSA_GetCmd();
	virtual ~M_PSA_GetCmd();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;
};


//class M_PSA_GetIDN ��ȡ�豸�ͺ���Ϣ
class M_PSA_GetIDN:public BaseMethod
{
public:
	M_PSA_GetIDN();
	virtual ~M_PSA_GetIDN();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

//M_PSA_LoadFile ����״̬�ļ�
class M_PSA_LoadFile:public BaseMethod
{
public:
	M_PSA_LoadFile();
	virtual ~M_PSA_LoadFile();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

//M_PSA_SaveFile �����ļ�
class M_PSA_SaveFile:public BaseMethod
{
public:
	M_PSA_SaveFile();
	virtual ~M_PSA_SaveFile();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;
};

//M_PSA_GetSEMPower ��ȡSEMģʽ�µĹ���ֵ
class M_PSA_GetSEMPower:public BaseMethod
{
public:
	M_PSA_GetSEMPower();
	virtual ~M_PSA_GetSEMPower();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

//M_PSA_GetEVMPower ��ȡEVMģʽ�µĹ���ֵ
class M_PSA_GetEVMPower:public BaseMethod
{
public:
	M_PSA_GetEVMPower();
	virtual ~M_PSA_GetEVMPower();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

//M_PSA_SetSweepPoint ����ɨ�����
class M_PSA_SetSweepPoint:public BaseMethod
{
public:
	M_PSA_SetSweepPoint();
	virtual ~M_PSA_SetSweepPoint();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};


// ��������ʽ�������������ݱ��浽PC�ڴ���
class M_PSA_SaveTraceByName:public BaseMethod
{
public:
	M_PSA_SaveTraceByName();
	virtual ~M_PSA_SaveTraceByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;		
};

// ��������ʽ����PC�ڴ�����(0:Off 1:Trace1/Trace2 2:Trace1*Trace2 3:Trace1-Trace2 4:Trace1+Trace2)
class M_PSA_SetTraceMathTypeByName:public BaseMethod
{
public:
	M_PSA_SetTraceMathTypeByName();
	virtual ~M_PSA_SetTraceMathTypeByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3, m_InputPara4;		
};

// ɾ��һ��PC�ڴ�����
class M_PSA_DeleteTraceByName:public BaseMethod
{
public:
	M_PSA_DeleteTraceByName();
	virtual ~M_PSA_DeleteTraceByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	
};

// ɾ������PC�ڴ�����
class M_PSA_DeleteAllTrace:public BaseMethod
{
public:
	M_PSA_DeleteAllTrace();
	virtual ~M_PSA_DeleteAllTrace();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;	
};

// ��PC�ڴ�����������MARKER �Ĳ��ҷ�Χ(MHz) 
class M_PSA_SetMarkerSearchFreqByName:public BaseMethod
{
public:
	M_PSA_SetMarkerSearchFreqByName();
	virtual ~M_PSA_SetMarkerSearchFreqByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;		
};

// ��PC�ڴ������л�ȡ���ֵ����Сֵ
class M_PSA_GetMarkerValueByName:public BaseMethod
{
public:
	M_PSA_GetMarkerValueByName();
	virtual ~M_PSA_GetMarkerValueByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1, m_OutputPara2;	
};

// ��PC�ڴ������л�ȡָ��������Χ�ڵ�ƽ̹��(MHz) 
class M_PSA_GetFluctuateByName:public BaseMethod
{
public:
	M_PSA_GetFluctuateByName();
	virtual ~M_PSA_GetFluctuateByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2;	
	TParamSetStruct m_OutputPara1;
	
};

// ��PC�ڴ����ݻ�ȡָ��Ƶ�ʵ�Markerֵ
class M_PSA_GetMarkerFreqByName:public BaseMethod
{
public:
	M_PSA_GetMarkerFreqByName();
	virtual ~M_PSA_GetMarkerFreqByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1, m_InputPara2, m_InputPara3;	
	TParamSetStruct m_OutputPara1;	
};

// class M_PSA_GetTraceDataXByName ��PC�ڴ����ݻ�ȡX������
class M_PSA_GetTraceDataXByName:public BaseMethod
{
public:
	M_PSA_GetTraceDataXByName();
	virtual ~M_PSA_GetTraceDataXByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;	
};

// class M_PSA_GetTraceDataYByName ��PC�ڴ����ݻ�ȡY������
class M_PSA_GetTraceDataYByName:public BaseMethod
{
public:
	M_PSA_GetTraceDataYByName();
	virtual ~M_PSA_GetTraceDataYByName();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
	TParamSetStruct m_OutputPara1;	
};

//��ȡɨ��ʱ��ֵ
class M_PSA_GetSweepTime:public BaseMethod
{
public:
	M_PSA_GetSweepTime();
	virtual ~M_PSA_GetSweepTime();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

//��ȡ�����ӳ�ʱ��
class M_PSA_GetTrigDelayTime:public BaseMethod
{
public:
	M_PSA_GetTrigDelayTime();
	virtual ~M_PSA_GetTrigDelayTime();
	virtual int Init(void);
	virtual int Run(void);

protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;	
};

// ���ô�������(0:Positive 1:Negative)
class M_PSA_SetTrigPolarity:public BaseMethod
{
public:
	M_PSA_SetTrigPolarity();
	virtual ~M_PSA_SetTrigPolarity();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;	
};

// ��ȡ�豸�Ĳ�������
class M_PSA_ReadDev:public BaseMethod
{
public:
	M_PSA_ReadDev();
	virtual ~M_PSA_ReadDev();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1;	
};

// ����һ�β���
class M_PSA_SetTrigOnce:public BaseMethod
{
public:
	M_PSA_SetTrigOnce();
	virtual ~M_PSA_SetTrigOnce();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
};

// ���²���һ��
class M_PSA_Restart:public BaseMethod
{
public:
	M_PSA_Restart();
	virtual ~M_PSA_Restart();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
};

//����Offset Abs
class M_PSA_SetOffsetAbsList:public BaseMethod
{
public:
	M_PSA_SetOffsetAbsList();
	virtual ~M_PSA_SetOffsetAbsList();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara1;
};
 

//����Egat State
class M_PSA_SetEgatState:public BaseMethod
{
public:
	M_PSA_SetEgatState();
	virtual ~M_PSA_SetEgatState();
	virtual int Init(void);
	virtual int Run(void);
	
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara;
};

 
// ��ȡOBWֵ
class M_PSA_GetOBW:public BaseMethod
{
public:
	M_PSA_GetOBW();
	virtual ~M_PSA_GetOBW();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara;
	TParamSetStruct m_InputDeviceName;
};
  

// ����Span
class M_PSA_SetSpan:public BaseMethod
{
public:
	M_PSA_SetSpan();
	virtual ~M_PSA_SetSpan();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};
  
// �����Զ���ƽ
class M_PSA_RefLevelAuto:public BaseMethod
{
public:
	M_PSA_RefLevelAuto();
	virtual ~M_PSA_RefLevelAuto();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

// ����ACLRģʽ
class M_PSA_SetACLRMEAS:public BaseMethod
{
public:
	M_PSA_SetACLRMEAS();
	virtual ~M_PSA_SetACLRMEAS();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

// ����ACLRģʽTX����
class M_PSA_SetACPTXBW:public BaseMethod
{
public:
	M_PSA_SetACPTXBW();
	virtual ~M_PSA_SetACPTXBW();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara,m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};

// ����ACLRģʽTXCount
class M_PSA_SetACPTXCount:public BaseMethod
{
public:
	M_PSA_SetACPTXCount();
	virtual ~M_PSA_SetACPTXCount();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

// ����TrigSource
class M_PSA_SetTriggerSource:public BaseMethod
{
public:
	M_PSA_SetTriggerSource();
	virtual ~M_PSA_SetTriggerSource();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

// ����TrigLevel
class M_PSA_SetTriggerLevel:public BaseMethod
{
public:
	M_PSA_SetTriggerLevel();
	virtual ~M_PSA_SetTriggerLevel();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara, m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};

// ����GateTrigSwitch
class M_PSA_SetGateTrigSwitch:public BaseMethod
{
public:
	M_PSA_SetGateTrigSwitch();
	virtual ~M_PSA_SetGateTrigSwitch();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

//����GateDelay
class M_PSA_SetGateDelay:public BaseMethod
{
public:
	M_PSA_SetGateDelay();
	virtual ~M_PSA_SetGateDelay();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

//����GateLength
class M_PSA_SetGateLength:public BaseMethod
{
public:
	M_PSA_SetGateLength();
	virtual ~M_PSA_SetGateLength();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

//��ȡACLRֵ
class M_PSA_GetACLR:public BaseMethod
{
public:
	M_PSA_GetACLR();
	virtual ~M_PSA_GetACLR();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_OutputPara1;
};

//����Ƶ����ΪVSAģʽ
class M_PSA_SetVSAMODE:public BaseMethod 
{
public:
	M_PSA_SetVSAMODE();
	virtual ~M_PSA_SetVSAMODE();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//����Ƶ����ΪPULSEģʽ
class M_PSA_SetPULSEMODE:public BaseMethod 
{
public:
	M_PSA_SetPULSEMODE();
	virtual ~M_PSA_SetPULSEMODE();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//����OBWPowerBandWidth
class M_PSA_SetOBWPOWERBW:public BaseMethod
{
public:
	M_PSA_SetOBWPOWERBW();
	virtual ~M_PSA_SetOBWPOWERBW();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

//���VSAģʽ�µ�EVMֵ
class M_PSA_GetEVMValue:public BaseMethod
{
public:
	M_PSA_GetEVMValue();
	virtual ~M_PSA_GetEVMValue();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara1,m_OutputPara2,m_OutputPara3,m_OutputPara4,m_OutputPara5,m_OutputPara6;
	TParamSetStruct m_InputDeviceName;
};


//���PULSEģʽ�µ�ֵ
class M_PSA_GetPULSEValue:public BaseMethod
{
public:
	M_PSA_GetPULSEValue();
	virtual ~M_PSA_GetPULSEValue();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara1,m_OutputPara2;
	TParamSetStruct m_InputDeviceName;
};

//����SignCountFunction
class M_PSA_SetSignCountFunc:public BaseMethod 
{
public:
	M_PSA_SetSignCountFunc();
	virtual ~M_PSA_SetSignCountFunc();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
};

//��ȡMark��Ƶ��
class M_PSA_GetMarkFreq:public BaseMethod 
{
public:
	M_PSA_GetMarkFreq();
	virtual ~M_PSA_GetMarkFreq();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara1;
	TParamSetStruct m_OutputPara1;
	TParamSetStruct m_InputDeviceName;
};

//����TriggerOffSet
class M_PSA_SetTriggerOffSet:public BaseMethod 
{
public:
	M_PSA_SetTriggerOffSet();
	virtual ~M_PSA_SetTriggerOffSet();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};

//����Timing������ʾ
class M_PSA_SetTimingPara:public BaseMethod 
{
public:
	M_PSA_SetTimingPara();
	virtual ~M_PSA_SetTimingPara();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara, m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};


//����Transmit Filter
class M_PSA_SetTransFilter:public BaseMethod 
{
public:
	M_PSA_SetTransFilter();
	virtual ~M_PSA_SetTransFilter();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara, m_InputPara2;
	TParamSetStruct m_InputDeviceName;
};

//����ModulationSetting
class M_PSA_SetModulation:public BaseMethod 
{
public:
	M_PSA_SetModulation();
	virtual ~M_PSA_SetModulation();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara, m_InputPara2, m_InputPara3, m_InputPara4;
	TParamSetStruct m_InputDeviceName;
};

//����CaptureLengthAuto
class M_PSA_SetCaptureLengthAuto:public BaseMethod 
{
public:
	M_PSA_SetCaptureLengthAuto();
	virtual ~M_PSA_SetCaptureLengthAuto();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputPara;
	TParamSetStruct m_InputDeviceName;
};



//��ȡPulseNumberֵ
class M_PSA_GetPULSENumber:public BaseMethod 
{
public:
	M_PSA_GetPULSENumber();
	virtual ~M_PSA_GetPULSENumber();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_OutputPara1;
	TParamSetStruct m_InputDeviceName;
};