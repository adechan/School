#pragma once
#include "SpatiuInchis.h"
#include <string>
#include <vector>

class Casa : public SpatiuInchis
{
private:
	std::vector <SpatiuInchis*> space;

public:
	std::string miros;
	bool lumina;
	std::string nume;

	Casa();
	Casa(std::string Miros, bool Lumina, std::string Nume);
	void AddSpatiu(SpatiuInchis*) override;
	int Count(std::vector <SpatiuInchis*> space) const;

	void PrintInfo() const override;
};