#include "Bullet.hpp"
#include "Board.hpp"

Bullet::Bullet(int const x, int const y, char const symbol) :
	AEntity(x, y, symbol) { }

Bullet::~Bullet(void) { }

void			Bullet::update(Board *board)
{
	board->setCell(this->_posX, this->_posY, NULL);
	this->_posY--;
	board->setCell(this->_posX, this->_posY, this);
}
