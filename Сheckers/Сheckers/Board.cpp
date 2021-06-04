#include "Board.h"

Board::Board() : cBoardSize(8)
{
}

Board::~Board()
{
}

void Board::ResetMap()
{

	for (size_t i = 0; i < cBoardSize; i++) {
		for (size_t j = 0; j < cBoardSize; j++) {

			State state = State::BLANK;
			if (i == 0 && j % 2 != 0)
			    state = State::WHITE;
			else if (i == 1 && j % 2 == 0)
				state = State::WHITE;
			else if (i == 2 && j % 2 != 0)
				state = State::WHITE;
			else if (i == 5 && j % 2 == 0)
				state = State::BLACK;
			else if (i == 6 && j % 2 != 0)
				state = State::BLACK;
			else if (i == 7 && j % 2 == 0)
				state = State::BLACK;

			const pair <size_t, size_t> position = pair <size_t, size_t>(i, j);
			Cell cell = Cell(state);
			cCells.insert({ move(position), move(cell) });
		}
	}
}

MoveResult Board::MakeMove(const pair<size_t, size_t>& startPos, const pair<size_t, size_t>& endPos, bool direction, bool forceCombat)
{
	auto moveResult = CheckMove(startPos, endPos, direction);

	switch (moveResult) {
		
	case MoveResult::SUCCESSFUL_MOVE:
		
		cCells.at(endPos).SetState(cCells.at(startPos).GetState());
		cCells.at(startPos).SetState(State::BLANK);
		break;
	case MoveResult::SUCCESSFUL_COMBAT:

		cCells.at(endPos).SetState(cCells.at(startPos).GetState());
		cCells.at(startPos).SetState(State::BLANK);
		cCells.at(pair <size_t, size_t>((startPos.first) / 2, (startPos.second) / 2)).SetState(State::BLANK);
		break;
	}
	return moveResult;
}

const map<pair<size_t, size_t>, Cell>& Board::GetMap() const
{
	return cCells;
}

MoveResult Board::CheckMove(const pair<size_t, size_t>& startPos, const pair<size_t, size_t>& endPos, bool direction)
{
	MoveResult result = MoveResult::PRHOBITED;
	const int dX = endPos.first - startPos.first;
	const int dY = endPos.second - startPos.second;
	bool isCombat = false;
	
	if (endPos.first >= 0 && endPos.first < cBoardSize && endPos.second >= 0 && endPos.second < cBoardSize) {

		auto targetCellState = cCells.at(endPos).GetState();
		if (targetCellState == State::BLANK) {

			pair<size_t, size_t> victimPos((endPos.first - endPos.first) / 2, (startPos.second + endPos.second) / 2);
			auto vistimCellState = cCells.at(victimPos).GetState();
			auto startCellState = cCells.at(startPos).GetState();
				
			if (abs(dX) == 2 && abs(dY) == 2) {

				if (targetCellState != vistimCellState && startCellState != vistimCellState)
					result = MoveResult::SUCCESSFUL_COMBAT;
			}
			else if ((abs(dX) == 1 && dY == 1 && direction) || (abs(dX) == 1 && dY == -1 && !direction)) {

				result = MoveResult::SUCCESSFUL_MOVE;
			}
		}
		

	}
	return result;
}
