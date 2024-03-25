
// Lesson002test2Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Lesson013.h"
#include "Lesson013Dlg1.h"
#include "afxdialogex.h"
#include <string>
#include <exception>
#define _USE_MATH_DEFINES
#include <math.h>
#include <sstream>
#include "DatabaseClass.h"
#include <tuple>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CLesson013Dlg1::CLesson013Dlg1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Lesson013_DIALOG1, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLesson013Dlg1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLesson013Dlg1, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_BN_CLICKED(1002, &CLesson013Dlg1::OnBnClickedButton1)
	ON_BN_CLICKED(1003, &CLesson013Dlg1::OnBnClickedButton2)
	ON_BN_CLICKED(1004, &CLesson013Dlg1::OnBnClickedButton3)
	ON_BN_CLICKED(1005, &CLesson013Dlg1::OnBnClickedButton4)
	ON_BN_CLICKED(1006, &CLesson013Dlg1::OnBnClickedButton5)
	ON_BN_CLICKED(1007, &CLesson013Dlg1::OnBnClickedButton6)
	ON_BN_CLICKED(1008, &CLesson013Dlg1::OnBnClickedButton7)
END_MESSAGE_MAP()



BOOL CLesson013Dlg1::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	if ((!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC))/* || !m_ToolBar.LoadToolBar(IDR_TOOLBAR1)*/)
	{
		TRACE0("Не удалось создать панель инструментов\n");
		return FALSE;      // не удалось создать
	}

	m_Button1.Create("|<", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_FLAT, CRect(0, 0, 25, 20), &m_ToolBar, 1002);
	m_Button2.Create("<", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_FLAT, CRect(0, 0, 25, 20), &m_ToolBar, 1003);
	m_Button3.Create(">", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_FLAT, CRect(0, 0, 25, 20), &m_ToolBar, 1004);
	m_Button4.Create(">|", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_FLAT, CRect(0, 0, 25, 20), &m_ToolBar, 1005);

	m_EditBox.Create(WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL, CRect(0, 0, 30, 20), &m_ToolBar, 1001);

	if (!m_StaticText.Create("of 0", WS_VISIBLE | WS_CHILD | SS_LEFT,
		CRect(0, 0, 50, 25), &m_ToolBar))
	{
		TRACE0("Не удалось создать статический текст\n");
		return FALSE;      // не удалось создать
	}

	m_ButtonAdd.Create("+", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_FLAT, CRect(0, 0, 25, 20), &m_ToolBar, 1006);
	m_ButtonDelete.Create("X", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_FLAT, CRect(0, 0, 25, 20), &m_ToolBar, 1007);
	m_ButtonSave.Create("SAVE", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON | BS_FLAT, CRect(0, 0, 50, 20), &m_ToolBar, 1008);


	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);
	RefreshToolbar();


	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CLesson013Dlg1::RefreshToolbar()
{
	if (m_ToolBar.GetSafeHwnd())
	{
		dishes = database.getAllDishes();
		fetchCurrentDish();

		m_ToolBar.MoveWindow(0, 0, 300, 25);
		// Вычислите новую позицию для CEdit на Toolbar
		CRect rect;
		m_ToolBar.GetItemRect(m_ToolBar.GetToolBarCtrl().CommandToIndex(1001), &rect);
		rect.left += 2; // Отступ для визуального разделения
		rect.top += 2;
		rect.right = rect.left + 25; 
		rect.bottom = rect.top + 20; 
		m_Button1.MoveWindow(&rect);

		m_ToolBar.GetItemRect(m_ToolBar.GetToolBarCtrl().CommandToIndex(1001), &rect);
		rect.left += 2 + 25;
		rect.top += 2;
		rect.right = rect.left + 25;
		rect.bottom = rect.top + 20;
		m_Button2.MoveWindow(&rect);

		m_ToolBar.GetItemRect(m_ToolBar.GetToolBarCtrl().CommandToIndex(1001), &rect);
		rect.left += 2 + 50;
		rect.top += 2;
		rect.right = rect.left + 30;
		rect.bottom = rect.top + 20;
		m_EditBox.MoveWindow(&rect);

		std::stringstream s1;
		s1 << (currentPos+1);
		currentPosText = s1.str();
		m_EditBox.SetWindowTextA(currentPosText.c_str());

		m_ToolBar.GetItemRect(m_ToolBar.GetToolBarCtrl().CommandToIndex(1001), &rect);
		rect.left += 2 + 80;
		rect.top += 2;
		rect.right = rect.left + 50;
		rect.bottom = rect.top + 20;
		m_StaticText.MoveWindow(&rect);
		
		std::stringstream s;
		s << " of " << dishes.size();
		
		countText = s.str();
		m_StaticText.SetWindowTextA(countText.c_str());

		m_ToolBar.GetItemRect(m_ToolBar.GetToolBarCtrl().CommandToIndex(1001), &rect);
		rect.left += 2 + 80 + 50;
		rect.top += 2;
		rect.right = rect.left + 25;
		rect.bottom = rect.top + 20;
		m_Button3.MoveWindow(&rect);
		
		
		m_ToolBar.GetItemRect(m_ToolBar.GetToolBarCtrl().CommandToIndex(1001), &rect);
		rect.left += 2 + 80 + 50 + 25;
		rect.top += 2;
		rect.right = rect.left + 25;
		rect.bottom = rect.top + 20;
		m_Button4.MoveWindow(&rect);

		m_ToolBar.GetItemRect(m_ToolBar.GetToolBarCtrl().CommandToIndex(1001), &rect);
		rect.left += 2 + 80 + 50 + 25 + 25;
		rect.top += 2;
		rect.right = rect.left + 25;
		rect.bottom = rect.top + 20;
		m_ButtonAdd.MoveWindow(&rect);

		m_ToolBar.GetItemRect(m_ToolBar.GetToolBarCtrl().CommandToIndex(1001), &rect);
		rect.left += 2 + 80 + 50 + 25 + 25 + 25;
		rect.top += 2;
		rect.right = rect.left + 25;
		rect.bottom = rect.top + 20;
		m_ButtonDelete.MoveWindow(&rect);

		m_ToolBar.GetItemRect(m_ToolBar.GetToolBarCtrl().CommandToIndex(1001), &rect);
		rect.left += 2 + 80 + 50 + 25 + 25 + 25 + 25;
		rect.top += 2;
		rect.right = rect.left + 50;
		rect.bottom = rect.top + 20;
		m_ButtonSave.MoveWindow(&rect);

	}
}
void CLesson013Dlg1::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	RefreshToolbar();
}

