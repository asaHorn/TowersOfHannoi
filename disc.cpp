#include "disc.h"

Disc::Disc()
{
}

Disc::Disc(int s)
{
	size = s;
}

Disc::~Disc()
{
}

int Disc::getSize()
{
	return size;
}

bool Disc::setSize(int s)
{
	size = s;
	return true;
}

std::string Disc::toString()
{
	return std::to_string(size);
	//return 
}

