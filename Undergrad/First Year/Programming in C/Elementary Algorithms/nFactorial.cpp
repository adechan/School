// It displays the factorial of a n number.

#include "stadfx.h"
include <iostream>

int factorialNumber(int n)
{
	if (n == 0 || n == 1) return 1;
	else
		return n * factorialNumber(n - 1);

}

int main()
{
	int n;
	std::cout << "Spune un numar: ";
	std::cin >> n;
	std::cout << factorialNumber(n);

	return 0;
}
