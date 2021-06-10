#include "CheckersPlayer.h"

CheckersPlayer::CheckersPlayer()
{
}

CheckersPlayer::~CheckersPlayer()
{
}

void CheckersPlayer::SetupPlayer(string name, CellType cellType)
{
	this->name = name; //записываем имя игрока
	this->cellType = cellType; //записываем тип шашек игрока
}

void CheckersPlayer::SetBoard(CheckersBoard* board)
{
	this->board = board;
}

string CheckersPlayer::GetName()
{
	return this->name;
}

bool CheckersPlayer::MakeMove(int Fx, int Fy, int Sx, int Sy)
{
	//здесь реализуем вызов и бота
	if (GetName() == "AIBot")
	{
		if (board->GetQuantityBot()) //если бот сделал ход
		{
			return true;
		}
		return false;
	}
	else
	{

		if (TakeChecker(Fx, Fy)) //вызов метода проверки верности выбранной шашки
		{
			unsigned int row1, col1;
			unsigned int flagMove = 0;
			unsigned int flagEnd = 0;
			unsigned int TriedEatNext = 0;
			do
			{
				row1 = Sx;
				col1 = Sy;
				if (flagEnd > 0) //если мы пытаемся второй раз съесть
				{
					row = row1; //записываем новые координаты фишки
					col = col1; //записываем новые координаты фишки
					/*board->Show();*/
					/*cout << endl;*/

					switch (cellType)
					{
					case CellType_w:
						if (!TriedEatNext)
						{
							row1=row1-2;
							col1=col1+2;
							TriedEatNext++;
							if ((row1 < 0) || (col1 < 0))
								return false;
						}
						else
						{
							row1 = row1 - 2;
							col1 = col1 - 2;
							TriedEatNext++;
							if ((row1 < 0) || (col1 < 0))
								return false;
						}
						break;
					case CellType_b:
						if (!TriedEatNext)
						{
							row1 = row1 + 2;
							col1 = col1 + 2;
							TriedEatNext++;
							if ((row1 < 0) || (col1 < 0))
								return false;
						}
						else
						{
							row1 = row1 + 2;
							col1 = col1 - 2;
							TriedEatNext++;
							if ((row1 < 0) || (col1 < 0))
								return false;
						}
						break;
					}
				}
				if (!this->board->CheckPosMove(col, row, cellType))
					return true; //если нет возможных ходов происходит смена игроков (Реализовано для повторного поедания)
				/*cout << "Игрок " << name << ", выберите куда пойти..." << endl;
				cout << "Введите строку: ";*/
				
				if (flagEnd == flagMove) //проверка на второе поедание
					if (this->board->CheckLegalMove(col, row, col1, row1))
					{
						//вызываем метод отрисовки новой позиции шашки
						board->PaintCell(col1, row1, cellType);
						//вызываем метод для удаления старой позиции шашки
						board->ClearCell(col, row);
						flagMove++; //флаг для обычного хода
						return true;
					}
				flagEnd++; //флаг для всего запуска цикла
			} while ((this->board->CheckLegalEat(col, row, col1, row1)) || TriedEatNext == 1); //если мы съели шашку противника будет запрос на новый ход
			if (flagEnd >= 2)
				return true;

		}
		return false; //если введенные координаты шашки неверные (будет выведена ошибка)
	}
}

bool CheckersPlayer::TakeChecker(int Fx, int Fy)
{
	//unsigned int row, col; //row - Y, col - X
	/*cout << "Игрок " << name << ", выберите шашку..." << endl;
	cout << "Введите строку выбранной шашки: ";*/
	row = Fx;
	/*cout << "Введите столбец выбранной шашки: ";*/
	col = Fy;
	if (this->board->CheckPosMove(col, row, cellType)) //вызов метода возможности ходов выбранной шашки
	{
		return true; //взята верная шашка
	}

	return false; //взята неверная шашка
}

bool CheckersPlayer::Victory()
{
	if(this->board->Victory(this->cellType))
		return true;
	return false;
}