#include <iostream>
#include "Forme.h"
#include "Cerc.h"
#include "Dreptunghi.h"
#include "DreptunghiRotit.h"
#include "Forma.h"
#include "Oval.h"

int main()
{
	Forme f;
	Cerc c;
	c.set(10, 10, 100);
	Oval o;
	o.set(20, 20, 50, 100);
	DreptunghiRotit p;
	p.set(5, 5, 2, 10, 30);
	f.Add(&c);
	f.Add(&o);
	f.Add(&p);
	f.Paint();

	std::cin.get();
	return 0;
}