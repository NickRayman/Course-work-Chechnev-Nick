#include "CheckersPlayer.h"

CheckersPlayer::CheckersPlayer()
{
}

CheckersPlayer::~CheckersPlayer()
{
}

void CheckersPlayer::SetupPlayer(string name, CellType cellType)
{
	this->name = name; //���������� ��� ������
	this->cellType = cellType; //���������� ��� ����� ������
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
	//����� ��������� ����� � ����
	if (GetName() == "AIBot")
	{
		if (board->GetQuantityBot()) //���� ��� ������ ���
		{
			return true;
		}
		return false;
	}
	else
	{

		if (TakeChecker(Fx, Fy)) //����� ������ �������� �������� ��������� �����
		{
			unsigned int row1, col1;
			unsigned int flagMove = 0;
			unsigned int flagEnd = 0;
			unsigned int TriedEatNext = 0;
			do
			{
				row1 = Sx;
				col1 = Sy;
				if (flagEnd > 0) //���� �� �������� ������ ��� ������
				{
					row = row1; //���������� ����� ���������� �����
					col = col1; //���������� ����� ���������� �����
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
					return true; //���� ��� ��������� ����� ���������� ����� ������� (����������� ��� ���������� ��������)
				/*cout << "����� " << name << ", �������� ���� �����..." << endl;
				cout << "������� ������: ";*/
				
				if (flagEnd == flagMove) //�������� �� ������ ��������
					if (this->board->CheckLegalMove(col, row, col1, row1))
					{
						//�������� ����� ��������� ����� ������� �����
						board->PaintCell(col1, row1, cellType);
						//�������� ����� ��� �������� ������ ������� �����
						board->ClearCell(col, row);
						flagMove++; //���� ��� �������� ����
						return true;
					}
				flagEnd++; //���� ��� ����� ������� �����
			} while ((this->board->CheckLegalEat(col, row, col1, row1)) || TriedEatNext == 1); //���� �� ����� ����� ���������� ����� ������ �� ����� ���
			if (flagEnd >= 2)
				return true;

		}
		return false; //���� ��������� ���������� ����� �������� (����� �������� ������)
	}
}

bool CheckersPlayer::TakeChecker(int Fx, int Fy)
{
	//unsigned int row, col; //row - Y, col - X
	/*cout << "����� " << name << ", �������� �����..." << endl;
	cout << "������� ������ ��������� �����: ";*/
	row = Fx;
	/*cout << "������� ������� ��������� �����: ";*/
	col = Fy;
	if (this->board->CheckPosMove(col, row, cellType)) //����� ������ ����������� ����� ��������� �����
	{
		return true; //����� ������ �����
	}

	return false; //����� �������� �����
}

bool CheckersPlayer::Victory()
{
	if(this->board->Victory(this->cellType))
		return true;
	return false;
}