#pragma once
#include "Robber.h"
#include "Map.h"
#include "Coordinates.h"
#include "Rules.h"
#include "resources.h"

class Catan
{
public:
	Catan(Player *, Player*, char[MAP_ITEMS_NUMBER], char[ISLANDS_AMMOUNT]);
	Catan(Player * , Player *); //Se mandan punteros a los dos players, primero es player1
	//~Catan();
	// Getters y setters
	Robber * getRobber(void); //Devuelve puntero al Robber 
	Player * getPlayer1(void); //Devuelve puntero a player1
	Player * getPlayer2(void); //Devuelve puntero a player2
	error getError(); //Devuelve si hubo un error (ver enum en defines.h)
	void setError(error); //Cambia el error
	Map * getMap(void); //Devuelve el puntero al mapa
	Rules getRules(void); //Devuelva las reglas

	void randomize(void); //genera la semilla para el rand (llamar una vez al principio del juego y listo.) //FUNCIONA
	
	void findNumber(int diceNumber, Player * player, resources resources1[], resources resources2[], Coordinates coordinates);// recibe el numero tirado en los dados (la suma de ambos) y mira el mapa para ver si hay que recolectar recursos. encuentra todas las islas que tienen el numero tirado por el dado y si el numero era un 7 se encarga de llamar a la funcion que mueve al robber
	//NOTA: TODOS LOS ARRAYS DE RESOURCES DEBEN TERMINAR CON UN RESOURCE END (VER RESOURCES.H)
	void ValidTrade(resources give[], resources request[], Player *, Player *);// si el trade era valido lo hace
	bool PlayerWantsToTrade(resources give[], resources request[], Player *, Player *);// el player que quiere cambiar llama a esta funcion y hay que llamar a la funcion de cuty que le pregunta al otro player si quiere tradear y si quiere se llama a validtrade y sino no se hace nada
	bool canTrade(resources resources1[], resources resources2[], Player * player, Player * other); //Se fija si player tiene los resources resources1 y si other tiene los resources resources2 para poder tradear
	error buildTown(Coordinates Coordinates, Player * player); // construye un town, recibe el player que quiere construirla y donde quiere construirla, devuelve si hubo algun error en el proceso
	error buildCity(Coordinates Coordinates, Player * player); // se fija si hay una town en coordinates, de ser asi construye una city y les saca los recursos al player (ojo! canBuildCity se fija si tiene esos recursos) 
	error buildRoad(Coordinates Coordinates, Player * player); // construye una road y da el longestRoad si es correcto que esto pase 
	bool checkDockTrade(resources give[], resources resource); // AUXILIAR: se fija si todos los resources de give, son iguales y si son resource
	error getResource(int diceNumber, Player *); // devuelve los recursos a player segun los numeros que salieron en el dado
	bool tradePlayer(resources give[], resources receive [], Player *); // recibe los resources que le quiero dar al otro player, los resources que recibo yo y quien soy yo 
	error tradeDock(resources myResources [], resources dockResources, Dock, Player *); //Le mando los recursos que quiero darle, se fija que todo el array se del mismo recurso y sea el recurso aceptado por el Dock, y los tradea por 1 dockResources 
	error tradeBank(resources[MAX_RESOURCE_AMMOUNT+1], resources take, Player *); // para darle 4 del mismo recurso al banco y tradearlo con take
	void takeResources(Player *, resources []); // le saca la mitad de resources al player cuando sale el robber si el player tiene mas de 7 recursos (EL ARRAY DE ENTRADA DEBE TENER LA CANTIDAD DE RESOURCES/2 COMO TAMANO)
	error getResourceBuildings(char , Player*, int);// agarra la cantidad de resources de cada isla dependiendo de si hay town o city
	void moveRobber(Player * player, Player * other, Coordinates); //mueve el robber a la coordinate que recibe y roba a other un recurso aleatorio si se mueve el robber a una isla que tenia una city o town de other
	Player * getLongestRoadPlayer(void); //Devuelve el puntero al player con el longestRoad
	void setLongestRoadPlayer(Player *); //Cambia el player con el longestRoad


private:
	Player * player1; // los datos de los jugadores se guardan ahi
	Player * player2;
	Robber robber;
	error catanError;
	Map map;
	Rules rules;
	Player * longestRoad = NULL;
};

