#ifndef AENTITY_HPP
# define AENTITY_HPP

# include <ncurses.h>

enum ColorCode
{
	PlayerColorCode = 1,
	BulletColorCode,
	SceneColorCode1,
	SceneColorCode2,
	SceneColorCode3,
	SceneColorCode4,
	SceneColorCode5,
	SceneColorCode6,
	SceneColorCode7,
};

class Board;
class Game;

class AEntity
{
public:
	AEntity(int const x, int const y, unsigned int const symbol);
	virtual ~AEntity(void);
	
	virtual void				update(Board *board) = 0;

	int							getPosX(void) const;
	int							getPosY(void) const;
	unsigned int				getSymbol(void) const;
	int							getAttributes(void) const;
	int							getForegroundColor(void) const;
	int							getBackgroundColor(void) const;
	unsigned char				getColorCode(void) const;

	virtual void				setPosX(int x);
	virtual void				setPosY(int y);
	void						setSymbol(unsigned int symbol);

	void						move(int x, int y, Board *board);

protected:

	Game						*_game;
	int							_posX;
	int							_posY;
	unsigned int				_symbol;
	int							_attributes;
	int							_foregroundColor;
	int							_backgroundColor;
	unsigned char				_colorCode;



private:
	
	AEntity(AEntity const &src);
	AEntity &					operator=(AEntity const &rhs);

};

#endif
