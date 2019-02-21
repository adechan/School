#pragma once
#include "Forma.h"

class Dreptunghi : public Forma
{
private:

public:
	int x;
	int y;
	int lungime;
	int latime;
	Dreptunghi();
	Dreptunghi(int X, int Y, int Lungime, int Latime);
	void Paint() const override;
	void set(int X, int Y, int Lungime, int Latime);
};