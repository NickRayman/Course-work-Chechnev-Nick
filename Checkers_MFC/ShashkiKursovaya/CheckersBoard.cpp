#include "CheckersBoard.h"

CheckersBoard::CheckersBoard()
{
	//this->boardsize = boardsize; //8x8 поле
	cells = new CellType * [boardsize];

	int z = 1; //флаг
	for (unsigned int i = 0; i < boardsize; i++)
		cells[i] = new CellType[boardsize];

	for (unsigned int i = 0; i < boardsize; i++) //заполняем поля
		for (unsigned int j = 0; j < boardsize; j++)
			cells[i][j] = CellType_Empty;


	for (unsigned int i = 0; i < boardsize; i++) //заполняем поля
	{
		for (unsigned int j = 0; j < boardsize; j++)
		{
			//здесь прописываем заполнение шашек черных, белых и пустых
			// 1 значение столбец, второе строка
			if (i < 3)
			{
				switch (z % 2)
				{
				case (1): //нечетные клетки
					cells[i][j] = CellType_Empty;
					z++;
					break;
				case (0): //четные клетки
					cells[i][j] = CellType_b;
					z++;
					break;

				}

			}
			
			if (i >= 3 && i <= 4)
				cells[i][j] = CellType_Empty;
			if (i > 4 && i < 8)
			{

				switch (z % 2)
				{
				case (1): //нечетные клетки
					cells[i][j] = CellType_Empty;
					z++;
					break;
				case (0): //четные клетки
					cells[i][j] = CellType_w;
					z++;
					break;
				}
			}
		}
		z++;
	}
}

CheckersBoard::~CheckersBoard()
{
	for (unsigned int i = 0; i < boardsize; i++)
		delete[]cells[i];
	delete[]cells;
}

void CheckersBoard::Show()
{
	cout << "  ";
	for (unsigned int j = 0; j < boardsize; j++)
		cout << j << " ";
	cout << endl;
	for (unsigned int i = 0; i < boardsize; i++)
	{
		cout << i << " ";
		for (unsigned int j = 0; j < boardsize; j++)
		{
			switch (cells[i][j])
			{
			case CellType_W: //белая дамка
				cout << "W";
				break;
			case CellType_w: //белая шашка
				cout << "w";
				break;
			case CellType_B: //черная дамка
				cout << "B";
				break;
			case CellType_b:  //черная шашка
				cout << "b";
				break;
			case CellType_Empty: //пустое поле игровое поле
				cout << "-";
				break;
			}
			cout << " ";
		}
		cout << endl;
	}
}

bool CheckersBoard::Victory(CellType cellType)
{
	int num = 0;
	if (cellType == CellType_w) {
		for (unsigned int i = 0; i < boardsize; i++)
			for (unsigned int j = 0; j < boardsize; j++)
			{
				if (cells[i][j] == CellType_b)
					num++;
			}
		if (num == 0)
			return true;
	}
	num = 0;
	if (cellType == CellType_b) {
		for (unsigned int i = 0; i < boardsize; i++)
			for (unsigned int j = 0; j < boardsize; j++)
			{
				if (cells[i][j] == CellType_w)
					num++;
			}
		if (num == 0)
			return true;
	}
	return false;
	//return win;
}

