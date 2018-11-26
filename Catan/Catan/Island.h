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
	Island();
	~Island();
	void setType(islandType);
	islandType getType(void);

private:
	int islandNumber; // en numero de la isla
	islandType type;
	bool isBlocked; // por si tiene el robber encima

};

