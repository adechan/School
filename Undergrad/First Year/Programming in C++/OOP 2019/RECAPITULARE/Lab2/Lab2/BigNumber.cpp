#include "BigNumber.h"
#include <cstring>

// Constructor implicit (creaza numarul 0 [field-ul Number contine "0", field-ul CharactersCount contine valoarea 1 - un caracter]
BigNumber::BigNumber()
{
	Number[0] = 0;
	CharactersCount = 1;
}

BigNumber::BigNumber(int value)
{
	std::memcpy(Number, &value, sizeof(int));
	CharactersCount = sizeof(int);
}

BigNumber::BigNumber(const char * number)
{
	std::memcpy(Number, number, strlen(number));
	CharactersCount = strlen(number);
}

BigNumber::BigNumber(const BigNumber & number)
{
	Set(number.Number);
}

bool BigNumber::Set(int value)
{
	std::memcpy(Number, &value, sizeof(value));
	CharactersCount = sizeof(value);
	return true;
}

bool BigNumber::Set(const char * number)
{
	std::memcpy(Number, number, strlen(number));
	CharactersCount = strlen(number);
	return true;
}

// OPERATORI

// FUNCTII PRIETENE
bool operator == (const BigNumber & n1, const BigNumber & n2)
{
	if (n1.CharactersCount != n2.CharactersCount)
		return false;

	for (int i = 0; i < n1.CharactersCount; i++)
	{
		if (n1.Number[i] != n2.Number[i])
			return false;
	}
	return true;
}

bool operator != (const BigNumber & n1, const BigNumber & n2)
{
	return !operator==(n1, n2);
}

bool operator <  (const BigNumber & n1, const BigNumber & n2)
{
	if (operator==(n1, n2))
		return false;

	for (int i = n1.CharactersCount - 1; i >= 0; i--)
	{
		if (n1.Number[i] < n2.Number[i])
			return true;

		else if (n1.Number[i] > n2.Number[i])
			return false;
	}
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
