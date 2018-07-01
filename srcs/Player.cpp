#include <ncurses.h>
#include "Player.hpp"
#include "Game.hpp"
#include "Bullet.hpp"
#include "Poop.hpp"

Player::Player(int const x, int const y, Game *game) : AEntity(x, y, L'🍔'), _game(game)
{
	this->_shotCooldown = 20;
	this->_cooldown = 0;
	this->_lives = 3;
	this->_bombs = 5;
}

Player::~Player(void)
{
	Game::playSound("sounds/wilheim_scream.wav");
	this->_game->setGameOver();
}

void			Player::killMe(void)
{
	if (this->_lives > 0)
		this->_lives--;
	else
		delete this;
}
/*
void			Player::operator delete(void *ptr)
{
	Player *p = (Player *)ptr;
	if (p->_lives > 0)
		p->_lives--;
	else
		::operator delete(ptr);
}
*/
void			Player::update(Board *board)
{
	(void)board;

	if (this->_cooldown > 0)
		this->_cooldown--;
}

void			Player::setPosX(int x)
{
	AEntity::setPosX(CLAMP(x, 0, Game::GAME_WINDOW_WIDTH - 1));
}

void			Player::setPosY(int y)
{
	AEntity::setPosY(CLAMP(y, 0, Game::GAME_WINDOW_HEIGHT - 1));
}

int				Player::getLives(void) const { return (this->_lives); }
int				Player::getBombs(void) const { return (this->_bombs); }

void			Player::shoot()
{
	if (this->_cooldown == 0)
	{
		Game::playSound("sounds/laser_1b.wav");
		
		Bullet *b;
		switch (std::rand() % 3)
		{
			case (0):
				b = new Bullet(this->getPosX(), this->getPosY() - 1, L'🍟', 5, UP);
				break;
			case (1):
				b = new BulletKnight(this->getPosX(), this->getPosY() - 1, L'🍟', 5, UP, LEFT);
				break;
			case (2):
			default:
				b = new BulletKnight(this->getPosX(), this->getPosY() - 1, L'🍟', 5, UP, RIGHT);
				break;
		}

		this->_game->getBoard()->setCell(b->getPosX(), b->getPosY(), b);
	
		this->_cooldown = this->_shotCooldown;
	}
}

void			Player::bomb()
{
	if (this->_bombs == 0) return;

	// destroy everything in 13 x 7 area around Player
	this->_bombs--;
	Game::playSound("sounds/singleShot4.wav");
	
	for (int x = this->_posX - 6; x <= this->_posX + 6; x++)
	{
		for (int y = this->_posY - 3; y <= this->_posY + 3; y++)
		{
			if (0 <= x && x < Game::GAME_WINDOW_WIDTH && 0 <= y && y < Game::GAME_WINDOW_HEIGHT)
			{
				if (!(x == this->_posX && y == this->_posY))
				{
					delete this->_game->getBoard()->getCell(x, y);
					this->_game->getBoard()->clearCell(x, y);
				}
				delete this->_game->getSceneBoard()->getCell(x, y);
				this->_game->getSceneBoard()->clearCell(x, y);
				this->_game->getSceneBoard()->setCell(x, y, new Poop(x, y));
			}
		}
	}
}
