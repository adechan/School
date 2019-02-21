#include "stack.h"	// Librarie persoanala pentru stiva;
#include <iostream>

//First In - Last Out
// dinamic -> atunci cand marimea este cunoscuta la rulare;
// static -> atunci cand compilatorul o stie de dinainte;

// Creaaza o stiva goala;
void createEmptyStack(stack& s, int capacity)
{
	// Aloca memorie pentru o stiva goala;
	s.data = new char[capacity];	// pointer catre un vector dinamic alocat;
	s.maxSize = capacity;			// dimensiunea maxima pe care o poate atinge stiva
	s.used = 0;						// nu exista inca elemente folosite (s.used) in stiva
}

// Returneaza ultimul element care a fost inserat;
char topStack(stack& s)				
{
	return s.data[s.used - 1];		// Elementul[elemente folosite - 1]
									// deoarece stiva incepe de la 0;
}
 
// Functie care verifica daca o stiva este goala;
bool isStackEmpty(stack& s)
{
	return s.used == 0;				// Numarul elementelor folosite este 0;
}

// Functie care verifica daca o stiva este plina;
bool isStackFull(stack& s)
{
	return s.used == s.maxSize;		// Numarul elementelor folosite 
									// este egal cu dimensiunea maxima a stivei;
}

// Insereaza un element nou la sfarsitul/topul stivei;
void pushStack(stack& s, char newElement)
{
	// Stiva este plina, deci nu putem insera noi elemente;
	if (isStackFull(s)) return;			
	else
	{
		// Altfel;
		s.used = s.used + 1;				// numarul elementelor folosite creste cu o unitate; 
		s.data[s.used - 1] = newElement;	// elementul nou este pe pozitia [elemente folosite - 1];
	}
}

// Scoate ultimul element care a fost inserat;
void popStack(stack& s)
{
	// Stiva este goala, deci nu putem scoate niciun element;
	if (isStackEmpty(s)) return;
	else
		// Altfel; 
		s.used = s.used - 1;				// numarul elementelor folosite se micsoreaza cu o unitate; 
}

// Sterge memoria folosita de stiva;
// Foloseste cand nu mai ai nevoie de stiva;
void freeStack(stack& s)
{
	delete[] s.data;
}

// Functie care printeaza elementele stivei;
void printStack(stack& s)
{
	// Folosim un for cu un i mai mic decat numarul elementelor folosite in stivei;
	for (int i = 0; i < s.used; i++)
		std::cout << s.data[i] << " ";		// printeaza elementul de pe pozitia i; 
	std::cout << std::endl;
}
