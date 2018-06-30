#include "Player.hpp"
#include "Game.hpp"

Player::Player(int const x, int const y, char const symbol) :
	AEntity(x, y, symbol) { }

Player::~Player(void) { }

void			Player::update(Board *board)
{
	board->setCell(this->getPosX(), this->getPosY(), this);
	(void)board;
}

void			Player::setPosX(int x)
{
	AEntity::setPosX(CLAMP(x, 0, Game::GAME_WINDOW_WIDTH - 1));
}
void			Player::setPosY(int y)
{
	AEntity::setPosY(CLAMP(y, 0, Game::GAME_WINDOW_HEIGHT - 1));
}
