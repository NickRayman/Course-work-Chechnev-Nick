
// ShashkiKursovayaDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "ShashkiKursovaya.h"
#include "ShashkiKursovayaDlg.h"
#include "afxdialogex.h"
#include "CStartupDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CShashkiKursovayaDlg



CShashkiKursovayaDlg::CShashkiKursovayaDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SHASHKIKURSOVAYA_DIALOG, pParent)
	, OutPut1(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShashkiKursovayaDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Text(pDX, IDC_EDIT1, OutPut1);
}

BEGIN_MESSAGE_MAP(CShashkiKursovayaDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CShashkiKursovayaDlg::OnBnClickedButton1)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// Обработчики сообщений CShashkiKursovayaDlg

BOOL CShashkiKursovayaDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	st1 = (CStatic*)GetDlgItem(IDC_STATIC);
	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CShashkiKursovayaDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CShashkiKursovayaDlg::OnPaint()
{
	CPaintDC dc(this);
	//отрисовка круга
	
	if (IsIconic())
	{
		//IDB_BITMAP1

		//CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{		
		CRect rect;
		GetClientRect(&rect);
		CDC  dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP1); // Фоновое изображение диалогового окна  
		BITMAP   bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap* pbmpOld = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(20, 28, 400, 400, &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

		CDialogEx::OnPaint();
		if(GameStarted)
			PaintCheckers(dc);
	}
	
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CShashkiKursovayaDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CShashkiKursovayaDlg::OnBnClickedButton1()
{
	CStartupDlg sdlg;
	sdlg.SetDlgParent(this);
	int nRes = sdlg.DoModal();

	if (nRes == IDOK)
	{
		GameStarted = true; //игра началась

		//HBITMAP startBitmap = (HBITMAP)LoadImage(NULL, L"res\\Board.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		//CShashkiKursovayaDlg::OnPaint();
		//this->Invalidate();
		////HANDLE test = LoadImage(NULL, L"res\\Board.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		//st1->SetBitmap(startBitmap);
		manager.Init(NameP1, NameP2, IsOponentAI);
		this->Invalidate();
		/*MessageBoxA(NULL, NameP1.c_str(), "testx", MB_OK);
		MessageBoxA(NULL, NameP2.c_str(), "testx", MB_OK);*/
	}
	
}

void CShashkiKursovayaDlg::CreatePlayer1(CString name)
{
	//NameP1 = string((LPCTSTR)name);
	NameP1 = CT2A(name.GetString());
}

void CShashkiKursovayaDlg::PaintChecker(CPaintDC& pDC, int x, int y, CellType ct)
{
	//цвета шашек
	CPen aPenG(PS_DASH, 3, RGB(0, 255, 0));//белая
	CPen aPenR(PS_DASH, 3, RGB(255, 0, 0));//черная
	//цвета королевы
	CPen aPenGQ(PS_DASH, 3, RGB(0, 255, 255));//белая
	CPen aPenRQ(PS_DASH, 3, RGB(255, 0, 255));//черная
	

	HGDIOBJ oldPen;

	switch (ct)
	{
	case CellType_W: //белая дамка
		oldPen = pDC.SelectObject(aPenGQ);
		pDC.Ellipse(x, y, x + 45, y + 45);
		pDC.SelectObject(oldPen);
		aPenGQ.DeleteObject();
		break;
	case CellType_w: //белая шашка
		oldPen = pDC.SelectObject(aPenG);
		pDC.Ellipse(x, y, x + 45, y + 45);
		pDC.SelectObject(oldPen);
		aPenG.DeleteObject();
		break;
	case CellType_B: //черная дамка
		oldPen = pDC.SelectObject(aPenRQ);
		pDC.Ellipse(x, y, x + 45, y + 45);
		pDC.SelectObject(oldPen);
		aPenRQ.DeleteObject();
		break;
	case CellType_b:  //черная шашка
		oldPen = pDC.SelectObject(aPenR);
		pDC.Ellipse(x, y, x + 45, y + 45);
		pDC.SelectObject(oldPen);
		aPenR.DeleteObject();
		break;
	case CellType_Empty: //пустое поле игровое поле		
		break;
	}
	
	//CPen* oldPen = pDC.SelectObject(&aPen1);//сохраняем старое перо
	

	
}

void CShashkiKursovayaDlg::CreatePlayer2(CString name, bool type)
{
	NameP2 = CT2A(name.GetString());
	IsOponentAI = type; 
	//определяем, против кого играем
	//человек - false
	//компьютер - true
}


void CShashkiKursovayaDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CPoint PointClick = point;

	if(GameStarted)
		if ((PointClick.x >= 40) && (PointClick.x <= 400)) //по x внутри доски
			if ((PointClick.y >= 48) && (PointClick.y <= 408)) //по y внутри доски
			{
				if (!IsSecondStep) //это первый ход
				{
					FirstStepX = (PointClick.x - 40) / 45; //передаем ячейку, шашки которой выбрали
					FirstStepY = (PointClick.y - 48) / 45;
					IsSecondStep = true;
					StepDone = false;
				}
				else
				{
					SecondStepX = (PointClick.x - 40) / 45; //передаем ячейку куда пойдем
					SecondStepY = (PointClick.y - 48) / 45;
					IsSecondStep = false;
					StepDone = true;
				}

				if (StepDone)
				{
					manager.MakeMove(FirstStepY, FirstStepX, SecondStepY, SecondStepX);
					if (manager.GetbGameFinished())
					{
						this->Invalidate();
						string EndGame = "Игра окончена, победил ";
						string nameWinner = manager.GetWinnerName();
						EndGame.append(nameWinner);
						if (MessageBoxA(NULL, EndGame.c_str(), "Информация об игре", MB_OK) == IDOK)
						{
							this->EndDialog(1);
						}

					}else if(IsOponentAI)
						manager.MakeMove(0, 0, 0, 0);
				}
				//узнаем номер ячейки для отрисовки
				/*int TimeX = (PointClick.x - 40) / 45;
				int TimeY = (PointClick.y - 48) / 45;*/

				/*Board[TimeX][TimeY] = 1;*/
				this->Invalidate();
				/*std::string test1 = std::to_string((PointClick.x - 40) / 45);
				std::string test2 = std::to_string((PointClick.y - 48) / 45);
				MessageBoxA(NULL, test1.c_str(), "testx", MB_OK);
				MessageBoxA(NULL, test2.c_str(), "testy", MB_OK);*/

			}
			
	//MessageBox((LPCTSTR)PointClick.x);
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	//MessageBox("text");CShashkiKursovayaDlg::OnPaint();
	CDialogEx::OnLButtonDown(nFlags, point);
}

void CShashkiKursovayaDlg::PaintCheckers(CPaintDC& pDC)
{
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			int TimeX1 = (i * 45) + 40;
			int TimeY1 = (j * 45) + 48;
			PaintChecker(pDC, TimeX1, TimeY1, manager.CheckCellType(i, j));	
			//передаем координаты для отрисовки
			//и тип шашки для отрисовки
		}			

			/*if (manager.CheckCellType(i,j))
			{
				int TimeX1 = (i * 45) + 40;
				int TimeY1 = (j * 45) + 48;
				PaintChecker(pDC, TimeX1, TimeY1);
			}*/
				
}