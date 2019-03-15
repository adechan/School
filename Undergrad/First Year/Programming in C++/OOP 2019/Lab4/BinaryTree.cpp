#include "BinaryTree.h"
#include <iostream>
#include <stack>

BinaryTree::BinaryTree()
	: root(nullptr)
{
}


void BinaryTree::InsertNode(int value, NodeTree* leaf)
{
	leaf = new NodeTree(0);

	if (value < leaf->value)
	{
		if (leaf->left != nullptr)
		{
			InsertNode(value, leaf->left);
		}

		else
		{
			leaf->left = new NodeTree();
			leaf->left->value = value;

			// left child of the child node : null
			leaf->left->left = nullptr;

			// right child of the child node : null
			leaf->left->right = nullptr;
		}
	}
	else if (value >= leaf->value)
	{
		if (leaf->right != nullptr)
			InsertNode(value, leaf->right);
		else
		{
			leaf->right = new NodeTree();
			leaf->right->value = value;

			// left child of the child node : null
			leaf->right->left = nullptr;

			// right child of the child node : null
			leaf->right->right = nullptr;
		}
	}
}

bool BinaryTree::Add(int value)
{
	if (this->root == nullptr)
	{
		InsertNode(value, this->root);
		return true;
	}
	else
	{
		this->root = new NodeTree();
		root->value = value;
		root->left = nullptr;
		root->right = nullptr;
	}
}

bool BinaryTree::Del(int value)
{
	return true;
}

int  BinaryTree::Count(int value)
{
	return value;
}

bool BinaryTree::Exists(int value)
{
	return true;
}

int* BinaryTree::GetSortedArray()
{
	int* array = new int[25];
	return array;
}

int  BinaryTree::GetCount()
{
	int count = 0;
	return count;
}

void BinaryTree::printTree()
{
	std::stack<NodeTree *> s;
	NodeTree* current = this->root;

	while (current != nullptr || s.empty() == false)
	{
		while (current != nullptr)
		{
			s.push(current);
			current = current->left;
		}

		current = s.top();
		s.pop();

		std::cout << current->value;

		current = current->right;
	}
	
}