#pragma once
#include "Masina.h"

class MasinaOras : public Masina
{
private:

public:
	MasinaOras();
	std::string getName() const override;
	virtual int getCapacitate() const = 0;
	virtual std::string getCuloare() const = 0;

};