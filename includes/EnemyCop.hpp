#ifndef ENEMY_COP_HPP
# define ENEMY_COP_HPP

# include "AEnemy.hpp"
# include "IShoot.hpp"

class EnemyCop : public AEnemy, public IShoot
{
public:

	EnemyCop(int const x, int const y, Game *game);
	~EnemyCop(void);

	void			update(Board *board);
	void			movePattern(Board *board);
	void			shoot(void);

private:

	EnemyCop(void);
	EnemyCop(EnemyCop const &src);
	EnemyCop &	operator=(EnemyCop const &rhs);

};

#endif
