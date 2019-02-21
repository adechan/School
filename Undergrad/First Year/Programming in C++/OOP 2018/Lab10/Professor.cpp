#include "Professor.h"

Professor::Professor()
{

}

Professor::Professor(std::string Name, std::string PhoneNumber, std::string EmailAdress)
{
	name = Name;
	phoneNumber = PhoneNumber;
	email = EmailAdress;
}

int Professor::getSalary()
{
	return salary;
}

