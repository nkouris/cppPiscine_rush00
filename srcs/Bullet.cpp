#include "Bullet.hpp"
#include "Board.hpp"

Bullet::Bullet(int const x, int const y, unsigned char const symbol, int const moveSpeed, Direction direction) :
	AMoving(x, y, symbol, moveSpeed), _direction(direction) { }


Bullet::~Bullet(void) { }

void			Bullet::update(Board *board)
{
	this->_moveInc++;
	if (this->_moveInc == this->_moveSpeed)
	{
		this->movePattern(board);
		this->_moveInc = 0;
	}
}

void			Bullet::movePattern(Board *board)
{
	if (this->_direction == UP)
		this->move(this->_posX, this->_posY - 1, board);
	else
		this->move(this->_posX, this->_posY + 1, board);
}
