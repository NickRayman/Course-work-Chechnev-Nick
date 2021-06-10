#include "CheckersBoard.h"

CheckersBoard::CheckersBoard()
{
	//this->boardsize = boardsize; //8x8 ����
	cells = new CellType * [boardsize];

	int z = 1; //����
	for (unsigned int i = 0; i < boardsize; i++)
		cells[i] = new CellType[boardsize];

	for (unsigned int i = 0; i < boardsize; i++) //��������� ����
		for (unsigned int j = 0; j < boardsize; j++)
			cells[i][j] = CellType_Empty;


	for (unsigned int i = 0; i < boardsize; i++) //��������� ����
	{
		for (unsigned int j = 0; j < boardsize; j++)
		{
			//����� ����������� ���������� ����� ������, ����� � ������
			// 1 �������� �������, ������ ������
			if (i < 3)
			{
				switch (z % 2)
				{
				case (1): //�������� ������
					cells[i][j] = CellType_Empty;
					z++;
					break;
				case (0): //������ ������
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
				case (1): //�������� ������
					cells[i][j] = CellType_Empty;
					z++;
					break;
				case (0): //������ ������
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
			case CellType_W: //����� �����
				cout << "W";
				break;
			case CellType_w: //����� �����
				cout << "w";
				break;
			case CellType_B: //������ �����
				cout << "B";
				break;
			case CellType_b:  //������ �����
				cout << "b";
				break;
			case CellType_Empty: //������ ���� ������� ����
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
	if (xpos >= 0 && xpos <= 7 && ypos >= 0 && ypos <= 7) //�������� ��� ���������� ����� ��������� � �������� �����
	{
		if (ct == cells[ypos][xpos]) //��������, ��� ��������� ����� �������� ������ ������ //(X � Y ���������� � �������� �������)
		{
			if (ct == CellType_w) //���� ����� ��������� ������ �������
			{
				//������� ��������� ����������� ����
				if (ypos > 0) //��������� �� ��������� �� ����� �� ��������� ������
				{
					//�������� ����������� ����� ����� �����
					if (xpos > 0) //�������� ��� ����� �� ��������� � ����� ������
						if (cells[ypos - 1][xpos - 1] == CellType_Empty) //��������, ��� ������ �� ��������� ����� ������ //(X � Y ���������� � �������� �������)
							return true; //��� ��������

					//�������� ����������� ����� ������ �����
					if (xpos < 7) //��������, ��� ����� �� ��������� � ������ ������
						if (cells[ypos - 1][xpos + 1] == CellType_Empty) //(X � Y ���������� � �������� �������)
							return true; //��� ��������
				}
				//������ �������� ����������� ������ ����� ����������
				if (ypos > 1) //�������� ��� ����� ��� �������� �� ������ �� ������� ����� �� Y
				{
					//�������� ����������� ���� ����� �����
					if (xpos > 1) //��������, ��� ����� ����� �������� �� ������ �� ������� ����� �� X �����
						if (cells[ypos - 1][xpos - 1] == CellType_b || cells[ypos - 1][xpos - 1] == CellType_B) //��������, ��� ����� �� ��������� ��������� ����� ���������� //(X � Y ���������� � �������� �������)
							if (cells[ypos - 2][xpos - 2] == CellType_Empty) //(X � Y ���������� � �������� �������)
								return true; //��� ������ ��������

					if (xpos < 6) //��������, ��� ����� ����� �������� �� ������ �� ������� ����� �� X ������
						if (cells[ypos - 1][xpos + 1] == CellType_b || cells[ypos - 1][xpos + 1] == CellType_B) //��������, ��� ������ �� ��������� ��������� ����� ���������� //(X � Y ���������� � �������� �������)
							if (cells[ypos - 2][xpos + 2] == CellType_Empty) //(X � Y ���������� � �������� �������)
								return true; //��� ������ ��������
				}
				return false; 
			}

			if (ct == CellType_b) //���� ����� ��������� ������� �������
			{
				//������� ��������� ����������� ����
				if (ypos < 7) //��������� �� ��������� �� ����� �� ��������� ������
				{
					//�������� ����������� ����� ����� ����
					if (xpos > 0) //�������� ��� ����� �� ��������� � ����� ������
						if (cells[ypos + 1][xpos - 1] == CellType_Empty) //��������, ��� ������ �� ��������� ����� ������ //(X � Y ���������� � �������� �������)
							return true; //��� ��������

					//�������� ����������� ����� ������ ����
					if (xpos < 7) //��������, ��� ����� �� ��������� � ������ ������
						if (cells[ypos + 1][xpos + 1] == CellType_Empty) //(X � Y ���������� � �������� �������)
							return true; //��� ��������
				}

				//������ �������� ����������� ������ ����� ����������
				if (ypos < 6) //��������, ��� ����� �������� ����� �� ������� ������� �����
				{
					if (xpos > 1) //��������, ��� ����� ����� �������� �� ������ �� ������� ����� �� X �����
						if (cells[ypos + 1][xpos - 1] == CellType_w || cells[ypos + 1][xpos - 1] == CellType_W) //��������, ��� ����� �� ��������� ��������� ����� ���������� //(X � Y ���������� � �������� �������)
							if (cells[ypos + 2][xpos - 2] == CellType_Empty) //(X � Y ���������� � �������� �������)
								return true; //��� ������ ��������

					if (xpos < 6) //��������, ��� ����� ����� �������� �� ������ �� ������� ����� �� X ������
						if (cells[ypos + 1][xpos + 1] == CellType_w || cells[ypos + 1][xpos + 1] == CellType_W) //��������, ��� ������ �� ��������� ��������� ����� ���������� //(X � Y ���������� � �������� �������)
							if (cells[ypos + 2][xpos + 2] == CellType_Empty) 
								return true; //��� ��������
				}
				
			}			
		}
		return false; //������� ����� �� ������������� ������
	}
	return false; //���������� ����� �� ��������� �����
}

bool CheckersBoard::CheckLegalMove(unsigned int xpos, unsigned int ypos, unsigned int xpos1, unsigned int ypos1)
{
	if ((xpos1 >= 0) && (xpos1 < 8) && (ypos1 >= 0) && (ypos1 < 8)) //�������� ��� ���������� ������� � �������� �����
	{
		if (cells[ypos][xpos] == CellType_w) //���������� ��� ����� ����� ������� ��� (��� �����)
			if (cells[ypos1][xpos1] == CellType_Empty) //��������, ��� ����������, ���� ����� ����� ������������ ������	
				if ((ypos - 1) == ypos1) //�������� ��������� �����������, (�������� Y)				
					if (((xpos - 1) == xpos1) || ((xpos + 1) == xpos1)) //�������� ��������� �����������, (�������� X)
						return true;

		if (cells[ypos][xpos] == CellType_b) //���������� ��� ����� ����� ������� ��� (��� ������)
			if (cells[ypos1][xpos1] == CellType_Empty) //��������, ��� ����������, ���� ����� ����� ������������ ������
				if ((ypos + 1) == ypos1) //�������� ��������� �����������, (�������� Y)
					if (((xpos - 1) == xpos1) || ((xpos + 1) == xpos1)) //�������� ��������� �����������, (�������� X)
						return true;
		return false;
	}
	return false;
}

bool CheckersBoard::CheckLegalEat(unsigned int xpos, unsigned int ypos, unsigned int xpos1, unsigned int ypos1)
{
	if ((xpos1 >= 0) && (xpos1 < 8) && (ypos1 >= 0) && (ypos1 < 8)) //�������� ��� ���������� ������� � �������� �����
	{
		if (cells[ypos][xpos] == CellType_w) //���������� ��� ����� ����� ������� ��� (��� �����)
			if (cells[ypos1][xpos1] == CellType_Empty) //��������, ��� ����������, ���� ����� ����� ������������ ������
				if (ypos >= 2) //��������, ��� ����� �������� ����� �� ������� �� ������� �����
					if ((ypos - 2) == ypos1) //�������� ��������� �����������, (�������� Y)
					{
						if (xpos <= 5) //���������� �� ������ �� ����� �� ������� ����� ����� ��������
							if (cells[ypos - 1][xpos + 1] == CellType_b) //������ ����� ���� (�������� ������� ����� ���������� �� ���� ��������)
								if ((xpos + 2) == xpos1) //��������, ��� ������������ ����� ���� ������ � ���� �����������
								{
									//�������� ��������� ����� �� ����� �������
									PaintCell(xpos1, ypos1, CellType_w);
									//������� �������� ����� ����������
									ClearCell((xpos + 1), (ypos - 1));
									//������� �������� ����� �����
									ClearCell(xpos, ypos);
									return true;
								}
						if (xpos >= 2) //���������� �� ������ �� ����� �� ������� ����� ����� ��������
							if (cells[ypos - 1][xpos - 1] == CellType_b) //����� ����� ����
								if ((xpos - 2) == xpos1)
								{
									//�������� ��������� ����� �� ����� �������
									PaintCell(xpos1, ypos1, CellType_w);
									//������� �������� ����� ����������
									ClearCell((xpos - 1), (ypos - 1));
									//������� �������� ����� �����
									ClearCell(xpos, ypos);
									return true;
								}
					}

		if (cells[ypos][xpos] == CellType_b) //���������� ��� ����� ����� ������� ��� (��� ������)
			if (cells[ypos1][xpos1] == CellType_Empty) //��������, ��� ����������, ���� ����� ����� ������������ ������
				if (ypos <= 5) //���������� �� ������ �� ����� �� ������� ����� ����� ��������
					if ((ypos + 2) == ypos1) //�������� ��������� �����������, (�������� Y)
					{
						if (xpos <= 5) //���������� �� ������ �� ����� �� ������� ����� ����� ��������
							if (cells[ypos + 1][xpos + 1] == CellType_w) //�������� ���� ������
								if ((xpos + 2) == xpos1) //�������� ��������� �����������, (�������� X)
								{
									//�������� ��������� ����� �� ����� �������
									PaintCell(xpos1, ypos1, CellType_b);
									//������� �������� ����� ����������
									ClearCell((xpos + 1), (ypos + 1));
									//������� �������� ����� �����
									ClearCell(xpos, ypos);
									return true;
								}
						if (xpos >= 2) //���������� �� ������ �� ����� �� ������� ����� ����� ��������
							if (cells[ypos + 1][xpos - 1] == CellType_w) // �������� ����� ���� �����
								if ((xpos - 2) == xpos1)
								{
									//�������� ��������� ����� �� ����� �������
									PaintCell(xpos1, ypos1, CellType_b);
									//������� �������� ����� ����������
									ClearCell((xpos - 1), (ypos + 1));
									//������� �������� ����� �����
									ClearCell(xpos, ypos);
									return true;
								}
					}
		return false;
	}
	return false; //���������� ���� ������� ��� ��������
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
			if (cells[i][j] == CellType_b) //������� ����� ������������� ���� �����
			{
				if (CheckPosMove(j, i, CellType_b))
				{
					int x1 = i + 2;//���� �����
					int y1 = j - 2;

					if ((x1 >= 0) || (y1 >= 0)) //� �������� ����� ���
						if ((x1 < 8) || (y1 < 8)) 
							if (!CheckLegalEat(j, i, y1, x1))
							{
								int x1 = i + 2;//���� ������
								int y1 = j + 2;
								if ((x1 >= 0) || (y1 >= 0)) //� �������� ����� ���
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
	return false; //��� �� ����� ����� ��� ����
}

bool CheckersBoard::MotionBot(unsigned int xpos, unsigned int ypos, CellType ct)
{
	if (ypos < 7) //��� ����� �� ��������� �� ��������� ������
	{
		ypos++;
		if (xpos < 7) //��������, ��� ��� �� ������ �� ������� �����
		if (cells[ypos][xpos + 1] == CellType_Empty) //���� ������ ����
		{
			//��������� ����������� ����� �� ������ ������ � ������� ������ �������
			PaintCell(xpos + 1, ypos, CellType_b);
			ClearCell(xpos, ypos - 1);
			return true;
		}
		if (xpos > 0) //��������, ��� ��� �� ������ �� ������� �����
		if (cells[ypos][xpos - 1] == CellType_Empty) //���� ����� ���
		{
			//��������� ����������� ����� �� ������ ������ � ������� ������ �������
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
