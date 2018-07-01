#ifndef ENEMYTYPEB_HPP
# define ENEMYTYPEB_HPP

# include "AEnemy.hpp"

class	EnemyTypeB : public AEnemy
{
	public:
		EnemyTypeB(int const x, int const y, unsigned int const symbol, int const moveSpeed);
		~EnemyTypeB(void);

		void	movePattern(Board *board);
		void	update(Board *board);
	
	private:
		int			_memory;
		Direction	_direction;

};

#endif
