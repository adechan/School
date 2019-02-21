%{
#include <iostream>
#include <string>
#include <cstdio>
#include "parser/parser.hpp"
#include "lexer/lexer.hpp"

extern void yyerror(const char*);
extern int yylex();

%}

%locations
%token CONSTANT_INT CONSTANT_REAL STRING_LITERAL CHAR_LITERAL
%token IDENTIFIER

%token GLOBAL CONSTANT
%token INTEGER CHARACTER REAL NONE BOOL STRING FUNCTION
%token IF ELSE WHILE FOR RETURN PRINT
%token TRUE FALSE
%token ASSIGN_OP DOT_OP ADD_OP SUBTRACT_OP MULTIPLY_OP DIVIDE_OP INC_OP DEC_OP
%token LT_OP GT_OP LEQ_OP GEQ_OP EQUALS_OP NOT_EQUALS_OP
%token BOOLEAN_AND_OP BOOLEAN_OR_OP BOOLEAN_NOT_OP
%token SEMICOLON COMMA
%token OPEN_BRACKET CLOSE_BRACKET OPEN_BRACE CLOSE_BRACE OPEN_PARENTHESIS CLOSE_PARENTHESIS
%token NEWLINE

%%

program : block	
	| statement_list
	;
	
semicolon : SEMICOLON { $$ = $1; parser::process_token($1); }

primitive_type : NONE 	{ $$ = $1; parser::process_token($1); }
	| INTEGER 			{ $$ = $1; parser::process_token($1); }
	| CHARACTER 		{ $$ = $1; parser::process_token($1); }
	| REAL 				{ $$ = $1; parser::process_token($1); }
	| STRING 			{ $$ = $1; parser::process_token($1); }
	;
	
array_type : primitive_type OPEN_BRACKET CLOSE_BRACKET 
	| primitive_type OPEN_BRACKET CONSTANT_INT CLOSE_BRACKET
	
constant : STRING_LITERAL 	{ $$ = $1; parser::process_token($1); }
	| CHAR_LITERAL 			{ $$ = $1; parser::process_token($1); }
	| CONSTANT_INT 			{ $$ = $1; parser::process_token($1); }
	| CONSTANT_REAL 		{ $$ = $1; parser::process_token($1); }
	| TRUE			 		{ $$ = $1; parser::process_token($1); }
	| FALSE			 		{ $$ = $1; parser::process_token($1); }
	;
	
scope_specifier : GLOBAL {  parser::process_token($1); std::cerr << "type_specifier\n"; }
	|
	;

type_specifier : primitive_type { std::cerr << "type_specifier\n"; }
	| array_type
	;

variable_declaration : scope_specifier type_specifier IDENTIFIER 
		{ parser::process_token($3); std::cerr << "hey" << '\n'; }
	;
	
variable_init : variable_declaration ASSIGN_OP expression 
		{  parser::process_token($2); std::cerr << "variable_init : variable_declaration ASSIGN_OP expression \n"; }
	
variable_decl_seq :
	| variable_declaration COMMA variable_declaration {  parser::process_token($2); }
	| variable_declaration
	;
		
lvalue : IDENTIFIER { parser::process_token($1); std::cerr << "lvalue " << $1.text() << '\n'; }
	| INC_OP lvalue
	| DEC_OP lvalue
	
	| lvalue INC_OP
	| lvalue DEC_OP
	
	| OPEN_PARENTHESIS lvalue CLOSE_PARENTHESIS
	;
	
value_operand : lvalue | rvalue;
	
rvalue : constant
	| OPEN_PARENTHESIS rvalue CLOSE_PARENTHESIS { parser::process_token($1); { parser::process_token($3); } }
	| value_operand ADD_OP value_operand		{ parser::process_token($2); }
	| value_operand SUBTRACT_OP value_operand	{ parser::process_token($2); }
	| value_operand MULTIPLY_OP value_operand	{ parser::process_token($2); }	
	| value_operand DIVIDE_OP value_operand		{ parser::process_token($2); }
	| value_operand BOOLEAN_AND_OP value_operand{ parser::process_token($2); }
	| value_operand BOOLEAN_OR_OP value_operand	{ parser::process_token($2); }
	
	| value_operand LT_OP value_operand			{ parser::process_token($2); }
	| value_operand GT_OP value_operand			{ parser::process_token($2); }
	| value_operand GEQ_OP value_operand		{ parser::process_token($2); }
	| value_operand LEQ_OP value_operand		{ parser::process_token($2); }
	
	| value_operand EQUALS_OP value_operand		{ parser::process_token($2); }
	| value_operand NOT_EQUALS_OP value_operand	{ parser::process_token($2); }
	
	| BOOLEAN_NOT_OP value_operand				{ parser::process_token($1); }
	| function_call							
	;
	
