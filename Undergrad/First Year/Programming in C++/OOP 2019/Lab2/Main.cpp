#include <iostream>
#include "MyString.h"

int main()
{
	MyString string("Hello, hello!"), string2;

	std::cout << "Testing GetText, GetSize...\n";
	std::cout << string.GetText() << '\n';
	std::cout << "Size string = " << string.GetSize() << '\n';
	std::cout << std::endl;

	string.Set("Meow meow..");
	std::cout << string.GetText() << '\n';
	std::cout << "Size = " << string.GetSize() << '\n';
	std::cout << std::endl;

	string.Add("Cute cat");
	std::cout << string.GetText() << '\n';
	std::cout << "Size = " << string.GetSize() << '\n';
	std::cout << std::endl;

	std::cout << "Testing SubString...\n";
	string.Set("It's a cute cat around...");
	MyString* substr = string.SubString(7, 8);
	if (substr != nullptr)
		std::cout << substr->GetText() << std::endl;
	std::cout << std::endl;



	std::cout << "Testing Delete...\n";
	string.Set("I want to delete a cat :)");
	string.Delete(5, 5);
	std::cout << string.GetText() << '\n';
	std::cout << std::endl;

	std::cout << "Testing Compare...\n";
	string.Set("Abc");
	std::cout << "Abc same as abc? " << string.Compare("abc") << std::endl;
	std::cout << std::endl;

	string.Set("cat");
	MyString string3;
	string3.Set("cat");
	std::cout << "cat same as cat? "<< string.Compare(string3) << std::endl;
	std::cout << std::endl;

	std::cout << "Testing Insert...\n";
	string.Set("Hey -cute cat");
	string.Insert(4, "pretty");
	std::cout << string.GetText() << std::endl;
	std::cout << std::endl;

	std::cout << "Testing Find...\n";
	string.Set("meow hey hey");
	std::cout << "Found on " << string.Find("hey");
	std::cout << std::endl;

	std::cout << "Testing FindLast...\n";
	string.Set("meow meow cat cat meow meow cat meow");
	std::cout << "Found on " << string.FindLast("cat");
	std::cout << std::endl;

	std::cin.get();
	return 0;
}