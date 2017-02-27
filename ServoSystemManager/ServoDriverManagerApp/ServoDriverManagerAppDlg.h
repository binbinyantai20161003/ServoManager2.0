
// ServoDriverManagerAppDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CServoDriverManagerAppDlg 对话框
class CServoDriverManagerAppDlg : public CDialogEx
{
// 构造
public:
	CServoDriverManagerAppDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_SERVODRIVERMANAGERAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();

public:
	CString m_strPath_IarServo;
	CString m_strPath_IarAddr;
	CString m_strPath_IarBin;
	CString m_DeviceAxisNum;
	short   m_iDevAxisNum;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnClose();
	CComboBox m_combo_devChoose;
};
