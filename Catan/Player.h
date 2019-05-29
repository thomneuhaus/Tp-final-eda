#pragma once
#include "Defines.h"
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
    int getWood(void); //devuelve la cantidad de woods que tiene el player
    void setClay(int);
    int getClay(void); //devuelve la cantidad de clays que tiene el player
    void setSheep(int);
    int getSheep(void); //devuelve la cantidad de sheep que tiene el player
    void setWheat(int);
    int getWheat(void); //devuelve la cantidad de wheat que tiene el player
    void setStone(int);
    int getStone(void); //devuelve la cantidad de stones que tiene el player
    int getVictoryPoints(void); // devuelve los victory points del player
    void setTownsBuilt(int);
    int getTownsBuilt(void); // devuelve cuantas towns construyo el player
    void setCitiesBuilt(int);
    int getCitiesBuilt(void); // devuelve cuantas cities construyo el player
    void setRoadsBuilt(int);
    int getRoadsBuilt(void); // devuelve cuantos roads construyo el player
    void setVictoryPoints(int);
    AbstractBuilding * getBuildings(); // devuelve un array con los edificios (towns y cities) que construyo el player
    Road * getRoads(void); // devuelve un array con los caminos construidos por el player
    bool hasResources(tradeIn);// mira si tiene resources para tradear

    int throwDice(void); // tira un dado

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