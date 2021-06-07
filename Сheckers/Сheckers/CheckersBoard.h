//Класс CheckersBoard.h для представления поля для игры
#pragma once

#include "CellTypes.h"//Подключаю перечисляемый класс (enum-CellTypes.h)
#include "pch.h"//Подключаю класс с массой нужных нам библиотек

class CheckersBoard
{
private:
	CellTypes** cells;//массив перечисляемого класса (enum-CellTypes.h)
	int boardSize = 8;//размер игрового поля
	int numberToRow(int num);//функция возврата строки
	int numberToCol(int num);//функция возврата столбца
	bool checkBounds(int row, int col);//функция для проверки границ
	bool canBeFigth(int rowFrom, int colFrom, int rowWhat, int colWhat);//функция для проверки, может ли шашка съесть шашку противника

public:
	CheckersBoard(int pattern);//конструктор для создания поля для шашек и их перемещения
	CheckersBoard(CheckersBoard* board);//конструктор кастомной шашечной доски, с добавлением своих параметров
	virtual ~CheckersBoard();//вирутальный деструктор, для очистки памяти
	void display();//функция показывает доску
	bool moveDraught(int from, int to);//функция двигает шашку
	bool checkRegulations(int from, CellTypes cell);//функция для проверки на нарушения правил
	bool checkEndGame();//функция для проверки окончания игры
	int* possibleЬMoves(int from, bool fight = false);//функция для получения количества возмодных ходов шашки
	int* possibleDraughts(CellTypes cell);//функция для получения количества шашек, которыми можно сходить
	CellTypes getCell(int row, int col);//функция возвращает тип клетки, по данной координате
	int rowAndColToNum(int row, int col);//функция для перевода строки и колонки в номер клетки

	/*
	Переопределение операторов: == и !=
	*/
	
	friend bool operator==(const CheckersBoard& left, const CheckersBoard& right);
	friend bool operator!=(const CheckersBoard& left, const CheckersBoard& right);

};

