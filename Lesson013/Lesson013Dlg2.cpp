
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
	ON_NOTIFY(GVN_BEGINLABELEDIT, 1010, OnBeginEdit) 
	ON_NOTIFY(GVN_ENDLABELEDIT, 1010, OnEndEdit)
END_MESSAGE_MAP()



BOOL CLesson013Dlg2::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	RefreshToolbar();


	
	CRect rectx;
	this->GetClientRect(rectx);

	m_Grid.Create(rectx, this, 1010);

	// Настройка колонок и строк
	m_Grid.SetColumnCount(8);
	m_Grid.SetRowCount(database.getWorkerCount()+1);
	m_Grid.SetFixedRowCount(1);

	// Заполнение заголовков колонок
	m_Grid.SetItemText(0, 0, _T("id"));
	m_Grid.SetItemText(0, 1, _T("Фамилия"));
	m_Grid.SetItemText(0, 2, _T("Имя"));
	m_Grid.SetItemText(0, 3, _T("Отчество"));
	m_Grid.SetItemText(0, 4, _T("Позиция"));
	m_Grid.SetItemText(0, 5, _T("Пол"));
	m_Grid.SetItemText(0, 6, _T("Семья"));
	m_Grid.SetItemText(0, 7, _T("Дети"));


	// Активация редактирования ячеек
	m_Grid.SetEditable(TRUE);

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	RefreshToolbar();

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
	if (m_Grid.GetSafeHwnd())
	{
		workers = database.getAllWorkers();



		// Заполнение ячеек данными
		for (int row = 1; row < m_Grid.GetRowCount(); row++)
		{
			auto& worker = workers[row - 1];


			std::stringstream s1;
			s1 << std::get<0>(worker);
			CString str1{ s1.str().c_str() };
			m_Grid.SetItemText(row, 0, str1);

			CString str2{ std::get<1>(worker).c_str() };
			m_Grid.SetItemText(row, 1, str2);

			CString str3{ std::get<2>(worker).c_str() };
			m_Grid.SetItemText(row, 2, str3);

			CString str4{ std::get<3>(worker).c_str() };
			m_Grid.SetItemText(row, 3, str4);

			CString str5{ std::get<4>(worker).c_str() };
			m_Grid.SetItemText(row, 4, str5);

			std::stringstream s6;
			s6 << std::get<5>(worker);
			CString str6{ s6.str().c_str() };
			m_Grid.SetItemText(row, 5, str6);

			std::stringstream s7;
			s7 << std::get<6>(worker);
			CString str7{ s7.str().c_str() };
			m_Grid.SetItemText(row, 6, str7);


			std::stringstream s8;
			s8 << std::get<7>(worker);
			CString str8{ s8.str().c_str() };
			m_Grid.SetItemText(row, 7, str8);
		}
	}
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


void CLesson013Dlg2::OnBeginEdit(NMHDR* pNMHDR, LRESULT* pResult)
{
	GV_ITEM* pItem = (GV_ITEM*)pNMHDR;
	// Здесь ваш код обработки начала редактирования
	*pResult = 0; // Установите 0, если редактирование разрешено, 1, если запрещено
}

void CLesson013Dlg2::OnEndEdit(NMHDR* pNMHDR, LRESULT* pResult)
{
	GV_ITEM* pItem = (GV_ITEM*)pNMHDR;
	try
	{
		SaveEverything();
		*pResult = 0;
	}
	catch (const std::exception& e)
	{
		*pResult = 1;
	}
}

void CLesson013Dlg2::SaveEverything()
{
	std::vector<std::tuple<int, std::string, std::string, std::string, std::string, int, int, int>> oldWorkers = workers;
	std::string stdStr;
	// Заполнение ячеек данными
	for (int row = 1; row < m_Grid.GetRowCount(); row++)
	{
		CString idStr = m_Grid.GetItemText(row, 0);
		stdStr = std::string{ CT2A(idStr) };
		int id = std::stoi(stdStr);
		std::get<0>(workers[row - 1]) = id;

		std::string lastNameStdStr;
		CString lastNameStr = m_Grid.GetItemText(row, 1);
		lastNameStdStr = std::string{ CT2A(lastNameStr) };
		std::get<1>(workers[row - 1]) = lastNameStdStr;

		std::string firstNameStdStr;
		CString firstNameStr = m_Grid.GetItemText(row, 2);
		firstNameStdStr = std::string{ CT2A(firstNameStr) };
		std::get<2>(workers[row - 1]) = firstNameStdStr;

		std::string middleNameStdStr;
		CString middleNameStr = m_Grid.GetItemText(row, 3);
		middleNameStdStr = std::string{ CT2A(middleNameStr) };
		std::get<3>(workers[row - 1]) = middleNameStdStr;

		std::string positionStdStr;
		CString positionStr = m_Grid.GetItemText(row, 4);
		positionStdStr = std::string{ CT2A(positionStr) };
		std::get<4>(workers[row - 1]) = positionStdStr;


		CString genderStr = m_Grid.GetItemText(row, 5);
		stdStr = std::string{ CT2A(genderStr) };
		int gender = std::stoi(stdStr);
		std::get<5>(workers[row - 1]) = gender;


		CString familyStr = m_Grid.GetItemText(row, 6);
		stdStr = std::string{ CT2A(familyStr) };
		int family = std::stoi(stdStr);
		std::get<6>(workers[row - 1]) = family;


		CString childrenStr = m_Grid.GetItemText(row, 7);
		stdStr = std::string{ CT2A(childrenStr) };
		int children = std::stoi(stdStr);
		std::get<7>(workers[row - 1]) = children;
	}

	for (int i = 0; i < workers.size(); i++)
	{
		database.updateWorker(std::get<0>(oldWorkers[i]), workers[i]);
	}
}