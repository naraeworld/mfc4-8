
// mfcprojectDlg.h : ��� ����
//

#pragma once

#include "DlgImage.h"
#include "afxwin.h"
// CmfcprojectDlg ��ȭ ����
class CmfcprojectDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CmfcprojectDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

	

	CDlgImage *m_pDlgImage;
	CDlgImage *m_pDlgImageResult;


// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBntTest();
	int m_nNum;
	CEdit m_Radius;
};
