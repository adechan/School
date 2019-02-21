#pragma once
//#include "Pestera.h"
#include <vector>

//class Pestera;

class SpatiuInchis
{
public:
	std::vector <SpatiuInchis*> pestera;
	SpatiuInchis();
	int Count() const;
	virtual void AddSpatiu(SpatiuInchis* spatiu) = 0;
	virtual void PrintInfo() const = 0;
};
