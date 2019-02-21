%{
	#include <cstring>
	#include <string>
	#include <iostream>
	#include "parser/parser.hpp"
	#include "lexer/lexer.hpp"
	#include "y.tab.h"	

	extern YYSTYPE yylval;

%}

letter 		[a-zA-Z_]
digit 		[0-9]
real 		{digit}*"."{digit}+
whitespace 	[ \t]
newline 	[\n]
string_literal \'(\\.|[^\\'])*\'

%%
%{
	
%}

{digit}+	{ 
				lexer::add_token(yytext, lexer::type::integer); 
				parser::set_lvalue(); 
				return CONSTANT_INT; 
			}
			
{real}		{
				lexer::add_token(yytext, lexer::type::real); 
				parser::set_lvalue(); 
				return CONSTANT_REAL; 
			}
				
{whitespace}	{ lexer::advance_column(yytext[0]); }

"if" 		{ lexer::add_token(yytext); parser::set_lvalue(); return IF; }
"else" 		{ lexer::add_token(yytext); parser::set_lvalue(); return ELSE; }
"for" 		{ lexer::add_token(yytext); parser::set_lvalue(); return FOR; }
"true" 		{ lexer::add_token(yytext); parser::set_lvalue(); return TRUE; }
"false" 	{ lexer::add_token(yytext); parser::set_lvalue(); return FALSE; }

"constant" 	{ lexer::add_token(yytext); parser::set_lvalue(); return CONSTANT; }

"function" 	{ lexer::add_token(yytext); parser::set_lvalue(); return FUNCTION; }
"integer" 	{ lexer::add_token(yytext); parser::set_lvalue(); return INTEGER; }
"none" 		{ lexer::add_token(yytext); parser::set_lvalue(); return NONE; }
"character" { lexer::add_token(yytext); parser::set_lvalue(); return CHARACTER; }
"real" 		{ lexer::add_token(yytext); parser::set_lvalue(); return REAL; }
"bool" 		{ lexer::add_token(yytext); parser::set_lvalue(); return BOOL; }
"string" 	{ lexer::add_token(yytext); parser::set_lvalue(); return STRING; }

"return"	{ lexer::add_token(yytext); parser::set_lvalue(); return RETURN; }
"while" 	{ lexer::add_token(yytext); parser::set_lvalue(); return WHILE; }
"global"	{ lexer::add_token(yytext); parser::set_lvalue(); return GLOBAL; }

"Print"		{ lexer::add_token(yytext); parser::set_lvalue(); return PRINT; }

"("			{ lexer::add_token(yytext); parser::set_lvalue(); return OPEN_PARENTHESIS; }
")"			{ lexer::add_token(yytext); parser::set_lvalue(); return CLOSE_PARENTHESIS; }
"["			{ lexer::add_token(yytext); parser::set_lvalue(); return OPEN_BRACKET; }
"]"			{ lexer::add_token(yytext); parser::set_lvalue(); return CLOSE_BRACKET; }
"{"			{ lexer::add_token(yytext); parser::set_lvalue(); return OPEN_BRACE; }
"}"			{ lexer::add_token(yytext); parser::set_lvalue(); return CLOSE_BRACE; }
";"			{ lexer::add_token(yytext); parser::set_lvalue(); return SEMICOLON; }
","			{ lexer::add_token(yytext); parser::set_lvalue(); return COMMA; }
"="			{ lexer::add_token(yytext); parser::set_lvalue(); return ASSIGN_OP; }

"<"		{ lexer::add_token(yytext, lexer::type::binary_operator); parser::set_lvalue(); return LT_OP; }
">"		{ lexer::add_token(yytext, lexer::type::binary_operator); parser::set_lvalue(); return GT_OP; }
"<="	{ lexer::add_token(yytext, lexer::type::binary_operator); parser::set_lvalue(); return LEQ_OP; }
">="	{ lexer::add_token(yytext, lexer::type::binary_operator); parser::set_lvalue(); return GEQ_OP; }
"=="	{ lexer::add_token(yytext, lexer::type::binary_operator); parser::set_lvalue(); return EQUALS_OP; }
"!="	{ lexer::add_token(yytext, lexer::type::binary_operator); parser::set_lvalue(); return NOT_EQUALS_OP; }

"+"		{ lexer::add_token(yytext, lexer::type::binary_operator); parser::set_lvalue(); return ADD_OP; }
"-"		{ lexer::add_token(yytext, lexer::type::binary_operator); parser::set_lvalue(); return SUBTRACT_OP; }
"*"		{ lexer::add_token(yytext, lexer::type::binary_operator); parser::set_lvalue(); return MULTIPLY_OP; }
"/"		{ lexer::add_token(yytext, lexer::type::binary_operator); parser::set_lvalue(); return DIVIDE_OP; }
"and"	{ lexer::add_token(yytext, lexer::type::binary_operator); parser::set_lvalue(); return BOOLEAN_AND_OP; }
"or"	{ lexer::add_token(yytext, lexer::type::binary_operator); parser::set_lvalue(); return BOOLEAN_OR_OP; }
"not"	{ lexer::add_token(yytext, lexer::type::unary_operator); parser::set_lvalue(); return BOOLEAN_NOT_OP; }
"++"	{ lexer::add_token(yytext, lexer::type::unary_operator); parser::set_lvalue(); return INC_OP; }
"--"	{ lexer::add_token(yytext, lexer::type::unary_operator); parser::set_lvalue(); return DEC_OP; }

"."			{ lexer::add_token(yytext); parser::set_lvalue(); return DOT_OP; }

{letter}({letter}|{digit})* { lexer::add_token(yytext); parser::set_lvalue(); return IDENTIFIER; }
{string_literal} { lexer::add_token(yytext); parser::set_lvalue(); return STRING_LITERAL; }

{newline}	{ lexer::next_line(); }
	.		{ lexer::advance_column(); }
%%

int yywrap() 
{ 
	return 1; 
}