#ifndef AENTITY_HPP
# define AENTITY_HPP

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

	virtual void				setPosX(int x);
	virtual void				setPosY(int y);
	void						setSymbol(char symbol);

	void						markDelete(void);

protected:
	int							_posX;
	int							_posY;
	char						_symbol;
	bool						_delete;

private:
	
	AEntity(AEntity const &src);
	AEntity &					operator=(AEntity const &rhs);

};

#endif
