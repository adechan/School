# ﻿Să se scrie o funcție ce primește ca parametru un string my_path.
# Dacă parametrul reprezintă calea către un fișier, se vor returna
# ultimele 20 de caractere din conținutul fișierului. Dacă
# parametrul reprezintă calea către un director, se va
# returna o listă de tuple (extensie, count), sortată
# descrescător după count, unde extensie reprezintă extensie
# de fișier, iar count - numărul de fișiere cu acea extensie.
# Lista se obține din toate fișierele (recursiv) din directorul
# dat ca parametru.

import os

def function3(myPath):
    if os.path.isfile(myPath):
        characters = []
        print(myPath + " -> file")
        f = open(myPath, "r")
        f.seek(0, os.SEEK_END) # seek to the end of file
        f.seek(f.tell() - 20, os.SEEK_SET) # go backwards 20 bytes
        characters.append(f.read())
        return characters

    elif os.path.isdir(myPath):
        print(myPath + " -> directory")

        countExtensions = {}
        for currentPath, folders, files in os.walk(myPath):
            for filename in files:
                extension = os.path.splitext(filename)[1]
                if extension in countExtensions:
                    countExtensions[extension] += 1
                else:
                    countExtensions[extension] = 1
        print("dict is -> ", countExtensions)

        tuples = []
        for item in sorted(countExtensions.items(), key = lambda element: element[1], reverse = True):
            tuples.append(item)
        return tuples


print(function3("C:\\Users\\Andreea Rindasu\\PycharmProjects\\PythonClass\\Lab 4\\Exercise3Directory"))
