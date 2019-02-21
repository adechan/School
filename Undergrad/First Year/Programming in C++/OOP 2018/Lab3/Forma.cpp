#include "Forma.h"
#include <iostream>

Dreptunghi::Dreptunghi(int lungime, int latime)
	: Latime(latime), Lungime(lungime)
{}

double Dreptunghi::ComputeArea()
{
	return this->Lungime * this->Latime;
}

const char *Dreptunghi::GetName()
{
	return "Dreptunghi";
}

Cerc::Cerc(int raza)
	: Raza(raza)
{}

double Cerc::ComputeArea()
{
	return;
}

const char *Cerc::GetName()
{

}

Triunghi::Triunghi(int X1, Y1, X2, Y2, X3, Y3)
	: X1(x1), Y2(y1), X2(x2), Y2(y2), X3(x3), Y3(y3)
{}

