#ifndef BULLET_HPP
# define BULLET_HPP

# include "AMoving.hpp"

class Bullet : public AMoving
{
public:

	Bullet(int const x, int const y, unsigned int const symbol, int const moveSpeed, Direction direction);
	~Bullet(void);

	void			update(Board *board);
	virtual void	movePattern(Board *board);

protected:

	Direction		_direction;

private:

	Bullet(Bullet const &src);
	Bullet &		operator=(Bullet const &src);

};

#endif
