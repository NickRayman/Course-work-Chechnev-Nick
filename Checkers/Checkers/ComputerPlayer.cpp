#include "ComputerPlayer.h"

void ComputerPlayer::contineToEat(int from)
{
	int* moves;
	int to, pl_from = from;
	int k = 0;
	while (true) {
		moves = board->possible‹Moves(pl_from, true);
		if (moves[0] == 0)
			break;

		for (int i = 0; i < 4; i++) {
			if (moves[i] == 0)
				break;
			else
				k++;
		}

		to = moves[rand() % k];
		cout << name << ": " << pl_from << " --> " << to << endl;
		board->moveDraught(pl_from, to);
		pl_from = to;
		delete[] moves;
	}
}

ComputerPlayer::ComputerPlayer()
{
}

ComputerPlayer::~ComputerPlayer()
{
}

bool ComputerPlayer::makeMove()
{
	e = new Calculation(3);
	e->minMax(cellType, board, 3);

	cout << ": " << e->profitableMove[0] << " --> " << e->profitableMove[1] << endl;

	bool eaten = board->moveDraught(e->profitableMove[0], e->profitableMove[1]);
	if (eaten)
		contineToEat(e->profitableMove[1]);

	delete e;
	return true;
}
