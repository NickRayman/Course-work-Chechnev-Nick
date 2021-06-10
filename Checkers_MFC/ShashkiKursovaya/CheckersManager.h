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
	bool BotOn;
public:
	int PlayVs;
	CheckersManager();
	~CheckersManager();
	bool Init(string nameP1, string nameP2, bool BotP2);
	void MakeMove(int Fx, int Fy, int Sx, int Sy); //реализация игры, а именно ходов
	bool IsGameFinished(); //метод вывода информации об окночании игры
	void ShowBoard();
	bool GetbGameFinished() { return bGameFinished; };
	CellType CheckCellType(int x, int y);
	string GetWinnerName();
};

