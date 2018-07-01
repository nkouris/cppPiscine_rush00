#ifndef SCENE_H
# define SCENE_H

#include "AMoving.hpp"
#include "Game.hpp"

class		Scene : public AMoving {

	public:
		Scene(void);
		Scene(int const x, int const y, unsigned char const symbol, int const moveSpeed);
		Scene(Scene const & src);
		~Scene(void);
		Scene&	operator=(Scene const & rhs);

		void	movePattern(Board *board);
		void	update(Board *board);

};

#endif
