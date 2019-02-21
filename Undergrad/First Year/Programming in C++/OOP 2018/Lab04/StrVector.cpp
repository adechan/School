#include <iostream>
#include "StrVector.h"

StrVector::StrVector()
{
	sir = new char[50];
	AllocatedSize = 50;
	Size = 0;
}

StrVector::StrVector(const char * text)
{
	unsigned int length = std::strlen(text);
	AllocatedSize = length + 1;
	Size = length;

	if (length > AllocatedSize)
	{
		delete sir;
		sir = new char[length + 1];
	}

	std::strcpy(sir, text);
}

StrVector::~StrVector()
{
	delete[] sir;
}

unsigned int StrVector::GetIterator() const
{

}

unsigned int StrVector::GetCount() const
{

}

