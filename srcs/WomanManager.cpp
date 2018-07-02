#include "WomanManager.hpp"
#include "WomanPart.hpp"
#include "Game.hpp"

// 		this =	👒
// _parts[0] =	🙅
// _parts[1] =	👖
// _parts[2] =	👠

WomanManager::WomanManager(int const x, int const y, Game *game) : AEnemy(x, y, L'👒', 30, game)
{
	this->_isKillingSelf = false;
	for (int i = 0; i < 3; i++)
		this->_isPartDead[i] = false;

	this->_parts[0] = new WomanPart(this->_posX, this->_posY + 1, L'🙅', game, this, 0);
	this->_parts[1] = new WomanPart(this->_posX, this->_posY + 2, L'👖', game, this, 1);
	this->_parts[2] = new WomanPart(this->_posX, this->_posY + 3, L'👠', game, this, 2);

	this->_game->getBoard()->setCell(this->_posX, this->_posY + 1, this->_parts[0]);
	this->_game->getBoard()->setCell(this->_posX, this->_posY + 2, this->_parts[1]);
	this->_game->getBoard()->setCell(this->_posX, this->_posY + 3, this->_parts[2]);
}

WomanManager::~WomanManager(void)
{
	this->_isKillingSelf = true;
	Game::playSound("sounds/wilheim_scream.wav");

	this->_game->getBoard()->clearCell(this->_posX, this->_posY);

	for (int i = 0; i < 3; i++)
	{
		if (this->_isPartDead[i] == false)
		{
			WomanPart *p = this->_parts[i];
			p->setManagerDead();
			this->_game->getBoard()->clearCell(p->getPosX(), p->getPosY());
			delete p;
		}
	}
}

void			WomanManager::partDied(int id)
{
	this->_isPartDead[id] = true;

	if (this->_isKillingSelf == false)
	{
		this->_isKillingSelf = true;
		delete this;
	}
}

void			WomanManager::update(Board *board)
{
	if (std::rand() % 100 < 5)
	{
		this->movePattern(board);
	}
}

void			WomanManager::movePattern(Board *board)
{
	// always move right 1 unit
	this->move(this->_posX + 1, this->_posY, board);

	for (int i = 0; i < 3; i++)
	{
		if (this->_isKillingSelf) return;
		WomanPart *p = this->_parts[i];
		p->move(p->getPosX() + 1, p->getPosY(), board);
	}
}
