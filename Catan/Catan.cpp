#include "Catan.h"


Catan::Catan(Player * player1, Player* player2, char map [MAP_ITEMS_NUMBER], char numbers [ISLANDS_AMMOUNT]) {// constructor por si soy client que tenog que copiar el mapa
	this->player1 = player1;
	this->player2 = player2;
	this->catanError = NO_ERROR;
	this->map = Map(map, numbers);
	Coordinates dessertCoord;
	bool found = false;
	for (int i = 0; i < ISLANDS_AMMOUNT && !found; i++) {
		if (getMap()->getIslands()[i].getType() == DESIERTO) {
			dessertCoord.setX(getMap()->getIslands()[i].getPosition());
			getMap()->getIslands()[i].setBlock(true);
			found = true;
		}
		else
			getMap()->getIslands()[i].setBlock(false);
	}
	this->robber = Robber(dessertCoord);
}
Catan::Catan(Player * player1, Player * player2)
{
	this->player1 = player1;
	this->player2 = player2;
	this->catanError = NO_ERROR;
	Coordinates dessertCoord;
	getMap()->setDocks();
	getMap()->setIslands();
	
	bool found = false;
	for (int i = 0; i < ISLANDS_AMMOUNT && !found; i++) {
		if (getMap()->getIslands()[i].getType() == DESIERTO) {
			dessertCoord.setX(getMap()->getIslands()[i].getPosition());
			getMap()->getIslands()[i].setBlock(true);
			found = true;
		}
		else
			getMap()->getIslands()[i].setBlock(false);
	}
	this->robber = Robber(dessertCoord);
}

void Catan::randomize(void) {
	srand((unsigned int)time(NULL));
}

Robber * Catan::getRobber(void) {
	return &robber;
}

bool Catan::PlayerWantsToTrade(resources give[], resources request[], Player * player, Player * other) {
	// aca va la funcion que pide si el otro player quiere cambiar.
	bool trade = true;
	return trade;
}

