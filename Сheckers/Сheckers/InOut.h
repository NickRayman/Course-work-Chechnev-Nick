#pragma once
#include <utility>
#include <iostream>
#include <map>
#include "Cell.h"
using namespace std;

class InOut
{
public:

	/*
	����������� � ����������
	*/
	InOut();
	~InOut();
	/*
	���������� ������� ������ ������
	*/
	static const pair<pair<size_t, size_t>, pair<size_t, size_t>>& GetMove();
	/*
	��������� ����� string ��������
	*/
	static void DrawBoard(const map<pair<size_t, size_t>, Cell>& board);
private:
	/*
	���������� ������� � string
	*/
	static const string& CastState(State state);

};

