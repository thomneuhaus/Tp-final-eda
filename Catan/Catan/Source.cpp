#include "Catan.h"
#include <cstring>
#include <cstdlib>
using namespace std;

int main(void) {
	Player player1("Carola");
	Player player2("Agustin");
	Catan catan(&player1, &player2);
	catan.randomize();
	catan.getPlayer1()->setWheat(4);
	catan.getPlayer1()->setStone(4);
	catan.getPlayer1()->setWood(4);
	catan.getPlayer1()->setSheep(4);
	catan.getPlayer1()->setClay(4);
	resources myResources[5] = {WOOD, WOOD,WOOD,SHEEP,END };
	catan.tradeBank( myResources, WHEAT, catan.getPlayer1());
	printf("WOOD:%d\nSHEEP:%d\nCLAY:%d\nWHEAT:%d\nSTONE:%d\n", catan.getPlayer1()->getWood(), catan.getPlayer1()->getSheep(), catan.getPlayer1()->getClay(), catan.getPlayer1()->getWheat(), catan.getPlayer1()->getStone());
	printf("%d\n", catan.getError());
	getchar();

}
