#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "MyString.h"
#include <cstring>

// contructor
MyString::MyString()
{
	AllocatedSize = 16;
	sir = new char[AllocatedSize];
	Size = 0;
}

// constructor
MyString::MyString(const char * text)
{
	AllocatedSize = std::strlen(text) + 1;
	sir = new char[AllocatedSize];
	Size = AllocatedSize - 1;

	// pune text in sir
	this->Set(text);
}

// destructor
MyString::~MyString()
{
	delete[] sir;
}

// dimensiunea sirului : getter
unsigned int MyString::GetSize() const
{
	return this->Size;
}

// copie text in sir 
void MyString::Set(const char *text)
{
	unsigned int length = std::strlen(text);

	// daca lungimea textului e mai mare decat dimensiunea alocata
	// stergem sirul si il cream mai mare 
	if (length > AllocatedSize)
	{
		delete sir;
		sir = new char[length + 1];
	}

	Size = length;
	AllocatedSize = length + 1;

	// copie 'text' in 'sir'
	std::strcpy(sir, text);
}

void MyString::Set(const MyString &other)
{
	this->Set(other.sir);
}

// adauga la sfarsitul sirului curent pe text : concatenare
void MyString::Add(const char *text)
{
	unsigned int textLength = std::strlen(text);
	
	// daca nu avem suficient spatiu cream un sir mai mare 
	// si punem vechiul sir in el
	if (Size + textLength > AllocatedSize)
	{
		// salvam sirul vechi 
		const char * aux = sir;

		// memorie suficient de mare astfel incat sa incapa sirul vechi + textul nou
		sir = new char[Size + textLength + 1];

		// copiem stringul vechi din aux in sir 
		std::strcpy(sir, aux);

		delete[] aux;
	}

	Size += textLength;
	AllocatedSize += textLength + 1;

	// concatenam text in sir 
	std::strcat(sir, text);
}

// concatenare2 
void MyString::Add(MyString &other)
{
	this->Add(other.sir);
}

const char* MyString::GetText() const
{
	return sir;
}

// returneaza un obiect nou MyString in care copie din obiectul curent sub-sirul care incepe de la pozitia start si are lunginea size.
MyString* MyString::SubString(unsigned int start, unsigned int size) const
{
	// starts at: sir[start], ends at: sir[start + size]
	// [start, start + size]

	if (start > this->Size - 1 || start + size > this->Size)
		return nullptr;

	MyString* result = new MyString;
	if (size > result->AllocatedSize)
	{
		// result is NOT sir
		delete[] result->sir;
		result->sir = new char[size + 1];
	}

	// char * strncpy(char * destination, const char * source, size_t num);
	std::strncpy(result->sir, &sir[start], size);
	result->sir[size] = '\0';

	result->AllocatedSize = size + 1;
	result->Size = result->AllocatedSize - 1;

	return result;
}

// sterge caracterele din sir de la pozitia start, de dimensiunea size
bool MyString::Delete(unsigned int start, unsigned int size)
{
	if (start > this->Size - 1 || start + size > this->Size - 1)
		return false;

	// terminam sirul inainte de substringul pe care vrem sa-l stergem 
	sir[start - 1] = '\0';

	// copiem sirul truncat intr-un string nou
	MyString s1(sir);

	// copiem sfarsitul sirului intr-un string nou 
	MyString s2(&sir[start + size]);

	// copie s1 in sir
	this->Set(s1);

	// concateneaza s2 in sir 
	this->Add(s2);
	
	return true;
}

// compara sirul curent cu un alt text
int MyString::Compare(const char * text) const
{
	return std::strcmp(sir, text);
}

// compara primul caracter din fiecare string
// si daca sunt egale continue pana la sfarsitul sirului
// sau pana cand intalneste o pereche diferita
int MyString::Compare(MyString &other) const
{
	return this->Compare(other.GetText());
}

// returneaza caracterrul de pe pozitia index
char MyString::GetChar(unsigned int index) const
{
	return sir[index];
}

// insereaza textul text la pozitia index in sir. 
// Daca index e in afara index-ului returneaza false; 
bool MyString::Insert(unsigned int index, const char* text)
{
	if (index > this->Size)
		return false;

	MyString* s1 = this->SubString(0, index + 1);
	if (s1 == nullptr)
		return false;

	MyString* s2 = this->SubString(index + 1, this->Size - s1->GetSize());
	if (s2 == nullptr)
		return false;

	this->Set(*s1);
	this->Add(text);
	this->Add(*s2);

	delete s1;
	delete s2;

	return true;
}

bool MyString::Insert(unsigned int index, MyString &other)
{
	return this->Insert(index, other.GetText());
}

// returneaza prima pozitie pe care a gasit sub-sirul text in 'sir'
int MyString::Find(const char * text)
{
	const char* result = std::strstr(sir, text);
	if (result == nullptr)
		return -1;

	// result = sir + index;

	else
		return result - sir;
}

// returneaza ultima pozitie pe care a gasit sub-sirul text in 'sir'.
int MyString::FindLast(const char * text)
{
	const char* result = std::strstr(sir, text);
	if (result == nullptr)
		return -1;

	while (std::strstr(result + 1, text) != nullptr)
		result = std::strstr(result + 1, text);

	return result - sir;

}