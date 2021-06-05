#pragma once
#include <utility>
#include <iostream>
#include <map>
#include "Cell.h"
#include <algorithm>
#include <string>

using namespace std;

class InOut
{
public:

	/*
	Конструктор и деструктор
	*/
	InOut();
	~InOut();
	/*
	Возвращает позицию каждой клетки
	*/
	static pair<pair<size_t, size_t>, pair<size_t, size_t>> GetMove(string player);
	/*
	Заполняет доску string клетками
	*/
	static void DrawBoard(const map<pair<size_t, size_t>, Cell>& board);

	void PrintScore(size_t whiteScore, size_t blackScore);

	void endGame(string player);
private:
	/*
	Определяет позиции в string
	*/
	static string CastState(State state);

};

