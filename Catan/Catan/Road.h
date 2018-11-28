#pragma once
#include "AbstractToken.h"
#include "Defines.h"
class Road :
	public AbstractToken
{
public:
	Road();
	Road(Coordinates);
	~Road();
	Road& operator= (Road road);
};

