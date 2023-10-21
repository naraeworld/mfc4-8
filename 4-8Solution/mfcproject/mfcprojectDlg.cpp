
// mfcprojectDlg.cpp : 구현 파일
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


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.
using namespace std;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();


// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
	/*afx_msg void OnDestroy();*/
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CmfcprojectDlg 대화 상자



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


// CmfcprojectDlg 메시지 처리기


//void CmfcprojectDlg::OnDestroy()
//{
//	CDialogEx::OnDestroy();
//
//	if (m_pDlgImage) delete m_pDlgImage;
//	if (m_pDlgImageResult) delete m_pDlgImageResult;
//}

BOOL CmfcprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 1280, 800);
	m_pDlgImage = new CDlgImage;
	m_pDlgImage->Create(IDD_DLGIMAGE, this);
	m_pDlgImage->ShowWindow(SW_SHOW);
	m_pDlgImage->MoveWindow(0,0,640,480);

	m_pDlgImageResult = new CDlgImage;
	m_pDlgImageResult->Create(IDD_DLGIMAGE, this);
	m_pDlgImageResult->ShowWindow(SW_SHOW);
	m_pDlgImageResult->MoveWindow(640, 0, 640, 480);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CmfcprojectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	CDC*pDC = GetDC();
}


// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CmfcprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CmfcprojectDlg::OnEnChangeEdit()
{
	UpdateData(TRUE); // Edit Control에서 데이터를 읽어옴
}


void CmfcprojectDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CmfcprojectDlg::ClearImageDialog(CDialog* pDialog)
{
	CRect clientRect;
	pDialog->GetClientRect(clientRect);
	CClientDC dc(pDialog);
	dc.FillSolidRect(clientRect, GetSysColor(COLOR_WINDOW));
}

void CmfcprojectDlg::OnBnClickedBntTest()
{

	if (m_pDlgImage) {

		// 이미지 초기화
		ClearImageDialog(m_pDlgImage);

		CClientDC dc(this);

		int nWidth = m_pDlgImage->m_image.GetWidth();
		int nHeight = m_pDlgImage->m_image.GetHeight();
		int nPitch = m_pDlgImage->m_image.GetPitch();

		int radius;
		CString radiusStr;
		// Edit Control의 텍스트를 얻어옴
		m_Radius.GetWindowText(radiusStr);
		// CString을 정수로 변환
		radius = _tstoi(radiusStr);

		// 새로운 중심 좌표 계산
		srand(time(NULL));  // 난수 시드 설정
		int centerX = rand() % (nWidth - 2 * radius) + radius;
		int centerY = rand() % (nHeight - 2 * radius) + radius;

		// 무게 중심 계산
		unsigned char* fm = (unsigned char*)m_pDlgImage->m_image.GetBits();
		int nTh = 0x80;
		int nSumX = 0;
		int nSumY = 0;
		int nCount = 0;

		for (int j = centerY - radius; j < centerY + radius; j++) {
			for (int i = centerX - radius; i < centerX + radius; i++) {
				if (i >= 0 && i < nWidth && j >= 0 && j < nHeight && fm[j * nPitch + i] > nTh) {
					nSumX += i;
					nSumY += j;
					nCount++;
				}
			}
		}

		double dCenterX = (double)nSumX / nCount;
		double dCenterY = (double)nSumY / nCount;

		// 원 그리기
		m_pDlgImage->drawData(&dc, centerX, centerY, radius);

		// 빨간색 십자가 그리기
		CPen pen;
		pen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		CPen* pOldPen = dc.SelectObject(&pen);

		// 가로선 그리기
		dc.MoveTo(dCenterX - 10, dCenterY);
		dc.LineTo(dCenterX + 10, dCenterY);

		// 세로선 그리기
		dc.MoveTo(dCenterX, dCenterY - 10);
		dc.LineTo(dCenterX, dCenterY + 10);

		dc.SelectObject(pOldPen);

		cout << "원의 무게 중심:" << dCenterX << ", " << dCenterY << endl;
	}
}


