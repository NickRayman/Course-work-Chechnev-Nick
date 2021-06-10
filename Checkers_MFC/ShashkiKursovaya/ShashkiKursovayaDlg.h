
// ShashkiKursovayaDlg.h: файл заголовка
//

#pragma once
#include "CheckersManager.h"

// Диалоговое окно CShashkiKursovayaDlg
class CShashkiKursovayaDlg : public CDialogEx
{
// Создание
public:
	CShashkiKursovayaDlg(CWnd* pParent = nullptr);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHASHKIKURSOVAYA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	CStatic* st1;
public:
	afx_msg void OnBnClickedButton1();
	void CreatePlayer2(CString name, bool type);
	void CreatePlayer1(CString name);
	void PaintChecker(CPaintDC& pDC, int x, int y, CellType ct);
	CString OutPut1;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
private:
	void PaintCheckers(CPaintDC& pDC);	
	CheckersManager manager;
	//int** Board;
	bool GameStarted = false;
	string NameP1, NameP2;
	bool IsOponentAI, IsSecondStep = false, StepDone = false;
	int FirstStepX, FirstStepY, SecondStepX, SecondStepY;

};
