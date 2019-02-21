#pragma once#
#include <string>

class Person
{
private:

public:
	std::string name;
	std::string phoneNumber;
	std::string email;
	bool hasParkingPass;
	Person();
	Person(std::string Name, std::string PhoneNumber, std::string Email);
	void PurchaseParkingPass();
	
	virtual ~Person() = 0;
};