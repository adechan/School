#pragma once
#include <vector>
#include <memory>

#include "token.hpp"

namespace lexer
{
	const std::vector<token>& tokens();
	
	token& current_token();
	
	token& get_token(int i);
	
	int current_line();
	int token_count();
	
	void add_token(const std::string& text, lexer::type type = lexer::type::string);
	
	void next_line();
	
	void advance_column(char c = ' ');
	
	void reset();
	
}