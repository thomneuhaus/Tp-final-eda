#include "Dice.h"



Dice::Dice()
{
	srand(time(NULL));
}


Dice::~Dice()
{
}

char Dice::rollDice(void)
{
	return (rand()%6)+1;
}
