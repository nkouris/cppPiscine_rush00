#ifndef AENTITY_HPP
# define AENTITY_HPP

# include <ncurses.h>

enum ColorCode { PlayerColorCode = 1, BulletColorCode, SceneColorCode };

class Board;

class AEntity
{
public:
	AEntity(int const x, int const y, unsigned char const symbol);
	virtual ~AEntity(void);
	
	virtual void				update(Board *board) = 0;

	int							getPosX(void) const;
	int							getPosY(void) const;
	unsigned char				getSymbol(void) const;
	int							getAttributes(void) const;
	int							getForegroundColor(void) const;
	int							getBackgroundColor(void) const;
	unsigned char				getColorCode(void) const;

	virtual void				setPosX(int x);
	virtual void				setPosY(int y);
	void						setSymbol(unsigned char symbol);

	void						move(int x, int y, Board *board);

protected:

	int							_posX;
	int							_posY;
	unsigned char				_symbol;
	int							_attributes;
	int							_foregroundColor;
	int							_backgroundColor;
	unsigned char				_colorCode;



private:
	
	AEntity(AEntity const &src);
	AEntity &					operator=(AEntity const &rhs);

};

#endif
