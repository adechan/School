#pragma once
#include <iostream>
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

inline void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

inline void bubbleSort(int arr[], int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
		}
	}
}


class SimpleList : Container {

protected: 
	Node* root;
	Node* end;

public:

	SimpleList();

	bool Add(int value);

	bool Del(int value);

	int  Count(int value);

	bool Exists(int value);

	int* GetSortedArray();

	int  GetCount();

	void printList();
};