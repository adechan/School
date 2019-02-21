#pragma once
#include <string>

#include "types.hpp"
#include "string_conversions.hpp"

namespace lexer
{
	class token
	{
	public:
		token() = default;
		explicit token(const std::string& text, lexer::type type, int id, int line, int column);
			
		const std::string& text() const;
		lexer::type type() const;

		int line() const;
		int column() const;
		int length() const;
		
		int id() const;
		
		bool empty() const;
		
		//virtual ~token() {}
		
	private:
		std::string text_;
		lexer::type type_;
		int id_;
		int line_;
		int column_;
	};
	
	/*
	class integer
	{
		
	};
	
	class real
	{
		
	};
	
	class character
	{
		
	};
	
	class unary_operator
	{
		
	};
	
	class binary_operator
	{
		
	};
	
	class function
	{
		
	};*/
}