#include "Camera.h"
#include <iostream>

Camera::Camera()
{
	miros = '0';
	lumina = false;
	nume = '0';
}

Camera::Camera(std::string Miros, bool Lumina, std::string Nume)
{
	miros = Miros;
	lumina = Lumina; 
	nume = Nume;
}


void Camera::AddSpatiu(SpatiuInchis* spatiu)
{
	space.push_back(spatiu);	
}

// the number of times you called AddSpatiu
// is the number of items in your vector
int Camera::Count(std::vector <SpatiuInchis*> space) const
{
	return space.size(); // number of elements in space
}


void Camera::PrintInfo() const
{
	std::cout << std::boolalpha;
	
	std::cout << nume << " are " << this->Camera::Count(space) << " camere " << "miros: " << miros <<
		", " << lumina << std::endl;
}
