#pragma once
#include "Coordinates.h"

class AbstractToken
{
public:
	AbstractToken(char, Coordinates);
	void setAbstractToken(char);
	char getAbstractToken(void);
	Coordinates getTokenCoordinates(void);
	void setTokenCoordinates(Coordinates);
	
	~AbstractToken();
private:
	Coordinates tokenCoordinates;
	char value;
};

