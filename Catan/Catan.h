#pragma once
#include "Robber.h"
#include "Map.h"
#include "Coordinates.h"
#include "Rules.h"
#include "Defines.h"

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
    int resourcesQuantity(Player * player);
    //void findNumber(int, Player *, resources resources[], Coordinates coordinates); // FUNCION QUE TE DIJE QUE HAY QUE ELIMINAR encuentra todas las islas que tienen el numero tirado por el dado y si el numero era un 7 se encarga de llamar a la funcion que mueve al robber
    //NOTA: TODOS LOS ARRAYS DE RESOURCES DEBEN TERMINAR CON UN RESOURCE END (VER RESOURCES.H)
    void ValidTrade(tradeIn give, tradeIn request, Player *, Player *);// si el trade era valido lo hace
    bool canTrade(tradeIn resources1, tradeIn resources2, Player * player, Player * other); //Se fija si player tiene los resources resources1 y si other tiene los resources resources2 para poder tradear
    void buildTown(Coordinates Coordinates, Player * player); // construye un town, recibe el player que quiere construirla y donde quiere construirla, devuelve si hubo algun error en el proceso
    void buildCity(Coordinates Coordinates, Player * player); // se fija si hay una town en coordinates, de ser asi construye una city y les saca los recursos al player (ojo! canBuildCity se fija si tiene esos recursos)
    void buildRoad(Coordinates Coordinates, Player * player); // construye una road y da el longestRoad si es correcto que esto pase
    bool checkDockTrade(Player *, tradeIn give, char resource, Coordinates coordinates); // AUXILIAR: se fija si todos los resources de give, son iguales y si son resource
    void getResource(int diceNumber, Player *); // devuelve los recursos a player segun los numeros que salieron en el dado
    void tradeDock(tradeIn myResources, tradeIn dockResources, Dock, Player *); //Le mando los recursos que quiero darle, se fija que todo el array se del mismo recurso y sea el recurso aceptado por el Dock, y los tradea por 1 dockResources
    void tradeBank(char give, char take, Player *); // para darle 4 del mismo recurso al banco y tradearlo con take
    void takeResources(Player *, tradeIn); // le saca la mitad de resources al player cuando sale el robber si el player tiene mas de 7 recursos (EL ARRAY DE ENTRADA DEBE TENER LA CANTIDAD DE RESOURCES/2 COMO TAMANO)
    error getResourceBuildings(char , Player*, int);// agarra la cantidad de resources de cada isla dependiendo de si hay town o city
    void moveRobber(Player * player, Player * other, Coordinates); //mueve el robber a la coordinate que recibe y roba a other un recurso aleatorio si se mueve el robber a una isla que tenia una city o town de other
    Player * getLongestRoadPlayer(void); //Devuelve el puntero al player con el longestRoad
    void setLongestRoadPlayer(Player *); //Cambia el player con el longestRoad
    bool canBuildTown(Player *, Player *, Coordinates, bool);// La idea seria que el dispatcher haga un if(canBuild) y ahi haga el build si puede hacerlo (bool en true si es el primer turno)
    bool canBuildCity(Player *player, Coordinates coordinates);
    bool canBuildRoad(Player *, Player *, Coordinates);

private:
    Player * player1; // los datos de los jugadores se guardan ahi
    Player * player2;
    Robber robber;
    error catanError;
    Map map;
    Rules rules;
    Player * longestRoad = NULL;
    Coordinates singlePortVertexes[SINGLE_PORT_VERTEX_AMMOUNT] = {Coordinates('0','A','B'), Coordinates('0','B', NO_VALUE),
                                                                  Coordinates('1','C','G'), Coordinates('1','G', NO_VALUE),
                                                                  Coordinates('2','L','P'), Coordinates('2','P', NO_VALUE),
                                                                  Coordinates('3','R','S'), Coordinates('3','R', NO_VALUE),
                                                                  Coordinates('4','M','Q'), Coordinates('4','M', NO_VALUE),
                                                                  Coordinates('5','D','H'), Coordinates('5','D', NO_VALUE)};

    Coordinates doublePortVertexes[DOUBLE_PORT_VERTEX_AMMOUNT] = {Coordinates('0','5','A'), Coordinates('0','A', NO_VALUE),
                                                                  Coordinates('0','B',NO_VALUE), Coordinates('0','B','C'),
                                                                  Coordinates('0','1','C'), Coordinates('1','C', NO_VALUE),
                                                                  Coordinates('1','G',NO_VALUE), Coordinates('1','G','L'),
                                                                  Coordinates('1','2','L'), Coordinates('2','L',NO_VALUE),
                                                                  Coordinates('2','P',NO_VALUE), Coordinates('2','P','S'),
                                                                  Coordinates('2','3','S'), Coordinates('3','S',NO_VALUE),
                                                                  Coordinates('3','R',NO_VALUE), Coordinates('3','Q','R'),
                                                                  Coordinates('3','4','Q'), Coordinates('4','Q',NO_VALUE),
                                                                  Coordinates('4','M',NO_VALUE), Coordinates('4','H','M'),
                                                                  Coordinates('4','5','H'), Coordinates('5','H',NO_VALUE),
                                                                  Coordinates('5','D',NO_VALUE), Coordinates('5','A','D')
    };
};
