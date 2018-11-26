#include "Map.h"


Map::Map()
{

}


Map::~Map()
{
}

void Map::setIslands()
{
	srand(time(NULL));
	islandType types[19] = { DESIERTO, BOSQUE, BOSQUE, BOSQUE, BOSQUE, PASTO, PASTO, PASTO, COLINA, COLINA, COLINA, MONTAÑA, MONTAÑA, MONTAÑA, MONTAÑA,CAMPO, CAMPO, CAMPO, CAMPO };
	for (int i = 0; i < 19; i++) {
		int index = rand() % 18;
		islandType aux = types[i];
		types[i] = types[index];
		types[index] = aux;
	}
	int numbers[18] = { 2, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10, 11, 12 };
	for (int i = 0; i < 19; i++) {
		int index = rand() % 18;
		int aux = numbers[i];
		numbers[i] = numbers[index];
		numbers[index] = aux;
	}
	int aux = 0;
	char position = 'A';
	for ( int i = 0; i < 18; i++)	//Inicializo la tierra vacia
	{
		if (types[i] == DESIERTO) {
			islands[i] = Island(position, 0, types[i]);
			aux = numbers[i];
		}
		else
		{
			islands[i] = Island(position, numbers[i], types[i]);
		}
		position++;
	}
	islands[18] = Island('A' + 18, aux, types[18]);
}


