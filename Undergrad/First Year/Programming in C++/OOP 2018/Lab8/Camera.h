#pragma once
#include "SpatiuInchis.h"
#include <string>
#include <vector>

class Camera : public SpatiuInchis
{
private:

public:
	std::vector <SpatiuInchis*> space;
	std::string miros;
	bool lumina;
	std::string nume;
	Camera();
	Camera(std::string Miros, bool Lumina, std::string Nume);

	void AddSpatiu(SpatiuInchis* spatiu) override;
	int Count(std::vector <SpatiuInchis*> space) const;

	void PrintInfo() const override;
};