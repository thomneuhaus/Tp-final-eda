#include "AbstractBuilding.h"

AbstractBuilding::AbstractBuilding(Coordinates coordinates) {
	getTokenCoordinates()->setX(coordinates.getX());
	getTokenCoordinates()->setY(coordinates.getY());
	getTokenCoordinates()->setZ(coordinates.getZ());
}

AbstractBuilding::AbstractBuilding() {
}