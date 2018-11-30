#pragma once
#include "AbstractToken.h"
#include "Defines.h"

class Robber :
	public AbstractToken
{
public:
	int robberNumber = ROBBER_NUMBER; //constante del numero del robber
	Robber();
	Robber(Coordinates); //crea el robber en una posicion
	~Robber();
};

