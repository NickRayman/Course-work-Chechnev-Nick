//Класс CheckersManager.h для управления игрой
#pragma once

#include "CheckersBoard.h"//Подключаю класс CheckersBoard.h для представления поля для игры/
#include "HumanPlayer.h"//Подключаю класс HumanPlayer.h для добавления игрока-человека
class CheckersManager
{
private:
	CheckersBoard* board;//указатель класса CheckersBoard
	HumanPlayer* player1;//указатель класса HumanPlayer
	HumanPlayer* player2;//указатель класса HumanPlayer
	HumanPlayer* currentPlayer;//указатель класса HumanPlayer
	unsigned int moves = 0;//интовая переменная для обозначения количества ходов
	bool bGameFinished = false;//булевая переменная для обозначения конца игры
	CheckersBoard** equalBoards;//массива для хранения клеток шашечного поля

	void showRules();//функция для показа правил игры
public:
	CheckersManager();//конструктор
	~CheckersManager();//деструктор для очистки памяти
	bool init();//функция для настройки игры
	void showBoard();//функция показывает доску
	void makeMove();//функция для совершения хода
	bool isGameFinished();//функция для проверки конца игры
};

