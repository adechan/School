import re

# These are the global varaibles defined in the __init__.py file
from ade import patterns, delimiter_pattern
from ade import tokens, token_index, token_count

class symbol:
	type = ''
	text = ''

	def __init__(self, type, text):
		self.type = type
		self.text = text

def tokenize(text):
	global delimiter_pattern, tokens, token_count
	tokens = re.split(delimiter_pattern, text)
	tokens = [x for x in tokens if x is not None and x is not '']
	token_count = len(tokens)

def next_symbol():
	global tokens, token_index
	
	if (empty()):
		return None 
	
	for pattern in patterns:
		if (re.match(pattern[0], tokens[token_index])):
			token_index = token_index + 1
			
			# Return the symbol type and the original text
			return symbol(type = pattern[1], text = tokens[token_index - 1])
			
def lookahead():
	global tokens, token_index
	
	if (empty()):
		return None 
	
	for pattern in patterns:
		if (re.match(pattern[0], tokens[token_index])):
			return symbol(type = pattern[1], text = tokens[token_index])
	
			
def empty():
	return token_index >= token_count