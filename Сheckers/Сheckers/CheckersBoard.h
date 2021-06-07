//����� CheckersBoard.h ��� ������������� ���� ��� ����
#pragma once

#include "CellTypes.h"//��������� ������������� ����� (enum-CellTypes.h)
#include "pch.h"//��������� ����� � ������ ������ ��� ���������

class CheckersBoard
{
private:
	CellTypes** cells;//������ �������������� ������ (enum-CellTypes.h)
	int boardSize = 8;//������ �������� ����
	int numberToRow(int num);//������� �������� ������
	int numberToCol(int num);//������� �������� �������
	bool checkBounds(int row, int col);//������� ��� �������� ������
	bool canBeFigth(int rowFrom, int colFrom, int rowWhat, int colWhat);//������� ��� ��������, ����� �� ����� ������ ����� ����������

public:
	CheckersBoard(int pattern);//����������� ��� �������� ���� ��� ����� � �� �����������
	CheckersBoard(CheckersBoard* board);//����������� ��������� �������� �����, � ����������� ����� ����������
	virtual ~CheckersBoard();//����������� ����������, ��� ������� ������
	void display();//������� ���������� �����
	bool moveDraught(int from, int to);//������� ������� �����
	bool checkRegulations(int from, CellTypes cell);//������� ��� �������� �� ��������� ������
	bool checkEndGame();//������� ��� �������� ��������� ����
	int* possible�Moves(int from, bool fight = false);//������� ��� ��������� ���������� ��������� ����� �����
	int* possibleDraughts(CellTypes cell);//������� ��� ��������� ���������� �����, �������� ����� �������
	CellTypes getCell(int row, int col);//������� ���������� ��� ������, �� ������ ����������
	int rowAndColToNum(int row, int col);//������� ��� �������� ������ � ������� � ����� ������

	/*
	��������������� ����������: == � !=
	*/
	
	friend bool operator==(const CheckersBoard& left, const CheckersBoard& right);
	friend bool operator!=(const CheckersBoard& left, const CheckersBoard& right);

};

