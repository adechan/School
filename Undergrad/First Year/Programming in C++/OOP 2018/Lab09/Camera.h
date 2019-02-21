#pragma once
#include "SpatiuInchis.h"

class Camera : public SpatiuInchis
{
private:

public:
	std::string miros;
	bool lumina;
	std::string nume;
	Camera();
	Camera(std::string Miros, bool Lumina, std::string Nume);
	void AddSpatiu(SpatiuInchis* spatiu) override;
	void PrintInfo() const override;
};