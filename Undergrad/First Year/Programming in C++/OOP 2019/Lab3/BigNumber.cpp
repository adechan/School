#include "BigNumber.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>

// Number contine "0", field - ul CharactersCount contine valoarea 1
BigNumber::BigNumber()
{
	bytes[0] = 0;
	usedBytesCount = 1;
}

// Copie in Number, valoarea lui value
BigNumber::BigNumber(int value)
{
	// sizeof = amount of memory allocated to that data type 
	// memcpy ( void * destination, const void * source, size_t num );
	memcpy(this->bytes, &value, sizeof(int));
	usedBytesCount = sizeof(int);
}

// Copie in Number, valuarea lui number
BigNumber::BigNumber(const char * number)
{
	memcpy(this->bytes, number, strlen(number));
	usedBytesCount = strlen(number);
}

// copy constructor : A copy constructor is a member function which
// initializes an object using another object of the same class
BigNumber::BigNumber(const BigNumber &number)
{
	this->Set(number.bytes);

	//memcpy(this->number, number.number, number.charactersCount);
	//this->charactersCount = number.charactersCount;
}

void BigNumber::Set(int value)
{
	memcpy(this->bytes, &value, sizeof(value));
	this->usedBytesCount = sizeof(value);
}

void BigNumber::Set(const char * number)
{
	memcpy(this->bytes, number, strlen(number));
	usedBytesCount = strlen(number);
}


// SUPRASCRIERE operatori



// FUNCTII PRIETENE

// A friend function of a class is defined outside that class' scope 
// but it has the right to access all private and protected members of the class. 
// Even though the prototypes for friend functions appear in the class definition, 
// friends are not member functions.

bool operator == (const BigNumber & n1, const BigNumber & n2)
{
	if (n1.usedBytesCount != n2.usedBytesCount)
		return false;

	for (int i = 0; i < n1.usedBytesCount; i++)
	{
		if (n1.bytes[i] != n2.bytes[i])
			return false;
	}
	return true;
}

bool operator != (const BigNumber & n1, const BigNumber & n2)
{
	if (n1.usedBytesCount == n2.usedBytesCount)
		return false;

	for (int i = 0; i < n1.usedBytesCount; i++)
	{
		if (n1.bytes[i] == n2.bytes[i])
			return false;
	}
	return true;
}

bool operator <  (const BigNumber & n1, const BigNumber & n2)
{
	for (int i = 0; i < n1.usedBytesCount; i++)
	{
		if (n1.bytes[i] > n2.bytes[i])
			return false;
	}
	return true;
}

bool operator >  (const BigNumber & n1, const BigNumber & n2)
{
	for (int i = 0; i < n1.usedBytesCount; i++)
	{
		if (n1.bytes[i] < n2.bytes[i])
			return false;
	}
	return true;
}

bool operator >= (const BigNumber & n1, const BigNumber & n2)
{
	for (int i = 0; i < n1.usedBytesCount; i++)
	{
		if (n1.bytes[i] <= n2.bytes[i])
			return false;
	}
	return true;
}

bool operator <= (const BigNumber & n1, const BigNumber & n2)
{
	for (int i = 0; i < n1.usedBytesCount; i++)
	{
		if (n1.bytes[i] >= n2.bytes[i])
			return false;
	}
	return true;
}
