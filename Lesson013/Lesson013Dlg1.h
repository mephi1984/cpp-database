#pragma once
#include "pch.h"
#include "framework.h"
#include <functional>
#include <string>

class CLesson013Dlg1 : public CDialogEx
{
// Создание
public:
	CLesson013Dlg1(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Lesson013_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	CToolBar m_ToolBar;
	CEdit m_EditBox;
	CStatic m_StaticText;
	CButton m_Button1;
	CButton m_Button2;
	CButton m_Button3;
	CButton m_Button4;
	CButton m_ButtonAdd;
	CButton m_ButtonDelete;
	CButton m_ButtonSave;

	int currentPos = 0;
	std::string currentPosText;
	std::string countText;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	void RefreshToolbar();

	std::vector<std::tuple<int, std::string, int, int, int, int, bool, std::string, std::string>> dishes;
	void fetchCurrentDish();

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
public:

};
