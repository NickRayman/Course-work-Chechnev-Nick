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
	player1->SetupPlayer(playerName, CellType_w); //заполняем имя и тип шашек первого игрока
	player1->SetBoard(this->board); //передаем игровую доску игроку


	if (!BotOn) //если не бот
	{
		this->player2 = new CheckersPlayer();
		playerName = nameP2;
		player2->SetupPlayer(playerName, CellType_b); //заполняем имя и тип шашек второго игрока
		player2->SetBoard(this->board); //передаем игровую доску игроку		
	}
	else
	{
		this->playerAI = new CheckersPlayer();
		playerName = "AIBot";
		playerAI->SetupPlayer(playerName, CellType_b); //заполняем имя и тип шашек второго игрока
		playerAI->SetBoard(this->board); //передаем игровую доску игроку		
	}	
	currentPlayer = player1;
	return true;
}

void CheckersManager::MakeMove(int Fx, int Fy, int Sx, int Sy)
{
	/*ShowBoard();*/
	while (!currentPlayer->MakeMove(Fx, Fy, Sx, Sy))
	{
		//cout << "Недопустимый ход, попробуйте еще раз" << endl;
		//ShowBoard(); //выводим игровую доску еще раз
	}
	bGameFinished = currentPlayer->Victory();
	if (!bGameFinished)
	{
		if (!BotOn)
			currentPlayer = (currentPlayer == player1) ? player2 : player1; //смена игроков
		else
			currentPlayer = (currentPlayer == player1) ? playerAI : player1; //смена игрока и бота
	}
	else
		//cout << "Игра окончена! Победил " << currentPlayer->GetName() << endl;
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
