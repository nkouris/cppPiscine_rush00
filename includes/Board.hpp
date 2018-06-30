#ifndef BOARD_HPP
# define BOARD_HPP

# include "AEntity.hpp"
# include <ncurses.h>

//  -------> width, x
// |
// |
// |
// |
// |
// V
// height, y

class Board
{
public:

	Board(int const width, int const height);
	~Board(void);

	AEntity *			getCell(int x, int y) const;
	void				setCell(int x, int y, AEntity *e);

	void				updateAllCells(void);
	void				renderAllCells(WINDOW *win);

private:

	int					_width;
	int					_height;
	AEntity	**			_cells;		// 1D array containing AEntity *

	Board(void);
	Board(Board const &src);
	Board &				operator=(Board const &rhs);

};

#endif
