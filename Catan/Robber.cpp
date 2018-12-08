#include "Robber.h"
#include <cstdlib>
#include <ctime>

Robber::Robber() {
	setAbstractToken(ROBBER_L);
}

Robber::Robber(Coordinates dessertCoord)
{
	setAbstractToken(ROBBER_L);
	setTokenCoordinates(dessertCoord);
}


Robber::~Robber()
{
}
