#pragma once
#include "Cell.h"
#include "MoveResult.h"
#include <map>//подключу мапу (коллекцию, улучшенный массив с ключами) для удобства в работе

using namespace std;

/*
Класс клетка (Board), для расположения шашек
*/
class Board
{
public:

	/*
	Конструктор и деструктор
	*/
	Board();
	~Board();
	
	/*
	Функция для заполнения данными массива cCells
	*/
	void ResetMap();

	/*
	Функция проверяет позиции шашек
	*/
	MoveResult MakeMove(const pair <size_t, size_t>& startPos, const pair <size_t, size_t>& endPos, bool direction, bool forceCombat);
	const map<pair <size_t, size_t>, Cell>& GetMap() const;
private:
	map<pair <size_t, size_t>, Cell> cCells;
	const size_t cBoardSize;
	/*
	Функция проверяет позиции шашек
	*/
	MoveResult CheckMove(const pair <size_t, size_t>& startPos, const pair <size_t, size_t>& endPos, bool direction);
};

