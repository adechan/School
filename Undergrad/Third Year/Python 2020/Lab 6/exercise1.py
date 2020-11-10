# Write a function that extracts the words from a given text as a parameter.
# A word is defined as a sequence of alpha-numeric characters.

import re

def extractWords(text):
    return re.findall('([a-zA-Z0-9]+)', text)

print(extractWords("Hello there, Ade23! !"))