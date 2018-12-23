#include "Catan.h"
#include "io.h"
#include "defines.h"
#include "auxiliar.h"
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
	
	message inputPlayer2; //Variable para recibir mensajes del otro jugador
	
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
	client myPlayerComu(ip);
	Al.showTryToConnect();
	do
	{
		connectionStatus = myPlayerComu.startConnection();
	} while (((elapsedTime - startTime) < randTime) && (connectionStatus != CONNECTION_SUCCESS));
	if (connectionStatus == CONNECTION_SUCCESS)
	{
		flagSC = AS_CLIENT;
	}
	
	else if (connectionStatus == CONNECTION_DECLINE)
	{
		myPlayerComu.~client();
		Al.showWaitPlayer();
		server myPlayerComu(ip);

		connectionStatus = myPlayerComu.startConnection();
		if (connectionStatus == CONNECTION_SUCCESS)
		{
			flagSC = AS_SERVER;
		}
		else if (connectionStatus == CONNECTION_DECLINE)
		{
			//TERMINAR PROGRAMA
		}
	}
	
	
	if (flagSC == AS_SERVER)
	{
		do 
		{
			dice1 = player1.throwDice();
			dice2 = player2.throwDice();
		} while (dice1 == dice2);
		if (dice2 > dice1) {
			Player * aux = starter;
			starter = other;
			other = aux;// se elige aleatoriamente quien empieza
			myPlayerComu.sendYouStart();
		}
		else 
		{
			myPlayerComu.sendIStart();
		}
		catan = Catan(&player1, &player2);
		catan.randomize();
	}
	else if(flagSC == AS_CLIENT) 
	{
		inputPlayer2 = myPlayerComu.getMessage(); //El programa no sigue hasta recibir un mensaje del otro jugador
		if (inputPlayer2.identifier == )
		{
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
	bool inputFlag = false;
	bool succes = false;
	genIn input;
	
	//Al.showGeneralDisplay(player1, player2, &myMap, MY_TURN);
	
	//*******************  COLOCO UNA CIUDAD  *******************************
	//Espero a que seleccione algo
	while (inputFlag == false)
	{
		inputFlag = Al.isInput();
	}
	inputFlag = false;
	//Cargo lo que selecciono en "input"
	input = Al.getInput();
	
	//Si selecciono contruir un settlement
	if(input.identifier == SETTLEMENT)
	{	
		while(succes == false)
		{
			coordinates = starter->selectCoordinates(Coordinates(input.x, input.y, input.z)); //como parametro pasale los coordinates donde quiere construir su town el starter
			if(!catan.getRules().canBuildTown(starter, other, coordinates, true)//Si las coordenadas recibidas estan mal, pregunto nuevamente por coordenadas nuevas
			{
				while (inputFlag == false)
				{
					inputFlag = Al.isInput();
				}
				input = Al.getInput();
			}
			else
			{
				succes = true;
			}
		}		   
		catan.buildTown(coordinates, starter);
		//traductor coordinates clase caro a coordenates estrucuta cuty
		if(flagSC == AS_SERVER)
		{
			myPlayerComu.sendSettlement(coordinatesAux,3);
		}
		else if(flagSC == AS_CLIENT)
		{
			myPlayerComu.sendSettlement(coordinatesAux,3);
		}	   
	}
	//***********************************************************************
	inputFlag = false;
	succes = false;
			   
	//Al.showGeneralDisplay(player1, player2, &myMap, MY_TURN);		   
			   
	//*************************  COLOCO UN CAMINO  **************************
		//Espero a que seleccione algo
	while (inputFlag == false)
	{
		inputFlag = Al.isInput();
	}
	inputFlag = false;
	//Cargo lo que selecciono en "input"
	input = Al.getInput();
	
	//Si selecciono contruir un settlement
	if(input.identifier == ROAD)
	{	
		while(succes == false)
		{
			coordinates = starter->selectCoordinates(Coordinates(input.x, input.y, input.z)); //como parametro pasale los coordinates donde quiere construir su town el starter
			if(!catan.getRules().canBuildTown(starter, other, coordinates, true)//Si las coordenadas recibidas estan mal, pregunto nuevamente por coordenadas nuevas
			{
				while (inputFlag == false)
				{
					inputFlag = Al.isInput();
				}
				input = Al.getInput();
			}
			else
			{
				succes = true;
			}
		}		   
		catan.buildRoad(coordinates, starter);
		//traductor coordinates clase caro a coordenates estrucuta cuty
		if(flagSC == AS_SERVER)
		{
			myPlayerComu.sendRoad(coordinatesAux,3);
		}
		else if(flagSC == AS_CLIENT)
		{
			myPlayerComu.sendRoad(coordinatesAux,3);
		}	   
	}
	//***********************************************************************
	
	//Al.showGeneralDisplay(player1, player2, &myMap, YOUR_TURN);
			   
	//***************  RECIBO DONDE CONTRUYE SU SETTLEMENT  ****************
	inputPlayer2 = myPlayerComu.getMessage(); //El programa no sigue hasta recibir un mensaje del otro jugador		   
	
	if(inputPlayer2.identifier == SETTLEMENT)
	{
		coordinates = other->selectCoordinates(Coordinates(inputPlayer2.x, inputPlayer2.y, inputPlayer2.z)); //como parametro pasale los coordinates donde quiere construir su town el other
		if (catan.getRules().canBuildTown(other, starter, coordinates, true))
		{
			if(flagSC == AS_SERVER)
			{
				myPlayerComu.sendAck();
			}
			else if(flagSC == AS_CLIENT)
			{
				myPlayerComu.sendAck();
			}
			catan.buildTown(coordinates, other);	
	} 
	//***********************************************************************
	//Al.showGeneralDisplay(player1, player2, &myMap, YOUR_TURN);	
	//***************  RECIBO DONDE CONTRUYE SU ROAD  ****************
	inputPlayer2 = myPlayerComu.getMessage(); //El programa no sigue hasta recibir un mensaje del otro jugador		   
	
	if(inputPlayer2.identifier == Road)
	{
		coordinates = other->selectCoordinates(Coordinates(inputPlayer2.x, inputPlayer2.y, inputPlayer2.z)); //como parametro pasale los coordinates donde quiere construir su town el other
		if (catan.getRules().canBuildTown(other, starter, coordinates, true))
		{
			if(flagSC == AS_SERVER)
			{
				myPlayerComu.sendAck();
			}
			else if(flagSC == AS_CLIENT)
			{
				myPlayerComu.sendAck();
			}
			catan.buildRoad(coordinates, other);	
	} 
	//***********************************************************************
		
	//Al.showGeneralDisplay(player1, player2, &myMap, YOUR_TURN);	
		
	//***************  RECIBO DONDE CONTRUYE SU SETTLEMENT  ****************
	inputPlayer2 = myPlayerComu.getMessage(); //El programa no sigue hasta recibir un mensaje del otro jugador		   
	
	if(inputPlayer2.identifier == SETTLEMENT)
	{
		coordinates = other->selectCoordinates(Coordinates(inputPlayer2.x, inputPlayer2.y, inputPlayer2.z)); //como parametro pasale los coordinates donde quiere construir su town el other
		if (catan.getRules().canBuildTown(other, starter, coordinates, true))
		{
			if(flagSC == AS_SERVER)
			{
				myPlayerComu.sendAck();
			}
			else if(flagSC == AS_CLIENT)
			{
				myPlayerComu.sendAck();
			}
			catan.buildTown(coordinates, other);	
	} 
	//***********************************************************************
	
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
		
	//Al.showGeneralDisplay(player1, player2, &myMap, YOUR_TURN);	
		
	//***************  RECIBO DONDE CONTRUYE SU ROAD  ****************
	inputPlayer2 = myPlayerComu.getMessage(); //El programa no sigue hasta recibir un mensaje del otro jugador		   
	
	if(inputPlayer2.identifier == Road)
	{
		coordinates = other->selectCoordinates(Coordinates(inputPlayer2.x, inputPlayer2.y, inputPlayer2.z)); //como parametro pasale los coordinates donde quiere construir su town el other
		if (catan.getRules().canBuildTown(other, starter, coordinates, true))
		{
			if(flagSC == AS_SERVER)
			{
				myPlayerComu.sendAck();
			}
			else if(flagSC == AS_CLIENT)
			{
				myPlayerComu.sendAck();
			}
			catan.buildRoad(coordinates, other);	
	} 
	//***********************************************************************
	inputFlag = false;
	succes = false;
		
	//Al.showGeneralDisplay(player1, player2, &myMap, MY_TURN);
		
	//*******************  COLOCO UNA CIUDAD  *******************************
	//Espero a que seleccione algo
	while (inputFlag == false)
	{
		inputFlag = Al.isInput();
	}
	inputFlag = false;
	//Cargo lo que selecciono en "input"
	input = Al.getInput();
	
	//Si selecciono contruir un settlement
	if(input.identifier == SETTLEMENT)
	{	
		while(succes == false)
		{
			coordinates = starter->selectCoordinates(Coordinates(input.x, input.y, input.z)); //como parametro pasale los coordinates donde quiere construir su town el starter
			if(!catan.getRules().canBuildTown(starter, other, coordinates, true)//Si las coordenadas recibidas estan mal, pregunto nuevamente por coordenadas nuevas
			{
				while (inputFlag == false)
				{
					inputFlag = Al.isInput();
				}
				input = Al.getInput();
			}
			else
			{
				succes = true;
			}
		}		   
		catan.buildTown(coordinates, starter);
		//traductor coordinates clase caro a coordenates estrucuta cuty
		if(flagSC == AS_SERVER)
		{
			myPlayerComu.sendSettlement(coordinatesAux,3);
		}
		else if(flagSC == AS_CLIENT)
		{
			myPlayerComu.sendSettlement(coordinatesAux,3);
		}	   
	}
	//***********************************************************************
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

	inputFlag = false;
	succes = false;
			   
	//Al.showGeneralDisplay(player1, player2, &myMap, MY_TURN);
			   
	//*************************  COLOCO UN CAMINO  **************************
		//Espero a que seleccione algo
	while (inputFlag == false)
	{
		inputFlag = Al.isInput();
	}
	inputFlag = false;
	//Cargo lo que selecciono en "input"
	input = Al.getInput();
	
	//Si selecciono contruir un settlement
	if(input.identifier == ROAD)
	{	
		while(succes == false)
		{
			coordinates = starter->selectCoordinates(Coordinates(input.x, input.y, input.z)); //como parametro pasale los coordinates donde quiere construir su town el starter
			if(!catan.getRules().canBuildTown(starter, other, coordinates, true)//Si las coordenadas recibidas estan mal, pregunto nuevamente por coordenadas nuevas
			{
				while (inputFlag == false)
				{
					inputFlag = Al.isInput();
				}
				input = Al.getInput();
			}
			else
			{
				succes = true;
			}
		}		   
		catan.buildRoad(coordinates, starter);
		//traductor coordinates clase caro a coordenates estrucuta cuty
		if(flagSC == AS_SERVER)
		{
			myPlayerComu.sendRoad(coordinatesAux,3);
		}
		else if(flagSC == AS_CLIENT)
		{
			myPlayerComu.sendRoad(coordinatesAux,3);
		}	   
	}
	//***********************************************************************
			   
	//Al.showGeneralDisplay(player1, player2, &myMap, YOUR_TURN);
		
	//Aca ya tenemos el primer turno hecho
	//Aca va la fsm de thomas
	getchar();
}