assignment_expression : lvalue ASSIGN_OP rvalue 
		{ parser::process_token($2); std::cerr << "expression: lvalue ASSIGN_OP expression\n"; }
	
expression : variable_declaration { std::cerr << "expression: variable_declaration\n"; }
	| variable_init { std::cerr << "expression: variable_init\n"; }
	| assignment_expression { std::cerr << "expression: assignment_expression\n"; }
	| rvalue { std::cerr << "expression: rvalue\n"; }
	| lvalue { std::cerr << "expression: lvalue\n"; }
	;
	
expression_list : expression COMMA expression_list
		{ parser::process_token($2); std::cerr << "expression_list : expression COMMA expression_list\n"; }
	| expression
		{ std::cerr << "expression_list : expression COMMA\n"; }
	;
	
function_call : lvalue OPEN_PARENTHESIS expression_list CLOSE_PARENTHESIS
		{ 
			parser::process_token($2);
			parser::process_token($4);
			std::cerr << "fn call params\n"; 
		}
		
	| lvalue OPEN_PARENTHESIS CLOSE_PARENTHESIS
		{ 
			parser::process_token($2);
			parser::process_token($3);
			std::cerr << "fn call no params\n"; 
		}
	;
	
function_declaration : FUNCTION type_specifier IDENTIFIER OPEN_PARENTHESIS variable_decl_seq CLOSE_PARENTHESIS
		{ 
			parser::process_token($2);
			parser::process_token($3);
			parser::process_token($5);
			std::cerr << "function_declaration : params\n";
		}
	;
	
function_definition : function_declaration block
		{ std::cerr << "function_definition : params\n"; }
	;
	
function_declaration_statement : function_declaration semicolon 
	| function_definition 
	;
	
subscript_operator : lvalue OPEN_BRACKET CONSTANT_INT CLOSE_BRACKET
		{ 
			parser::process_token($2);
			parser::process_token($3);
			parser::process_token($4);
			std::cerr << "subscript_operator\n"; 
		}
	;
	
expression_statement : expression semicolon 
		{ std::cerr << "statement : expression semicolon\n"; }
	| semicolon
	;
	
if_statement : IF OPEN_PARENTHESIS expression CLOSE_PARENTHESIS statement
		{ 
			parser::process_token($1);
			parser::process_token($2);
			parser::process_token($4);
			std::cerr << "if_statement statement\n"; 
		}
		
	| IF OPEN_PARENTHESIS expression CLOSE_PARENTHESIS ELSE statement
		{ 
			parser::process_token($1);
			parser::process_token($2);
			parser::process_token($4);
			parser::process_token($5);
			std::cerr << "if_statement else statement\n"; 
		}
	;
	
while_statement : WHILE OPEN_PARENTHESIS expression CLOSE_PARENTHESIS statement
		{ 
			parser::process_token($1);
			parser::process_token($2);
			parser::process_token($4);
			std::cerr << "while_statement\n"; 
		}
	;
	
control_statement : if_statement 
	| while_statement
	;

statement : expression_statement { std::cerr << "statement : expression_statement\n"; }
	| control_statement { std::cerr << "statement : control_statement\n"; }
	| function_declaration_statement { std::cerr << "statement : function_declaration_statement\n"; }
	| RETURN expression semicolon { std::cerr << "statement: return expression\n"; }
	| block
	;
	
statement_list : statement_list statement { std::cerr << "statement_list : statement_list statement\n"; }
	| statement
	;
	
block : OPEN_BRACE statement_list CLOSE_BRACE 
		{ 
			parser::process_token($1);
			parser::process_token($3);
			std::cerr << "new scope\n"; 
		}
	;
	
%% 

void yyerror(const char* str)
{
	parser::output_error(str);
}