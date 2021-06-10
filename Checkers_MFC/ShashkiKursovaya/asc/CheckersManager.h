#pragma once
#include "pch.h"
#include "CheckersBoard.h"
#include "CheckersPlayer.h"

class CheckersManager
{
private:
	CheckersBoard* board;
	CheckersPlayer* player1;
	CheckersPlayer* player2;
	CheckersPlayer* playerAI;
	CheckersPlayer* currentPlayer;
	bool bGameFinished = false; //переменная отвечающая за окончание игры

public:
	int PlayVs;
	CheckersManager();
	~CheckersManager();
	bool Init();
	void MakeMove(); //реализация игры, а именно ходов
	bool IsGameFinished(); //метод вывода информации об окночании игры
	void ShowBoard();
};

