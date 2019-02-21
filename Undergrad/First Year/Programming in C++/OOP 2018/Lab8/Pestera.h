#pragma once
#include "SpatiuInchis.h"
#include <string>
#include <vector>

class Pestera : public SpatiuInchis
{
private:

public:
	std::vector <SpatiuInchis*> space;
	std::string miros;
	bool lumina;
	std::string nume;
	Pestera();
	Pestera(std::string elt1, bool elt2, std::string elt3);
	void AddSpatiu(SpatiuInchis* spatiu) override;
	int Count(std::vector <SpatiuInchis*> space) const;

	void PrintInfo() const override;

};