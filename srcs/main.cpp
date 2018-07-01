# include "Game.hpp"

int			main(void)
{
	while (true)
	{
		Game game;
		game.run();

		nodelay(stdscr, FALSE);
		while (true)
		{
			int ch = getch();
			if (ch == 'r' || ch == 'R') break;
			else if (ch == 'q' || ch == 'Q') return (0);
		}
	}
	return (0);
}
