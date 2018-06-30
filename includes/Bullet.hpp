#ifndef BULLET_HPP
# define BULLET_HPP

# include "AEntity.hpp"

class Bullet : public AEntity
{
public:

	Bullet(int const x, int const y, char const symbol);
	~Bullet(void);

	void			update(Board *board);
	

private:

	int				_moveSpeed;

	Bullet(Bullet const &src);
	Bullet &		operator=(Bullet const &src);

};

#endif
