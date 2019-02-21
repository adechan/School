#include "Student.h"

Student::Student()
{

}

Student::Student(std::string Name, std::string PhoneNumber, std::string EmailAdress,
	int StudentNumber, int AverageMark)
{
	name = Name;
	phoneNumber = PhoneNumber;
	email = EmailAdress;
	studentNumber = StudentNumber;
	averageMark = AverageMark;
}

bool Student::isEligibleToEnroll()
{
	return (averageMark >= 5);
}

int Student::getSeminarsTaken() const
{
	return numberSeminars;
}

void Student::attendSeminar()
{
	numberSeminars++;
}
