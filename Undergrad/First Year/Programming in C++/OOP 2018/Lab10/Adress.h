#pragma once
#include <vector>
#include <string>
#include "Person.h"

class Adress
{
private:

public:
	std::string street;
	std::string city;
	std::string state;
	std::string postalCode;
	std::string country;

	std::vector <Person*> persoana;

	Adress();
	Adress(std::string Street,
		std::string City,
		std::string State,
		std::string PostalCode,
		std::string Country);

	bool validate();
	void outputAsLabel();
};