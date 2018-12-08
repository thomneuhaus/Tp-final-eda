#pragma once
#include "Coordinates.h"
#define MAX_TOKEN	50 // maxima cantidad de piezas por jugador
// Para los recursos l parte de la comunicacion
// #define MAX_DEV_CARDS 50
#define MAX_PORT_TRADE 3 //maxima cantidad de recursos que se puede dar a un dock para tradear
#define MAX_RESOURCE_AMMOUNT 4 //maxima cantidad de recursos que se puede dar al banco para tradear
#define BLOCK 4 //Para el arreglo de resources de un player, como pueden ser infinitos, voy agrandando de a 5 bloques cuando se llena
#define ROBBER_NUMBER 7 //Dado que hay que tirar para mover el robber
#define ROBBER_AMMOUNT 7 //maxima cantidad de recursos para que el robber no te saque la mitad
#define TAKE_RESOURCE_NUMBER 4


//token identifiers
#define CITY_L 'C' 
#define TOWN_L 'T' 
#define ROAD_L 'R'
#define ROBBER_L 'L'

#define MAX_ROAD_AMMOUNT 15 //cantidad maxima de roads que se pueden construir
#define MAX_TOWNS 5 //cantidad maxima de towns que se pueden construir
#define MAX_CITIES 4 //cantidad maxima de cities que se pueden construir
#define MAX_BUILDING_AMMOUNT (MAX_TOWNS + MAX_CITIES) //cantidad maxima de edificios que se pueden construir
#define ISLANDS_AMMOUNT 19 //cantidad de islas
#define DOCKS_AMMOUNT 6 //cantidad de puertos
#define MAP_ITEMS_NUMBER (ISLANDS_AMMOUNT + DOCKS_AMMOUNT)
#define LONGEST_ROAD_MIN 5 //cantidad minima de roads para ganar longestRoad
#define NO_VALUE 6 //coordenada "vacia"
#define VERTEX_AMMOUNT 54 //cantidad de vertices en el mapa
typedef enum {
	ERROR_GETTING_RESOURCE,
	ERROR_TRADING_RESOURCE,
	ERROR_TRADING_PORT,
	NO_ERROR,
	ERROR_TAKING_RESOURCE_POST_ROBBER,
	ERROR_BUILDING_CITY,
	ERROR_GETTING_RESOURCE_TOWN,
	ERROR_GETTING_RESOURCE_CITY,
	ERROR_TRADING_BANK
}error; // tipos de errores que pueden ocurrir