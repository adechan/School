#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <cstring>

// aloca 16 octeti pentru sir-ul 
MyString::MyString()
{
	AllocatedSize = 16;
	sir = new char[AllocatedSize];
	Size = 0;
}

// aloca spatiu suficient pentru a copia si continutul lui text in sir
MyString::MyString(const char * text)
{
	AllocatedSize = std::strlen(text) + 1;
	sir = new char[AllocatedSize];
	Size = AllocatedSize - 1;

	Set(text);
}
// dealoca stringul
MyString::~MyString()
{
	delete[] sir;
}

unsigned int MyString::GetSize()
{
	return Size;
}

// copie in sir pe text. Daca e nevoie, redimensioneaza pe sir
void MyString::Set(const char *text)
{
	int length = std::strlen(text);

	if (length > AllocatedSize)
	{
		delete[] sir;
		sir = new char[length + 1];
	}

	Size = length; 
	AllocatedSize = Size + 1;

	std::strcpy(sir, text);

}

// similar ca la functia Set de mai sus
void MyString::Set(MyString &m)
{
	Set(m.sir);
}

// adauga la sfarsitul sirului curent pe text. Daca e nevoie redimensioneaza pe sir
void MyString::Add(const char *text)
{
	int length = std::strlen(text);

	if (Size + length > AllocatedSize)
	{
		char* savedSir = sir;
		sir = new char[Size + length + 1];
		std::strcpy(sir, savedSir);

		delete[] savedSir;
	}

	Size = Size + length;
	AllocatedSize = AllocatedSize + length + 1;

	std::strcat(sir, text);
}

// similar ca Add de mai sus
void MyString::Add(MyString &m)
{
	Add(m.sir);
}

// returneaza textul
const char* MyString::GetText()
{
	return sir;
}

// returneaza un obiect nou MyString in care copie din obiectul curent sub-sirul care incepe de la pozitia start si are lunginea size.
// daca pozitia start e in afara sirului meu, sau dimensiunea ceruta (size) e prea mare, functia returneaza NULL
MyString* MyString::SubString(unsigned int start, unsigned int size)
{
	if (start + size > Size || start > Size - 1)
		return nullptr;

	MyString* result = new MyString;

	if (size > result->AllocatedSize)
	{
		delete[] result->sir;
		result->sir = new char[size + 1];
	}

	std::strncpy(result->sir, &sir[start], size);

	result->AllocatedSize = size + 1;
	result->Size = result->AllocatedSize - 1;

	return result;
}

// sterge caracterele din sir de la pozitia start, de dimensiunea size. Returneaza true daca parametri sunt corecti.
// daca pozitia start e in afara sirului meu, sau dimensiunea ceruta (size) e prea mare, functia returneaza false 
bool MyString::Delete(unsigned int start, unsigned int size)
{
	if (start + size > Size || start > Size - 1)
		return false;

	sir[start - 1] = '\0';

	MyString s1(sir);
	MyString s2(&sir[start + size]);

	Set(s1);

	Add(s2);

	return true;
}

// compara sirul curent cu un alt text. Returneaza -1 daca sirul e mai mic decat text, 0 daca sunt egale si 1 altfel
int MyString::Compare(const char * text)
{
	return std::strcmp(sir, text);
}

// similar cu functia Compare de mai sus
int MyString::Compare(MyString &m)
{
	return Compare(m.sir);
}

// returneaza caracterrul de pe pozitia index. Daca pozitia e in afara sirului returneaza 0
char MyString::GetChar(unsigned int index)
{
	if (index > AllocatedSize)
		return 0;

	return sir[index];
}

// insereaza textul text la pozitia index in sir. Daca index e in afara index-ului returneaza false; 
// face si redimensionare daca e cazul
bool MyString::Insert(unsigned int index, const char* text)
{
	if (index > AllocatedSize)
		return false;

	// memoreaza textul vechi pana la index + 1
	MyString* s1 = SubString(0, index + 1);

	// memoreaza textul vechi de la index + 1
	MyString* s2 = SubString(index + 1, Size - s1->GetSize());

	Set(*s1);
	Add(text);
	Set(*s2);

	delete[] s1;
	delete[] s2;

	return true;
}

// similar cu functia Insert de mai sus.
bool MyString::Insert(unsigned int index, MyString &m)
{
	return Insert(index, m.sir);
}

// returneaza prima pozitie pe care a gasit sub-sirul text in 'sir'. Daca nu il gaseste returneaza -1
int MyString::Find(const char * text)
{
	char* result = std::strstr(sir, text);

	if (result == nullptr)
		return -1;
	else
		return result - sir;
}

// returneaza ultima pozitie pe care a gasit sub-sirul text in 'sir'. Daca nu il gaseste returneaza -1
int MyString::FindLast(const char * text)
{
	char* result = std::strstr(sir, text);
	
	if (result == nullptr)
		return -1;

	while (std::strstr(result + 1, text) != nullptr)
		result = std::strstr(result + 1, text);

	return result - sir;
}