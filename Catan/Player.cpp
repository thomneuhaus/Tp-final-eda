#include "Player.h"

Player::Player() {
	wood = 0;
	sheep = 0;
	clay = 0;
	stone = 0;
	wheat = 0;
	citiesBuilt = 0;
	townsBuilt = 0;
	roadsBuilt = 0;
	victoryPoints = 0;
	this->name = "";
}

Player::Player(string nombre) { // constructor
	wood = 0;
	sheep = 0;
	clay = 0;
	stone = 0;
	wheat = 0;
	citiesBuilt = 0;
	townsBuilt = 0;
	roadsBuilt = 0;
	victoryPoints = 0;
	this->name = nombre;
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
	return (rand() % 6) + 1;
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

bool Player::hasResources(tradeIn resources) {
    if ((getWood() < resources.wood) || (getClay() < resources.clay) || (getSheep() < resources.sheep) || (getWheat() < resources.wheat) || (getStone() < resources.stone))
        return false;
    return true;
}