#ifndef WOMAN_PART_HPP
# define WOMAN_PART_HPP

# include "AEnemy.hpp"

class WomanManager;

class WomanPart : public AEnemy
{
public:

	WomanPart(int const x, int const y, unsigned int const symbol, Game *game, WomanManager *manager, int id);
	~WomanPart(void);

	void				update(Board *board);
	void				movePattern(Board *board);

	void				setManagerDead(void);

private:

	int					_partID;
	WomanManager *		_manager;
	bool				_isManagerDead;

	WomanPart(void);
	WomanPart(WomanPart const &src);
	WomanPart &	operator=(WomanPart const &rhs);

};

#endif
