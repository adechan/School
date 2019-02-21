#include "Person.h"

Person::Person()
{

}
Person::Person(std::string Name, std::string PhoneNumber, std::string Email)
{
	name = Name;
	phoneNumber = PhoneNumber;
	email = Email;
}


void Person::PurchaseParkingPass()
{
	hasParkingPass = true;
}
