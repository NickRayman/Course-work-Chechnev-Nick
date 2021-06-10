#include "CheckersManager.h"

CheckersManager::CheckersManager()
{
}

CheckersManager::~CheckersManager()
{
}

bool CheckersManager::Init()
{
	cout << "�������� � ��� �� ������ �������:" << endl;
	cout << "1 - ������ ��������� ����" << endl;
	cout << "2 - ������ AI" << endl;
	cin >> PlayVs;
	string playerName;
	this->board = new CheckersBoard();
	this->player1 = new CheckersPlayer();
	cout << "������� ��� ������, ��������� ������: ";
	cin >> playerName;
	//playerName = "White";
	player1->SetupPlayer(playerName, CellType_w); //��������� ��� � ��� ����� ������� ������
	player1->SetBoard(this->board); //�������� ������� ����� ������
	if (PlayVs == 1)
	{
		this->player2 = new CheckersPlayer();
		cout << "������� ��� ������, ��������� �������: ";
		cin >> playerName;
		cout << endl;
		player2->SetupPlayer(playerName, CellType_b); //��������� ��� � ��� ����� ������� ������
		player2->SetBoard(this->board); //�������� ������� ����� ������		
	}
	else
	{
		this->playerAI = new CheckersPlayer();
		playerName = "AIBot";
		playerAI->SetupPlayer(playerName, CellType_b); //��������� ��� � ��� ����� ������� ������
		playerAI->SetBoard(this->board); //�������� ������� ����� ������		
	}	
	currentPlayer = player1;
	return true;
}

void CheckersManager::MakeMove()
{
	ShowBoard();
	while (!currentPlayer->MakeMove())
	{
		cout << "������������ ���, ���������� ��� ���" << endl;
		ShowBoard(); //������� ������� ����� ��� ���
	}
	bGameFinished = currentPlayer->Victory();
	if (!bGameFinished)
	{
		if (PlayVs == 1)
			currentPlayer = (currentPlayer == player1) ? player2 : player1; //����� �������
		else
			currentPlayer = (currentPlayer == player1) ? playerAI : player1; //����� ������ � ����
	}
	else
		cout << "���� ��������! ������� " << currentPlayer->GetName() << endl;
		
}

bool CheckersManager::IsGameFinished()
{
	return bGameFinished;
}

void CheckersManager::ShowBoard()
{
	this->board->Show();
}
