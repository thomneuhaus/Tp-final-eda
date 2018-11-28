#include "Rules.h"

bool Rules::verifyRoads(Player * player, Coordinates coordinates) {
	for (int i = 0; i < player->getRoadsBuilt(); i++) {
		char x = player->getRoads()[i].getTokenCoordinates()->getX();
		char y = player->getRoads()[i].getTokenCoordinates()->getY();
		char z = player->getRoads()[i].getTokenCoordinates()->getZ();
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

bool Rules::canBuildTown(Player * player, Coordinates coordinates, bool isFirstTurn) {
	if (!isFirstTurn && !((player->getClay() >= 1) && (player->getWood() >= 1) && (player->getWheat() >= 1) && (player->getSheep() >= 1))) {// si tiene los recursos
		return false;
	}
	
	if (player->getTownsBuilt() >= MAX_TOWNS)
		return false;
	if (!isFirstTurn && !verifyRoads(player, coordinates))
		return false;
	for (int i = 0; i < player->getTownsBuilt() + player->getCitiesBuilt(); i++)//para ver que no haya cities ni towns  a dos lineas de distancia
	{
		if (coordinates == *(player->getBuildings()[i].getTokenCoordinates()))
			return false;
		char x = player->getBuildings()[i].getTokenCoordinates()->getX();
		char y = player->getBuildings()[i].getTokenCoordinates()->getY();
		char z = player->getBuildings()[i].getTokenCoordinates()->getZ();
		if (x == coordinates.getX()) {
			if (y == coordinates.getY() || y == coordinates.getZ() || z == coordinates.getY() || z == coordinates.getZ())
				return false;
		}
		else if (y == coordinates.getX()) {
			if (x == coordinates.getY() || x == coordinates.getZ() || z == coordinates.getY() || z == coordinates.getZ())
				return false;
		}
		else if (z == coordinates.getX()) {
			if (x == coordinates.getY() || x == coordinates.getZ() || y == coordinates.getY() || y == coordinates.getZ())
				return false;
		}
		else if (y == coordinates.getY()) {
			if (z == coordinates.getZ())
				return false;
		}
		else if (y == coordinates.getY()) {
			if (z == coordinates.getZ())
				return false;
		}
		else if (y == coordinates.getZ()) {
			if (z == coordinates.getY())
				return false;
		}
	}
	return true;
}

bool Rules::canBuildRoad(Player * player, Coordinates coordinates) {
	if (!((player->getClay() >= 1) && (player->getWood() >= 1))) {// si tiene los recursos
		return false;
	}

	if (player->getRoadsBuilt() >= MAX_ROAD_AMMOUNT)//si tiene roads disponibles
		return false;

	for (int i = 0; i < player->getRoadsBuilt(); i++) { 
		char x = player->getRoads()[i].getTokenCoordinates()->getX();
		char y = player->getRoads()[i].getTokenCoordinates()->getY();
		char z = player->getRoads()[i].getTokenCoordinates()->getZ();
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
			if (z != coordinates.getZ() && x!= coordinates.getZ())
				return false;
		}
		else if (z == coordinates.getY()) {
			if (y != coordinates.getZ() && x != coordinates.getZ())
				return false;
		}
	}
	return true;
}

bool Rules::firstCanBuildRoad(Player * player, Coordinates coordinates) {
	for (int i = 0; i < player->getRoadsBuilt(); i++) {
		char x = player->getRoads()[i].getTokenCoordinates()->getX();
		char y = player->getRoads()[i].getTokenCoordinates()->getY();
		char z = player->getRoads()[i].getTokenCoordinates()->getZ();
		if (x == coordinates.getX()) {
			if (y == coordinates.getY() || y == coordinates.getZ() || z == coordinates.getY() || z == coordinates.getZ())
				return false;
		}
		else if (y == coordinates.getX()) {
			if (x == coordinates.getY() || x == coordinates.getZ() || z == coordinates.getY() || z == coordinates.getZ())
				return false;
		}
		else if (z == coordinates.getX()) {
			if (x == coordinates.getY() || x == coordinates.getZ() || y == coordinates.getY() || y == coordinates.getZ())
				return false;
		}
		else if (y == coordinates.getY()) {
			if (z == coordinates.getZ() || x == coordinates.getZ())
				return false;
		}
		else if (z == coordinates.getY()) {
			if (y == coordinates.getZ() || x == coordinates.getZ())
				return false;
		}
	}
	
	for (int i = 0; i < player->getTownsBuilt(); i++) {
		if (coordinates.getZ() > 5) {
			char x = player->getBuildings()[i].getTokenCoordinates()->getX();
			char y = player->getBuildings()[i].getTokenCoordinates()->getY();
			char z = player->getBuildings()[i].getTokenCoordinates()->getZ();
			if (x == coordinates.getX()) {
				if (y == coordinates.getY() || y == coordinates.getZ() || z == coordinates.getY() || z == coordinates.getZ())
					return true;
			}
			else if (y == coordinates.getX()) {
				if (x == coordinates.getY() || x == coordinates.getZ() || z == coordinates.getY() || z == coordinates.getZ())
					return true;
			}
			else if (z == coordinates.getX()) {
				if (x == coordinates.getY() || x == coordinates.getZ() || y == coordinates.getY() || y == coordinates.getZ())
					return true;
			}
			else if (y == coordinates.getY()) {
				if (z == coordinates.getZ() || x == coordinates.getZ())
					return true;
			}
			else if (z == coordinates.getY()) {
				if (y == coordinates.getZ() || x == coordinates.getZ())
					return true;
			}
		}
		else
			if (coordinates == *(player->getBuildings()[i].getTokenCoordinates())) {
				return true;
			}
	}
	return false;
}

bool Rules::canBuildCity(Player * player, Coordinates coordinates) {
	if (!((player->getStone() >= 3) && player->getWheat()>=2 )) {//veo si tiene los recursos necesarios
		return false;
	}
	if (player->getCitiesBuilt() >= MAX_CITIES) { //veo si tiene ciudades disponibles
		return false;
	}

	for (int i = 0; i < player->getTownsBuilt() + player->getCitiesBuilt(); i++) //recorro el array de buildings del player
	{
		if (*(player->getBuildings()[i].getTokenCoordinates()) == coordinates) // si encuentro un building en ese lugar
		{
			City newCity(coordinates);
			if (player->getBuildings()[i].getAbstractToken() == TOWN) {
				return true; // porque encontre un town
			}
		}
	}
	return false;
}