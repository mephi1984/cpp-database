
// Lesson008.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CLesson008App:
// Сведения о реализации этого класса: Lesson008.cpp
//

class CLesson008App : public CWinApp
{
public:
	CLesson008App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CLesson008App theApp;
