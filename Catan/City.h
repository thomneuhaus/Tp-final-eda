#pragma once
#include "AbstractBuilding.h"
class City :
	public AbstractBuilding
{
public:
	City(Coordinates); //Construye una city en coordinates
	~City();
};

