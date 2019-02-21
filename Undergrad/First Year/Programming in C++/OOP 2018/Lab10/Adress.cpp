#include "Adress.h"

Adress::Adress()
{

}

Adress::Adress(std::string Street,
	std::string City,
	std::string State,
	std::string PostalCode,
	std::string Country)
{
	street = Street;
	city = City;
	state = State;
	postalCode = PostalCode;
	country = Country;
}

bool Adress::validate()
{

}

void Adress::outputAsLabel()
{

}
