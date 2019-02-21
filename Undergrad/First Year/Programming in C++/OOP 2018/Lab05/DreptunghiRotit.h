#pragma once
#include "Dreptunghi.h"

class DreptunghiRotit : public Dreptunghi
{
private:

public:
	int unghi;
	DreptunghiRotit();
	DreptunghiRotit(int X, int Y, int Lungime, int Latime, int Unghi);
	void set(int X, int Y, int Lungime, int Latime, int Unghi);
	void Paint() const override;
};