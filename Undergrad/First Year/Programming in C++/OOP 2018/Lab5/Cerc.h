#pragma once
#include "Forma.h"

class Cerc : public Forma
{
private:

public:
	int x;
	int y;
	int raza;
	Cerc();
	Cerc(int X, int Y, int Raza);
	void Paint() const override;
	void set(int X, int Y, int Raza);
};