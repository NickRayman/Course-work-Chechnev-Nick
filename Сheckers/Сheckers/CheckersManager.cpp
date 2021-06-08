#include "CheckersManager.h"

void CheckersManager::showRules()
{
	cout << "_________________________________________________________________________" << endl;
	cout << "| ������� Checkers:                                                     |" << endl;
	cout << "| 1. ������ ����� ������.                                               |" << endl;
	cout << "| 2. ����� ����� �� ���� ������ �����, � ����� ����� � �� ���� �����.  |" << endl;
	cout << "| 3. ��� �����������.                                                   |" << endl;
	cout << "| 4. ��� ���������� ���������� ���� ����� ���������� ������.            |" << endl;
	cout << "|    ��� ���� ����������� ����� ����.                                   |" << endl;
    cout << "| 5. ���� ���������, ���� ������� ��� ������� ��� ��������� �����.      |" << endl;
	cout << "| 6. ����� �� ���������� ����, ��� ���������� 100 ������. ����� �����   |" << endl;
	cout << "|    ��� ������ ����� � ��������� ����� � ������ ����������.           |" << endl;
	cout << "_________________________________________________________________________" << endl;
	cout << endl;
}

CheckersManager::CheckersManager()
{
}

CheckersManager::~CheckersManager()
{
	delete this->player1;
	delete this->player2;
	delete this->board;
}

bool CheckersManager::init()
{
	string playerName;
	int type;

	showRules();

	cout << "�������� ����������� ����� ���� (������� ������ - 1, ���� ������� �������� - 2): ";
	cin >> type;
	this->board = new CheckersBoard(type);

	int pType = 0;
	while (pType != 1) {

		cout << "�������� ��� ������, ��������� ������� ������� (������� - 1, �� ���� ���������� - 2): ";
		cin >> pType;
		if (pType == 1) {
			cin.ignore();
			cout << "������� ��� ������, ��������� �������: ";
			getline(cin, playerName);
			player1 = new HumanPlayer();
			player1->setupPlayer(playerName, BlACK_DRAUGHT);
		 }
		else if (pType == 2) {
			//nothing
		}
		player1->setBoard(this->board);
	}

	pType = 0;
	while (pType != 1) {

		cout << "�������� ��� ������, ��������� ������ ������� (������� - 1, �� ���� ���������� - 2): ";
		cin >> pType;
		if (pType == 1) {
			while (true) {
				cin.ignore();
				cout << "������� ��� ������, ��������� �������: ";
				getline(cin, playerName);
				if (player1->getName() != playerName)
					break;
				cout << "��� ��� ������. ������� ������" << endl;
			}
			
			player2 = new HumanPlayer();
			player2->setupPlayer(playerName, WHITE_DRAUGHT);
		}
		else if (pType == 2) {
			//nothing
		}
		player2->setBoard(this->board);
	}
	currentPlayer = player1;
	equalBoards = new CheckersBoard * [2];

	return true;

}

void CheckersManager::showBoard()
{
	this->board->display();
}

void CheckersManager::makeMove()
{
	showBoard();

	while (!currentPlayer->makeMove()) {
		cout << "�������� ���. ���������� ��� ���." << endl;
		showBoard();
	}

	showBoard();

	moves++;
	if (moves == 1 || moves == 2) {
		equalBoards[moves - 1] = new CheckersBoard(board);
	}

	if (moves % 4 == 0) {

		if (*equalBoards[0] == *board) {

			if (*equalBoards[1] == *board) {

				cout << "��� ������������� ����! �����! ����� ���������: " << moves << endl;
				this->bGameFinished = true;
				return;
			}
			else {
				equalBoards[1] = new CheckersBoard(board);
			}
		}
		else
			equalBoards[0] = new CheckersBoard(board);
	}

	if (moves > 100) {
		
		cout << "����� ����� �����!" << endl;
		int value = Calculation().countValue(board, BlACK_DRAUGHT);
		if (value < 0)
			cout << "����� � ������ ���������. ��� ��������!" << endl;
		else
			cout << "׸���� � ������ ���������. ��� ��������!" << endl;
		this->bGameFinished = true;
		return;
	}

	if (this->board->checkEndGame()) {

		cout << "����� ���������: " << moves << endl;
		cout << "************************************************" << endl;
		cout << "*-*-*-*-*-*-* ����� " << currentPlayer->getName() << " �������! *-*-*-*-*-*-*" << endl;
	    cout << "************************************************" << endl;

		this->bGameFinished = true;
		return;
	}

	currentPlayer = (currentPlayer == player1) ? player2 : player1;

}

bool CheckersManager::isGameFinished()
{
	return bGameFinished;
}
