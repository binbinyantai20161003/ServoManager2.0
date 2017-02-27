
// ServoDriverManagerAppDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"

#include "afxdialogex.h"
#include "./../ServoDriverManagerDll/Basetype_def.h"
#include "./../ServoDriverManagerDll/ServoDriverManagerDll.h"
#include "conio.h"
#include "ServoDriverManagerApp.h"
#include "ServoDriverManagerAppDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CServoDriverManagerAppDlg �Ի���



CServoDriverManagerAppDlg::CServoDriverManagerAppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CServoDriverManagerAppDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CServoDriverManagerAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_DEVICE_CHOOSE, m_combo_devChoose);
}

BEGIN_MESSAGE_MAP(CServoDriverManagerAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CServoDriverManagerAppDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &CServoDriverManagerAppDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CServoDriverManagerAppDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CServoDriverManagerAppDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDOK, &CServoDriverManagerAppDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CServoDriverManagerAppDlg::OnBnClickedCancel)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CServoDriverManagerAppDlg ��Ϣ�������

BOOL CServoDriverManagerAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������

	// ��ʼ���Ƿ���Ҫִ�нű�
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(BST_CHECKED);


	inputDirectory dir;
	int16 rtn;
	wstring tmp = L"dir.cfg";
	rtn = SDM_ReadDirectoryIniFile(tmp, &dir);
	if (rtn == 0)
	{
		//cstring����ֱ��ת��Ϊwstring
		//����wstringͨ��c_strת��Ϊcstring
		m_strPath_IarServo	= dir.IAR_Servo.c_str();
		m_strPath_IarAddr	= dir.IAR_Addr.c_str();
		m_strPath_IarBin	= dir.IAR_Bin.c_str();
		m_DeviceAxisNum = dir.DEV_AXIS_NUM.c_str();
		wstringstream ss;
		ss << dir.DEV_AXIS_NUM;
		ss >> m_iDevAxisNum;
	}
	else
	{
		
		//Ĭ�ϳ�ʼ��
		m_strPath_IarServo	= L"E:\\googoltech_program\\ARM_program\\CM408\\IAR_SERVO(V119_0922)\\IAR_SERVO\\Servo Control";
		m_strPath_IarAddr	= L"E:\\googoltech_program\\ARM_program\\CM408\\IAR_SERVO(V119_0922)\\IAR_SERVO\\GetAddr";
		m_strPath_IarBin	= L"D:\\IAR\\common\\bin";
		m_DeviceAxisNum = L"4";
		m_iDevAxisNum = 4;
		/**/
	}

	SetDlgItemText(IDC_EDIT1, m_strPath_IarServo);
	SetDlgItemText(IDC_EDIT2, m_strPath_IarAddr);
	SetDlgItemText(IDC_EDIT3, m_strPath_IarBin);

	//
	CString Strtmp[4] = { _T("2"), _T("4"), _T("6"), _T("8") };

	((CComboBox*)GetDlgItem(IDC_COMBO_DEVICE_CHOOSE))->ResetContent();//����������������

	for (int i = 0; i < 4; i++)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_DEVICE_CHOOSE))->AddString(Strtmp[i]);
	}

	//����Ĭ�ϵ�ģʽ

	m_combo_devChoose.SetCurSel((m_iDevAxisNum>>1)-1);

	//���������Ϣ������̨
	AllocConsole();

	_tcprintf_s(_T("%s \r\n\r\n"), _T("IAR Servo����Ŀ¼:"));
	_tcprintf_s(_T("%s \r\n\r\n"), m_strPath_IarServo);
	_tcprintf_s(_T("%s \r\n\r\n"), _T("IAR Addr����Ŀ¼:"));
	_tcprintf_s(_T("%s \r\n\r\n"), m_strPath_IarAddr);
	_tcprintf_s(_T("%s \r\n\r\n"), _T("IAR Bin��װĿ¼:"));
	_tcprintf_s(_T("%s \r\n\r\n"), m_strPath_IarBin);
	_tcprintf_s(_T("%s \r\n\r\n"), _T("Ĭ���豸������:"));
	_tcprintf_s(_T("%s \r\n\r\n"), m_DeviceAxisNum);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CServoDriverManagerAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CServoDriverManagerAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CServoDriverManagerAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CServoDriverManagerAppDlg::OnBnClickedButton4()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT1, m_strPath_IarServo);
	GetDlgItemText(IDC_EDIT2, m_strPath_IarAddr);
	GetDlgItemText(IDC_EDIT3, m_strPath_IarBin);


	//��ȡ�豸������ţ����ڴ�ӡ��Ϣ
	int16 DevAxisNum;
	CString strText(_T(""));
	m_combo_devChoose.GetLBText(m_combo_devChoose.GetCurSel(), strText);
	wstring tmp = strText;
	wstringstream ss1;
	ss1 << tmp.c_str();
	ss1 >> DevAxisNum;

	if ((m_strPath_IarServo == L"") || (m_strPath_IarAddr == L"") || (m_strPath_IarBin == L""))
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("��ַ����,�����˳�...."));
		return;
	}


	//�ж��Ƿ�����ȷ��Ŀ¼
	int16 index;
	CString substr;
	
	index = m_strPath_IarServo.ReverseFind('\\');
	if (index == -1)
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("IarServo��ַ��ʽ����,����ִֹͣ�У������ַ������...."));
		return;
	}
	substr = m_strPath_IarServo.Mid(index + 1);

	if (substr != L"IAR_SERVO")
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("IarServo��ַ��ʽ����,����ִֹͣ�У������ַ������...."));
		return;
	}
	//////////////////////////////////////////////////////////////////////////
	index = m_strPath_IarAddr.ReverseFind('\\');
	if (index == -1)
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("IarGetAddr��ַ��ʽ����,����ִֹͣ�У������ַ������...."));
		return;
	}
	substr = m_strPath_IarAddr.Mid(index + 1);

	if (substr != L"GetAddr")
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("IarGetAddr��ַ��ʽ����,����ִֹͣ�У������ַ������...."));
		return;
	}
	//////////////////////////////////////////////////////////////////////////
	index = m_strPath_IarBin.ReverseFind('\\');
	if (index == -1)
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("Iar���ߵ�ַ��ʽ����,����ִֹͣ�У������ַ������...."));
		return;
	}
	substr = m_strPath_IarBin.Mid(index + 1);

	if (substr != L"bin")
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("Iar���ߵ�ַ��ʽ����,����ִֹͣ�У������ַ������...."));
		return;
	}
	//////////////////////////////////////////////////////////////////////////


	_tcprintf_s(_T("%s \r\n\r\n"), _T("��������...."));

	SDM_CreateObject();

	wstring str, str1;
	str = m_strPath_IarServo.GetString();
	
	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼɨ��ͷ�ļ�...."));

	SDM_VS2IAR(str);
	
	_tcprintf_s(_T("%s \r\n\r\n"), _T("ɨ��ͷ�ļ�����...."));

	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		str = m_strPath_IarAddr.GetString();
		str1 = m_strPath_IarBin.GetString();

		_tcprintf_s(_T("%s \r\n\r\n"), _T("ϵͳ���ÿ�ʼ...."));

		SDM_RUNBAT(str, str1);

		_tcprintf_s(_T("%s \r\n\r\n"), _T("ϵͳ���ý���...."));

	}
	
	/**/
	_tcprintf_s(_T("%s \r\n\r\n"), _T("����xml�ļ��汾Ŀ¼...."));

	wstring Addrfilepath = L"Addr.txt";
	wstring xmlfilepath;
	SDM_GetXmlDirName(xmlfilepath);
	xmlfilepath = L".\\" + xmlfilepath;

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ʼ��ӡxml�ļ�...."));

	SDM_IAR2VS(Addrfilepath, xmlfilepath,DevAxisNum);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("��ӡxml�ļ�����...."));

	SDM_DeleteObject();

	_tcprintf_s(_T("%s \r\n\r\n"), _T("���ٶ���...."));

}


void CServoDriverManagerAppDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TCHAR szPath[65536];     //���ѡ���Ŀ¼·�� 
	CString str;

	ZeroMemory(szPath, sizeof(szPath));

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = (szPath);
	bi.lpszTitle = L"��ѡ��IAR Servo ����Ŀ¼��";
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//����ѡ��Ŀ¼�Ի���
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);

	if (lp && SHGetPathFromIDList(lp, szPath))
	{
		str.Format(L"%s", szPath);
		//AfxMessageBox(str);
		m_strPath_IarServo = str;
		SetDlgItemText(IDC_EDIT1, m_strPath_IarServo);
	}
	else
	{
		m_strPath_IarServo = L"";
		SetDlgItemText(IDC_EDIT1, m_strPath_IarServo);

		AfxMessageBox(L"��Ч��IAR SERVO ����Ŀ¼��������ѡ��!");
	}
}


void CServoDriverManagerAppDlg::OnBnClickedButton2()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	TCHAR szPath[65536];     //���ѡ���Ŀ¼·�� 
	CString str;

	ZeroMemory(szPath, sizeof(szPath));

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	bi.lpszTitle = L"��ѡ��IAR ADDR ����Ŀ¼��";
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//����ѡ��Ŀ¼�Ի���
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);

	if (lp && SHGetPathFromIDList(lp, szPath))
	{
		str.Format(L"%s", szPath);
		//AfxMessageBox(str);
		m_strPath_IarAddr = str;
		SetDlgItemText(IDC_EDIT2, m_strPath_IarAddr);
	}
	else
	{
		m_strPath_IarAddr = L"";
		SetDlgItemText(IDC_EDIT2, m_strPath_IarAddr);

		AfxMessageBox(L"��Ч��IAR ADDR ����Ŀ¼��������ѡ��!");
	}
}


