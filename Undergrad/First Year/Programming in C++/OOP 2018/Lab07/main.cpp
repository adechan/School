#include <iostream>
#include "Masina.h"
#include "MasinaOras.h"
#include "Opel.h"
#include "Dacia.h"
#include "RangeRover.h"

int main()
{
	RangeRover rang;
	rang.setConsum(200);
	std::cout << rang.getName() << "," << rang.getConsum() << std::endl;
	
	Opel o;
	o.setAnFabricatie(1998);
	o.setCapacitate(4);
	o.setCuloare("albastru");
	MasinaOras *m = &o;

	std::cout << m->getName() << ", " << m->getCapacitate() << ", " << m->getCuloare() << ", " <<
		o.getAnFabricatie() << std::endl;
	std::cout << o.getName() << ", " << o.getCapacitate() << ", " << o.getCuloare() << ", " <<
		o.getAnFabricatie() << std::endl;

	std::cin.get();
	return 1;
}