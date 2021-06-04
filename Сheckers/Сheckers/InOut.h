#pragma once
#include <utility>
#include <iostream>
#include <map>
#include "Cell.h"
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
	static const pair<pair<size_t, size_t>, pair<size_t, size_t>>& GetMove();
	/*
	Заполняет доску string клетками
	*/
	static void DrawBoard(const map<pair<size_t, size_t>, Cell>& board);
private:
	/*
	Определяет позиции в string
	*/
	static const string& CastState(State state);

};

