#pragma once
class Coordinates
{
public:
	Coordinates();
	Coordinates(int, int, int);
	Coordinates(const Coordinates&);
	// ~Coordinates(); No se bien que onda esto (que le pondria)
	int getX(); //FUNCIONA
	int getY(); //FUNCIONA
	int getZ(); //FUNCIONA
	void setX(int ); //FUNCIONA
	void setY(int ); //FUNCIONA
	void setZ(int ); //FUNCIONA
	bool operator == (Coordinates);
	Coordinates& operator = (Coordinates);
private:
	unsigned int x;
	unsigned int y;
	unsigned int z;
};