#pragma once
#include "Island.h"
#include "Dock.h"
#include <iostream>
#include <time.h>

class Map
{
public:
	Map();
	~Map();
	Island * getIslands(void);
	Dock * getDocks(void);

private:
	Island islands[19]; // arreglo de islas
	Dock docks[5]; // arreglo de puertos
	void setIslands();// para poner las islas al principio
};

