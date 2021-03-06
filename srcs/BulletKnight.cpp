#include "BulletKnight.hpp"


BulletKnight::BulletKnight(int const x, int const y, unsigned int const symbol, int const moveSpeed, Direction direction, Direction knightDirection) :
	Bullet(x, y, symbol, moveSpeed, direction), _knightDirection(knightDirection) { }

BulletKnight::~BulletKnight(void) { }

void			BulletKnight::movePattern(Board *board)
{
	if (this->_direction == UP)
	{
		if (this->_knightDirection == LEFT)
			this->move(this->_posX - 1, this->_posY - 1, board);
		else
			this->move(this->_posX + 1, this->_posY - 1, board);
	}
	else
	{
		if (this->_knightDirection == LEFT)
			this->move(this->_posX - 1, this->_posY + 1, board);
		else
			this->move(this->_posX + 1, this->_posY + 1, board);
	}
}
