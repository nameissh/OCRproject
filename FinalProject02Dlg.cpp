﻿
// FinalProject02Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "FinalProject02.h"
#include "FinalProject02Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CFinalProject02Dlg 대화 상자



CFinalProject02Dlg::CFinalProject02Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINALPROJECT02_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFinalProject02Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFinalProject02Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CFinalProject02Dlg::OnBnClickedButton1)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON2, &CFinalProject02Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CFinalProject02Dlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CFinalProject02Dlg 메시지 처리기

BOOL CFinalProject02Dlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CFinalProject02Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CFinalProject02Dlg::OnPaint()
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
HCURSOR CFinalProject02Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFinalProject02Dlg::OnBnClickedButton1()		// open file
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	TCHAR szFilter[] = _T("Image(*.png, *.gif, *.jpg)|*.png;*.gif;*.jpg|All Files(*.*)|*.*||");
	CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);

	if (IDOK == dlg.DoModal())
	{
		// 선택 파일정보 얻기
		// strPathName      "C:/Images/Picture1.jpg"
		// strFileName      "Picture1.jpg"
		// strFolderPath    "C:/Images"

		CString strPathName = dlg.GetPathName();
		CString strFileName = dlg.GetFileName();
		CString strFolderPath = dlg.GetFolderPath();
		//SetDlgItemText(IDC_EDIT1, strPathName);

		// Bitmap 정보를 생성하는 함수 호출
		CT2CA pszString(strPathName);
		string strPath(pszString);

		m_matImage = imread(strPath, IMREAD_UNCHANGED);

		CreateBitmapInfo(m_matImage.cols, m_matImage.rows, m_matImage.channels() * 8);

		// 파일 picture control에 띄우기
		CClientDC dc(GetDlgItem(IDC_picture));

		CRect rect;
		GetDlgItem(IDC_picture)->GetClientRect(&rect);

		SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
		StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, m_matImage.cols, m_matImage.rows, m_matImage.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
	}
}



void CFinalProject02Dlg::CreateBitmapInfo(int w, int h, int bpp)
{
	if (m_pBitmapInfo != NULL)
	{
		delete m_pBitmapInfo;
		m_pBitmapInfo = NULL;
	}

	if (bpp == 8)
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO) + 255 * sizeof(RGBQUAD)];
	else // 24 or 32bit
		m_pBitmapInfo = (BITMAPINFO*) new BYTE[sizeof(BITMAPINFO)];

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_pBitmapInfo->bmiHeader.biPlanes = 1;
	m_pBitmapInfo->bmiHeader.biBitCount = bpp;
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	m_pBitmapInfo->bmiHeader.biSizeImage = 0;
	m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biClrUsed = 0;
	m_pBitmapInfo->bmiHeader.biClrImportant = 0;

	if (bpp == 8)
	{
		for (int i = 0; i < 256; i++)
		{
			m_pBitmapInfo->bmiColors[i].rgbBlue = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbGreen = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbRed = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbReserved = 0;
		}
	}

	m_pBitmapInfo->bmiHeader.biWidth = w;
	m_pBitmapInfo->bmiHeader.biHeight = -h;
}



void CFinalProject02Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_pBitmapInfo != NULL)
	{
		delete m_pBitmapInfo;
		m_pBitmapInfo = NULL;
	}
}



void CFinalProject02Dlg::OnBnClickedButton2()		// image preprocessing
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	// 가우시안 필터
	cvtColor(m_matImage, m_src, COLOR_RGB2GRAY);
	GaussianBlur(m_src, m_gaus, Size(3, 3), 0);

	// 이진화
	threshold(m_gaus, m_bin, 0, 255, THRESH_BINARY | THRESH_OTSU);

	// Bitmap 정보를 생성하는 함수 호출
	CreateBitmapInfo(m_bin.cols, m_bin.rows, m_bin.channels() * 8);

	// 파일 picture control에 띄우기
	CClientDC dc(GetDlgItem(IDC_picture));

	CRect rect;
	GetDlgItem(IDC_picture)->GetClientRect(&rect);

	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, m_bin.cols, m_bin.rows, m_bin.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);

	// FinalProject02 폴더에 파일 저장
	CString savePath = _T("C:/c++/FinalProject02/text.bmp");
	string savePathStr(CW2A(savePath.GetString()));		// 유니코드 멀티바이트 변환 : CW2A
	imwrite(savePathStr, m_bin);
}



void CFinalProject02Dlg::OnBnClickedButton3()		// text
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	const char* input_image = "C:/c++/FinalProject02/text.bmp";
	const char* dataPath = "C:/Program Files/Tesseract-OCR/tessdata";

	// tesseract api 설정
	tesseract::TessBaseAPI* api = new tesseract::TessBaseAPI();

	if (api->Init(dataPath, "eng+kor"))
	{
		return;
	}

	// 이미지 설정
	Pix* image = pixRead(input_image);
	api->SetImage(image);

	string utf_text = api->GetUTF8Text();
	CString text(utf_text.c_str());

	SetDlgItemText(IDC_EDIT1, text);
}