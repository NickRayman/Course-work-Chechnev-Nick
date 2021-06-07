//����� Calculation.h ��� �������� ������������ ��������, ����������� �������
#pragma once
#include "pch.h"//��������� ����� � ������ ������ ��� ���������
#include "CheckersBoard.h"//�������� ����� CheckersBoard.h ��� ������������� ���� ��� ����

class Calculation
{
private:
	int height = 3;
public:
	int* profitableMove = new int[2];

	Calculation(int height = 3);//����������� ��� �������� ������� ����
	~Calculation();//����������, ��� ������� ������
	int calculatet(CellTypes cell, CheckersBoard* board, int height);//������� ��� �������� ������ ���� ������
	int calculatetFight(CheckersBoard* board, CellTypes cell, int from);//������� ��� �������� �������� ���������� ����� ����������
	int minMax(CellTypes cell, CheckersBoard* board, int height);//������� ��� �������� ���� � ������� ��������� ������� �����
	int countValue(CheckersBoard* board, CellTypes cell);//������� ��� �������� ��������� �� ����
};

