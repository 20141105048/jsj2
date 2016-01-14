
// jsjDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "jsj.h"
#include "jsjDlg.h"
#include "afxdialogex.h"
#include "math.h"
#define NULL 0
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CjsjDlg 对话框




CjsjDlg::CjsjDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CjsjDlg::IDD, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	c=174;c1=168;c3=1820;c4=1819.9;c5=180;c6=174;
}

void CjsjDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CjsjDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_1, &CjsjDlg::OnClicked1)
	ON_BN_CLICKED(IDC_2, &CjsjDlg::OnBnClicked2)
	ON_BN_CLICKED(IDC_3, &CjsjDlg::OnBnClicked3)
	ON_BN_CLICKED(IDC_0, &CjsjDlg::OnBnClicked0)
	ON_BN_CLICKED(IDC_dian, &CjsjDlg::OnBnClickeddian)
	ON_BN_CLICKED(IDC_Add, &CjsjDlg::OnBnClickedAdd)
	
	ON_BN_CLICKED(IDC_c, &CjsjDlg::OnBnClickedc)
	ON_BN_CLICKED(IDC_js, &CjsjDlg::OnBnClickedjs)
	ON_BN_CLICKED(IDC_4, &CjsjDlg::OnBnClicked4)
	ON_BN_CLICKED(IDC_5, &CjsjDlg::OnBnClicked5)
	ON_BN_CLICKED(IDC_6, &CjsjDlg::OnBnClicked6)
	ON_BN_CLICKED(IDC_7, &CjsjDlg::OnClicked7)
	ON_BN_CLICKED(IDC_8, &CjsjDlg::OnBnClicked8)
	ON_BN_CLICKED(IDC_9, &CjsjDlg::OnClicked9)

	ON_BN_CLICKED(IDC_cheng, &CjsjDlg::OnBnClickedcheng)
	
	ON_BN_CLICKED(IDC_pingfang, &CjsjDlg::OnBnClickedpingfang)
	ON_BN_CLICKED(IDC_genhao, &CjsjDlg::OnBnClickedgenhao)
	ON_BN_CLICKED(IDC_bfh, &CjsjDlg::OnBnClickedbfh)
	ON_BN_CLICKED(IDC_jian, &CjsjDlg::OnClickedJian)
	ON_BN_CLICKED(IDC_chu, &CjsjDlg::OnClickedChu)
	ON_BN_CLICKED(IDC_back, &CjsjDlg::OnBnClickedback)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_sj, &CjsjDlg::OnBnClickedsj)
END_MESSAGE_MAP()


// CjsjDlg 消息处理程序

BOOL CjsjDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	//SetTimer(1,1000,NULL);
	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CjsjDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CjsjDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CjsjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CjsjDlg::OnClicked1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"1";
	UpdateData(false);
}


void CjsjDlg::OnBnClicked2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"2";
	UpdateData(false);
}


void CjsjDlg::OnBnClicked3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"3";
	UpdateData(false);
}


void CjsjDlg::OnBnClicked0()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"0";
	UpdateData(false);
}




void CjsjDlg::OnBnClickeddian()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(m_str.Find(L".")==-1)
		m_str=m_str+L".";
	UpdateData(false);
}


void CjsjDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CjsjDlg::OnBnClickedjs()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(flag==1)
	{
		temp=temp+_ttof(m_str);
	}
	
	if(flag==2)
	{
		temp=temp-_ttof(m_str);
	}
	
	if(flag==3)
	{
		temp=temp*_ttof(m_str);
	}
	
	if(flag==4)
	{
		double a;
		a=_ttof(m_str);
		if(a<=0.00000000000000000000000001)
		{
			
			MessageBox(L"0不能做除数");
		
		}
		else
		temp=temp/_ttof(m_str);
	}

	
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	

	UpdateData(false);
}


void CjsjDlg::OnBnClickedc()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str="";
	UpdateData(false);
}







void CjsjDlg::OnBnClicked4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"4";
	UpdateData(false);
}


void CjsjDlg::OnBnClicked5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"5";
	UpdateData(false);
}


void CjsjDlg::OnBnClicked6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"6";
	UpdateData(false);
}


void CjsjDlg::OnClicked7()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"7";
	UpdateData(false);
}


void CjsjDlg::OnBnClicked8()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"8";
	UpdateData(false);
}


void CjsjDlg::OnClicked9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	m_str=m_str+L"9";
	UpdateData(false);
}





void CjsjDlg::OnBnClickedcheng()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}




