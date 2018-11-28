#pragma once
#include "AbstractBuilding.h"
class City :
	public AbstractBuilding
{
public:
	City(Coordinates);
	~City();
};

