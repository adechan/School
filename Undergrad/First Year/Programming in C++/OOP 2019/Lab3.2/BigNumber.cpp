#include "BigNumber.h"
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>

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
}

void BigNumber::Set(int value)
{
	memcpy(this->bytes, &value, sizeof(value));
	this->usedBytesCount = sizeof(value);
}

void BigNumber::Set(const char * number)
{
	std::strncpy(this->bytes, number, 256);
	usedBytesCount = strlen(number);
}


// SUPRASCRIERE operatori
BigNumber BigNumber::operator+ (const BigNumber & other)
{
		// this : pointer to BigNumber
		// *this : type of BigNumber&
		BigNumber result = *this;

		int overflow = 0;
		int maxBytesCount = std::max(this->usedBytesCount, other.usedBytesCount);

		for (int i = 0; i < maxBytesCount; i++)
		{
			// add the two bytes together
			// if their sum overflows > 0xFF (i.e., can't fit into 1 byte)
			// then move the overflow into the next byte

			//int sum = std::to_string(this->bytes[i]) + (int)other.bytes[i] + overflow;
			result.bytes[i] = sum % 0x100;

			if (sum > 0xFF)
				overflow = sum - 0xFF;
			else
				overflow = 0;
		}

		// The last two bytes' sum overflowed
		if (overflow > 0)
			result.bytes[maxBytesCount] = overflow;

		result.usedBytesCount = maxBytesCount + 1;
		return result;
}


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
	// a more elegant way to implement this is as
	// return not true (n1 == n2), that is:
	// return !operator==(n1, n2);
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
	int countOne1 = 0;
	int countOne2 = 0;

	// 9184_10 = 23E0_16
	// 9288_10 = 2448_16

	// the logical negation of < is >= 
	// so if n1 == n2 then < is false
	if (operator==(n1, n2))
		return false;

	// or if n1 > n2 then < is false
	// e.g.: 423 < 311
	for (int i = n1.usedBytesCount - 1; i >= 0; i--)
	{
		// 323, 411
		// we are checking (3 < 4)
		// in this case since 3 < 4 we can immediately say the whole number n1 < n2
		if (n1.bytes[i] < n2.bytes[i])
			return true;

		// otherwise we have a situation like 411 < 323
		// in which we are checking 4 > 3, in which the whole number is n1 > n2
		else if (n1.bytes[i] > n2.bytes[i])
			return false;

		// the last case is that the digits are ==
	}

	// this happens if after the for loop all the digits are ==
	// which is NOT what we want for <
	return false;
}

bool operator >  (const BigNumber & n1, const BigNumber & n2)
{
	return !(operator<(n1, n2) || operator==(n1, n2));
}

bool operator >= (const BigNumber & n1, const BigNumber & n2)
{
	return !operator<(n1, n2);
}

bool operator <= (const BigNumber & n1, const BigNumber & n2)
{
	return !operator>(n1, n2);
}
