#pragma once
#include <vector>
#include "Item.h"

class ShoppingList
{
private:

public:
	std::vector <Item*> lista;
	ShoppingList();
	void addItem(Item* item);
	void printList();
};