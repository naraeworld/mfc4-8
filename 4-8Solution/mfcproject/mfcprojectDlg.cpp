
// mfcprojectDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "mfcproject.h"
#include "mfcprojectDlg.h"
#include "afxdialogex.h"
#include "DlgImage.h"
#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmfcprojectDlg ��ȭ ����



CmfcprojectDlg::CmfcprojectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCPROJECT_DIALOG, pParent)
	, m_nNum(10)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, m_nNum);
	DDX_Control(pDX, IDC_EDIT, m_Radius);
}

BEGIN_MESSAGE_MAP(CmfcprojectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT, &CmfcprojectDlg::OnEnChangeEdit)
	ON_BN_CLICKED(IDCANCEL, &CmfcprojectDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BNT_TEST, &CmfcprojectDlg::OnBnClickedBntTest)
END_MESSAGE_MAP()


// CmfcprojectDlg �޽��� ó����

BOOL CmfcprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	MoveWindow(0, 0, 1280, 800);
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);
	m_pDlgImage->MoveWindow(0,0,640,480);

	m_pDlgImageResult = new CDlgImage;
	m_pDlgImageResult->Create(IDD_DLGIMAGE, this);
	m_pDlgImageResult->ShowWindow(SW_SHOW);
	m_pDlgImageResult->MoveWindow(640, 0, 640, 480);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CmfcprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CmfcprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	CDC*pDC = GetDC();
}


// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CmfcprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcprojectDlg::OnEnChangeEdit()
{
	UpdateData(TRUE); // Edit Control���� �����͸� �о��
}


void CmfcprojectDlg::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnCancel();
}


void CmfcprojectDlg::OnBnClickedBntTest()
{

	if (m_pDlgImage) {

		CClientDC dc(this);
		int centerX = 100;
		int centerY = 100;

		int radius;
		CString radiusStr;
		// Edit Control�� �ؽ�Ʈ�� ����
		m_Radius.GetWindowText(radiusStr);
		// CString�� ������ ��ȯ
		radius = _tstoi(radiusStr);

		m_pDlgImage->drawData(&dc, centerX, centerY, radius);
	}
}
	
	


	//unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
	//int nWidth = m_pDlgImage->m_image.GetWidth();
	//int nHeight = m_pDlgImage->m_image.GetHeight();
	//int nPitch = m_pDlgImage->m_image.GetPitch();


	//for (int k = 0; k < 100; k++) {
	//	int x = rand() % nWidth;
	//	int y = rand() % nHeight;
	//	fm[y*nPitch + x] = 0;


	//m_pDlgImage->Invalidate();

