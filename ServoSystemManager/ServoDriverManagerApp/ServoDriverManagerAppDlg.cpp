
// ServoDriverManagerAppDlg.cpp : 实现文件
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



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CServoDriverManagerAppDlg 对话框



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


// CServoDriverManagerAppDlg 消息处理程序

BOOL CServoDriverManagerAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	// 初始化是否需要执行脚本
	((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(BST_CHECKED);


	inputDirectory dir;
	int16 rtn;
	wstring tmp = L"dir.cfg";
	rtn = SDM_ReadDirectoryIniFile(tmp, &dir);
	if (rtn == 0)
	{
		//cstring可以直接转化为wstring
		//但是wstring通过c_str转化为cstring
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
		
		//默认初始化
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

	((CComboBox*)GetDlgItem(IDC_COMBO_DEVICE_CHOOSE))->ResetContent();//消除现有所有内容

	for (int i = 0; i < 4; i++)
	{
		((CComboBox*)GetDlgItem(IDC_COMBO_DEVICE_CHOOSE))->AddString(Strtmp[i]);
	}

	//设置默认的模式

	m_combo_devChoose.SetCurSel((m_iDevAxisNum>>1)-1);

	//输出调试信息到控制台
	AllocConsole();

	_tcprintf_s(_T("%s \r\n\r\n"), _T("IAR Servo工程目录:"));
	_tcprintf_s(_T("%s \r\n\r\n"), m_strPath_IarServo);
	_tcprintf_s(_T("%s \r\n\r\n"), _T("IAR Addr工程目录:"));
	_tcprintf_s(_T("%s \r\n\r\n"), m_strPath_IarAddr);
	_tcprintf_s(_T("%s \r\n\r\n"), _T("IAR Bin安装目录:"));
	_tcprintf_s(_T("%s \r\n\r\n"), m_strPath_IarBin);
	_tcprintf_s(_T("%s \r\n\r\n"), _T("默认设备总轴数:"));
	_tcprintf_s(_T("%s \r\n\r\n"), m_DeviceAxisNum);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CServoDriverManagerAppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CServoDriverManagerAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CServoDriverManagerAppDlg::OnBnClickedButton4()
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItemText(IDC_EDIT1, m_strPath_IarServo);
	GetDlgItemText(IDC_EDIT2, m_strPath_IarAddr);
	GetDlgItemText(IDC_EDIT3, m_strPath_IarBin);


	//获取设备的总轴号，用于打印信息
	int16 DevAxisNum;
	CString strText(_T(""));
	m_combo_devChoose.GetLBText(m_combo_devChoose.GetCurSel(), strText);
	wstring tmp = strText;
	wstringstream ss1;
	ss1 << tmp.c_str();
	ss1 >> DevAxisNum;

	if ((m_strPath_IarServo == L"") || (m_strPath_IarAddr == L"") || (m_strPath_IarBin == L""))
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("地址错误,程序退出...."));
		return;
	}


	//判断是否是正确的目录
	int16 index;
	CString substr;
	
	index = m_strPath_IarServo.ReverseFind('\\');
	if (index == -1)
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("IarServo地址格式不符,程序停止执行，请检查地址并重试...."));
		return;
	}
	substr = m_strPath_IarServo.Mid(index + 1);

	if (substr != L"IAR_SERVO")
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("IarServo地址格式不符,程序停止执行，请检查地址并重试...."));
		return;
	}
	//////////////////////////////////////////////////////////////////////////
	index = m_strPath_IarAddr.ReverseFind('\\');
	if (index == -1)
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("IarGetAddr地址格式不符,程序停止执行，请检查地址并重试...."));
		return;
	}
	substr = m_strPath_IarAddr.Mid(index + 1);

	if (substr != L"GetAddr")
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("IarGetAddr地址格式不符,程序停止执行，请检查地址并重试...."));
		return;
	}
	//////////////////////////////////////////////////////////////////////////
	index = m_strPath_IarBin.ReverseFind('\\');
	if (index == -1)
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("Iar工具地址格式不符,程序停止执行，请检查地址并重试...."));
		return;
	}
	substr = m_strPath_IarBin.Mid(index + 1);

	if (substr != L"bin")
	{
		_tcprintf_s(_T("%s \r\n\r\n"), _T("Iar工具地址格式不符,程序停止执行，请检查地址并重试...."));
		return;
	}
	//////////////////////////////////////////////////////////////////////////


	_tcprintf_s(_T("%s \r\n\r\n"), _T("创建对象...."));

	SDM_CreateObject();

	wstring str, str1;
	str = m_strPath_IarServo.GetString();
	
	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始扫描头文件...."));

	SDM_VS2IAR(str);
	
	_tcprintf_s(_T("%s \r\n\r\n"), _T("扫描头文件结束...."));

	if (BST_CHECKED == ((CButton*)GetDlgItem(IDC_CHECK1))->GetCheck())
	{
		str = m_strPath_IarAddr.GetString();
		str1 = m_strPath_IarBin.GetString();

		_tcprintf_s(_T("%s \r\n\r\n"), _T("系统调用开始...."));

		SDM_RUNBAT(str, str1);

		_tcprintf_s(_T("%s \r\n\r\n"), _T("系统调用结束...."));

	}
	
	/**/
	_tcprintf_s(_T("%s \r\n\r\n"), _T("生成xml文件版本目录...."));

	wstring Addrfilepath = L"Addr.txt";
	wstring xmlfilepath;
	SDM_GetXmlDirName(xmlfilepath);
	xmlfilepath = L".\\" + xmlfilepath;

	_tcprintf_s(_T("%s \r\n\r\n"), _T("开始打印xml文件...."));

	SDM_IAR2VS(Addrfilepath, xmlfilepath,DevAxisNum);

	_tcprintf_s(_T("%s \r\n\r\n"), _T("打印xml文件结束...."));

	SDM_DeleteObject();

	_tcprintf_s(_T("%s \r\n\r\n"), _T("销毁对象...."));

}


void CServoDriverManagerAppDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	TCHAR szPath[65536];     //存放选择的目录路径 
	CString str;

	ZeroMemory(szPath, sizeof(szPath));

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = (szPath);
	bi.lpszTitle = L"请选择IAR Servo 工程目录：";
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//弹出选择目录对话框
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

		AfxMessageBox(L"无效的IAR SERVO 工程目录，请重新选择!");
	}
}


void CServoDriverManagerAppDlg::OnBnClickedButton2()
{
	// TODO:  在此添加控件通知处理程序代码
	TCHAR szPath[65536];     //存放选择的目录路径 
	CString str;

	ZeroMemory(szPath, sizeof(szPath));

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	bi.lpszTitle = L"请选择IAR ADDR 工程目录：";
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//弹出选择目录对话框
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

		AfxMessageBox(L"无效的IAR ADDR 工程目录，请重新选择!");
	}
}


void CServoDriverManagerAppDlg::OnBnClickedButton3()
{
	// TODO:  在此添加控件通知处理程序代
	TCHAR szPath[65536];     //存放选择的目录路径 
	CString str;

	ZeroMemory(szPath, sizeof(szPath));

	BROWSEINFO bi;
	bi.hwndOwner = m_hWnd;
	bi.pidlRoot = NULL;
	bi.pszDisplayName = szPath;
	bi.lpszTitle = L"请选择IAR安装文件bin目录：";
	bi.ulFlags = 0;
	bi.lpfn = NULL;
	bi.lParam = 0;
	bi.iImage = 0;
	//弹出选择目录对话框
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
		AfxMessageBox(L"无效的IAR 安装文件BIN 目录,请重新选择!");
	}
}


void CServoDriverManagerAppDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
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
		AfxMessageBox(L"写入dir.cfg配置文件失败");
	}
	FreeConsole();
	CDialogEx::OnOK();
}


void CServoDriverManagerAppDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
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
		AfxMessageBox(L"写入dir.cfg配置文件失败");
	}
	FreeConsole();
	CDialogEx::OnCancel();
}


void CServoDriverManagerAppDlg::OnClose()
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
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
		AfxMessageBox(L"写入dir.cfg配置文件失败");
	}
	FreeConsole();
	CDialogEx::OnClose();
}
