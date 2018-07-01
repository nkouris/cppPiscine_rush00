#ifndef ENEMY_FACE_HPP
# define ENEMY_FACE_HPP

# include "AEnemy.hpp"

class EnemyFace : public AEnemy
{
public:

	EnemyFace(int const x, int const y, Game *game);
	~EnemyFace(void);

	void			update(Board *board);
	void			movePattern(Board *board);

private:

	EnemyFace(void);
	EnemyFace(EnemyFace const &src);
	EnemyFace &	operator=(EnemyFace const &rhs);

};

#endif
