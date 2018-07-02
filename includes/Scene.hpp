#ifndef SCENE_H
# define SCENE_H

#include "AMoving.hpp"
#include "Game.hpp"

class		Scene : public AMoving
{
public:
	
	Scene(int const x, int const y);
	~Scene(void);

	void	update(Board *board);
	void	movePattern(Board *board);

private:

	int		_blinkRate;
	int		_blinkInc;
	
	Scene(void);
	Scene(Scene const & src);
	Scene&	operator=(Scene const & rhs);

};

#endif