bool CheckersBoard::CheckPosMove(unsigned int xpos, unsigned int ypos, CellType ct) 
{
	if (xpos >= 0 && xpos <= 7 && ypos >= 0 && ypos <= 7) //проверка что координаты шашки находятся в пределах карты
	{
		if (ct == cells[ypos][xpos]) //проверка, что выбранная шашка является шашкой игрока //(X и Y передаются в обратном порядке)
		{
			if (ct == CellType_w) //если игрок управляет белыми шашками
			{
				//сначала проверить возможность хода
				if (ypos > 0) //проверяем не находится ли шашка на последней клетке
				{
					//проверка возможности пойти влево вверх
					if (xpos > 0) //проверка что шашка не находится у левой стенки
						if (cells[ypos - 1][xpos - 1] == CellType_Empty) //проверка, что клетка по диагонали влево пустая //(X и Y передаются в обратном порядке)
							return true; //ход возможен

					//проверка возможности пойти вправо вверх
					if (xpos < 7) //проверка, что шашка не находится у правой стенки
						if (cells[ypos - 1][xpos + 1] == CellType_Empty) //(X и Y передаются в обратном порядке)
							return true; //ход возможен
				}
				//теперь проверим возможность съесть шашку противника
				if (ypos > 1) //проверка что шашка при поедании не выйдет за пределы карты по Y
				{
					//проверка возможности есть влево вверх
					if (xpos > 1) //проверка, что шашка после поедания не выйдет за пределы карты по X слева
						if (cells[ypos - 1][xpos - 1] == CellType_b || cells[ypos - 1][xpos - 1] == CellType_B) //проверка, что слева по диагонали находится шашка противника //(X и Y передаются в обратном порядке)
							if (cells[ypos - 2][xpos - 2] == CellType_Empty) //(X и Y передаются в обратном порядке)
								return true; //ход съесть возможен

					if (xpos < 6) //проверка, что шашка после поедания не выйдет за пределы карты по X справа
						if (cells[ypos - 1][xpos + 1] == CellType_b || cells[ypos - 1][xpos + 1] == CellType_B) //проверка, что справа по диагонали находится шашка противника //(X и Y передаются в обратном порядке)
							if (cells[ypos - 2][xpos + 2] == CellType_Empty) //(X и Y передаются в обратном порядке)
								return true; //ход съесть возможен
				}
				return false; 
			}

			if (ct == CellType_b) //если игрок управляет черными шашками
			{
				//сначала проверить возможность хода
				if (ypos < 7) //проверяем не находится ли шашка на последней клетке
				{
					//проверка возможности пойти влево вниз
					if (xpos > 0) //проверка что шашка не находится у левой стенки
						if (cells[ypos + 1][xpos - 1] == CellType_Empty) //проверка, что клетка по диагонали влево пустая //(X и Y передаются в обратном порядке)
							return true; //ход возможен

					//проверка возможности пойти вправо вниз
					if (xpos < 7) //проверка, что шашка не находится у правой стенки
						if (cells[ypos + 1][xpos + 1] == CellType_Empty) //(X и Y передаются в обратном порядке)
							return true; //ход возможен
				}

				//теперь проверим возможность съесть шашку противника
				if (ypos < 6) //проверка, что после поедания шашка не покинет пределы доски
				{
					if (xpos > 1) //проверка, что шашка после поедания не выйдет за пределы карты по X слева
						if (cells[ypos + 1][xpos - 1] == CellType_w || cells[ypos + 1][xpos - 1] == CellType_W) //проверка, что слева по диагонали находится шашка противника //(X и Y передаются в обратном порядке)
							if (cells[ypos + 2][xpos - 2] == CellType_Empty) //(X и Y передаются в обратном порядке)
								return true; //ход съесть возможен

					if (xpos < 6) //проверка, что шашка после поедания не выйдет за пределы карты по X справа
						if (cells[ypos + 1][xpos + 1] == CellType_w || cells[ypos + 1][xpos + 1] == CellType_W) //проверка, что справа по диагонали находится шашка противника //(X и Y передаются в обратном порядке)
							if (cells[ypos + 2][xpos + 2] == CellType_Empty) 
								return true; //ход возможен
				}
				
			}			
		}
		return false; //выбрана шашка не принадлежащая игроку
	}
	return false; //координаты шашки за пределами карты
}

bool CheckersBoard::CheckLegalMove(unsigned int xpos, unsigned int ypos, unsigned int xpos1, unsigned int ypos1)
{
	if ((xpos1 >= 0) && (xpos1 < 8) && (ypos1 >= 0) && (ypos1 < 8)) //проверка что координаты указаны в пределах карты
	{
		if (cells[ypos][xpos] == CellType_w) //определяем для какой шашки смотрим ход (для белых)
			if (cells[ypos1][xpos1] == CellType_Empty) //проверка, что координата, куда хочет пойти пользователь пустая	
				if ((ypos - 1) == ypos1) //проверка диагонали перемещения, (проверка Y)				
					if (((xpos - 1) == xpos1) || ((xpos + 1) == xpos1)) //проверка диагонали перемещения, (проверка X)
						return true;

		if (cells[ypos][xpos] == CellType_b) //определяем для какой шашки смотрим ход (для черных)
			if (cells[ypos1][xpos1] == CellType_Empty) //проверка, что координата, куда хочет пойти пользователь пустая
				if ((ypos + 1) == ypos1) //проверка диагонали перемещения, (проверка Y)
					if (((xpos - 1) == xpos1) || ((xpos + 1) == xpos1)) //проверка диагонали перемещения, (проверка X)
						return true;
		return false;
	}
	return false;
}

