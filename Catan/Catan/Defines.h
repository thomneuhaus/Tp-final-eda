#pragma once
#define MAX_TOKEN	50 // maxima cantidad de piezas por jugador
// Para los recursos l parte de la comunicacion
// #define MAX_DEV_CARDS 50
#define MAX_PORT_TRADE 3
#define MAX_RESOURCE_AMMOUNT 4
#define BLOCK 4 //Para el arreglo de resources de un player, como pueden ser infinitos, voy agrandando de a 5 bloques cuando se llena
#define ROBBER_NUMBER 7
#define ROBBER_AMMOUNT 7
#define TAKE_RESOURCE_NUMBER 4
#define CITY 'C'
#define TOWN 'T'
#define ROAD 'R'
#define ROBBER 'L'
#define MAX_ROAD_AMMOUNT 15
#define MAX_TOWNS 5
#define MAX_CITIES 4
#define MAX_BUILDING_AMMOUNT (MAX_TOWNS + MAX_CITIES)
typedef enum {
	ERROR_GETTING_RESOURCE,
	ERROR_TRADING_RESOURCE,
	ERROR_TRADING_PORT,
	NO_ERROR,
	ERROR_TAKING_RESOURCE_POST_ROBBER,
	ERROR_BUILDING_CITY,
	ERROR_GETTING_RESOURCE_TOWN,
	ERROR_GETTING_RESOURCE_CITY
}error;