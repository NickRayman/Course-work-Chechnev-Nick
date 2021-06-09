//����� CoumputerPlayer.h ��� ���������� ������-����������
#pragma once

#include "HumanPlayer.h"//��������� ����� HumanPlayer.h ��� ������������ �� ���� ������ ComputerPlayer
#include "Calculation.h"//��������� ����� Calculation.h ��� �������� ������������ ��������, ����������� �������

class ComputerPlayer : public HumanPlayer
{
private:
	Calculation* e;//��������� ������ Calculation ��� �������� ������������ ��������, ����������� ������������ �������
	void contineToEat(int from);//������� ��� ����������� �������� ���������� �����
public:

	ComputerPlayer();//�����������
	virtual ~ComputerPlayer();//����������� ����������
	virtual bool makeMove();//������� ��� ���������� ���� ������������ �������
};

