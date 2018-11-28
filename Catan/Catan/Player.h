#pragma once
#include "defines.h"
#include "Resources.h"
#include "AbstractToken.h"
#include "AbstractBuilding.h"
#include "Dock.h"
#include "Catan.h"
#include "Town.h"
#include "City.h"
#include "Road.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
using namespace std;
class Player {

public:

	Player(string); // constructor

	//Getters y Setters para recursos
	void setWood(int);
	int getWood(void);
	void setClay(int);
	int getClay(void);
	void setSheep(int);
	int getSheep(void);
	void setWheat(int);
	int getWheat(void);
	void setStone(int);
	int getStone(void);
	int getVictoryPoints(void);
	Catan getCatan(void);
	void setTownsBuilt(int);
	int getTownsBuilt(void);
	void setCitiesBuilt(int);
	int getCitiesBuilt(void);
	void setRoadsBuilt(int);
	int getRoadsBuilt(void);
	void setVictoryPoints(int);
	Road * getRoads(void);
	int throwDice(void);
	void take4resources();
	Coordinates selectCoordinatesForRobber(void);
	resources* selectResources(void); // esta funcion me devuelve en un arreglo de resources los 4 resources que el player quiere dejar cuando sale el robber 
	bool tradePlayer(resources[], resources[]);// te doy, dame ( en ese orden estan los resources)
	error tradePort(resources[], resources, Dock);
	error tradeBank(resources[MAX_RESOURCE_AMMOUNT], resources);
	//void buyDevCard(void);// si queremos
	//void throwDevelopment(developmentCard); // hacer clase development card
	error returnResource(int); // le mando el numero que me dio el dado para ver si tengo que recolectar recursos
	AbstractBuilding * getBuildings();
private:
	int victoryPoints;
	resources * myResources;
	AbstractBuilding buildings[MAX_BUILDING_AMMOUNT];
	Road roads[MAX_ROAD_AMMOUNT];
	int townsBuilt;
	int citiesBuilt;
	int roadsBuilt;
	Catan catan; // para que el player se pueda comunicar con el juego. Por ejemplo en trades, para decir "yo player quiero tradear"
	string name;
	int wood;
	int sheep;
	int clay;
	int stone;
	int wheat;
	//char development[MAX_DEV_CARDS]; // por si usamos development cards
	AbstractToken tokens[MAX_TOKEN]; // arreglo con las piezas del jugador
};