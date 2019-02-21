#include "token.hpp"

namespace lexer
{	
	token::token(const std::string& text, lexer::type type, int id, int line, int column)
		: text_(text), type_(type)
		, id_(id), line_(line), column_(column)
	{}
		
	const std::string& token::text() const
	{
		return text_;
	}
	
	lexer::type token::type() const
	{ return type_; }
	
	int token::line() const
	{
		return line_;
	}
	
	int token::column() const
	{
		return column_;
	}

	int token::length() const
	{
		return text_.size();
	}
	
	int token::id() const
	{
		return id_;
	}
	
	bool token::empty() const
	{
		return text_.size() == 0;
	}
}
