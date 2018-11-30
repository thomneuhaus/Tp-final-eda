#pragma once
#include "Resources.h"
#include "Defines.h"
#include "AbstractToken.h"
// para evitar el codigo repetido entre town y city

class AbstractBuilding:
	public AbstractToken 
{
public:
	AbstractBuilding(Coordinates); //Le pasas donde lo queres coonstruir
	AbstractBuilding(); // Se construye en 0,0,0
	~AbstractBuilding();
	AbstractBuilding& operator= (AbstractBuilding); //sobrecarga del operador =
private:
};