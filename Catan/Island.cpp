#include "Island.h"
Island::Island()
{
	isBlocked = false;
}

Island::Island(char position, int islandNumber, char type) {
	this->position = position;
	this->islandNumber = islandNumber;
	this->type = type;
	this->isBlocked = false; // todas las islas empiezan desbloqueadas
}


Island::~Island()
{
}

char Island::getNumber(void) {
	return islandNumber;
}

bool Island::getIsBlocked(void) {
	return this->isBlocked;
}

char Island::getPosition(void) {
	return this->position;
}
void Island:: setBlock(bool isBlocked) {
	this->isBlocked = isBlocked;
}


char Island::getType(void)
{
	return this ->type;
}
