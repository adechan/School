// Find the greatest common divisor for n numbers.

#include "stadfx.h"
#include <iostream>

int cmmdc(int a, int b)
{
	int r =  a % b; 
	while (r != 0)
	{
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main()
{
	int n, i;
	int numbers[100];
	int result = numbers[0];
	
	std::cout << "Enter a positive number: ";
	std::cin >> n;

	for (i = 1; i <= n; i++)
	{
		std::cout << "Number " << i << " : ";
		std::cin >> numbers[i];
	}
	for (i = 1; i < n; i++)
	{
		result = cmmdc(result, numbers[i]);
	}
	std::cout << "The greatest common divisor " << result;
	return 0;
}
