#include "Food.h"
#include <iostream>

Food::Food()
{
	quantity = 0;
}

Food::Food(float Quantity)
{
	quantity = Quantity;
}

void Food::setQuantity(float Quantity)
{
	quantity = Quantity;
}

std::string Food::getInfo() const 
{
	std::string info = this->getName();
	info += " : ";
	info += std::to_string(quantity);
	info += "kg\n";

	// std::cout << name << " : " << quantity << " kg" << std::endl;
	return info;
}
