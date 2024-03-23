
// Lesson002test2Dlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "Lesson003.h"
#include "Lesson003Dlg.h"
#include "afxdialogex.h"
#include <string>
#include <exception>
#define _USE_MATH_DEFINES
#include <math.h>

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



CLesson003Dlg::CLesson003Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LESSON003_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLesson003Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLesson003Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CLesson003Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()



BOOL CLesson003Dlg::OnInitDialog()
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

	
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CLesson003Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLesson003Dlg::OnPaint()
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
HCURSOR CLesson003Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CLesson003Dlg::OnBnClickedButton1()
{
	drawFunction(IDC_PIC1, [](double x) { return sin(x); });
	drawFunction(IDC_PIC2, [](double x) { return sin(x) + cos(x); });
	drawFunction(IDC_PIC3, [](double x) { return sin(x)/cos(x); });
	drawFunction(IDC_PIC4, [](double x) { return cos(x)/sin(x); });
}

void CLesson003Dlg::drawFunction(int elementIndex, std::function<double(double)> f)
{
	CStatic* pic1 = (CStatic*)GetDlgItem(elementIndex);

	// Получаем контекст устройства для PictureControl
	CDC* pDC = pic1->GetDC();


	// Получаем размеры клиентской области PictureControl
	CRect rect;
	pic1->GetClientRect(&rect);

	// Создаем белую кисть
	CBrush brush(RGB(255, 255, 255)); // Белый цвет

	// Заполняем область PictureControl белым цветом
	pDC->FillRect(rect, &brush);

	// Создаем и выбираем перо для рисования линии
	CPen pen1(PS_SOLID, 1, RGB(0, 0, 0)); // Красное перо толщиной в 2 пикселя
	CPen* pOldPen = pDC->SelectObject(&pen1);

	// Рисуем линию от точки (10, 10) к точке (100, 100)
	pDC->MoveTo(10, 0);
	pDC->LineTo(10, 100);

	pDC->MoveTo(0, 60);
	pDC->LineTo(750, 60);

	const double shiftX = 10;
	const double shiftY = 60;
	const double scaleX = 10;
	const double scaleY = -10;

	CPen pen2(PS_SOLID, 1, RGB(255, 0, 0)); // Красное перо толщиной в 2 пикселя
	pDC->SelectObject(&pen2);

	pDC->MoveTo(shiftX, shiftY);

	for (int i = 0; i < 750; i++)
	{
		double x = i / scaleX;
		double y = f(x)* scaleY;
		if (y < -60)
		{
			y = -60;
		}
		if (y > 60)
		{
			y = 60;
		}
		pDC->LineTo(shiftX + i, shiftY + y);
		pDC->MoveTo(shiftX + i, shiftY + y);
	}

	

	// Возвращаем старое перо обратно
	pDC->SelectObject(pOldPen);

	// Освобождаем контекст устройства
	pic1->ReleaseDC(pDC);
	pic1->Invalidate();
}