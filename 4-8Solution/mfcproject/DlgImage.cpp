// DlgImage.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "mfcproject.h"
#include "DlgImage.h"
#include "afxdialogex.h"


// CDlgImage 대화 상자입니다.

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DLGIMAGE, pParent)
{

}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기입니다.


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();



	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, 640, 480);
	InitImage();
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	/*if (m_image) {
		m_image.Draw(dc, 0, 0);
	}
*/
}

void CDlgImage::drawData(CDC* pDC, int centerX, int centerY, int radius) {

	CPen pen(PS_SOLID, 2, RGB(255, 255, 0)); // 노란색 테두리 펜 생성
	CBrush brush(GetSysColor(COLOR_WINDOW)); // 빨간색 채우기 브러시 생성
	CPen* pOldPen = pDC->SelectObject(&pen);
	CBrush* pOldBrush = pDC->SelectObject(&brush);


	CRect rect(centerX - radius, centerY - radius, centerX + radius, centerY + radius);
	pDC->Ellipse(&rect);

	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);


}

void CDlgImage::InitImage() {

	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth*nHeight);

}

