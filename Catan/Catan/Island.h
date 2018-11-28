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

} islandType;

class Island
{
public:
	Island();
	Island(char, int, islandType);
	~Island();
	islandType getType(void); //FUNCIONA
	char getPosition(void); //FUNCIONA
	void setBlock(bool); //FUNCIONA
	int getNumber(void); //FUNCIONA
	bool getIsBlocked(void); //FUNCIONA

private:
	char position;
	int islandNumber; // en numero de la isla
	islandType type;
	bool isBlocked; // por si tiene el robber encima

};

