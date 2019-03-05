#include <iostream>
#include "BigNumber.h"

/*
	[0x0c, 0x8f] + [0x00, 0xde] = [0x0d, 0x6d]
*/

int main()
{
	BigNumber number = BigNumber(3);
	BigNumber number1 = BigNumber();

	number1.Set(4);


	std::cin.get();
	return 0;
}