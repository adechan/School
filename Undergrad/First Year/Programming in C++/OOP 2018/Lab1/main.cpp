#include <iostream>

#include "MyString.h"

void test(int)
{
	std::cout << "in guy \n";
}

void test(const char*)
{
	std::cout << "const char* guy \n";
}

int main()
{
	MyString string("ayy"), string2;

	std::cout << "Testing GetText, GetSize...\n"; 
	std::cout << string.GetText() << '\n';
	std::cout << "Size = " << string.GetSize() << '\n';

	string.Set("Dankmanweedman");
	std::cout << string.GetText() << '\n';
	std::cout << "Size = " << string.GetSize() << '\n';

	string.Add(" ayyyyy");
	std::cout << string.GetText() << '\n';
	std::cout << "Size = " << string.GetSize() << '\n';
	//string.GetSize();

	//test("ayy");
	//assign
	//set x = 2
	//string2 = string;
	//string2.Set(string);

	std::cout << "Testing SubString...\n"; 
		string.Set("YoYo Ade Meow Meow");
	MyString* substr = string.SubString(5, 3);

	if (substr != nullptr)
		std::cout << substr->GetText() << std::endl;


	std::cout << "Testing Delete...\n";
	string.Set("meow horse ade ade");
	string.Delete(5, 5);
	std::cout << string.GetText() << '\n';

	std::cout << "Testing Compare...\n";
	string.Set("Abc");
	std::cout << string.Compare("abc") << std::endl;

	string.Set("ade");
	MyString string3;
	string3.Set("ade");
	std::cout << string.Compare(string3) << std::endl;
	
	//string3.Set("Adeadeade dog dog ade");
	//string3.Insert(6, "shrek");
	
	std::cout << "Testing Insert...\n";
	string.Set("adee chan baby");
	string.Insert(4, "shaun ");
	std::cout << string.GetText() << std::endl;

	std::cout << "Testing FindLast...\n";
	string.Set("meow meow ade chan hi lel ade");
	std::cout << string.FindLast("ade");

	std::cin.get();
	return 0;
}