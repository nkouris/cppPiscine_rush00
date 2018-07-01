#include "Player.hpp"
#include "Game.hpp"
# include <ncurses.h>

Player::Player(int const x, int const y, char const symbol) :
	AEntity(x, y, symbol)
{
	this->_attributes = A_BOLD;
	this->_foregroundColor = COLOR_RED;
	this->_backgroundColor = COLOR_GREEN;
	this->_colorCode = PlayerColorCode;
}

Player::~Player(void) { }

void			Player::update(Board *board)
{
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
