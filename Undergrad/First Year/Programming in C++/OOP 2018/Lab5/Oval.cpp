#include "Oval.h"
#include <iostream>

Oval::Oval()
{
	x = 0;
	y = 0;
	raza1 = 0;
	raza2 = 0;
}

Oval::Oval(int X, int Y, int Raza1, int Raza2)
{
	x = X;
	y = Y;
	raza1 = Raza1;
	raza2 = Raza2;
}


void Oval::Paint() const
{
	std::cout << "oval(" << x << "," << y << "," << raza1<< ","<< raza2 << ")" << std::endl;
}

void Oval::set(int X, int Y, int Raza1, int Raza2)
{
	x = X;
	y = Y;
	raza1 = Raza1;
	raza2 = Raza2;
}
