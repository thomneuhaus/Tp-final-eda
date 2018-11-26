#include "Player.h"
#include "Catan.h"
#include "Dock.h"

Player::Player(string name) { // constructor

	wood = 0;
	sheep = 0;
	clay = 0;
	stone = 0;
	wheat = 0;
	citiesBuilt = 0;
	townsBuilt = 0;
	roadsBuilt = 0;
	victoryPoints = 0;
	this->name = name;

}

int Player::getClay() {
	return this->clay;
}

void Player::setClay(int newClays) {
	this->clay = newClays;
}

int Player::getWood() {
	return this->wood;
}

void Player::setWood(int newWoods) {
	this->wood = newWoods;
}
int Player::getSheep() {
	return this->sheep;
}

void Player::setSheep(int newSheep) {
	this->sheep = newSheep;
}
int Player::getWheat() {
	return this->wheat;
}

void Player::setWheat(int newWheats) {
	this->wheat = newWheats;
}
int Player::getStone() {
	return this->stone;
}

void Player::setStone(int newStones) {
	this->stone = newStones;
}
int Player::getVictoryPoints(void) {
	return this->victoryPoints;
}

void Player::setVictoryPoints(int points) {
	this->victoryPoints = points;
}

int Player::throwDice(void) {
	srand(time(NULL));
	return (rand() % 6) + 1;

}

Catan Player::getCatan(void){
	return catan;
}

bool Player::tradePlayer(resources give[], resources request[]) {
	bool answer = getCatan().PlayerWantsToTrade(give, request, this);
	if (answer == true) {
		catan.ValidTrade( give,request, this);
	}
	return answer;
}
error Player::tradePort(resources give[], resources take, Dock dock) {
	switch (dock.tradeType) {
	case 'N': // caso aparte porque necesito tener 3 iguales
		resources giving = give[0];
		for (int i = 1; i <= MAX_PORT_TRADE; i++)
		{
			if (give[i] != giving)
			{
				getCatan().setError(ERROR_TRADING_PORT);
				return getCatan().getError();
			}
		}
		switch (giving) {
		case WOOD:
			wood -= 3;
			break;
		case SHEEP:
			sheep -= 3;
			break;
		case STONE:
			stone -= 3;
			break;
		case WHEAT:
			wheat -= 3;
			break;
		case CLAY:
			clay -= 3;
			break;
		default:
			getCatan().setError(ERROR_TRADING_PORT);
		}
		
		break;

	case 'T':
		bool valid = getCatan().checkDockTrade(give, WHEAT);
		if (valid) {
			wheat -= 2;
		}
		else
			getCatan().setError(ERROR_TRADING_PORT);

		break;

	case 'L':
		bool valid = getCatan().checkDockTrade(give, CLAY);
		if (valid) {
			clay -= 2;
		}
		else 
			getCatan().setError(ERROR_TRADING_PORT);
		break;

	case 'P':
		bool valid = getCatan().checkDockTrade(give, STONE);
		if (valid) {
			stone -= 2;
		}
		else 
			getCatan().setError(ERROR_TRADING_PORT);
		break;

	case 'M':
		bool valid = getCatan().checkDockTrade(give, WOOD);
		if (valid) {
			stone -= 2;
		}
		else
			getCatan().setError(ERROR_TRADING_PORT);
		break;

	case 'O':
		bool valid = getCatan().checkDockTrade(give, SHEEP);
		if (valid) {
			stone -= 2;
		}
		else
			getCatan().setError(ERROR_TRADING_PORT);
		break;
	}

	if (getCatan().getError() == NO_ERROR) {

		switch (take) {
		case WOOD:
			wood++;
			break;
		case CLAY:
			clay++;
			break;
		case WHEAT:
			wheat++;
			break;
		case STONE:
			stone++;
			break;
		case SHEEP:
			sheep++;
			break;
		default:
			getCatan().setError(ERROR_TRADING_PORT);
		}
	}

	return getCatan().getError();
}

error Player::tradeBank(resources give [MAX_RESOURCE_AMMOUNT], resources take) {
	resources giving = give[0];
	for (int i = 1; i <= MAX_RESOURCE_AMMOUNT; i++)
	{
		if (give[i] != giving)
		{
			getCatan().setError(ERROR_TRADING_PORT);
			return getCatan().getError();
		}
	}
	switch (giving) {
	case WOOD:
		wood -= 4;
		break;
	case SHEEP:
		sheep -= 4;
		break;
	case STONE:
		stone -= 4;
		break;
	case WHEAT:
		wheat -= 4;
		break;
	case CLAY:
		clay -= 4;
		break;
	default:
		getCatan().setError(ERROR_TRADING_PORT);
	}
	if (getCatan().getError() == NO_ERROR) {

		switch (take) {
		case WOOD:
			wood++;
			break;
		case CLAY:
			clay++;
			break;
		case WHEAT:
			wheat++;
			break;
		case STONE:
			stone++;
			break;
		case SHEEP:
			sheep++;
			break;
		default:
			getCatan().setError(ERROR_TRADING_PORT);
		}
	}

	return getCatan().getError();
}

void Player::take4resources() {
	resources * takeResource = selectResources();
	for (int i = 0; i < TAKE_RESOURCE_NUMBER; i++)
	{
		switch (takeResource[i]) {
		case WOOD:
			wood--;
			break;
		case CLAY:
			clay--;
			break;
		case WHEAT:
			wheat--;
			break;
		case STONE:
			stone--;
			break;
		case SHEEP:
			sheep--;
			break;
		default:
			getCatan().setError(ERROR_TAKING_RESOURCE_POST_ROBBER);
		}

	}	
}

void Player::setTownsBuilt(int towns) {
	this->townsBuilt = towns;
}
int Player:: getTownsBuilt(void) {
	return this->townsBuilt;
}
void Player:: setCitiesBuilt(int cities) {
	this->citiesBuilt = cities;
}
int Player:: getCitiesBuilt(void) {
	return this->citiesBuilt;
}
void Player:: setRoadsBuilt(int roads) {
	this->roadsBuilt = roads;
}
int Player:: getRoadsBuilt(void) {
	return this->roadsBuilt;
}

Road * Player::getRoads(void) {
	return this->roads;
}

AbstractBuilding * Player:: getBuildings() {
	return this->buildings;
}
Coordinates Player::selectCoordinatesForRobber(void) {
	// en esta funcion el jugador selecciona las coordenadas a las cuales quiere mover el robber
}



error Player::returnResource(int) {// le mando el numero que me dio el dado para ver si tengo que recolectar recursos
	


}