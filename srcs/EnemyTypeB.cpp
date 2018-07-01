#include "EnemyTypeB.hpp"

EnemyTypeB::EnemyTypeB(int const x, int const y, unsigned int const symbol, int const moveSpeed) : AEnemy(x, y, symbol, moveSpeed)
{
	this->_attributes = A_BOLD;
	this->_foregroundColor = COLOR_CYAN;
	this->_backgroundColor = COLOR_BLACK;
	this->_symbol = 'H';
	this->_colorCode = 0;
	this->_direction = DOWN;
}

EnemyTypeB::~EnemyTypeB(void) { }

void	EnemyTypeB::update(Board *board)
{
	this->_moveInc++;
	if (this->_moveInc == this->_moveSpeed)
	{
		this->movePattern(board);
		this->_moveInc = 0;
	}
}

void	EnemyTypeB::movePattern(Board *board)
{
	this->_memory = 0;
	this->move(this->_posX, this->_posY - 1, board);
}
