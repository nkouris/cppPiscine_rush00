#include "AMoving.hpp"

AMoving::AMoving(int const x, int const y, unsigned int const symbol, int const moveSpeed)
	: AEntity(x, y, symbol), _moveSpeed(moveSpeed), _moveInc(0) { }

AMoving::~AMoving(void) { }
