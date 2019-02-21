#include "lexer.hpp"

#include <iostream>

namespace lexer
{
	static std::vector<token> tokens_;
	
	static int current_line_ = 1;
	static int current_column_ = 1;
	
	int current_line()
	{
		return current_line_;
	}
	
	const std::vector<token>& tokens()
	{
		return tokens_;
	}
	
	static void push_token(const std::string& value, lexer::type type, int id, int line, int column)
	{ 
		tokens_.push_back(token(value, type, id, line, column)); 
	}
	
	void add_token(const std::string& text, lexer::type type)
	{
		if (token_count() == 0)
		{
			push_token(text, type, tokens_.size() - 1, current_line(), 1);
			return;
		}
		
		current_column_ = current_column_ + current_token().text().size();
		push_token(text, type, tokens_.size() - 1, current_line(), current_column_);
	}
	
	token& current_token()
	{
		return tokens_.back();
	}
	
	token& get_token(int i)
	{
		return tokens_[i];
	}
	
	int token_count()
	{
		return tokens_.size();
	}
	
	void next_line()
	{
		current_line_++;
		current_column_ = 0;
	}
	
	void advance_column(char c)
	{
		int length = 1;
		if (c == '\t')
			if (current_column_ % 4 == 0)
				length = 4;
			else
				length = 4 - ((current_column_ % 4) - 1);
		
		current_column_ += length;
	}
	
	void reset()
	{
		tokens_.clear();
	}
}