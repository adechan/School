#pragma once
#include "Item.h"

class Miscellaneous : public Item
{
private:

public:
	int count;

	Miscellaneous();
	Miscellaneous(int Count);

	std::string getInfo() const override;

	void setCount(int Count);
	void setQuantity(int Count);
};