#pragma once
#include "abstractBuilding.h"
#include"Island.h"
#include "Player.h"
class City :
	public AbstractBuilding
{
public:
	City(Coordinates);
	~City();
	error getResource(resources, Player*);
};

