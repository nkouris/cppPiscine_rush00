#ifndef AENEMY_HPP
# define AENEMY_HPP

# include "AMoving.hpp"

class	AEnemy : public AMoving
{
	public:
		AEnemy(int const x, int const y, unsigned int const symbol, int const moveSpeed);
		virtual ~AEnemy(void);

		virtual void		update(Board *board) = 0;
		virtual void		movePattern(Board *board) = 0;

};

#endif
