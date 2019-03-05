#include "BigNumber.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string>

// Number contine "0", field - ul CharactersCount contine valoarea 1
BigNumber::BigNumber()
{
	number[0] = 0;
	charactersCount = 1;
}

// Copie in Number, valoarea lui value
BigNumber::BigNumber(int value)
{
	// sizeof = amount of memory allocated to that data type 
	// memcpy ( void * destination, const void * source, size_t num );
	memcpy(this->number, &value, sizeof(int));
	charactersCount = sizeof(int);
}

// Copie in Number, valuarea lui number
BigNumber::BigNumber(const char * number)
{
	memcpy(this->number, number, strlen(number));
	charactersCount = strlen(number);
}

// copy constructor : A copy constructor is a member function which
// initializes an object using another object of the same class
BigNumber::BigNumber(const BigNumber &number)
{
	this->Set(number.number);

	//memcpy(this->number, number.number, number.charactersCount);
	//this->charactersCount = number.charactersCount;
}

void BigNumber::Set(int value)
{
	memcpy(this->number, &value, sizeof(value));
	this->charactersCount = sizeof(value);
}

void BigNumber::Set(const char * number)
{
	memcpy(this->number, number, strlen(number));
	charactersCount = strlen(number);
}


// SUPRASCRIERE operatori
