#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "AEntity.hpp"
# include "IShoot.hpp"

class Player : public AEntity, public IShoot
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

	bool				killMe(void);

private:

	Game *				_game;
	
	int					_shotCooldown;
	int					_cooldown;

	int					_lives;
	int					_bombs;

	Player(Player const &src);
	Player(void);
	Player &		operator=(Player const &rhs);

};


#endif
