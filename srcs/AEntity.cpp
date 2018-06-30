#include "AEntity.hpp"

AEntity::AEntity(int const x, int const y, char const symbol) :
	_posX(x), _posY(y), _symbol(symbol), _delete(false) { }

AEntity::~AEntity(void) { }

int							AEntity::getPosX(void) const { return (this->_posX); }
int							AEntity::getPosY(void) const { return (this->_posY); }
char						AEntity::getSymbol(void) const { return (this->_symbol); }
void						AEntity::setPosX(int x) { this->_posX = x; }
void						AEntity::setPosY(int y) { this->_posY = y; }
void						AEntity::setSymbol(char symbol) { this->_symbol = symbol; }

void						AEntity::markDelete(void) { this->_delete = true; }
