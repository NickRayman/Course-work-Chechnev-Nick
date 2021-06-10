#include "CheckersManager.h"

CheckersManager::CheckersManager()
{
}

CheckersManager::~CheckersManager()
{
}

bool CheckersManager::Init()
{
	cout << "¬ыберите с кем вы хотите сыграть:" << endl;
	cout << "1 - против реального игра" << endl;
	cout << "2 - против AI" << endl;
	cin >> PlayVs;
	string playerName;
	this->board = new CheckersBoard();
	this->player1 = new CheckersPlayer();
	cout << "¬ведите им€ игрока, играющего Ѕелыми: ";
	cin >> playerName;
	//playerName = "White";
	player1->SetupPlayer(playerName, CellType_w); //заполн€ем им€ и тип шашек первого игрока
	player1->SetBoard(this->board); //передаем игровую доску игроку
	if (PlayVs == 1)
	{
		this->player2 = new CheckersPlayer();
		cout << "¬ведите им€ игрока, играющего „ерными: ";
		cin >> playerName;
		cout << endl;
		player2->SetupPlayer(playerName, CellType_b); //заполн€ем им€ и тип шашек второго игрока
		player2->SetBoard(this->board); //передаем игровую доску игроку		
	}
	else
	{
		this->playerAI = new CheckersPlayer();
		playerName = "AIBot";
		playerAI->SetupPlayer(playerName, CellType_b); //заполн€ем им€ и тип шашек второго игрока
		playerAI->SetBoard(this->board); //передаем игровую доску игроку		
	}	
	currentPlayer = player1;
	return true;
}

void CheckersManager::MakeMove()
{
	ShowBoard();
	while (!currentPlayer->MakeMove())
	{
		cout << "Ќедопустимый ход, попробуйте еще раз" << endl;
		ShowBoard(); //выводим игровую доску еще раз
	}
	bGameFinished = currentPlayer->Victory();
	if (!bGameFinished)
	{
		if (PlayVs == 1)
			currentPlayer = (currentPlayer == player1) ? player2 : player1; //смена игроков
		else
			currentPlayer = (currentPlayer == player1) ? playerAI : player1; //смена игрока и бота
	}
	else
		cout << "»гра окончена! ѕобедил " << currentPlayer->GetName() << endl;
		
}

bool CheckersManager::IsGameFinished()
{
	return bGameFinished;
}

void CheckersManager::ShowBoard()
{
	this->board->Show();
}
