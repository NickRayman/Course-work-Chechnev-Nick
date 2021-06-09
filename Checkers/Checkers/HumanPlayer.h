//Класс HumanPlayer.h для добавления игрока-человека
#pragma once

#include "pch.h"//Подключаю класс с массой нужных нам библиотек
#include "CheckersBoard.h"//Подкючаю класс CheckersBoard.h для представления поля для игры
#include "Calculation.h"//Подключаю класс Calculation.h для рассчета определенных действий, совершаемых игроком

class HumanPlayer
{
protected:
	CheckersBoard* board;//указатель класса CheckersBoard
	string name;//стринговый объект
	void contineToEat(int from);//функция для продолжения поедания нескольких фигур
public:
	CellTypes cellType;//объект класса CellType
	HumanPlayer();//конструктор
	virtual ~HumanPlayer();//виртуальный деструктор
	void setupPlayer(string name, CellTypes cellType);//функция для настройки парметров игрока
	void setBoard(CheckersBoard* board);//функция для установки соотношений между доской и игроком
	virtual bool makeMove();//функция для совершения хода игроком человеком
	string getName();//фунция для возврата имени игрока
};

