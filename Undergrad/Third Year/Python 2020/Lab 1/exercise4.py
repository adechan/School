# Write a script that converts a string of characters written in
# UpperCamelCase into lowercase_with_underscores.

def replaceWord(word):
    result = ""
    if word[0].isupper():
        result = word[0].lower()
        result += word[1:] + "_"
    return result

# def findWords(concatenatedWords):
#     words = []
#
#
#     return words
#
# print(findWords("AdeIsCat"))