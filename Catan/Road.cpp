#include "Road.h"

Road::Road()
{
	this->setAbstractToken(ROAD_L);
	this->setTokenCoordinates(Coordinates(0,0,6));
}

Road::Road(Coordinates coordinates)
{
	this->setAbstractToken(ROAD_L);
	this->setTokenCoordinates(coordinates);
}


Road::~Road()
{
}

Road& Road :: operator= (Road road)
{
	getTokenCoordinates()->setX(road.getTokenCoordinates()->getX());
	getTokenCoordinates()->setY(road.getTokenCoordinates()->getY());
	getTokenCoordinates()->setZ(road.getTokenCoordinates()->getZ());
	return *this;
}
