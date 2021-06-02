#pragma once
#include "Cell.h"
#include "MoveResult.h"
#include <unordered_map> //�������� ���� (���������, ���������� ������ � �������) ��� �������� � ������

using namespace std;

/*
����� ������ (Board), ��� ������������ �����
*/
class Board
{
public:

	/*
	����������� � ����������
	*/
	Board();
	~Board();
	
	/*
	������� ��� ���������� ������� ������� cCells
	*/
	void ResetMap();

	/*
	������� ��������� ������� �����
	*/
	MoveResult MakeMove(const pair <size_t, size_t>& startPos, const pair <size_t, size_t>& endPos, bool direction, bool forceCombat);

private:
	unordered_map<pair <size_t, size_t>, Cell> cCells;
	const size_t cBoardSize;
	/*
	������� ��������� ������� �����
	*/
	MoveResult CheckMove(const pair <size_t, size_t>& startPos, const pair <size_t, size_t>& endPos, bool direction);
};

