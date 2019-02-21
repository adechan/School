#pragma once
#include "Person.h"
#include <string>

class Student : public Person
{
private:
	int numberSeminars;

public:
	int studentNumber;
	int averageMark;

	Student();
	Student(
		std::string Name, std::string PhoneNumber, std::string EmailAdress, 
		int StudentNumber, int AverageMark);

	bool isEligibleToEnroll();
	int getSeminarsTaken() const;

	void attendSeminar();
};