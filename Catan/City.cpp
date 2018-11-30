#include "City.h"



City::City(Coordinates coordinates)
{
	this->setAbstractToken(CITY);
	this->setTokenCoordinates(coordinates);
}

City::~City()
{
}
