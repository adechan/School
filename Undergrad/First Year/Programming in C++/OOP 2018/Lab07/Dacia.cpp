#include "Dacia.h"

Dacia::Dacia()
{
	capacitate = 0;
	culoare = nullptr;
}

std::string Dacia::getName() const
{
	std::string masina = "Dacia";
	return masina;
}

void Dacia::setCapacitate(int Capacitate)
{
	capacitate = Capacitate;
}

void Dacia::setCuloare(std::string Culoare)
{
	culoare = Culoare;
}

int Dacia::getCapacitate() const
{
	return capacitate;
}

std::string Dacia::getCuloare() const
{
	std::string culour = culoare;
	return culour;
}
