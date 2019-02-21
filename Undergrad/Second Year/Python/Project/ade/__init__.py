import re

patterns = [
	# delimiters
	("\(", "OPEN_PARANTHESIS"),
	("\)", "CLOSE_PARANTHESIS"),
	("\[", "OPEN_BRACKET"),
	("\]", "CLOSE_BRACKET"),
	("\{", "OPEN_BRACE"),
	("\}", "CLOSE_BRACE"),
	(",", "COMMA"),
	(";", "SEMICOLON"),
	(":", "COLON"),
	
	# statements : if, while, for
	("if", "IF"),
	("else", "ELSE"),
	("while", "WHILE"),
	("do", "DO"),
	("for", "FOR"),
	("goto", "GOTO"),
	("break", "BREAK"),
	("continue", "CONTINUE"),
	("return", "RETURN"),
	("switch", "SWITCH"),
	("case", "CASE"),
	("main", "MAIN"),
	
	# types
	("int", "TYPE"),
	("float", "TYPE"),
	("char", "TYPE"),
	("short", "TYPE"),
	("long", "TYPE"),
	("double", "TYPE"),
	
	# binary operators
	("\+", "BINARY_OPERATOR"),
	("\-", "BINARY_OPERATOR"),
	("\*", "BINARY_OPERATOR"),
	("/", "BINARY_OPERATOR"),
	("%", "BINARY_OPERATOR"),
	("\|\|", "BINARY_OPERATOR"),
	("&&", "BINARY_OPERATOR"),
	("<=", "BINARY_OPERATOR"),
	(">=", "BINARY_OPERATOR"),
	("<", "BINARY_OPERATOR"),
	(">", "BINARY_OPERATOR"),
	("==", "BINARY_OPERATOR"),
	("!=", "BINARY_OPERATOR"),
	("\^", "BINARY_OPERATOR"),
	("\|", "BINARY_OPERATOR"),
	("&", "BINARY_OPERATOR"),
	("<<", "BINARY_OPERATOR"),
	(">>", "BINARY_OPERATOR"),
	
	# unary operators
	("\+\+", "UNARY_OPERATOR"),
	("\-\-", "UNARY_OPERATOR"),
	("!", "UNARY_OPERATOR"),
	("~", "UNARY_OPERATOR"),

	# assignment operators
	("=", "ASSIGNMENT_OPERATOR"),
	("\+=", "ASSIGNMENT_OPERATOR"),
	("\-=", "ASSIGNMENT_OPERATOR"),
	("\*=", "ASSIGNMENT_OPERATOR"),
	("/=", "ASSIGNMENT_OPERATOR"),
	("%=", "ASSIGNMENT_OPERATOR"),
	("&=", "ASSIGNMENT_OPERATOR"),
	("\|=", "ASSIGNMENT_OPERATOR"),
	("\^=", "ASSIGNMENT_OPERATOR"),
	("<<=", "ASSIGNMENT_OPERATOR"),
	(">>=", "ASSIGNMENT_OPERATOR"),
	
	# constants
	("[0-9][0-9]*", "CONSTANT"),
	("[0-9][0-9]*.[0-9][0-9]*", "CONSTANT"),
	("\"[^\n]*\"", "CONSTANT"),
	("\"[^\n][a-zA-Z][0-9]\"", "CONSTANT"),
	
	# identifiers 
	("[a-zA-Z_][0-9a-zA-Z_]*", "ID"),
]

patterns = [[re.compile(pattern[0]), pattern[1]] for pattern in patterns]

# So there are 2 parts to this regex pattern
# The first part is the whitespace pattern [\s]+ which means
# match all whitespace characters.
# The second part ([;,.\(\)\{\}\[\]]) has a ( ) 
# keeps the captured ), (, {, }, [, ], ;, ',', and . characters

# This removes all the None and empty string guys from the list
# This happens because if the re.split guy sees no captured guys, it returns None
token_index = 0
tokens = [ '' ]
token_count = len(tokens);

delimiter_pattern = "[\s]+|([;,.\(\)\{\}\[\]])";