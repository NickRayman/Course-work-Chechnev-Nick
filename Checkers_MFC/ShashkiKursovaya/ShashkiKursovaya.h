
// ShashkiKursovaya.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CShashkiKursovayaApp:
// Сведения о реализации этого класса: ShashkiKursovaya.cpp
//

class CShashkiKursovayaApp : public CWinApp
{
public:
	CShashkiKursovayaApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CShashkiKursovayaApp theApp;
