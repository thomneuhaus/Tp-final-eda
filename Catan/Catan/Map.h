#pragma once
#include "Island.h"
#include "Puerto.h"
#include <iostream>


class Map
{
public:
	Map();
	~Map();

private:
	Island tierra[19];
	Puerto mar[5];

	void setIslandTypes();
};

