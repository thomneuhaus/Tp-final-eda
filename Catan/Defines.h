#pragma once
#define _CRT_SECURE_NO_WARNINGS
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

#define BOSQUE 'M'
#define COLINA 'L'
#define MONTANIA 'P'
#define CAMPO 'T'
#define PASTO 'O'
#define DESIERTO 'N'

#define MAX_ROAD_AMMOUNT 15 //cantidad maxima de roads que se pueden construir
#define MAX_TOWNS 5 //cantidad maxima de towns que se pueden construir
#define MAX_CITIES 4 //cantidad maxima de cities que se pueden construir
#define MAX_BUILDING_AMMOUNT (MAX_TOWNS + MAX_CITIES) //cantidad maxima de edificios que se pueden construir
#define ISLANDS_AMMOUNT 19 //cantidad de islas
#define DOCKS_AMMOUNT 6 //cantidad de puertos
#define MAP_ITEMS_NUMBER (ISLANDS_AMMOUNT + DOCKS_AMMOUNT)
#define LONGEST_ROAD_MIN 5 //cantidad minima de roads para ganar longestRoad
#define EMPTY 6
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



//**********************  Package  ***************************

#define ACK				0x01
#define NAME			0x10
#define NAME_IS			0x11
#define MAP_IS			0x12
#define CIRCULAR_TOKENS	0x13
#define PLAY_WITH_DEV	0x15
#define DEV_CARDS		0x16
#define YOU_START		0x17
#define I_START			0x18
#define DICES_ARE		0x20
#define ROBBER_CARDS	0x21
#define CARD_IS			0x22
#define ROBBER_MOVE		0x23
#define SETTLEMENT		0x24
#define ROAD			0x25
#define CITY			0x26
#define BANK_TRADE		0x27
#define OFFER_TRADE		0x28
#define PASS			0x29
//********  opcional  **********
#define DEV_CARD		0x30
#define MONOPOLY		0x31
#define YEARS_OF_PLENTY	0x32
#define ROAD_BUILDING	0x33
#define KNIGHT			0x34
//******************************
#define YES				0x40
#define NO				0x41
#define I_WON			0x50
#define PLAY_AGAIN		0x51
#define GAME_OVER		0x52
#define ERROR_T			0xFE
#define QUIT			0xFF
#define NO_VALUE		0x36

//************************************************************


//*******************  Communication  ************************

#define HELLO_PORT_STR	"13225"
#define HELLO_PORT		13225

#define MAX_NUMBER_TIME	5000
#define MIN_NUMBER_TIME	2000	

#define CONNECTION_SUCCESS	true
#define CONNECTION_DECLINE	false

#define MESSAGE_RECIVED		true
#define	MESSAGE_NOT_RECIVED	false

//************************************************************

//*******************  General Game  *************************

#define MAX_NUMBER_PIECES	25
#define MAX_NUMBER_TOKENS	19

//************************************************************


//******************  Allegro Defines  ***********************

#define NO_INPUT 0x45


//***************** FUENTE *******************
#define FONT_SIZE	20
#define FONT_SIZE_TRADE	50
#define FONT_SIZE_NAME	70

#define FONT_NAME_X	40
#define FONT_NAME_Y	350

#define FONT_WHEAT_X	1160	
#define FONT_WHEAT_Y	40
#define FONT_WHEAT_X_TRADE		425
#define FONT_WHEAT_Y_TRADE		400
#define FONT_WHEAT_X_TRADE_1		650
#define FONT_WHEAT_Y_TRADE_1		635
#define FONT_WHEAT_X_TRADE_2		650
#define FONT_WHEAT_Y_TRADE_2		435

#define FONT_CLAY_X		1160
#define FONT_CLAY_Y		140
#define FONT_CLAY_X_TRADE		650
#define FONT_CLAY_Y_TRADE		400
#define FONT_CLAY_X_TRADE_1		760
#define FONT_CLAY_Y_TRADE_1		635
#define FONT_CLAY_X_TRADE_2		760
#define FONT_CLAY_Y_TRADE_2		435

#define FONT_WOOD_X		1160
#define FONT_WOOD_Y		240
#define FONT_WOOD_X_TRADE		185
#define FONT_WOOD_Y_TRADE		400
#define FONT_WOOD_X_TRADE_1		860
#define FONT_WOOD_Y_TRADE_1		635
#define FONT_WOOD_X_TRADE_2		860
#define FONT_WOOD_Y_TRADE_2		435

#define FONT_SHEEP_X	1160
#define FONT_SHEEP_Y	490
#define FONT_SHEEP_X_TRADE	1100
#define FONT_SHEEP_Y_TRADE	400
#define FONT_SHEEP_X_TRADE_1	400
#define FONT_SHEEP_Y_TRADE_1	635
#define FONT_SHEEP_X_TRADE_2	400
#define FONT_SHEEP_Y_TRADE_2	435

#define FONT_STONE_X	1160
#define FONT_STONE_Y	590
#define FONT_STONE_X_TRADE	880
#define FONT_STONE_Y_TRADE	400
#define FONT_STONE_X_TRADE_1	525
#define FONT_STONE_Y_TRADE_1	635
#define FONT_STONE_X_TRADE_2	525
#define FONT_STONE_Y_TRADE_2	435

#define FONT_TOWN_X		120
#define FONT_TOWN_Y		652

