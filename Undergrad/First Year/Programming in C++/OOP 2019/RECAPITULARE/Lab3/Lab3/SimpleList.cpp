#include "SimpleList.h"

SimpleList::SimpleList()
{
	root = nullptr;
	end = nullptr;
}

// Add (adauga o valoare noua de tipul int in container). 
// Metoda returneaza true daca a reusit, false altfel.
bool SimpleList::Add(int value)
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

bool SimpleList::Del(int value)
{
	Node* previousNode = this->root;
	Node* current = nullptr;

	current = this->root;
	if (this->root->value == value)
	{
		this->root = this->root->next;
		delete[] current;
		return true;
	}

	current = current->next;
	while (current != nullptr)
	{
		if (current->value == value)
		{
			previousNode->next = current->next;
			return true;
		}

		else
		{
			previousNode->next = current;
			current = current->next;
		}
	}
	return false;
}

//Count - numara de cate ori o anumita valoare este prezenta in Container. 
// Daca o valoare nu este prezenta va returna 0.
int  SimpleList::Count(int value)
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

// Exists - returneaza true daca o valoare exista in container macar o data.
bool SimpleList::Exists(int value)
{
	int count = 0;
	Node* current = nullptr;

	current = this->root;
	while (current->next != nullptr)
	{
		if (current->value == value)
		{
			count++;
			current = current->next;
		}
		else
			current = current->next;
	}

	if (count != 0)
		return true;
	return false;
}

// GetSortedArray() - aloca si returneaza un vector de elemente,
// in care sunt copiate si sortate valorile introdu-se in container
int* SimpleList::GetSortedArray()
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

int  SimpleList::GetCount()
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

void SimpleList::printList()
{
	Node* current = nullptr;
	current = this->root;

	while (current != nullptr)
	{
		std::cout << current->value << std::endl;
		current = current->next;
	}
}