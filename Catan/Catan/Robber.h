#pragma once
#include "AbstractToken.h"
#include "Defines.h"

class Robber :
	public AbstractToken
{
public:
	int robberNumber = ROBBER_NUMBER;
	Robber();
	Robber(Coordinates); //FUNCIONA
	~Robber();
};