void CjsjDlg::OnBnClickedpingfang()
{

	// TODO: 在此添加控件通知处理程序代码
	
	UpdateData(true);
	temp=_ttof(m_str);
	temp=temp*temp;
	m_str="";
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CjsjDlg::OnBnClickedgenhao()
{

	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp=_ttof(m_str);
	temp=sqrt(temp);
	m_str="";
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CjsjDlg::OnBnClickedbfh()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	temp=_ttof(m_str);
	temp=0.01*temp;
	m_str.Format(L"%lf",temp);
	while(m_str.Right(1)=="0")
		m_str.Delete(m_str.GetLength()-1,1);
	while(m_str.Right(1)==".")
		m_str.Delete(m_str.GetLength()-1,1);
	UpdateData(false);
}


void CjsjDlg::OnClickedJian()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CjsjDlg::OnClickedChu()
{
	// TODO: 在此添加控件通知处理程序代码
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CjsjDlg::OnBnClickedback()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(!m_str.IsEmpty())
	{
		m_str=m_str.Left(m_str.GetLength()-1);
	}
	UpdateData(false);

}



void CjsjDlg::OnBnClickedsj()
{
	SetTimer(1,1000,NULL);
	CDC *pDC9;
	pDC9=GetDC();
	pDC9->SetWindowOrg(-380,-240);
	CPen *oldpen1;
	CPen pen(PS_SOLID,3,RGB(0,100,255));
	oldpen1=pDC9->SelectObject(&pen);
	pDC9->Ellipse(100,-100,-100,100);
	for(int i=0;i<12;i++)
	{
		double l=90,ag=i*3.1415926/6;
		double a=l*sin(ag)+1,b=-l*cos(ag)+1,c=l*sin(ag)-1,d=-l*cos(ag)-1;
		pDC9->Ellipse(a,b,c,d);
	}
}



void CjsjDlg::OnTimer(UINT_PTR nIDEvent)
{
	if(nIDEvent==1)
	{
		int r=80,x,x1,y,y1,ox=380,oy=240;
	    CDC *pDC;
	    CPen newpen,*oldpen;
	    newpen.CreatePen(PS_SOLID,1,RGB(255,255,255));
	    pDC=GetDC();
	    oldpen=pDC->SelectObject(&newpen);
        x=ox+r*sin(c*3.1415926/180);
	    y=oy+r*cos(c*3.1415926/180);
	    pDC->MoveTo(ox,oy);
	    pDC->LineTo(x,y);
	    c=c-6;
	    CDC *pDC1;
	    CPen newpen1,*oldpen1;
	    newpen1.CreatePen(PS_SOLID,1,RGB(0,0,0));
	    pDC1=GetDC();
	    oldpen1=pDC1->SelectObject(&newpen1);
        x1=ox+r*sin(c1*3.1415926/180);
	    y1=oy+r*cos(c1*3.1415926/180);
	    pDC1->MoveTo(ox,oy);
	    pDC1->LineTo(x1,y1);
	    c1=c1-6;
	
	}
	int r=60,x3,x4,y3,y4,ox=380,oy=240;
	CDC *pDC3;
	CPen newpen2,*oldpen2;
	newpen2.CreatePen(PS_SOLID,2,RGB(255,255,255));
	pDC3=GetDC();
	oldpen2=pDC3->SelectObject(&newpen2);
    x3=ox+r*sin(c3*3.1415926/1800);
	y3=oy+r*cos(c3*3.1415926/1800);
	pDC3->MoveTo(ox,oy);
	pDC3->LineTo(x3,y3);
	c3=c3-0.1;
	CDC *pDC4;
	CPen newpen3,*oldpen3;
	newpen3.CreatePen(PS_SOLID,2,RGB(0,100,255));
	pDC4=GetDC();
	oldpen3=pDC4->SelectObject(&newpen3);
    x4=ox+r*sin(c4*3.1415926/1800);
	y4=oy+r*cos(c4*3.1415926/1800);
	pDC4->MoveTo(ox,oy);
	pDC4->LineTo(x4,y4);
	c4=c4-0.1;


	int k=40,x5,x6,y5,y6;
	CDC *pDC7;
	CPen newpen5,*oldpen5;
	newpen5.CreatePen(PS_SOLID,2,RGB(255,255,255));
	pDC7=GetDC();
	oldpen5=pDC7->SelectObject(&newpen5);
    x5=ox+k*sin(c3*3.1415926/216000);
	y5=oy+k*cos(c3*3.1415926/216000);
	pDC7->MoveTo(ox,oy);
	pDC7->LineTo(x5,y5);
	c5=c5-0.1;
	CDC *pDC8;
	CPen newpen6,*oldpen6;
	newpen6.CreatePen(PS_SOLID,2,RGB(255,0,255));
	pDC8=GetDC();
	oldpen6=pDC8->SelectObject(&newpen6);
    x6=ox+k*sin(c4*3.1415926/216000);
	y6=oy+k*cos(c4*3.1415926/216000);
	pDC8->MoveTo(ox,oy);
	pDC8->LineTo(x6,y6);
	c6=c6-0.1;

	CDialogEx::OnTimer(nIDEvent);
}


