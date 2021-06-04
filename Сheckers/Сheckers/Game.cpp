#include "Game.h"

Game::Game() : cWhiteScore(0), cBlackScore(0), cLastPlayer(Player::NONE), cIsSurrender(false)
{
}

Game::~Game()
{
}

void Game::Start() 
{
	cBoard.ResetMap();
	//проверка - конец игры
	while (GetWinner() == Player::NONE) {

		MoveResult moveResult(MoveResult::PRHOBITED);

		while (moveResult == MoveResult::PRHOBITED) {
			//Вызов метода IO
			auto newMove = makeIO();

			//Проверить, сдается ли
			bool direction = GetDirection();
			moveResult = cBoard.MakeMove(newMove.first, newMove.second, GetDirection(), direction);
		}
			
		//Разбор результата перемещения
		if (moveResult == MoveResult::SUCCESSFUL_COMBAT) {
			
			//Обновить счет 
			UpdateScore();
			
		}
		//Обновить последнего игрока
			SwitchPlayer();
			//Проверить ход результата
	}
	
	
	
}

Player Game::GetWinner() const
{
	Player winner = Player::NONE;

	if (cIsSurrender) {
		 
		if (cLastPlayer == Player::WHITE)
			winner = Player::BLACK;
		else if (cLastPlayer == Player::BLACK)
			winner = Player::WHITE;
	}
	else {
		if (cWhiteScore == 12)
			winner = Player::WHITE;
		else if (cBlackScore == 12)
			winner = Player::BLACK;
	}

	return winner;
}

void Game::UpdateScore()
{
	if (cLastPlayer == Player::WHITE)
		cBlackScore++;
	else cWhiteScore++;
}

void Game::SwitchPlayer()
{
	if (cLastPlayer == Player::WHITE)
		cLastPlayer = Player::BLACK;
	else cLastPlayer = Player::WHITE;
}

pair<pair<size_t, size_t>, pair<size_t, size_t>> Game::makeIO()
{
	//Напечатать доску
	system("cls");
	auto map = cBoard.GetMap();
	cIO.DrawBoard(map);

	//Попросите сделать ход
	auto newMove = cIO.GetMove();

	return move(newMove);
}

bool Game::GetDirection() const
{
	bool direction;

	switch (cLastPlayer) {
	case Player::WHITE:
		direction = false;
		break;
	default:
		direction = true;
		break;
	}
	return direction;
}
