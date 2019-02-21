import ade.lexer as lexer
import sys

debug_tab_level = -1

def error(message):
	print('Error: Expected symbol {}'.format(message))
	
def debug(nonterminal):
	global debug_tab_level
	
	tabs = ''
	for i in range(0, debug_tab_level):
		tabs += '  '
		
	print(tabs + nonterminal + ':')
	debug_tab_level	+= 1

def debug_end():
	global debug_tab_level
	debug_tab_level -= 1
	
def expect_symbol(symbol_type):
	symbol = lexer.next_symbol()

	tabs = ''
	for i in range(0, debug_tab_level):
		tabs += '  '
		
	print(tabs + "['{}', '{}']".format(symbol.type, symbol.text))
	if (symbol.type != symbol_type):
		error(symbol_type)

# program -> int main() block .	
def program():
	debug('program')
	expect_symbol('TYPE')
	expect_symbol('MAIN')
	expect_symbol('OPEN_PARANTHESIS')
	expect_symbol('CLOSE_PARANTHESIS')
	block()
	debug_end()

# block -> { statement_list } .	
block_first = [ 'OPEN_BRACE' ]
def block(): 
	debug('block')
	expect_symbol('OPEN_BRACE')
	statement_list()
	expect_symbol('CLOSE_BRACE')
	debug_end()
	
# statement_list -> statement statement_list1 
# | block .
def statement_list(): 
	debug('statement_list')
	
	if (not lexer.empty() and lexer.lookahead().type in block_first):
		block()
	else:
		statement()
		statement_list1()
	debug_end()
	
# statement_list1 -> statement statement_list1 
# | .	
def statement_list1():
	debug('statement_list1')
	follow = [ 'CLOSE_BRACE' ]
	
	if (not lexer.empty() and lexer.lookahead().type in follow):
		return
		
	statement()
	statement_list1()
	debug_end()
	
# statement -> control_statement 
# | expression_statement 
# | variable_declaration
# | return_statement .
def statement():
	debug('statement')
	lookahead = lexer.lookahead()
	if (lookahead.type in control_statement_first):
		control_statement() 
		
	elif (lookahead.type in expression_statement_first):
		expression_statement()
		
	elif (lookahead.type in return_statement_first):
		return_statement()
	
	elif (lookahead.type in variable_declaration_first):
		variable_declaration()
		
	debug_end()
	
# return_statement -> return rvalue ; .	
return_statement_first = [ 'RETURN' ]
def return_statement():
	debug('return_statement')
	expect_symbol('RETURN')
	expression()
	expect_symbol('SEMICOLON')
	debug_end()
	
# control_statement -> if_statement | while_statement | for_statement .	
control_statement_first = [ 'IF', 'WHILE' ]
def control_statement():
	debug('control_statement')
	lookahead = lexer.lookahead()
	
	if (lookahead.type in if_statement_first):
		if_statement()
	
	elif (lookahead.type in while_statement_first):
		while_statement()
	
	#elif (lookahead.type in for_statement_first):
	#  	for_statement()
	debug_end()
	
	
"""	
# expression_statement_rhs -> = rvalue .	
def expression_statement_rhs():
	debug('expression_statement_rhs')
	follow = [ 'SEMICOLON' ]
	
	if (lexer.lookahead().type in follow):
		return
		
	expect_symbol('ASSIGNMENT_OPERATOR')
	rvalue()
	debug_end()
"""


# expression_statement -> variable_declaration .
expression_statement_first = [ 
	'OPEN_PARANTHESIS',  
	'ID', 'UNARY_OPERATOR',
	'CONSTANT'
]
def expression_statement():
	debug('expression_statement')
	
	expression()
	expect_symbol('SEMICOLON')
	debug_end()
	
def expression():
	debug('expression')
	
	rvalue()
	expression1()
	debug_end()
	
def expression1():
	debug('expression1')
	follow = [ 'SEMICOLON', 'CLOSE_PARANTHESIS', 'COMMA' ]
	
	if (lexer.lookahead().type in follow):
		return
	
	expect_symbol('BINARY_OPERATOR')
	expression()
	debug_end()
	
# if_statement -> if ( expression ) statement else statement .	
if_statement_first = [ 'IF' ]
def if_statement():
	debug('if_statement')
	expect_symbol('IF')
	expect_symbol('OPEN_PARANTHESIS')
	expression()
	expect_symbol('CLOSE_PARANTHESIS')
	statement()
	expect_symbol('ELSE')
	statement()
	debug_end()
	
# while_statement -> while ( expression ) statement .	
while_statement_first = [ 'WHILE' ]
def while_statement():
	debug('while_statement')
	expect_symbol('WHILE')
	expect_symbol('OPEN_PARANTHESIS')
	expression()
	expect_symbol('CLOSE_PARANTHESIS')
	statement()
	debug_end()
""" 	
# for_statement -> for ( ) statement .	
for_statement_first = [ 'FOR' ]
def for_statement():
	debug('for_statement')
	expect_symbol('FOR')
	expect_symbol('OPEN_PARANTHESIS')
	expect_symbol('CLOSE_PARANTHESIS')
	statement()
	debug_end()
"""
	
# variable_declaration -> var_decl_list ;.	
variable_declaration_first = [ 'TYPE' ]
def variable_declaration():
	debug('variable_declaration')
	var_decl_list()
	expect_symbol('SEMICOLON')
	debug_end()
	
def var_decl_list():
	debug('var_decl_list')
	var_decl()
	var_decl_list1()
	debug_end()
	
def var_decl_list1():
	debug('var_decl_list1')
	follow = [ 'SEMICOLON' ]
	if (lexer.lookahead().type in follow):
		return 
		
	expect_symbol('COMMA')
	var_decl_list1()
	debug_end()

def var_decl():
	debug('var_decl')
	expect_symbol('TYPE')
	expect_symbol('ID')
	expect_symbol('ASSIGNMENT_OPERATOR')
	expression()
	debug_end()
	
# lvalue -> id lvalue1 
# | ++ id .
lvalue_first = [ 'ID', 'UNARY_OPERATOR' ]
def lvalue():
	debug('lvalue')
	lookahead = lexer.lookahead()
	
	if (lookahead.type == 'ID'):
		expect_symbol('ID')
		lvalue1()
	else:
		expect_symbol('UNARY_OPERATOR')
		expect_symbol('ID')
	
	debug_end()
	
# lvalue1 -> ++
# | .
def lvalue1():
	debug('lvalue1')
	follow = [ 'SEMICOLON', 'BINARY_OPERATOR', 'CLOSE_PARANTHESIS', 'COMMA' ]
	
	if (not lexer.empty() and lexer.lookahead().type in follow):
		return 
	else:
		expect_symbol('UNARY_OPERATOR')
	debug_end()
	
# rvalue1 -> ( rvalue )
# | lvalue 
# | constant .	
def rvalue():
	debug('rvalue')
	
	if (lexer.lookahead().type == 'OPEN_PARANTHESIS'):
		expect_symbol('OPEN_PARANTHESIS')
		rvalue()
		expect_symbol('CLOSE_PARANTHESIS')
	elif (lexer.lookahead().type == 'CONSTANT'):
		expect_symbol('CONSTANT')
	else:
		lvalue()
		
	debug_end()
	
def parse(text):
	lexer.tokenize(text);
	program()
	
file = open(sys.argv[1])
c_source = file.read()

print(c_source)
parse(c_source)
print('')
print('Finished parsing')