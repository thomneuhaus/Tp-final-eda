#include "Town.h"



Town::Town(Coordinates coordinates)
{
	this->setAbstractToken(TOWN);
	this->setTokenCoordinates(coordinates);
}

error Town::getResource(resources resource, Player* player) 
{
	switch (resource)
	{
	case WOOD:
		player->setWood(player->getWood() + 1);
		break;
	case CLAY:
		player->setClay(player->getClay() + 1);
		break;
	case SHEEP:
		player->setSheep(player->getSheep() + 1);
		break;
	case WHEAT:
		player->setWheat(player->getWheat() + 1);
		break;
	case STONE:
		player->setStone(player->getStone() + 1);
		break;
	default:
		player->getCatan().setError(ERROR_GETTING_RESOURCE_TOWN);
	}
}

Town::~Town()
{
}
