#pragma warning( disable : 4786)

#include <windows.h>
//#include <Vector>
//#include <map>
//#include <string>
//#include <algorithm>

#include "Method.h"
#include "NTSDin.h"



/************************************************************************
* �汾��2.0.0.45
* ���ߣ�dolby.jiang
* ������ڣ�2009��10��10��
* ���ģ�����
*		M_SPE_IntToString ����������ת�����ַ���
*		M_SPE_FloatToString �Ѹ���������ת�����ַ���
*		M_SPE_GetConditionData ��ȡָ����Χ�ڵ�����
*		M_SPE_GetMaxPosition ��ȡMaxֵ��λ��
*		M_SPE_StrCat �ַ�������
*
************************************************************************/

/************************************************************************
* �汾��2.1.0.0
* ���ߣ�dolby.jiang
* ������ڣ�2009��10��13��
* ���ģ�����M_SPE_GetMinPosition ��ȡMinֵ��λ��
*
************************************************************************/


/************************************************************************
* �汾��2.1.0.0
* ���ߣ�dolby.jiang
* ������ڣ�2009��10��13��
* ���ģ��޸�M_SPE_SpectrumPowerDebugEx
*
************************************************************************/

/************************************************************************
* �汾��2.1.0.7
* ���ߣ�dolby.jiang
* ������ڣ�2010��1��18��
* ���ģ��޸�M_SPE_OpenDev
*
************************************************************************/


/************************************************************************
* �汾��2.1.0.9
* ���ߣ�dolby.jiang
* ������ڣ�2010��3��25��
* ���ģ����� SPE_GetIDN
*
************************************************************************/


/************************************************************************
* �汾��3.0.2.2
* ���ߣ�dolby.jiang
* ������ڣ�2010��11��20��
* ���ģ�	
	1) ���� M_NTS_SetCom ���ô���ͨѶ����	
	2) ���� M_NTS_SetDTR ����RTS(�����ն˾���)��־  Ӳ�������� 0:Low 1:Hight
	3) ���� M_NTS_SetRTS ����RTS(�����������ݷ���)��־  Ӳ�������� 0:Low 1:Hight
	4) ���� M_NTS_SetXOFF ����XOFF(����������ֹͣ����)��־ ���������
	5) ���� M_NTS_SetXON ����XON(���������ݼ�������)��־ ���������
	6) ���� M_SPE_WriteDev ���Զ����豸д����
	7) ���� M_SPE_ReadDev ���Զ����豸��ȡ����
	8) ���� M_SPE_QueryDev ��ѯ
*
************************************************************************/

/************************************************************************
* �汾��3.0.2.18
* ���ߣ�dolby.jiang
* ������ڣ�2011��11��20��
* ���ģ�	
	1) ���� M_SPE_SprintfDev ���Զ����豸д�ַ�������
	2) ���� M_SPE_SetAttribute  ����ͨ�����Բ���
*
************************************************************************/

/************************************************************************
* �汾��3.0.2.25
* ���ߣ�dolby.jiang
* ������ڣ�2011��11��20��
* ���ģ�	
	1) ���� M_SPE_AgePowerOn �ڵ��ϵ�
	2) ���� M_SPE_AgePowerOff �ڵ�ص�
	3) ���� M_SPE_AgeRead ��ȡ����
*
************************************************************************/

/************************************************************************
* �汾��3.0.2.29
* ���ߣ�dolby.jiang
* ������ڣ�2021��12��12��
* ���ģ�	
	1) ���� M_SPE_SetIOPortVal 
	2) ���� M_SPE_GetIOPortVal
*
************************************************************************/

/************************************************************************/
/*  ���⹦�ܺ���������                                                  */
/************************************************************************/
//class M_SPE_Pause ϵͳֹͣ
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
//class M_SPE_SetDelayTime ϵͳ��ʱ
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
//class M_SPE_ACPRPowerDebug ACPR���ʵ���
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
//class M_SPE_GetTimeSwitch ����ʱ�����
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
//class M_SPE_ACPPowerDebug ACP���ʵ���
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
//class M_SPE_SEMPowerDebug SEM���ʵ���
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
//class M_SPE_EVMandPCDEPowerDebug EVM��PCDE���ʵ���
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
//class M_SPE_Add �������
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
//class M_SPE_Subtract	�������
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
//class M_SPE_Multiply	�������
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
//class M_SPE_Divide �������
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
//class M_SPE_Compare �Ƚ�
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
//class M_SPE_Equal ��ֵ
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
//class M_SPE_Absolute ����ֵ
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
//class M_SPE_SpectrumPowerDebug Ƶ��ģʽ���ʵ���
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
//class M_SPE_ACPRDebug ACPR����
class M_SPE_ACPRDebug:public BaseMethod
{
public:
	M_SPE_ACPRDebug();
	virtual ~M_SPE_ACPRDebug();
	virtual int Init(void);
	virtual int Run(void);
private:
	typedef short int (_stdcall _ACPRDebug)(
		short int ,		//ģ����
		short int ,		//�������ں�
		short int ,		//�ź�Դ���	
		short int ,		//Ƶ���Ǿ��
		short,			//ͨ����
		float ,			//ģ������
		float ,			//�ź�Դ�����޷���ֵ
		int ,			//��ȡƵ���ǵļ��ʱ��(ms)
		float ,			//1.6MHz APCR����ָ��
		float, 			//3.2MHz APCR����ָ��
		float			//������Χ
		);	