void Catan::ValidTrade(resources give[], resources request[], Player * player, Player * other)//recibe el player que quiere hacer el cambio
{
	for (int i = 0; give[i] != END; i++) {
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
	for (int i = 0; request[i] != END; i++) {
		switch (request[i])
		{
		case WOOD:
			player->setWood(player->getWood() + 1);
			other->setWood(other->getWood() - 1);
			break;
		case CLAY:
			player->setClay(player->getClay() + 1);
			other->setClay(other->getClay() - 1);
			break;
		case SHEEP:
			player->setSheep(player->getSheep() + 1);
			other->setSheep(other->getSheep() - 1);
			break;
		case WHEAT:
			player->setWheat(player->getWheat() + 1);
			other->setWheat(other->getWheat() - 1);
			break;
		case STONE:
			player->setStone(player->getStone() + 1);
			other->setStone(other->getStone() - 1);
			break;
		default:
			this->catanError = ERROR_TRADING_RESOURCE;
		}
	}
}

bool Catan::checkDockTrade(resources give[], resources resource) { // se fija que todos los resources de give sean iguales
	for (int i = 0; i <= MAX_PORT_TRADE - 1; i++)
	{
		if (give[i] != resource)
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

void Catan::findNumber(int diceNumber, Player * player, resources resources[] = NULL, Coordinates coordinates = Coordinates())// recibe el numero tirado en los dados (la suma de ambos) y mira el mapa para ver si hay que recolectar recursos
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
			takeResources(player1, resources);
		if (suma2 > ROBBER_AMMOUNT)
			takeResources(player2, resources);
		Player * other;
		if (player == player1) {
			other = player2;
		}
		else
			other = player1;
		moveRobber(player, other, player->selectCoordinatesForRobber(coordinates));//ARREGLAR
	}
	else {
		getResource(diceNumber, player1); //se fija el resource que estamos buscando
		getResource(diceNumber, player2);
	}
}

error  Catan::buildTown(Coordinates coordinates, Player * player) 
{
	Town newTown(coordinates);
	player->getBuildings()[player->getTownsBuilt() + player->getCitiesBuilt()] = newTown;
	player->setVictoryPoints(player->getVictoryPoints() + 1);
	player->setTownsBuilt(player->getTownsBuilt() + 1);
	return NO_ERROR;
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
			City newCity(coordinates);
			found = true;
			if (player->getBuildings()[i].getAbstractToken() == TOWN_L) { // si el building que encontre era un town
				player->getBuildings()[i] = newCity;
				player->setTownsBuilt(player->getTownsBuilt() - 1);
				player->setCitiesBuilt(player->getCitiesBuilt() + 1);
				player->setVictoryPoints(player->getVictoryPoints() + 1);
				player->setWheat(player->getWheat() - 2); //para cobrarle si construyo
				player->setStone(player->getStone() - 3);
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
	player->setRoadsBuilt(player->getRoadsBuilt() + 1);
	if (getLongestRoadPlayer() == NULL) { //si nadie tenia longest road todavia
		if (player->getRoadsBuilt() >= LONGEST_ROAD_MIN) {
			setLongestRoadPlayer(player);
			player->setVictoryPoints(player->getVictoryPoints() + 2);
		}
	}
	else if ((getLongestRoadPlayer()->getRoadsBuilt()) < player->getRoadsBuilt()) { //si el que tenia el longest road tiene menos roads que el que acaba de construir
		getLongestRoadPlayer()->setVictoryPoints(getLongestRoadPlayer()->getVictoryPoints()-2);
		player->setVictoryPoints(player->getVictoryPoints() + 2);
		setLongestRoadPlayer(player);
	}
	return NO_ERROR;
}

bool Catan::canTrade(resources give[], resources request[], Player * player, Player * other) {
	return player->hasResources(give) && other->hasResources(request);
}

bool Catan::tradePlayer(resources give[], resources request[], Player * player) {
	Player * other;
	if (player == player1)
		other = player2;
	else
		other = player1;

	if (!canTrade(give, request, player, other))
		return false;
	bool answer = PlayerWantsToTrade(give, request, player, other);
	if (answer == true) {
		ValidTrade(give, request, player, other);
	}
	return answer;
}

error Catan::tradeDock(resources give[], resources take, Dock dock, Player * player) {
	bool valid;
	resources giving;
	if (!(player->hasResources(give)))
		return ERROR_TRADING_PORT;

	switch (dock.getTradeType()) {
	case 'N': // caso aparte porque necesito tener 3 iguales
		giving = give[0];
		for (int i = 1; i < MAX_PORT_TRADE; i++)
		{
			if (give[i] != giving)
			{
				setError(ERROR_TRADING_PORT);
				return getError();
			}
		}
		switch (giving) {
		case WOOD:
			player->setWood(player->getWood() - 3);
			break;
		case SHEEP:
			player->setSheep(player->getSheep() - 3);
			break;
		case STONE:
			player->setStone(player->getStone() - 3);
			break;
		case WHEAT:
			player->setWheat(player->getWheat() - 3);
			break;
		case CLAY:
			player->setClay(player->getClay() - 3);
			break;
		default:
			setError(ERROR_TRADING_PORT);
		}

		break;

	case 'T':
		valid = checkDockTrade(give, WHEAT);
		if (valid) {
			player->setWheat(player->getWheat() - 2);
		}
		else
			setError(ERROR_TRADING_PORT);

		break;

	case 'L':
		valid = checkDockTrade(give, CLAY);
		if (valid) {
			player->setClay(player->getClay() - 2);
		}
		else
			setError(ERROR_TRADING_PORT);
		break;

	case 'P':
		valid = checkDockTrade(give, STONE);
		if (valid) {
			player->setStone(player->getStone() - 2);
		}
		else
			setError(ERROR_TRADING_PORT);
		break;

	case 'M':
		valid = checkDockTrade(give, WOOD);
		if (valid) {
			player->setWood(player->getWood() - 2);
		}
		else
			setError(ERROR_TRADING_PORT);
		break;

	case 'O':
		valid = checkDockTrade(give, SHEEP);
		if (valid) {
			player->setSheep(player->getSheep() - 2);
		}
		else
			setError(ERROR_TRADING_PORT);
		break;
	}
	if (getError() == NO_ERROR) {
		switch (take) {
		case WOOD:
			player->setWood(player->getWood() + 1);
			break;
		case CLAY:
			player->setClay(player->getClay() + 1);
			break;
		case WHEAT:
			player->setWheat(player->getWheat() + 1);
			break;
		case STONE:
			player->setStone(player->getStone() + 1);
			break;
		case SHEEP:
			player->setSheep(player->getSheep() + 1);
			break;
		default:
			setError(ERROR_TRADING_PORT);
		}
	}

	return getError();
}

error Catan::tradeBank(resources give[MAX_RESOURCE_AMMOUNT+1], resources take, Player * player) {
	
	if ( !(player->hasResources(give)) )
		return ERROR_TRADING_BANK;
	resources giving = give[0];
	give[MAX_RESOURCE_AMMOUNT] = END;
	for (int i = 1; i < MAX_RESOURCE_AMMOUNT; i++)
	{
		if (give[i] != giving)
		{
			setError(ERROR_TRADING_PORT);
			return getError();
		}
	}
	switch (giving) {
	case WOOD:
		player->setWood(player->getWood() - 4);
		break;
	case SHEEP:
		player->setSheep(player->getSheep() - 4);
		break;
	case STONE:
		player->setStone(player->getStone() - 4);
		break;
	case WHEAT:
		player->setWheat(player->getWheat() - 4);
		break;
	case CLAY:
		player->setClay(player->getClay() - 4);
		break;
	default:
		setError(ERROR_TRADING_PORT);
	}
	if (getError() == NO_ERROR) {

		switch (take) {
		case WOOD:
			player->setWood(player->getWood() + 1);
			break;
		case CLAY:
			player->setClay(player->getClay() + 1);
			break;
		case WHEAT:
			player->setWheat(player->getWheat() + 1);
			break;
		case STONE:
			player->setStone(player->getStone() + 1);
			break;
		case SHEEP:
			player->setSheep(player->getSheep() + 1);
			break;
		default:
			setError(ERROR_TRADING_PORT);
		}
	}

	return getError();
}

void Catan::takeResources(Player * player, resources resourcesToTake[]) {
	resources * takeResource = player->selectResources(resourcesToTake);
	for (int i = 0; i < (player->getWood() + player->getSheep() + player->getClay() + player->getWheat() + player->getStone())/2; i++)
	{
		switch (takeResource[i]) {
		case WOOD:
			player->setWood(player->getWood() - 1);
			break;
		case CLAY:
			player->setClay(player->getClay() - 1);
			break;
		case WHEAT:
			player->setWheat(player->getWheat() - 1);
			break;
		case STONE:
			player->setStone(player->getStone() - 1);
			break;
		case SHEEP:
			player->setSheep(player->getSheep() - 1);
			break;
		default:
			setError(ERROR_TAKING_RESOURCE_POST_ROBBER);
		}

	}
}

error Catan::getResourceBuildings(islandType type, Player* player, int qty)
{
	switch (type)
	{
	case BOSQUE:
		player->setWood(player->getWood() + qty);
		break;
	case COLINA:
		player->setClay(player->getClay() + qty);
		break;
	case PASTO:
		player->setSheep(player->getSheep() + qty);
		break;
	case CAMPO:
		player->setWheat(player->getWheat() + qty);
		break;
	case MONTAÑA:
		player->setStone(player->getStone() + qty);
		break;
	}
	return NO_ERROR;
}

void Catan::moveRobber(Player * player, Player * other, Coordinates newRobberCoordinates) {
	getRobber()->setTokenCoordinates(newRobberCoordinates);
	bool hasBuilding = false;
	for (int i = 0; i < MAX_BUILDING_AMMOUNT && !hasBuilding; i++) {
		Coordinates * coord = other->getBuildings()[i].getTokenCoordinates();
		if ((coord->getX() == getRobber()->getTokenCoordinates()->getX()) || (coord->getY() == getRobber()->getTokenCoordinates()->getX()) || (coord->getZ() == getRobber()->getTokenCoordinates()->getX())) {
			hasBuilding = true;
		}
	}
	if (hasBuilding && ((other->getClay() + other->getWood() + other->getWheat() + other->getSheep() + other->getStone())>0)) {
		resources * resource = NULL;
		int dim = 0;
		for (int i = 0; i < player->getWood(); i++) {
			if (dim % BLOCK == 0) {
				resource = (resources * )realloc(resource, (dim + BLOCK) * sizeof(resources));
			}
			resource[dim++] = WOOD;
		}
		for (int i = 0; i < player->getClay(); i++) {
			if (dim % BLOCK == 0) {
				resource = (resources *)realloc(resource, (dim + BLOCK) * sizeof(resources));
			}
			resource[dim++] = CLAY;
		}
		for (int i = 0; i < player->getSheep(); i++) {
			if (dim % BLOCK == 0) {
				resource = (resources *)realloc(resource, (dim + BLOCK) * sizeof(resources));
			}
			resource[dim++] = SHEEP;
		}
		for (int i = 0; i < player->getWheat(); i++) {
			if (dim % BLOCK == 0) {
				resource = (resources *)realloc(resource, (dim + BLOCK) * sizeof(resources));
			}
			resource[dim++] = WHEAT;
		}
		for (int i = 0; i < player->getStone(); i++) {
			if (dim % BLOCK == 0) {
				resource = (resources *)realloc(resource, (dim + BLOCK) * sizeof(resources));
			}
			resource[dim++] = STONE;
		}

		switch (resource[rand() % dim]) {
		case CLAY:
			other->setClay(other->getClay() - 1);
			player->setClay(player->getClay() + 1);
			break;
		case SHEEP:
			other->setSheep(other->getSheep() - 1);
			player->setSheep(player->getSheep() + 1);
			break;
		case WHEAT:
			other->setWheat(other->getWheat() - 1);
			player->setWheat(player->getWheat() + 1);
			break;
		case STONE:
			other->setStone(other->getStone() - 1);
			player->setStone(player->getStone() + 1);
			break;
		case WOOD:
			other->setWood(other->getWood() - 1);
			player->setWood(player->getWood() + 1);
			break;
		}
		free(resource);
	}
}

error Catan::getResource(int dice, Player * player) {
	for (int i = 0; i < 19; i++) {
		if ( (map.getIslands()[i].getNumber() == dice) && (!map.getIslands()[i].getIsBlocked() ) )
		{
			for (int j = 0; j < player->getCitiesBuilt() + player->getTownsBuilt(); j++) {
				if ((player->getBuildings()[j].getTokenCoordinates()->getX() == map.getIslands()[i].getPosition()) || (player->getBuildings()[j].getTokenCoordinates()->getY() == map.getIslands()[i].getPosition()) || (player->getBuildings()[j].getTokenCoordinates()->getZ() == map.getIslands()[i].getPosition())) {
					if (player->getBuildings()[j].getAbstractToken() == TOWN_L) {
						getResourceBuildings(map.getIslands()[i].getType(), player, 1);
					}
					else {
						getResourceBuildings(map.getIslands()[i].getType(), player, 2);
					}
				}
			}
		}
	}
	return NO_ERROR;
}

Map * Catan::getMap(void) {
	return &map;
}
//Catan::~Catan()
//{
//}

Player * Catan::getPlayer1(void) {
	return player1;
}
Player * Catan::getPlayer2(void) {
	return player2;
}

Rules Catan::getRules() {
	return rules;
}

Player * Catan::getLongestRoadPlayer(void) {
	return longestRoad;
}

void Catan::setLongestRoadPlayer(Player * player) {
	this->longestRoad = player;
}