#ifndef SCENE_H
# define SCENE_H

#include "AMoving.hpp"
#include "Game.hpp"

class		Scene : AMoving {

	protected:

	public:
		Scene(void);
		Scene(int const x, int const y, char const symbol, int const moveSpeed);
		Scene(Scene const & src);
		~Scene(void);
		Scene&	operator=(Scene const & rhs);
		void	movePattern(Board *board);	
};

std::ostream& operator<<(std::ostream &, Scene const &);

#endif
