#pragma once
#include "CellType.h"
#include "pch.h"
class CheckersBoard
{
private:
	unsigned int boardsize = 8;
	CellType** cells;
	bool win = false;
public:
	CheckersBoard();
	virtual ~CheckersBoard();
	void Show();
	bool Victory(CellType cellType);
	bool CheckPosMove(unsigned int xpos, unsigned int ypos, CellType ct);
	bool CheckLegalMove(unsigned int xpos, unsigned int ypos, unsigned int xpos1, unsigned int ypos1); //�������� �������� ���������� �� ����������� ����
	bool CheckLegalEat(unsigned int xpos, unsigned int ypos, unsigned int xpos1, unsigned int ypos1); //�������� ��������� ��������� �� ����������� ������ ����� ����������
	void PaintCell(unsigned int xpos1, unsigned int ypos1, CellType ct);
	void ClearCell(unsigned int xpos, unsigned int ypos);
	//������ ��� AIBot
	bool GetQuantityBot();
	bool MotionBot(unsigned int xpos, unsigned int ypos, CellType ct);
	CellType CheckCellType(int x, int y);
};

