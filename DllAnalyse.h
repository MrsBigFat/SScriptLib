
/************************************************************************
* Copyright (c) 2009,оͨ�Ƽ����޹�˾
* All rights reserved.
* �ļ����ƣ�
* �ļ���ʶ��reserved
* ժҪ����ȡDLL�ļ��еĺ�����
*
************************************************************************/

/************************************************************************
* �汾��2.0.1.0
* ���ߣ�dolby.jiang
* ������ڣ�2009��8��26��
* ���ģ��ļ�����
*
************************************************************************/

/************************************************************************
* �汾��2.0.1.0
* ���ߣ�dolby.jiang
* ������ڣ�2009��9��30��
* ���ģ�����GetSubStr����
*
************************************************************************/

#ifdef __cplusplus
extern "C" {
#endif
	
	//��ȡDLL�ĺ�������
	void _stdcall AnalysisFunction(const char *szDllName, char **FunctionList, int *Count);
	
	//����_stdcall�����API�����������ͺ�����������
	void _stdcall GetSubStr(const char *SourceStr, char *Substr, int *Count);

#ifdef __cplusplus
}
#endif