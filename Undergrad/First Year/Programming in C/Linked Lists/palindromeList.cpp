//Check if a list is palindrome

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

typedef struct nod
{
	int elt;
	nod* succ;
} nod;

// Make a list;
void creeaza(nod *& prim)
{
	nod *ultim;
	nod *p, *q;
	int i, n, x;
	prim = nullptr;
	std::cout << "Dati numarul de elemente ";
	std::cin >> n;
	std::cout << "Primul element = ";
	std::cin >> x;
	
	prim = new nod;
	prim->elt = x;
	ultim = prim;

	for (i = 2; i <= n; i++)
	{
		std::cout << "Elementul al " << i << " - lea ";
		std::cin >> x;
		p = new nod;
		p->elt = x;
		p->succ = nullptr;
		ultim->succ = p;
		ultim = p;
	}
}

// Display a list;
void afisare(nod *&prim)
{
	nod *p;
	p = prim;
	while (p != nullptr)
	{
		std::cout << p->elt << " ";
		p = p->succ;
	}
	std::cout << std::endl;
}


// Reverse the second list;
nod *reverse(nod *prim)
{
	nod *p, *q;
	if (prim == nullptr) return prim;
	p = prim;
	q = p->succ;
	if (q == nullptr) return p;
	q = reverse(q);
	p->succ->succ = p;
	p->succ = nullptr;
	return q;
}

// Check if the list is palindrome
void verificaPalindrom(nod *start)
{
	nod *p, *q, *first_start, *second_start;
	p = start;
	q = start;
	if (p->succ == nullptr) // If the list has only one element;
	{
		std::cout << "It is palindrom";
		return;
	}
	while (1)
	{
		p = p->succ->succ;
		if (p == nullptr)
		{
			second_start = q->succ;
			break;
		}
		if (p->succ == nullptr)
		{
			second_start = q->succ->succ;
			break;
		}
		q = q->succ;
	}
	q->succ = nullptr;

		// Reverse the second list;
	second_start = reverse(second_start);
	first_start = start;
	while (first_start != nullptr && second_start != nullptr)
	{
		if (first_start->elt == second_start->elt)
		{
			first_start = first_start->succ;
			second_start = second_start->succ;
		}
		else
		{
			std::cout << "It is not palindrome";
			return;
		}
	}
	std::cout << "It is palindrome";
}

int main()
{
	nod * lista;
	creeaza(lista);
	afisare(lista);
	verificaPalindrom(lista);
	return 0;
}
