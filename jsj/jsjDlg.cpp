
// jsjDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CjsjDlg �Ի���




CjsjDlg::CjsjDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CjsjDlg::IDD, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
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
END_MESSAGE_MAP()


// CjsjDlg ��Ϣ��������

BOOL CjsjDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵������ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ����Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի���������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CjsjDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CjsjDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CjsjDlg::OnClicked1()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str=m_str+L"1";
	UpdateData(false);
}


void CjsjDlg::OnBnClicked2()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str=m_str+L"2";
	UpdateData(false);
}


void CjsjDlg::OnBnClicked3()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str=m_str+L"3";
	UpdateData(false);
}


void CjsjDlg::OnBnClicked0()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str=m_str+L"0";
	
	UpdateData(false);
}




void CjsjDlg::OnBnClickeddian()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);

	if(m_str.Find(L".")==-1)
		m_str=m_str+L".";
	UpdateData(false);
}


void CjsjDlg::OnBnClickedAdd()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	flag=1;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CjsjDlg::OnBnClickedjs()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
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
			
			temp=0.0001;
		
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
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str="";
	UpdateData(false);
}







void CjsjDlg::OnBnClicked4()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str=m_str+L"4";
	UpdateData(false);
}


void CjsjDlg::OnBnClicked5()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str=m_str+L"5";
	UpdateData(false);
}


void CjsjDlg::OnBnClicked6()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str=m_str+L"6";
	UpdateData(false);
}


void CjsjDlg::OnClicked7()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str=m_str+L"7";
	UpdateData(false);
}


void CjsjDlg::OnBnClicked8()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str=m_str+L"8";
	UpdateData(false);
}


void CjsjDlg::OnClicked9()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	m_str=m_str+L"9";
	UpdateData(false);
}





void CjsjDlg::OnBnClickedcheng()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	flag=3;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}




void CjsjDlg::OnBnClickedpingfang()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	
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
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
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
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
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
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	flag=2;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CjsjDlg::OnClickedChu()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	flag=4;
	UpdateData(true);
	temp=_ttof(m_str);
	m_str="";
	UpdateData(false);
}


void CjsjDlg::OnBnClickedback()
{
	// TODO: �ڴ����ӿؼ�֪ͨ�����������
	UpdateData(true);
	if(!m_str.IsEmpty())
	{
		m_str=m_str.Left(m_str.GetLength()-1);
	}
	UpdateData(false);

}
