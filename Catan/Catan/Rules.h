#pragma once
#include "Player.h"
bool isMoveValid();
bool isTokenAvailable(Player * player,  Coordinates);
bool canBuildTown(Player *, Coordinates);
bool canBuildCity(Player *, Coordinates);
bool canBuildRoad(Player *, Coordinates);
// bool canBuyDevelopment(Player *, Coordinates);