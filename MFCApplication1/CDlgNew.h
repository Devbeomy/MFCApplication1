#pragma once
#include "afxdialogex.h"


// CDlgNew 대화 상자

class CDlgNew : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgNew)

public:
	CDlgNew(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgNew();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1_NEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
