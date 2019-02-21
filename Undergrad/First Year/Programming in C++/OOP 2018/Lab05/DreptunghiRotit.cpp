#include "DreptunghiRotit.h"
#include <iostream>

DreptunghiRotit::DreptunghiRotit()
{
	x = 0;
	y = 0;
	lungime = 0;
	latime = 0;
	unghi = 0;
}
DreptunghiRotit::DreptunghiRotit(int X, int Y, int Lungime, int Latime, int Unghi)
{
	x = X;
	y = Y;
	lungime = Lungime;
	latime = Latime;
	unghi = Unghi;
}

void DreptunghiRotit::set(int X, int Y, int Lungime, int Latime, int Unghi)
{
	x = X;
	y = Y;
	lungime = Lungime;
	latime = Latime;
	unghi = Unghi;
}

void DreptunghiRotit::Paint() const
{
	std::cout << "dreptunghi(" << x << "," << y << "," << lungime << "," << latime << ") rotit la " << unghi << " grade" << std::endl;
}