#include "Map.h"


Map::Map()
{

}


Map::~Map()
{
}

void Map::setIslandTypes()
{
	for (int i = 0; i < 19; i++)	//Inicializo la tierra vacia
	{
		tierra[i].setType(VACIA);
	}

	
}
