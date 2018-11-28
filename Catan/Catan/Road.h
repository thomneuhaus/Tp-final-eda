#pragma once
#include "AbstractToken.h"
#include "Defines.h"
class Road :
	public AbstractToken
{
public:
	Road(Coordinates);
	~Road();
};