void CLesson013Dlg1::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CLesson013Dlg1::OnPaint()
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
HCURSOR CLesson013Dlg1::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLesson013Dlg1::fetchCurrentDish()
{
	using namespace std;

	tuple<int, string, int, int, int, int, bool, string, string> value = dishes[currentPos];

	CEdit* edit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
	std::stringstream s1;
	s1 << get<0>(value);
	edit1->SetWindowTextA(s1.str().c_str());

	CEdit* edit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
	edit3->SetWindowTextA(get<1>(value).c_str());

	//....

	CEdit* edit6 = (CEdit*)GetDlgItem(IDC_EDIT6);
	std::stringstream s6;
	s6 << get<3>(value);
	edit6->SetWindowTextA(s6.str().c_str());

	CEdit* edit7 = (CEdit*)GetDlgItem(IDC_EDIT7);
	std::stringstream s7;
	s7 << get<4>(value);
	edit7->SetWindowTextA(s7.str().c_str());

	//....

	CEdit* edit9 = (CEdit*)GetDlgItem(IDC_EDIT9);
	edit9->SetWindowTextA(get<7>(value).c_str());

	CEdit* edit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
	edit2->SetWindowTextA(get<8>(value).c_str());

	/*
	CString str;
	std::string stdStr;
	try
	{
		GetDlgItemText(IDC_EDIT1, str);
		stdStr = std::string{ CT2A(str) };

		double a = std::stod(stdStr);

		GetDlgItemText(IDC_EDIT2, str);
		stdStr = std::string{ CT2A(str) };

		double b = std::stod(stdStr);

		GetDlgItemText(IDC_EDIT3, str);
		stdStr = std::string{ CT2A(str) };

		double x = std::stod(stdStr);

		double y = 0;

		y = cos(x - a) / (exp(x - a) + sqrt(abs(b * x)));

		std::stringstream s;
		s << "A=" << a << "\r\n";
		s << "B=" << b << "\r\n";
		s << "X=" << x << "\r\n";
		s << "Результат: " << "\r\n";
		s << "Y=" << y << "\r\n";

		edit4->SetWindowTextA(s.str().c_str());
	}
	catch (const std::exception& e)
	{
		edit4->SetWindowTextA("Ошибка: невозможно выполнить расчет");
	}*/

}

void CLesson013Dlg1::OnBnClickedButton1()
{
	currentPos = 0;
	RefreshToolbar();
}
void CLesson013Dlg1::OnBnClickedButton2()
{
	currentPos--;
	if (currentPos < 0)
	{
		currentPos = 0;
	}
	RefreshToolbar();
}
void CLesson013Dlg1::OnBnClickedButton3()
{
	currentPos++;
	if (currentPos > this->dishes.size() - 1)
	{
		currentPos = this->dishes.size() - 1;
	}
	RefreshToolbar();

}
void CLesson013Dlg1::OnBnClickedButton4()
{
	currentPos = this->dishes.size() - 1;
	RefreshToolbar();
}
void CLesson013Dlg1::OnBnClickedButton5()
{
	int id = database.createNewDish();
	dishes = database.getAllDishes();
	for (int i = 0; i < dishes.size(); i++)
	{
		auto& dish = dishes[i];
		if (std::get<0>(dish) == id)
		{
			currentPos = i;
			RefreshToolbar();
			return;
		}
	}

}
void CLesson013Dlg1::OnBnClickedButton6()
{
	auto& dish = dishes[currentPos];
	database.deleteDish(std::get<0>(dish));
	currentPos = 0;
	RefreshToolbar();
}
void CLesson013Dlg1::OnBnClickedButton7()
{

}
