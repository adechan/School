#include "Dreptunghi.h"
#include <iostream>

Dreptunghi::Dreptunghi()
{
	x = 0;
	y = 0;
	lungime = 0;
	latime = 0;
}

void Dreptunghi::Paint() const
{
	std::cout << "dreptunghi(" << x << "," << y << "," << lungime << "," << latime << ")" << std::endl;
}

void Dreptunghi::set(int X, int Y, int Lungime, int Latime)
{
	x = X;
	y = Y;
	lungime = Lungime;
	latime = Latime;
}

Dreptunghi::Dreptunghi(int X, int Y, int Lungime, int Latime)
{
	x = X;
	y = Y;
	lungime = Lungime;
	latime = Latime;
}
