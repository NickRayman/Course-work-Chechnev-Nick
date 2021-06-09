#include "HumanPlayer.h"

void HumanPlayer::contineToEat(int from)
{
	int* moves;
	int to, pl_from = from;
	while (true) {

		this->board->display();
		moves = this->board->possible�Moves(pl_from, true);
		if (moves[0] != 0) {

			cout << "����� " << name << ", ����� ������!" << endl;
			cout << "���� �������? ";
			cin >> to;

			for (int i = 0; i < 4; i++) {
				if (moves[i] == to) {
					this->board->moveDraught(pl_from, to);
					pl_from = to;
					continue;
				}
			}
			cout << "��������� ���� ��� ���� �����: ";
			for (int i = 0; i < 4; i++) {
				if (moves[i] != 0)
					cout << moves[i] << " ";
			}
			cout << endl;
		}
		else
			break;
	}
}

HumanPlayer::HumanPlayer()
{
}

HumanPlayer::~HumanPlayer()
{
}

void HumanPlayer::setupPlayer(string name, CellTypes cellType)
{
	this->name = name;
	this->cellType = cellType;
}

void HumanPlayer::setBoard(CheckersBoard* board)
{
	this->board = board;
}

bool HumanPlayer::makeMove()
{
	int from, to;
	cout << "����� " << name << ", ��� ���!" << endl;
	cout << "������ ������ �����? ";
	cin >> from;

	if (!this->board->checkRegulations(from, this->cellType))
		return false;

	int* moves = this->board->possible�Moves(from);
	if (moves[0] == 0) {
		cout << "- ��� ����� �� ����� ���������! -" << endl;
		return false;
	}

	cout << "���� �������? ";
	cin >> to;

	bool validMove = false;
	for (int i = 0; i < 4; i++) {
		if (moves[i] == to) {
			validMove = true;
			break;
		}
	}
	if (!validMove) {
		cout << "��������� ���� ��� ���� �����: ";
		for (int i = 0; i < 4; i++) {
			if (moves[i] != 0)
				cout << moves[i] << " ";
		}
		cout << endl;
		return validMove;
	}
	else {
		bool eaten = this->board->moveDraught(from, to);
		if (eaten)
			contineToEat(to);
	}

	return validMove;
}

string HumanPlayer::getName()
{
	return this->name;
}
