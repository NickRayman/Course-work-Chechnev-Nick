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
	bool bGameFinished = false; //���������� ���������� �� ��������� ����

public:
	int PlayVs;
	CheckersManager();
	~CheckersManager();
	bool Init();
	void MakeMove(); //���������� ����, � ������ �����
	bool IsGameFinished(); //����� ������ ���������� �� ��������� ����
	void ShowBoard();
};

