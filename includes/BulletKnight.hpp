#ifndef BULLET_KNIGHT_HPP
# define BULLET_KNIGHT_HPP

# include "Bullet.hpp"

class BulletKnight : public Bullet
{
public:

	BulletKnight(int const x, int const y, unsigned char const symbol, int const moveSpeed, Direction direction, Direction knightDirection);
	~BulletKnight(void);

	
	void				movePattern(Board *board);

private:

	Direction			_knightDirection;

	BulletKnight(BulletKnight const &src);
	BulletKnight &		operator=(BulletKnight const &src);

};

#endif
