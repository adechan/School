# Write a function that recursively scrolls a directory and
# displays those files whose name matches a regular expression
# given as a parameter or contains a string that matches the
# same expression. Files that satisfy both conditions will be prefixed with ">>"

import re
import os

def function8(directory):
    pattern = re.compile("^[a-zA-Z]+[\.a-zA-Z]+?$")
    firstMatched = []
    secondMatched = []
    for root, directories, files in os.walk(directory):
        for filename in files:
            if re.match(pattern, filename):
                firstMatched.append(os.path.join(root, filename))

            with open(os.path.join(root, filename), "r") as file:
                lines = file.readlines()
                for line in lines:
                    if re.match(pattern, line):
                        secondMatched.append(os.path.join(root, filename))

    matchedFiles = []
    for file in firstMatched:
        if file in secondMatched:
            matchedFiles.append(">> " + file)
        else:
            matchedFiles.append(file)

    for file in secondMatched:
        if file not in matchedFiles:
            matchedFiles.append(file)

    return matchedFiles


# match: make match from beginning (needs to start with pattern)
# search: make match anywhere in the string (prints from start till it finds match)
# findall: list of all matched


print(function8("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 6\\Exercise8"))