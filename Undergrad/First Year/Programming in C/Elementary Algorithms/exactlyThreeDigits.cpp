// It reads n numbers. Displays how many numbers have exactly 3 digits nonzero.

#include "stdafx.h"
#include <iostream>

bool has3NonZeroDigits(int n)
{
	int counter = 0;

	while (n != 0)
	{
		if (n % 10 != 0) counter++;
		n = n / 10;
	}

	if (counter == 3) return true;
	else return false;
}

int main()
{
	int n = 0;
	int *numbers = nullptr;

	std::cout << "Size of array: ";
	std::cin >> n;
	numbers = new int[n];
	std::cout << "Input " << n << " numere: \n";

	for (int i = 0; i < n; i++)
	{
		std::cout << "Numarul " << i << ": ";
		std::cin >> numbers[i];
		std::cout << '\n';
	}

	std::cout << "Numere cu exact 3 cifre nenule: \n";

	for (int i = 0; i < n; i++)
	{
		if (has3NonZeroDigits(numbers[i]))
			std::cout << numbers[i] << ' ';
	}
	std::cout << '\n';
	
	delete[] numbers;
	return 0;
}
