#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>
# include <ncurses.h>
# include <unistd.h>
# include "Player.hpp"
# include "AEntity.hpp"
# include "Bullet.hpp"
# include "Board.hpp"

# define MAX(a, b)				((a) > (b) ? (a) : (b))
# define MIN(a, b)				((a) < (b) ? (a) : (b))
# define CLAMP(d, d_min, d_max)	(d = MIN(MAX(d_min, d), d_max))

class Game
{
public:

	static const int 			GAME_WINDOW_WIDTH;
	static const int			GAME_WINDOW_HEIGHT;
	static const int			INFO_WINDOW_WIDTH;
	static const int			INFO_WINDOW_HEIGHT;

	static void					playSound(std::string soundFile);

	Game(void);
	~Game(void);

	void						run(void);

private:

	WINDOW *					_gameWindow;
	WINDOW *					_infoWindow;

	Player						*_player;
	Board						*_board;
	Board						*_sceneBoard;

	bool						_isGameOver;
	unsigned long long			_time;
	unsigned long long			_score;
	unsigned int				_lives;
	unsigned int				_bombs;

	Game(Game const &src);
	Game &						operator=(Game const &rhs);

	void						_processInput(void);

	void						_update(void);

	void						_render(void) const;
	void						_updateGameWindow(void) const;
	void						_updateInfoWindow(void) const;
	void						_generateScenery(void);

	

};

#endif
