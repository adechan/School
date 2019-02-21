// Checks if a number is prime.

#include "stadafx.h"
#include <iostream>

int prime (int n)
{
	int i;
	bool isPrime = true;

	for (i = 2; i < n / 2; i++)
	{
		if (n % i == 0)
		{
			isPrime = false;
			break;
		}
	}
	return isPrime;
	
}

int main()
{
	int n;
	std::cout << "Spune un numar: ";
	std::cin >> n;
	if (prime(n) != 0)
		std::cout << n << " este prim" << std::endl;
	else
		std::cout << n << " nu este prim" << std::endl;

	return 0;
}