#define FONT_CITY_X		253
#define FONT_CITY_Y		652

#define FONT_ROAD_X		372
#define FONT_ROAD_Y		649
//********************************************


//****************** ISLAS *******************
//Coordenadas en Y
#define FIRST_LINE		85					
#define SECOND_LINE		FIRST_LINE + 95	
#define THIRD_LINE		SECOND_LINE + 95
#define FOURTH_LINE		THIRD_LINE	+ 95
#define FIFTH_LINE		FOURTH_LINE	+ 95

//Primera coordenada en X
#define FIRST_COLUMN	595
#define SECOND_COLUMN	545
#define THIRD_COLUMN	487
#define FOURTH_COLUMN	540
#define FIFTH_COLUMN	595

#define WIDTH_ISLAND	155 //140
#define HIGH_ISLAND		140	//136

#define DISTANCE_ISLAND	109 //Distancia entre cada isla
#define DIFFERENCE_CLAY 17
#define DIFFERENCE_CLAY_Y 17
#define DIFFERENCE_CLAY_X 8
#define OFFSET_NUMBER	40

//********************************************

//******************* MAR ********************
//Coordenadas
#define SEA_X	430
#define SEA_Y	26 //25
//Tamaño
#define WIDTH_SEA 710
#define HIGH_SEA  629

//********************************************

//************** VERTICES ********************
//Coordenadas en Y
#define FIRST_Y_V		80
#define SECOND_Y_V		FIRST_Y_V + 30
#define THIRD_Y_V		SECOND_Y_V + 55
#define FOURTH_Y_V		THIRD_Y_V +30
#define FIFTH_Y_V		FOURTH_Y_V + 63
#define SIXTH_Y_V		FIFTH_Y_V + 33
#define SEVENTH_Y_V		SIXTH_Y_V + 70
#define EIGTH_Y_V		SEVENTH_Y_V + 30
#define NINETH_Y_V		EIGTH_Y_V + 55
#define TENTH_Y_V		NINETH_Y_V + 35
#define ELEVENTH_Y_V	TENTH_Y_V + 70
#define TWELFTH_Y_V		ELEVENTH_Y_V + 30


//Primera coordenada en X
#define FIRST_X_V		659
#define SECOND_X_V		609
#define THIRD_X_V		609
#define FOURTH_X_V		555
#define FIFTH_X_V		FOURTH_X_V
#define SIXTH_X_V		495
#define SEVENTH_X_V		SIXTH_X_V
#define EIGTH_X_V		FOURTH_X_V
#define NINETH_X_V		FOURTH_X_V
#define TENTH_X_V		SECOND_X_V	
#define ELEVENTH_X_V	SECOND_X_V	
#define	TWELFTH_X_V		FIRST_X_V

#define SIZE_V	30
#define DISTANCE_V 110
//********************************************

//************** ARISTAS ********************
//Coordenadas en Y
#define FIRST_Y_A		96
#define SECOND_Y_A		FIRST_Y_A + 55
#define THIRD_Y_A		SECOND_Y_A + 36
#define FOURTH_Y_A		THIRD_Y_A + 55
#define FIFTH_Y_A		FOURTH_Y_A + 40
#define SIXTH_Y_A		FIFTH_Y_A + 55
#define SEVENTH_Y_A		SIXTH_Y_A + 55
#define EIGTH_Y_A		SEVENTH_Y_A + 40
#define NINETH_Y_A		EIGTH_Y_A + 60
#define TENTH_Y_A		NINETH_Y_A + 40
#define ELEVENTH_Y_A	TENTH_Y_A + 55


//Primera coordenada en X
#define FIRST_X_A		670
#define SECOND_X_A		621
#define THIRD_X_A		605
#define FOURTH_X_A		568
#define FIFTH_X_A		540
#define SIXTH_X_A		513
#define SEVENTH_X_A		568
#define EIGTH_X_A		FOURTH_X_A
#define NINETH_X_A		620
#define TENTH_X_A		SECOND_X_A	
#define ELEVENTH_X_A	680

#define SIZE_A_X	42
#define SIZE_A_Y	22
#define DISTANCE_A 57
#define THICKNESS_LINE 10.0
#define X_DIFFERENCE 10

//********************************************

#define EV_EXIST	true
#define NO_EVENT	false
#define ERROR_EXIST	true
#define NO_ERROR_B	false
#define NOTHING_SELECTED 10

//************* BOTONES DE INPUT *************
#define BUTTON_A	255

#define NOTHING_A	255

#define DICES_A	10
#define OFFER_A	20
#define BANK_A	30
#define QUIT_A	40
#define YES_A	50
#define NO_A	60
#define WOOD_A	70
#define WHEAT_A	80
#define CLAY_A	90
#define STONE_A	100
#define SHEEP_A	110
#define RESET_A	120
#define OK_A	130
#define CITY_A	139
#define CASA_A	150
#define RUTA_A	159
//********************************************

#define TURN_X	346
#define TURN_Y	8
#define TURN_SIZE 60

#define MY_TURN true
#define YOUR_TURN false

#define	WIDTH_DISPLAY	1270
#define	HIGH_DISPLAY	714

#define MAX_COORDENATES_AMMOUNT_V	54
#define MAX_COORDENATES_AMMOUNT_R	72

//************************************************************

