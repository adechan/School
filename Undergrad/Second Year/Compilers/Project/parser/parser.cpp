#include "parser.hpp"
#include "../lexer/lexer.hpp"

#include <stdexcept>
#include <cstdio>
#include <cstring>
#include <algorithm>

extern int yylineno;
extern char* yytext;
extern FILE* yyin;

extern YYSTYPE yylval;

extern int yyparse();

namespace parser
{
	static std::string current_filename_;
	
	static int last_processed_token_ = 0;
	
	std::vector<parser::symbol_table>& global_scope()
	{
		static std::vector<parser::symbol_table> global_scope_;
		return global_scope_;
	}
	
	std::string current_file()
	{
		return current_filename_;
	}
	
	void set_lvalue()
	{
		::yylval = lexer::current_token();
	}
	
	std::ostream& output_error(const std::string& message, std::ostream& out)
	{

		return out << current_filename_ << ":" 
			<< last_processed_token().line() << ":" << last_processed_token().column()
			<< ": Syntax error; last parsed token >" << last_processed_token().text() << "<\n";
	}
	
	const lexer::token& last_processed_token()
	{
		return lexer::tokens()[last_processed_token_];
	}
	
	void process_token(const lexer::token& token)
	{
		last_processed_token_ = token.id();
		//symbol_table.push_back(symbol(token, 
	}
	
	bool parse_file(const std::string& filename)
	{
		::yyin = ::fopen(filename.c_str(), "r");
		if (!::yyin)
			throw std::runtime_error(
				std::string("Unable to open file: ") + ::strerror(errno)
			);
		
		current_filename_ = filename;
		bool result = ::yyparse();
		::fclose(::yyin);
		return result;
	}
}