
// Lesson010Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Lesson010.h"
#include "Lesson010Dlg.h"
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


// Диалоговое окно CLesson010Dlg



CLesson010Dlg::CLesson010Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Lesson010_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLesson010Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLesson010Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLesson010Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений CLesson010Dlg

BOOL CLesson010Dlg::OnInitDialog()
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


	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_YOUR_LIST_CONTROL_ID);

	pList->InsertColumn(0, _T("Валюта"), LVCFMT_LEFT, 100);
	pList->InsertColumn(1, _T("Курс к сому"), LVCFMT_LEFT, 100);
	pList->InsertColumn(2, _T("Принято, сом"), LVCFMT_LEFT, 100);
	pList->InsertColumn(3, _T("Комиссия, сом"), LVCFMT_LEFT, 100);
	pList->InsertColumn(4, _T("Ваша валюта"), LVCFMT_LEFT, 100);

	pList->InsertItem(3, _T(""));
	pList->InsertItem(3, _T(""));
	pList->InsertItem(3, _T(""));

	pList->SetItemText(0, 0, _T("Доллар США"));
	pList->SetItemText(0, 1, _T("89.87"));
	pList->SetItemText(0, 2, _T(""));
	pList->SetItemText(0, 3, _T(""));
	pList->SetItemText(0, 4, _T(""));

	pList->SetItemText(1, 0, _T("Фунт стерлингов"));
	pList->SetItemText(1, 1, _T("113.68"));
	pList->SetItemText(1, 2, _T(""));
	pList->SetItemText(1, 3, _T(""));
	pList->SetItemText(1, 4, _T(""));

	pList->SetItemText(2, 0, _T("Евро"));
	pList->SetItemText(2, 1, _T("97.09"));
	pList->SetItemText(2, 2, _T(""));
	pList->SetItemText(2, 3, _T(""));
	pList->SetItemText(2, 4, _T(""));

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CLesson010Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLesson010Dlg::OnPaint()
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
HCURSOR CLesson010Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void CLesson010Dlg::OnBnClickedButton1()
{
	CString str;
	std::string stdStr;
	try
	{
		GetDlgItemText(IDC_EDIT2, str);
		stdStr = std::string{ CT2A(str) };

		double comission = std::stod(stdStr) / 100;

		GetDlgItemText(IDC_EDIT3, str);
		stdStr = std::string{ CT2A(str) };

		double value = std::stod(stdStr);


		CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_YOUR_LIST_CONTROL_ID);
		
			//	pList->InsertColumn(2, _T("Принято, сом"), LVCFMT_LEFT, 100);
		//pList->InsertColumn(3, _T("Комиссия, сом"), LVCFMT_LEFT, 100);
		//pList->InsertColumn(4, _T("Ваша валюта"), LVCFMT_LEFT, 100);

		std::stringstream s;
		s << value;

		pList->SetItemText(0, 2, _T(s.str().c_str()));
		pList->SetItemText(1, 2, _T(s.str().c_str()));
		pList->SetItemText(2, 2, _T(s.str().c_str()));

		s = std::stringstream();
		s << comission * value;
		pList->SetItemText(0, 3, _T(s.str().c_str()));
		pList->SetItemText(1, 3, _T(s.str().c_str()));
		pList->SetItemText(2, 3, _T(s.str().c_str()));

		CString currencyRate1str = pList->GetItemText(0, 1);
		stdStr = std::string{ CT2A(currencyRate1str) };

		double currencyRate1 = std::stod(stdStr);
		double valueInCurrency1 = (value - comission * value) / currencyRate1;

		s = std::stringstream();
		s << valueInCurrency1;
		pList->SetItemText(0, 4, _T(s.str().c_str()));


		CString currencyRate2str = pList->GetItemText(1, 1);
		stdStr = std::string{ CT2A(currencyRate2str) };

		double currencyRate2 = std::stod(stdStr);
		double valueInCurrency2 = (value - comission * value) / currencyRate2;

		s = std::stringstream();
		s << valueInCurrency2;
		pList->SetItemText(1, 4, _T(s.str().c_str()));


		CString currencyRate3str = pList->GetItemText(2, 1);
		stdStr = std::string{ CT2A(currencyRate3str) };

		double currencyRate3 = std::stod(stdStr);
		double valueInCurrency3 = (value - comission * value) / currencyRate3;

		s = std::stringstream();
		s << valueInCurrency3;
		pList->SetItemText(2, 4, _T(s.str().c_str()));

	}
	catch (const std::exception& e)
	{
		MessageBoxA("Введены некорректнын данные", "Ошибка", 0);
	}
}
