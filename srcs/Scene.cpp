#include "Scene.hpp"
#include <ncurses.h>

Scene::Scene(int const x, int const y) :
	AMoving(x, y, '.', std::rand() % 20)
{
	this->_attributes = A_NORMAL;
	this->_foregroundColor = std::rand() % 7 + 1;
	this->_backgroundColor = COLOR_BLACK;
	this->_colorCode = this->_foregroundColor + 2;

	this->_blinkRate = std::rand() % 5 + 5;
	this->_blinkInc = 0;
}

Scene::~Scene(void) { }

void		Scene::movePattern(Board *board)
{
	this->move(this->_posX, this->_posY + 1, board);
}

void		Scene::update(Board *board)
{
	this->_moveInc++;
	if (this->_moveInc == this->_moveSpeed)
	{
		this->movePattern(board);
		this->_moveInc = 0;
	}

	this->_blinkInc++;
	if (this->_blinkInc == this->_blinkRate)
	{
		this->_foregroundColor = std::rand() % 7 + 1;
		this->_colorCode = this->_foregroundColor + 2;

		this->_blinkRate = std::rand() % 5 + 5;
		this->_blinkInc = 0;
	}
}
