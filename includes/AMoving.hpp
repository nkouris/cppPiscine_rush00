#ifndef AMOVING_HPP
# define AMOVING_HPP

# include "AEntity.hpp"

enum Direction { UP, DOWN, LEFT, RIGHT };

class Board;

class AMoving : public AEntity
{
public:

	AMoving(int const x, int const y, unsigned int const symbol, int const moveSpeed);
	virtual ~AMoving(void);

	virtual void	update(Board *board) = 0;
	virtual void	movePattern(Board *board) = 0;

protected:

	int				_moveSpeed;
	int				_moveInc;

private:
	
	AMoving(AMoving const &src);
	AMoving &		operator=(AMoving const &rhs);

};

#endif
