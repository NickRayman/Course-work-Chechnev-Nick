#pragma once
#include "CheckersBoard.h"
class CheckersPlayer
{
private:
	CheckersBoard* board; //������� �����
	CellType cellType; //��� �����, �������� ���������� �����
	string name; // ��� ������
	unsigned int row, col; //������ � �������
public:
	CheckersPlayer();
	virtual ~CheckersPlayer();
	void SetupPlayer(string name, CellType cellType); //����� ���������� ����� � ���� ������������ ����� �������
	void SetBoard(CheckersBoard* board);  //��������� ������� �����
	string GetName(); //���������� ��� ������
	bool MakeMove(int Fx, int Fy, int Sx, int Sy); //��� ������
	bool TakeChecker(int Fx, int Fy); //�������� ��������� �����		
	bool Victory();
};

