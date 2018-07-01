#ifndef AENEMY_HPP
# define AENEMY_HPP

# include "AMoving.hpp"

class Game;

class AEnemy : public AMoving
{
public:

	AEnemy(int const x, int const y, unsigned int const symbol, int const moveSpeed, Game *game);
	virtual ~AEnemy(void);

	virtual void		update(Board *board) = 0;
	virtual void		movePattern(Board *board) = 0;
	virtual void		shoot(void) = 0;

protected:

	Game *				_game;

private:

	AEnemy(AEnemy const &src);
	AEnemy &			operator=(AEnemy const &rhs);


};

#endif
