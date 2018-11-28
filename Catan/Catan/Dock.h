#pragma once
class Dock
{
public:
	Dock(int, char);
	Dock();
	~Dock();
	char getPosition(void);
	char getTradeType(void);
private:
	char position;
	char tradeType; // para diferenciar los puertos
	// void getDock(port *);

	
};

