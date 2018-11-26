#include "Rules.h"

bool Rules::verifyRoads(Player * player, Coordinates coordinates, Catan * catan) {
	for (int i = 0; i < player->getRoadsBuilt(); i++) {
		char x = player->getRoads()[i].getTokenCoordinates().getX();
		char y = player->getRoads()[i].getTokenCoordinates().getY();
		char z = player->getRoads()[i].getTokenCoordinates().getZ();
		if (x == coordinates.getX()) {
			if (y != coordinates.getY() && y != coordinates.getZ() && z != coordinates.getY() && z != coordinates.getZ())
				return false;
		}
		else if (y == coordinates.getX()) {
			if (x != coordinates.getY() && x != coordinates.getZ() && z != coordinates.getY() && z != coordinates.getZ())
				return false;
		}
		else if (z == coordinates.getX()) {
			if (x != coordinates.getY() && x != coordinates.getZ() && y != coordinates.getY() && y != coordinates.getZ())
				return false;
		}
		else if (y == coordinates.getY()) {
			if (z != coordinates.getZ())
				return false;
		}
		else if (y == coordinates.getZ()) {
			if (z != coordinates.getY())
				return false;
		}
		else
			return false;
	}
	return true;
}

bool Rules::canBuildTown(Player * player, Coordinates coordinates, Catan * catan) {
	if (player->getTownsBuilt() >= MAX_TOWNS)
		return false;
	else
	{
		if (!verifyRoads(player, coordinates, catan))
			return false;
		for (int i = 0; i < player->getRoadsBuilt(); i++) {
			if (coordinates == player->getBuildings()[i].getTokenCoordinates())
				return false;
			char x = player->getBuildings()[i].getTokenCoordinates().getX();
			char y = player->getBuildings()[i].getTokenCoordinates().getY();
			char z = player->getBuildings()[i].getTokenCoordinates().getZ();
			if (x == coordinates.getX()) {
				if (y != coordinates.getY() && y != coordinates.getZ() && z != coordinates.getY() && z != coordinates.getZ())
					return false;
			}
			else if (y == coordinates.getX()) {
				if (x != coordinates.getY() && x != coordinates.getZ() && z != coordinates.getY() && z != coordinates.getZ())
					return false;
			}
			else if (z == coordinates.getX()) {
				if (x != coordinates.getY() && x != coordinates.getZ() && y != coordinates.getY() && y != coordinates.getZ())
					return false;
			}
			else if (y == coordinates.getY()) {
				if (z != coordinates.getZ())
					return false;
			}
			else if (y == coordinates.getY()) {
				if (z != coordinates.getZ())
					return false;
			}
			else if (y == coordinates.getZ()) {
				if (z != coordinates.getY())
					return false;
			}
			else
				return true;
		}
	}

}

bool Rules::canBuildRoad(Player * player, Coordinates coordinates, Catan * catan) {
	if (player->getRoadsBuilt() >= MAX_ROAD_AMMOUNT)
		return false;
	for (int i = 0; i < player->getRoadsBuilt(); i++) {
		char x = player->getBuildings()[i].getTokenCoordinates().getX();
		char y = player->getBuildings()[i].getTokenCoordinates().getY();
		char z = player->getBuildings()[i].getTokenCoordinates().getZ();
		if (x == coordinates.getX()) {
			if (y != coordinates.getY() && y != coordinates.getZ() && z != coordinates.getY() && z != coordinates.getZ())
				return false;
		}
		else if (y == coordinates.getX()) {
			if (x != coordinates.getY() && x != coordinates.getZ() && z != coordinates.getY() && z != coordinates.getZ())
				return false;
		}
		else if (z == coordinates.getX()) {
			if (x != coordinates.getY() && x != coordinates.getZ() && y != coordinates.getY() && y != coordinates.getZ())
				return false;
		}
		else if (y == coordinates.getY()) {
			if (z != coordinates.getZ())
				return false;
		}
	}
	return true;
}