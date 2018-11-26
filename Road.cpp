#include "Road.h"



Road::Road(Coordinates coordinates)
{
	this->setAbstractToken(ROAD);
	this->setTokenCoordinates(coordinates);
}


Road::~Road()
{
}
