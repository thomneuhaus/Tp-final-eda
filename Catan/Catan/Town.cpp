#include "Town.h"



Town::Town(Coordinates coordinates)
{
	this->setAbstractToken(TOWN);
	this->setTokenCoordinates(coordinates);
}

Town::~Town()
{
}