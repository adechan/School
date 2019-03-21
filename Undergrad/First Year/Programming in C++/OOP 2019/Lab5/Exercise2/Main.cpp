#include <iostream>
#include <cassert>
#include "List.h"
#include "Object.h"

int main()
{
	List<int> lista;
	
	lista.Add(7);
	lista.Add(2);
	lista.Add(3);
	
	std::cout << "Print list: " << std::endl;
	for (int i = 0; i < lista.Count; i++)
		std::cout << lista.Elemente[i] << std::endl;
	std::cout << std::endl;

	lista.Sort();
	std::cout << "Sort list: " << std::endl;
	lista.printList();

	assert(lista.Elemente[2] == lista[2]);

	Object obiect(2);
	Object obiect1(5);
	Object obiect2(1);
	List<Object> listaObiecte;

	listaObiecte.Add(obiect);
	listaObiecte.Add(obiect1);
	listaObiecte.Add(obiect2);

	std::cout << "Print list: " << std::endl;
	for (int i = 0; i < listaObiecte.Count; i++)
		std::cout << listaObiecte.Elemente[i].x << std::endl;
	std::cout << std::endl;

	listaObiecte.Sort();
	std::cout << "Sort list: " << std::endl;
	for (int i = 0; i < listaObiecte.Count; i++)
		std::cout << listaObiecte.Elemente[i].x << std::endl;
	std::cout << std::endl;

	assert(listaObiecte.Elemente[2] == listaObiecte[2]);

	std::cin.get();
	return 0;
}