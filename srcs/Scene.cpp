#include "Scene.hpp"

Scene::Scene(int x, int y, char const symbol, int const moveSpeed) : AMoving(x, y, symbol, moveSpeed)
{
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
