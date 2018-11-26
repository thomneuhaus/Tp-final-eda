#pragma once
class Coordinates
{
public:
	Coordinates(int, int, int);
	Coordinates(Coordinates&);
	// ~Coordinates(); No se bien que onda esto (que le pondria)
	int getX();
	int getY();
	int getZ();
	int setX(int );
	int setY(int );
	int setZ(int );
	bool operator== (Coordinates);
	void operator= (Coordinates);
private:
	unsigned int x;
	unsigned int y;
	unsigned int z;

};