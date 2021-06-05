#pragma once
#include <utility>
#include <iostream>
#include <map>
#include "Cell.h"
#include <algorithm>
#include <string>

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
	static pair<pair<size_t, size_t>, pair<size_t, size_t>> GetMove(string player);
	/*
	��������� ����� string ��������
	*/
	static void DrawBoard(const map<pair<size_t, size_t>, Cell>& board);

	void PrintScore(size_t whiteScore, size_t blackScore);

	void endGame(string player);
private:
	/*
	���������� ������� � string
	*/
	static string CastState(State state);

};

