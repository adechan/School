#include "tree.h"		// Librarie personala pentru arbori;
#include "parse.h"		// Librarie persoanala pentru a converti un string in simbol
#include "nodeStack.h"	// Librarie personala pentru nodul unei stive;

// Creeaza un nod gol;
node* createEmptyNode()
{
	node* empty = new node;
	empty->left = nullptr;
	empty->right = nullptr;
	return empty;
}

// Creeaza un nou nod cu valoarea simbol;
node* createNode(char simbol)
{
	node* empty = new node;
	empty->simbol = simbol;
	empty->left = nullptr;
	empty->right = nullptr;
	return empty;
}

// Sterge data din arbore;
void freeTree(node* radacina)
{
	if (radacina->left != nullptr)
		freeTree(radacina->left);

	if (radacina->right != nullptr)
		freeTree(radacina->right);

	if (radacina)
		delete radacina;
}

// Functie care returneaza maximul a doua numere;
int max(int a, int b)
{
	if (a > b) return a;
	else return b;
}

// Functie care returneaza inaltimea unui arbore;
int inaltimeArbore(node* radacina)
{
	// Daca nodul curent este gol, atunci inaltimea este 0;
	if (radacina == nullptr) return 0;

	// Inaltimea arborelui este 1 + maximul dintre inaltimile subarborilor;
	return 1 + max(inaltimeArbore(radacina->left), inaltimeArbore(radacina->right));
}

// Converteste expresia postfixata intr-un arbore;
node* convertPostfixToTree(queue& postfix)
{
	nodeStack nodes;
	createEmptyStack(nodes, postfix.maxSize);

	// Cat timp coada postfix nu este goala;
	while (!isQueueEmpty(postfix))
	{
		char simbol = frontQueue(postfix);			// simbol devine primul element din coada postfix;
		node* current = createNode(simbol);			// Se creeaza un nou nod current cu valoarea simbol;
		
		// Daca simbol nu este un operator;
		if (!isOperator(simbol))
		// Atunci;
			pushStack(nodes, current);				// Se insereaza in nodes nodul curremt;
		// Altfel;
		else
		{
			// Daca operatorul este unar;
			if (aritateOperator(simbol) == 1)
			{
				// Adaugam doar un copil la dreapta;
				node* right = topStack(nodes);		// nodul right ia valoarea ultimului element inserat in nodes;
				popStack(nodes);					// Si se scoada ultimul nod inserat;
				current->right = right;			
			}
			// Daca operatorul este binar;
			else if (aritateOperator(simbol) == 2)
			{
				// Adaugam un copil la stanga si unul la dreapta;
				node* right = topStack(nodes);
				popStack(nodes);

				node* left = topStack(nodes);
				popStack(nodes);

				current->left = left;
				current->right = right;
			}

			// Inseram expresia current in stiva;
			pushStack(nodes, current);
		}

		popQueue(postfix);
	}

	node* current = topStack(nodes);
	freeStack(nodes);
	return current;
}