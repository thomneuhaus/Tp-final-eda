#pragma once
#include "Player.h"

class Rules {
public:
    error canBuildTown(Player *, Player *, Coordinates, bool);// La idea seria que el dispatcher haga un if(canBuild) y ahi haga el build si puede hacerlo (bool en true si es el primer turno)
    error canBuildCity(Player *player, Coordinates coordinates);
    error canBuildRoad(Player *, Player *, Coordinates); //idem
    // bool canBuyDevelopment(Player *, Coordinates);
    bool verifyRoads(Player *, Coordinates);// se fija si hay caminos para poder construir town
    bool firstCanBuildRoad(Player *, Coordinates); //para construir los caminos del primer turno
    bool hasAdjacentRoad(Player *, Coordinates); //para ver si hay roads vecinas
private:
	//Lo comente porque no lo necesito pero ya lo habia copiado y fue mucho trabajo como para borrar
	// corregir con las correcciones de cuty si lo quieren usar
	/*Coordinates allEdges[] = { Coordinates('0','A', '5'), Coordinates('0','A','B'), Coordinates('0','B','A'), Coordinates('0','B','C'), Coordinates('0','C',EMPTY),
Coordinates('1','C','0'), Coordinates('5','A','D'),
Coordinates('A','B',EMPTY), Coordinates('B','C',EMPTY), Coordinates('1','C','G'), Coordinates('5','D','A'),
Coordinates('A','D',EMPTY), Coordinates('A','E',EMPTY),
Coordinates('B','E',EMPTY), Coordinates('B','F',EMPTY), Coordinates('C','F',EMPTY), Coordinates('C','G',EMPTY), Coordinates('1','G','C'),
Coordinates('5','D','H'),
Coordinates('D','E',EMPTY), Coordinates('E','F',EMPTY), Coordinates('F','G',EMPTY), Coordinates('1','G','C'), Coordinates('5','D','H'),
Coordinates('D','E',EMPTY),
Coordinates('E','F',EMPTY), Coordinates('F','G',EMPTY), Coordinates('1','G','L'), Coordinates('5','H','D'), Coordinates('D','H',EMPTY),
Coordinates('D','I',EMPTY),
Coordinates('E','I',EMPTY), Coordinates('E','J',EMPTY), Coordinates('F','J',EMPTY), Coordinates('F','K',EMPTY), Coordinates('G','K',EMPTY),
Coordinates('G','L',EMPTY), Coordinates('1','L','G'), Coordinates('5','H','4'), Coordinates('H','I',EMPTY), Coordinates('I','J',EMPTY),
Coordinates('J','K',EMPTY),Coordinates('K','L',EMPTY), Coordinates('2','L','1'), Coordinates('4','H','M'), Coordinates('H','M', EMPTY),
Coordinates('I','M',EMPTY), Coordinates('I','N',EMPTY), Coordinates('J','N',EMPTY), Coordinates('J','O',EMPTY), Coordinates('K','O',EMPTY),
Coordinates('K','P',EMPTY),Coordinates('L','P',EMPTY), Coordinates('2','L','P'), Coordinates('4','M','H'), Coordinates('M','N',EMPTY),
Coordinates('N','O',EMPTY), Coordinates('O','P',EMPTY), Coordinates('2','P','L'), Coordinates('4','M','Q'), Coordinates('M','Q',EMPTY),
Coordinates('N','Q',EMPTY), Coordinates('N','R',EMPTY), Coordinates('O','R',EMPTY), Coordinates('O','S',EMPTY), Coordinates('P','S',EMPTY),
Coordinates('2','P','S'), Coordinates('4','Q','M'), Coordinates('Q','R',EMPTY), Coordinates('R','S',EMPTY), Coordinates('2','S','P'),
Coordinates('4','Q','3'), Coordinates('3','Q',EMPTY), Coordinates('3','R','Q'), Coordinates('3','R','S'), Coordinates('3','S','R'), Coordinates('3','S','2')
	};*/

	Coordinates allVertex[VERTEX_AMMOUNT] = { Coordinates('0','A', EMPTY), Coordinates('0','B',EMPTY), Coordinates('0','1','C'), 
	Coordinates('0','5','A'), Coordinates('0','A','B'), Coordinates('0','B','C'), Coordinates('1','C',EMPTY), Coordinates('5','A','D'), Coordinates('A','B','E'), Coordinates('B','C','F'), Coordinates('1','C','G'), Coordinates('5','D',EMPTY), Coordinates('A','D','E'),
	Coordinates('B','E','F'), Coordinates('C','F','G'), Coordinates('1','G',EMPTY), Coordinates('5','D','H'), Coordinates('D','E','I'),
	Coordinates('E','F','J'),
	Coordinates('F','G','K'), Coordinates('1','G','L'), Coordinates('5','H',EMPTY), Coordinates('D','H','I'), Coordinates('E','I','J'),
	Coordinates('F','J','K'),
	Coordinates('G','K','L'), Coordinates('1','2','L'), Coordinates('4','5','H'), Coordinates('H','I','M'), Coordinates('I','J','N'),
	Coordinates('J','K','O'),
	Coordinates('K','L','P'), Coordinates('2','L',EMPTY), Coordinates('4','H','M'), Coordinates('I','M','N'), Coordinates('J','N','O'),
	Coordinates('K','O','P'), Coordinates('2','L','P'), Coordinates('4','M',EMPTY), Coordinates('N','M','Q'), Coordinates('N','O','R'),
	Coordinates('O','P','S'),Coordinates('2','P',EMPTY), Coordinates('4','M','Q'), Coordinates('N','Q','R'), Coordinates('O','R', 'S'),
	Coordinates('2','P','S'), Coordinates('4','Q',EMPTY), Coordinates('3','Q','R'), Coordinates('3','R','S'), Coordinates('2','3','S'),
	Coordinates('3','4','Q'),Coordinates('3','R',EMPTY), Coordinates('3','S',EMPTY) };
};
