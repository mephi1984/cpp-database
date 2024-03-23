
// Lesson002test2.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CLesson002test2App:
// Сведения о реализации этого класса: Lesson002test2.cpp
//

class CLesson002test2App : public CWinApp
{
public:
	CLesson002test2App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CLesson002test2App theApp;
