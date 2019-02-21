#pragma once
#include "MasinaOras.h"

class Dacia : public MasinaOras
{
private:

public:
	int capacitate;
	std::string culoare;
	Dacia();
	std::string getName() const override;
	int getCapacitate() const override;
	std::string getCuloare() const override;

	void setCapacitate(int Capacitate);
	void setCuloare(std::string Culoare);
};