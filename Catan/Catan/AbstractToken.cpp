#include "AbstractToken.h"

AbstractToken::AbstractToken(char value, Coordinates coordinates)
{
	this->value = value;
	this->tokenCoordinates = coordinates;
}

Coordinates AbstractToken::getTokenCoordinates(void) {
	return this->tokenCoordinates;
}
void AbstractToken::setTokenCoordinates(Coordinates Coordinates) {
	this->tokenCoordinates = Coordinates;
}

AbstractToken::~AbstractToken()
{
}

void AbstractToken::setAbstractToken(char value) {
	this->value = value;
}
char AbstractToken::getAbstractToken(void) {
	return this->value;
}