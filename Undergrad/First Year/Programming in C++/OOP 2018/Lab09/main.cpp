#include <iostream>
#include "Camera.h"
#include "Pestera.h"
#include "SpatiuInchis.h"
#include "Casa.h"

class Composition
{
	std::vector<Camera*> spatula;

public:
	Composition(std::string name, bool luminos, std::string stuff)
	{
		spatula.push_back(new Camera(name, luminos, stuff));
	}


	~Composition()
	{
		for (auto* s : spatula)
			delete s;
	}
};

int main()
{
	Composition c("paie", true, "Culoar frontal");

	std::cout << std::boolalpha;
	SpatiuInchis* c1 = new Camera("paie", true, "Culoar frontal");
	SpatiuInchis* c2 = new Camera("urs", false, "Camera ursului");
	SpatiuInchis* c3 = new Camera("rugina", false, "Depozit arme");
	SpatiuInchis* c4 = new Pestera("neutru", false, "Pestera muierilor");

	c4->AddSpatiu(c1);
	c4->AddSpatiu(c2);
	c4->AddSpatiu(c3);

	SpatiuInchis* my_home = new Casa("var", true, "Casa lui Manole");
	
	my_home->AddSpatiu(new Camera("mucegai", false, "Baie"));
	my_home->AddSpatiu(new Camera("parfum", true, "Sufragerie"));
	
	c4->PrintInfo();
	my_home->PrintInfo();

	std::cin.get();
	return 0;
}