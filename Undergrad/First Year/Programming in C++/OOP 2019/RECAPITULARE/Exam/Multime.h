#pragma once

// using Comparator = int(int, int); AND IN FUNCTION Comparator compare

inline void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

inline int lessThan(int left, int right)
{
	return left < right;
}

inline int greaterThan(int left, int right)
{
	return left > right;
}

inline void bubbleSort(int arr[], int size, int(*compare)(int, int))
{
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (compare(arr[j], arr[j+1]) == 0)
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

class Multime
{
	int Numere[100];
	int Count;

public:
	// constructor 0 elemente
	Multime();
	// se vor copia elementele din lista in vectorul Numere
	// daca size > 100 se vor copia primele 100
	Multime(int* lista, int size);
	// elementul cu valoare maxima
	int Max();
	// elementul cu valoare minima
	int Min();

	// sorteaza vectorul folosind o functie de comparatie
	void Sort(int(*compare) (int, int));
	// numarul de elemente
	int GetSize() const;

	bool contains(int value) const;

	// operator de indexare care sa returneze o referinta la un element in vector
	int& operator[] (int index);
	const int& operator[] (int index) const;

	// operator de cast la double care returneaza suma elementele din vector
	operator double();

	// functie friend pentru operatorul & care returneaza o multime cu
	// reuniunea a doua multimi
	friend Multime operator& (const Multime& m1, const Multime& m2);

	// o functie friend pentru operatorul | care returneaza o multime
	// cu intersectia a doua multimi
	friend Multime operator| (const Multime& m1, const Multime& m2);
};