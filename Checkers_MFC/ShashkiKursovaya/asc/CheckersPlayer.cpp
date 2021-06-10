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

bool CheckersPlayer::MakeMove()
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

		if (TakeChecker()) //����� ������ �������� �������� ��������� �����
		{
			unsigned int row1, col1;
			unsigned int flagMove = 0;
			unsigned int flagEnd = 0;

			do
			{
				if (flagEnd > 0) //���� �� �������� ������ ��� ������
				{
					row = row1; //���������� ����� ���������� �����
					col = col1; //���������� ����� ���������� �����
					board->Show();
					cout << endl;
				}
				if (!this->board->CheckPosMove(col, row, cellType))
					return true; //���� ��� ��������� ����� ���������� ����� ������� (����������� ��� ���������� ��������)
				cout << "����� " << name << ", �������� ���� �����..." << endl;
				cout << "������� ������: ";
				cin >> row1;
				cout << "������� �������: ";
				cin >> col1;
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
			} while (this->board->CheckLegalEat(col, row, col1, row1)); //���� �� ����� ����� ���������� ����� ������ �� ����� ���
			if (flagEnd >= 2)
				return true;

		}
		return false; //���� ��������� ���������� ����� �������� (����� �������� ������)
	}
}

bool CheckersPlayer::TakeChecker()
{
	//unsigned int row, col; //row - Y, col - X
	cout << "����� " << name << ", �������� �����..." << endl;
	cout << "������� ������ ��������� �����: ";
	cin >> row;
	cout << "������� ������� ��������� �����: ";
	cin >> col;
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



