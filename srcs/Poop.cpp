#include "Poop.hpp"

Poop::Poop(int const x, int const y) : AEntity(x, y, L'💩') { }

Poop::~Poop(void) { }

void			Poop::update(Board *board)
{
	(void)board;
}
