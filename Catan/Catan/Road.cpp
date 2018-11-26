#include "Road.h"

Road::Road()
{
	//que deberia inicializar si o si?
}

Road::Road(Coordinates coordinates)
{
	this->setAbstractToken(ROAD);
	this->setTokenCoordinates(coordinates);
}


Road::~Road()
{
}
