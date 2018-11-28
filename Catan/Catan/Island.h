#pragma once
#include "AbstractPlace.h"

typedef enum
{
	BOSQUE,
	COLINA,
	MONTAÑA,
	CAMPO,
	PASTO,
	DESIERTO,
	VACIA

} islandType;

class Island :
	public AbstractPlace
{
public:
	Island(char, int, islandType);
	~Island();
	islandType getType(void);
	char getPosition(void);
	void setBlock(bool);

private:
	char position;
	int islandNumber; // en numero de la isla
	islandType type;
	bool isBlocked; // por si tiene el robber encima

};

