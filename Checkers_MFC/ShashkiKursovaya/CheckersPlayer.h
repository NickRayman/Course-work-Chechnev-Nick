#pragma once
#include "CheckersBoard.h"
class CheckersPlayer
{
private:
	CheckersBoard* board; //игровая доска
	CellType cellType; //тип шашек, которыми пользуется игрок
	string name; // имя игрока
	unsigned int row, col; //строка и колонна
public:
	CheckersPlayer();
	virtual ~CheckersPlayer();
	void SetupPlayer(string name, CellType cellType); //Метод заполнения имени и типа используемых шашек игроков
	void SetBoard(CheckersBoard* board);  //получение игровой доски
	string GetName(); //возвращает имя игрока
	bool MakeMove(int Fx, int Fy, int Sx, int Sy); //Ход игрока
	bool TakeChecker(int Fx, int Fy); //Проверка выбранной шашки		
	bool Victory();
};

