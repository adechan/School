#pragma once
#include "Container.h"

struct NodeTree
{
	NodeTree()
	{
		this->value = 0;
		this->right = nullptr;
		this->left = nullptr;
	}

	NodeTree(int value)
	{
		this->value = value;
		this->right = nullptr;
		this->left = nullptr;
	}

	int value;
	NodeTree* right;
	NodeTree* left;

};

class BinaryTree : public Container
{
protected:
	NodeTree* root;

public:
	
	BinaryTree();

	void InsertNode(int value, NodeTree* leaf);

	bool Add(int value);

	bool Del(int value);

	int  Count(int value);

	bool Exists(int value);

	int* GetSortedArray();

	int  GetCount();

	void printTree();
};