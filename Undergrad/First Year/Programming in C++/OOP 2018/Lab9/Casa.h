#pragma once
#include "SpatiuInchis.h"
#include <string>
#include <vector>

class Casa : public SpatiuInchis
{
private:

public:
	std::string miros;
	bool lumina;
	std::string nume;
	Casa();
	Casa(std::string Miros, bool Lumina, std::string Nume);
	void AddSpatiu(SpatiuInchis* spatiu);
	void PrintInfo() const;

};