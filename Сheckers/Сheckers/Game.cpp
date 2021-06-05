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
	//�������� - ����� ����
	while (GetWinner() == Player::NONE) {

		MoveResult moveResult(MoveResult::PRHOBITED);

		while (moveResult == MoveResult::PRHOBITED) {
			//����� ������ IO
			auto newMove = makeIO();

			//���������, ������� ��
			bool direction = GetDirection();
			moveResult = cBoard.MakeMove(newMove.first, newMove.second, GetDirection(), direction);
		}
			
		//��������� ff
		if (moveResult == MoveResult::FF) {
			cIsSurrender = true;
			break;
		}
			

		//������ ���������� �����������
		if (moveResult == MoveResult::SUCCESSFUL_COMBAT) {
			
			//�������� ���� 
			UpdateScore();
			
		}
		//�������� ���������� ������
			SwitchPlayer();
			//��������� ��� ����������
	}
	cIO.endGame(CastPlayer(GetWinner()));
	
	
	
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

string Game::CastPlayer(Player player) const
{
	string playerStr;

	switch (player) {

	case Player::WHITE:
			playerStr = "White player";
			break;
	default:
		playerStr = "Black player";
		break;
	}
	return playerStr;
}

string Game::GetCurrentPlayer() const
{
	string player;
	if (cLastPlayer == Player::WHITE)
		player = "Black";
	else
		player = "White";
	return move(player);

}

void Game::UpdateScore()
{
	if (cLastPlayer == Player::WHITE)
		cBlackScore++;
	else 
		cWhiteScore++;
}

void Game::SwitchPlayer()
{
	if (cLastPlayer == Player::WHITE)
		cLastPlayer = Player::BLACK;
	else 
		cLastPlayer = Player::WHITE;
}

pair<pair<size_t, size_t>, pair<size_t, size_t>> Game::makeIO()
{
	//���������� �����
	system("cls");
	cIO.PrintScore(cWhiteScore, cBlackScore);
	auto map = cBoard.GetMap();
	cIO.DrawBoard(map);

	//��������� ������� ���
	auto newMove = cIO.GetMove(GetCurrentPlayer());

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
