#include "EnemyFace.hpp"
#include "Game.hpp"

EnemyFace::EnemyFace(int const x, int const y, Game *game)
	: AEnemy(x, y, 0, 50, game)
{
	static unsigned int face[16] =
	{
		L'😃', L'😂', L'😆', L'😉',
		L'😗', L'😆', L'😐', L'😏',
		L'😯', L'😪', L'😫', L'😛',
		L'😆', L'😒', L'😟', L'😦'
	};

	this->_symbol = face[std::rand() % 16];
}

EnemyFace::~EnemyFace(void)
{
	Game::playSound("sounds/minecraft_ugh.wav");
	this->_game->addScore(10);
}

void			EnemyFace::update(Board *board)
{
	this->_moveInc++;
	if (this->_moveInc == this->_moveSpeed)
	{
		this->movePattern(board);
		this->_moveInc = 0;
		this->_moveSpeed = 10 + std::rand() % 10 - 5;
	}
}

void			EnemyFace::movePattern(Board *board)
{
	if (this->_game->getPlayer() == NULL) return;

	if (std::rand() % 2)
	{
		int vDiff = this->_game->getPlayer()->getPosY() - this->_posY;
		if (vDiff > 0)
			this->move(this->_posX, this->_posY + 1, board);
		else if (vDiff < 0)
			this->move(this->_posX, this->_posY - 1, board);
		else
		{
			int hDiff = this->_game->getPlayer()->getPosX() - this->_posX;
			if (hDiff > 0)
				this->move(this->_posX + 1, this->_posY, board);
			else
				this->move(this->_posX - 1, this->_posY, board);
		}
	}
	else
	{
		int hDiff = this->_game->getPlayer()->getPosX() - this->_posX;
		if (hDiff > 0)
			this->move(this->_posX + 1, this->_posY, board);
		else if (hDiff < 0)
			this->move(this->_posX - 1, this->_posY, board);
		else
		{
			int vDiff = this->_game->getPlayer()->getPosY() - this->_posY;
			if (vDiff > 0)
				this->move(this->_posX, this->_posY + 1, board);
			else
				this->move(this->_posX, this->_posY - 1, board);
		}
	}
}