	_ACPRDebug *ACPRDebug;
protected:
	TParamSetStruct m_SGDevName,m_PSADevName, m_NTSDevName;
	TParamSetStruct m_InputPara[9];	
};	

//class M_SPE_ShowDialog ����Ի���
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

//class M_SPE_SpectrumPowerDebugEx Ƶ��ģʽ���ʵ���
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

//class M_SPE_ACPRPowerDebugEx ACPR���ʵ���
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

//class M_SPE_GetUpTimeSwitch ��ȡ������ʱ��������ӳ�ʱ��
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
//class M_SPE_GetDownTimeSwitch ��ȡ�½���ʱ����½��ӳ�ʱ��
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

//class M_SPE_ShowPromptDialog ��ʾԤ����Ի���
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
//class M_SPE_SetLastDAOffset	�޸�ָ���¶ȷ�Χ��ĩ��DA��ƫ����
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
//class M_SPE_SetAutoACPR	ACPR�Զ�����
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

//class M_SPE_CompareA �Ƚ�
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

//class M_SPE_Power ĳ�����Ķ��ٴη�
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

//class M_SPE_DevReset	������λ
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

//class M_SPE_PRMPowerDebug ���ʼ��¹��ʵ���
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

//M_SPE_SeparateData �����ض��ַ������ַ���������ȡָ��λ�õ�����
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

//M_SPE_IntToString ����������ת�����ַ���
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

//M_SPE_FloatToString �Ѹ���������ת�����ַ���
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

//M_SPE_GetConditionData ��ȡָ����Χ�ڵ�����
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

//M_SPE_GetMaxPosition ��ȡMaxֵ��λ��
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

//M_SPE_GetMinPosition ��ȡMinֵ��λ��
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

//M_SPE_StrCat �ַ�������
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

//M_SPE_GainDebugWithENA ������������¸ı书��DAֵ�����Բ�Ʒ������
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

//M_SPE_OpenDev ���豸
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
	
//M_SPE_CloseDev �ر��豸
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
// M_SPE_SetBufSize ���û���������(Mask 0:ALL 1:Tx_Buffer 2:Rx_Buffer)
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

// M_SPE_ClearBuf ���������(Mask 0:ALL 1:Tx_Buffer 2:Rx_Buffer)
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

// M_SPE_WriteDev ���Զ����豸д����
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

// M_SPE_ReadDev ���Զ����豸��ȡ����
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

// M_SPE_QueryDev ��ѯ
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

// M_SPE_SprintfDev ���Զ����豸д������(�ַ���)
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
// M_SPE_ScanfDev ���Զ����豸��ȡ����
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

// M_SPES_SetCom ����ComͨѶ����
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

// M_SPE_SetDTR ����RTS(�����ն˾���)��־  Ӳ�������� 0:Low 1:Hight
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

//M_SPE_SetRTS ����RTS(�����������ݷ���)��־  Ӳ�������� 0:Low 1:Hight
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

// M_SPE_SetXOFF ����XOFF(����������ֹͣ����)��־ ���������
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
// M_SPE_SetXON ����XON(���������ݼ�������)��־ ���������
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

//M_SPE_PolyFit ����ʽ���
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

	//��ȡa��n�η�
	virtual double pow_n(double	a, int n);
	
	//
	int mutiple(double a[][PARALENGTH], double b[][T+1], double c[][T+1], int Count, int N);

	//�������б任
	int matrix_trans(double a[][T+1], double b[][PARALENGTH], int Count, int N);

	//���ϵ����չ����
	int get_A(double matrix_A[][T+1], double x_y[][2], int Count, int N);

	//���ø�˹��Ԫ���������
	//arguA:�������
	//N:����
	int convert(double argu[][T+2], int N) ;

	int compute(double argu[][T+2], int N, double root[]);

	//���Yֵ	
	int get_y(double trans_A[][PARALENGTH], double x_y[][2], double y[],int Count, int N) ;

	//׷��Y��ֵ����������
	int cons_formula(double coef_A[][T+1], double y[], double coef_form[][T+2], int N);

	//���õݹ�������ʽ��ֵ A:����ʽ N:����	
	virtual double  ComputeMatrix(double *A,int N);
};			

// M_SPE_GetIDN ��ȡ�豸������Ϣ
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

//M_SPE_FFT FFT�㷨
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
	
	//������ת���� N:��������
	ComplexStruct Wn(int N, int n);

	//�����ӷ���out=a+b
	ComplexStruct add(ComplexStruct a, ComplexStruct b);

	//����������out=a-b
	ComplexStruct sub(ComplexStruct a, ComplexStruct b);

	//�����˷���out=a*b
	ComplexStruct mul(ComplexStruct a, ComplexStruct b);

	//������ģ��out = a*b
	double mod(ComplexStruct a);

	//������ֵ
	ComplexStruct comcpy(ComplexStruct a);
	
	// ��λ
	int reverse(int n, int j);

	// FFT �㷨 N:��������
	int DoFFT(ComplexStruct *x, ComplexStruct *F, int N);
};	

// M_SPE_GetLastErrStr ��ȡ���������Ϣ
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

// M_SPE_SetAttributeDev  ����ͨ�����Բ���()
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

// M_SPE_AgePowerOn �ڵ��ϵ�
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

// M_SPE_AgePowerOff �ڵ�ص�
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

// M_SPE_AgeRead ��ȡ����
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

// ��I/O��д���� 
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

// ��I/O��ȡ����
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

// ����T/R�����������(Pin2:Data Pin3:CLK Pin4:Lock)
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

// ����IO������ʽ 0:Positive(������) 1:Negative(�½���)
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