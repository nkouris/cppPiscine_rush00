#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "AEntity.hpp"

class Player : public AEntity
{
public:

	Player(int const x, int const y, unsigned char const symbol);
	~Player(void);

	void				setPosX(int x);
	void				setPosY(int y);

	void				update(Board *board);

	void				moveUp(void);
	void				moveDown(void);
	void				moveLeft(void);
	void				moveRight(void);

private:
	
	unsigned char		_symbol;

	Player(Player const &src);
	Player &		operator=(Player const &rhs);

};


#endif
