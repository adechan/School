#include <iostream>
#include "BigNumber.h"

int main()
{
	BigNumber number = BigNumber(4);
	BigNumber number1 = BigNumber();
	number1.Set(4);

	int result = number == number1;

	std::cout << result; 

	std::cin.get();
	return 0;
}