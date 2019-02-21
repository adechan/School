#include "parse.h"		// Librarie persoanala pentru a converti un string in simbol
#include "queue.h"		// Librarie persoanala pentru coada;
#include "stack.h"		// Librarie persoanala pentru stiva;
#include <string.h>		// Librarie pentru string;

// define creeaza un sinonim pentru un anumit simbol;
#define SIN_SYMBOL 20
#define COS_SYMBOL 21
#define TG_SYMBOL 22
#define CTG_SYMBOL 23
#define LOG_SYMBOL 24
#define SQRT_SYMBOL 25
#define ROUND_SYMBOL 26
#define MOD_SYMBOL 27
#define AND_SYMBOL 28
#define OR_SYMBOL 29

#define INVALID_FUNCTION -1

// Verifica prioritatea operatorului;
int priorit(char op)
{
	switch (op)
	{
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
		case '^': return 3;
		case '%': return 3;
		case '(': return 4;
		case ')': return 4;
		case SIN_SYMBOL: return 3;
		case COS_SYMBOL: return 3;
		case TG_SYMBOL: return 3;
		case CTG_SYMBOL: return 3;
		case LOG_SYMBOL: return 3;
		case SQRT_SYMBOL: return 3;
		case ROUND_SYMBOL: return 3;
		case MOD_SYMBOL: return 3;
		case AND_SYMBOL: return 3;
		case OR_SYMBOL: return 3;
	}

	return 0;
}

// Verifica aritatea operatorului;
// adica cate argumente poate lua acel operator;
unsigned int aritateOperator(char op)
{
	switch (op)
	{
		case '+': return 2;
		case '-': return 2;
		case '*': return 2;
		case '/': return 2;
		case '^': return 2;
		case '%': return 2;
		case SIN_SYMBOL: return 1;
		case COS_SYMBOL: return 1;
		case TG_SYMBOL: return 1;
		case CTG_SYMBOL: return 1;
		case LOG_SYMBOL: return 1;
		case SQRT_SYMBOL: return 1;
		case ROUND_SYMBOL: return 1;
		case MOD_SYMBOL: return 2;
		case AND_SYMBOL: return 2;
		case OR_SYMBOL: return 2;
	}

	return 0;
}

// Verifica daca un termen este operator;
bool isOperator(char oper)
{
	return
		(oper == '+') ||
		(oper == '-') ||
		(oper == '*') ||
		(oper == '/') ||
		(oper == '^') ||
		(oper == '%') ||
		(oper == SIN_SYMBOL) ||
		(oper == COS_SYMBOL) ||
		(oper == TG_SYMBOL) ||
		(oper == CTG_SYMBOL) ||
		(oper == LOG_SYMBOL) ||
		(oper == SQRT_SYMBOL) ||
		(oper == ROUND_SYMBOL) ||
		(oper == MOD_SYMBOL) ||
		(oper == AND_SYMBOL) ||
		(oper == OR_SYMBOL);
		
}

// Verifica daca un termen este operand;
bool isOperand(char operand)
{
	return
		(operand < 58 && operand > 47) ||		// cifrele de la '0' la '9'
		(operand < 91 && operand > 64) ||		// literele de la 'A' la 'Z'
		(operand < 123 && operand > 96);		// literele de la 'a' la 'z'
}

// Converteste o expresie infixata intr-o expresie postfixata;
// Foloseste doua cozi (infix, postfix) si o stiva S;
void convInfix2Postfix(queue& infix, queue& postfix)
{
	stack S;
	// Creeaza o stiva goala cu o capacitate de 100 elemente;
	createEmptyStack(S, 100);

	// Cat timp coada infix nu este goala;
	while (!isQueueEmpty(infix))
	{
		char x = frontQueue(infix);		// x devine primul element din coada infix;
		popQueue(infix);				// Se sterge primul element din coada infix;

		// Daca x este operand, atunci
		if (isOperand(x))
			pushQueue(postfix, x);		// Se insereaza x la sfarsitul coadei postfix;

		// Altfel;
		else
		{
			// Daca x este ')' 
			if (x == ')')
			{
				// Cat timp ultimul element inserat in stiva nu este '(';
				while (topStack(S) != '(')
				{
					pushQueue(postfix, topStack(S));		// Se insereaza in coada postfix, ultimul element inserat in stiva;
					popStack(S);							// Si se scoate ultimul element inserat in stiva;
				}

				// Se scoate ultimul element inserat in stiva;
				popStack(S);
			}

			// Altfel;
			else
			{
				// Cat timp stiva S nu este goala && 
				// Ultimul element inserat in stiva nu este '(' &&
				// Prioritatea ultimului element din stiva este mai mare decat prioritatea primului element din coada infix;
				while (!isStackEmpty(S) && (topStack(S) != '(') && (priorit(topStack(S)) >= priorit(x)))
				{
					pushQueue(postfix, topStack(S));		// Se insereaza in coada postfix ultimul element inserat in stiva;
					popStack(S);							// Si se scoate ultimul element inserat in stiva;
				}

				// Se insereaza in stiva primul element din coada infix;
				pushStack(S, x);
			}
		}
	}

	// Cat timp stiva S nu este goala;
	while (!isStackEmpty(S))
	{
		pushQueue(postfix, topStack(S));	// Se insereaza in coada postfix, ultimul element inserat in coada;
		popStack(S);						// Si se scoate ultimul element inserat in stiva;
	}
	// Sterge memoria folosita de stiva pentru ca nu mai avem nevoie de ea;
	freeStack(S);
}

