#include "AEnemy.hpp"

AEnemy::AEnemy(int const x, int const y, unsigned int const symbol, int const moveSpeed, Game *game)
	: AMoving(x, y, symbol, moveSpeed), _game(game) { }

AEnemy::~AEnemy(void) { }
