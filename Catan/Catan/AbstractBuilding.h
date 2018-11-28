#pragma once
#include "Resources.h"
#include "Defines.h"
#include "AbstractToken.h"
// para evitar el codigo repetido entre town y city

class AbstractBuilding:
	public AbstractToken 
{
public:
	AbstractBuilding(Coordinates); //FUNCIONA
	AbstractBuilding(); //FUNCIONA
	~AbstractBuilding();
	AbstractBuilding& operator= (AbstractBuilding); //FUNCIONA
private:
};