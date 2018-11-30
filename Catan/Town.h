#pragma once
#include "AbstractBuilding.h"
class Town :
	public AbstractBuilding
{
public:
	Town(Coordinates); //crea un town posicionado en coordinates
	~Town();
};
