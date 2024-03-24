
// Lesson002test2Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Lesson009.h"
#include "Lesson009Dlg.h"
#include "afxdialogex.h"
#include <string>
#include <exception>
#define _USE_MATH_DEFINES
#include <math.h>
#include <sstream>
#include <array>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



int countWords(const std::string& str) {
	int wordCount = 0;
	bool inWord = false;
	std::setlocale(LC_ALL, "Russian");
	for (char ch : str) {
		if (std::isspace(ch)) {
			if (inWord) {
				inWord = false;
			}
		}
		else {
			if (!inWord) {
				inWord = true;
				++wordCount;
			}
		}
	}

	return wordCount;
}

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



CLesson009Dlg::CLesson009Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Lesson009_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLesson009Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLesson009Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLesson009Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLesson009Dlg::OnBnClickedButton2)
END_MESSAGE_MAP()



BOOL CLesson009Dlg::OnInitDialog()
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


	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST1);

	// Добавляем строки в List Box.
	pListBox->AddString(_T("1. Технология обработки информации"));
	pListBox->AddString(_T("2. Информатика / теоретическая информатика"));
	pListBox->AddString(_T("3. Технология программирования"));
	pListBox->AddString(_T("4. Базы данных"));
	pListBox->AddString(_T("5. Объектно-ориентированное программирование"));

	CListBox* pListBox2 = (CListBox*)GetDlgItem(IDC_LIST2);

	// Добавляем строки в List Box.
	pListBox2->AddString(_T("1. 1 1 1 0 1 0 1 1 0 1"));
	pListBox2->AddString(_T("2. 1 1 1 1 1 1"));
	pListBox2->AddString(_T("3. 0 0 0 0 0"));
	pListBox2->AddString(_T("4. 1 1 1 1 1 1 1 1 1 1 1 1"));
	pListBox2->AddString(_T("5. 0 0 0"));


	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CLesson009Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLesson009Dlg::OnPaint()
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
HCURSOR CLesson009Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CLesson009Dlg::OnBnClickedButton1()
{
	CStatic* staticText = (CStatic*)GetDlgItem(IDC_STATIC1);

	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST1);
	std::string stdStr;


	int nIndex = pListBox->GetCurSel();

	if (nIndex != LB_ERR)
	{
		CString strItemText;

		pListBox->GetText(nIndex, strItemText);

		stdStr = std::string{ CT2A(strItemText) };

		int count = countWords(stdStr);

		std::stringstream s;
		s << "Количество слов: " << count;

		staticText->SetWindowTextA(s.str().c_str());
	}
	else
	{
		staticText->SetWindowTextA("Строка не выбрана");
	}

}


void CLesson009Dlg::OnBnClickedButton2()
{
	CStatic* staticText = (CStatic*)GetDlgItem(IDC_STATIC2);

	CListBox* pListBox = (CListBox*)GetDlgItem(IDC_LIST2);
	std::string stdStr;


	int nIndex = pListBox->GetCurSel();

	if (nIndex != LB_ERR)
	{
		CString strItemText;

		pListBox->GetText(nIndex, strItemText);

		stdStr = std::string{ CT2A(strItemText) };

		int count = 0;
		for (int i = 0; i < stdStr.size(); i++)
		{
			if ((stdStr[i] == '1') || (stdStr[i] == '0'))
			{
				count++;
			}
		}

		std::stringstream s;
		s << "Количество 0 и 1: " << count;

		staticText->SetWindowTextA(s.str().c_str());
	}
	else
	{
		staticText->SetWindowTextA("Строка не выбрана");
	}
}
