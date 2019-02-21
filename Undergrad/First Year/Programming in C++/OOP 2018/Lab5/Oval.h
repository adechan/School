#pragma once
#include "Forma.h"

class Oval : public Forma
{
private:

public:
	int x;
	int y;
	int raza1;
	int raza2;
	Oval();
	Oval(int X, int Y, int Raza1, int Raza2);
	void Paint() const override;
	void set(int X, int Y, int Raza1, int Raza2);
};
