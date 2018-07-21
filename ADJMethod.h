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
* 版本：2.0.0.45
* 作者：dolby.jiang
* 完成日期：2009年10月10日
* 更改：
*
************************************************************************/



/************************************************************************/
/*  EEPROM校准驱动程序方法类                                                                    */
/************************************************************************/
//M_ADJ_WriteCal 写校准
class M_ADJ_WriteCal:public BaseMethod
{
public:
	M_ADJ_WriteCal();
	virtual ~M_ADJ_WriteCal();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;
	TParamSetStruct m_InputPara[4];
	TParamSetStruct m_OutputPara1,m_OutputPara2,m_OutputPara3;

};
//M_ADJ_ReadCal 读校准
class M_ADJ_ReadCal:public BaseMethod
{
public:
	M_ADJ_ReadCal();
	virtual ~M_ADJ_ReadCal();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;	
	TParamSetStruct m_OutputPara1,m_OutputPara2,m_OutputPara3;
};
//M_ADJ_GetClientSNRelate 获取产品的客户SN与校准数据是否有关系(0:无  1:有)
class M_ADJ_GetClientSNRelate:public BaseMethod
{
public:
	M_ADJ_GetClientSNRelate();
	virtual ~M_ADJ_GetClientSNRelate();
	virtual int Init(void);
	virtual int Run(void);
protected:
	TParamSetStruct m_InputDeviceName;	
	TParamSetStruct m_OutputPara1;
};