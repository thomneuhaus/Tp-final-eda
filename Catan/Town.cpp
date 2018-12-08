#include "Town.h"



Town::Town(Coordinates coordinates)
{
	this->setAbstractToken(TOWN_L);
	this->setTokenCoordinates(coordinates);
}

Town::~Town()
{
}