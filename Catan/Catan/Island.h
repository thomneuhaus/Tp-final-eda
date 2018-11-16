#pragma once
#include "AbstractPlace.h"

typedef enum
{
	BOSQUE,
	COLINA,
	MONTA�A,
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

	islandType type;

};

