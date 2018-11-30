#include "AbstractBuilding.h"

AbstractBuilding::AbstractBuilding(Coordinates coordinates) {
	getTokenCoordinates()->setX(coordinates.getX());
	getTokenCoordinates()->setY(coordinates.getY());
	getTokenCoordinates()->setZ(coordinates.getZ());
}

AbstractBuilding::AbstractBuilding() {
}

AbstractBuilding::~AbstractBuilding() {
}

AbstractBuilding& AbstractBuilding :: operator= (AbstractBuilding abstractBuilding)
{
	getTokenCoordinates()->setX(abstractBuilding.getTokenCoordinates()->getX());
	getTokenCoordinates()->setY(abstractBuilding.getTokenCoordinates()->getY());
	getTokenCoordinates()->setZ(abstractBuilding.getTokenCoordinates()->getZ());
	setAbstractToken(abstractBuilding.getAbstractToken());
	return *this;
}