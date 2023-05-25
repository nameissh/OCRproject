
// FinalProject02Dlg.h: 헤더 파일
//

#pragma once
#include "opencv2/opencv.hpp"
using namespace cv;
using namespace std;


// CFinalProject02Dlg 대화 상자
class CFinalProject02Dlg : public CDialogEx
{
// 생성입니다.
public:
	CFinalProject02Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINALPROJECT02_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton1();
	Mat m_matImage; // 이미지 정보를 담고 있는 객체
	BITMAPINFO* m_pBitmapInfo; // Bitmap 정보를 담고 있는 구조체
	void CreateBitmapInfo(int w, int h, int bpp);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButton2();
	Mat m_src;
	Mat m_gaus;
	Mat m_bin;
	Mat m_edge;
	Mat m_morp;
};
