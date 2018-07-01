#include "Game.hpp"
#include "BulletKnight.hpp"

const int	Game::GAME_WINDOW_WIDTH = 30;
const int	Game::GAME_WINDOW_HEIGHT = 30;
const int	Game::INFO_WINDOW_WIDTH = 30;
const int	Game::INFO_WINDOW_HEIGHT = 30;

Game::Game(void)
{
	std::srand(time(0));
	initscr();
	raw();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	noecho();
	curs_set(0);
	refresh();

	this->_gameWindow = newwin(GAME_WINDOW_HEIGHT + 2, GAME_WINDOW_WIDTH + 2, 0, 0);
	this->_infoWindow = newwin(INFO_WINDOW_HEIGHT + 2, INFO_WINDOW_WIDTH + 2, 0, GAME_WINDOW_WIDTH + 2);
	
	this->_board = new Board(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
	this->_sceneBoard = new Board(GAME_WINDOW_WIDTH, GAME_WINDOW_HEIGHT);
	
	this->_player = new Player(GAME_WINDOW_WIDTH / 2, GAME_WINDOW_HEIGHT / 2, 'A');
	this->_board->setCell(this->_player->getPosX(), this->_player->getPosY(), this->_player);

	this->_isGameOver = false;
	this->_time = 0;
	this->_score = 0;
	this->_lives= 5;
	this->_bombs = 3;
}

Game::~Game(void)
{
	if (this->_gameWindow) delwin(this->_gameWindow);
	if (this->_infoWindow) delwin(this->_infoWindow);
	endwin();

	delete _board;
}

void				Game::playSound(std::string soundFile)
{
	std::string		command = "afplay " + soundFile + " &";
	std::system(command.c_str());
}

void				Game::run(void)
{
	while (this->_isGameOver == false)
	{
		usleep(25000);
		this->_processInput();
		this->_update();	// disabled for debugging; press 't' to run update once
		this->_render();
	}
}

// -----------------------------------------------------------------------------------
// PROCESS_INPUT
// -----------------------------------------------------------------------------------

void				Game::_processInput(void)
{
	switch (getch())
	{
		
		case (KEY_UP):
			this->_player->move(this->_player->getPosX(), this->_player->getPosY() - 1, this->_board);
			break;
		case (KEY_DOWN):
			this->_player->move(this->_player->getPosX(), this->_player->getPosY() + 1, this->_board);
			break;
		case (KEY_LEFT):
			this->_player->move(this->_player->getPosX() - 1, this->_player->getPosY(), this->_board);
			break;
		case (KEY_RIGHT):
			this->_player->move(this->_player->getPosX() + 1, this->_player->getPosY(), this->_board);
			break;
		case (' '):
			Game::playSound("sounds/laser_1b.wav");
			this->_board->setCell(this->_player->getPosX(), this->_player->getPosY() - 1,
				new BulletKnight(this->_player->getPosX(), this->_player->getPosY() - 1, '*', 10, UP, LEFT));
				//new Bullet(this->_player->getPosX(), this->_player->getPosY() - 1, '*', 10, UP));
			break;
		case ('q'):
			this->_isGameOver = true;
		case ('t'):
			this->_update();
			break;
		default:
			break;
	}
}


// -----------------------------------------------------------------------------------
// UPDATE
// -----------------------------------------------------------------------------------

void				Game::_update(void)
{
	this->_generateScenery();
	
	this->_sceneBoard->updateAllCells();
	this->_board->updateAllCells();
}

void				Game::_generateScenery(void)
{

}

// -----------------------------------------------------------------------------------
// RENDER
// -----------------------------------------------------------------------------------

void				Game::_render(void) const
{
	this->_updateGameWindow();
	this->_updateInfoWindow();
}

void				Game::_updateGameWindow(void) const
{
	wclear(this->_gameWindow);

	this->_sceneBoard->renderAllCells(this->_gameWindow);
	this->_board->renderAllCells(this->_gameWindow);
	
	wborder(this->_gameWindow, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(this->_gameWindow);
}

void				Game::_updateInfoWindow(void) const
{
	wclear(this->_infoWindow);

	mvwprintw(this->_infoWindow, 1, 1, "%s:\t%llu", "Time", this->_time);
	mvwprintw(this->_infoWindow, 2, 1, "%s:\t%llu", "Score", this->_score);
	mvwprintw(this->_infoWindow, 4, 1, "%s:\t%u", "Lives", this->_lives);
	mvwprintw(this->_infoWindow, 5, 1, "%s:\t%u", "Bombs", this->_bombs);

	wborder(this->_infoWindow, '|', '|', '-', '-', '+', '+', '+', '+');
	wrefresh(this->_infoWindow);
}






























