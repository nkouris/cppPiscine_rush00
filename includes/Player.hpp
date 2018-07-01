#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "AEntity.hpp"

class Player : public AEntity
{
public:

	Player(int const x, int const y, Game *game);
	~Player(void);

	void				setPosX(int x);
	void				setPosY(int y);

	int					getLives(void) const;
	int					getBombs(void) const;

	void				update(Board *board);

	void				shoot(void);
	void				bomb(void);

	void				killMe(void);

//	static void				operator delete(void *ptr);

private:

	Game *				_game;
	
	int					_shotCooldown;
	int					_cooldown;

	int					_lives;
	int					_bombs;

	Player(Player const &src);
	Player &		operator=(Player const &rhs);

};


#endif
