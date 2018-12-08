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
	for (int i = 0; i < 2; i++) {
		Coordinates coordinates;
		do {
			coordinates = starter->selectCoordinates(Coordinates(0, 0, 0)); //como parametro pasale los coordinates donde quiere construir su town el starter
		} while (catan.getRules().canBuildTown(starter, other, coordinates, true));
		catan.buildTown(coordinates, starter);

		do {
			coordinates = starter->selectCoordinates(Coordinates(0, 0, 0)); //como parametro pasale los coordinates donde quiere construir su town el starter
		} while (catan.getRules().firstCanBuildRoad(starter, coordinates));
		catan.buildRoad(coordinates, starter);


		do {
			coordinates = other->selectCoordinates(Coordinates(0, 0, 0)); //como parametro pasale los coordinates donde quiere construir su town el other
		} while (catan.getRules().canBuildTown(other, starter, coordinates, true));
		catan.buildTown(coordinates, other);

		do {
			coordinates = other->selectCoordinates(Coordinates(0, 0, 0)); //como parametro pasale los coordinates donde quiere construir su town el other
		} while (catan.getRules().firstCanBuildRoad(other, coordinates));
		catan.buildRoad(coordinates, other);
	}

	//Aca ya tenemos el primer turno hecho
	//Aca va la fsm de thomas
	getchar();
}
