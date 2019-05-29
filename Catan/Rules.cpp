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

error Rules::canBuildTown(Player * player, Player * other, Coordinates coordinates, bool isFirstTurn) {
    if (!isFirstTurn && !((player->getClay() >= 1) && (player->getWood() >= 1) && (player->getWheat() >= 1) && (player->getSheep() >= 1))) {// si tiene los recursos
        return ERROR_NO_RESOURCES;
    }

    if (player->getTownsBuilt() >= MAX_TOWNS)
        return ERROR_NO_TOWNS_AVAILABLE;
    if (!isFirstTurn && !verifyRoads(player, coordinates))
        return ERROR_INVALID_COORDINATES;
    for (int i = 0; i < player->getTownsBuilt() + player->getCitiesBuilt(); i++)//para ver que no haya cities ni towns  a dos lineas de distancia
    {
        if (coordinates == *(player->getBuildings()[i].getTokenCoordinates()))
            return ERROR_INVALID_COORDINATES;
        char x = player->getBuildings()[i].getTokenCoordinates()->getX();
        char y = player->getBuildings()[i].getTokenCoordinates()->getY();
        char z = player->getBuildings()[i].getTokenCoordinates()->getZ();
        if (x == coordinates.getX()) {
            if (y == coordinates.getY() || y == coordinates.getZ() || z == coordinates.getY() || z == coordinates.getZ())
                return ERROR_INVALID_COORDINATES;
        }
        else if (y == coordinates.getX()) {
            if (x == coordinates.getY() || x == coordinates.getZ() || z == coordinates.getY() || z == coordinates.getZ())
                return ERROR_INVALID_COORDINATES;
        }
        else if (z == coordinates.getX()) {
            if (x == coordinates.getY() || x == coordinates.getZ() || y == coordinates.getY() || y == coordinates.getZ())
                return ERROR_INVALID_COORDINATES;
        }
        else if (y == coordinates.getY()) {
            if (z == coordinates.getZ())
                return ERROR_INVALID_COORDINATES;
        }
        else if (y == coordinates.getY()) {
            if (z == coordinates.getZ())
                return ERROR_INVALID_COORDINATES;
        }
        else if (y == coordinates.getZ()) {
            if (z == coordinates.getY())
                return ERROR_INVALID_COORDINATES;
        }
    }

    for (int i = 0; i < other->getTownsBuilt() + other->getCitiesBuilt(); i++)//para ver que no haya cities ni towns  a dos lineas de distancia con el otro player
    {
        if (coordinates == *(other->getBuildings()[i].getTokenCoordinates()))
            return ERROR_INVALID_COORDINATES;
        char x = other->getBuildings()[i].getTokenCoordinates()->getX();
        char y = other->getBuildings()[i].getTokenCoordinates()->getY();
        char z = other->getBuildings()[i].getTokenCoordinates()->getZ();
        if (x == coordinates.getX()) {
            if (y == coordinates.getY() || y == coordinates.getZ() || z == coordinates.getY() || z == coordinates.getZ())
                return ERROR_INVALID_COORDINATES;
        }
        else if (y == coordinates.getX()) {
            if (x == coordinates.getY() || x == coordinates.getZ() || z == coordinates.getY() || z == coordinates.getZ())
                return ERROR_INVALID_COORDINATES;
        }
        else if (z == coordinates.getX()) {
            if (x == coordinates.getY() || x == coordinates.getZ() || y == coordinates.getY() || y == coordinates.getZ())
                return ERROR_INVALID_COORDINATES;
        }
        else if (y == coordinates.getY()) {
            if (z == coordinates.getZ())
                return ERROR_INVALID_COORDINATES;
        }
        else if (y == coordinates.getY()) {
            if (z == coordinates.getZ())
                return ERROR_INVALID_COORDINATES;
        }
        else if (y == coordinates.getZ()) {
            if (z == coordinates.getY())
                return ERROR_INVALID_COORDINATES;
        }
    }
    if (!isFirstTurn) {
        player->setWood(player->getWood() - 1); // Para cobrarle porque construyo
        player->setClay(player->getClay() - 1);
        player->setSheep(player->getSheep() - 1);
        player->setWheat(player->getWheat() - 1);
    }
    return NO_ERROR;
}

error Rules::canBuildRoad(Player * player, Player * other, Coordinates coordinates) {
    if (!((player->getClay() >= 1) && (player->getWood() >= 1))) {// si tiene los recursos
        return ERROR_NO_RESOURCES;
    }

    if (player->getRoadsBuilt() >= MAX_ROAD_AMMOUNT)//si tiene roads disponibles
        return ERROR_NO_ROADS_AVAILABLE;


    for (int i = 0; i < player->getRoadsBuilt(); i++) {
        char z = player->getRoads()[i].getTokenCoordinates()->getZ();
        if ((coordinates == *(player->getRoads()[i].getTokenCoordinates())) && (z == coordinates.getZ())) {
            return ERROR_INVALID_COORDINATES;
        }
    }

    for (int i = 0; i < other->getRoadsBuilt(); i++) {
        if ((*(other->getRoads()[i].getTokenCoordinates()) == coordinates) && (other->getRoads()[i].getTokenCoordinates()->getZ() == coordinates.getZ()))
            return ERROR_INVALID_COORDINATES;
    }

    if (!hasAdjacentRoad(player, coordinates)) {
        return ERROR_INVALID_COORDINATES;
    }

    player->setWood(player->getWood() - 1); // Para cobrarle porque construyo
    player->setClay(player->getClay() - 1);
    return NO_ERROR;
}

