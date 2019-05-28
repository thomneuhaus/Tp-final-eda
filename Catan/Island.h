#pragma once

class Island
{
public:
	Island();
	Island(char coordinate, int diceNumber, char type); //constructor
	~Island();

	// getters y setters
	char getType(void); //tipo de isla
	char getPosition(void); //posicion de la isla
	void setBlock(bool); //true si tiene el robber encima
	char getNumber(void); //numero de dado para activar isla
	bool getIsBlocked(void); //si esta bloqueada por el robber

private:
	char position;
	char islandNumber; // en numero de la isla
	char type;
	bool isBlocked; // por si tiene el robber encima

};

