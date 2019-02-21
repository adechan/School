#pragma once
#include "Person.h"
#include <string>

class Professor : public Person
{
private:
	int salary;
public:
	Professor();
	Professor(std::string Name, std::string PhoneNumber, std::string EmailAdress);
	int getSalary();

};