#pragma once
#include "AbstractPlace.h"
#include "Coordinates.h"
#include "port.h"
class Dock :
	public AbstractPlace
{
public:
	Coordinates Coordinates;
	char tradeType; // para diferenciar los puertos
	// void getDock(port *);

	Dock();
	~Dock();
};

