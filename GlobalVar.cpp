
#include "stdafx.h"
#include <string>
#include "Method.h"
#include <map>


// ȫ�ֱ�������
BaseMethod *gMethodDev[MAXMETHOD + 1];	// �������
TDeviceManagerMap gDeviceManagerMap;	// �豸���������
BOOL gCommIsStr;						// ͨ�ö�д�������ݷ��ͷ�ʽ True:�ַ���	false:������