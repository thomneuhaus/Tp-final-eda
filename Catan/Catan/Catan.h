#pragma once
#include "Player.h"
#include "Robber.h"

class Catan
{
public:
	Player * player1; // los datos de los jugadores se guardan ahi
	Player * player2;
	Robber robber;
	error catanError;
	Catan(Player * , Player *);
	~Catan();

	void findNumber(int, Player *);// hace las cosas despues de tirar el dado
	void ValidTrade(resources give[], resources request[], Player *);
	bool PlayerWantsToTrade(resources give[], resources request[], Player *);// el player que quiere cambiar
	error buildTown(Coordinates Coordinates, Player * player);
	error buildCity(Coordinates Coordinates, Player * player);
	error buildRoad(Coordinates Coordinates, Player * player);
	bool isPortTradeValid(resources [], resources, Dock);
	bool checkDockTrade(resources give[], resources take);
	error getError();
	void setError(error);
	error getResource(resources);
};

