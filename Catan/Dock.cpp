#include "Dock.h"



Dock::Dock()
{
}

char Dock::getPosition(void) {
	return this->position;
}
char Dock::getTradeType(void) {
	return this->tradeType;
}

Dock::Dock(char position, char type) {
	this->position = position;
	this->tradeType = type;
}


Dock::~Dock()
{
}