void CServoDriverManagerAppDlg::OnBnClickedButton3()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ��������
	TCHAR szPath[65536];     //���ѡ���Ŀ¼·�� 
	CString str;

	ZeroMemory(szPath, sizeof(szPath));

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	bi.lpszTitle = L"��ѡ��IAR��װ�ļ�binĿ¼��";
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//����ѡ��Ŀ¼�Ի���
	LPITEMIDLIST lp = SHBrowseForFolder(&bi);

	if (lp && SHGetPathFromIDList(lp, szPath))
	{
		str.Format(L"%s", szPath);
		//AfxMessageBox(str);
		m_strPath_IarBin = str;
		SetDlgItemText(IDC_EDIT3, m_strPath_IarBin);
	}
	else
	{
		m_strPath_IarBin = L"";
		SetDlgItemText(IDC_EDIT3, m_strPath_IarBin);
		AfxMessageBox(L"��Ч��IAR ��װ�ļ�BIN Ŀ¼,������ѡ��!");
	}
}


void CServoDriverManagerAppDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT1, m_strPath_IarServo);
	GetDlgItemText(IDC_EDIT2, m_strPath_IarAddr);
	GetDlgItemText(IDC_EDIT3, m_strPath_IarBin);
	CString strText(_T(""));
	m_combo_devChoose.GetLBText(m_combo_devChoose.GetCurSel(), strText);
	inputDirectory dir;
	dir.IAR_Servo	=	m_strPath_IarServo;
	dir.IAR_Addr	=	m_strPath_IarAddr;
	dir.IAR_Bin		=	m_strPath_IarBin;
	dir.DEV_AXIS_NUM = strText;
	int16 rtn;
	wstring tmp = L"dir.cfg";
	rtn = SDM_WriteDirectoryIniFile(tmp, dir);
	if (rtn != 0)
	{
		AfxMessageBox(L"д��dir.cfg�����ļ�ʧ��");
	}
	FreeConsole();
	CDialogEx::OnOK();
}


void CServoDriverManagerAppDlg::OnBnClickedCancel()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	GetDlgItemText(IDC_EDIT1, m_strPath_IarServo);
	GetDlgItemText(IDC_EDIT2, m_strPath_IarAddr);
	GetDlgItemText(IDC_EDIT3, m_strPath_IarBin);
	CString strText(_T(""));
	m_combo_devChoose.GetLBText(m_combo_devChoose.GetCurSel(), strText);
	inputDirectory dir;
	dir.IAR_Servo = m_strPath_IarServo;
	dir.IAR_Addr = m_strPath_IarAddr;
	dir.IAR_Bin = m_strPath_IarBin;
	dir.DEV_AXIS_NUM = strText;
	int16 rtn;
	wstring tmp = L"dir.cfg";
	rtn = SDM_WriteDirectoryIniFile(tmp, dir);
	if (rtn != 0)
	{
		AfxMessageBox(L"д��dir.cfg�����ļ�ʧ��");
	}
	FreeConsole();
	CDialogEx::OnCancel();
}


void CServoDriverManagerAppDlg::OnClose()
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ
	GetDlgItemText(IDC_EDIT1, m_strPath_IarServo);
	GetDlgItemText(IDC_EDIT2, m_strPath_IarAddr);
	GetDlgItemText(IDC_EDIT3, m_strPath_IarBin);
	CString strText(_T(""));
	m_combo_devChoose.GetLBText(m_combo_devChoose.GetCurSel(), strText);
	inputDirectory dir;
	dir.IAR_Servo = m_strPath_IarServo;
	dir.IAR_Addr = m_strPath_IarAddr;
	dir.IAR_Bin = m_strPath_IarBin;
	dir.DEV_AXIS_NUM = strText;
	int16 rtn;
	wstring tmp = L"dir.cfg";
	rtn = SDM_WriteDirectoryIniFile(tmp, dir);
	if (rtn != 0)
	{
		AfxMessageBox(L"д��dir.cfg�����ļ�ʧ��");
	}
	FreeConsole();
	CDialogEx::OnClose();
}
