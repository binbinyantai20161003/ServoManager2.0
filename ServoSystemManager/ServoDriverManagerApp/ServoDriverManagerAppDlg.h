
// ServoDriverManagerAppDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CServoDriverManagerAppDlg �Ի���
class CServoDriverManagerAppDlg : public CDialogEx
{
// ����
public:
	CServoDriverManagerAppDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_SERVODRIVERMANAGERAPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
