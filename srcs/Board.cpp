#include "Board.hpp"
#include "Game.hpp"

Board::Board(int const width, int const height)
{
	this->_cells = new AEntity*[width * height];
	for (int i = 0; i < Game::GAME_WINDOW_WIDTH * Game::GAME_WINDOW_HEIGHT; i++)
		this->_cells[i] = NULL;	
}

Board::~Board(void)
{
	for (int i = 0; i < Game::GAME_WINDOW_WIDTH * Game::GAME_WINDOW_HEIGHT; i++)
	{
//		delete this->_cells[i];		// WHY DOES THIS CAUSE MALLOC ERROR
	}
	delete [] this->_cells;
}

AEntity *			Board::getCell(int x, int y) const
{
	int				i = Game::GAME_WINDOW_WIDTH * y + x;

	if (0 <= i && i < Game::GAME_WINDOW_WIDTH * Game::GAME_WINDOW_HEIGHT)
		return (this->_cells[i]);
	else
		return (NULL);
}

void				Board::setCell(int x, int y, AEntity *e)
{
	// simplified version for debugging
	int				i = Game::GAME_WINDOW_WIDTH * y + x;
	
	if (0 <= i && i < Game::GAME_WINDOW_WIDTH * Game::GAME_WINDOW_HEIGHT)
		this->_cells[Game::GAME_WINDOW_WIDTH * y + x] = e;

	// later version, with collision detection handled here
	/*
	if (0 <= i && i < Game::GAME_WINDOW_WIDTH * Game::GAME_WINDOW_HEIGHT)
	{
		if (this->_cells[i])
		{
			delete this->_cells[i];
			delete e;
			this->_cells[i] = NULL;
		}
		else
			this->_cells[Game::GAME_WINDOW_WIDTH * y + x] = e;
	}
	else
		delete e;
	*/
}

void				Board::updateAllCells(void)
{
	for (int i = 0; i < Game::GAME_WINDOW_WIDTH * Game::GAME_WINDOW_HEIGHT; i++)
	{
		if (this->_cells[i])
			this->_cells[i]->update(this);
	}
}

void				Board::renderAllCells(WINDOW *win)
{
	for (int i = 0; i < Game::GAME_WINDOW_WIDTH * Game::GAME_WINDOW_HEIGHT; i++)
	{
		if (this->_cells[i])
			mvwprintw(win, this->_cells[i]->getPosY() + 1, this->_cells[i]->getPosX() + 1, "%c", this->_cells[i]->getSymbol());
	}
}