bool Rules::hasAdjacentRoad(Player * player, Coordinates coordinates) {
	for (int i = 0; i < player->getRoadsBuilt(); i++) {
		if (coordinates.getZ() == NO_VALUE) {
			if (player->getRoads()[i].getTokenCoordinates()->getZ() == NO_VALUE) {
				if (player->getRoads()[i].getTokenCoordinates()->getX() == coordinates.getX()) {
					Coordinates aux(coordinates.getX(), coordinates.getY(), player->getRoads()[i].getTokenCoordinates()->getY());
					for (int i = 0; i < VERTEX_AMMOUNT; i++) {
						if (allVertex[i] == aux)
							return true;
					}
				}
				else if (player->getRoads()[i].getTokenCoordinates()->getY() == coordinates.getY()) {
					Coordinates aux(coordinates.getX(), coordinates.getY(), player->getRoads()[i].getTokenCoordinates()->getX());
					for (int i = 0; i < VERTEX_AMMOUNT; i++) {
						if (allVertex[i] == aux)
							return true;
					}
				}
				else if (player->getRoads()[i].getTokenCoordinates()->getY() == coordinates.getX()) {
					Coordinates aux(coordinates.getX(), coordinates.getY(), player->getRoads()[i].getTokenCoordinates()->getX());
					for (int i = 0; i < VERTEX_AMMOUNT; i++) {
						if (allVertex[i] == aux)
							return true;
					}
				}
				else if (player->getRoads()[i].getTokenCoordinates()->getX() == coordinates.getY()) {
					Coordinates aux(coordinates.getX(), coordinates.getY(), player->getRoads()[i].getTokenCoordinates()->getY());
					for (int i = 0; i < VERTEX_AMMOUNT; i++) {
						if (allVertex[i] == aux)
							return true;
					}
				}
			}
			else {
				if (((coordinates.getX() == player->getRoads()[i].getTokenCoordinates()->getX()) && (coordinates.getY() == player->getRoads()[i].getTokenCoordinates()->getY())) || ((coordinates.getY() == player->getRoads()[i].getTokenCoordinates()->getX()) && (coordinates.getX() == player->getRoads()[i].getTokenCoordinates()->getY()))) {
					for (int i = 0; i < VERTEX_AMMOUNT; i++) {
						if (allVertex[i] == *(player->getRoads()[i].getTokenCoordinates()))
							return true;
					}
				}
			}
		}
		else{
			if (player->getRoads()[i].getTokenCoordinates()->getZ() == NO_VALUE) {
				for (int i = 0; i < VERTEX_AMMOUNT; i++) {
					if (allVertex[i] == coordinates)
						return true;
				}
			}
			else{
				if (coordinates == *(player->getRoads()[i].getTokenCoordinates())) {
					for (int i = 0; i < VERTEX_AMMOUNT; i++) {
						if (allVertex[i] == coordinates)
							return true;
					}
				}
				else if (((coordinates.getX() == player->getRoads()[i].getTokenCoordinates()->getX()) && (coordinates.getY() == player->getRoads()[i].getTokenCoordinates()->getY())) || ((coordinates.getY() == player->getRoads()[i].getTokenCoordinates()->getX()) && (coordinates.getX() == player->getRoads()[i].getTokenCoordinates()->getY()))) {
					Coordinates aux(coordinates.getX(), coordinates.getY(), NO_VALUE);
					for (int i = 0; i < VERTEX_AMMOUNT; i++) {
						if (allVertex[i] == aux)
							return true;
					}
				}
			}
		}
	}
	return false;
}

bool Rules::firstCanBuildRoad(Player * player, Coordinates coordinates) {
	if (hasAdjacentRoad(player, coordinates))
		return false;
	
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

error Rules::canBuildCity(Player * player, Coordinates coordinates) {
    if (!((player->getStone() >= 3) && player->getWheat()>=2 )) {//veo si tiene los recursos necesarios
        return ERROR_NO_RESOURCES;
    }
    if (player->getCitiesBuilt() >= MAX_CITIES) {
        return ERROR_NO_CITIES_AVAILABLE;
    }

    for (int i = 0; i < player->getTownsBuilt() + player->getCitiesBuilt(); i++) //recorro el array de buildings del player
    {
        if (*(player->getBuildings()[i].getTokenCoordinates()) == coordinates) // si encuentro un building en ese lugar
        {
            if(player->getBuildings()[i].getAbstractToken() == TOWN_L)
                return NO_ERROR;
            else
                return ERROR_INVALID_COORDINATES;
        }
    }
    return ERROR_INVALID_COORDINATES;
}