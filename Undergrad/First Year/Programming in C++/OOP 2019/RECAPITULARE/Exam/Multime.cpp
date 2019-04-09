#include "Multime.h"
#include <iostream>

Multime::Multime()
{
	Count = 0;
}

// copie in Numere primele size elemente din lista
Multime::Multime(int* lista, int size)
{
	Count = 0;

	for (int i = 0; i < size; i++)
	{
		if (!this->contains(lista[i]))
			Numere[Count++] = lista[i];
	}

	if (size > 100)
	{
		for (int i = 0; i < 100; i++)
			Numere[i] = lista[i];

		Count = 100;
	}
}

int Multime::Max()
{
	int max = Numere[0];

	for (int i = 0; i < Count; i++)
	{
		if (Numere[i] > max)
			max = Numere[i];
	}
	return max;
}

int Multime::Min()
{
	int min = Numere[0];

	for (int i = 0; i < Count; i++)
	{
		if (Numere[i] < min)
			min = Numere[i];
	}
	return min;
}

void Multime::Sort(int(*compare) (int, int))
{
	bubbleSort(Numere, Count, compare);
}

int Multime::GetSize() const
{
	return Count;
}

bool Multime::contains(int value) const
{
	for (int i = 0; i < this->GetSize(); i++)
		if (Numere[i] == value)
			return true;

	return false;
}

int& Multime::operator[] (int index)
{
	return Numere[index];
}

const int& Multime::operator[] (int index) const
{
	return Numere[index];
}


Multime::operator double()
{
	double result = 0;
	
	for (int i = 0; i < this->GetSize(); i++)
	{
		result += this->Numere[i];
	}

	return result;
}

Multime operator& (const Multime& m1, const Multime& m2)
{
	Multime result = m1;

	for (int i = 0; i < m2.Count; i++)
	{
		if (!result.contains(m2[i]))
			result[result.Count++] = m2[i];
	}

	return result;
}

Multime operator| (const Multime& m1, const Multime& m2)
{
	Multime result;

	for (int i = 0; i < m1.Count; i++)
	{
		if (m2.contains(m1[i]))
			result.Numere[result.Count++] = m1.Numere[i];
	}

	return result;
}