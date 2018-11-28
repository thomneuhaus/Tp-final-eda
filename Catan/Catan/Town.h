#pragma once
#include "AbstractBuilding.h"
class Town :
	public AbstractBuilding
{
public:
	Town(Coordinates);
	~Town();
};
