#include "Camera.h"
#include "Pestera.h"

#include <iostream>
#include <string>

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
	pestera.push_back(dynamic_cast<Pestera*>(spatiu));
}

void Camera::PrintInfo() const
{
	std::cout << nume << " are " << this->Count() << " camere, miros: " << miros << ", " <<
		(lumina? "luminos" : "intunecat") << std::endl;

	for (const auto* s : pestera)
		s->PrintInfo();

}