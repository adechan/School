pattern = [
	# identifiers 
	("[a-zA-Z_][0-9a-zA-Z_]*", "ID")
	
	# type of identifiers
	("int", "TYPE")
	("float", "TYPE")
	("char", "TYPE")
	("short", "TYPE")
	("long", "TYPE")
	("double", "TYPE")
	("[0-9][0-9]*", "CONSTANT_INT")
	("[0-9][0-9]*.[0-9][0-9]*", "CONSTANT_FLOAT")
	("\"[^\n]*\"", "CONSTANT_STRING")
	("\"[^\n][a-zA-Z][0-9]\"", "CONSTANT_CHAR")
	
	# binary operators
	("+", "BINARY_OPERATOR")
	("-", "BINARY_OPERATOR")
	("*", "BINARY_OPERATOR")
	("/", "BINARY_OPERATOR")
	("%", "BINARY_OPERATOR")
	("||", "BINARY_OPERATOR")
	("&&", "BINARY_OPERATOR")
	("<=", "BINARY_OPERATOR")
	(">=", "BINARY_OPERATOR")
	("<", "BINARY_OPERATOR")
	(">", "BINARY_OPERATOR")
	("==", "BINARY_OPERATOR")
	("!=", "BINARY_OPERATOR")
	("^", "BINARY_OPERATOR")
	("|", "BINARY_OPERATOR")
	("&", "BINARY_OPERATOR")
	("<<", "BINARY_OPERATOR")
	(">>", "BINARY_OPERATOR")
	
	# unary operators
	("++", "UNARY_OPERATOR")
	("--", "UNARY_OPERATOR")
	("!", "UNARY_OPERATOR")
	("~", "UNARY_OPERATOR")

	# assignment operators
	("=", "ASSIGNMENT_OPERATOR")
	("+=", "ASSIGNMENT_OPERATOR")
	("-=", "ASSIGNMENT_OPERATOR")
	("*=", "ASSIGNMENT_OPERATOR")
	("/=", "ASSIGNMENT_OPERATOR")
	("%=", "ASSIGNMENT_OPERATOR")
	("&=", "ASSIGNMENT_OPERATOR")
	("|=", "ASSIGNMENT_OPERATOR")
	("^=", "ASSIGNMENT_OPERATOR")
	("<<=", "ASSIGNMENT_OPERATOR")
	(">>=", "ASSIGNMENT_OPERATOR")
	
	# delimiters
	("(", "LEFT_PARANTHESIS")
	(")", "RIGHT_PARANTHESIS")
	("[", "LEFT_BRACKET")
	("]", "RIGHT_BRACKET")
	("{", "LEFT_BRACE")
	("}", "RIGHT_BRACE")
	(",", "COMMA")
	(";", "SEMICOLON")
	(":", "COLON")
	
	# statements : if, while, for
	("if", "IF")
	("else", "ELSE")
	("while", "WHILE")
	("do", "DO")
	("for", "FOR")
	("goto", "GOTO")
	("break", "BREAK")
	("continue", "CONTINUE")
	("return", "RETURN")
	("switch", "SWITCH")
	("case", "CASE")
	]
	
	
	