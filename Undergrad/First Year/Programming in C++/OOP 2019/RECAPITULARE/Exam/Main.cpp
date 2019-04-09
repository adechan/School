#include <iostream>
#include "Multime.h"

int main()
{
	Multime multime = Multime();
	std::cout << "Size multime1: " << multime.GetSize() << std::endl;

	int* lista = new int[6];
	lista[0] = 1;
	lista[1] = 6;
	lista[2] = 3;
	lista[3] = 2;
	lista[4] = 1;
	lista[5] = 5;

	Multime multime2 = Multime(lista, 6);
	std::cout << "Size multime2: " << multime2.GetSize() << std::endl;

	std::cout << "Minim: " << multime2.Max() << " Maxim: " << multime2.Min() << "\n";

	for (int i = 0; i < multime2.GetSize(); i++)
		std::cout << multime2[i] << " ";
	std::cout << '\n';

	multime2.Sort(lessThan);

	for (int i = 0; i < multime2.GetSize(); i++)
		std::cout << multime2[i] << " ";
	std::cout << '\n';

	int* lista1 = new int[6];
	lista1[0] = 0;
	lista1[1] = 1;
	lista1[2] = 2;
	lista1[3] = 3;
	lista1[4] = 5;
	lista1[5] = 6;
	Multime m1 = Multime(lista1, 6);

	std::cout << "Sum values of m1: " << (double)m1 << " ";
	std::cout << '\n';

	int* lista2 = new int[5];
	lista2[0] = 0;
	lista2[1] = 1;
	lista2[2] = 2;
	lista2[3] = 4;
	lista2[4] = 5;
	Multime m2 = Multime(lista2, 5);

	std::cout << "Sum values of m2: " << m2.operator double() << " ";
	std::cout << '\n';

	Multime result = Multime();
	result = m1 & m2;

	std::cout << "Reuniune: ";
	for (int i = 0; i < result.GetSize(); i++)
		std::cout << result[i] << " ";
	std::cout << '\n';

	Multime result2 = Multime();
	result2 = m1 | m2;

	std::cout << "Intersectie: ";
	for (int i = 0; i < result2.GetSize(); i++)
		std::cout << result2[i] << " ";
	std::cout << '\n';

	std::cin.get();
	return 0;
}

