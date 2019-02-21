#pragma once
#include <iostream>

namespace lexer
{
	enum class type
	{
		string, integer, real, character, unary_operator, binary_operator, function
	};
	
	std::ostream& operator<<(std::ostream& stream, lexer::type type);
}