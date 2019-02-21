#include <iostream>
#include <cstdio>

#include "parser/parser.hpp"
#include "lexer/lexer.hpp"

int main(int argc, char* argv[])
{
	if (argc < 2)
		return -1;
	
	try
	{
		parser::parse_file(argv[1]);
		std::cout << "Done parsing\n";
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}