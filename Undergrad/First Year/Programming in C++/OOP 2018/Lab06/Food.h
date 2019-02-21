#pragma once
#include "Item.h"

class Food : public Item
{
private:

public:
	float quantity;

	Food();
	Food(float Quantity);

	void setQuantity(float Quantity);

	std::string getInfo() const override;

};