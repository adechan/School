#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

bool Convert(unsigned int number, unsigned int toBase, char* result, unsigned int resultMaxSize)
{
	if (result == NULL)
		return false;

	// set memory to 0
	memset(result, 0, resultMaxSize);
	int remainder[100];
	int x = 0;

	while (number != 0)
	{
		remainder[x] = number % toBase;
		number = number / toBase;
		x++;
	}

	// 8 -> 8
	// 9 -> 9
	// 10 -> A = 65 
	// 11 -> B = 66 
	// 12 -> C = 67 
	// 13 -> D = 68
	char buffer[256];
	for (int i = x - 1; i >= 0; i--)
	{
		// for bases >= 10
		if (remainder[i] > 9)
			// b = 65 - 10 = 55
			sprintf(buffer, "%c", remainder[i] + 55);
		else
			sprintf(buffer, "%d", remainder[i]);

		strcat(result, buffer);
	}

	return true;
}

int main()
{
	char result[256];
	int number;
	std::cout << "Give a number: ";
	std::cin >> number;

	int base;
	std::cout << "Give a base: ";
	std::cin >> base;


	Convert(number, base, result, 256);
	std::cout << "The conversion to base " << base << " is " << result;

	std::cin.get();
	std::cin.get();
	return 0;
}