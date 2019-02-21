#pragma once

struct stack
{
	int maxSize;	// dimensiunea maxima care poate fi folosita;
	int used;		// cate elemente au fost folosite;
	char *data;		// datele stivei;
};

char topStack(stack& s);

bool isStackEmpty(stack& s);

bool isStackFull(stack& s);

void pushStack(stack& s, char newElement);

void popStack(stack& s);

void createEmptyStack(stack& s, int capacity);

void freeStack(stack& s);

void printStack(stack&s);