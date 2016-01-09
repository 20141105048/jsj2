
// jsjDlg.h : 头文件
//

#pragma once


// CjsjDlg 对话框
class CjsjDlg : public CDialogEx
{
// 构造
public:
	CjsjDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_JSJ_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	
public:
	CString m_str;
	afx_msg void OnClicked1();
	int flag;
	double temp;
	afx_msg void OnBnClicked2();
	afx_msg void OnBnClicked3();
	afx_msg void OnBnClicked0();
	afx_msg void OnBnClicked9();
	afx_msg void OnBnClickeddian();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClicked7();
	afx_msg void OnBnClickedc();
	afx_msg void OnBnClickedjs();
	afx_msg void OnBnClicked4();
	afx_msg void OnBnClicked5();
	afx_msg void OnBnClicked6();
	afx_msg void OnClicked7();
	afx_msg void OnBnClicked8();
	afx_msg void OnClicked9();
	afx_msg void OnBnClickedjian();
	afx_msg void OnBnClickedcheng();
	afx_msg void OnBnClickedchu();
	afx_msg void OnBnClickedpingfang();
	afx_msg void OnBnClickedgenhao();
	afx_msg void OnBnClickedbfh();
	afx_msg void OnClickedJian();
	afx_msg void OnClickedChu();
	afx_msg void OnBnClickedback();
	
};