// Lista de operatori suportati:
// pointer catre un vector static alocat (cu 10 elemente);
char* operatorList[] = { "sin", "cos", "tg", "ctg", "log", "sqrt", "round", "mod", "and", "or"};

// Numar de operatori suportati; 
// sizeof(OperatorList) = numar elemente * sizeof(char*) 
unsigned int numSupportedOperators = 10;

// Returneaza indexul operatorului din operatorList daca acesta exista acolo
// si invalid_function (-1) daca acesta nu exista;
int getOperatorIndex(char* string)
{
	for (int i = 0; i < numSupportedOperators; i++)
	{
		// Daca string a fost gasit in operatorList[i] atunci se poate potrivi 
		// deci comparam string cu numarul de litere; 
		// iar daca e 0 (adevarat pentru strncmp) atunci returneaza indexul operatorului din operatorList;
		if (strncmp(operatorList[i], string, strlen(operatorList[i])) == 0)
			return i;
	}

	// Acest string nu este un operator suportat;
	// adica nu se afla in lista noastra;
	return INVALID_FUNCTION;
}

// Ia indexul din operatorList si il converteste intr-un simbol;
char getOperatorSymbol(int index)
{
	switch (index)
	{
		case 0: return SIN_SYMBOL;				// operatorList[0] = sin; --> 20
		case 1: return COS_SYMBOL;				// operatorList[1] = cos; --> 21
		case 2: return TG_SYMBOL;				// operatorList[2] = tg;  --> 22
		case 3: return CTG_SYMBOL;				// operatorList[3] = ctg; --> 23
		case 4: return LOG_SYMBOL;				// operatorList[4] = log; --> 24
		case 5: return SQRT_SYMBOL;				// operatorList[5] = sqrt;--> 25
		case 6: return ROUND_SYMBOL;			// operatorList[6] = round;-> 26
		case 7: return MOD_SYMBOL;				// operatorList[7] = mod; --> 27
		case 8: return AND_SYMBOL;				// operatorList[8] = and; --> 28
		case 9: return OR_SYMBOL;				// operatorList[9] = or;  --> 29
	}

	return 0;
}

// Converteste reprezentarea noastra char a unui operator inapoi la forma initiala;
// pentru a o putea desena in interiorul nodului;
void symbolToText(char simbol, char* outputText)
{
	switch (simbol)
	{
		case SIN_SYMBOL:
			strcpy(outputText, "sin");
			break;

		case COS_SYMBOL:
			strcpy(outputText, "cos");
			break;

		case TG_SYMBOL:
			strcpy(outputText, "tg");
			break;

		case CTG_SYMBOL:
			strcpy(outputText, "ctg");
			break;

		case LOG_SYMBOL:
			strcpy(outputText, "log");
			break;

		case SQRT_SYMBOL:
			strcpy(outputText, "sqrt");
			break;

		case ROUND_SYMBOL:
			strcpy(outputText, "round");
			break;

		case MOD_SYMBOL:
			strcpy(outputText, "mod");
			break;

		case AND_SYMBOL:
			strcpy(outputText, "and");
			break;

		case OR_SYMBOL:
			strcpy(outputText, "or");
			break;

		default:
			// Daca caracterul este doar o litera, atunci pune acea litera in outputText;
			outputText[0] = simbol;

			// Pentru ca un sir sa se termine, acesta trebuie sa ajunga la \0; 
			outputText[1] = 0;
			break;
	}
}

// Converteste o expresie de mai multe simboluri intr-un simbol;
void convertOperatorsToSymbols(char* expresie)
{
	// Copia convertita a expresiei string;
	char converted[256];
	unsigned int lungime = strlen(expresie);

	unsigned int currentIndex = 0;

	// Construim un nou string dupa urmatoarele reguli:
	// " " -> null
	// "sin", "cos", "tg", "ctg", "log" -> char
	// operatori (+, -, etc) + operand -> la fel

	for (unsigned int i = 0; i < lungime; i++)
	{
		// Sare peste toate " ";
		if (expresie[i] == ' ') continue;

		// Gaseste operatorul ce trebuie convertita (sin, cos, tg, ctg, log);
		// iar atunci cand il gaseste, functia getOperatorIndex returneaza indexul acestuia;
		int operatorIndex = getOperatorIndex(expresie + i);
		
		// Daca e orice index, dar nu -1, atunci avem un operator ce trebiue convertit;
		if (operatorIndex != INVALID_FUNCTION)
		{
			// Daca gasim un operator in expresie, il inlocuim cu un numar;
			// Construim un nou string cu aceiasi operatori
			// care sa converteasca operatorul in numarul corespunzator;
			converted[currentIndex++] = getOperatorSymbol(operatorIndex);	
			i += strlen(operatorList[operatorIndex]) - 1;

		}
		else
			// Altfel, acesta este un posibil valid input, deci pastreaza-l 
			converted[currentIndex++] = expresie[i];
	}

	converted[currentIndex++] = 0;
	// Copiaza stringul convertit in expresia veche;
	strcpy(expresie, converted);
}
