#pragma once

#include "../lexer/token.hpp"
#include "types.hpp"

#include <stack>
#include <string>

namespace parser
{
	class symbol
	{
	public:
		explicit symbol(const lexer::token& token, parser::type type);
		
		const std::string& text() const;
	
	private:
		lexer::token token_;
		parser::type type_;
	};
}