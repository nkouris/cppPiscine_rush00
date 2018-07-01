#include "Scene.hpp"
#include <ncurses.h>

Scene::Scene(int const x, int const y, char const symbol, int const moveSpeed) :
	AMoving(x, y, symbol, moveSpeed)
{
	/*
//	this->_attributes = A_NORMAL;
	this->_foregroundColor = COLOR_MAGENTA;
	this->_backgroundColor = COLOR_BLUE;
	this->_symbol = 'F';
	*/
}

Scene::~Scene(void)
{
}

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
}
