#ifndef WOMAN_MANAGER_HPP
# define WOMAN_MANAGER_HPP

# include "AEnemy.hpp"

class WomanPart;

class WomanManager : public AEnemy
{
public:

	WomanManager(int const x, int const y, Game *game);
	~WomanManager(void);

	void			update(Board *board);
	void			movePattern(Board *board);

	void			partDied(int id);

private:

	WomanPart *		_parts[3];
	bool			_isPartDead[3];
	bool			_isKillingSelf;

	WomanManager(void);
	WomanManager(WomanManager const &src);
	WomanManager &	operator=(WomanManager const &rhs);

};

#endif
