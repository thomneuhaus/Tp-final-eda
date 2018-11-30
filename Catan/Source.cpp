#include "Catan.h"
#include <cstring>
#include <cstdlib>
using namespace std;

int main(void) {
	Player player1("Carola");
	Player player2("Agustin");
	int dice1;
	int dice2;
	do {
		dice1 = player1.throwDice();
		dice2 = player2.throwDice();
	} while (dice1 == dice2);
	if (dice2 > dice1) {
		Player aux;
		aux = player2;
		player2 = player1;
		player1 = aux;
	}
	Catan catan(&player1, &player2);
	catan.randomize();
	Coordinates coordinates;
	do {Coordinates selectCoordinates(void);
		coordinates = catan.getPlayer1()->selectCoordinates(Coordinates(0,0,0));
	} while (catan.getRules().canBuildTown(catan.getPlayer1(), catan.getPlayer2(), coordinates, true));
	catan.buildTown(coordinates, catan.getPlayer1());
	getchar();
}