bool CheckersBoard::CheckLegalEat(unsigned int xpos, unsigned int ypos, unsigned int xpos1, unsigned int ypos1)
{
	if ((xpos1 >= 0) && (xpos1 < 8) && (ypos1 >= 0) && (ypos1 < 8)) //проверка что координаты указаны в пределах карты
	{
		if (cells[ypos][xpos] == CellType_w) //определяем для какой шашки смотрим ход (для белых)
			if (cells[ypos1][xpos1] == CellType_Empty) //проверка, что координата, куда хочет пойти пользователь пустая
				if (ypos >= 2) //проверка, что после поедания шашка не вылетет за пределы карты
					if ((ypos - 2) == ypos1) //проверка диагонали перемещения, (проверка Y)
					{
						if (xpos <= 5) //определяем не выйдет ли шашка за пределы карты после поедания
							if (cells[ypos - 1][xpos + 1] == CellType_b) //вправо вверх едим (проверка наличия шашки противника на пути поедания)
								if ((xpos + 2) == xpos1) //проверка, что пользователь хочет есть именно в этом направлении
								{
									//вызываем отрисовку шашки на новой позиции
									PaintCell(xpos1, ypos1, CellType_w);
									//функция удаления шашки противника
									ClearCell((xpos + 1), (ypos - 1));
									//функция удаления шашки своей
									ClearCell(xpos, ypos);
									return true;
								}
						if (xpos >= 2) //определяем не выйдет ли шашка за пределы карты после поедания
							if (cells[ypos - 1][xpos - 1] == CellType_b) //влево вверх едим
								if ((xpos - 2) == xpos1)
								{
									//вызываем отрисовку шашки на новой позиции
									PaintCell(xpos1, ypos1, CellType_w);
									//функция удаления шашки противника
									ClearCell((xpos - 1), (ypos - 1));
									//функция удаления шашки своей
									ClearCell(xpos, ypos);
									return true;
								}
					}

		if (cells[ypos][xpos] == CellType_b) //определяем для какой шашки смотрим ход (для черных)
			if (cells[ypos1][xpos1] == CellType_Empty) //проверка, что координата, куда хочет пойти пользователь пустая
				if (ypos <= 5) //определяем не выйдет ли шашка за пределы карты после поедания
					if ((ypos + 2) == ypos1) //проверка диагонали перемещения, (проверка Y)
					{
						if (xpos <= 5) //определяем не выйдет ли шашка за пределы карты после поедания
							if (cells[ypos + 1][xpos + 1] == CellType_w) //поедание вниз вправо
								if ((xpos + 2) == xpos1) //проверка диагонали перемещения, (проверка X)
								{
									//вызываем отрисовку шашки на новой позиции
									PaintCell(xpos1, ypos1, CellType_b);
									//функция удаления шашки противника
									ClearCell((xpos + 1), (ypos + 1));
									//функция удаления шашки своей
									ClearCell(xpos, ypos);
									return true;
								}
						if (xpos >= 2) //определяем не выйдет ли шашка за пределы карты после поедания
							if (cells[ypos + 1][xpos - 1] == CellType_w) // поедание шашки вниз влево
								if ((xpos - 2) == xpos1)
								{
									//вызываем отрисовку шашки на новой позиции
									PaintCell(xpos1, ypos1, CellType_b);
									//функция удаления шашки противника
									ClearCell((xpos - 1), (ypos + 1));
									//функция удаления шашки своей
									ClearCell(xpos, ypos);
									return true;
								}
					}
		return false;
	}
	return false; //координаты хода неверны для поедания
}

void CheckersBoard::PaintCell(unsigned int xpos1, unsigned int ypos1, CellType ct)
{
	cells[ypos1][xpos1] = ct;
}

void CheckersBoard::ClearCell(unsigned int xpos, unsigned int ypos)
{
	cells[ypos][xpos] = CellType_Empty;
}

bool CheckersBoard::GetQuantityBot()
{
	for (unsigned int i = 0; i < boardsize; i++)
		for (unsigned int j = 0; j < boardsize; j++)
		{
			if (cells[i][j] == CellType_b) //находим шашки принадлежащие боту шашки
			{
				if (CheckPosMove(j, i, CellType_b))
				{
					int x1 = i + 2;//вниз влево
					int y1 = j - 2;

					if ((x1 >= 0) || (y1 >= 0)) //в пределах карты ход
						if ((x1 < 8) || (y1 < 8)) 
							if (!CheckLegalEat(j, i, y1, x1))
							{
								int x1 = i + 2;//вниз вправо
								int y1 = j + 2;
								if ((x1 >= 0) || (y1 >= 0)) //в пределах карты ход
									if ((x1 < 8) || (y1 < 8))
										if (CheckLegalEat(j, i, y1, x1))
											return true;
							}
							else
								return true;

					if (MotionBot(j, i, CellType_b))
						return true;
				}
			}	
					
				
		}
	return false; //бот не нашел шашек для хода
}

bool CheckersBoard::MotionBot(unsigned int xpos, unsigned int ypos, CellType ct)
{
	if (ypos < 7) //что шашка не находится на последней клетке
	{
		ypos++;
		if (xpos < 7) //проверка, что бот не выйдет за пределы карты
		if (cells[ypos][xpos + 1] == CellType_Empty) //вниз вправо вход
		{
			//прописать перемещение шашки на пустую клетку и удалить старую позицию
			PaintCell(xpos + 1, ypos, CellType_b);
			ClearCell(xpos, ypos - 1);
			return true;
		}
		if (xpos > 0) //проверка, что бот не выйдет за пределы карты
		if (cells[ypos][xpos - 1] == CellType_Empty) //вниз влево ход
		{
			//прописать перемещение шашки на пустую клетку и удалить старую позицию
			PaintCell((xpos - 1), ypos, CellType_b);
			ClearCell(xpos, ypos - 1);
			return true;
		}
	}
	return false;
}

CellType CheckersBoard::CheckCellType(int x, int y)
{
	return cells[y][x];
}
