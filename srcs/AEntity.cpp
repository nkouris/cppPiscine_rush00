#include "AEntity.hpp"
#include "Board.hpp"

AEntity::AEntity(int const x, int const y, char const symbol) :
	_posX(x), _posY(y), _symbol(symbol)
{
	this->_attributes = A_BOLD;
	this->_foregroundColor = COLOR_RED;
	this->_backgroundColor = COLOR_GREEN;
	this->_colorCode = PlayerColorCode;
}

AEntity::~AEntity(void) { }

int							AEntity::getPosX(void) const { return (this->_posX); }
int							AEntity::getPosY(void) const { return (this->_posY); }
char						AEntity::getSymbol(void) const { return (this->_symbol); }
int							AEntity::getAttributes(void) const { return (this->_attributes); }
int							AEntity::getForegroundColor(void) const { return (this->_foregroundColor); }
int							AEntity::getBackgroundColor(void) const { return (this->_backgroundColor); }
unsigned char				AEntity::getColorCode(void) const { return (this->_colorCode); }

void						AEntity::setPosX(int x) { this->_posX = x; }
void						AEntity::setPosY(int y) { this->_posY = y; }
void						AEntity::setSymbol(char symbol) { this->_symbol = symbol; }

void						AEntity::move(int x, int y, Board *board)
{
	board->clearCell(this->_posX, this->_posY);
	this->setPosX(x);
	this->setPosY(y);
	board->setCell(this->_posX, this->_posY, this);
}