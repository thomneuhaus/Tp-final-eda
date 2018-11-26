#include "Robber.h"
#include <cstdlib>
#include <ctime>

void Robber::moveRobber(Player * player, Player * other) {
	setTokenCoordinates(player->selectCoordinatesForRobber());
	bool hasBuilding = false;
	for (int i = 0; i < MAX_BUILDING_AMMOUNT && !hasBuilding; i++) {
		Coordinates coord = other->getBuildings()[i].getTokenCoordinates();
		if (coord.getX() == getTokenCoordinates().getX() || coord.getY() == getTokenCoordinates().getX() || coord.getZ() == getTokenCoordinates().getZ) {
			hasBuilding = true;
		}
	}
	if (hasBuilding) {
		srand(time(NULL));
		switch (rand()%5) {
		case 0:
			other->setClay(other->getClay() - 1);
			player->setClay(player->getClay() + 1);
			break;
		case 1:
			other->setSheep(other->getSheep() - 1);
			player->setSheep(player->getSheep() + 1);
			break;
		case 2:
			other->setWheat(other->getWheat() - 1);
			player->setWheat(player->getWheat() + 1);
			break;
		case 3:
			other->setStone(other->getStone() - 1);
			player->setStone(player->getStone() + 1);
			break;
		case 4:
			other->setWood(other->getWood() - 1);
			player->setWood(player->getWood() + 1);
			break;
		}
	}
}

Robber::Robber()
{
}


Robber::~Robber()
{
}
