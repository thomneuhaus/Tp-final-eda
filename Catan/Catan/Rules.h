#pragma once
#include "Player.h"

class Rules {
public:
	bool canBuildTown(Player *, Coordinates, bool);// La idea seria que el dispatcher haga un if(canBuild) y ahi haga el build si puede hacerlo
	bool canBuildCity(Player *, Coordinates);
	bool canBuildRoad(Player *, Coordinates);
	// bool canBuyDevelopment(Player *, Coordinates);
	bool verifyRoads(Player *, Coordinates);// se fija si hay caminos para poder construir town
	bool firstCanBuildRoad(Player *, Coordinates);
private:

};
