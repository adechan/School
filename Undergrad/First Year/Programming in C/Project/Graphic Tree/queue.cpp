#include "queue.h"	// Librarie personala pentru coada;
#include <iostream>

//First In - First Out
// dinamic -> atunci cand marimea este cunoscuta la rulare;
// static -> atunci cand compilatorul o stie de dinainte;

// Creaaza o coada goala;
void createEmptyQueue(queue& q, int capacity)
{
	// Aloca memorie pentru o coada goala;
	q.data = new char[capacity];	// pointer catre un vector dinamic alocat;
	q.maxSize = capacity;			// dimensiunea maxima pe care o poate atinge coada
	q.used = 0;						// nu exista inca elemente folosite (q.used) in coada
}

// Functie care verifica daca o coada este plina;
bool isQueueFull(queue& q)
{
	return q.used == q.maxSize;		// Numarul elementelor folosite 
									// este egal cu dimensiunea maxima a coadei;
}

// Functie care verifica daca o coada este goala;
bool isQueueEmpty(queue& q)
{
	return q.used == 0;				// Numarul elementelor folosite este 0;
}

// Returneaza ultimul element care a fost inserat;
// Element care va fi ultimul scos;
char backQueue(queue& q)
{
	return q.data[q.used - 1];		// Elementul[elemente folosite - 1]
									// deoarece coada incepe de la 0;
}

// Returneaza primul element care a fost inserat;
// Element care va fi primul scos;
char frontQueue(queue& q)
{
	return q.data[0];				// Elementul care se afla pozitia 0
									// deoarece coada incepe de la 0;
}

// Insereaza un element nou la sfarsitul coadei;
void pushQueue(queue& q, char newElement)
{
	// Coada este plina, deci nu putem insera noi elemente;
	if (isQueueFull(q)) return;
	else
	{	
		// Altfel;
		q.used = q.used + 1;				// numarul elementelor folosite creste cu o unitate; 
		q.data[q.used - 1] = newElement;	// elementul nou este pe pozitia [elemente folosite - 1];
	}
}

// Scoate primul element din coada;
void popQueue(queue& q)
{
	// Coada este goala, deci nu putem scoate niciun element;
	if (isQueueEmpty(q)) return;
	else
	{
		// Altfel;
		// Folosim un for pentru a shifta toate elementele la stanga cu o unitate
		// atata timp cat i este mai mic strict decat numarul elementelor folosite in coada;
		// incepe de la 1 pentru ca q.data[0 - 1] nu exista;
		for (int i = 1; i < q.used; i++)	
		{
			q.data[i - 1] = q.data[i];		// Elementul de pe pozitia [i-1] devine elementul de pe pozitia [i]

		}
		// Si apoi micsoram numarul elementelor folosite cu o unitate;
		q.used = q.used - 1;
	}
}

// Functie care printeaza elementele coadei;
void printQueue(queue& q)
{
	// Folosim un for cu un i mai mic decat numarul elementelor folosite in coada;
	for (int i = 0; i < q.used; i++)
		std::cout << q.data[i] << " ";		// printeaza elementul de pe pozitia i;
	std::cout << std::endl;
}

void clearQueue(queue& q)
{
	while (!isQueueEmpty(q))
		popQueue(q);
}

// Sterge memoria folosita de coada;
// Foloseste cand nu mai ai nevoie de coada;
void freeQueue(queue& q)
{
	delete[] q.data;
}

