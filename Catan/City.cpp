#include "City.h"



City::City(Coordinates coordinates)
{
	this->setAbstractToken(CITY_L);
	this->setTokenCoordinates(coordinates);
}

City::~City()
{
}
