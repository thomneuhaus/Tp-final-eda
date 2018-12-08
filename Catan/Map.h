#pragma once
#include "Island.h"
#include "Dock.h"
#include "resources.h"
#include <iostream>
#include <time.h>

#include "Defines.h"

class Map
{
public:
	Map();
	Map(char[MAP_ITEMS_NUMBER], char[ISLANDS_AMMOUNT]);
	~Map();
	Island * getIslands(void); //devuelve un array de las islas
	Dock * getDocks(void); //devuelve un array de los puertos
	void setIslands();// para poner las islas al principio
	void setDocks(); //para mezclar los puertos al principio

private:
	Island islands[ISLANDS_AMMOUNT]; // arreglo de islas
	Dock docks[DOCKS_AMMOUNT]; // arreglo de puertos
};