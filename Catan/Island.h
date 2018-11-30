#pragma once

typedef enum
{
	BOSQUE,
	COLINA,
	MONTAÑA,
	CAMPO,
	PASTO,
	DESIERTO,
	VACIA

} islandType; // tipos de islas

class Island
{
public:
	Island();
	Island(char coordinate, int diceNumber, islandType type); //constructor
	~Island();

	// getters y setters
	islandType getType(void); //tipo de isla
	char getPosition(void); //posicion de la isla
	void setBlock(bool); //true si tiene el robber encima
	int getNumber(void); //numero de dado para activar isla
	bool getIsBlocked(void); //si esta bloqueada por el robber

private:
	char position;
	int islandNumber; // en numero de la isla
	islandType type;
	bool isBlocked; // por si tiene el robber encima

};

