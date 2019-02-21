#include "Pestera.h"
#include <iostream>

Pestera::Pestera()
{
	miros = '0';
	lumina = false;
	nume = '0';
}
Pestera::Pestera(std::string Miros, bool Lumina, std::string Nume)
{
	miros = Miros;
	lumina = Lumina;
	nume = Nume;
}


void Pestera::AddSpatiu(SpatiuInchis* spatiu)
{
	space.push_back(spatiu);
}

int Pestera::Count(std::vector <SpatiuInchis*> space) const
{
	return space.size();
}


void Pestera::PrintInfo() const
{
	std::cout << std::boolalpha;
	std::cout << nume << " are " << this->Pestera::Count(space) << " camere " << "miros: " << miros <<
		", " << lumina << std::endl;
}
