#ifndef AENTITY_HPP
# define AENTITY_HPP

# include <ncurses.h>

class Board;

class AEntity
{
public:
	AEntity(int const x, int const y, char const symbol);
	virtual ~AEntity(void);
	
	virtual void				update(Board *board) = 0;

	int							getPosX(void) const;
	int							getPosY(void) const;
	char						getSymbol(void) const;
	int							getAttributes(void) const;
	int							getForegroundColor(void) const;
	int							getBackgroundColor(void) const;

	virtual void				setPosX(int x);
	virtual void				setPosY(int y);
	void						setSymbol(char symbol);

	void						move(int x, int y, Board *board);

protected:

	int							_posX;
	int							_posY;
	char						_symbol;
	int							_attributes;
	int							_foregroundColor;
	int							_backgroundColor;

private:
	
	AEntity(AEntity const &src);
	AEntity &					operator=(AEntity const &rhs);

};

#endif
