#pragma once
#include "AbstractToken.h"
#include "defines.h"
#include "Player.h"
#include "Coordinates.h"
class Robber :
	public AbstractToken
{
public:
	int robberNumber = ROBBER_NUMBER;
	void moveRobber(Player *, Player *);
	Robber();
	~Robber();
};

