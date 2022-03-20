
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#include "CDlgNew.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <fstream>

#define COLOR_LABEL_BK RGB(100, 0, 0)
#define COLOR_LABEL_TEXT RGB(255, 255, 255)

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

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


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, m_dNum(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_NEW, m_btnNew);
	DDX_Text(pDX, IDC_EDIT1, m_dNum);
	DDX_Control(pDX, IDC_STATIC1, m_lblNum);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_NEW, &CMFCApplication1Dlg::OnBnClickedButtonNew)
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_IMAGE, &CMFCApplication1Dlg::OnBnClickedButtonImage)
	ON_BN_CLICKED(IDC_BUTTON_PARAMETER, &CMFCApplication1Dlg::OnBnClickedButtonParameter)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CMFCApplication1Dlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CMFCApplication1Dlg::OnBnClickedButtonLoad)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	InitButtons(&m_btnNew);
	InitLabels(&m_lblNum);
	InitDialog();

	UpdateIni(true);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
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
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication1Dlg::InitDialog() {

	m_pDlgImage = new CDlgImage();
	m_pDlgImage->Create(IDD_CDlgImage);
	m_pDlgImage->MoveWindow(20, 100, 650, 450);

	m_pDlgParameter = new CDlgParameter();
	m_pDlgParameter->Create(IDD_CDlgParameter);
	m_pDlgParameter->MoveWindow(20, 100, 650, 450);

	setDlgView(DLG_VIEW_IMAGE);
}

void CMFCApplication1Dlg::setDlgView(int nMode) {
	
	if (nMode & DLG_VIEW_IMAGE)
		m_pDlgImage->ShowWindow(SW_SHOW);
	else
		m_pDlgImage->ShowWindow(SW_HIDE);

	if (nMode & DLG_VIEW_PARAMETER)
		m_pDlgParameter->ShowWindow(SW_SHOW);
	else
		m_pDlgParameter->ShowWindow(SW_HIDE);
}

void CMFCApplication1Dlg::InitButtons(CButtonST* pButton) {

	CFont Font;
	Font.CreatePointFont(30, _T("Consolas"));

	pButton->SetFont(&Font);
	pButton->SetColor(CButtonST::BTNST_COLOR_BK_IN, COLOR_LABEL_BK);
	pButton->SetColor(CButtonST::BTNST_COLOR_BK_OUT, COLOR_LABEL_BK);
	pButton->SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, COLOR_LABEL_BK);
	pButton->SetColor(CButtonST::BTNST_COLOR_FG_IN, COLOR_LABEL_TEXT);
	pButton->SetColor(CButtonST::BTNST_COLOR_FG_OUT, COLOR_LABEL_TEXT);
	pButton->SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, COLOR_LABEL_TEXT);
}

void CMFCApplication1Dlg::InitLabels(CLabel* pLabel) {

	pLabel->SetFontName(_T("Consolas"));
	pLabel->SetFontSize(20);

	pLabel->SetBkColor(COLOR_LABEL_BK);
	pLabel->SetTextColor(COLOR_LABEL_TEXT);
}

void CMFCApplication1Dlg::UpdateIni(BOOL bLoad) {

	CString fileName = CString("C://Users//sorab//source//repos//Devbeomy//MFCApplication1//MFCApplication1//Glim.ini");
	std::ifstream file(fileName);

	if (!file.good()) bLoad = false;

	CString str(fileName);
	CString strSection(_T("Parameters"));

	CIni ini(str, strSection);

	ini.SerGet(bLoad, m_dNum, _T("NUM"));

	UpdateData(false);
}

void CMFCApplication1Dlg::OnBnClickedButtonNew()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(true);
	m_lblNum.SetText(m_dNum);
}


void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(true);
	UpdateIni(false);

	CDialogEx::OnOK();
}


void CMFCApplication1Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	delete m_pDlgImage;
	delete m_pDlgParameter;
}


void CMFCApplication1Dlg::OnBnClickedButtonImage()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	setDlgView(DLG_VIEW_IMAGE);
}


void CMFCApplication1Dlg::OnBnClickedButtonParameter()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	setDlgView(DLG_VIEW_PARAMETER);
}


void CMFCApplication1Dlg::OnBnClickedButtonSave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFCApplication1Dlg::OnBnClickedButtonLoad()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	char strFilter[] = "BMP ONLY (*.BMP) | *.BMP;*.bmp | All Files(*.*)|*.*||";
	CFileDialog FileDlg(TRUE, CString(".BMP"), NULL, 0, CString(strFilter));

	if (FileDlg.DoModal() == IDOK) {

		HRESULT hr = m_pDlgImage->m_imgFile.Load(FileDlg.GetPathName());

		if (SUCCEEDED(hr)) {

			//이미지 출력
			m_pDlgParameter->ShowWindow(SW_HIDE);
			m_pDlgImage->ShowWindow(SW_HIDE);
			m_pDlgImage->ShowWindow(SW_HIDE); // for repaint

		}
	}
}
