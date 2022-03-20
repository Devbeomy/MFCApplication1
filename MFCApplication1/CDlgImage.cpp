// CDlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication1.h"
#include "afxdialogex.h"
#include "CDlgImage.h"


// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialog)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CDlgImage, pParent)
{

}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기


void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialog::OnPaint()을(를) 호출하지 마십시오.
}

void CDlgImage::drawImage() {
	CStatic* staticsize = (CStatic*)GetDlgItem(IDC_STATIC_IMAGE);
	CClientDC dc(staticsize);

	CRect rect;
	staticsize->GetClientRect(rect);

	if(m_imgFile != NULL) {

		int w = m_imgFile.GetWidth();
		int h = m_imgFile.GetWidth();

		m_imgFile.BitBlt(dc.m_hDC, 0, 0, w, h, 0, 0);
	}
}