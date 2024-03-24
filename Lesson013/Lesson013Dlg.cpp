
// Lesson002test2Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Lesson013.h"
#include "Lesson013Dlg.h"
#include "Lesson013Dlg1.h"
#include "Lesson013Dlg2.h"
#include "CLesson013Dlg4.h"
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



CLesson013Dlg::CLesson013Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Lesson013_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLesson013Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLesson013Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_32771, &CLesson013Dlg::On32771)
	ON_COMMAND(ID_32772, &CLesson013Dlg::On32772)
	ON_COMMAND(ID_32773, &CLesson013Dlg::On32773)
	ON_COMMAND(ID_32774, &CLesson013Dlg::On32774)
END_MESSAGE_MAP()



BOOL CLesson013Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CMenu* pMenu = new CMenu();
	pMenu->LoadMenu(IDR_MENU1);
	SetMenu(pMenu);

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CLesson013Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	CDialogEx::OnSysCommand(nID, lParam);
	
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CLesson013Dlg::OnPaint()
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
HCURSOR CLesson013Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CLesson013Dlg::On32771()
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}


void CLesson013Dlg::On32772()
{
	EndDialog(IDCANCEL);
}


void CLesson013Dlg::On32773()
{
	CLesson013Dlg1 dlg;
	dlg.DoModal();
}


void CLesson013Dlg::On32774()
{
	CLesson013Dlg2 dlg;
	dlg.DoModal();
}
