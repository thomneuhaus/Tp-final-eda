#include "City.h"



City::City(Coordinates coordinates)
{
	this->setAbstractToken(CITY);
	this->setTokenCoordinates(coordinates);
}

error City::getResource(resources resource, Player * player) {
	switch (resource)
	{
	case WOOD:
		player->setWood(player->getWood() + 2);
		break;
	case CLAY:
		player->setClay(player->getClay() + 2);
		break;
	case SHEEP:
		player->setSheep(player->getSheep() + 2);
		break;
	case WHEAT:
		player->setWheat(player->getWheat() + 2);
		break;
	case STONE:
		player->setStone(player->getStone() + 2);
		break;
	default:
		player->getCatan().setError(ERROR_GETTING_RESOURCE_CITY);
	}
}

City::~City()
{
}
