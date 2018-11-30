#pragma once
class Coordinates
{
public:
	Coordinates();
	Coordinates(int, int, int); //x y z
	Coordinates(const Coordinates&); //copiador
	//self explaining
	int getX();
	int getY(); 
	int getZ();
	void setX(int );
	void setY(int );
	void setZ(int );

	bool operator == (Coordinates); // sobrecarga operador == (compara todos con todos sin importar el orden)
	Coordinates& operator = (Coordinates);// copiador
private:
	unsigned int x;
	unsigned int y;
	unsigned int z;
};