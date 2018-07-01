#include "EnemyCop.hpp"
#include "Game.hpp"

EnemyCop::EnemyCop(int const x, int const y, Game *game) : AEnemy(x, y, L'🚓', 80, game) { }

EnemyCop::~EnemyCop(void)
{
	static std::string deathSound[4] =
	{
		"sounds/death1.wav",
		"sounds/death2.wav",
		"sounds/death3.wav",
		"sounds/death4.wav"
	};
	
	if (this->_posX >= 0)
	{
		Game::playSound(deathSound[std::rand() % 4]);
		this->_game->addScore(20);
	}
}

void			EnemyCop::update(Board *board)
{
	this->_moveInc++;
	if (this->_moveInc == this->_moveSpeed)
	{
		this->movePattern(board);
		this->_moveInc = 0;
		this->_moveSpeed = 10 + std::rand() % 10 - 5;
	}
	if (std::rand() % 1000 < 10)
		this->shoot();
}

void			EnemyCop::movePattern(Board *board)
{
	// always move left 1 unit
	this->move(this->_posX - 1, this->_posY, board);
}

void			EnemyCop::shoot(void)
{
	// shoot a donut diagonally 🍩
	int donutSpeed = 5 + std::rand() % 5;
	Bullet *b;
	switch(std::rand() % 4)
	{
		case (0):
			b = new BulletKnight(this->getPosX() - 1, this->getPosY() - 1, L'🍩', donutSpeed, UP, LEFT);
			break;
		case (1):
			b = new BulletKnight(this->getPosX() + 1, this->getPosY() - 1, L'🍩', donutSpeed, UP, RIGHT);
			break;
		case (2):
			b = new BulletKnight(this->getPosX() - 1, this->getPosY() + 1, L'🍩', donutSpeed, DOWN, LEFT);
			break;
		default:
			b = new BulletKnight(this->getPosX() + 1, this->getPosY() + 1, L'🍩', donutSpeed, DOWN, RIGHT);
			break;
	}
	this->_game->getBoard()->setCell(b->getPosX(), b->getPosY(), b);
	Game::playSound("sounds/whoosh.wav");
}


