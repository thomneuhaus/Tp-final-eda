#pragma once
#include "Island.h"
#include "Dock.h"
#include <iostream>


class Map
{
public:
	Map();
	~Map();

private:
	Island tierra[19]; // arreglo de islas
	Dock mar[5]; // arreglo de puertos

	void setIslandTypes();// para poner las islas al principio
};

