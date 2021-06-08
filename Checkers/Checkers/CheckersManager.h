//����� CheckersManager.h ��� ���������� �����
#pragma once

#include "CheckersBoard.h"//��������� ����� CheckersBoard.h ��� ������������� ���� ��� ����/
#include "HumanPlayer.h"//��������� ����� HumanPlayer.h ��� ���������� ������-��������
class CheckersManager
{
private:
	CheckersBoard* board;//��������� ������ CheckersBoard
	HumanPlayer* player1;//��������� ������ HumanPlayer
	HumanPlayer* player2;//��������� ������ HumanPlayer
	HumanPlayer* currentPlayer;//��������� ������ HumanPlayer
	unsigned int moves = 0;//������� ���������� ��� ����������� ���������� �����
	bool bGameFinished = false;//������� ���������� ��� ����������� ����� ����
	CheckersBoard** equalBoards;//������� ��� �������� ������ ��������� ����

	void showRules();//������� ��� ������ ������ ����
public:
	CheckersManager();//�����������
	~CheckersManager();//���������� ��� ������� ������
	bool init();//������� ��� ��������� ����
	void showBoard();//������� ���������� �����
	void makeMove();//������� ��� ���������� ����
	bool isGameFinished();//������� ��� �������� ����� ����
};

