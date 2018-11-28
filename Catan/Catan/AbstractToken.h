 #pragma once
#include "Coordinates.h"

class AbstractToken
{
public:
	AbstractToken(); //FUNCIONA
	AbstractToken(char, Coordinates); //FUNCIONA
	void setAbstractToken(char); //FUNCIONA
	char getAbstractToken(void); //FUNCIONA
	Coordinates * getTokenCoordinates(void); //FUNCIONA
	void setTokenCoordinates(Coordinates); //FUNCIONA
	
	~AbstractToken();
private:
	Coordinates tokenCoordinates;
	char value;
};

