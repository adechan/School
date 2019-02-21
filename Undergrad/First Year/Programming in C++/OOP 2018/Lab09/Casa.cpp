#include "Casa.h"
#include "Pestera.h"
#include <iostream>

Casa::Casa()
{

}

Casa::Casa(std::string Miros, bool Lumina, std::string Nume)
{
	miros = Miros;
	lumina = Lumina;
	nume = Nume;
}


void Casa::AddSpatiu(SpatiuInchis* spatiu)
{
	pestera.push_back(spatiu);
}

void Casa::PrintInfo() const
{
	std::cout << nume << " are " << this->Count() << " camere, miros: " << miros << ", " <<
		(lumina ? "luminos" : "intunecat") << std::endl;

	for (const auto* s : pestera)
		s->PrintInfo();
}
