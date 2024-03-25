
// Lesson002test2Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Lesson013.h"
#include "Lesson013Dlg2.h"
#include "afxdialogex.h"
#include <string>
#include <exception>
#define _USE_MATH_DEFINES
#include <math.h>
#include <sstream>
#include "DatabaseClass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CLesson013Dlg2::CLesson013Dlg2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Lesson013_DIALOG2, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLesson013Dlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLesson013Dlg2, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
END_MESSAGE_MAP()



BOOL CLesson013Dlg2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	RefreshToolbar();


	
	CRect rectx;
	this->GetClientRect(rectx);

	m_Grid.Create(rectx, this, 1010);

	// Настройка колонок и строк
	m_Grid.SetColumnCount(5);
	m_Grid.SetRowCount(database.getWorkerCount());
	m_Grid.SetFixedRowCount(1);

	// Заполнение заголовков колонок
	m_Grid.SetItemText(0, 0, _T("Колонка 1"));
	m_Grid.SetItemText(0, 1, _T("Колонка 2"));
	m_Grid.SetItemText(0, 2, _T("Колонка 3"));
	m_Grid.SetItemText(0, 3, _T("Колонка 4"));
	m_Grid.SetItemText(0, 4, _T("Колонка 5"));

	// Заполнение ячеек данными
	for (int row = 1; row < m_Grid.GetRowCount(); row++)
	{
		for (int col = 0; col < m_Grid.GetColumnCount(); col++)
		{
			CString data;
			data.Format(_T("%d,%d"), row, col);
			m_Grid.SetItemText(row, col, data);
		}
	}

	// Активация редактирования ячеек
	m_Grid.SetEditable(TRUE);

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CLesson013Dlg2::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CLesson013Dlg2::OnPaint()
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
HCURSOR CLesson013Dlg2::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CLesson013Dlg2::RefreshToolbar()
{
	/*
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

	}*/
}
void CLesson013Dlg2::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	RefreshToolbar();

	CRect rectx;
	this->GetClientRect(rectx);
	//rectx.top += 30;

	if (m_Grid.GetSafeHwnd())
	{
		m_Grid.MoveWindow(rectx);
	}
}