#pragma once
#include "abstractBuilding.h"
#include "Player.h"
class Town :
	public AbstractBuilding
{
public:
	Town(Coordinates);
	~Town();
	error getResource(resources, Player *);
};
