#pragma once
#include "pch.h"
#include "framework.h"
#include <functional>
#include "GridCtrl_src/GridCtrl.h"
#include <tuple>
#include <string>
class CLesson013Dlg2 : public CDialogEx
{
// Создание
public:
	CLesson013Dlg2(CWnd* pParent = nullptr);	// стандартный конструктор

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
	CGridCtrl m_Grid;

	std::vector<std::tuple<int, std::string, std::string, std::string, std::string, int, int, int>> workers;
	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	afx_msg void OnSize(UINT nType, int cx, int cy);
	void RefreshToolbar();

	afx_msg void OnBeginEdit(NMHDR* pNMHDR, LRESULT* pResult);

	afx_msg void OnEndEdit(NMHDR* pNMHDR, LRESULT* pResult);

	void SaveEverything();
public:
};
