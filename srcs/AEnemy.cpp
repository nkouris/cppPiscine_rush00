#include "AEnemy.hpp"

AEnemy::AEnemy(int const x, int const y, unsigned char const symbol, int const moveSpeed)
	: AMoving(x, y, symbol, moveSpeed) { }

AEnemy::~AEnemy(void) { }
