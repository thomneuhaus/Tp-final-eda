#include "Catan.h"
#include <cstring>
#include <cstdlib>
using namespace std;

int main(void) {
	// aca va la funcion que recibe el arreglo de caracteres
	char player_name1[255];// aca va la funcion que recibe MI NOMBRE el arreglo de caracteres
	char player_name2[255];// funcion que recibe el NOMBRE DEL OTRO PLAYER
	Player player1(player_name1); //insert name
	Player player2(player_name2); //pide el nombre de la otra computadora
	srand(time(NULL));
	int dice1;
	int dice2;
	Player * starter = &player1;
	Player * other = &player2;
	Catan catan(NULL, NULL);
	if (true) {//if(soy server)
		do {
			dice1 = player1.throwDice();
			dice2 = player2.throwDice();
		} while (dice1 == dice2);
		if (dice2 > dice1) {
			Player * aux = starter;
			starter = other;
			other = aux;// se elige aleatoriamente quien empieza
			//send You_start
		}
		else {
			//send i_start
		}
		catan = Catan(&player1, &player2);
		catan.randomize();
	}
	else { // yo soy client
		//recibo quien empieza
		if (true) { //if(i_start) si el server me dice que el empieza
			Player * aux = starter;
			starter = other;
			other = aux;
		}
		char types[MAP_ITEMS_NUMBER]; //recibo el array de types
		char number[ISLANDS_AMMOUNT]; //recibo el array de circular tokens
		catan = Catan(&player1, &player2, types, number);
		catan.randomize();
	}

	Coordinates coordinates;
	do {
		coordinates = starter->selectCoordinates(Coordinates(0, 0, 0)); //como parametro pasale los coordinates donde quiere construir su town el starter
	} while (!catan.getRules().canBuildTown(starter, other, coordinates, true));
	catan.buildTown(coordinates, starter);
	//send construi town en coordinates

	do {
		coordinates = starter->selectCoordinates(Coordinates(0, 0, 0)); //como parametro pasale los coordinates donde quiere construir su town el starter
	} while (!catan.getRules().firstCanBuildRoad(starter, coordinates));
	catan.buildRoad(coordinates, starter);
	//send construi un road en coordinates

	do {
		//recibo donde construye su town el
		coordinates = other->selectCoordinates(Coordinates(0, 0, 0)); //como parametro pasale los coordinates donde quiere construir su town el other
	} while (!catan.getRules().canBuildTown(other, starter, coordinates, true));
	catan.buildTown(coordinates, other);
	
	do {
		//recibo donde construye su road el
		coordinates = other->selectCoordinates(Coordinates(0, 0, 0)); //como parametro pasale los coordinates donde quiere construir su town el other
	} while (!catan.getRules().firstCanBuildRoad(other, coordinates));
	catan.buildRoad(coordinates, other);

	do {
		//recibo donde construye su town el
		coordinates = other->selectCoordinates(Coordinates(0, 0, 0)); //como parametro pasale los coordinates donde quiere construir su town el other
	} while (!catan.getRules().canBuildTown(other, starter, coordinates, true));
	catan.buildTown(coordinates, other);

	if (isalpha(coordinates.getX())) {
		//Para que le de los recursos de las segunda town que construyo el otro player
		switch (catan.getMap()->getIslands()[toupper(coordinates.getX()) - 'A'].getType()) {
		case BOSQUE:
			other->setWood(other->getWood() + 1);
			break;
		case COLINA:
			other->setClay(other->getClay() + 1);
			break;
		case MONTA�A:
			other->setStone(other->getStone() + 1);
			break;
		case CAMPO:
			other->setWheat(other->getWheat() + 1);
			break;
		case PASTO:
			other->setSheep(other->getSheep() + 1);
			break;
		case DESIERTO:
			//Nada
			break;
		}
	}

	if (isalpha(coordinates.getY())) {
		switch (catan.getMap()->getIslands()[toupper(coordinates.getY()) - 'A'].getType()) {
		case BOSQUE:
			other->setWood(other->getWood() + 1);
			break;
		case COLINA:
			other->setClay(other->getClay() + 1);
			break;
		case MONTA�A:
			other->setStone(other->getStone() + 1);
			break;
		case CAMPO:
			other->setWheat(other->getWheat() + 1);
			break;
		case PASTO:
			other->setSheep(other->getSheep() + 1);
			break;
		case DESIERTO:
			//Nada
			break;
		}
	}

	if (isalpha(coordinates.getZ())) {
		switch (catan.getMap()->getIslands()[toupper(coordinates.getZ()) - 'A'].getType()) {
		case BOSQUE:
			other->setWood(other->getWood() + 1);
			break;
		case COLINA:
			other->setClay(other->getClay() + 1);
			break;
		case MONTA�A:
			other->setStone(other->getStone() + 1);
			break;
		case CAMPO:
			other->setWheat(other->getWheat() + 1);
			break;
		case PASTO:
			other->setSheep(other->getSheep() + 1);
			break;
		case DESIERTO:
			//Nada
			break;
		}
	}
	do {
		//recibo donde construye su road el
		coordinates = other->selectCoordinates(Coordinates(0, 0, 0)); //como parametro pasale los coordinates donde quiere construir su town el other
	} while (!catan.getRules().firstCanBuildRoad(other, coordinates));
	catan.buildRoad(coordinates, other);

	do {
		coordinates = starter->selectCoordinates(Coordinates(0, 0, 0)); //como parametro pasale los coordinates donde quiere construir su town el starter
	} while (!catan.getRules().canBuildTown(starter, other, coordinates, true));
	catan.buildTown(coordinates, starter);
	//send construi town en coordinates

	//Para que me de los recursos de las segunda town que construi
	if (isalpha(coordinates.getX())) {
		switch (catan.getMap()->getIslands()[toupper(coordinates.getX()) - 'A'].getType()) {
		case BOSQUE:
			starter->setWood(starter->getWood() + 1);
			break;
		case COLINA:
			starter->setClay(starter->getClay() + 1);
			break;
		case MONTA�A:
			starter->setStone(starter->getStone() + 1);
			break;
		case CAMPO:
			starter->setWheat(starter->getWheat() + 1);
			break;
		case PASTO:
			starter->setSheep(starter->getSheep() + 1);
			break;
		case DESIERTO:
			//Nada
			break;
		}
	}

	if (isalpha(coordinates.getY())) {
		switch (catan.getMap()->getIslands()[toupper(coordinates.getY()) - 'A'].getType()) {
		case BOSQUE:
			starter->setWood(starter->getWood() + 1);
			break;
		case COLINA:
			starter->setClay(starter->getClay() + 1);
			break;
		case MONTA�A:
			starter->setStone(starter->getStone() + 1);
			break;
		case CAMPO:
			starter->setWheat(starter->getWheat() + 1);
			break;
		case PASTO:
			starter->setSheep(starter->getSheep() + 1);
			break;
		case DESIERTO:
			//Nada
			break;
		}
	}

	if (isalpha(coordinates.getZ())) {
		switch (catan.getMap()->getIslands()[toupper(coordinates.getZ()) - 'A'].getType()) {
		case BOSQUE:
			starter->setWood(starter->getWood() + 1);
			break;
		case COLINA:
			starter->setClay(starter->getClay() + 1);
			break;
		case MONTA�A:
			starter->setStone(starter->getStone() + 1);
			break;
		case CAMPO:
			starter->setWheat(starter->getWheat() + 1);
			break;
		case PASTO:
			starter->setSheep(starter->getSheep() + 1);
			break;
		case DESIERTO:
			//Nada
			break;
		}
	}

	do {
		coordinates = starter->selectCoordinates(Coordinates(0, 0, 0)); //como parametro pasale los coordinates donde quiere construir su town el starter
	} while (!catan.getRules().firstCanBuildRoad(starter, coordinates));
	catan.buildRoad(coordinates, starter);
	//send construi road en coordinates

	//Aca ya tenemos el primer turno hecho
	//Aca va la fsm de thomas
	getchar();
}
