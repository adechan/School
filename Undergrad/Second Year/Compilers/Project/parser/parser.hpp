#pragma once
#include <string>
#include <iostream>
#include <vector>

#include "../lexer/token.hpp"
#include "symbol_table.hpp"
#include "scope.hpp"

// parser module
namespace parser
{
	std::vector<parser::symbol_table>& global_scope();
	
	std::string filename();
	
	void set_lvalue();
	
	const lexer::token& last_processed_token();
	
	void process_token(const lexer::token& token);
	
	std::ostream& output_error(const std::string& message, std::ostream& out = std::cerr);
	
	bool parse_file(const std::string& filename);
}

#define YYSTYPE lexer::token