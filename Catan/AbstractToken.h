 #pragma once
#include "Coordinates.h"

class AbstractToken
{
public:
	AbstractToken(); //Se posiciona en 0,0,0
	AbstractToken(char, Coordinates); //Se manda el identificador de la pieza (ver defines.h) y las coordenadas donde la quiero poner
	void setAbstractToken(char); //Cambia el identificador de la pieza
	char getAbstractToken(void); //Devuelve el identificador de la pieza (ver defines.h)
	Coordinates * getTokenCoordinates(void); //Me devuelve las coordenadas de la pieza
	void setTokenCoordinates(Coordinates); //Cambia las coordenadas de la pieza
	
	~AbstractToken();
private:
	Coordinates tokenCoordinates;
	char value;
};

