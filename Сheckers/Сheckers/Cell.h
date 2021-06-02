#pragma once
#include "State.h"
#include <utility>

using namespace std;

/*
����� ������ (Cell), ��� ������ � �������
*/
class Cell
{
public:
	
	/*
	����������� � ����������
	*/
	Cell(/*const pair <size_t, size_t>& cPosition,*/ State cstate);
	~Cell();

	/*
	�������
	*/
	State GetState() const; 
	const pair <size_t, size_t>& GetPosition() const;

	/*
	�������
	*/
	void SetState(State cState); 
	/*void SetPosition(const pair <size_t, size_t>& cPosition);*/


private:
	State cState;
	//pair <size_t, size_t> cPosition; //������ ��� ��������� ����� �� ����
	
};

