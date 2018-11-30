#include "AbstractToken.h"

AbstractToken::AbstractToken() {
	value = 0;
}

AbstractToken::AbstractToken(char value, Coordinates coordinates)
{
	this->value = value;
	this->tokenCoordinates = coordinates;
}

AbstractToken::~AbstractToken()
{
}

Coordinates * AbstractToken::getTokenCoordinates(void) {
	return &tokenCoordinates;
}
void AbstractToken::setTokenCoordinates(Coordinates coordinates) {
	this->tokenCoordinates = coordinates;
}

void AbstractToken::setAbstractToken(char value) {
	this->value = value;
}
char AbstractToken::getAbstractToken(void) {
	return this->value;
}