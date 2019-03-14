#include "List.h"

List::List()
	: root(nullptr)
	, currentNode(nullptr)
{
}

bool List::Add(int value)
{
	if (this->root == nullptr)
	{
		this->root = new Node(value);
		this->currentNode = this->root;
		return true;
	}

	this->currentNode->next = new Node(value);
	this->currentNode = this->currentNode->next;
}


/*
delete: 3
1 3 4 5 6 7 9 
*/
bool List::Del(int value)
{
	struct Node* previousNode;
	bool checkValue = false;

	if (this->root != nullptr)
	{
		while (checkValue != true)
		{
			this->currentNode = this->root;

			if (this->currentNode->value == value)
			{
				checkValue = true;
				previousNode->next = currentNode->next;

				return true;
			}
			else
			{
				this->currentNode = this->currentNode->next;
			}
		}
			
	}
	return false;
}


int  List::Count(int value)
{
	int count = 0;

	while (this->root != nullptr)
	{
		this->currentNode = this->root;
		if (this->currentNode->value == value)
		{
			count++;
			this->currentNode = this->currentNode->next;
		}
		else
		{
			this->currentNode = this->currentNode->next;
		}
	}

	return count;
}

bool List::Exists(int value)
{
	int count = 0;
	while (this->root != nullptr)
	{
		this->currentNode = this->root;
		if (this->currentNode->value == value)
		{
			count++;
			this->currentNode = this->currentNode->next;
		}
		else
		{
			this->currentNode = this->currentNode->next;
		}
	}

	if (count != 0)
		return true;
	return false;
}


int* List::GetSortedArray()
{

}