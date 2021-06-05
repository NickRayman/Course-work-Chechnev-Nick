#pragma once
#include "Winner.h"
#include "Board.h"
#include "InOut.h"
#include <stdlib.h>
class Game
{
public:
	/*
	Конструктор и деструктор
	*/
	Game();
	~Game();

	void Start();
	/*
	Геттеры
	*/
	Player GetWinner() const;
private:
	string CastPlayer(Player player) const;
	string GetCurrentPlayer() const;
	void UpdateScore();
	void SwitchPlayer();
	pair<pair<size_t, size_t>, pair<size_t, size_t>> makeIO();
	bool GetDirection() const;
	size_t cWhiteScore;
	size_t cBlackScore;
	Player cLastPlayer;
	bool cIsSurrender;
	Board cBoard;
	InOut cIO;
};

