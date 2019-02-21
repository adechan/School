#include "symbol.hpp"

namespace parser
{
	symbol::symbol(const lexer::token& token, parser::type type)
		: token_(token)
		, type_(type)
	{}
	
	const std::string& symbol::text() const
	{
		return token_.text();
	}
}