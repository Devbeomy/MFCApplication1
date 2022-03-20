// CDlgNew.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CDlgNew.h"


// CDlgNew 대화 상자

IMPLEMENT_DYNAMIC(CDlgNew, CDialogEx)

CDlgNew::CDlgNew(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1_NEW, pParent)
{

}

CDlgNew::~CDlgNew()
{
}

void CDlgNew::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgNew, CDialogEx)
END_MESSAGE_MAP()


// CDlgNew 메시지 처리기
