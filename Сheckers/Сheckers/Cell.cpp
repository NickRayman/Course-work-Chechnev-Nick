#include "Cell.h"

Cell::Cell(/*const pair<size_t, size_t>& cPosition, */State cState) : /*cPosition(cPosition), */cState(cState)
{
}

Cell::~Cell()
{
}

State Cell::GetState() const
{
	return cState;
}

//const pair<size_t, size_t>& Cell::GetPosition() const
//{
//	return cPosition;
//}

void Cell::SetState(State cState)
{
	this->cState = cState;
}

//void Cell::SetPosition(const pair<size_t, size_t>& cPosition)
//{
//	this->cPosition = cPosition;
//}


