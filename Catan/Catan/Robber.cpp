#include "Robber.h"
#include <cstdlib>
#include <ctime>

Robber::Robber() {
	setAbstractToken(ROBBER);
}

Robber::Robber(Coordinates dessertCoord)
{
	setAbstractToken(ROBBER);
	setTokenCoordinates(dessertCoord);
}


Robber::~Robber()
{
}
