// DlgImage.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "mfcproject.h"
#include "DlgImage.h"
#include "afxdialogex.h"


// CDlgImage ��ȭ �����Դϴ�.

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


// CDlgImage �޽��� ó�����Դϴ�.


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();



	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	MoveWindow(0, 0, 640, 480);
	InitImage();
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
					   // �׸��� �޽����� ���ؼ��� CDialogEx::OnPaint()��(��) ȣ������ ���ʽÿ�.

	/*if (m_image) {
		m_image.Draw(dc, 0, 0);
	}
*/
}

void CDlgImage::drawData(CDC* pDC, int centerX, int centerY, int radius) {

	CPen pen(PS_SOLID, 2, RGB(255, 255, 0)); // ����� �׵θ� �� ����
	CBrush brush(GetSysColor(COLOR_WINDOW)); // ������ ä��� �귯�� ����
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

