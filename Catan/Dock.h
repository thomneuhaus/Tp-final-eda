#pragma once
class Dock
{
public:
	Dock(char coordinate, char type); // constructor que recibe la posicion y el tipo de puerto
	Dock(); // no hace nada pero lo deje para evitar errores de constructores (visual)
	~Dock();
	char getPosition(void); // devuelve la posicion del dock
	char getTradeType(void); // devuelve el tipo de dock
private:
	char position;
	char tradeType; // para diferenciar los puertos
	// void getDock(port *);

	
};

