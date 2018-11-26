#pragma once
#include "Resources.h"
#include "defines.h"
#include "AbstractToken.h"
// para evitar el codigo repetido entre town y city

class AbstractBuilding:
	public AbstractToken 
{
public:
	AbstractBuilding(Coordinates);
	~AbstractBuilding();
	virtual error getResource(resources); // si es city le da 2 de resource al player, si es town le da 1 resource (del resource que le mandaste)
private:
};