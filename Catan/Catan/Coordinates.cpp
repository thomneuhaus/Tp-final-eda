#include "Coordinates.h"

Coordinates::Coordinates() {
	x = 0;
	y = 0;
	z = 0;
}

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

bool Coordinates:: operator== (Coordinates coordinates) 
{
	if (this->x == coordinates.getX())
	{
		if ((this->y == coordinates.getY() && this->z == coordinates.getZ())||(this->z == coordinates.getY() && this->y == coordinates.getZ()))
		{
				return true;
		}
	}
	else if (this->y == coordinates.getX())
	{
		if ((this->x == coordinates.getY() && this->z == coordinates.getZ()) || (this->z == coordinates.getY() && this->x == coordinates.getZ()))
		{
			return true;
		}
	}
	else if (this->z == coordinates.getX())
	{
		if ((this->y == coordinates.getY() && this->x == coordinates.getZ()) || (this->x == coordinates.getY() && this->y == coordinates.getZ()))
		{
			return true;
		}
	}
	else
		return false;
}
void Coordinates :: operator= (Coordinates coordinates) 
{
	this->setX(coordinates.getX());
	this->setY(coordinates.getY());
	this->setZ(coordinates.getZ());
}