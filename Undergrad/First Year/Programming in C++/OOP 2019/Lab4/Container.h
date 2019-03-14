#pragma once
class Container {

public:

	// adauga o valoare noua de tipul int in container).
	// Metoda returneaza true daca a reusit, false altfel.
	virtual bool Add(int value) = 0;

	// sterge o valoare din container. Daca acea valoare exista si s-a reusit stergerea, 
	// returneaza true. In caz contrat va returna 0.
	virtual bool Del(int value) = 0;

	// numara de cate ori o anumita valoare este prezenta in Container. 
	// Daca o valoare nu este prezenta va returna 0.
	virtual int  Count(int value) = 0;

	// returneaza true daca o valoare exista in container macar o data.
	virtual bool Exists(int value) = 0;

	// aloca si returneaza un vector de elemente, 
	// in care sunt copiate si sortate valorile introduse in container
	virtual int* GetSortedArray() = 0;

	// returneaza numarul de elemente din container.
	virtual int  GetCount() = 0;

};