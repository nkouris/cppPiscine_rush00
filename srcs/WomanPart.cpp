#include "WomanPart.hpp"
#include "WomanManager.hpp"

WomanPart::WomanPart(int const x, int const y, unsigned int const symbol, Game *game, WomanManager *manager, int id) :
	AEnemy(x, y, symbol, 0, game)
{
	this->_manager = manager;
	this->_partID = id;
	this->_isManagerDead = false;
}

WomanPart::~WomanPart(void)
{
	if (this->_isManagerDead == false)
		this->_manager->partDied(this->_partID);
}

void		WomanPart::update(Board *board)
{
	(void)board;
}

void		WomanPart::movePattern(Board *board)
{
	(void)board;
}

void		WomanPart::setManagerDead(void) { this->_isManagerDead = true; }
