/************************************************************************
* Copyright (c) 2010,芯通科技有限公司
* All rights reserved.
* 文件名称： DGL.h
* 文件标识：reserved
* 摘要：Map/Vector 等泛型数据类型定义
*
************************************************************************/
#include "ConstDin.h"
#include <Vector>
#include <map>
#include <string>

//小数据量vector容器定义
typedef std::vector<TParamSetStruct> TParamSetVector;

//驱动库方法Map容器 key:方法名
typedef std::map<std::string, MethodNameStruct> TMethodMap;

//仪器句柄容器 key:设备连接字符串
typedef std::map<std::string, DeviceInfoStruct> TDeviceManagerMap;
