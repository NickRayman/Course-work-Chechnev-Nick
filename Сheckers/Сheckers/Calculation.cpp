#include "Calculation.h"

Calculation::Calculation(int height)
{
	this->height = height;
}

Calculation::~Calculation()
{
	delete[] profitableMove;
}

int Calculation::calculatet(CellTypes cell, CheckersBoard* board, int height)
{
	if (height == 0) {
		return countValue(board, cell);
	}
	CheckersBoard* bd = new CheckersBoard(board);
	int startValue = countValue(bd, cell);
	int* draughts = bd->possibleDraughts(cell);

	int* moves = new int[4];
	int** equalMoves = new int* [16];
	for (int i = 0; i < 16; i++) {
		equalMoves[i] = new int[2];
		equalMoves[i][0] = 0;
		equalMoves[i][1] = 0;
	}

	int v, k = 0;
	int valDif = 0;
	bool eaten;
	for (int i = 0; draughts[i] != 0; i++) {
		moves = bd->possible‹Moves(draughts[i]);
		for (int j = 0; j < 4; j++) {
			if (moves[j] == 0)
				break;

			eaten = bd->moveDraught(draughts[i], moves[j]);
			if (eaten)
				v = calculatetFight(bd, cell, draughts[i]) - startValue;
			else
				v = countValue(bd, cell) - startValue;
			if (v == valDif) {
				equalMoves[k][0] = draughts[i];
				equalMoves[k][1] = moves[j];
				k++;
			}
			else if (v > valDif) {
				for (int i = 0; i < 16; i++) {
					equalMoves[i] = new int[2];
					equalMoves[i][0] = 0;
					equalMoves[i][1] = 0;
				}
				k = 1;

				valDif = v;
				equalMoves[0][0] = draughts[i];
				equalMoves[0][1] = moves[j];
			}
			bd = new CheckersBoard(board);
		}

	}
	return countValue(board, cell) - calculatet((cell == WHITE_DRAUGHT) ? BlACK_DRAUGHT : WHITE_DRAUGHT, bd, height - 1);

	profitableMove = equalMoves[rand() % k];
	return 0;
}

int Calculation::calculatetFight(CheckersBoard* board, CellTypes cell, int from)
{
	int* moves;
	int to, pl_from = from;
	int k = 0;
	CheckersBoard* bd = new CheckersBoard(board);
	int startValue = countValue(board, cell);
	while (true) {
		moves = bd->possible‹Moves(pl_from, true);
		if (moves[0] == 0)
			break;

		for (int i = 0; i < 4; i++) {
			if (moves[i] == 0)
				break;
			else
				k++;
		}
		to = moves[rand() % k];
		bd->moveDraught(pl_from, to);
		pl_from = to;
		k = 0;
	}
	delete[] moves, bd;
	return countValue(bd, cell) - startValue;
}

int Calculation::minMax(CellTypes cell, CheckersBoard* board, int height)
{
	if (height == 0) {
		return countValue(board, cell);
	}
	CheckersBoard* bd = new CheckersBoard(board);
	int startValue = countValue(bd, cell);
	int* draughts = bd->possibleDraughts(cell);

	int* moves = new int[4];
	int** equalMoves = new int* [16];
	for (int i = 0; i < 16; i++) {
		equalMoves[i] = new int[2];
		equalMoves[i][0] = 0;
		equalMoves[i][1] = 0;
	}

	int v, k = 0;
	int valDif = INT_MIN;
	bool eaten;
	for (int i = 0; draughts[i] != 0; i++) {
		moves = bd->possible‹Moves(draughts[i]);
		for (int j = 0; j < 4; j++) {
			if (moves[j] == 0)
				break;

			eaten = bd->moveDraught(draughts[i], moves[j]);
			if (eaten)
				v = calculatetFight(bd, cell, moves[j]);
			else
				v = minMax((cell == WHITE_DRAUGHT) ? BlACK_DRAUGHT : WHITE_DRAUGHT, bd, height - 1) - startValue;

			if (height == this->height) {
				if (v == valDif) {
					equalMoves[k][0] = draughts[i];
					equalMoves[k][1] = moves[j];
					k++;
				}
				else if (v > valDif) {
					for (int i = 0; i < 16; i++) {
						equalMoves[i] = new int[2];
						equalMoves[i][0] = 0;
						equalMoves[i][1] = 0;
					}
					k = 1;

					valDif = v;
					equalMoves[0][0] = draughts[i];
					equalMoves[0][1] = moves[j];
				}
			}
			else {
				if (v == valDif)
					k++;
				else if (v > valDif) {
					k = 1;
					valDif = v;
				}
			}
			delete bd;
			bd = new CheckersBoard(board);
		}
	}

	if (k == 0) {
		delete bd;
		delete[] draughts, moves;
		for (int i = 0; i < 16; i++)
			delete[] equalMoves[i];
		delete[] equalMoves;

		return startValue;
	}

	if (height == this->height) {
		profitableMove = equalMoves[rand() % k];
		return 1;
	}

	delete bd;
	delete[] draughts, moves;
	for (int i = 0; i < 16; i++)
		delete[] equalMoves[i];
	delete[] equalMoves;
	return startValue - valDif;
}

int Calculation::countValue(CheckersBoard* board, CellTypes cell)
{
	int boardSize = 8;
	int value = 0;
	int* moves = { 0 };
	int k = 0;
	int mine = 0, his = 0;
	CellTypes cell1;
	for (int row = 0; row < boardSize; row++) {
		for (int col = 0; col < boardSize; col++) {
			k = 0;
			moves = board->possible‹Moves(board->rowAndColToNum(row, col));
			for (int i = 0; moves[i] != 0; i++)
				k++;

			cell1 = board->getCell(row, col);
			if (cell == WHITE_DRAUGHT) {
				if (cell1 == WHITE_DRAUGHT || cell1 == WHITE_KING) {
					value += k;
					mine++;
				}
				else if (cell == BlACK_DRAUGHT || cell == BLACK_KING) {
					value -= k;
					his++;
				}
			}
			else if (cell == BlACK_DRAUGHT) {
				if (cell1 == WHITE_DRAUGHT || cell1 == WHITE_KING) {
					value -= k;
					his++;
				}
				else if (cell1 == BlACK_DRAUGHT || cell == BLACK_KING) {
					value += k;
					mine++;
				}
			}
		}
			
	}
	if (mine == 0)
		value -= 1000;
	if (his == 0)
		value += 1000;

	delete moves;
	return value;
}
