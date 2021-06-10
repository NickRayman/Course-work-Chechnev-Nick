// CStartupDlg.cpp: файл реализации
//

#include "pch.h"
#include "ShashkiKursovaya.h"
#include "CStartupDlg.h"
#include "afxdialogex.h"


// Диалоговое окно CStartupDlg

IMPLEMENT_DYNAMIC(CStartupDlg, CDialogEx)

CStartupDlg::CStartupDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOGMenu, pParent)
	, FPlayerName(_T(""))
	, SPlayerName(_T(""))
	, AIPlayerOn(FALSE)
{

}

CStartupDlg::~CStartupDlg()
{
}

void CStartupDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, FPlayerName);
	DDX_Text(pDX, IDC_EDIT3, SPlayerName);
	DDX_Check(pDX, IDC_CHECK1, AIPlayerOn);
}


BEGIN_MESSAGE_MAP(CStartupDlg, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &CStartupDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDOK, &CStartupDlg::OnBnClickedOk)
	ON_BN_CLICKED(ID_STARTBUTTON, &CStartupDlg::OnBnClickedStartbutton)
END_MESSAGE_MAP()


// Обработчики сообщений CStartupDlg


void CStartupDlg::OnBnClickedCheck1()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CStartupDlg::OnBnClickedOk()
{
	// TODO: добавьте свой код обработчика уведомлений
	CDialogEx::OnOK();
}


void CStartupDlg::OnBnClickedStartbutton()
{
	// TODO: добавьте свой код обработчика уведомлений
	UpdateData(TRUE);
	if ((FPlayerName == L"") || (SPlayerName == L""))
	{
		AfxMessageBox(L"Имя не может быть пустым");
	}
	dlgParent->CreatePlayer1(FPlayerName);
	dlgParent->CreatePlayer2(SPlayerName, IsDlgButtonChecked(IDC_CHECK1));
	this->EndDialog(IDOK);
}

void CStartupDlg::SetDlgParent(CShashkiKursovayaDlg* p)
{
	this->dlgParent = p;
}
