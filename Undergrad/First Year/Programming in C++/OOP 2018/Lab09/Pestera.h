#pragma once
#include "SpatiuInchis.h"
#include <string>

class Pestera : public SpatiuInchis
{
private:

public:
	std::string miros;
	bool lumina;
	std::string nume;
	Pestera();
	Pestera(std::string Miros, bool Lumina, std::string Nume);
	void AddSpatiu(SpatiuInchis* spatiu) override;
	void PrintInfo() const override;
};