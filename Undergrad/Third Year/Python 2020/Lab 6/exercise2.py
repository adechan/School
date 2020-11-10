# Write a function that receives as a parameter a regex string,
# a text string and a whole number x, and returns those
# long-length x substrings that match the regular expression.

import re

def function2(regex, text, number):
    r = re.findall(regex, text)

    result = []
    for substring in r:
        if len(substring) == number:
            result.append(substring)

    return result

print(function2("[a-zA-Z0-9]+", "Ana are mere !", 3))