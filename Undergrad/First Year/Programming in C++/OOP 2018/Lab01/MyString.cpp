#include <iostream>
#include "MyString.h"
#include <cstring>
				 
MyString::MyString()
{
	AllocatedSize = 16;
	sir = new char[AllocatedSize];
	Size = 0;
} 

MyString::MyString(const char * text)
{
	AllocatedSize = std::strlen(text) + 1;
	sir = new char[AllocatedSize];
	Size = AllocatedSize - 1;

	this->Set(text); 
	// la fel ca anterior: std::strcpy(sir, text);
}

MyString::~MyString()
{
	delete[] sir;
}

unsigned int MyString::GetSize() const
{
	return this->Size;
}

void MyString::Set(const char *text)
{
	unsigned int length = std::strlen(text);

	if (length > AllocatedSize)
	{
		delete sir;
		sir = new char[length + 1];
	}

	Size = length;
	AllocatedSize = length + 1;

	std::strcpy(sir, text);
}

void MyString::Set(const MyString &other)
{
	this->Set(other.sir);

	// other has type MyString
	//std::strcpy(sir, other.sir);
}

void MyString::Add(const char *text)
{
	unsigned int textLength = std::strlen(text);

	// If we don't have enough space, we make enough room for old sir length + length of text
	if (Size + textLength > AllocatedSize)
	{
		// Save sir in a temporary
		const char * aux = sir;

		// Create new memory big enough for both strings
		sir = new char[Size + textLength + 1];

		// Copy the old string from aux into sir
		std::strcpy(sir, aux);

		// Delete the old memory
		delete[] aux;
	}

	Size += textLength;
	AllocatedSize += textLength + 1;

	std::strcat(sir, text);
}

void MyString::Add(MyString &other)
{
	this->Add(other.sir);
}

const char* MyString::GetText() const
{
	return sir;
}

MyString* MyString::SubString(unsigned int start, unsigned int size) const
{
	// starts at: sir[start], ends at: sir[start + size]
	// [start, start + size)

	if (start > this->Size - 1 || start + size > this->Size)
		return nullptr;

	MyString* result = new MyString;
	if (size > result->AllocatedSize)
	{
		// result is NOT sir
		delete[] result->sir;
		result->sir = new char[size + 1];
	}

	std::strncpy(result->sir, &sir[start], size);
	result->sir[size] = '\0';

	result->AllocatedSize = size + 1;
	result->Size = result->AllocatedSize - 1;

	return result;
}
// ade meow chan
// start= 2 size = 4
// delete "e m"
// sir = adeow chan

bool MyString::Delete(unsigned int start, unsigned int size)
{
	if (start > this->Size - 1 || start + size > this->Size - 1)
		return false;

	/*
	0: h
	1: e
	2: y <-- start, size = 3
	3: a
	4: b <-- 
	5: c
	6: 0
	*/

	// sir1 = 0 to start
	// sir2 = start+size to end

	// Example: "horse dank ade", Delete(6, 4)

	// Our sir before: "horse dank ade"
	// End our sir before the start of the delete
	sir[start - 1] = '\0';
	//                          V ends here, but we still have this memory after
	// Our sir before: "horse "\0"dank ade"

	// Copy the truncated sir into a new string
	MyString s1(sir);

	// Our sir before: "horse "\0"dank ade"
	// Copy the " ade" into the new string
	// Copy the tail of our sir into a new string
	MyString s2(&sir[start + size]);

	// Make our sir = "horse "
	// Copy out sir to be the truncated string
	this->Set(s1);

	// Put " ade" after our sir
	// Add the tail to our sir
	this->Add(s2);
	// Our sir after: "horse  ade"

	// C Version
	/*char * sir1 = new char[this->Size];
	std::strncpy(sir1, sir, start - 1);
	sir1[start - 1] = '\0';

	char * sir2 = new char[this->Size];
	std::strncpy(sir2, &sir[start + size], this->Size - (start + size));
	sir2[this->Size - (start + size)] = '\0';

	std::strcpy(sir, sir1);
	std::strcat(sir, sir2);
	delete[] sir1;
	delete[] sir2;*/

	return true;
}

int MyString::Compare(const char * text) const
{
	return std::strcmp(sir, text);
}

int MyString::Compare(MyString &other) const
{
	return this->Compare(other.GetText());
	//return std::strcmp(sir, other.sir);
}

char MyString::GetChar(unsigned int index) const
{
	return sir[index];
}

// sir = ade meow ham'\0'                        
// index = 3, text = chan
// sir1 = "ade "
// sir2 = "meow ham"
// cat( sir1, text)
// cat( sir1, sir2)

bool MyString::Insert(unsigned int index, const char* text)
{
	if (index > this->Size)
		return false;

	MyString* s1 = this->SubString(0, index + 1);
	if (s1 == nullptr)
		return false;

	/*char * sir1 = new char[this->Size + strlen(text) + 1];
	std::strncpy(sir1, sir, index + 1);
	sir1[index + 1] = '\0';*/


	MyString* s2 = this->SubString(index + 1, this->Size - s1->GetSize());
	if (s2 == nullptr)
		return false;

	/*char *sir2 = new char[this->Size + strlen(text) + 1];
	std::strncpy(sir2, &sir[index + 1], this->Size - strlen(sir1));
	sir2[this->Size - strlen(sir1)] = '\0';*/

	this->Set(*s1);
	this->Add(text);
	this->Add(*s2);

	delete s1;
	delete s2;

	/*delete[] sir;
	sir = new char[strlen(sir1) + strlen(sir2) + strlen(text) + 1];
	std::strcpy(sir, sir1);
	std::strcat(sir, text);
	std::strcat(sir, sir2);

	delete[] sir1;
	delete[] sir2;*/
	return true;
}

bool MyString::Insert(unsigned int index, MyString &other)
{
	return this->Insert(index, other.GetText());
}

int MyString::Find(const char * text)
{
	const char* result = std::strstr(sir, text);
	if (result == nullptr)
		return -1;

	// result = sir + index;

	else
		return result - sir;

	/*                V-----------------------------|
	string = "ade man ham dam"						|
	strstr(string, "ham") returns a pointer to here |
	*/
}

int MyString::FindLast(const char * text)
{
	const char* result = std::strstr(sir, text);
	if (result == nullptr)
		return -1;

	while (std::strstr(result + 1, text) != nullptr)
		result = std::strstr(result + 1, text);

	return result - sir;
		
	/*                V-----------------------------|
	string = "ade man ham dam ham ham ham"			|
	strstr(string, "ham") returns a pointer to here |
	*/
}