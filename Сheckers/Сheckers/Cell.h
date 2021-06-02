#pragma once
#include "State.h"
#include <utility>

using namespace std;

/*
Класс клетка (Cell), для работы с шашками
*/
class Cell
{
public:
	
	/*
	Конструктор и деструктор
	*/
	Cell(/*const pair <size_t, size_t>& cPosition,*/ State cstate);
	~Cell();

	/*
	геттеры
	*/
	State GetState() const; 
	const pair <size_t, size_t>& GetPosition() const;

	/*
	сеттеры
	*/
	void SetState(State cState); 
	/*void SetPosition(const pair <size_t, size_t>& cPosition);*/


private:
	State cState;
	//pair <size_t, size_t> cPosition; //шаблон для координат шашек на поле
	
};

