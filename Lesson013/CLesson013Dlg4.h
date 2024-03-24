#pragma once
#include "afxdialogex.h"


// Диалоговое окно CLesson013Dlg4

class CLesson013Dlg4 : public CDialogEx
{
	DECLARE_DYNAMIC(CLesson013Dlg4)

public:
	CLesson013Dlg4(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CLesson013Dlg4();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Lesson013_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
