# Write a function that, for a text given as a parameter, censures
# words that begin and end with voices. Censorship means replacing
# characters from odd positions with *.

import re

def function6(text):
    vowels = "aeiouAEIOU"
    words = re.findall("[a-zA-Z0-9]+", text)

    matchedWords = []
    for word in words:
        r = re.findall(f"^[{vowels}][a-zA-Z0-9]*[{vowels}]$", word)
        if len(r) > 0:
            matchedWords.append(word)

    result = []
    for word in matchedWords:
        for index in range(0, len(word), 2):
            censoredWord = word[:index] + "*" + word[index + 1:]
            word = censoredWord

        result.append(censoredWord)

    return result


print(function6("Anna are mere"))