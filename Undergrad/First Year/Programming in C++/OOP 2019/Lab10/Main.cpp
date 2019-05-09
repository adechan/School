
#include <iostream>
#include "Lab10.h"


int main()
{
	Array<const int> array;

	try
	{
		array.Insert(0, 2);
		array.Insert(0, -1);
		std::cout << array[1] << '\n';

		array.Delete(1);
		std::cout << array[1] << '\n';
	}
	catch (std::out_of_range& e)
	{
		std::cout << "Exception: " << e.what() << '\n';
	}

	std::cin.get();
	return 0;
}
