
// Lesson008Dlg.h: файл заголовка
//

#pragma once

#include <array>
#include <random>

const int MAT1_SIZE = 4;
const int MAT2_SIZE = 15;

// Диалоговое окно CLesson008Dlg
class CLesson008Dlg : public CDialogEx
{
// Создание
public:
	CLesson008Dlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Lesson008_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	std::random_device rd;
	std::mt19937 gen = std::mt19937(rd());
	std::array<std::array<int, MAT1_SIZE>, MAT1_SIZE> mat1{};
	std::array<std::array<int, MAT2_SIZE>, MAT2_SIZE> mat2{};

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
