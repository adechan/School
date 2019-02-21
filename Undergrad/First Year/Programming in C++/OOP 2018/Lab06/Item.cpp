#include "Item.h"
#include <iostream>

Item::Item()
{
	
}

Item::Item(std::string Name)
{
	name = Name;
}

void Item::setName(std::string Name)
{
	name = Name;
}

std::string Item::getName() const
{
	return name;
}
