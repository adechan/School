// After each even element inserts the double of its factorial.

#include "stdafx.h"
#include <iostream>
 
typedef struct nod
{
    int elt;
    nod* succ;
} nod;
 
 
//  Crearea unei liste
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
 
 
// Afisarea unei liste
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
 
 
 
// functie pentru factorialul unui numar
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else return n*factorial(n - 1);
 
}
 
 
// functie insereaza dupa un element par dublul factorialului sau
void evenThenFactorial(nod *& prim)
{
    nod* p, *q, *ultim;
    p = new nod;
    p = prim;
    int inter = 0;
 
    while (p->succ != NULL)
        if ((p->elt % 2) != 0)
        {
            p = p->succ;
        }
 
        else
        {
            q = new nod;
 
            q->elt = 2 * factorial(p->elt);
            q->succ = p->succ;
            p->succ = q;
            p = p->succ->succ;
        }
 
    ultim = NULL;
    q = prim;
    while (q != NULL)
    {
        std::cout << q->elt;
        std::cout << ", ";
        q = q->succ;
    }
}
 
 
int main()
{
    nod * lista;
    creeaza(lista);
    afisare(lista);
    evenThenFactorial(lista);
 
    return 0;
}
