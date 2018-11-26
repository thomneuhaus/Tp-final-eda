#include "Catan.h"

Catan::Catan()
{
	//que deberia inicializar siempre?
}

Catan::Catan(Player * player1, Player * player2)
{
	this->player1 = player1;
	this->player2 = player2;
	this->catanError = NO_ERROR;
}

bool Catan::PlayerWantsToTrade(resources give[], resources request[], Player * player) {
	// aca va la funcion que pide si el otro player quiere cambiar.
	bool trade = false;
	return trade;
}

void Catan::ValidTrade(resources give[], resources request[], Player * player)//recibe el player que quiere hacer el cambio
{
	Player * other;
	if (player == player1)
		other = player2;
	else
		other = player1;

	for (int i = 0; give[i] != NULL; i++) {
		switch (give[i])
		{
			case WOOD:
				player->setWood(player->getWood() - 1);
				other->setWood(other->getWood() + 1);
			break;
			case CLAY:
				player->setClay(player->getClay() - 1);
				other->setClay(other->getClay() + 1);
			break;
			case SHEEP:
				player->setSheep(player->getSheep() - 1);
				other->setSheep(other->getSheep() + 1);
			break;
			case WHEAT:
				player->setWheat(player->getWheat() - 1);
				other->setWheat(other->getWheat() + 1);
			break;
			case STONE:
				player->setStone(player->getStone() - 1);
				other->setStone(other->getStone() + 1);
			break;
			default:
				this->catanError = ERROR_TRADING_RESOURCE;
		}
	}

}

bool Catan::isPortTradeValid(resources give[], resources take, Dock dock) {
	


}

bool Catan::checkDockTrade(resources give[], resources take) {
	for (int i = 0; i <= MAX_PORT_TRADE - 1; i++)
	{
		if (give[i] != take)
			return false;
	}
	return true;
}

error Catan::getError() {
	return this->catanError;
}

void Catan::setError(error error) {
	this->catanError = error;
}

void Catan::findNumber(int diceNumber, Player * player)// recibe el numero tirado en los dados (la suma de ambos) y mira el mapa para ver si hay que recolectar recursos
{
	if (diceNumber == ROBBER_NUMBER) {
		// hay que verificar si algun player tiene mas de 7 recursos
		int suma1=0;
		int suma2 = 0;
		suma1 += player1->getWood();
		suma1 += player1->getSheep();
		suma1 += player1->getStone();
		suma1 += player1->getClay();
		suma1 += player1->getWheat();
		suma2 += player2->getWood();
		suma2 += player2->getSheep();
		suma2 += player2->getStone();
		suma2 += player2->getClay();
		suma2 += player2->getWheat();
		if (suma1 > ROBBER_AMMOUNT)
			player1->take4resources();
		if (suma2 > ROBBER_AMMOUNT)
			player2->take4resources();
		Player * other;
		if (player == player1) {
			other = player2;
		}
		else
			other = player1;
		robber.moveRobber(player, other);
	}
	else {
		player1->returnResource(diceNumber); //se fija el resource que estamos buscando
		player2->returnResource(diceNumber);
	}
}

error  Catan::buildTown(Coordinates coordinates, Player * player) 
{
	Town newTown(coordinates);
	player->getBuildings()[player->getTownsBuilt() + player->getCitiesBuilt()] = newTown;
}

error  Catan::buildCity(Coordinates coordinates, Player * player) 
{
	if (player->getCitiesBuilt() >= MAX_CITIES) {
		this->catanError = ERROR_BUILDING_CITY;
		return catanError;
	}

	bool found = false;
	for (int i = 0; i < player->getTownsBuilt() + player->getCitiesBuilt() && !found; i++) //recorro el array de buildings del player
	{
		if (*(player->getBuildings()[i].getTokenCoordinates()) == coordinates) // si encuentro un building en ese lugar
		{
			found = true;
			if (player->getBuildings()[i].getAbstractToken() == TOWN) { // si el building que encontre era un town
				player->getBuildings()[i] = City(coordinates);
				player->setTownsBuilt(player->getTownsBuilt() - 1);
				player->setCitiesBuilt(player->getCitiesBuilt() + 1);
			}
			else
				this->catanError = ERROR_BUILDING_CITY;
		}
	}
	if(!found)
		this->catanError = ERROR_BUILDING_CITY;
	return catanError;
}

error  Catan::buildRoad(Coordinates coordinates, Player * player) {
	Road newRoad(coordinates);
	player->getRoads()[player->getRoadsBuilt()] = newRoad;
}


//Catan::~Catan()
//{
//}
