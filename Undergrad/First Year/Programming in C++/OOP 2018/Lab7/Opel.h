#pragma once
#include "MasinaOras.h"

class Opel : public MasinaOras
{
private:

public:
	int capacitate;
	std::string culoare;
	int anFabricatie;
	Opel();
	void setCapacitate(int Capacitate);
	void setCuloare(std::string Culoare);
	void setAnFabricatie(int AnFabricatie);
	int getAnFabricatie();
	std::string getName() const override;
	int getCapacitate() const override;
	std::string getCuloare() const override;
};