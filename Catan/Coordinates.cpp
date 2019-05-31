#include "Coordinates.h"

Coordinates::Coordinates() {
	x = EMPTY;
	y = EMPTY;
	z = EMPTY;
}

 Coordinates::Coordinates(int x, int y, int z) {
	 this->x = x;
	 this->y = y;
	 this->z = z;
}

 Coordinates::Coordinates(const Coordinates &coordinates) {
	 this->x = coordinates.x;
	 this->y = coordinates.y;
	 this->z = coordinates.z;
 }

int Coordinates::getX() {
	return x;
}

int Coordinates::getY() {
	return y;
}

int Coordinates::getZ() {
	return z;
}

void Coordinates:: setX(int x) {
	this->x = x;
}

void Coordinates:: setY(int y) {
	this->y = y;
}

void Coordinates:: setZ(int z) {
	this->z = z;
}

bool Coordinates:: operator== (Coordinates coordinates) //No importa el orden de las coordenadas, compara todo con todo
{
	if (this->x == coordinates.getX())
	{
		if ((this->y == coordinates.getY() && this->z == coordinates.getZ())||(this->z == coordinates.getY() && this->y == coordinates.getZ()))
		{
				return true;
		}
	}
	if (this->y == coordinates.getX())
	{
		if ((this->x == coordinates.getY() && this->z == coordinates.getZ()) || (this->z == coordinates.getY() && this->x == coordinates.getZ()))
		{
			return true;
		}
	}
	if (this->z == coordinates.getX())
	{
		if ((this->y == coordinates.getY() && this->x == coordinates.getZ()) || (this->x == coordinates.getY() && this->y == coordinates.getZ()))
		{
			return true;
		}
	}
	return false;
}
Coordinates& Coordinates :: operator= (Coordinates coordinates) 
{
	this->setX(coordinates.getX());
	this->setY(coordinates.getY());
	this->setZ(coordinates.getZ());
	return *this;
}