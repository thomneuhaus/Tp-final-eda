#include "Island.h"



Island::Island()
{
}


Island::~Island()
{
}

void
Island::setType(islandType tipo)
{
	type = tipo;
}

islandType Island::getType(void)
{
	return type;
}
