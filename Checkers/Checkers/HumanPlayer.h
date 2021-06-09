//����� HumanPlayer.h ��� ���������� ������-��������
#pragma once

#include "pch.h"//��������� ����� � ������ ������ ��� ���������
#include "CheckersBoard.h"//�������� ����� CheckersBoard.h ��� ������������� ���� ��� ����
#include "Calculation.h"//��������� ����� Calculation.h ��� �������� ������������ ��������, ����������� �������

class HumanPlayer
{
protected:
	CheckersBoard* board;//��������� ������ CheckersBoard
	string name;//���������� ������
	void contineToEat(int from);//������� ��� ����������� �������� ���������� �����
public:
	CellTypes cellType;//������ ������ CellType
	HumanPlayer();//�����������
	virtual ~HumanPlayer();//����������� ����������
	void setupPlayer(string name, CellTypes cellType);//������� ��� ��������� ��������� ������
	void setBoard(CheckersBoard* board);//������� ��� ��������� ����������� ����� ������ � �������
	virtual bool makeMove();//������� ��� ���������� ���� ������� ���������
	string getName();//������ ��� �������� ����� ������
};

