
// Lesson010.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CLesson010App:
// Сведения о реализации этого класса: Lesson010.cpp
//

class CLesson010App : public CWinApp
{
public:
	CLesson010App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CLesson010App theApp;
