#pragma once
#include "Player.h"
class Rules {
public:
	bool canBuildTown(Player *, Coordinates, Catan *);
	bool canBuildRoad(Player *, Coordinates, Catan *);
	// bool canBuyDevelopment(Player *, Coordinates);
	bool verifyRoads(Player *, Coordinates, Catan *);
private:

};
