#include "ShoppingList.h"
#include <iostream>

ShoppingList::ShoppingList()
{

}

void ShoppingList::addItem(Item* item)
{
	lista.push_back(item);
}

void ShoppingList::printList()
{
	for (auto it = lista.begin(); it != lista.end(); it++)
	{
		auto& list = *it;
		std::cout << list->getInfo();
	}
}
