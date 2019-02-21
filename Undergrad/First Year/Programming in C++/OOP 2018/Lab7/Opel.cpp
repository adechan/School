#include "Opel.h"

Opel::Opel()
{
	capacitate = 0;
	culoare = '0';
	anFabricatie = 0;
}

void Opel::setCapacitate(int Capacitate)
{
	capacitate = Capacitate;
}

void Opel::setCuloare(std::string Culoare)
{
	culoare = Culoare;
}

void Opel::setAnFabricatie(int AnFabricatie)
{
	anFabricatie = AnFabricatie;
}

int Opel::getAnFabricatie()
{
	return anFabricatie;
}

std::string Opel::getName() const
{
	std::string masina = "Opel";
	return masina;
}

int Opel::getCapacitate() const 
{
	return capacitate;
}

std::string Opel::getCuloare() const
{
	std::string culour = culoare;
	return culour;
}