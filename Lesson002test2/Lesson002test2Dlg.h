
// Lesson002test2Dlg.h: файл заголовка
//

#pragma once


// Диалоговое окно CLesson002test2Dlg
class CLesson002test2Dlg : public CDialogEx
{
// Создание
public:
	CLesson002test2Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LESSON002TEST2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	double value1 = 0.0;
	double value2 = 0.0;
	void calcAndOutput();

public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
};
