//Класс CoumputerPlayer.h для добавления игрока-компьютера
#pragma once

#include "HumanPlayer.h"//Подключаю Класс HumanPlayer.h для наследования от него класса ComputerPlayer
#include "Calculation.h"//Подключаю класс Calculation.h для рассчета определенных действий, совершаемых игроком

class ComputerPlayer : public HumanPlayer
{
private:
	Calculation* e;//указаетль класса Calculation для рассчета определенных действий, совершаемых компьютерным игроком
	void contineToEat(int from);//функция для продолжения поедания нескольких фигур
public:

	ComputerPlayer();//конструктор
	virtual ~ComputerPlayer();//виртуальный деструктор
	virtual bool makeMove();//функция для совершения хода компьютерным игроком
};

