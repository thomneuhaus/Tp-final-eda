#pragma once
#include "Player.h"

class Rules {
public:
	bool canBuildTown(Player *, Player *, Coordinates, bool);// La idea seria que el dispatcher haga un if(canBuild) y ahi haga el build si puede hacerlo (bool en true si es el primer turno)
	bool canBuildCity(Player *, Coordinates); //idem pero sin bool
	bool canBuildRoad(Player *, Player*, Coordinates); //idem
	// bool canBuyDevelopment(Player *, Coordinates);
	bool verifyRoads(Player *, Coordinates);// se fija si hay caminos para poder construir town
	bool firstCanBuildRoad(Player *, Coordinates); //para construir los caminos del primer turno
	bool hasAdjacentRoad(Player *, Coordinates); //para ver si hay roads vecinas
private:
	//Lo comente porque no lo necesito pero ya lo habia copiado y fue mucho trabajo como para borrar
	// corregir con las correcciones de cuty si lo quieren usar
	/*Coordinates allEdges[] = { Coordinates('0','A', '5'), Coordinates('0','A','B'), Coordinates('0','B','A'), Coordinates('0','B','C'), Coordinates('0','C',NO_VALUE),
Coordinates('1','C','0'), Coordinates('5','A','D'),
Coordinates('A','B',NO_VALUE), Coordinates('B','C',NO_VALUE), Coordinates('1','C','G'), Coordinates('5','D','A'),
Coordinates('A','D',NO_VALUE), Coordinates('A','E',NO_VALUE),
Coordinates('B','E',NO_VALUE), Coordinates('B','F',NO_VALUE), Coordinates('C','F',NO_VALUE), Coordinates('C','G',NO_VALUE), Coordinates('1','G','C'),
Coordinates('5','D','H'),
Coordinates('D','E',NO_VALUE), Coordinates('E','F',NO_VALUE), Coordinates('F','G',NO_VALUE), Coordinates('1','G','C'), Coordinates('5','D','H'),
Coordinates('D','E',NO_VALUE),
Coordinates('E','F',NO_VALUE), Coordinates('F','G',NO_VALUE), Coordinates('1','G','L'), Coordinates('5','H','D'), Coordinates('D','H',NO_VALUE),
Coordinates('D','I',NO_VALUE),
Coordinates('E','I',NO_VALUE), Coordinates('E','J',NO_VALUE), Coordinates('F','J',NO_VALUE), Coordinates('F','K',NO_VALUE), Coordinates('G','K',NO_VALUE),
Coordinates('G','L',NO_VALUE), Coordinates('1','L','G'), Coordinates('5','H','4'), Coordinates('H','I',NO_VALUE), Coordinates('I','J',NO_VALUE),
Coordinates('J','K',NO_VALUE),Coordinates('K','L',NO_VALUE), Coordinates('2','L','1'), Coordinates('4','H','M'), Coordinates('H','M', NO_VALUE),
Coordinates('I','M',NO_VALUE), Coordinates('I','N',NO_VALUE), Coordinates('J','N',NO_VALUE), Coordinates('J','O',NO_VALUE), Coordinates('K','O',NO_VALUE),
Coordinates('K','P',NO_VALUE),Coordinates('L','P',NO_VALUE), Coordinates('2','L','P'), Coordinates('4','M','H'), Coordinates('M','N',NO_VALUE),
Coordinates('N','O',NO_VALUE), Coordinates('O','P',NO_VALUE), Coordinates('2','P','L'), Coordinates('4','M','Q'), Coordinates('M','Q',NO_VALUE),
Coordinates('N','Q',NO_VALUE), Coordinates('N','R',NO_VALUE), Coordinates('O','R',NO_VALUE), Coordinates('O','S',NO_VALUE), Coordinates('P','S',NO_VALUE),
Coordinates('2','P','S'), Coordinates('4','Q','M'), Coordinates('Q','R',NO_VALUE), Coordinates('R','S',NO_VALUE), Coordinates('2','S','P'),
Coordinates('4','Q','3'), Coordinates('3','Q',NO_VALUE), Coordinates('3','R','Q'), Coordinates('3','R','S'), Coordinates('3','S','R'), Coordinates('3','S','2')
	};*/

	Coordinates allVertex[VERTEX_AMMOUNT] = { Coordinates('0','A', NO_VALUE), Coordinates('0','B',NO_VALUE), Coordinates('0','1','C'), 
	Coordinates('0','5','A'), Coordinates('0','A','B'), Coordinates('0','B','C'), Coordinates('1','C',NO_VALUE), Coordinates('5','A','D'), Coordinates('A','B','E'), Coordinates('B','C','F'), Coordinates('1','C','G'), Coordinates('5','D',NO_VALUE), Coordinates('A','D','E'),
	Coordinates('B','E','F'), Coordinates('C','F','G'), Coordinates('1','G',NO_VALUE), Coordinates('5','D','H'), Coordinates('D','E','I'),
	Coordinates('E','F','J'),
	Coordinates('F','G','K'), Coordinates('1','G','L'), Coordinates('5','H',NO_VALUE), Coordinates('D','H','I'), Coordinates('E','I','J'),
	Coordinates('F','J','K'),
	Coordinates('G','K','L'), Coordinates('1','2','L'), Coordinates('4','5','H'), Coordinates('H','I','M'), Coordinates('I','J','N'),
	Coordinates('J','K','O'),
	Coordinates('K','L','P'), Coordinates('2','L',NO_VALUE), Coordinates('4','H','M'), Coordinates('I','M','N'), Coordinates('J','N','O'),
	Coordinates('K','O','P'), Coordinates('2','L','P'), Coordinates('4','M',NO_VALUE), Coordinates('N','M','Q'), Coordinates('N','O','R'),
	Coordinates('O','P','S'),Coordinates('2','P',NO_VALUE), Coordinates('4','M','Q'), Coordinates('N','Q','R'), Coordinates('O','R', 'S'),
	Coordinates('2','P','S'), Coordinates('4','Q',NO_VALUE), Coordinates('3','Q','R'), Coordinates('3','R','S'), Coordinates('2','3','S'),
	Coordinates('3','4','Q'),Coordinates('3','R',NO_VALUE), Coordinates('3','S',NO_VALUE) };
};
