#pragma once
#include "Container.h"

struct Node
{
	Node(int value)
	{
		this->value = value;
		this->next = nullptr;
	}

	int value;
	Node* next;
};

class List : public Container
{
protected:
	Node* root;
	Node* currentNode;

public:

	List();

	bool Add(int value);

	bool Del(int value);

	int  Count(int value);

	bool Exists(int value);

	int* GetSortedArray();

	int  GetCount();
};