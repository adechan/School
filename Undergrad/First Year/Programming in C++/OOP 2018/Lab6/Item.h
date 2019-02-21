#pragma once
#include <string>

class Item
{
private:

public:
	std::string name;

	Item();
	Item(std::string Name);

	std::string getName() const;
	virtual std::string getInfo() const = 0;
	void setName(std::string Name);
};
