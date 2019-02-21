#pragma once
#include "tree.h"

struct nodeStack
{
	int maxSize;	// dimensiunea maxima care poate fi folosita;
	int used;		// cate elemente au fost folosite;
	node** data;	// datele stivei;
};

node* topStack(nodeStack& s);

bool isStackEmpty(nodeStack& s);

bool isStackFull(nodeStack& s);

void pushStack(nodeStack& s, node* newNode);

void popStack(nodeStack& s);

void createEmptyStack(nodeStack& s, int capacity);

void freeStack(nodeStack& s);
