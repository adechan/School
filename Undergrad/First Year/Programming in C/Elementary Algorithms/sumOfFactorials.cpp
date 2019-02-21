// It displays the sum of a n factorial numbers. 
ex: n = 3 ; Sum = 1! + 2! + 3!

#include "stadfx.h"
#include <iostream>

int factorialNumber(int n)
{
	if (n == 0 || n == 1) return 1;
	else
		return n * factorialNumber(n - 1);

}

int main()
{
	int n, sum = 0;
	std::cout << "Spune un numar: ";
	std::cin >> n;
	for (int i = 1; i <= n; i++)
	{
		std::cout << i << " ";
	}
	std::cout << '\n';

	for (int i = 1; i <= n; i++)
	{
		sum = sum+ factorialNumber(i);
	}
	std::cout << sum;

	return 0;
}
