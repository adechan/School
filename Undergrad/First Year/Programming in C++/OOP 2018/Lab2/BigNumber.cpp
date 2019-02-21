#include <iostream>
#include "BigNumber.h"

BigNumber::BigNumber()
{
	Number[0] = 0;
	CharactersCount = 1;
}

BigNumber::BigNumber(int value)
{
	memcpy(Number, &value, sizeof(int));
	CharactersCount = sizeof(int);
}

BigNumber::BigNumber(const char * number)
{
	int count = strlen(number);
	memcpy(Number, number, count);
	CharactersCount = count;
}

BigNumber::BigNumber(const BigNumber& number)  // copy constructor
{
	// BigNumber x, y
	//                        &         number
	// x looks like { char* Number = 0x400, int count }
	// y looks like { char* Number = 0x500, int count }

	//                       array of numbers
	// x.Number (0x400) points to { 0, 0, 0, 0, ..., 0}
	// y.Number(0x500) points to { 1, 0, 1, 0, ..., 0}

	// x.Number is 0x400
	// y.Number is 0x500

	// copy x = y
	// y: { Number } -> x: { Number }
	// y: { count  } -> x: { count  }

	// x.Number is 0x500
	// y.Number is 0x500

	// x.Number points to ?

	memcpy(Number, number.Number, number.CharactersCount);
	this->CharactersCount = number.CharactersCount;

}

bool BigNumber::Set(int value)
{
	// memcpy takes a pointer ot the guy we want to copy (both source and dest)
	memcpy(Number, &value, sizeof(value));
	this->CharactersCount = sizeof(value);
}

bool BigNumber::Set(const char * number)
{
	memcpy(Number, number, strlen(number));
	this->CharactersCount = strlen(number);
}

BigNumber BigNumber::operator+(const BigNumber & number)
{
	// int x = 54326 = 0xD436 = {0x36, 0xD4, 0x00, 0x00}
	// int y = x

}

bool operator==(const BigNumber & n1, const BigNumber & n2)
{
	// x y
	// 0 0 i = 0
	// 1 0 i = 1
	if (n1.CharactersCount != n2.CharactersCount) return false;
	for (int i = 0; i < n1.CharactersCount; i++)
		if (n1.Number[i] != n2.Number[i]) return false;
	return true;
}

bool operator!=(const BigNumber & n1, const BigNumber & n2)
{
	if (n1.CharactersCount == n2.CharactersCount) return false;
	for (int i = 0; i < n1.CharactersCount; i++)
		if (n1.Number[i] == n2.Number[i]) return false;
	return true;
}

bool operator<(const BigNumber & n1, const BigNumber & n2)
{
	for (int i = 0; i < n1.CharactersCount; i++)
		if (n1.Number[i] > n2.Number[i]) return false;
	return true;
}

bool operator>(const BigNumber & n1, const BigNumber & n2)
{
	for (int i = 0; i < n1.CharactersCount; i++)
		if (n1.Number[i] < n2.Number[i]) return false;
	return true;
}

bool operator<=(const BigNumber & n1, const BigNumber & n2)
{
	for (int i = 0; i < n1.CharactersCount; i++)
		if (n1.Number[i] >= n2.Number[i]) return false;
	return true;
}

bool operator>=(const BigNumber & n1, const BigNumber & n2)
{
	for (int i = 0; i < n1.CharactersCount; i++)
		if (n1.Number[i] <= n2.Number[i]) return false;
	return true;
}