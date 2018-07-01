#include "EnemyTypeB.hpp"

EnemyTypeB::EnemyTypeB(int const x, int const y, unsigned char const symbol, int const moveSpeed) : AEnemy(x, y, symbol, moveSpeed)
{
	this->_attributes = A_BOLD;
	this->_foregroundColor = COLOR_CYAN;
	this->_backgroundColor = COLOR_BLACK;
	this->_symbol = 'H';
	this->_colorCode = SceneColorCode;
	this->_direction = DOWN;
}

EnemyTypeB::~EnemyTypeB(void) { }

void	EnemyTypeB::movePattern(Board *board)
{
	/*
	if (this->_memory == 3)
	{
		this->_direction == DOWN ? this->_direction = UP :
			this->_direction = DOWN;
		this->_memory = 0;
	}
	else
		this->_memory++;
	this->_posY++;
	this->move(this->_posX, this->_posY, board);
	*/
	this->_memory = 0;
	this->move(this->_posX, this->_posY + 1, board);
}

void	EnemyTypeB::update(Board *board)
{
	this->_moveInc++;
	if (this->_moveInc == this->_moveSpeed)
	{
		this->movePattern(board);
		this->_moveInc = 0;
	}
}
