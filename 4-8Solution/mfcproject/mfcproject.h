
// mfcproject.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CmfcprojectApp:
// �� Ŭ������ ������ ���ؼ��� mfcproject.cpp�� �����Ͻʽÿ�.
//

class CmfcprojectApp : public CWinApp
{
public:
	CmfcprojectApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CmfcprojectApp theApp;