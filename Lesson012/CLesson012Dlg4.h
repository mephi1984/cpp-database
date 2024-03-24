#pragma once
#include "afxdialogex.h"


// Диалоговое окно CLesson012Dlg4

class CLesson012Dlg4 : public CDialogEx
{
	DECLARE_DYNAMIC(CLesson012Dlg4)

public:
	CLesson012Dlg4(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~CLesson012Dlg4();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Lesson012_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
};
