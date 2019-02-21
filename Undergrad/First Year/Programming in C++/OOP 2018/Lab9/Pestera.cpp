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
	pestera.push_back(spatiu);
}

void Pestera::PrintInfo() const 
{
	std::cout << nume << " are " << this->Count() << " camere, miros: " << miros << ", " <<
		(lumina ? "luminos" : "intunecat") << std::endl;

	for (const auto* p : pestera)
		p->PrintInfo();
}
