#include "Miscellaneous.h"
#include <iostream>

Miscellaneous::Miscellaneous()
{
	count = 0;
}

Miscellaneous::Miscellaneous(int Count)
{
	count = Count;
}

std::string Miscellaneous::getInfo() const
{
	std::string info = this->getName();
	info += " : ";
	// to_string converts "count" into a std::string
	info += std::to_string(count);
	info += " items\n";

	// std::cout << name << " : " << count << " items" << std::endl;

	return info;
}

void Miscellaneous::setCount(int Count)
{
	count = Count;
}

void Miscellaneous::setQuantity(int Count)
{
	count = Count;
}