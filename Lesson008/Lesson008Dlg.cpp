
// Lesson008Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Lesson008.h"
#include "Lesson008Dlg.h"
#include "afxdialogex.h"
#include <string>
#include <exception>
#define _USE_MATH_DEFINES
#include <math.h>
#include <sstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
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


// Диалоговое окно CLesson008Dlg



CLesson008Dlg::CLesson008Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Lesson008_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLesson008Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLesson008Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLesson008Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLesson008Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CLesson008Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CLesson008Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// Обработчики сообщений CLesson008Dlg

BOOL CLesson008Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
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

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию


	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_YOUR_LIST_CONTROL_ID2);

	// Добавляем колонки
	for (int i = 0; i < MAT1_SIZE; i++)
	{
		pList->InsertColumn(i, _T("Column 1"), LVCFMT_LEFT, 50);
		int nIndex;
		nIndex = pList->InsertItem(MAT1_SIZE, _T("Первая строка"));
	}
	for (int i = 0; i < MAT1_SIZE; i++)
	{
		for (int j = 0; j < MAT1_SIZE; j++)
		{
			pList->SetItemText(i, j, _T("0.0"));
		}
	}

	CListCtrl* pList2 = (CListCtrl*)GetDlgItem(IDC_YOUR_LIST_CONTROL_ID);

	// Добавляем колонки
	for (int i = 0; i < MAT2_SIZE; i++)
	{
		pList2->InsertColumn(i, _T("Column 1"), LVCFMT_LEFT, 50);
		int nIndex;
		nIndex = pList2->InsertItem(MAT2_SIZE, _T("Первая строка"));
	}
	for (int i = 0; i < MAT2_SIZE; i++)
	{
		for (int j = 0; j < MAT2_SIZE; j++)
		{
			pList2->SetItemText(i, j, _T("0.0"));
		}
	}

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CLesson008Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CLesson008Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CLesson008Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CLesson008Dlg::OnBnClickedButton1()
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_YOUR_LIST_CONTROL_ID2);
	std::uniform_int_distribution<> distrib(-50, 50);

	for (int i = 0; i < MAT1_SIZE; i++)
	{
		for (int j = 0; j < MAT1_SIZE; j++)
		{
			mat1[i][j] = distrib(gen);

			std::stringstream s;
			s << mat1[i][j];

			pList->SetItemText(i, j, _T(s.str().c_str()));
		}
	}
}


void CLesson008Dlg::OnBnClickedButton2()
{
	double maxvalue = mat1[0][MAT1_SIZE - 1];

	for (int i = 1; i < MAT1_SIZE; i++)
	{
		if (mat1[i][MAT1_SIZE - i - 1] > maxvalue)
		{
			maxvalue = mat1[i][MAT1_SIZE - i - 1];
		}
	}

	std::stringstream s;
	s << "MAX=" << maxvalue;

	CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT2);
	edit->SetWindowTextA(s.str().c_str());
}


void CLesson008Dlg::OnBnClickedButton3()
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_YOUR_LIST_CONTROL_ID);
	std::uniform_int_distribution<> distrib(-50, 50);

	for (int i = 0; i < MAT2_SIZE; i++)
	{
		for (int j = 0; j < MAT2_SIZE; j++)
		{
			mat2[i][j] = distrib(gen);

			std::stringstream s;
			s << mat2[i][j];

			pList->SetItemText(i, j, _T(s.str().c_str()));
		}
	}
}


void CLesson008Dlg::OnBnClickedButton4()
{
	double maxvalue = mat2[0][MAT2_SIZE - 1];

	for (int i = 1; i < MAT2_SIZE; i++)
	{
		if (mat2[i][MAT2_SIZE - i - 1] > maxvalue)
		{
			maxvalue = mat2[i][MAT2_SIZE - i - 1];
		}
	}

	std::stringstream s;
	s << "MAX=" << maxvalue;

	CEdit* edit = (CEdit*)GetDlgItem(IDC_EDIT1);
	edit->SetWindowTextA(s.str().c_str());
}
