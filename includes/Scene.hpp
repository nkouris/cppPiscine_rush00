#ifndef SCENE_H
# define SCENE_H

#include "AMoving.hpp"
#include "Game.hpp"

class		Scene : public AMoving
{
public:
	Scene(void);
	Scene(int const x, int const y);
	~Scene(void);

	void	movePattern(Board *board);
	void	update(Board *board);

private:

	int		_blinkRate;
	int		_blinkInc;
	
	Scene&	operator=(Scene const & rhs);
	Scene(Scene const & src);

};

#endif
