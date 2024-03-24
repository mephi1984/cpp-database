
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

		m_ToolBar.GetItemRect(m_ToolBar.GetToolBarCtrl().CommandToIndex(1001), &rect);
		rect.left += 2 + 80;
		rect.top += 2;
		rect.right = rect.left + 50;
		rect.bottom = rect.top + 20;
		m_StaticText.MoveWindow(&rect);

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
