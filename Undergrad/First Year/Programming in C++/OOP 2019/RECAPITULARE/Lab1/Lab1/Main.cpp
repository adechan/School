#include <iostream>
#include "MyString.h"

int main()
{
	MyString obiect1 = MyString("hey");

	std::cout << obiect1.GetSize() << '\n';
	obiect1.Add("hey");
	std::cout << obiect1.GetText() << '\n';

	std::cout << obiect1.Compare("hey") << '\n';
	
	std::cin.get();
	return 0;
}