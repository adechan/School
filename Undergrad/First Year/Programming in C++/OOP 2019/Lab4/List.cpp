#include "List.h"
#include <iostream>

List::List()
	: root(nullptr)
	, end(nullptr)
{
}

bool List::Add(int value)
{
	if (this->root == nullptr)
	{
		this->root = new Node(value);
		this->end = this->root;
		return true;
	}
	
	this->end->next = new Node(value);
	this->end = this->end->next;
}

bool List::Del(int value)
{
	Node* previousNode = this->root;
	Node* current = nullptr;

	current = this->root;
	if (this->root->value == value)
	{
		this->root = this->root->next;
		delete current;
		return true;
	}

	current = current->next;
	while (current != nullptr)
	{
		if (current->value == value)
		{
			std::cerr << "node found\n";
			std::cerr << "previous == " << previousNode->value << '\n';
			std::cerr << "current == " << current->value << '\n';
			previousNode->next = current->next;
			return true;
		}
		else
		{
			previousNode = current;
			current = current->next;
		}
	}	

	return false;
}


int List::Count(int value)
{
	int count = 0;
	Node* current = nullptr;

	current = this->root;
	while (current != nullptr)
	{
		if (current->value == value)
		{
			count++;
			current = current->next;
		}
		else
			current = current->next;
	}

	return count;
}

bool List::Exists(int value)
{
	int count = 0;
	Node* current = nullptr;

	current = this->root;
	while (current != nullptr)
	{
		if (current->value == value)
		{
			count++;
			current = current->next;
		}
		else
		{
			current = current->next;
		}
	}

	if (count != 0)
		return true;
	return false;
}


int* List::GetSortedArray()
{
	int count = 0;
	Node* current = nullptr;

	current = this->root;
	while (current != nullptr)
	{
		current = current->next;
		count++;
	}

	int i = 0;
	int* array = new int[count];

	current = this->root;
	while (current != nullptr)
	{
		array[i] = current->value;
		current = current->next;
		i++;
	}

	bubbleSort(array, count);
	return array;
}

int List::GetCount()
{
	int count = 0;
	Node* current = nullptr;

	current = this->root;
	while (current != nullptr)
	{
		current = current->next;
		count++;
	}

	return count;
}

void List::printList()
{
	Node* current = nullptr;
	current = this->root;

	while (current != nullptr)
	{
		std::cout << current->value << std::endl;
		current = current->next;
	}
}