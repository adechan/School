// Display the product of odd numbers and the sum of even numbers when you have n elements.

#include "stdafx.h"
#include <iostream>

int sumEven(int *numbers, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		if ( numbers[i] % 2 == 0)	
			sum += numbers[i];
	}
	return sum;
}

int productOdd(int *numbers, int size)
{
	int product = 1;
	for (int i = 0; i < size; i++)
	{
		if (numbers[i] % 2 != 0)
			product *= numbers[i];
	}
	return product;
}

int main()
{
	int n = 0;
	int *numbers = nullptr;

	std::cout << "Marimea vectorului: ";
	std::cin >> n;
	numbers = new int[n];
	std::cout << "Input " << n << " numarul: \n";
	
	for (int i = 0; i < n; i++)
	{
		std::cout << "Numar " << i << ": ";
		std::cin >> numbers[i];
		std::cout << '\n';
	}
	
	std::cout << "Suma numerelor pare = " << sumEven(numbers, n) << '\n';
	std::cout << "Produsul numerelor impare = " << productOdd(numbers, n) << '\n';
	
	delete[] numbers;
	return 0;
}
