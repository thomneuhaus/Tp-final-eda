#include "Coordinates.h"

 Coordinates::Coordinates(int x, int y, int z) {
	 this->x = x;
	 this->y = y;
	 this->z = z;
}

 Coordinates::Coordinates(Coordinates& coordinates) {
	 this->x = coordinates.getX();
	 this->y = coordinates.getY();
	 this->z = coordinates.getZ();
 }

int Coordinates::getX() {
	return this->x;
}

int Coordinates::getY() {
	return this->y;
}

int Coordinates::getZ() {
	return this->z;
}

int Coordinates:: setX(int x) {
	this->x = x;
}

int Coordinates:: setY(int y) {
	this->y = y;
}

int Coordinates:: setZ(int z) {
	this->z = z;
}

bool Coordinates:: operator== (Coordinates Coordinates) 
{
	if (this->x == Coordinates.getX())
	{
		if (this->y == Coordinates.getY())
		{
			if (this->z == Coordinates.getZ())
			{
				return true;
			}
		}
	}
	return false;
}
void Coordinates :: operator= (Coordinates coordinates) 
{
	this->setX(coordinates.getX());
	this->setY(coordinates.getY());
	this->setZ(coordinates.getZ());
}