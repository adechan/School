#include "Casa.h"
#include <iostream>

Casa::Casa()
{
	miros = '0';
	lumina = false;
	nume = '0';
}

Casa::Casa(std::string Miros, bool Lumina, std::string Nume)
{
	miros = Miros;
	lumina = Lumina;
	nume = Nume;
}


void Casa::AddSpatiu(SpatiuInchis* spatiu)
{
	space.push_back(spatiu);
}

int Casa::Count(std::vector <SpatiuInchis*> space) const
{
	return space.size();
}

void Casa::PrintInfo() const
{
	std::cout << std::boolalpha;
	for (const auto* camera : space)
		camera->PrintInfo();

	std::cout << nume << " are " << this->Casa::Count(space) << " camere " << "miros: " << miros <<
		", " << lumina << std::endl;
}
