#pragma once
#include "SUV.h"

class RangeRover : public SUV
{
private:

public:
	int consum;
	RangeRover();
	void setConsum(int Consum);
	std::string getName() const override;
	int getConsum() const override;
};