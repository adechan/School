# Write a function that counts how many words exists in a text.
# A text is considered to be form out of words that are separated
# by only ONE space. For example: "I have Python exam" has 4 words.

def countWords(string):
    words = string.split(" ")
    return len(words)

print(countWords("I have Python exam"))