# Write a function that receives as a parameter a string of
# text characters and a list of regular expressions and
# returns a list of strings that match on at least one regular
# expression given as a parameter.

import re

def function3(text, expressions):
    result = []

    for expression in expressions:
        r = re.findall(expression, text)
        if len(r) != 0:
            for element in r:
                result.append(element)

    if len(result) == 0:
        print("No match could be found!")

    return result


print(function3("Ana are 23 mere !!", ["[a-zA-Z]+", "[0-9]+"]))