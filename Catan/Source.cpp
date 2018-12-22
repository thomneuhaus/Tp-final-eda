#include "Catan.h"
#include "io.h"
#include "defines.h"
#include "controller.h"
#include "client.h"
#include "server.h"
#include <cstring>
#include <cstdlib>
using namespace std;

//AVISO IMPORTANTE: AL FINAL DE CADA TURNO SE ACTUALIZA LA PANTALLA DEL JUGADOR CON LOS CAMBIOS YA REALIZADOS.
/* POR EJEMPLO YO QUIERO CONSTRUIR:
 * - ACTUALIZO EL DISPLAY CON EL SIGUIENTE METODO --> Al.showGeneralDisplay(&P1, &P2, &myMap, turnoFlag); (turnoFlag en 1, si es mi turno)
 * - HAGO LA CONSTRUCCION (LOGICA) (actualiza las fichas del jugador)
 * - LE COMUNICO AL OTRO JUGADOR QUE CONSTRUI 
 * - ACTUALIZO EL DISPLAY CON EL SIGUIENTE METODO --> Al.showGeneralDisplay(&P1, &P2, &myMap, turnoFlag); (turnoFlag en 0, termino m turno, le toca al otro jugador)
*/ 

int main(void) {
	io Al;	//Inicializo allegro
	srand(time(NULL));
	int dice1;
	int dice2;
	
	//IDENTIFICADOR DE CLIENTE O SERVIDO
	int flagSC = AS_CLIENT;
	
	//CARGO EL NOMBRE DEL JUGADOR LOCAL
	char* player1NamePointer;
	char player_name1[255];
	player1NamePointer = Al.getMyName();
	int i = 0;
	while (player1NamePointer != '/0')
	{
		player_name1[i] = player1NamePointer[i];
		i++;
	}
	Player player1(player_name1); //insert name
	
	//CARGO EL NOMBRE DLE JUGADOR VISITANTW
	char player_name2[255];// funcion que recibe el NOMBRE DEL OTRO PLAYER
	Player player2(player_name2); //pide el nombre de la otra computadora
	
	Player * starter = &player1;
	Player * other = &player2;
	Catan catan(NULL, NULL);
	
	//PREPARO PARA CONECTARME
	//Tiempo de inicio
	int startTime = 0;
	//Tiempo ocurrido
	int elapsedTime = 5;
	//Tiempo arbitrario
	int randTime;
	randTime = rand() % (MAX_NUMBER_TIME - MIN_NUMBER_TIME + 1) + MIN_NUMBER_TIME;
	bool connectionStatus;
	
	//CARGO LA IP
	char* ip;
	ip = Al.getMyIp();
	
	//ME INTENTO CONECTAR COMO CLIENTE
	client myPlayer(ip);
	//!!!!!  CARTEL DE CONECTANDO, PRESIONE Q PARA SALIR  !!!!!!!!!!!!
	do
	{
		connectionStatus = myPlayer.startConnection();
	} while (((elapsedTime - startTime) < randTime) && (connectionStatus != CONNECTION_SUCCESS));
	if (connectionStatus == CONNECTION_SUCCESS)
	{
		flagSC = AS_CLIENT;
	}
	
	else if (connectionStatus == CONNECTION_DECLINE)
	{
		myPlayer.~client();
		//!!!!!! ESPERANDO JUGADOR, PRESIONE Q PARA SALIR !!!!!!!!!!!!!!!!
		server myPlayer(ip);

		connectionStatus = myPlayer.startConnection();
		if (connectionStatus == CONNECTION_SUCCESS)
		{
			flagSC = AS_SERVER;
		}
		else if (connectionStatus == CONNECTION_DECLINE)
		{
			//TERMINAR PROGRAMA
		}
	}
	
	
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
		case MONTAÑA:
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
		case MONTAÑA:
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
		case MONTAÑA:
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
		case MONTAÑA:
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
		case MONTAÑA:
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
		case MONTAÑA:
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
