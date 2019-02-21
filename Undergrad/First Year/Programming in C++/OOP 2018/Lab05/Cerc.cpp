#include "Cerc.h"
#include <iostream>

Cerc::Cerc()
{
	x = 0;
	y = 0;
	raza = 0;
}

Cerc::Cerc(int X, int Y, int Raza)
{
	x = X;
	y = Y;
	raza = Raza;
}

void Cerc::Paint() const
{
	std::cout << "cerc(" << x << "," << y << "," << raza << ")" << std::endl;
}

void Cerc::set(int X, int Y, int Raza)
{
	x = X;
	y = Y;
	raza = Raza;
}
