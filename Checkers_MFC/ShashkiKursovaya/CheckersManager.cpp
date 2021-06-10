#include "CheckersManager.h"

CheckersManager::CheckersManager()
{
}

CheckersManager::~CheckersManager()
{
}

bool CheckersManager::Init(string nameP1, string nameP2, bool BotP2)
{
	BotOn = BotP2;
	string playerName = nameP1;
	this->board = new CheckersBoard();
	this->player1 = new CheckersPlayer();
	player1->SetupPlayer(playerName, CellType_w); //��������� ��� � ��� ����� ������� ������
	player1->SetBoard(this->board); //�������� ������� ����� ������


	if (!BotOn) //���� �� ���
	{
		this->player2 = new CheckersPlayer();
		playerName = nameP2;
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

void CheckersManager::MakeMove(int Fx, int Fy, int Sx, int Sy)
{
	/*ShowBoard();*/
	while (!currentPlayer->MakeMove(Fx, Fy, Sx, Sy))
	{
		//cout << "������������ ���, ���������� ��� ���" << endl;
		//ShowBoard(); //������� ������� ����� ��� ���
	}
	bGameFinished = currentPlayer->Victory();
	if (!bGameFinished)
	{
		if (!BotOn)
			currentPlayer = (currentPlayer == player1) ? player2 : player1; //����� �������
		else
			currentPlayer = (currentPlayer == player1) ? playerAI : player1; //����� ������ � ����
	}
	else
		//cout << "���� ��������! ������� " << currentPlayer->GetName() << endl;
		return;
		
}

bool CheckersManager::IsGameFinished()
{
	return bGameFinished;
}

void CheckersManager::ShowBoard()
{
	this->board->Show();
}

CellType CheckersManager::CheckCellType(int x, int y)
{
	return this->board->CheckCellType(x, y);
}

string CheckersManager::GetWinnerName()
{
	return this->currentPlayer->GetName();
}
