

#pragma once

#include <functional>
#include <array>
#include <random>

const int ARR_SIZE = 20;

class CLesson007Dlg : public CDialogEx
{
// Создание
public:
	CLesson007Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Lesson007_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;
	std::random_device rd;
	std::mt19937 gen = std::mt19937(rd());
	std::array<int, ARR_SIZE> arr{};
	std::array<int, ARR_SIZE> arr2{};

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
