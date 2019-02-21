#include <iostream>
#include "Casa.h"
#include "Camera.h"
#include "Pestera.h"
#include "SpatiuInchis.h"

int main()
{
	SpatiuInchis* camera1 = new Camera("paie", true, "Culoar frontal");
	SpatiuInchis* camera2 = new Camera("urs", false, "Camera ursului");
	SpatiuInchis* camera3 = new Camera("rugina", false, "Depozit arme");
	SpatiuInchis* camera4 = new Pestera("neutru", false, "Pestera muierilor");

	camera4->AddSpatiu(camera1);
	camera4->AddSpatiu(camera2);
	camera4->AddSpatiu(camera3);

	camera4->PrintInfo();
	camera1->PrintInfo();
	camera2->PrintInfo();
	camera3->PrintInfo();

	SpatiuInchis* casa_mea = new Casa("var", true, "Casa lui Manole");
	
	casa_mea->AddSpatiu(new Camera("mucegai", false, "Baie"));
	casa_mea->AddSpatiu(new Camera("parfum", true, "Sufragerie"));

	casa_mea->PrintInfo();

	std::cin.get();
	return 0;
}