#pragma once
#include "Island.h"
#include "Dock.h"
#include <iostream>
#include <time.h>

#include "Defines.h"

class Map
{
public:
	Map();
	~Map();
	Island * getIslands(void); //FUNCIONA
	Dock * getDocks(void); //FUNCIONA
	void setIslands();// para poner las islas al principio //FUNCIONA
	void setDocks(); //para mezclar los puertos al principio //FUNCIONA

private:
	Island islands[ISLANDS_AMMOUNT]; // arreglo de islas
	Dock docks[DOCKS_AMMOUNT]; // arreglo de puertos
};