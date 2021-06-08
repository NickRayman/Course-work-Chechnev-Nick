#include "CheckersManager.h"

void CheckersManager::showRules()
{
	cout << "_________________________________________________________________________" << endl;
	cout << "| Правила Checkers:                                                     |" << endl;
	cout << "| 1. Первые ходят чёрные.                                               |" << endl;
	cout << "| 2. Шашки ходят на одну клетку вперёд, а дамки могут и на одну назад.  |" << endl;
	cout << "| 3. Бои обязательны.                                                   |" << endl;
	cout << "| 4. При достижении последнего ряда шашка становится дамкой.            |" << endl;
	cout << "|    При этом прерывается серия боев.                                   |" << endl;
    cout << "| 5. Игра кончается, если съедены или заперты все вражеские шашки.      |" << endl;
	cout << "| 6. Чтобы не затягивать игру, она ограничена 100 ходами. После этого   |" << endl;
	cout << "|    идёт расчёт доски и побеждает игрок с лучшем положением.           |" << endl;
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

	cout << "Выберите необходимый режим игры (Обычная партия - 1, Своя игровая ситуация - 2): ";
	cin >> type;
	this->board = new CheckersBoard(type);

	int pType = 0;
	while (pType != 1) {

		cout << "Выберите тип игрока, играющего чёрными шашками (Человек - 1, ИИ пока разработке - 2): ";
		cin >> pType;
		if (pType == 1) {
			cin.ignore();
			cout << "Введите имя игрока, играющего чёрными: ";
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

		cout << "Выберите тип игрока, играющего белыми шашками (Человек - 1, ИИ пока разработке - 2): ";
		cin >> pType;
		if (pType == 1) {
			while (true) {
				cin.ignore();
				cout << "Введите имя игрока, играющего чёрными: ";
				getline(cin, playerName);
				if (player1->getName() != playerName)
					break;
				cout << "Имя уже занято. Введите другое" << endl;
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
		cout << "Неверный ход. Попробуйте ещё раз." << endl;
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

				cout << "Три повторяющихся хода! Ничья! Ходов совершено: " << moves << endl;
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
		
		cout << "Более сотни ходов!" << endl;
		int value = Calculation().countValue(board, BlACK_DRAUGHT);
		if (value < 0)
			cout << "Белые в лучшем положении. Они победили!" << endl;
		else
			cout << "Чёрные в лчушем положении. Они победили!" << endl;
		this->bGameFinished = true;
		return;
	}

	if (this->board->checkEndGame()) {

		cout << "Ходов совершено: " << moves << endl;
		cout << "************************************************" << endl;
		cout << "*-*-*-*-*-*-* Игрок " << currentPlayer->getName() << " победил! *-*-*-*-*-*-*" << endl;
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
