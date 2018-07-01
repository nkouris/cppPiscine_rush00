#include "Board.hpp"

Board::Board(int const width, int const height)
{
	this->_width = width;
	this->_height = height;
	this->_cells = new AEntity*[width * height];
	for (int i = 0; i < this->_width * this->_height; i++)
		this->_cells[i] = NULL;
}

Board::~Board(void)
{
	for (int i = 0; i < this->_width * this->_height; i++)
	{
		delete this->_cells[i];
	}
	delete [] this->_cells;
}

AEntity *			Board::getCell(int x, int y) const
{
	int				i = this->_width * y + x;

	if (0 <= i && i < this->_width * this->_height)
		return (this->_cells[i]);
	else
		return (NULL);
}

void				Board::setCell(int x, int y, AEntity *e)
{

	if (0 <= x && x < this->_width && 0 <= y && y < this->_height)
	{
		int			i = this->_width * y + x;
		if (this->_cells[i])
		{
			delete this->_cells[i];
			delete e;
			this->_cells[i] = NULL;
		}
		else
			this->_cells[i] = e;
	}
	else
		delete e;

}

void				Board::clearCell(int x, int y)
{
	int				i = this->_width * y + x;

	this->_cells[i] = NULL;
}

void				Board::updateAllCells(void)
{
	for (int i = 0; i < this->_width * this->_height; i++)
	{
		if (this->_cells[i])
			this->_cells[i]->update(this);
	}
}

void				Board::renderAllCells(WINDOW *win)
{
	for (int i = 0; i < this->_width * this->_height; i++)
	{
		if (this->_cells[i])
		{
			unsigned char colorNum = this->_cells[i]->getColorCode();
			init_pair(colorNum, this->_cells[i]->getForegroundColor(), this->_cells[i]->getBackgroundColor());
					
			//mvwaddch(win, this->_cells[i]->getPosY() + 1, this->_cells[i]->getPosX() + 1, this->_cells[i]->getSymbol() | COLOR_PAIR(colorNum));
			int attr = COLOR_PAIR(colorNum) | this->_cells[i]->getAttributes();

			wattron(win, attr);
			mvwprintw(win, this->_cells[i]->getPosY() + 1, this->_cells[i]->getPosX() + 1, "%lc", this->_cells[i]->getSymbol());
			wattroff(win, attr);
			
		}
	}
}
