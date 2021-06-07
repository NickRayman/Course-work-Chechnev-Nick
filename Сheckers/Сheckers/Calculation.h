//Класс Calculation.h для рассчета определенных действий, совершаемых игроком
#pragma once
#include "pch.h"//Подключаю класс с массой нужных нам библиотек
#include "CheckersBoard.h"//Подкючаю класс CheckersBoard.h для представления поля для игры

class Calculation
{
private:
	int height = 3;
public:
	int* profitableMove = new int[2];

	Calculation(int height = 3);//конструктор для создания глубины хода
	~Calculation();//деструктор, для очистки памяти
	int calculatet(CellTypes cell, CheckersBoard* board, int height);//функция для рассчёта одного хода игрока
	int calculatetFight(CheckersBoard* board, CellTypes cell, int from);//функция для рассчёта поедания нескольких фигур противника
	int minMax(CellTypes cell, CheckersBoard* board, int height);//функция для рассчёта хода с помощью возможных будущих ходов
	int countValue(CheckersBoard* board, CellTypes cell);//функция для рассчёта положения на поле
};

