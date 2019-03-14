#pragma once
#include "Container.h"

class BinaryTree : public Container
{
	bool Add(int value);

	bool Del(int value);

	int  Count(int value);

	bool Exists(int value);

	int* GetSortedArray();

	int  GetCount();
};