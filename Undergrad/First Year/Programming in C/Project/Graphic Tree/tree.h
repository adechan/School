#pragma once

#include "queue.h"

struct node
{
	char simbol;
	node* left;
	node* right;
};

void freeTree(node* root);

int inaltimeArbore(node* root);

node* createNode(char symbol);

node* createEmptyNode();

node* convertPostfixToTree(queue& postfix);
