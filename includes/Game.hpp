#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>
# include <locale.h>
# include <ncurses.h>
# include <unistd.h>
# include <chrono>
# include "Player.hpp"
# include "AEntity.hpp"
# include "Bullet.hpp"
# include "Board.hpp"
# include "Scene.hpp"
# include "BulletKnight.hpp"
# include "EnemyTypeB.hpp"
# include "EnemyFace.hpp"


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
	void						addScore(unsigned long long inc);

	Board *						getBoard(void) const;
	Board *						getSceneBoard(void) const;
	Player *					getPlayer(void) const;

	void						setGameOver(void);

private:

	WINDOW *					_gameWindow;
	WINDOW *					_infoWindow;

	Player						*_player;
	Board						*_board;
	Board						*_sceneBoard;

	bool										_isGameOver;
	unsigned long long							_score;
	std::chrono::steady_clock::time_point		_start;

	Game(Game const &src);
	Game &						operator=(Game const &rhs);

	void						_processInput(void);

	void						_update(void);

	void						_render(void) const;
	void						_updateGameWindow(void) const;
	void						_updateInfoWindow(void) const;
	void						_generateScenery(void);
	void						_generateEnemies(void);

	

};

#endif
