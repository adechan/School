// It displays the sum of even digits of a number.

#include "stdafx.h"
#include <iostream>

int digitsSumEven(int n)
{
	int sum = 0, cifra = 0;
	while (n != 0)
	{
		cifra = n % 10;
		n = n / 10;
		if (cifra % 2 == 0) sum = sum + cifra;
	}
	return sum;
}

int main()
{
	int n;
	std::cout << "Spune un numar: ";
	std::cin >> n;
	std::cout << "Suma cifrelor pare este:" << digitsSumEven(n) << std::endl;

	return 0;
}
