
// ServoDriverManagerApp.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CServoDriverManagerAppApp: 
// �йش����ʵ�֣������ ServoDriverManagerApp.cpp
//

class CServoDriverManagerAppApp : public CWinApp
{
public:
	CServoDriverManagerAppApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CServoDriverManagerAppApp theApp;