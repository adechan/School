// Read n numbers until you meet 0, then display the numbers that are palindromes

#include "stdafx.h"
#include <iostream>

bool palindrome(int n)
{
	int invers = 0, copie;
	copie = n;
	while (n != 0)
	{
		invers = invers * 10 + n % 10;
		n = n / 10;
	}
	if (invers == copie) return true;
	else 
		return false;
}

int main()
{
	int n, i;
	std::cout << "Dati un numar: ";
	std:: cin >> n;
	for (i = n; i >= 0; i--)
		std::cout << i << " ";
	std::cout << '\n';
	for (i = n; i >= 0; i--)
	{
		if (palindrome(i))
			std::cout << i << " ";
	}

	return 0;
}
