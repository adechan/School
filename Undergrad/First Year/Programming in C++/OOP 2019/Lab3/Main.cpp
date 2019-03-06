#include <iostream>
#include <vector>
#include "BigNumber.h"

/*
	[0x0c, 0x8f] + [0x00, 0xde] = [0x0d, 0x6d]
*/

int main()
{
	BigNumber number = BigNumber(0xFFAA);
	BigNumber number1 = BigNumber();

	number1.Set(4);

	std::cout << (0x16 + 0x6) << '\n';
	std::cin.get();
	return 0;
}