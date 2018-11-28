#pragma once
#include "Player.h"
#include "Robber.h"
#include "Map.h"
#include "Coordinates.h"
#include "Rules.h"

class Catan
{
public:
	Catan(Player * , Player *); //FUNCIONA
	//~Catan();
	Robber * getRobber(void); //FUNCIONA
	Player * getPlayer1(void); //FUNCIONA
	Player * getPlayer2(void); //FUNCIONA
	error getError(); //FUNCIONA
	void setError(error); //FUNCIONA
	Map * getMap(void); //FUNCIONA
	Rules getRules(void);

	void randomize(void);//FUNCIONA //genera la semilla para el rand (llamar una vez al principio del juego y listo.) //FUNCIONA
	void findNumber(int, Player *);//FUNCIONA // encuentra todas las islas que tienen el numero tirado por el dado y si el numero era un 7 se encarga de llamar a la funcion que mueve al robber
	void ValidTrade(resources give[], resources request[], Player *, Player *);// si el trade era valido lo hace
	bool PlayerWantsToTrade(resources give[], resources request[], Player *, Player *);// el player que quiere cambiar llama a esta funcion y hay que llamar a la funcion de cuty que le pregunta al otro player si quiere tradear y si quiere se llama a validtrade y sino no se hace nada
	bool canTrade(resources[], resources[], Player *, Player *);//FUNCIONA
	error buildTown(Coordinates Coordinates, Player * player);//FUNCIONA // construye la casita, recibe el player que quiere construirla y donde quiere construirla, devuelve si hubo algun error en el proceso FUNCIONA
	error buildCity(Coordinates Coordinates, Player * player);//FUNCIONA // idem buildTown FUNCIONA
	error buildRoad(Coordinates Coordinates, Player * player); // idem buildTown 
	bool checkDockTrade(resources give[], resources resource); // AUXILIAR: se fija si todos los resources de give, son iguales y si son resource
	error getResource(int diceNumber, Player *);//FUNCIONA // devuelve los recursos a player segun los numeros que salieron en el dado FUNCIONA
	bool tradePlayer(resources give[], resources receive [], Player *); //FUNCIONA // recibe los resources que le quiero dar al otro player, los resources que recibo yo y quien soy yo 
	error tradeDock(resources myResources [], resources dockResources, Dock, Player *);//FUNCIONA// 
	error tradeBank(resources[MAX_RESOURCE_AMMOUNT+1], resources, Player *);//FUNCIONA // para darle 4 del mismo recurso al banco
	void takeResources(Player *); // le saca la mitad de resources al player cuando sale el robber si el player tiene mas de 7 recursos
	error getResourceBuildings(islandType , Player*, int);//FUNCIONA// agarra la cantidad de resources de cada isla dependiendo de si hay town o city FUNCIONA
	void moveRobber(Player *, Player *, Coordinates); //FUNCIONA. mueve el robber a la coordinate que recibe
	Player * getLongestRoadPlayer(void);
	void setLongestRoadPlayer(Player *);
private:
	Player * player1; // los datos de los jugadores se guardan ahi
	Player * player2;
	Robber robber;
	error catanError;
	Map map;
	Rules rules;
	Player * longestRoad = NULL;
};

