// It displays every fibonacci number smaller or equal with n.

#include "stadfx.h"
#include <iostream>

int fibonacciNumber(int n)
{
	if (n == 0) return 0;
	else
		if (n == 1) return 1;
		else return fibonacciNumber(n - 1) + fibonacciNumber(n - 2);
}

int main()
{
	int n, i;
	std::cout << "Enter a positive number: ";
	std::cin >> n;

	for (i = 0; i <= n; i++)
	{
		if (fibonacciNumber(i) <= n)
			std::cout << fibonacciNumber(i) << " ";	
		
	}
	return 0;
}
