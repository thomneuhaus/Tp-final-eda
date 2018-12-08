#include "Map.h"


Map::Map()
{

}

Map::Map(char map[MAP_ITEMS_NUMBER], char numbers[ISLANDS_AMMOUNT]) { //por si soy client, copio el mapa
	for (int i = DOCKS_AMMOUNT; i < MAP_ITEMS_NUMBER; i++) {
		switch (map[i])
		{
		case WOOD:
			islands[i] = Island('A' + i - DOCKS_AMMOUNT, numbers[i], BOSQUE);
			break;
		case WHEAT:
			islands[i] = Island('A' + i - DOCKS_AMMOUNT, numbers[i], CAMPO);
			break;
		case STONE:
			islands[i] = Island('A' + i - DOCKS_AMMOUNT, numbers[i], MONTAÑA);
			break;
		case CLAY:
			islands[i] = Island('A' + i - DOCKS_AMMOUNT, numbers[i], COLINA);
			break;
		case SHEEP:
			islands[i] = Island('A' + i - DOCKS_AMMOUNT, numbers[i], PASTO);
			break;
		case DESIERTO:
			islands[i] = Island('A' + i - DOCKS_AMMOUNT, numbers[i], DESIERTO);
			break;
		}
	}

	for (int i = 0; i < DOCKS_AMMOUNT; i++) {
		docks[i] = Dock(i, map[i]);
	}
}

Map::~Map()
{
}

void Map::setIslands()
{
	srand((unsigned int) time(NULL));
	islandType types[ISLANDS_AMMOUNT] = { DESIERTO, BOSQUE, BOSQUE, BOSQUE, BOSQUE, PASTO, PASTO, PASTO, COLINA, COLINA, COLINA, MONTAÑA, MONTAÑA, MONTAÑA, MONTAÑA,CAMPO, CAMPO, CAMPO, CAMPO };
	for (int i = 0; i < ISLANDS_AMMOUNT; i++) {
		int index = rand() % ISLANDS_AMMOUNT;
		islandType aux = types[i];
		types[i] = types[index];
		types[index] = aux;
	}
	int numbers[ISLANDS_AMMOUNT - 1] = { 2, 3, 3, 4, 4, 5, 5, 6, 6, 8, 8, 9, 9, 10, 10, 11, 11, 12 }; //Desierto no tiene numero
	for (int i = 0; i < ISLANDS_AMMOUNT-1; i++) {
		int index = rand() % (ISLANDS_AMMOUNT -1);
		int aux = numbers[i];
		numbers[i] = numbers[index];
		numbers[index] = aux;
	}
	int aux = 0;
	for ( int i = 0, j = 0; i < ISLANDS_AMMOUNT; i++)	//Inicializo la tierra vacia
	{
		if (types[i] == DESIERTO) {
			islands[i] = Island('A' + i, 0, types[i]);
		}
		else
		{
			islands[i] = Island('A' + i, numbers[j], types[i]);
			j++;
		}
	}
}

void Map::setDocks()
{
	srand((unsigned int)time(NULL));
	char types[DOCKS_AMMOUNT] = { 'N', 'T', 'O', 'L', 'P', 'M' };
	for (int i = 0; i < DOCKS_AMMOUNT; i++) {
		int index = rand() % DOCKS_AMMOUNT;
		char aux = types[i];
		types[i] = types[index];
		types[index] = aux;
	}

	for (int j = 0; j < DOCKS_AMMOUNT; j++)	
	{
		docks[j] = Dock(j, types[j]);
	}
}

Island * Map::getIslands(void) {
	return islands;
}
Dock * Map::getDocks(void) {
	return docks;
}
