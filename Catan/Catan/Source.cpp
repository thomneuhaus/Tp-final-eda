#include "Catan.h"
#include <cstring>
#include <cstdlib>
using namespace std;

int main(void) {
	Player player1("Carola");
	Player player2("Agustin");
	Catan catan(&player1, &player2);
	catan.randomize();
	int dice1 = catan.getPlayer1()->throwDice();
	int dice2 = catan.getPlayer1()->throwDice();
	printf("%d %d\n", dice1, dice2);
	catan.buildTown(Coordinates('A', 'D', 'E'), catan.getPlayer1());
	catan.buildCity(Coordinates('A', 'D', 'E'), catan.getPlayer1());
	catan.findNumber(dice1 + dice2, catan.getPlayer1());
	//printf("%c\n", catan.getRobber()->getTokenCoordinates()->getX());
	for (int i = 0; i < ISLANDS_AMMOUNT; i++) {
		if ((catan.getMap()->getIslands()[i].getPosition() == 'A') || (catan.getMap()->getIslands()[i].getPosition() == 'D') || (catan.getMap()->getIslands()[i].getPosition() == 'E'))
			printf("%c: %d\n", catan.getMap()->getIslands()[i].getPosition(), catan.getMap()->getIslands()[i].getNumber());
	}
	printf("woods:%d\nclay:%d\nsheep:%d\nwheat:%d\nstone:%d\n", catan.getPlayer1()->getWood(), catan.getPlayer1()->getClay(), catan.getPlayer1()->getSheep(), catan.getPlayer1()->getWheat(), catan.getPlayer1()->getStone());
	getchar();
}
