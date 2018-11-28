#pragma once
#include "Defines.h"
#include "Resources.h"
#include "AbstractBuilding.h"
#include "Dock.h"
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
	Player();
	Player(string); // constructor

	//Getters y Setters para recursos
	//FUNCIONAN GETTERS Y SETTERS
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
	void setTownsBuilt(int);
	int getTownsBuilt(void);
	void setCitiesBuilt(int);
	int getCitiesBuilt(void);
	void setRoadsBuilt(int);
	int getRoadsBuilt(void);
	void setVictoryPoints(int);
	AbstractBuilding * getBuildings();
	Road * getRoads(void);
	bool hasResources(resources[]);//FUNCIONA mira si tiene resources para tradear

	int throwDice(void); //FUNCIONA
	Coordinates selectCoordinatesForRobber(void);//CUTY!!
	resources* selectResources(int); // CUTY!! esta funcion me devuelve en un arreglo de resources los 4 resources que el player quiere dejar cuando sale el robber 
	//void buyDevCard(void);// si queremos
	//void throwDevelopment(developmentCard); // hacer clase development card
private:
	int victoryPoints;
	AbstractBuilding buildings[MAX_BUILDING_AMMOUNT];
	Road roads[MAX_ROAD_AMMOUNT];
	int townsBuilt;
	int citiesBuilt;
	int roadsBuilt;
	string name;
	int wood;
	int sheep;
	int clay;
	int stone;
	int wheat;
	//char development[MAX_DEV_CARDS]; // por si usamos development cards
};