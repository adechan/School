#include "RangeRover.h"

RangeRover::RangeRover()
{
	consum = 0;
}

void RangeRover::setConsum(int Consum)
{
	consum = Consum;
}

std::string RangeRover::getName() const
{
	std::string name = "Range Rover";
	return name;
}

int RangeRover::getConsum() const
{
	return consum;
}
