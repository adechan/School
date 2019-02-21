#include "types.hpp"

namespace lexer
{
	std::ostream& operator<<(std::ostream& stream, lexer::type type)
	{
		switch (type)
		{
			case lexer::type::string: stream << "string"; break;
			case lexer::type::integer: stream <<  "integer"; break;
			case lexer::type::real: stream <<  "real"; break;
			case lexer::type::character: stream <<  "character"; break;
			case lexer::type::unary_operator: stream <<  "unary_operator"; break;
			case lexer::type::binary_operator: stream <<  "binary_operator"; break;
			case lexer::type::function: stream <<  "function"; break;
		}
		
		return stream;
	}
}